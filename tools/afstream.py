#!/usr/bin/env python3
# Copyright 2026 Evariste F5OEO
# https://github.com/F5OEO
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
#     Unless required by applicable law or agreed to in writing, software
#     distributed under the License is distributed on an "AS IS" BASIS,
#     WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#     See the License for the specific language governing permissions and
#     limitations under the License.
"""Record the radio's demodulated audio, streamed over the USB serial port.

    ./afstream.py --seconds 10 --out af.wav
    ./afstream.py --play
    ./afstream.py --raw - | sox -t raw -r 8000 -e signed -b 16 - spectrogram.png

The App/apps/afstream overlay ("AF Stream") must be running on the radio: while
it is, it owns the USB CDC port, so this is raw bytes and not the framed
command protocol tools/appload.py speaks.  The wire format is the ADC's 12-bit
codes as little-endian halfwords, 0 to 4095, silence at 2048 - no header and no
framing, so a capture can start and stop at any time.

Two things this tool exists to get right.

Alignment.  Opening the port lands anywhere in the stream, possibly on the odd
byte of a sample, and a halfword read one byte late is noise.  The top four
bits of every sample are zero, which gives a test: whichever of the two offsets
puts almost no value above 0x0FFF is the right one.  The same test then says
how clean the link is.

The sample rate.  The radio's clock is not the PC's: Voice TX measured it 0.6 %
slow on the air (tools/beacon_say.py, CLOCK = 1.0062), which is 0.36 s per
minute at a nominal 8 kHz - enough to make a player stutter and to spoil any
timing measurement.  So the rate is MEASURED here, from the bytes' own arrival,
and written into the WAV header; --rate only says what to expect.

Gaps.  With the app's gate on (key 4) nothing is sent while nothing is being
received, so the stream arrives in bursts.  They are counted, and the rate is
measured inside them rather than across them - a silence would otherwise read
as a slow clock.  One WAV holds every burst end to end, which is what you want
to listen to; --split writes one file per burst instead, which is what you want
after a night of recording.
"""

import argparse, os, struct, subprocess, sys, time, wave

try:
    from serial import Serial
except ImportError:
    sys.exit("pyserial is missing: pip install pyserial")

BIAS = 2048
CHUNK = 512          # the app sends 256 B a half-buffer; read in two of them
GAP_S = 0.3          # silence longer than this ends a burst
WARM_S = 2.0         # --play: measure the rate this long before opening aplay.
                     # One second gave 8000 Hz where two give 7971: the first
                     # blocks arrive from the kernel's buffer in a rush, and a
                     # sink opened 0.4 % fast starves every half minute


def align(buf: bytes) -> tuple[int, float]:
    """(offset, share of samples in range) for the better of the two phases."""
    best, score = 0, -1.0
    for off in (0, 1):
        n = (len(buf) - off) // 2
        if n < 16:
            continue
        good = sum(1 for v in struct.unpack_from(f"<{n}H", buf, off) if v < 4096)
        if good / n > score:
            best, score = off, good / n
    return best, max(score, 0.0)


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("-p", "--port", default="/dev/ttyACM0")
    ap.add_argument("-r", "--rate", type=int, default=8000,
                    help="the rate selected on the radio (key 1): 8000, 16000, 32000 or 38400")
    ap.add_argument("-s", "--seconds", type=float, default=0.0,
                    help="stop this long after starting, data or not "
                         "(default: until Ctrl-C)")
    ap.add_argument("-o", "--out", help="write a WAV file at the measured rate")
    ap.add_argument("--raw", help="write signed 16-bit little-endian here, - for stdout")
    ap.add_argument("--play", action="store_true", help="pipe to aplay as it arrives")
    ap.add_argument("-g", "--gain", type=float, default=1.0,
                    help="multiply before clipping; the chain leaves about "
                         "18 dB of headroom on speech")
    ap.add_argument("-D", "--device", default="default",
                    help="the ALSA device --play writes to")
    ap.add_argument("--split", metavar="PREFIX",
                    help="one WAV per burst, PREFIX_001.wav and so on")
    a = ap.parse_args()
    if not a.out and not a.raw and not a.play:
        a.out = "af.wav"

    # 50 ms, not 500: during a gap the loop only pads the sink when a read
    # comes back empty, so the read timeout IS the granularity of the silence.
    # Half a second written at once and then half a second of nothing drains a
    # sink whose buffer is shorter than that - 30 underruns over two minutes,
    # measured. With data flowing a 512-byte read fills in 32 ms at 16 kB/s,
    # so asking more often costs nothing.
    ser = Serial(a.port, 115200, timeout=0.05)
    try:
        ser.dtr = True                  # the app only sends with DTR asserted
    except OSError as exc:              # a pty or a port with no modem lines
        print(f"cannot assert DTR on {a.port} ({exc}); carrying on", file=sys.stderr)
    ser.reset_input_buffer()

    raw = None
    if a.raw:
        raw = sys.stdout.buffer if a.raw == "-" else open(a.raw, "wb")
    # --play opens aplay only once the rate has been measured: the radio's RC
    # clock runs a few tenths of a percent off nominal, and a sink consuming
    # 8000 Hz from a source producing 7963 starves every few seconds.
    player = None
    warm = bytearray()

    play_rate = float(a.rate)   # what the sink was opened at
    play_t0 = 0.0               # when it opened
    play_n = 0                  # samples handed to it since

    def spawn_player(rate: int):
        nonlocal play_rate, play_t0, play_n
        print(f"aplay at {rate} Hz", file=sys.stderr)
        play_rate, play_t0, play_n = float(rate), time.time(), 0
        return subprocess.Popen(
            ["aplay", "-q", "-D", a.device, "-t", "raw", "-f", "S16_LE",
             "-c", "1", "-r", str(rate)], stdin=subprocess.PIPE)

    def feed(chunk: bytes) -> None:
        """Audio to the sink, preceded by silence for whatever time passed
        without any. With the gate on (the app's key 1) nothing arrives
        between transmissions, and a sink with nothing to play starves: one
        240 s session reported a 212 s underrun, which is the gate working but
        reads like a fault and clicks on the way back in. Silence keeps the
        sink exactly on real time, so a gap sounds like a closed squelch."""
        nonlocal play_n
        if player is None:
            return
        want = int((time.time() - play_t0) * play_rate)
        pad = want - play_n - len(chunk) // 2
        if pad > 0:
            player.stdin.write(bytes(2 * pad))
            play_n += pad
        if chunk:
            player.stdin.write(chunk)
            play_n += len(chunk) // 2

    pcm = bytearray()
    pending = b""
    offset = None
    quality = 0.0
    total = 0
    t0 = None
    peak = 0
    report = 0.0
    # bursts: the gate (app key 4) sends nothing while nothing is received
    bursts = 0
    b_start = b_last = None
    b_samples = b_first = 0
    b_pcm = bytearray()
    active_t = 0.0
    active_n = 0
    t_start = time.time()      # the session's own clock: a gated stream may
                               # never send a byte, and that is a result too

    def write_wav(path: str, data: bytes, rate: int) -> None:
        with wave.open(path, "wb") as w:
            w.setnchannels(1)
            w.setsampwidth(2)
            w.setframerate(rate)
            w.writeframes(data)

    def end_burst() -> None:
        nonlocal b_start, b_last, b_samples, b_first, b_pcm, active_t, active_n
        if b_start is None:
            return
        if b_last > b_start and b_samples > b_first:
            active_t += b_last - b_start
            active_n += b_samples - b_first
        if a.split and b_pcm:
            rate = int(round(active_n / active_t)) if active_t > 0 else a.rate
            name = f"{a.split}_{bursts:03d}.wav"
            write_wav(name, bytes(b_pcm), rate)
            print(f"\n{name}: {len(b_pcm) // 2} samples", file=sys.stderr)
        b_pcm = bytearray()
        b_start = b_last = None
        b_samples = b_first = 0
    try:
        while True:
            block = ser.read(CHUNK)
            now = time.time()
            if a.seconds and now - t_start >= a.seconds:
                if b_last is not None:
                    end_burst()
                break
            if not block:
                if b_last is not None and now - b_last > GAP_S:
                    end_burst()
                feed(b"")               # the sink still needs its silence
                continue
            if t0 is None:
                t0 = now
            pending += block
            if offset is None:
                if len(pending) < 2 * CHUNK:
                    continue
                offset, quality = align(pending)
                if quality < 0.99:
                    # not the audio yet: the resident firmware still owns the
                    # port, or the app was launched mid-block. Drop and retry.
                    pending = pending[-CHUNK:]
                    offset = None
                    t0 = None
                    total = 0
                    continue
                pending = pending[offset:]
                print(f"aligned on byte {offset}, {quality * 100:.1f} % of samples in range",
                      file=sys.stderr)
            n = len(pending) // 2
            codes = struct.unpack_from(f"<{n}H", pending, 0)
            pending = pending[2 * n:]
            # AF Bridge mixes control halfwords into the same pipe; audio
            # never has its top nibble set, so anything >= 0x1000 is not a
            # sample. Masking it would make a near-full-scale spike.
            codes = [v for v in codes if v < 0x1000]
            n = len(codes)
            if not n:
                continue
            total += n
            if b_start is None or (b_last is not None and now - b_last > GAP_S):
                end_burst()
                bursts += 1
                b_start = now
                b_first = n
            b_last = now
            b_samples += n
            out = bytearray(2 * n)
            lo = hi = BIAS
            for i, v in enumerate(codes):
                if v < lo: lo = v
                if v > hi: hi = v
                s16 = int((v - BIAS) * 16 * a.gain)
                struct.pack_into("<h", out, 2 * i,
                                 -32768 if s16 < -32768 else 32767 if s16 > 32767 else s16)
            peak = max(peak, hi - lo)
            if raw:
                raw.write(out)
                raw.flush()
            # The rate so far, this burst included. end_burst() only folds a
            # burst into active_n/active_t once it is OVER, and a continuous
            # stream never ends one - reading those here left aplay unopened
            # for 89 s of perfectly good audio, until the end-of-session
            # fallback dumped it at the nominal rate.
            live = (active_n + b_samples - b_first) / \
                   ((active_t + b_last - b_start) or 1.0)
            if a.play:
                if player is not None:
                    feed(out)
                else:
                    warm += out
                    # A tenth of a second in hand, then open at the NOMINAL
                    # rate: the silence padding tops the sink up against real
                    # time, so opening a shade fast only inserts the odd
                    # single sample, where waiting to measure meant a 1.7 s
                    # transmission was never heard at all.
                    if len(warm) >= 2 * (a.rate // 5):
                        player = spawn_player(a.rate)
                        player.stdin.write(warm)   # the backlog is the latency
                        play_n += len(warm) // 2
                        warm = bytearray()
            if a.out:
                pcm += out
            if a.split:
                b_pcm += out
            if now - report >= 1.0:
                report = now
                print(f"\r{total} samples, {live:7.1f} Hz in burst {bursts}, "
                      f"peak-to-peak {peak:4d} / 4096   ", end="", file=sys.stderr)
                peak = 0
    except KeyboardInterrupt:
        pass
    finally:
        ser.close()
        if a.play and player is None and warm:      # too short to measure
            player = spawn_player(a.rate)
            player.stdin.write(warm)
            play_n += len(warm) // 2
        if player:
            player.stdin.close()
            player.wait()
        if raw and raw is not sys.stdout.buffer:
            raw.close()

    end_burst()
    session = time.time() - t_start
    if not total:
        print(f"nothing received in {session:.1f} s: the gate stayed closed, "
              f"or the app is not running / not streaming", file=sys.stderr)
        return
    elapsed = (time.time() - t0) if t0 else 0.0
    measured = active_n / active_t if active_t > 0 else float(a.rate)
    print(f"\n{total} samples in {elapsed:.2f} s, {bursts} burst(s), "
          f"{active_t / elapsed * 100 if elapsed else 0:.0f} % of the time sending",
          file=sys.stderr)
    print(f"measured inside the bursts: {measured:.1f} Hz "
          f"({measured / a.rate * 100 - 100:+.2f} % of the {a.rate} Hz selected)",
          file=sys.stderr)
    if a.out and total:
        write_wav(a.out, bytes(pcm), int(round(measured)))
        print(f"{a.out}: {total} samples at {int(round(measured))} Hz", file=sys.stderr)


if __name__ == "__main__":
    main()

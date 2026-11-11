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
"""Transmit through the radio with the App/apps/afbridge overlay running.

    ./afbridge.py message.wav                 # one counted burst
    ./afbridge.py message.wav --repeat 3
    ./afbridge.py --watch                     # just show what the app reports

AF Bridge must be running on the radio.  While it is, it owns the USB CDC port,
so only one program at a time can talk to it: stop tools/aflisten.sh before
transmitting.

Up (host -> radio) is Voice TX's wire format: 'V','T','X','S', the sample count
as 32 bits little-endian, then 3-bit ADPCM, 8 codes to three bytes.  Down
(radio -> host) is audio as 12-bit halfwords plus control halfwords, which is
what this tool watches:

    0x1001 / 0x1002   the carrier is up / reception resumed
    0x2000 | fill     bytes waiting in the radio's 128-byte ring
    0x3000 | code     the burst ended: OK, UNDER, DENIED, MISMATCH, BADLEN, TOT

PACING IS THE WHOLE PROBLEM, and the reason the link is duplex.  The radio
consumes 3000 B/s off its own RC clock, which is a few tenths of a percent from
the PC's and drifts with temperature; the resident port's 256-byte ring does
not drop the excess when it laps, it FLUSHES, which costs the rest of the
burst.  So this tool runs a feed-forward of 3000 B/s corrected by an integral
term on the reported fill, aiming at TARGET bytes and backing off hard above
PANIC.  The same loop is what a live microphone would need.

The audio chain before the ADPCM is not optional: App/apps/vtxdata/encode_clip.py
does the interpolation to 8 kHz, the AGC and the limiter, and its own ablation
measured those worth 0.31 -> 0.53 and 0.53 -> 0.89 of correlation on the air.
"""

import argparse, base64, fcntl, json, math, os, shlex, struct, subprocess, sys, tempfile, time

try:
    from serial import Serial
except ImportError:
    sys.exit("pyserial is missing: pip install pyserial")

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
ENCODER = os.path.join(ROOT, "App", "apps", "vtxdata", "encode_clip.py")
RATE = 8000
BIAS = 2048                         # the ADC code the AF sits on
# The radio's own clock, measured: its ADC produced 7970 Hz for a nominal 8000,
# and the TX loop is paced by the same RC oscillator. beacon_say.py measured
# 1.0062 on another day; this is per-radio and per-temperature, which is why
# the fill report servos on top of it rather than instead of it.
CLOCK = 1.004
BYTES_PER_S = RATE * 3 / 8 / CLOCK  # what the radio actually consumes
TARGET = 88                         # bytes to keep in the radio's 128 B ring.
                                    # 40 was far too tight: beacon_say.py keeps
                                    # a tenth of a second of lead across both
                                    # rings, and at 40 the ring hit 0, where
                                    # every dry group costs the modulator a
                                    # stall - heard as a gap, and it stretches
                                    # the clip by as much
LOW = 48                            # below this, push a chunk at once
PANIC = 116                         # above this, hold off for a moment
KP = 0.1                            # B/s of correction per byte of error,
                                    # applied at each credit (10 a second):
                                    # KP = 6 saturated both rails on the
                                    # first burst and limit-cycled
LEAD = 192                          # bytes of lead before the first credit:
                                    # 64 ms in the app ring, the rest in the
                                    # resident 256 B one
MAX_CHUNK = 32                      # 10 ms a write: the ring's sawtooth is
                                    # the chunk size, not the servo's doing
CATCH_UP = 192                      # a backlog may go out in one write: the
                                    # loop must be able to catch up after any
                                    # hiccup of the host's own scheduler
STATUS = {0: "OK", 1: "UNDER", 2: "DENIED", 3: "MISMATCH", 4: "BADLEN", 5: "TOT"}


def encode(wav: str, lead_ms: int) -> tuple[int, bytes]:
    """The clip through encode_clip.py: interpolation, AGC, limiter, ADPCM."""
    with tempfile.TemporaryDirectory() as work:
        out = os.path.join(work, "clips.json")
        r = subprocess.run([sys.executable, ENCODER, wav, out, "",
                            "--lead-ms", str(lead_ms)],
                           capture_output=True, text=True)
        if r.returncode:
            sys.exit(f"encoding failed:\n{r.stdout}{r.stderr}")
        print("  " + r.stdout.strip().splitlines()[0])
        d = json.load(open(out))
    n = d["n"]
    pay = b"".join(base64.b64decode(c) for c in d["chunks"])
    return n, pay[:(n + 7) // 8 * 3]


class Link:
    """The control words coming back, the audio they are mixed with, and
    optionally a sink to play that audio on while the same loop answers it."""

    def __init__(self, port: str, play: bool = False, device: str = "default",
                 rate: int = RATE, gain: float = 2.0):
        self.ser = Serial(port, 115200, timeout=0.05)
        try:
            self.ser.dtr = True
        except OSError as exc:
            print(f"cannot assert DTR ({exc}); carrying on", file=sys.stderr)
        self.ser.reset_input_buffer()
        self.buf = b""
        self.fill = 0
        self.fresh = False
        self.audio = 0
        self.last_audio = 0.0          # when a sample last arrived
        self.play = play
        self.device = device
        self.rate = rate
        self.gain = gain
        self.player = None
        self.warm = bytearray()
        self.p_rate = float(rate)
        self.p_t0 = 0.0
        self.p_n = 0
        self.run_t0 = 0.0              # start of the current run of audio
        self.run_n = 0                 # samples in it
        self.record = None             # a list the received codes go into too
        self.latency = 0.0             # the sink's delay: the warm-up backlog
        self.run_skip = 0              # its first chunk, which arrives in a
                                       # rush from the kernel's buffer and
                                       # reads 0.6 % fast if it is counted

    # ---- the sink: opened on the measured rate, and never left to starve
    def _spawn(self, rate: int) -> None:
        print(f"  aplay at {rate} Hz", file=sys.stderr)
        self.p_rate, self.p_t0, self.p_n = float(rate), time.time(), 0
        self.player = subprocess.Popen(
            ["aplay", "-q", "-D", self.device, "-t", "raw", "-f", "S16_LE",
             "-c", "1", "-r", str(rate)], stdin=subprocess.PIPE)

    def _feed(self, chunk: bytes) -> None:
        """Audio to the sink, preceded by the silence of whatever gap just
        passed: nothing arrives between transmissions, and a sink with nothing
        to play starves."""
        if self.player is None:
            return
        want = int((time.time() - self.p_t0) * self.p_rate)
        pad = want - self.p_n - len(chunk) // 2
        if pad > 0:
            self.player.stdin.write(bytes(2 * pad))
            self.p_n += pad
        if chunk:
            self.player.stdin.write(chunk)
            self.p_n += len(chunk) // 2

    def _audio_out(self, codes: list) -> None:
        if not self.play or not codes:
            return
        out = bytearray(2 * len(codes))
        for i, v in enumerate(codes):
            s16 = int((v - BIAS) * 16 * self.gain)
            struct.pack_into("<h", out, 2 * i,
                             -32768 if s16 < -32768 else 32767 if s16 > 32767 else s16)
        if self.player is not None:
            self._feed(bytes(out))
            return
        # A tenth of a second in hand, then open at the NOMINAL rate and let
        # the silence padding absorb the difference. Waiting two seconds to
        # measure the real rate meant a 1.7 s transmission was never heard at
        # all; and since the padding tops the sink up against real time,
        # opening a shade fast only inserts the odd single sample - 0.4 % is
        # one in 250, seven cents of pitch - where opening slow would let the
        # backlog, and the latency, grow without end.
        self.warm += out
        if len(self.warm) >= self.rate // 5:
            self._spawn(self.rate)
            self.latency = len(self.warm) / 2.0 / self.p_rate
            self.player.stdin.write(bytes(self.warm))
            self.p_n += len(self.warm) // 2
            self.warm = bytearray()

    def poll(self) -> list[int]:
        """Read what is waiting; return the control words, count the audio.

        Only what is waiting: ser.read(n) blocks until n bytes arrive or the
        port's timeout expires, and during a transmission the radio sends
        almost nothing. Polling 4096 bytes here throttled the send loop to
        one iteration per 50 ms - 640 B/s against the 3000 the radio eats,
        which is exactly the starvation measured on the air (1729 samples/s
        instead of 8000, the stall counter saturated)."""
        waiting = self.ser.in_waiting
        if waiting:
            self.buf += self.ser.read(waiting)
        n = len(self.buf) // 2
        if not n:
            return []
        words = struct.unpack_from(f"<{n}H", self.buf, 0)
        self.buf = self.buf[2 * n:]
        out, codes = [], []
        for w in words:
            if w < 0x1000:
                self.audio += 1
                codes.append(w)
            else:
                out.append(w)
                if (w & 0xF000) == 0x2000:
                    self.fill = w & 0x7F
                    self.fresh = True
        if codes:
            if self.record is not None:
                self.record.extend(codes)
            now = time.time()
            if not self.run_t0 or now - self.last_audio > 0.3:
                self.run_t0, self.run_n = now, 0   # a new run after a gap
                self.run_skip = len(codes)
            self.run_n += len(codes)
            self._audio_out(codes)
            self.last_audio = now
        return out

    def playing(self, guard: float) -> bool:
        """True while received audio is still coming out of the speakers, or
        stopped less than `guard` ago: open speakers feed the microphone, and
        a VOX that answers its own loudspeaker transmits what it just
        received - which is exactly what the first attempt did.

        The sink's own backlog cannot be the measure: the silence padding
        keeps it on real time, so it reads a constant two seconds for ever.
        What matters is when real audio last arrived, plus the fixed latency
        the warm-up buffer gave the sink."""
        return time.time() - self.last_audio < self.latency + guard

    def prefill(self, seconds: float) -> None:
        """Hand the sink `seconds` of silence in advance, before something
        blocking. The padding in _feed keeps the sink on real time, but it only
        runs when the loop does: the two or three seconds encode() spends in a
        subprocess are enough for ALSA to starve and say so."""
        if self.player is None:
            return
        n = int(seconds * self.p_rate)
        self.player.stdin.write(bytes(2 * n))
        self.p_n += n

    def pump(self) -> list[int]:
        """poll(), plus the silence the sink needs while nothing arrives."""
        words = self.poll()
        if not words and self.player is not None:
            self._feed(b"")
        return words

    def send(self, data: bytes) -> None:
        self.ser.write(data)

    def close(self) -> None:
        self.ser.close()


def burst(link: Link, n: int, pay: bytes, verbose: bool) -> str:
    link.send(b"VTXS" + struct.pack("<I", n))
    # the radio answers only once the carrier is up: anything earlier would
    # fill a ring nobody is draining yet
    t0 = time.time()
    while True:
        for w in link.pump():
            if w == 0x1001:
                break
            if (w & 0xF000) == 0x3000:
                return STATUS.get(w & 0xFF, "?")
        else:
            if time.time() - t0 > 5.0:
                return "no answer"
            continue
        break

    sent = 0
    pace = BYTES_PER_S
    link.send(pay[:LEAD])
    sent = min(LEAD, len(pay))
    t0 = time.time()
    last = t0
    while sent < len(pay):
        for w in link.pump():
            if (w & 0xF000) == 0x3000:
                return STATUS.get(w & 0xFF, "?")
        if link.fresh:
            link.fresh = False
            err = TARGET - link.fill
            pace = max(BYTES_PER_S * 0.95, min(BYTES_PER_S * 1.05, pace + KP * err))
            if link.fill >= PANIC:          # the resident ring is filling too
                time.sleep(0.02)
                continue
            if link.fill < LOW:             # a stall is imminent: push now
                chunk = pay[sent:sent + MAX_CHUNK]
                link.send(chunk)
                sent += len(chunk)
                t0 -= len(chunk) / pace     # keep the feed-forward honest
                continue
        now = time.time()
        due = int((now - t0) * pace) - sent
        if due <= 0:
            time.sleep(0.001)
            continue
        chunk = pay[sent:sent + min(due, CATCH_UP if due > 4 * MAX_CHUNK else MAX_CHUNK)]
        link.send(chunk)
        sent += len(chunk)
        if verbose and now - last >= 1.0:
            last = now
            print(f"\r  {sent}/{len(pay)} B, pace {pace:6.1f} B/s, "
                  f"ring {link.fill:3d}  ", end="", file=sys.stderr)
    # wait for the radio's verdict
    t0 = time.time()
    while time.time() - t0 < 10.0:
        for w in link.pump():
            if (w & 0xF000) == 0x3000:
                return STATUS.get(w & 0xFF, "?")
        time.sleep(0.01)
    return "no verdict"


MIC_CMD = "arecord -q -D default -t raw -f S16_LE -c 1 -r 8000"
FIFO = "/tmp/afbridge.fifo"         # a named pipe holds no data, so /tmp is fine


def parrot_loop(a, link) -> None:
    """Record what is received, then send it straight back.

    The roger mode answers with a fixed clip; this one answers with the thing
    itself, which is the only test that puts the whole chain end to end in one
    pass: the AM detector, PA4, the ADC and the DMA on the way in, then the
    AGC, the ADPCM, the flow control and the gain field on the way out. What
    comes back out of a second receiver is everything the radio did to it.

    Nothing is trimmed, so the squelch's own noise at either end of the
    transmission goes back out with the speech - that is the point.
    """
    sys.path.insert(0, os.path.join(ROOT, "App", "apps", "vtxdata"))
    import numpy as np
    import encode_clip as ec

    link.record = []
    cap = int(a.max_rec * RATE)
    print(f"  parrot: waiting for a transmission (up to {a.max_rec:.0f} s)",
          flush=True)
    rec: list = []
    last = 0.0
    t_start = time.time()
    while not a.seconds or time.time() - t_start < a.seconds:
        for w in link.pump():
            if (w & 0xF000) == 0x3000:
                print(f"  burst ended: {STATUS.get(w & 0xFF, '?')}", flush=True)
        if link.record:
            got, link.record = link.record, []
            if len(rec) < cap:
                rec.extend(got)
            last = time.time()
        now = time.time()
        if rec and now - last > a.hang:
            if len(rec) < a.min_rx * RATE:
                print(f"  ignored {len(rec)} samples", flush=True)
                rec = []
                continue
            print(f"  heard {len(rec) / RATE:.1f} s -> encoding and sending it back",
                  flush=True)
            link.prefill(4.0)           # the encode below blocks the loop
            x = (np.array(rec, dtype=np.float64) - BIAS) / 2048.0
            if a.lead_ms:               # silence for the far squelch
                x = np.concatenate([np.zeros(a.lead_ms * RATE // 1000), x])
            enc = ec.Adpcm()
            pay = enc(ec.Agc()(x))[0] + enc.flush()
            rec = []
            link.record = []
            print(f"  -> {burst(link, len(x), pay, False)}", flush=True)
            link.record = []            # whatever leaked in while transmitting
        elif not link.record:
            time.sleep(0.005)
    link.record = None


def listen_loop(a, link) -> None:
    """Hold the port, play what is received, and transmit on command.

    One program at a time owns the USB port, so listening and sending a file
    used to exclude each other: every send meant stopping the listener, and
    forgetting to restart it meant silence. This mode keeps the port and takes
    its orders through a named pipe instead:

        echo /path/clip.wav > /tmp/afbridge.fifo

    A clip is encoded once and kept, so a second send of the same file is
    immediate; `quit` ends the session. Nothing is transmitted that was not
    asked for by name.
    """
    path = a.fifo
    if not os.path.exists(path):
        os.mkfifo(path, 0o600)
    fd = os.open(path, os.O_RDONLY | os.O_NONBLOCK)
    print(f"  listening; echo a WAV path into {path} to transmit", flush=True)
    clips: dict = {}
    line = b""
    t_start = time.time()
    while not a.seconds or time.time() - t_start < a.seconds:
        for w in link.pump():
            kind = w & 0xF000
            if kind == 0x1000 and w == 0x1002:
                print("  receiving again", flush=True)
            elif kind == 0x3000:
                print(f"  burst ended: {STATUS.get(w & 0xFF, '?')}", flush=True)
        try:
            chunk = os.read(fd, 4096)
        except (BlockingIOError, OSError):
            chunk = b""
        if not chunk:
            time.sleep(0.005)
            continue
        line += chunk
        while b"\n" in line:
            cmd, line = line.split(b"\n", 1)
            cmd = cmd.decode("utf-8", "replace").strip()
            if not cmd:
                continue
            if cmd in ("quit", "stop", "exit"):
                print("  asked to stop", flush=True)
                os.close(fd)
                return
            if not os.path.isfile(cmd):
                print(f"  no such file: {cmd}", flush=True)
                continue
            if cmd not in clips:
                print(f"  encoding {os.path.basename(cmd)}", flush=True)
                link.prefill(4.0)       # encode() blocks; the sink must not
                clips[cmd] = encode(cmd, a.lead_ms)
            n, pay = clips[cmd]
            print(f"  sending {os.path.basename(cmd)}, {n / RATE:.2f} s",
                  flush=True)
            print(f"  -> {burst(link, n, pay, False)}", flush=True)
    os.close(fd)


def vox_loop(a, link) -> None:
    """Listen, and transmit the PC's microphone whenever it hears speech.

    Four things make this different from sending a file, and the fourth is the
    one that bites.

    The source cannot be paced: it arrives at the PC's 8000 Hz while the radio
    consumes at its own ~7970, so a resampler drops (or duplicates) one sample
    now and then. The gain cannot be set in advance, so the repo's own Agc and
    Adpcm run live - both are explicitly stateful for that, and feeding them
    block by block gives the same bytes as a whole clip. The first syllable
    would be lost while the carrier comes up, so the microphone is encoded
    before the header goes out and the backlog is sent first.

    And a microphone does not arrive smoothly. PulseAudio hands over 50 to
    100 ms at a time, and the radio, once keyed, eats continuously: feeding it
    chunk by chunk as they land left it dry between them, which stalls the
    modulator and - past 250 ms - drops the carrier. The first VOX attempt
    came back UNDER with the audio heard as "chirpy". So the encoder feeds a
    jitter buffer, the carrier only goes up once JITTER_MS of audio is in it,
    and a deadline paces the bytes out of it at the rate the radio really
    consumes. The resampler is then servoed on that buffer's own length, which
    is what reflects the clock difference, and the ring fill the radio reports
    is kept as the ceiling it was.
    """
    sys.path.insert(0, os.path.join(ROOT, "App", "apps", "vtxdata"))
    import numpy as np
    import encode_clip as ec

    mic = subprocess.Popen(shlex.split(a.mic_cmd), stdout=subprocess.PIPE,
                           stderr=subprocess.DEVNULL)
    fcntl.fcntl(mic.stdout.fileno(), fcntl.F_SETFL, os.O_NONBLOCK)
    thr = 10.0 ** (a.vox_thr / 20.0)
    print(f"  microphone open, VOX at {a.vox_thr:.0f} dBFS - speak to transmit",
          flush=True)

    BLK = 160                       # 20 ms at 8 kHz
    JITTER_MS = 400                 # audio buffered before the carrier goes up
    Q_TARGET = int(JITTER_MS * BYTES_PER_S / 1000)
    pend = b""                      # microphone bytes not yet a whole block
    q = bytearray()                 # ADPCM waiting to go out: the jitter buffer
    tx = False
    agc = adpcm = None
    drop, acc = 0.004, 0.0          # the clock difference, and its remainder
    last_voice = tx_t0 = hold_off = 0.0
    pace_t0 = 0.0
    sent = 0
    dry = 0                         # times the pacer found the buffer empty
    t_start = time.time()
    while not a.seconds or time.time() - t_start < a.seconds:
        for w in link.pump():
            if (w & 0xF000) == 0x3000:
                print(f"  burst ended: {STATUS.get(w & 0xFF, '?')}"
                      f"{f', {dry} dry' if dry else ''}", flush=True)
                if tx:              # the radio unkeyed on its own: so do we,
                    tx = False      # or tx stays set and nothing keys again
                    agc = adpcm = None
                    q.clear()
                    pend = b""
                    hold_off = time.time() + 1.0
        try:
            got = mic.stdout.read(8192)
        except (BlockingIOError, TypeError):
            got = None
        if got:
            pend += got
        now = time.time()

        while len(pend) >= 2 * BLK:
            blk = np.frombuffer(pend[:2 * BLK], dtype="<i2").astype(np.float64) / 32768.0
            pend = pend[2 * BLK:]
            rms = float(np.sqrt(np.mean(blk * blk)))
            if rms > thr:
                last_voice = now
            if agc is None:                     # start encoding on first voice
                if rms <= thr or now < hold_off or link.playing(a.rx_guard):
                    continue
                agc, adpcm = ec.Agc(), ec.Adpcm()
                print(f"  voice ({20 * math.log10(max(rms, 1e-9)):.0f} dBFS)",
                      flush=True)
            # the resampler, servoed on the jitter buffer rather than on the
            # radio's ring: the buffer is what the clock difference shows in
            drop = max(-0.03, min(0.03, drop + 3e-5 * (len(q) - Q_TARGET)))
            acc += len(blk) * drop
            k = int(acc)
            if k:
                acc -= k
                cut = np.linspace(0, len(blk) - 1, abs(k)).astype(int)
                blk = np.delete(blk, cut) if k > 0 else np.insert(blk, cut, blk[cut])
            q += adpcm(agc(blk))[0]

        # the carrier goes up once there is enough in hand to keep it fed
        if agc is not None and not tx and len(q) >= Q_TARGET:
            link.send(b"VTXS" + struct.pack("<I", 0xFFFFFFFF))
            t0, up = time.time(), False
            while time.time() - t0 < 3.0:
                for w in link.pump():
                    if w == 0x1001:
                        up = True
                    elif (w & 0xF000) == 0x3000:
                        print(f"  refused: {STATUS.get(w & 0xFF, '?')}")
                        t0 = 0.0
                if up or not t0:
                    break
            if not up:
                hold_off = time.time() + 2.0
                print("  no carrier confirmed; holding off 2 s", flush=True)
                agc = adpcm = None
                q.clear()
                continue
            lead = bytes(q[:LEAD])
            del q[:len(lead)]
            link.send(lead)
            print(f"  keyed, {len(lead)} B of lead, {len(q)} B in hand",
                  flush=True)
            tx, tx_t0, pace_t0, dry = True, time.time(), time.time(), 0
            sent = 0                # the lead is the radio's cushion, not pace

        if tx:
            if link.fresh:
                link.fresh = False
            due = int((time.time() - pace_t0) * BYTES_PER_S) - sent
            if due > 0 and link.fill < PANIC:
                take = min(due, 64, len(q))
                if take:
                    link.send(bytes(q[:take]))
                    del q[:take]
                    sent += take
                elif len(q) == 0:
                    dry += 1

        if tx and (now - last_voice > a.vox_hang or now - tx_t0 > a.max_tx):
            why = "silence" if now - last_voice > a.vox_hang else "time limit"
            if q and now - last_voice < a.vox_hang + 1.5:
                continue                        # let the tail out, but not for ever
            print(f"  {why} -> unkeying after {now - tx_t0:.1f} s"
                  f"{f', {dry} dry' if dry else ''}", flush=True)
            link.send(adpcm.flush())
            tx = False                          # the app unkeys after 250 ms
            agc = adpcm = None
            pend = b""
            q.clear()
        if not got and not tx:
            time.sleep(0.004)
    mic.terminate()


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("wav", nargs="?", help="the message, any format ffmpeg reads")
    ap.add_argument("-p", "--port", default="/dev/ttyACM0")
    ap.add_argument("--repeat", type=int, default=1)
    ap.add_argument("--lead-ms", type=int, default=1000,
                    help="silence before the message, for the far squelch")
    ap.add_argument("--watch", action="store_true",
                    help="only print what the app reports, transmit nothing")
    ap.add_argument("--roger", metavar="WAV",
                    help="listen, play what is received, and answer each "
                         "transmission with this clip")
    ap.add_argument("--hang", type=float, default=0.8,
                    help="silence that ends a reception, seconds (the app's "
                         "own gate already holds 600 ms)")
    ap.add_argument("--parrot", action="store_true",
                    help="send back what was just received, as received")
    ap.add_argument("--max-rec", type=float, default=30.0,
                    help="longest recording the parrot sends back, seconds")
    ap.add_argument("--min-rx", type=float, default=0.5,
                    help="ignore a reception shorter than this, seconds")
    ap.add_argument("--listen", action="store_true",
                    help="play the received audio (implied by --roger)")
    ap.add_argument("--fifo", metavar="PATH", nargs="?", const=FIFO,
                    help="hold the port, play what is received, and transmit "
                         f"whatever WAV path is echoed into this pipe "
                         f"(default {FIFO})")
    ap.add_argument("-D", "--device", default="default")
    ap.add_argument("-g", "--gain", type=float, default=2.0)
    ap.add_argument("-s", "--seconds", type=float, default=0.0,
                    help="stop after this long")
    ap.add_argument("--vox", action="store_true",
                    help="listen, and transmit the PC microphone on voice")
    ap.add_argument("--vox-thr", type=float, default=-35.0,
                    help="VOX threshold in dBFS on the raw microphone")
    ap.add_argument("--vox-hang", type=float, default=1.0,
                    help="silence that unkeys, seconds")
    ap.add_argument("--max-tx", type=float, default=120.0,
                    help="longest single transmission, seconds")
    ap.add_argument("--rx-guard", type=float, default=0.6,
                    help="hold the VOX off this long after received audio, "
                         "so open speakers cannot key the radio")
    ap.add_argument("--mic-cmd", default=MIC_CMD,
                    help="the capture command, raw S16_LE mono at 8 kHz")
    ap.add_argument("-q", "--quiet", action="store_true")
    a = ap.parse_args()
    if not (a.wav or a.watch or a.roger or a.vox or a.fifo or a.parrot):
        ap.error("a WAV file, --fifo, --parrot, --vox, --roger or --watch")

    link = Link(a.port, play=(a.listen or bool(a.roger) or a.vox
                              or bool(a.fifo) or a.parrot),
                device=a.device, gain=a.gain)
    try:
        if a.watch:
            print("watching; Ctrl-C to stop", file=sys.stderr)
            while True:
                for w in link.pump():
                    kind = w & 0xF000
                    if kind == 0x1000:
                        print(f"  {'carrier up' if w == 0x1001 else 'receiving'}")
                    elif kind == 0x2000:
                        print(f"  ring {w & 0xFF}")
                    elif kind == 0x3000:
                        print(f"  burst ended: {STATUS.get(w & 0xFF, '?')}")
                time.sleep(0.05)
        if a.parrot:
            parrot_loop(a, link)
            return
        if a.fifo:
            listen_loop(a, link)
            return
        if a.vox:
            vox_loop(a, link)
            return
        if a.roger:
            # Half duplex, automated: listen, play what comes in, and answer
            # each transmission once it has stopped. The app's gate already
            # waits 600 ms after the signal, so the carrier goes up about
            # a.hang later - and this is the one loop that exercises both
            # directions without a human in it.
            n, pay = encode(a.roger, a.lead_ms)
            print(f"  roger: {n} samples, {len(pay)} B of ADPCM, "
                  f"{n / RATE:.2f} s - waiting for a transmission", flush=True)
            t_start = time.time()
            rx_n, rx_last = 0, 0.0
            while not a.seconds or time.time() - t_start < a.seconds:
                before = link.audio
                for w in link.pump():
                    if (w & 0xF000) == 0x3000:
                        print(f"  (burst ended: {STATUS.get(w & 0xFF, '?')})")
                got = link.audio - before
                now = time.time()
                if got:
                    rx_n += got
                    rx_last = now
                elif rx_n and now - rx_last > a.hang:
                    if rx_n >= a.min_rx * RATE:
                        print(f"  heard {rx_n / RATE:.1f} s -> answering",
                              flush=True)
                        print(f"  roger sent: {burst(link, n, pay, False)}")
                    else:
                        print(f"  ignored {rx_n} samples")
                    rx_n, rx_last = 0, 0.0
                else:
                    time.sleep(0.005)
            return
        n, pay = encode(a.wav, a.lead_ms)
        print(f"  {n} samples, {len(pay)} B of ADPCM, {n / RATE:.2f} s")
        for r in range(a.repeat):
            res = burst(link, n, pay, not a.quiet)
            print(f"\nburst {r + 1}/{a.repeat}: {res}, {link.audio} audio samples seen")
            if res != "OK":
                break
            if r + 1 < a.repeat:
                time.sleep(1.0)
    except KeyboardInterrupt:
        pass
    finally:
        link.close()


if __name__ == "__main__":
    main()

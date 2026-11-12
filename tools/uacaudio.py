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
"""Drive the firmware's USB Audio Class: statistics, transmit, record, parrot.

    ./uacaudio.py stats
    ./uacaudio.py rec 10 out.wav
    ./uacaudio.py play clip.wav
    ./uacaudio.py tx 3000
    ./uacaudio.py parrot --hang 1.0

No overlay app is involved: the radio receives through its own UAC capture
interface and transmits from its own UAC playback interface, which is what
tools/afbridge.py needed an app for. ALSA sees one card both ways, so
anything on the host can record or play it.

THE CARRIER ONLY GOES UP ON COMMAND. A PC that merely opens the playback
stream must not key a transmitter, and that is not a hypothetical: PulseAudio
adopts the sink the moment it appears and pushes silence into it for ever -
789800 samples before anyone asked for anything, measured. So `play` streams
the audio AND sends command 0x0752, which names the number of milliseconds
the carrier may stay up; the firmware bounds it at 60 s, refuses if
tx_state() refuses, checks the frequency it reads back against the VFO, and
drops the carrier at the count.

`parrot` is the round trip in one process: record until the far station stops,
then send that recording straight back. Everything in it goes through the
class driver, in both directions.
"""

import argparse, os, struct, subprocess, sys, time, wave

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from mbload import Radio                                  # noqa: E402

CARD = "DEMO"                       # the radio's ALSA card name
RATE = 8000
TX_ERR = {0: "OK", 1: "refused by the radio", 2: "no audio arriving",
          3: "frequency mismatch", 4: "implausible length",
          5: "aborted with EXIT", 6: "timestamp refused"}


def alsa_dev() -> str:
    return f"plughw:CARD={CARD},DEV=0"


def pulse_sink() -> str | None:
    try:
        out = subprocess.run(["pactl", "list", "sinks", "short"],
                             capture_output=True, text=True).stdout
    except FileNotFoundError:
        return None
    for line in out.splitlines():
        if "CDC_DEMO" in line:
            return line.split()[1]
    return None


def stats(radio: Radio) -> tuple:
    radio.send(0x0750, b"")
    d = radio.recv(0x0751, timeout=3.0)
    return struct.unpack_from("<IHHB", d, 0)        # delivered, queued, lost, capturing


def transmit(radio: Radio, ms: int) -> tuple:
    radio.send(0x0752, struct.pack("<HI", ms, radio.ts))
    # the radio answers only once the burst is over: it is modal meanwhile
    d = radio.recv(0x0753, timeout=ms / 1000.0 + 10.0)
    sent, dry, status = struct.unpack_from("<IHB", d, 0)
    return sent, dry, status


def to_raw(path: str) -> tuple[bytes, float]:
    """Any audio file -> raw mono s16 at 8 kHz, through ffmpeg."""
    raw = subprocess.run(["ffmpeg", "-v", "error", "-i", path, "-ac", "1",
                          "-ar", str(RATE), "-f", "s16le", "-"],
                         check=True, capture_output=True).stdout
    return raw, len(raw) / 2 / RATE


def shape(raw: bytes, agc: bool = True, gain: float = 1.0) -> bytes:
    """Bring the audio up to the gain field's scale before sending it.

    The firmware maps PCM straight onto the 7-bit gain field: full-scale s16
    becomes the full +-64 steps of deviation. Audio off the radio's own ADC
    peaks around -12 dBFS and sits near -39 dBFS rms, because the detector
    only swings +-520 of the ADC's +-2048 - so it arrives at +-17 steps of
    gain, with an rms under one step. The first parrot came back almost
    silent for exactly that reason.

    So the host does what encode_clip.py does for the CDC path: its own
    envelope follower and tanh limiter, whose ablation is worth 0.53 -> 0.89
    of correlation on the air. The radio has no business guessing a level.
    """
    import numpy as np
    sys.path.insert(0, os.path.join(os.path.dirname(os.path.dirname(
        os.path.abspath(__file__))), "App", "apps", "vtxdata"))
    import encode_clip as ec
    x = np.frombuffer(raw, dtype="<i2").astype(np.float64) / 32768.0
    if agc:
        x = ec.Agc(target=0.5)(x)
    x = np.clip(x * gain, -1.0, 1.0)
    return (x * 32767.0).astype("<i2").tobytes()


def feed(raw: bytes) -> subprocess.Popen:
    """Start the audio going to the radio, by the least invasive route."""
    sink = pulse_sink()
    if sink:
        p = subprocess.Popen(["paplay", f"--device={sink}", "--raw",
                              "--format=s16le", "--rate", str(RATE),
                              "--channels=1"], stdin=subprocess.PIPE)
    else:   # no PulseAudio: take the device directly
        p = subprocess.Popen(["aplay", "-q", "-D", alsa_dev(), "-t", "raw",
                              "-f", "S16_LE", "-c", "1", "-r", str(RATE)],
                             stdin=subprocess.PIPE)
    p.stdin.write(raw)
    p.stdin.flush()
    return p


def cmd_stats(radio, a):
    delivered, queued, lost, cap = stats(radio)
    print(f"  playback: {delivered} samples delivered, {queued} queued, "
          f"{lost} lost")
    print(f"  capture:  {'streaming' if cap else 'idle'}")


def cmd_tx(radio, a):
    sent, dry, status = transmit(radio, a.ms)
    print(f"  {TX_ERR.get(status, status)}: {sent} samples "
          f"({sent / RATE:.2f} s), {dry} dry")


def cmd_play(radio, a):
    raw, secs = to_raw(a.file)
    print(f"  {os.path.basename(a.file)}: {secs:.2f} s at {RATE} Hz")
    raw = shape(raw, not a.no_agc, a.gain)
    p = feed(raw)
    time.sleep(0.25)                        # let the ring fill first
    ms = int(secs * 1000) + a.margin
    sent, dry, status = transmit(radio, ms)
    print(f"  {TX_ERR.get(status, status)}: {sent} samples "
          f"({sent / RATE:.2f} s), {dry} dry")
    p.stdin.close()
    p.wait()


def cmd_rec(radio, a):
    subprocess.run(["arecord", "-q", "-D", alsa_dev(), "-f", "S16_LE",
                    "-r", str(RATE), "-c", "1", "-d", str(a.seconds), a.out],
                   check=True)
    with wave.open(a.out) as w:
        print(f"  {a.out}: {w.getnframes() / w.getframerate():.2f} s")


def cmd_parrot(radio, a):
    """Record until the far station stops, then send it straight back."""
    import numpy as np
    print(f"  parrot: listening (threshold {a.thr}, hang {a.hang} s)",
          flush=True)
    rec = subprocess.Popen(["arecord", "-q", "-D", alsa_dev(), "-f", "S16_LE",
                            "-r", str(RATE), "-c", "1", "-t", "raw"],
                           stdout=subprocess.PIPE)
    buf = bytearray()
    heard = bytearray()
    last_voice = 0.0
    t_start = time.time()
    try:
        while not a.seconds or time.time() - t_start < a.seconds:
            chunk = rec.stdout.read(1600)           # 100 ms
            if not chunk:
                break
            buf += chunk
            x = np.frombuffer(chunk, dtype="<i2").astype(float)
            rms = float(np.sqrt((x * x).mean()))
            now = time.time()
            if rms > a.thr:
                if not heard:
                    print("  signal", flush=True)
                heard += buf
                buf = bytearray()
                last_voice = now
            elif heard:
                heard += chunk
                if now - last_voice > a.hang:
                    secs = len(heard) / 2 / RATE
                    print(f"  heard {secs:.1f} s -> sending it back",
                          flush=True)
                    rec.send_signal(2)              # stop capturing to transmit
                    rec.stdout.close()
                    rec.wait()
                    p = feed(shape(bytes(heard), not a.no_agc, a.gain))
                    time.sleep(0.25)
                    sent, dry, status = transmit(radio, int(secs * 1000) + a.margin)
                    print(f"  {TX_ERR.get(status, status)}: {sent} samples, "
                          f"{dry} dry")
                    p.stdin.close()
                    p.wait()
                    return
            else:
                del buf[:-RATE]                     # keep half a second of lead
    finally:
        if rec.poll() is None:
            rec.kill()
    print("  nothing heard")


def main():
    p = argparse.ArgumentParser(description=__doc__.splitlines()[0],
                                formatter_class=argparse.RawDescriptionHelpFormatter,
                                epilog=__doc__)
    p.add_argument("-p", "--port", default="/dev/ttyACM0")
    p.add_argument("--margin", type=int, default=250,
                   help="milliseconds of carrier past the clip")
    p.add_argument("--gain", type=float, default=1.0,
                   help="extra gain after the AGC, before clipping")
    p.add_argument("--no-agc", action="store_true",
                   help="send the samples as they are: the gain field will "
                        "see whatever level the file has")
    sub = p.add_subparsers(dest="cmd", required=True)

    s1 = sub.add_parser("stats", help="what the playback endpoint has received")
    s1.set_defaults(func=cmd_stats)

    s2 = sub.add_parser("tx", help="key up for this long, on whatever arrives")
    s2.add_argument("ms", type=int)
    s2.set_defaults(func=cmd_tx)

    s3 = sub.add_parser("play", help="stream a file and transmit it")
    s3.add_argument("file")
    s3.set_defaults(func=cmd_play)

    s4 = sub.add_parser("rec", help="record the radio")
    s4.add_argument("seconds", type=int)
    s4.add_argument("out", nargs="?", default="uac.wav")
    s4.set_defaults(func=cmd_rec)

    s5 = sub.add_parser("parrot", help="record a transmission, then send it back")
    s5.add_argument("--thr", type=float, default=300.0,
                    help="rms that counts as signal, of 32768")
    s5.add_argument("--hang", type=float, default=1.0)
    s5.add_argument("--seconds", type=float, default=120.0)
    s5.set_defaults(func=cmd_parrot)

    a = p.parse_args()
    radio = Radio(a.port)
    try:
        print(f"  radio: {radio.hello()}  (session {radio.ts})")
        a.func(radio, a)
    finally:
        radio.close()


if __name__ == "__main__":
    main()

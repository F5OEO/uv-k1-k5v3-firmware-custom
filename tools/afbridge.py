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

import argparse, base64, json, os, struct, subprocess, sys, tempfile, time

try:
    from serial import Serial
except ImportError:
    sys.exit("pyserial is missing: pip install pyserial")

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
ENCODER = os.path.join(ROOT, "App", "apps", "vtxdata", "encode_clip.py")
RATE = 8000
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
    """The control words coming back, and the audio they are mixed with."""

    def __init__(self, port: str):
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
        out = []
        for w in words:
            if w < 0x1000:
                self.audio += 1
            else:
                out.append(w)
                if (w & 0xF000) == 0x2000:
                    self.fill = w & 0xFF
                    self.fresh = True
        return out

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
        for w in link.poll():
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
        for w in link.poll():
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
        for w in link.poll():
            if (w & 0xF000) == 0x3000:
                return STATUS.get(w & 0xFF, "?")
        time.sleep(0.01)
    return "no verdict"


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
    ap.add_argument("-q", "--quiet", action="store_true")
    a = ap.parse_args()
    if not a.wav and not a.watch:
        ap.error("a WAV file, or --watch")

    link = Link(a.port)
    try:
        if a.watch:
            print("watching; Ctrl-C to stop", file=sys.stderr)
            while True:
                for w in link.poll():
                    kind = w & 0xF000
                    if kind == 0x1000:
                        print(f"  {'carrier up' if w == 0x1001 else 'receiving'}")
                    elif kind == 0x2000:
                        print(f"  ring {w & 0xFF}")
                    elif kind == 0x3000:
                        print(f"  burst ended: {STATUS.get(w & 0xFF, '?')}")
                time.sleep(0.05)
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

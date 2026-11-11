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
"""Speak a message through the radio, streaming it over the USB serial port.

    ./beacon_say.py message.wav
    ./beacon_say.py message.wav --port /dev/ttyACM0

Voice TX 3.1 or later must be running on the radio: while it is, it owns the
USB CDC port, so this is raw bytes and not the framed command protocol that
tools/appload.py speaks.  Nothing is written to flash, which is the point -
a beacon that re-reads the weather every half hour would otherwise erase four
sectors of NOR each time.

The wire format is as small as it can be:

    'V','T','X','S'   the sample count, 32 bits little-endian,
                      then the 3-bit ADPCM stream, 8 codes to three bytes.

The radio answers one line per event: VTX TX, then VTX OK <samples>, or
VTX UNDER <samples> if this end fell behind, VTX DENIED when the radio
refuses to transmit, VTX BADLEN for a count it will not accept.

Pacing matters, and getting it wrong is silent.  The resident port keeps 256
bytes, and app_serial_read does not merely drop the excess when the ring laps:
it FLUSHES the ring and raises APP_SERIAL_LOST.  While the app is idle it
polls every 20 ms, so anything over 256 bytes thrown at it before the burst
starts takes the header away with it and nothing happens at all.

Hence the handshake.  The 8-byte header goes out alone, and the audio only
starts once the radio has answered VTX TX - by then it is inside the sample
loop, draining the port every millisecond.  From there the host stays a little
over a tenth of a second ahead, which fits in the 256 bytes of the port plus
the 128 the app holds.
"""

import argparse, base64, json, math, os, subprocess, sys, tempfile, time

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
ENCODER = os.path.join(ROOT, "App", "apps", "vtxdata", "encode_clip.py")
RATE = 8000
BYTES_PER_S = RATE * 3 / 8          # 3 bits a sample, 3000 B/s
PRIME = 128                         # the first push once the radio is keyed
CHUNK = 24                          # one write is 8 ms of audio
# This is a narrow window.  Too little and the player waits, which costs it a
# millisecond and a restart of its sample clock each time; too much and the
# resident 256-byte ring laps, and app_serial_read does not drop the excess -
# it FLUSHES, so the burst loses everything still in flight.  0.09 s (270 B)
# was measured doing exactly that: VTX UNDER with 273 bytes gone.  0.06 s is
# 180 bytes, which fits the port's 256 even when the app's own 128 are full.
LEAD = 0.06                         # stay this far ahead of the player, in s

try:
    from serial import Serial
except ImportError:
    sys.exit("pyserial is missing: pip install pyserial")


def encode(wav, work):
    clips = os.path.join(work, "clips.json")
    r = subprocess.run([sys.executable, ENCODER, wav, clips, ""],
                       capture_output=True, text=True)
    if r.returncode:
        sys.exit(f"  encoding failed:\n{r.stdout}{r.stderr}")
    print("  " + r.stdout.strip().splitlines()[0])
    d = json.load(open(clips))
    n = d["n"]
    # the blocks are padded for the flash layout; the stream wants neither the
    # padding nor the block split
    raw = b"".join(base64.b64decode(c) for c in d["chunks"])
    need = (n + 7) // 8 * 3
    pay = bytearray()
    for i, c in enumerate(d["chunks"]):
        pay += base64.b64decode(c)
    return n, bytes(pay[:need])


def main():
    p = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    p.add_argument("wav", help="the spoken message, any format ffmpeg reads")
    p.add_argument("-p", "--port", default="/dev/ttyACM0")
    p.add_argument("--timeout", type=float, default=30.0)
    args = p.parse_args()

    work = tempfile.mkdtemp(prefix="say_", dir=os.environ.get("TMPDIR"))
    try:
        n, pay = encode(args.wav, work)
    finally:
        import shutil
        shutil.rmtree(work, ignore_errors=True)
    print(f"  {n} samples, {n / RATE:.2f} s, {len(pay)} B to stream")

    ser = Serial(args.port, 38400, timeout=0.1)
    try:
        ser.dtr = True          # the app only answers a host it can see
        ser.reset_input_buffer()

        # the header alone, then wait to be told the carrier is up
        ser.write(b"VTXS" + n.to_bytes(4, "little"))
        ser.flush()
        rx = bytearray()
        start = time.time()
        while b"VTX TX" not in rx:
            if time.time() - start > 5.0:
                print("  radio: no VTX TX - is Voice TX running and the VFO "
                      "able to transmit?")
                return 1
            rx += ser.read(64) or b""
            if b"VTX DENIED" in rx or b"VTX BADLEN" in rx or b"VTX REFUSED" in rx:
                print("  radio: " + rx.decode("ascii", "replace").strip())
                return 1
        print("  radio: VTX TX")

        ser.write(pay[:PRIME])
        ser.flush()
        t0 = time.monotonic()
        sent = PRIME
        while sent < len(pay):
            # the player has consumed about this much by now
            due = (time.monotonic() - t0) * BYTES_PER_S + LEAD * BYTES_PER_S
            if sent > due:
                time.sleep(0.01)
                continue
            part = pay[sent:sent + CHUNK]
            ser.write(part)
            sent += len(part)
        ser.flush()

        deadline = time.time() + args.timeout
        line = bytearray()
        while time.time() < deadline:
            b = ser.read(64)
            if not b:
                continue
            line += b
            while b"\n" in line:
                one, _, rest = bytes(line).partition(b"\n")
                line = bytearray(rest)
                txt = one.decode("ascii", "replace").strip()
                if txt:
                    print(f"  radio: {txt}")
                if txt.startswith(("VTX OK", "VTX UNDER", "VTX DENIED",
                                   "VTX REFUSED", "VTX BADLEN")):
                    return 0 if txt.startswith("VTX OK") else 1
        print("  radio: no reply - is Voice TX running?")
        return 1
    finally:
        ser.close()


if __name__ == "__main__":
    sys.exit(main())

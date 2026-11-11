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
"""Push a new voice message into the radio's VTX Data slots.

    ./beacon_push.py message.wav
    ./beacon_push.py message.wav --slot0 3 --max-blocks 6

One run is one update of the beacon: encode the WAV with
App/apps/vtxdata/encode_clip.py, build one VTX Data app per block, install
each into its slot over the USB serial port (tools/appload.py), and erase the
slots above the last block.

That last erase matters.  Voice TX scans all 48 slots and takes the highest
block index it finds, so a leftover block from a longer message would be
played after the new one and the sample count would not match.  The slots are
therefore fixed: block i always goes to slot0 + i, and slot0 + N .. the end of
the range is wiped.

Voice TX itself carries no clip, so it is installed once and never touched
here.  It caches the scan at launch, so it has to be relaunched - or left to
exit and be relaunched - after an update for the new message to be seen.

What this does NOT do is key the transmitter: no serial command launches an
app, and a running overlay app does not service the serial port at all.  Until
that is resolved the burst is still started by hand.
"""

import argparse, json, os, shutil, subprocess, sys, tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
VTXDATA = os.path.join(ROOT, "App", "apps", "vtxdata")
sys.path.insert(0, HERE)
import appload as al                                   # noqa: E402


def run(cmd, env=None, cwd=None):
    r = subprocess.run(cmd, env=env, cwd=cwd, capture_output=True, text=True)
    if r.returncode:
        sys.exit(f"  {' '.join(cmd)} failed:\n{r.stdout}{r.stderr}")
    return r.stdout


def main():
    p = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    p.add_argument("wav", help="the spoken message, any format ffmpeg reads")
    p.add_argument("-p", "--port", default="/dev/ttyACM0")
    p.add_argument("--slot0", type=int, default=3,
                   help="1-based slot of block 0 (default 3)")
    p.add_argument("--max-blocks", type=int, default=6,
                   help="slots reserved for the clip; must match BLK_MAX in "
                        "voicetx_app.c (default 6)")
    p.add_argument("--keep", action="store_true",
                   help="leave the work directory for inspection")
    p.add_argument("--lead-ms", type=int, default=1000,
                   help="silence before the message so a receiver's squelch "
                        "opens on the carrier first (default 1000)")
    p.add_argument("--build", default=None,
                   help="how to build one block (default: compile-app.sh, or "
                        "nativebuild/build-native.sh when that exists)")
    args = p.parse_args()

    work = tempfile.mkdtemp(prefix="beacon_", dir=os.environ.get("TMPDIR"))
    try:
        clips = os.path.join(work, "clips.json")
        out = run([sys.executable, os.path.join(VTXDATA, "encode_clip.py"),
                   args.wav, clips, "", "--lead-ms", str(args.lead_ms)])
        print("  " + out.strip().splitlines()[0])
        n = len(json.load(open(clips))["chunks"])
        if n > args.max_blocks:
            sys.exit(f"  the clip needs {n} blocks and only {args.max_blocks} "
                     f"slots are reserved: shorten it, or raise BLK_MAX")

        # compile-app.sh is the repo's way in; the native wrapper is the same
        # script with the pinned toolchain on PATH, so prefer it when present.
        native = os.path.join(ROOT, "nativebuild", "build-native.sh")
        build = (args.build.split() if args.build
                 else ([native, "app", "vtxdata"] if os.path.exists(native)
                       else ["./compile-app.sh", "vtxdata"]))
        env = dict(os.environ, VTX_CLIPS=clips)
        radio = al.Radio(args.port)
        print(f"  radio: {radio.hello()}")
        try:
            for i in range(n):
                run(build, env=dict(env, VTX_CHUNK=str(i)), cwd=ROOT)
                app = os.path.join(ROOT, "build", "Apps", f"VTXData{i}.app")
                al.install(radio, app, args.slot0 - 1 + i)
            for s in range(args.slot0 + n, args.slot0 + args.max_blocks):
                st = radio.slot_erase(s - 1)
                if st:
                    sys.exit(f"  erasing the spare slot {s}: {al.ERR.get(st, st)}")
            print(f"  {n} blocks in slots {args.slot0}..{args.slot0 + n - 1}, "
                  f"{args.slot0 + n}..{args.slot0 + args.max_blocks - 1} cleared")
        finally:
            radio.close()
    finally:
        if args.keep:
            print(f"  work directory kept at {work}")
        else:
            shutil.rmtree(work, ignore_errors=True)


if __name__ == "__main__":
    main()

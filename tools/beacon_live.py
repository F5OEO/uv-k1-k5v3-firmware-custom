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
"""Transmit the PC's microphone live, through the radio.

    ./beacon_live.py --seconds 20
    ./beacon_live.py --open            # until ctrl-C
    ./beacon_live.py --seconds 7 --source plughw:2,0
    ./beacon_live.py --seconds 10 --file message.wav      # rehearse without a mic

Voice TX 3.1 or later must be running on the radio.  This is the same wire
format as beacon_say.py - header, VTX TX, then the ADPCM - but the clip is
produced as it is spoken instead of read from a file, so the encoder runs
block by block (the Agc and Adpcm classes in App/apps/vtxdata/encode_clip.py
keep their state across calls for exactly this).

Latency, measured as buffering rather than guessed: about 30 ms in ffmpeg's
capture, 60 ms of host lead, and what the radio holds, which the player keeps
near the lead because it drains every millisecond.  Call it a tenth to a
sixth of a second from the microphone to the air.  Fine for announcing,
noticeable in a conversation.

Two things make live harder than a file:

  - The burst length normally has to be fixed when it starts, because the
    player is told the sample count up front, so --seconds is a commitment.
    --open sends 0xFFFFFFFF instead, which Voice TX 3.2 reads as "until I
    stop".  ctrl-C then just goes quiet, and the player's underrun guard
    unkeys 250 ms later and reports what it sent - so VTX UNDER is the normal
    end of an open burst, not a fault.
  - The sound card and the radio do not share a clock, and the radio's is
    about 0.6 % slow, so a live source produces samples faster than the radio
    plays them.  Left alone, the backlog laps the radio's ring after a minute
    or so and the burst dies.  This drops one group - one millisecond - when
    the backlog grows past its limit, which works out at roughly six drops a
    second and is not audible on speech.

Keying a handheld for minutes on end is a thermal question, not a software
one: use low power for anything long.
"""

import argparse, os, select, subprocess, sys, time

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, os.path.join(ROOT, "App", "apps", "vtxdata"))
import numpy as np                                      # noqa: E402
import encode_clip as ec                                # noqa: E402

BLOCK = 160                         # 20 ms of microphone at a time
PRIME_MS = 60                       # fresh audio buffered before the first write
CHUNK = 24                          # one write is 8 ms of audio
LEAD_B = 180                        # bytes in flight; see beacon_say.py
DROP_B = 300                        # above this the backlog is trimmed
# What the player actually consumes.  Its sample clock runs about 0.6 % slow
# against the PC's - measured repeatedly as 1.006 on the air - so pacing
# against a nominal 3000 B/s walks the lead upwards: 0.6 % of 7.5 s is 140
# bytes, which pushed it past the radio's ring and lapped 261 bytes off the
# end of a burst that was otherwise clean.
CLOCK = 1.0062
BPS = ec.RATE*3/8/CLOCK

try:
    from serial import Serial
except ImportError:
    sys.exit("pyserial is missing: pip install pyserial")


def drain(ff):
    """Throw away whatever the capture has buffered, without blocking.

    A sound card that has just been woken, or one left running while we waited
    for the radio to key, hands over everything it saved up.  That lump is
    stale by definition - it is older than the moment we start transmitting -
    and feeding it in would only be dropped again by the pacing, a second at a
    time.  Returns the number of samples discarded."""
    fd = ff.stdout.fileno()
    os.set_blocking(fd, False)
    n = 0
    while select.select([fd], [], [], 0.0)[0]:
        chunk = ff.stdout.read(65536)
        if not chunk:
            break
        n += len(chunk)
    os.set_blocking(fd, True)
    return n//4


def capture(args):
    """The sound card, as mono float32 at 8 kHz on stdout.

    arecord rather than ffmpeg, and the reason is worth keeping: ffmpeg hands
    a pipe its audio in whole buffers, measured here at 16000 samples every
    two seconds whatever -flush_packets says.  The player waits 250 ms for its
    first bytes, so that alone ends every live burst in VTX UNDER 0, and the
    lump that follows is then thrown away by the pacing.  arecord with an
    explicit period delivers 160 samples every 20 ms and starts in 25 ms.
    ffmpeg is still right for --file, where -re paces the read for us."""
    if args.file:
        cmd = ["ffmpeg", "-hide_banner", "-loglevel", "error",
               "-re", "-i", args.file,
               "-ac", "1", "-ar", str(ec.RATE), "-f", "f32le", "-"]
    else:
        cmd = ["arecord", "-q", "-D", args.source or "default",
               "-f", "FLOAT_LE", "-r", str(ec.RATE), "-c", "1", "-t", "raw",
               "--period-size", str(BLOCK), "--buffer-size", str(BLOCK*4)]
    return subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)


def main():
    p = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    p.add_argument("-p", "--port", default="/dev/ttyACM0")
    p.add_argument("--seconds", type=float, default=15.0,
                   help="how long to transmit (default 15)")
    p.add_argument("--open", action="store_true",
                   help="transmit until ctrl-C (needs Voice TX 3.2)")
    p.add_argument("--source", help="ALSA capture device (default: default)")
    p.add_argument("--file", help="read this instead of a microphone, in real "
                                  "time, to rehearse the path without one")
    args = p.parse_args()

    OPEN = 0xFFFFFFFF
    n = OPEN if args.open else int(args.seconds*ec.RATE)//8*8
    need = None if args.open else n//8*3   # None: until the operator stops
    agc, adpcm = ec.Agc(), ec.Adpcm()
    ff = capture(args)
    ser = Serial(args.port, 38400, timeout=0.1)
    sent = dropped = 0
    try:
        # Everything here happens BEFORE keying, and all three steps matter.
        # PulseAudio takes a moment to bring a suspended source up while the
        # player waits only 250 ms for its first bytes, so keying first ends
        # in VTX UNDER 0.  Worse, once the device does start it hands over
        # everything it buffered meanwhile - seconds of it - which arrives as
        # one lump the pacing then has to throw away.  So: wait for the device
        # to produce anything, drop whatever it had saved up, and only then
        # buffer a little fresh audio to key on.
        warm = ff.stdout.read(BLOCK*4)
        if not warm:
            err = (ff.stderr.read() or b"").decode("ascii", "replace").strip()
            return say_no(f"no audio from the capture. {err}", ff, ser)
        print(f"  capture running ({drain(ff)} stale samples dropped)")

        ser.dtr = True
        ser.reset_input_buffer()
        ser.write(b"VTXS" + n.to_bytes(4, "little"))
        ser.flush()
        rx = bytearray()
        t = time.time()
        while b"VTX TX" not in rx:
            if time.time() - t > 5.0:
                return say_no("no VTX TX - is Voice TX running?", ff, ser)
            rx += ser.read(64) or b""
            for bad in (b"VTX DENIED", b"VTX BADLEN", b"VTX REFUSED"):
                if bad in rx:
                    return say_no(rx.decode("ascii", "replace").strip(), ff, ser)
        print("  radio: VTX TX - " +
              ("open, ctrl-C to stop" if need is None
               else f"{n/ec.RATE:.1f} s") + ", speak now")

        # Keying takes the radio a moment, and the sound card did not stop
        # during it.  Drain again, or that backlog is the first thing on the
        # air and the pacing spends the burst throwing it away.  Then a little
        # fresh audio to hand over at once: the player waits 250 ms for its
        # first bytes, so priming well inside that keeps it fed without
        # putting the delay into the latency.
        drain(ff)
        q = bytearray()
        while len(q) < PRIME_MS*3:      # 3 bytes a millisecond
            raw = ff.stdout.read(BLOCK*4)
            if not raw:
                return say_no("the capture stopped while priming", ff, ser)
            q += adpcm(agc(np.frombuffer(raw, dtype="<f4").astype(np.float64)))[0]
        t0 = time.monotonic()
        try:
            while need is None or sent < need:
                raw = ff.stdout.read(BLOCK*4)
                if not raw:
                    break
                x = np.frombuffer(raw, dtype="<f4").astype(np.float64)
                q += adpcm(agc(x))[0]

                # played: what the radio has consumed by now.  sent - played
                # is how far ahead of it we are; + len(q) is everything it has
                # yet to hear.  The sound card runs faster than the radio, so
                # that total grows; trim the oldest groups before it laps.
                played = (time.monotonic() - t0)*BPS
                while (sent - played) + len(q) > DROP_B and len(q) >= 3:
                    del q[:3]
                    dropped += 1

                while q and (need is None or sent < need) \
                        and (sent - played) < LEAD_B:
                    k = min(len(q), CHUNK) if need is None \
                        else min(len(q), need - sent, CHUNK)
                    ser.write(q[:k]); sent += k; del q[:k]
                    played = (time.monotonic() - t0)*BPS
        except KeyboardInterrupt:
            print("  stopping")
        ser.flush()
        # Open mode ends by simply going quiet: the player's underrun guard
        # unkeys after 250 ms and reports what it sent.  Dropping DTR does end
        # the burst a millisecond after ctrl-C instead of 250, but then the
        # player cannot report at all - serial_write refuses a port no host is
        # holding, and raising DTR again races its own stopTx.  That check is
        # still worth having for a host that dies or is unplugged; it is just
        # not the way to say "I have finished".

        deadline = time.time() + 10.0
        line = bytearray()
        while time.time() < deadline:
            b = ser.read(64)
            if not b:
                continue
            line += b
            if b"\n" in line:
                txt = bytes(line).split(b"\n")[0].decode("ascii", "replace").strip()
                print(f"  radio: {txt}   ({dropped} groups dropped to the clock)")
                # in open mode the underrun IS the end, not a fault
                good = txt.startswith("VTX OK") or (need is None
                                                    and txt.startswith("VTX UNDER"))
                return 0 if good else 1
        print("  radio: no closing line")
        return 1
    finally:
        ff.terminate()
        ser.close()


def say_no(msg, ff, ser):
    print(f"  radio: {msg}")
    return 1


if __name__ == "__main__":
    sys.exit(main())

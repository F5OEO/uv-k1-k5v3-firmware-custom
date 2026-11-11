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
"""Install overlay apps over the radio's USB serial port, without UV Studio.

    ./appload.py list
    ./appload.py install build/Apps/VTXData1.app 3
    ./appload.py erase 7 8

The point of this is an unattended loop: regenerate a voice clip, push the new
data blocks, transmit.  UV Studio does the same job through Web Serial, which
needs a browser and a human.

Protocol.  The transport is the stock Quansheng frame - 0xABCD, a 16-bit
length, the body XORed with the 16-byte obfuscation table, a CRC-16/XMODEM
over the plain body, then 0xDCBA - implemented in tools/serialtool/msg.py and
reused here.  On top of it this firmware adds the overlay-app slot family
(App/app/uart.c, under ENABLE_FEAT_F4HWN_OVERLAY_APPS):

    0x0730 slot -> 0x0731  read the 64-byte header
    0x0732 slot, pad, ts         -> 0x0733  erase the 8 KiB slot
    0x0734 slot, pad, off, len, ts, data -> 0x0735  program bytes
    0x0736 slot -> 0x0737  validate the header and refresh the Apps menu

Every write is authenticated by the session timestamp the radio latches from
the 0x0514 handshake, so the sequence always starts with that.

A .app file is header(64) + code + assets, and the installer places them at
the slot offsets app_overlay.h gives: header at 0, assets at 0x100, code at
0x1000.

Two things to know before running it.  The radio must be on its normal screen:
a modal overlay app runs its own loop and never calls UART_ServiceCommands, so
nothing is answered while one is open.  And only one program can hold the port
- close UV Studio's connection first, or both read each other's replies.
"""

import argparse, os, struct, sys, time, zlib

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "serialtool"))
import msg as mm                                      # noqa: E402  (path first)

try:
    from serial import Serial
except ImportError:
    sys.exit("pyserial is missing: pip install pyserial")

# app_overlay.h
SLOT_COUNT   = 48
ASSET_OFFSET = 0x100
CODE_OFFSET  = 0x1000
HDR_SIZE     = 64
APP_MAGIC    = 0x31504146                             # "FAP1"

# The radio's receive ring is 256 B and must hold a whole frame, so keep the
# payload well under that: 8 transport + 4 header + 12 fixed + CHUNK.
CHUNK = 128

ERR = {0: "OK", 1: "bad slot", 2: "bad magic", 3: "ABI mismatch",
       4: "not committed", 5: "bad size", 6: "CRC mismatch", 7: "wrong VMA",
       8: "timestamp refused", 9: "missing firmware capability",
       10: "hand-off chain aborted"}


class Radio:
    def __init__(self, port, timeout=2.0, verbose=False):
        self.ser = Serial(port, 38400, timeout=0.2)
        self.buf = bytearray()
        self.timeout = timeout
        self.verbose = verbose
        self.ts = int(time.time()) & 0xFFFFFFFF

    def close(self):
        self.ser.close()

    def send(self, cmd_id, data=b""):
        m = mm.Msg.make(cmd_id, len(data))
        m.buf[4:4 + len(data)] = data
        self.ser.write(mm.make_packet(m.buf))

    def recv(self, want_id, timeout=None):
        """Wait for one reply with the given id, discarding anything else
        (the radio also emits an unsolicited 0x0518 after the handshake)."""
        deadline = time.time() + (timeout or self.timeout)
        while time.time() < deadline:
            self.buf.extend(self.ser.read(256) or b"")
            while True:
                m = mm.fetch(self.buf)
                if m is None:
                    break
                mid = m.get_msg_type()
                if self.verbose:
                    print(f"      <- {mid:#06x} {len(m.buf) - 4} B")
                if mid == want_id:
                    return bytes(m.buf[4:])
        raise TimeoutError(f"no {want_id:#06x} reply")

    def hello(self):
        """0x0514: the radio latches this timestamp as the session id, and
        every slot write is checked against it."""
        self.send(0x0514, struct.pack("<I", self.ts))
        info = self.recv(0x0515)
        ver = info[0:16].split(b"\0")[0].decode("ascii", "replace")
        return ver

    # ---- overlay-app slots ------------------------------------------------
    def slot_info(self, slot):
        self.send(0x0730, bytes([slot]))
        r = self.recv(0x0731)
        return r[1], r[2:2 + HDR_SIZE]                 # status, raw header

    def slot_erase(self, slot):
        self.send(0x0732, bytes([slot, 0]) + struct.pack("<I", self.ts))
        r = self.recv(0x0733, timeout=5.0)             # two sector erases
        return r[1]

    def slot_write(self, slot, offset, data):
        head = bytes([slot, 0]) + struct.pack("<IHI", offset, len(data), self.ts)
        self.send(0x0734, head + data)
        return self.recv(0x0735, timeout=3.0)[1]

    def slot_validate(self, slot):
        self.send(0x0736, bytes([slot]))
        return self.recv(0x0737, timeout=3.0)[1]


def parse_app(path):
    blob = open(path, "rb").read()
    if len(blob) < HDR_SIZE:
        sys.exit(f"{path}: too short to be a .app")
    (magic, _hv, _abi, _api, code_size, code_crc, _entry, flags) = \
        struct.unpack_from("<IHBBIIHH", blob, 0)
    if magic != APP_MAGIC:
        sys.exit(f"{path}: not a .app (magic {magic:#010x})")
    name = blob[20:36].split(b"\0")[0].decode("ascii", "replace")
    ver  = blob[36:52].split(b"\0")[0].decode("ascii", "replace")
    asset_size, asset_crc = struct.unpack_from("<HH", blob, 60)
    header = blob[:HDR_SIZE]
    code   = blob[HDR_SIZE:HDR_SIZE + code_size]
    assets = blob[HDR_SIZE + code_size:]
    if len(code) != code_size:
        sys.exit(f"{path}: truncated, {len(code)} B of code for {code_size}")
    if len(assets) != asset_size:
        sys.exit(f"{path}: {len(assets)} B of assets for {asset_size}")
    if zlib.crc32(code) & 0xFFFFFFFF != code_crc:
        sys.exit(f"{path}: code CRC mismatch in the file itself")
    if asset_size and (zlib.crc32(assets) & 0xFFFF) != asset_crc:
        sys.exit(f"{path}: asset CRC mismatch in the file itself")
    return dict(name=name, ver=ver, flags=flags, header=header,
                code=code, assets=assets)


def install(radio, path, slot, quiet=False):
    app = parse_app(path)
    say = (lambda *a: None) if quiet else print
    say(f"  {os.path.basename(path)}: {app['name']} {app['ver']}, "
        f"{len(app['code'])} B of code + {len(app['assets'])} B of assets "
        f"-> slot {slot + 1}")

    st = radio.slot_erase(slot)
    if st:
        sys.exit(f"  erase refused: {ERR.get(st, st)}")

    # Code and assets first, the header last: a slot that loses power midway
    # then has no valid magic rather than a header promising absent code.
    for off, blob in ((CODE_OFFSET, app["code"]),
                      (ASSET_OFFSET, app["assets"]),
                      (0, app["header"])):
        for i in range(0, len(blob), CHUNK):
            part = blob[i:i + CHUNK]
            st = radio.slot_write(slot, off + i, part)
            if st:
                sys.exit(f"  write at {off + i:#x} refused: {ERR.get(st, st)}")

    st = radio.slot_validate(slot)
    if st:
        sys.exit(f"  validate refused: {ERR.get(st, st)}")

    st, hdr = radio.slot_info(slot)
    if st:
        sys.exit(f"  read-back refused: {ERR.get(st, st)}")
    if hdr != app["header"]:
        sys.exit("  read-back differs from the file's header")
    say("    installed and verified")


def cmd_list(radio, args):
    for slot in range(args.first - 1, args.last):
        st, hdr = radio.slot_info(slot)
        if st or struct.unpack_from("<I", hdr, 0)[0] != APP_MAGIC:
            continue
        name = hdr[20:36].split(b"\0")[0].decode("ascii", "replace")
        ver  = hdr[36:52].split(b"\0")[0].decode("ascii", "replace")
        code_size = struct.unpack_from("<I", hdr, 8)[0]
        asset_size, asset_crc = struct.unpack_from("<HH", hdr, 60)
        print(f"  slot {slot + 1:2d}  {name:<16s} {ver:<6s} "
              f"{code_size:5d} B code  {asset_size:5d} B assets  "
              f"asset crc16 {asset_crc:#06x}")


def main():
    p = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    p.add_argument("-p", "--port", default="/dev/ttyACM0")
    p.add_argument("-v", "--verbose", action="store_true")
    sub = p.add_subparsers(dest="cmd", required=True)
    pl = sub.add_parser("list", help="show the installed apps")
    pl.add_argument("first", nargs="?", type=int, default=1)
    pl.add_argument("last", nargs="?", type=int, default=SLOT_COUNT)
    pi = sub.add_parser("install", help="write a .app into a slot (1-based)")
    pi.add_argument("app")
    pi.add_argument("slot", type=int)
    pe = sub.add_parser("erase", help="wipe one or more slots (1-based)")
    pe.add_argument("slots", type=int, nargs="+")
    args = p.parse_args()

    radio = Radio(args.port, verbose=args.verbose)
    try:
        print(f"  radio: {radio.hello()}  (session {radio.ts})")
        if args.cmd == "list":
            cmd_list(radio, args)
        elif args.cmd == "install":
            install(radio, args.app, args.slot - 1)
        elif args.cmd == "erase":
            for s in args.slots:
                st = radio.slot_erase(s - 1)
                print(f"  slot {s}: {ERR.get(st, st)}")
    finally:
        radio.close()


if __name__ == "__main__":
    main()

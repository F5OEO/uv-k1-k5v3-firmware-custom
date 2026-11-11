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
"""Install a firmware image into a Multiboot slot over the USB serial port.

    ./mbload.py list
    ./mbload.py install build/FFVL/f5oeo.ffvl.bin 1 --name "FFVL audio"
    ./mbload.py validate 1
    ./mbload.py erase 3

This is tools/appload.py's counterpart for the firmware slots: appload writes
the 8 KiB overlay-app slots (0x0730 family), this one writes the 128 KiB
firmware slots (0x0720 family) in external flash, from which ui/multiboot.c
reprograms the internal application flash.

Nothing here touches the running image. A slot is a candidate; the radio only
adopts it when you choose it in the Multiboot selector, which is entered by
holding MENU at power-on - a physical key, with no USB in the path. That is
what makes testing a new image safe: if its USB never enumerates, MENU at
power-on still reaches the selector and slot 0.

Slot 0 is the firmware-managed backup of the running image and is refused
unless --allow-backup is given: overwriting it throws away the one copy the
radio made of a working firmware.

Protocol (App/app/uart.c, under ENABLE_FEAT_F4HWN_MULTIBOOT):

    0x0720 slot                       -> 0x0721  slot, status, 64-byte header
    0x0722 slot, pad, ts              -> 0x0723  slot, status  (erase 128 KiB)
    0x0724 slot, pad, off, len, ts, d -> 0x0725  slot, status
    0x0726 slot                       -> 0x0727  crc32, slot, status

Every write is authenticated by the session timestamp the radio latched from
the 0x0514 handshake. The 64-byte header is written LAST, so an install that
is interrupted leaves a slot with no valid magic rather than a half image
that looks loadable.

Two things to know before running it. The radio must be on its normal screen:
a modal overlay app or the Apps menu never services the UART. And only one
program can hold the port - stop aflisten.sh, afbridge.py and UV Studio first.
"""

import argparse, os, struct, sys, time, zlib

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "serialtool"))
import msg as mm                                      # noqa: E402  (path first)

try:
    from serial import Serial
except ImportError:
    sys.exit("pyserial is missing: pip install pyserial")

# App/driver/mb_flash.h
SLOT_COUNT   = 5                                      # 0 backup + 1..4 user
SLOT_STRIDE  = 0x00020000
IMG_OFFSET   = 0x00001000
INT_APP_SIZE = 0x0001D800                             # 118 KiB
HDR_SIZE     = 64
SLOT_MAGIC   = 0x31424D46                             # "FMB1"
HDR_VERSION  = 1
FLAG_COMMITTED = 1 << 0
NAME_LEN     = 16
VERSION_LEN  = 16

# The radio's receive ring is 256 B and must hold a whole frame: 8 transport
# + 4 header + 12 fixed + CHUNK, as appload.py sizes it.
CHUNK = 128

ERR = {0: "OK", 1: "bad magic", 2: "bad header version", 3: "not committed",
       4: "bad size", 5: "CRC mismatch", 6: "SPI timeout", 7: "bad slot",
       8: "timestamp refused", 9: "RAM load mismatch", 10: "write protected"}


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
        """Read only what is waiting. ser.read(256) blocks until 256 bytes
        arrive or the port's timeout expires, and a slot reply is six bytes:
        every write then cost the whole 200 ms timeout, which is the 638 B/s
        this tool first managed against UV Studio's five seconds for the same
        image."""
        deadline = time.time() + (timeout or self.timeout)
        while time.time() < deadline:
            waiting = self.ser.in_waiting
            if waiting:
                self.buf.extend(self.ser.read(waiting))
            else:
                time.sleep(0.001)
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
        self.send(0x0514, struct.pack("<I", self.ts))
        info = self.recv(0x0515)
        return info[0:16].split(b"\0")[0].decode("ascii", "replace")

    # ---- firmware slots ---------------------------------------------------
    def slot_info(self, slot):
        self.send(0x0720, bytes([slot]))
        r = self.recv(0x0721)
        return r[1], r[2:2 + HDR_SIZE]

    def slot_erase(self, slot):
        self.send(0x0722, bytes([slot, 0]) + struct.pack("<I", self.ts))
        # 128 KiB of NOR: the whole region, one sector at a time
        return self.recv(0x0723, timeout=60.0)[1]

    def slot_write(self, slot, offset, data):
        head = bytes([slot, 0]) + struct.pack("<IHI", offset, len(data), self.ts)
        self.send(0x0724, head + data)
        return self.recv(0x0725, timeout=5.0)[1]

    def slot_validate(self, slot):
        self.send(0x0726, bytes([slot]))
        r = self.recv(0x0727, timeout=20.0)
        # 0x0727 alone puts the CRC first: Crc32, Slot, Status - so the status
        # is byte 5, where every other reply in this family has it at byte 1.
        # Reading byte 4 returns the slot number, which the error table then
        # prints as whatever that number happens to mean.
        crc = struct.unpack_from("<I", r, 0)[0]
        return r[5], crc


def decode_header(h: bytes) -> dict:
    magic, ver, flags, size, crc = struct.unpack_from("<IHHII", h, 0)
    name = h[16:16 + NAME_LEN].split(b"\0")[0].decode("ascii", "replace")
    fw = h[16 + NAME_LEN:16 + NAME_LEN + VERSION_LEN].split(b"\0")[0] \
        .decode("ascii", "replace")
    return {"magic": magic, "ver": ver, "flags": flags, "size": size,
            "crc": crc, "name": name, "fw": fw}


def make_header(image: bytes, name: str, fw: str) -> bytes:
    return struct.pack("<IHHII", SLOT_MAGIC, HDR_VERSION, FLAG_COMMITTED,
                       len(image), zlib.crc32(image) & 0xFFFFFFFF) \
        + name.encode("ascii", "replace")[:NAME_LEN - 1].ljust(NAME_LEN, b"\0") \
        + fw.encode("ascii", "replace")[:VERSION_LEN - 1].ljust(VERSION_LEN, b"\0") \
        + bytes(16)


def cmd_list(radio, a):
    for slot in range(a.first, min(a.last, SLOT_COUNT - 1) + 1):
        status, raw = radio.slot_info(slot)
        if status or struct.unpack_from("<I", raw, 0)[0] != SLOT_MAGIC:
            print(f"  slot {slot}  empty ({ERR.get(status, status)})")
            continue
        h = decode_header(raw)
        flags = "committed" if h["flags"] & FLAG_COMMITTED else "INCOMPLETE"
        tag = "  <- backup of the running image" if slot == 0 else ""
        print(f"  slot {slot}  {h['name']:16s} {h['fw']:10s} "
              f"{h['size']:6d} B  crc {h['crc']:#010x}  {flags}{tag}")


def cmd_install(radio, a):
    image = open(a.image, "rb").read()
    if not image:
        sys.exit(f"{a.image}: empty")
    if len(image) > INT_APP_SIZE:
        sys.exit(f"{a.image}: {len(image)} B exceeds the {INT_APP_SIZE} B "
                 "application region")
    if a.slot == 0 and not a.allow_backup:
        sys.exit("slot 0 is the firmware's own backup of the running image; "
                 "pass --allow-backup only if you mean to throw that away")
    if not 0 <= a.slot < SLOT_COUNT:
        sys.exit(f"slot must be 0..{SLOT_COUNT - 1}")
    if IMG_OFFSET + len(image) > SLOT_STRIDE:
        sys.exit("image does not fit the slot")

    name = a.name or os.path.basename(a.image)[:NAME_LEN - 1]
    crc = zlib.crc32(image) & 0xFFFFFFFF
    print(f"  {os.path.basename(a.image)}: {len(image)} B, crc {crc:#010x} "
          f"-> slot {a.slot} ({name})")

    status = radio.slot_erase(a.slot)
    if status:
        sys.exit(f"    erase failed: {ERR.get(status, status)}")
    print("    erased")

    sent = 0
    t0 = time.time()
    while sent < len(image):
        part = image[sent:sent + CHUNK]
        status = radio.slot_write(a.slot, IMG_OFFSET + sent, part)
        if status:
            sys.exit(f"\n    write at {sent} failed: {ERR.get(status, status)}")
        sent += len(part)
        if sent % (CHUNK * 32) == 0 or sent == len(image):
            rate = sent / max(time.time() - t0, 1e-3)
            print(f"\r    {sent}/{len(image)} B  {rate:5.0f} B/s", end="",
                  flush=True)
    print()

    # The header goes last: an interrupted install then leaves no valid magic
    # rather than a half image that looks loadable.
    status = radio.slot_write(a.slot, 0, make_header(image, name, a.fw))
    if status:
        sys.exit(f"    header failed: {ERR.get(status, status)}")

    status, got = radio.slot_validate(a.slot)
    if status:
        sys.exit(f"    validate failed: {ERR.get(status, status)}")
    if got != crc:
        sys.exit(f"    CRC mismatch: radio {got:#010x}, file {crc:#010x}")
    print(f"    installed and verified, crc {got:#010x}")
    print("  Boot it by holding MENU at power-on and choosing the slot; "
          "slot 0 stays as it was.")


def cmd_validate(radio, a):
    for slot in a.slots:
        status, crc = radio.slot_validate(slot)
        print(f"  slot {slot}: {ERR.get(status, status)}, crc {crc:#010x}")


def cmd_erase(radio, a):
    for slot in a.slots:
        if slot == 0 and not a.allow_backup:
            print("  slot 0 refused (--allow-backup)")
            continue
        print(f"  slot {slot}: {ERR.get(radio.slot_erase(slot), '?')}")


def main():
    p = argparse.ArgumentParser(description=__doc__.splitlines()[0],
                                formatter_class=argparse.RawDescriptionHelpFormatter,
                                epilog=__doc__)
    p.add_argument("-p", "--port", default="/dev/ttyACM0")
    p.add_argument("-v", "--verbose", action="store_true")
    p.add_argument("--allow-backup", action="store_true",
                   help="permit writing slot 0, the backup of the running image")
    sub = p.add_subparsers(dest="cmd", required=True)

    pl = sub.add_parser("list", help="what each firmware slot holds")
    pl.add_argument("first", nargs="?", type=int, default=0)
    pl.add_argument("last", nargs="?", type=int, default=SLOT_COUNT - 1)
    pl.set_defaults(func=cmd_list)

    pi = sub.add_parser("install", help="erase a slot and write an image into it")
    pi.add_argument("image", help="a .bin built for 0x08002800")
    pi.add_argument("slot", type=int)
    pi.add_argument("--name", help=f"label, {NAME_LEN - 1} chars")
    pi.add_argument("--fw", default="", help="version string for the header")
    pi.set_defaults(func=cmd_install)

    pv = sub.add_parser("validate", help="CRC-32 a slot, no reflash")
    pv.add_argument("slots", type=int, nargs="+")
    pv.set_defaults(func=cmd_validate)

    pe = sub.add_parser("erase", help="wipe a slot")
    pe.add_argument("slots", type=int, nargs="+")
    pe.set_defaults(func=cmd_erase)

    a = p.parse_args()
    radio = Radio(a.port, verbose=a.verbose)
    try:
        print(f"  radio: {radio.hello()}  (session {radio.ts})")
        a.func(radio, a)
    finally:
        radio.close()


if __name__ == "__main__":
    main()

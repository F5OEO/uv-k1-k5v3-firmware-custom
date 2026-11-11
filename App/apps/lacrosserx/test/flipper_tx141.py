#!/usr/bin/env python3
"""Generate Flipper Zero Sub-GHz RAW files for LaCrosse RX bench tests.

A TX141TH-Bv2 sensor is already OOK on 433.92 MHz, so unlike the ACARS bench
files these carry the real waveform, not a substitute: 4 preamble pulses of
833 us then 40 PWM bits of 625 us, 12 copies a burst (doc/doc.md 9.5).

Run:
  flipper_tx141.py [out_dir] [--freq 433920000]

Copy the .sub files to subghz/ on the Flipper, tune the radio to the same
frequency in AM, start LaCrosse RX, and send one file at a time. Keep the test
brief and local: 433.92 MHz is shared with everyone's doorbells.
"""

from __future__ import annotations

import argparse
import os

PRESET = "FuriHalSubGhzPresetOok650Async"
DEFAULT_FREQ = 433_920_000
PER_LINE = 512
LEAD_US = 20_000
TAIL_US = 40_000


def digest(data: bytes) -> int:
    """The family's check byte: a keyed LFSR digest over the first 4 bytes,
    message and bytes read backwards (rtl_433 lfsr_digest8_reflect, 0x31,
    0xf4)."""
    total, key = 0, 0xF4
    for byte in reversed(data[:4]):
        for bit in range(8):
            if (byte >> bit) & 1:
                total ^= key
            key = ((key << 1) ^ (0x31 if key & 0x80 else 0)) & 0xFF
    return total


def frame(temp_c: float, humidity: int, sensor_id: int, channel: int = 0,
          battery_low: int = 0, test: int = 0) -> bytes:
    raw = round(temp_c * 10) + 500
    if not 0 <= raw < 4096:
        raise SystemExit(f"temperature {temp_c} C is outside the 12-bit field")
    body = bytes((
        sensor_id & 0xFF,
        ((battery_low & 1) << 7) | ((test & 1) << 6) | ((channel & 3) << 4) | (raw >> 8),
        raw & 0xFF,
        humidity & 0xFF,
    ))
    return body + bytes((digest(body),))


def durations(data: bytes, copies: int = 12, bits: int = 40) -> list[int]:
    """Signed OOK durations in microseconds, positive = carrier on."""
    out = [-LEAD_US]
    for _ in range(copies):
        for _ in range(4):
            out += [833, -833]
        for index in range(bits):
            one = index < 40 and (data[index >> 3] >> (7 - (index & 7))) & 1
            out += [417, -208] if one else [208, -417]
    out.append(-TAIL_US)
    return out


def tune_durations(seconds: float = 5.0, hz: int = 1000) -> list[int]:
    """A carrier keyed at hz, 50 %: something to peak the offset on, since a
    real sensor only speaks every 50 s."""
    half = 500_000 // hz
    out = [-LEAD_US]
    for _ in range(int(seconds * hz)):
        out += [half, -half]
    return out


def write_sub(path: str, values: list[int], frequency: int) -> None:
    lines = [
        "Filetype: Flipper SubGhz RAW File",
        "Version: 1",
        f"Frequency: {frequency}",
        f"Preset: {PRESET}",
        "Protocol: RAW",
    ]
    for index in range(0, len(values), PER_LINE):
        chunk = values[index:index + PER_LINE]
        lines.append("RAW_Data: " + " ".join(str(v) for v in chunk))
    with open(path, "w", encoding="ascii") as stream:
        stream.write("\n".join(lines) + "\n")


def files() -> dict[str, list[int]]:
    ref = frame(21.4, 54, 0xA7, channel=0)
    cold = frame(-7.5, 88, 0x3C, channel=1, battery_low=1)
    hot = frame(60.0, 100, 0xFF, channel=2, test=1)
    bad = bytearray(ref)
    bad[4] ^= 0x20
    return {
        "tx141_ref": durations(ref),
        "tx141_cold": durations(cold),
        "tx141_hot": durations(hot),
        "tx141_bv3": durations(ref, bits=41),
        "tx141_two": durations(ref, copies=2),
        "tx141_single": durations(ref, copies=1),
        "tx141_badchk": durations(bytes(bad)),
        "tx141_tune": tune_durations(),
    }


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("out_dir", nargs="?", default="flipper")
    parser.add_argument("--freq", type=int, default=DEFAULT_FREQ)
    args = parser.parse_args()
    if not 300_000_000 <= args.freq <= 348_000_000 and \
       not 387_000_000 <= args.freq <= 464_000_000 and \
       not 779_000_000 <= args.freq <= 928_000_000:
        raise SystemExit(f"{args.freq} Hz is outside the CC1101 operating ranges")
    os.makedirs(args.out_dir, exist_ok=True)
    for name, values in files().items():
        path = os.path.join(args.out_dir, name + ".sub")
        write_sub(path, values, args.freq)
        print(f"{path}: {len(values)} durations")


if __name__ == "__main__":
    main()

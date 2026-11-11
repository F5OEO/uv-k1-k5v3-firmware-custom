#!/usr/bin/env python3
# Read-only assets of the AF Bridge overlay: the UI texts and one icon.
import os
import sys

sys.dont_write_bytecode = True
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(HERE, ".."))
from app_assets import Assets

TITLE = "AF Bridge"
UI = [
    ("T_TITLE", TITLE),
    ("T_RX", "RX"),
    ("T_AIR", "ON AIR"),
    ("T_SQ", " SQ"),
    ("T_RAW", " RAW"),
    ("T_OUT", "OUT "),
    ("T_KB", "kB "),
    ("T_PP", " PP "),
    ("T_IN", "IN "),
    ("T_FILL", " FILL "),
    ("T_OVR", "OVR "),
    ("T_TO", " TO "),
    ("T_ST", " ST "),
    ("T_C", " C"),
    ("T_STAT", " OK UND DEN MIS LEN TOT"),
]
a = Assets("AF_BRIDGE")
ui_size = 0
for name, value in UI:
    pad = -(len(value) + 1) % 4
    a.text(name, value + "\0" * pad)
    ui_size += len(value) + 1 + pad
a.const("UI_SIZE", ui_size)
a.const("T_TITLE_CHARS", len(TITLE))
a.u8("BMP_USB", [0x00, 0x1C, 0x22, 0x22, 0x7F, 0x08, 0x08, 0x3E, 0x00, 0x00])
a.const("ICON_W", 10)
a.main()

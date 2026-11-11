#!/usr/bin/env python3
# Read-only assets of the LaCrosse RX overlay: the UI texts and one icon.
import os
import sys

sys.dont_write_bytecode = True
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(HERE, ".."))
from app_assets import Assets

TITLE = "LaCrosse"
UI = [
    ("T_TITLE", TITLE),
    ("T_NODATA", "waiting 433.920 AM"),
    ("T_SETAM", "VFO IS NOT AM"),
    ("T_RH", "RH "),
    ("T_PCT", "%"),
    ("T_BATLOW", "BAT LOW"),
    ("T_ID", "ID "),
    ("T_CH", " CH"),
    ("T_PATH", " RAW WID STK"),
    ("T_AUTO", " AUTO"),
    ("T_EV", "E"),
    ("T_CL", " C"),
    ("T_PK", " P"),
    ("T_OVR", " O"),
    ("T_DBM", "dBm"),
    ("T_RX", "RX "),
    ("T_K", "k"),
    ("T_DEG", "C"),
]
a = Assets("LACROSSE_RX")
ui_size = 0
for name, value in UI:
    pad = -(len(value) + 1) % 4
    a.text(name, value + "\0" * pad)
    ui_size += len(value) + 1 + pad
a.const("UI_SIZE", ui_size)
a.const("T_TITLE_CHARS", len(TITLE))
# Status-bar icons, 10 columns each: the thermometer and the beep bell.
a.u8("BMP_TEMP", [0x00, 0x7C, 0x82, 0x82, 0xFE, 0x82, 0x82, 0x7C, 0x00, 0x00])
a.u8("BMP_BEEP", [0x1C, 0x1C, 0x3E, 0x7F, 0x00, 0x22, 0x1C, 0x41, 0x22, 0x1C])
a.const("ICON_W", 10)
a.main()

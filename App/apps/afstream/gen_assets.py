#!/usr/bin/env python3
# Read-only assets of the AF Stream overlay: the UI texts.
import os
import sys

sys.dont_write_bytecode = True
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(HERE, ".."))
from app_assets import Assets

TITLE = "AF Stream"
UI = [
    ("T_TITLE", TITLE),
    ("T_OFF", "STOPPED - MENU starts"),
    ("T_WAIT", "no host on the port"),
    ("T_FS", "FS "),
    ("T_HZ", "Hz "),
    ("T_KB", "kB "),
    ("T_OVR", "OVR "),
    ("T_TO", " TO "),
    ("T_PATH", " STK RAW"),
    ("T_GATE", " OFF SQL LVL"),
    ("T_SQ", " SQ"),
    ("T_LVL", "PP "),
    ("T_DBM", "dBm"),
]
a = Assets("AF_STREAM")
ui_size = 0
for name, value in UI:
    pad = -(len(value) + 1) % 4
    a.text(name, value + "\0" * pad)
    ui_size += len(value) + 1 + pad
a.const("UI_SIZE", ui_size)
a.const("T_TITLE_CHARS", len(TITLE))
# Status-bar icon: a small USB plug, 10 columns, lit while a host is reading.
a.u8("BMP_USB", [0x00, 0x1C, 0x22, 0x22, 0x7F, 0x08, 0x08, 0x3E, 0x00, 0x00])
a.const("ICON_W", 10)
a.main()

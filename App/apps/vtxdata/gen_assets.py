#!/usr/bin/env python3
# VTX Data: one block of the Voice TX clip, carried in this app's asset area.
#
#   VTX_CHUNK=0 ./gen_assets.py vtxdata_assets.bin vtxdata_assets.h
#
# Voice TX carries no clip, so every block is one of these, VTX_CHUNK=0 up to
# however many the message needs, each installed in a slot of its own.
#
# The clip is 'Balise de Massogne, nord-nord-est, 15 kilomètres heure, 26
# maximum.', spoken by the Piper neural voice fr_FR-upmc-medium, speaker
# jessica, then trimmed, 8 kHz, a second of silence so a receiver's squelch
# opens on the carrier first, AGC (5 ms / 150 ms, up to +21 dB, target 0.35)
# and a tanh limiter, then 3-bit IMA ADPCM: 45240 samples, 5.66 s, 18.9 dB,
# 16965 B over 5 blocks of 3831. encode_clip.py beside this file does all of
# it, and the exact command is in its docstring - the lead-in is not the
# default, so it has to be asked for.
#
# A block is 8 header bytes - 'V','T','X', the block index, then the total
# sample count little-endian - followed by its share of the stream. Voice TX
# finds the blocks by scanning the app store (0x102000 + slot * 0x2000, assets
# at +0x100) for that signature, so the blocks can sit in any slots and in any
# order. 3831 B of payload is 1277 whole groups of 8 codes, so a group never
# straddles two blocks.
#
# Every block is padded to the same BLOCK_PAY payload, the last one included.
# That is an unexplained fix rather than a diagnosis: while the last block was
# short (3216 B against 3831) block 2 came out wrong on the air from its first
# sample, 0.396 and 0.385 of correlation on two bursts, and padding gave 0.881.
# It is not an overrun - the player stops on the sample count, which falls
# exactly on byte 3216 of block 2, so the bytes beyond it are only prefetched.
# The padding stays because it is what the passing burst ran.
import base64, json, os, sys
sys.dont_write_bytecode = True
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
from app_assets import Assets

HERE = os.path.dirname(os.path.abspath(__file__))
# VTX_CLIPS lets a host loop build from a freshly encoded clip without writing
# into the tree; the committed clips.json is the default.
d = json.load(open(os.environ.get("VTX_CLIPS") or os.path.join(HERE, "clips.json")))
idx = int(os.environ.get("VTX_CHUNK", "0"))
payload = base64.b64decode(d["chunks"][idx])
payload = payload.ljust(d["pay"], b"\0")   # all blocks the same length
n = d["n"]
head = bytes([ord('V'), ord('T'), ord('X'), idx,
              n & 255, (n >> 8) & 255, (n >> 16) & 255, (n >> 24) & 255])

a = Assets("VTXDATA")
a.raw("BLOCK", head + payload)
a.const("BLOCK_IDX", idx)
a.main()

#!/usr/bin/env python3
# VTX Data: one block of the Voice TX clip, carried in this app's asset area.
#
#   VTX_CHUNK=1 ./gen_assets.py vtxdata_assets.bin vtxdata_assets.h
#
# Block 0 is Voice TX's own asset, so this app is built once for each of
# VTX_CHUNK=1, 2, 3 and 4, and each build installed in a slot of its own.
#
# The clip is 'Balise du 86, vent nord-est, 25 kilomètres heure, 30 maximum.',
# spoken by the Piper neural voice fr_FR-upmc-medium, speaker jessica, then
# trimmed, 8 kHz, AGC (5 ms / 150 ms, up to +21 dB, target 0.35) and a tanh
# limiter, then 3-bit IMA ADPCM: 42632 samples, 5.33 s, 18.7 dB, 15987 B over
# 5 blocks of 3831. ../voicetx/encode_clip.py does all of it.
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

# There is one clips.json, next to the app that plays it: two copies could
# drift apart and the blocks would no longer belong to the same clip.
HERE = os.path.dirname(os.path.abspath(__file__))
d = json.load(open(os.path.join(HERE, "..", "voicetx", "clips.json")))
idx = int(os.environ.get("VTX_CHUNK", "1"))
payload = base64.b64decode(d["chunks"][idx])
payload = payload.ljust(d["pay"], b"\0")   # all blocks the same length
n = d["n"]
head = bytes([ord('V'), ord('T'), ord('X'), idx,
              n & 255, (n >> 8) & 255, (n >> 16) & 255, (n >> 24) & 255])

a = Assets("VTXDATA")
a.raw("BLOCK", head + payload)
a.const("BLOCK_IDX", idx)
a.main()

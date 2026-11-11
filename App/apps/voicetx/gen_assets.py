#!/usr/bin/env python3
# Voice TX asset: block 0 of the clip. Blocks 1.. are carried by App/apps/vtxdata.
#
#   ./gen_assets.py voicetx_assets.bin voicetx_assets.h
#
# The clip is 'Balise du 86, vent nord-est, 25 kilomètres heure, 30 maximum.',
# spoken by the Piper neural voice fr_FR-upmc-medium, speaker jessica, then
# trimmed, 8 kHz, AGC (5 ms / 150 ms, up to +21 dB, target 0.35 of full scale)
# and a tanh limiter so speech's 12 dB of crest factor does not waste the gain
# field, then 3-bit IMA ADPCM: 42632 samples, 5.33 s, 18.7 dB, 15987 B over 5
# blocks of 3831. encode_clip.py in App/apps/voicetx does all of it.
#
# A block is 8 header bytes - 'V','T','X', the block index, then the total
# sample count little-endian - and then its share of the stream. Voice TX
# finds every block by scanning the app store for that signature, so this one
# is only special in being the app's own. 3831 B of payload is 1277 whole
# groups of 8 codes, so a group never straddles two blocks.
#
# The step table lives in the app's code: the asset area is full.
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
d = json.load(open(os.path.join(HERE, "clips.json")))
n = d["n"]
head = bytes([ord('V'), ord('T'), ord('X'), 0,
              n & 255, (n >> 8) & 255, (n >> 16) & 255, (n >> 24) & 255])

a = Assets("VOICETX")
a.raw("BLOCK", head + base64.b64decode(d["chunks"][0]).ljust(d["pay"], b"\0"))
a.const("CLIP_SAMPLES", n)
a.const("CLIP_RATE", 8000)
a.const("BLOCK_PAY", d["pay"])
a.main()

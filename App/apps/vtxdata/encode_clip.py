#!/usr/bin/env python3
"""An audio file -> clips.json for App/apps/voicetx, plus a rendering of what
the air path does to it.

    ./encode_clip.py voice.wav clips.json "the text, for the record"
    ./encode_clip.py voice.wav clips.json "..." --lead-ms 1000

It reads an audio file, not text: synthesise first and keep the WAV.  The clip
in clips.json came from Piper (neural, offline, see doc/doc.md section 8.4):

    piper -m fr_FR-upmc-medium.onnx -s 0 --sentence-silence 0.0 \
          -f upmc_jessica.wav <<< "Balise du 86, vent nord-est, 25 kilometres \
          heure, 30 maximum."

at the default length scale.

ATTRIBUTION.  fr_FR-upmc-medium is a Piper voice (rhasspy/piper-voices) trained
on the UPMC Pierre corpus, https://github.com/marytts/upmc-pierre-data, which
is licensed CC BY-SA 4.0: http://creativecommons.org/licenses/by-sa/4.0/.  The
encoded clip in clips.json derives from that voice, so the share-alike term
reaches that file even though the rest of this tree is Apache-2.0.  The other
French voice tried, fr_FR-siwis-medium, is CC BY 4.0 and carries no
share-alike, if that ever matters more than the timbre.

Piper's output is NOT reproducible - VITS draws noise on every run, so the
same command gives a slightly different render and a different duration.  The
render that made this clip is therefore kept beside this script as
upmc_jessica.wav, and re-encoding it reproduces clips.json byte for byte:

    ./encode_clip.py upmc_jessica.wav clips.json "Balise du 86, ..."

The chain after that is the one measured on 2026-11-10: 8 kHz, an AGC and a
tanh limiter so speech's crest factor does not waste the gain field, 3-bit IMA
ADPCM, then the decoder's 16-bit predictor driving REG_70 <14:8> as
64 + (pred >> 9).  Besides clips.json it writes three WAVs next to it: the
source at 8 kHz, the clip as the air delivers it, and the same with a 750 us
de-emphasis, so a voice can be judged before anything is flashed.  That last
stage is a model of the receiver, not a measurement.
"""
import argparse, base64, json, math, os, subprocess, sys, wave
import numpy as np

RATE = 8000
BLOCK_PAY = 3831                 # 1277 whole groups of 8 codes
STEP = [7,8,9,10,11,12,13,14,16,17,19,21,23,25,28,31,34,37,41,45,50,55,60,66,
        73,80,88,97,107,118,130,143,157,173,190,209,230,253,279,307,337,371,
        408,449,494,544,598,658,724,796,876,963,1060,1166,1282,1411,1552,1707,
        1878,2066,2272,2499,2749,3024,3327,3660,4026,4428,4871,5358,5894,6484,
        7132,7845,8630,9493,10442,11487,12635,13899,15289,16818,18500,20350,
        22385,24623,27086,29794,32767]
ADJ = [-1,-1,2,4]

# ---------------------------------------------------------------- front end
def load_8k(path):
    """Any audio file -> mono float32 at 8 kHz, via ffmpeg (scipy is broken
    against numpy 2 on this machine)."""
    out = subprocess.run(
        ["ffmpeg","-v","error","-i",path,"-ac","1","-ar",str(RATE),
         "-f","f32le","-"], check=True, capture_output=True).stdout
    return np.frombuffer(out, dtype="<f4").astype(np.float64)

def trim(x, thr_db=-45.0, pad_ms=20):
    """Drop leading and trailing silence, keeping a short pad."""
    k = RATE // 100                                   # 10 ms frames
    f = x[:len(x)//k*k].reshape(-1, k)
    e = 20*np.log10(np.sqrt((f**2).mean(1)) + 1e-12)
    live = np.flatnonzero(e > e.max() + thr_db)
    if len(live) == 0:
        return x
    pad = pad_ms*RATE//1000
    a = max(0, live[0]*k - pad)
    b = min(len(x), (live[-1]+1)*k + pad)
    return x[a:b]

class Agc:
    """One-sided envelope follower, then a tanh limiter.  Speech has about
    12 dB of crest factor; without this it uses a tenth of the gain field.

    Stateful so a live source can be fed block by block: the envelope carries
    across calls, and feeding the whole clip at once gives the same samples as
    feeding it in pieces."""

    def __init__(self, target=0.35, attack_ms=5.0, release_ms=150.0,
                 max_gain_db=21.0):
        self.aa = math.exp(-1.0/(attack_ms*RATE/1000.0))
        self.ar = math.exp(-1.0/(release_ms*RATE/1000.0))
        self.gmax = 10.0**(max_gain_db/20.0)
        self.target = target
        self.env = 0.0

    def __call__(self, x):
        aa, ar, gmax, target = self.aa, self.ar, self.gmax, self.target
        env = self.env
        y = np.empty_like(x)
        for i, s in enumerate(x):
            a = abs(s)
            env = a + (aa if a > env else ar)*(env - a)
            g = min(gmax, target/env) if env > 1e-6 else gmax
            y[i] = s*g
        self.env = env
        return np.tanh(y)


def agc(x, **kw):
    return Agc(**kw)(x)

# ---------------------------------------------------------------- ADPCM
class Adpcm:
    """3-bit IMA ADPCM, eight codes packed LSB-first into every three bytes.

    Stateful for the same reason as Agc.  Codes that do not fill a group are
    held back until the next call, so the byte stream is identical however the
    input is cut up; flush() pads the last group out."""

    def __init__(self):
        self.pred = 0
        self.idx = 0
        self.codes = []

    def __call__(self, x):
        q = np.clip(np.round(x*32767.0), -32768, 32767).astype(np.int64)
        pred, idx, codes, rec = self.pred, self.idx, self.codes, []
        for s in q:
            step = STEP[idx]
            d = int(s) - pred
            code = 4 if d < 0 else 0
            d = abs(d)
            if d >= step:                   # bit <1>
                code |= 2; d -= step
            if d >= step >> 1:              # bit <0>
                code |= 1
            diff = step >> 2
            if code & 2: diff += step
            if code & 1: diff += step >> 1
            pred = pred - diff if code & 4 else pred + diff
            pred = max(-32768, min(32767, pred))
            idx = max(0, min(88, idx + ADJ[code & 3]))
            codes.append(code); rec.append(pred)
        self.pred, self.idx = pred, idx
        return self._take(), np.array(rec, dtype=np.int64)

    def flush(self):
        if self.codes:
            while len(self.codes) % 8:      # a near-zero step, never heard
                self.codes.append(self.codes[-1] & 4)
        return self._take()

    def _take(self):
        out = bytearray()
        n = len(self.codes)//8*8
        for i in range(0, n, 8):
            w = 0
            for k in range(8):
                w |= self.codes[i+k] << (3*k)
            out += bytes((w & 255, (w >> 8) & 255, (w >> 16) & 255))
        del self.codes[:n]
        return bytes(out)


def encode(x):
    enc = Adpcm()
    data, rec = enc(x)
    return data + enc.flush(), rec

def decode(pk, n):
    """The decoder the C player runs, ported from the analysis script that
    scored 0.93 against the air."""
    pred, idx, out = 0, 0, []
    for i in range(0, len(pk) - 2, 3):
        w = pk[i] | (pk[i+1] << 8) | (pk[i+2] << 16)
        for k in range(8):
            c = (w >> (3*k)) & 7
            step = STEP[idx]
            diff = step >> 2
            if c & 2: diff += step
            if c & 1: diff += step >> 1
            pred = pred - diff if c & 4 else pred + diff
            pred = max(-32768, min(32767, pred))
            idx = max(0, min(88, idx + ADJ[c & 3]))
            out.append(pred)
            if len(out) >= n:
                return np.array(out, dtype=np.int64)
    return np.array(out, dtype=np.int64)

# ---------------------------------------------------------------- the air
def gain_field(rec):
    """What the app writes into REG_70 <14:8>."""
    return np.clip(64 + (rec >> 9), 0, 127).astype(np.float64)

def through_channel(v, deemph=False):
    """Deviation is affine in the gain, so the demodulated audio is the gain
    sequence less its DC, band-limited by the receiver's audio path."""
    y = v - v.mean()
    # 300-3000 Hz, the FM audio path, as a pair of one-pole sections
    def hp(s, fc):
        a = math.exp(-2*math.pi*fc/RATE); o = np.empty_like(s); z = 0.0
        for i, t in enumerate(s):
            z = a*z + (1-a)*t; o[i] = t - z
        return o
    def lp(s, fc):
        a = math.exp(-2*math.pi*fc/RATE); o = np.empty_like(s); z = 0.0
        for i, t in enumerate(s):
            z = a*z + (1-a)*t; o[i] = z
        return o
    y = lp(hp(hp(y, 300.0), 300.0), 3000.0)
    if deemph:                      # 750 us, if the receiver de-emphasises
        y = lp(y, 1.0/(2*math.pi*750e-6))
    return y/ (np.abs(y).max() + 1e-12)

def wav(path, y, rate=RATE):
    with wave.open(path, "wb") as w:
        w.setnchannels(1); w.setsampwidth(2); w.setframerate(rate)
        w.writeframes(np.clip(y*32767, -32768, 32767).astype("<i2").tobytes())

# ---------------------------------------------------------------- driver
def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("src")
    ap.add_argument("out_json")
    ap.add_argument("txt", nargs="?", default="")
    ap.add_argument("--lead-ms", type=int, default=0,
                    help="silence before the message, to let a receiver's "
                         "squelch open on the carrier first (default none)")
    a = ap.parse_args()
    src, out_json, txt = a.src, a.out_json, a.txt
    x = agc(trim(load_8k(src)))
    # After the AGC, so the lead-in stays exact zeros: the coder then holds
    # its predictor at 0 and the gain field at 64, which is an unmodulated
    # carrier - what a noise squelch needs, and it needs it before the first
    # word, not during it.
    if a.lead_ms:
        x = np.concatenate([np.zeros(a.lead_ms*RATE//1000), x])
    x = x[:len(x) // 8 * 8]          # whole groups of eight codes
    pk, rec = encode(x)
    n = len(x)
    chunks = [pk[i:i+BLOCK_PAY].ljust(BLOCK_PAY, b"\0")
              for i in range(0, len(pk), BLOCK_PAY)]

    # the encoder's own reconstruction must equal what the player decodes
    assert np.array_equal(rec[:n], decode(b"".join(chunks), n)[:n]), \
        "encoder and decoder disagree"

    json.dump({"n": n, "pay": BLOCK_PAY, "txt": txt,
               "chunks": [base64.b64encode(c).decode() for c in chunks]},
              open(out_json, "w"))

    v = gain_field(rec[:n])
    base = os.path.splitext(out_json)[0]
    wav(base + "_src.wav", x)
    wav(base + "_air.wav", through_channel(v))
    wav(base + "_air_deemph.wav", through_channel(v, deemph=True))
    seg = 10*np.log10(np.sum(x**2)/(np.sum((x - rec[:n]/32767.0)**2) + 1e-18))
    print(f"{os.path.basename(src):22s} {n/RATE:5.2f} s  {n:6d} smp  "
          f"{len(pk):6d} B  {len(chunks)} blocks  ADPCM {seg:4.1f} dB  "
          f"gain {int(v.min())}-{int(v.max())}")
    for i, c in enumerate(chunks):
        print(f"    block {i}: sum {sum(c) & 0xffff}")

if __name__ == "__main__":
    main()

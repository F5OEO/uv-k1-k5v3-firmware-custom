/* Copyright 2026 Evariste F5OEO
 * https://github.com/F5OEO
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *     Unless required by applicable law or agreed to in writing, software
 *     distributed under the License is distributed on an "AS IS" BASIS,
 *     WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *     See the License for the specific language governing permissions and
 *     limitations under the License.
 */

/*
 * Voice TX - plays a recorded clip from external flash over the transmitter,
 * through the BK4829's tone generator used as a baseband DAC.
 *
 * The route, measured with App/apps/pllfm on 2026-11-10 and written up in
 * doc/doc.md section 8.4:
 *   - REG_38/39 written at sample rate do NOT modulate.  A frequency write
 *     takes effect only after a REG_30 toggle, and that toggle blanks the
 *     carrier for 108 us, so direct FM through the PLL is dead.
 *   - REG_70 <14:8>, the Tone 1 gain, IS live: aprstx rewrites it every
 *     833 us (aprstx_app.c:290) and it takes effect instantly.
 *   - A zero frequency word FREEZES the tone DDS phase rather than clearing
 *     it.  Run Tone 1 at 32 Hz, wait a quarter period, write REG_71 = 0, and
 *     the generator holds its peak: the gain field now scales a DC, and
 *     writing samples into it is baseband modulation.  7 bits, one 80 us
 *     register write per sample, no REG_30, no blanking; pllfm's GAIN mode
 *     measured 3.2 kHz of deviation at Fs = 8 kHz this way.
 *
 * Where the clip lives.  The factory voice prompts used to sit at 0x14d000
 * with an index at 0x14c000 / 0x14c800 (App/audio.c:201-245), but this
 * firmware's overlay-app store spans 0x102000 to 0x160000
 * (app_overlay.h:37), so that region is gone - reading the index here
 * returns app data, not clip records.  The clip is therefore carried in the
 * app's own asset block, which is external flash all the same: 3840 B at
 * offset 0x100 of the slot's header sector, read with sys_storage_read at
 * the absolute address the scan below works out.
 *
 * THIS APP CARRIES NO CLIP.  Every block of it is an App/apps/vtxdata
 * installed in a slot of its own, block 0 included, so a new message is
 * pushed by rewriting those slots and this player is installed once and left
 * alone - which is what tools/appload.py does over the USB serial port,
 * without UV Studio and without a human.  The clip as it stands is "Balise du
 * 86, vent nord-est, 25 kilometres heure, 30 maximum.", 5.33 s at 8 kHz,
 * 3-bit IMA ADPCM, 18.7 dB, 15987 B over five blocks, spoken by the Piper
 * neural voice fr_FR-upmc-medium, speaker jessica (vtxdata/encode_clip.py has
 * the whole chain and the licence that voice carries).  The store is a plain
 * array - 0x102000 +
 * slot * 0x2000, assets at +0x100 (app_overlay.h:37) - and sys_storage_read
 * addresses it directly, so at startup this app SCANS the 48 slots for the
 * 8-byte signature 'V','T','X',index followed by the total sample count, and
 * plays the blocks in index order whatever slots they landed in.  3831 B of
 * payload is 1277 whole groups of 8 codes, so a group never straddles two
 * blocks, and every block is padded to that length.  The padding is an
 * unexplained fix, not a diagnosis: with an earlier clip whose last block was
 * short (3216 B against 3831) that block came out wrong on the air from its
 * first sample, 0.396 and 0.385 of correlation on two bursts, and padding
 * gave 0.881.  The player cannot read past a clip - it stops on the sample
 * count, which fell exactly on byte 3216 of that block, and the bytes beyond
 * were only prefetched by the 15-byte read - so the cause is still open and
 * the padding stays because it is what the passing burst ran.
 *
 * The on-screen K values are the blocks' byte sums as the flash holds them,
 * against 10359 / 60992 / 63898 / 60285 / 2190 from the encoder, which is
 * how an install is checked without taking the radio apart.
 *
 * Measured on the air on 2026-11-11, a UV-K1 at 143.98750 MHz received on a
 * Maia SDR at 25 ksps and correlated against the gain sequence written:
 * 0.946, 0.952, 0.963 and 0.963 on the four full blocks fitted separately,
 * 708 Hz rms of deviation, the joins regular to a tenth of a millisecond; and
 * at that alignment 0.963 over the whole 5.36 s, 11.1 dB of SNR, with the
 * 0.5 s windows running 0.93 to 0.99 from one end to the other.  The
 * espeak-ng clip this replaced measures 0.946 and 9.3 dB the same way, so the
 * neural voice is 1.8 dB better on the air as well as better in the ear - the
 * ADPCM also has an easier job with it, 18.7 dB against 14.8.
 *
 * Two traps in measuring that, both of which bit:
 *   - Do NOT fit the clock by sliding the whole clip against the burst.  With
 *     the reference nearly as long as the recording, numpy's "valid"
 *     correlation leaves 314 lags where the true offset is 330, so the search
 *     buys a reachable lag with a wrong clock and reports 0.806.  Fit on the
 *     blocks, then correlate the whole clip at that alignment.
 *   - Cut the last 30 ms.  stopTx drops the carrier, the phase runs away as
 *     the envelope collapses and the demodulator makes one 13 kHz spike
 *     against 681 Hz rms.  Inside the 0.22 s last block that single spike
 *     reads as 0.491 instead of 0.975, which looks exactly like the
 *     short-block fault above and is not it.
 *
 * Eight codes are packed LSB-first into every three bytes.  The decoder's
 * predictor is 16-bit and its top 7 bits are the gain: 64 + (pred >> 9).
 *
 * Timing: 6000 cycles a sample, of which one register write takes about
 * 3850.  One asset read of CHUNK = 15 bytes covers 40 samples - eight codes
 * to three bytes - and is issued right after a sample is written, so it runs
 * in the slack - RD on the screen is its measured cost against those 6000
 * cycles.  If it ever exceeded the slack the loop would stretch that one
 * period rather than drop a sample.
 *
 * The shorter single-block version that came first - the same message cut to
 * "Balise du 86, vent nord-est, 25, maxi 30.", 2.51 s at 4 kHz and 3 bits,
 * 3759 B, which is all one asset area holds - measured 0.894, 6.0 dB of SNR,
 * 723 Hz rms of deviation and 0.886 on the 20 ms envelope.  Its ablation is
 * what fixed the encoding, and the two things that had to be right are worth
 * 0.31 -> 0.53 (interpolating to 8 kHz, which moves the hold's images out of
 * the audio band) and 0.53 -> 0.89 (the AGC and limiter before encoding,
 * because speech's 12 dB of crest factor otherwise uses a tenth of the gain
 * field).  An earlier 0.825 s clip at 8 kHz and 4 bits reached 0.945.
 *
 * clips.json holds the encoded stream and encode_clip.py, next to it, is what
 * produces it from an audio file: the trim, the AGC and limiter, the ADPCM and
 * the block split, with the player's own decoder as a self-check - the
 * encoder's reconstruction must equal sample for sample what the decoder
 * yields, or it refuses to write.  It also renders what the air does to the
 * clip, so a voice can be judged before anything is flashed.
 *
 * Two things that measurement settled.  The gain law is AFFINE - deviation
 * proportional to (gain + 13.6) - so its offset is pure DC and the audio is
 * undistorted; LIN, which pre-divides by that fit, only clips the quiet
 * samples and took the correlation down to 0.358.  Leave it off; it is kept
 * as the control that proves the point.  And the parked phase can land on
 * either peak of the sine, so the deviation's sign is not guaranteed from
 * one key-up to the next: the audio may come out inverted, which no ear
 * hears, and the DC pedestal may sit either side of the carrier.
 *
 * Keys: MENU or PTT send  1 / 2 how many times  4 LIN, the control  EXIT
 * quit.  An experiment like pllfm: not built by "compile-app.sh All",
 * built by name.  Nothing is saved.
 */

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "../app_api.h"

/* ---- BK4829 ---- */
#define REG_30      0x30
#define REG_38      0x38
#define REG_39      0x39
#define REG_51      0x51
#define REG_70      0x70   /* tone 1: <15> enable, <14:8> gain                */
#define REG_71      0x71   /* tone 1 frequency, Hz x 10.32444                 */
#define TX_LINK_NO_MIC 0xC3FAu
#define TX_LINK_OFF    0x0000u
#define PLL_LOCK_MS    2u
#define F_PARK       330u  /* scale_freq(32 Hz): the tone that parks the DDS  */
#define PARK_MS        8u  /* a quarter period of 31.96 Hz                    */

/* The clip's geometry, fixed by the encoder (vtxdata/encode_clip.py) rather
 * than carried in an asset, because this app no longer holds any clip. */
#define CLIP_RATE 8000u
#define BLOCK_PAY 3831u                 /* 1277 whole groups of 8 codes     */
#define CPS       (48000000u / CLIP_RATE)   /* 6000 cycles per sample, 8 kHz */
#define CHUNK     15u                   /* 5 groups of 3 bytes: 40 samples  */
/* The app store, as app_overlay.h:37 lays it out. */
#define SLOT_N      48u
#define SLOT_ASSETS(n)  (0x102000u + (uint32_t)(n) * 0x2000u + 0x100u)
#define BLK_MAX     6u   /* 6 x 1.277 s = 7.6 s; the clip needs 5      */
#define REP_MAX   5u

#define F_PLAUS_MIN 1800000u
#define F_PLAUS_MAX 130000000u
#define F_BAND_TOL  100000u             /* 1 MHz: another band, another LPF  */

enum { S_READY = 0, S_TX, S_DONE, S_NOCLIP, S_DENIED, S_MISMATCH, S_UNDER };

/* ---- live clip over the USB serial port --------------------------------
 * The flash blocks are a whole message frozen into the app store, so a new
 * one means rewriting slots: four sector erases every half hour wears the
 * NOR and still cannot key the radio, because a modal app never services the
 * resident command parser.  Streaming turns that round.  The app holds the
 * port itself (serial_read, API level 3) and the host sends:
 *
 *     'V','T','X','S'   then the sample count, 32 bits little-endian,
 *                       then the 3-bit ADPCM stream, 8 codes to 3 bytes.
 *
 * A count of 0xFFFFFFFF means open-ended - a live microphone, where nobody
 * knows in advance how long the operator will talk.  The burst then runs
 * until the host closes the port (DTR drops, checked once a group) or stops
 * feeding it (the underrun guard, 250 ms).
 *
 * 8 kHz at 3 bits is 3 kB/s, which USB CDC carries without noticing, and the
 * radio answers one line per event so the host knows what happened.  Nothing
 * is written to flash, the host decides when the beacon speaks, and the
 * message can change every time.  The flash blocks stay as the fallback for
 * when no host is attached.
 *
 * Measured on the air on 2026-11-11, the same rig as the flash path: a 3.91 s
 * clip streamed from tools/beacon_say.py came back at 0.965 correlation
 * (0.900 with the carrier ramp-down left in), 11.3 dB of SNR, 746 Hz rms of
 * deviation, with the 0.5 s windows between 0.92 and 0.98 end to end.  That
 * is the flash path's 0.963 and 11.1 dB: streaming costs nothing in quality.
 *
 * The one trap, and it is the host's: the resident port keeps 256 bytes and
 * app_serial_read does not drop the excess when it laps, it FLUSHES.  A host
 * that runs too far ahead therefore loses everything in flight, not just the
 * overflow - 270 bytes of lead was measured losing 273 bytes and ending the
 * burst in VTX UNDER.  And while this app is idle it only polls every 20 ms,
 * so a header sent inside a larger burst is flushed before it is ever seen,
 * which is why the host sends the 8-byte header alone and waits for VTX TX
 * before any audio. */
#define SR_SIZE   128u                  /* 42 groups = 43 ms of slack       */
#define SR_MASK   (SR_SIZE - 1u)
#define SR_WAIT_MS 250u                 /* hold the carrier this long for a
                                           late host before giving up       */
#define SR_OPEN   0xFFFFFFFFu           /* sample count meaning "until I stop" */
#define SR_MAX    0x00FFFFFFu           /* 35 min: a sanity bound, not a budget */

static struct {
    const app_api_t *A;
    uint8_t  rep, prevKey, status, denial;
    bool     running, lin, rbSeen, norb;
    uint32_t f0, fchip, rd;
    uint8_t  buf[CHUNK];
    uint32_t blk[BLK_MAX];         /* flash address of each block's payload  */
    uint8_t  slot[BLK_MAX];        /* which store slot each one came from    */
    uint16_t sum[BLK_MAX];         /* sum of its payload bytes, to check it  */
    uint32_t total;                /* samples, from block 0's header         */
    uint8_t  nblk;
    /* streaming */
    uint8_t  sr[SR_SIZE];          /* bytes from the host, not yet decoded   */
    uint8_t  srh, srt;             /* ring read / write cursors              */
    uint8_t  hdr[8];               /* the magic and count being matched      */
    uint8_t  nhdr;
    bool     stream;               /* this burst's samples come from serial  */
    bool     host;                 /* a host has the port open (DTR)         */
    uint32_t srx;                  /* bytes taken off the port, ever         */
    uint8_t  sevt;                 /* the last serial_ctl event bits         */
    uint32_t nstream;              /* samples the host announced             */
    uint32_t sent;                 /* samples actually put on the air        */
} g;

uint64_t __aeabi_idivmod(int32_t n, int32_t d) { return g.A->idivmod(n, d); }
uint64_t __aeabi_idiv(int32_t n, int32_t d) __attribute__((alias("__aeabi_idivmod")));
uint64_t __aeabi_uidivmod(uint32_t n, uint32_t d) { return g.A->uidivmod(n, d); }
uint64_t __aeabi_uidiv(uint32_t n, uint32_t d) __attribute__((alias("__aeabi_uidivmod")));

/* ---- the serial ring ---- */
static uint8_t srUsed(void)
{
    return (uint8_t)((g.srt - g.srh) & SR_MASK);
}

/* Drain the port into the ring.  The resident side keeps only 256 bytes and
 * laps silently, so this has to be called often; at 3 kB/s that is every few
 * milliseconds, which the sample loop does comfortably. */
static void srTop(void)
{
    uint8_t room = (uint8_t)(SR_MASK - srUsed());
    while (room) {
        uint8_t lin = (uint8_t)(SR_SIZE - g.srt);   /* up to the wrap        */
        if (lin > room)
            lin = room;
        uint16_t n = g.A->serial_read(APP_SERIAL_USB, g.sr + g.srt, lin);
        if (!n)
            return;
        g.srt = (uint8_t)((g.srt + n) & SR_MASK);
        g.srx += n;
        room = (uint8_t)(room - n);
    }
}

static uint8_t srGet(void)
{
    uint8_t b = g.sr[g.srh];
    g.srh = (uint8_t)((g.srh + 1u) & SR_MASK);
    return b;
}

static void say(const char *s)
{
    const char *p = s;
    uint16_t n = 0;
    while (*p++)
        n++;
    g.A->serial_write(APP_SERIAL_USB, s, n);
}

static char *putS(char *o, const char *s)
{
    while (*s)
        *o++ = *s++;
    return o;
}

static char *putF(char *o, uint32_t f)          /* "145.50000", 10 Hz units  */
{
    uint64_t qr = g.A->uidivmod(f, 100000u);
    uint32_t r = (uint32_t)(qr >> 32);
    o = g.A->append_u32(o, (uint32_t)qr);
    *o++ = '.';
    for (uint32_t d = 10000u; d; d /= 10u) {
        uint64_t x = g.A->uidivmod(r, d);
        *o++ = (char)('0' + (uint32_t)x);
        r = (uint32_t)(x >> 32);
    }
    return o;
}

/* One chunk read, to compare with the 6000-cycle sample period. */
/* Find every block of the clip in the app store, wherever it was installed. */
static void scan(void)
{
    const app_api_t *A = g.A;
    uint8_t h[8];

    g.nblk = 0u;
    g.total = 0u;
    for (uint8_t n = 0; n < SLOT_N; n++) {
        A->sys_storage_read(SLOT_ASSETS(n), h, 8u);
        if (h[0] != 'V' || h[1] != 'T' || h[2] != 'X' || h[3] >= BLK_MAX)
            continue;
        g.blk[h[3]] = SLOT_ASSETS(n) + 8u;
        g.slot[h[3]] = n;
        if (h[3] == 0u)
            g.total = (uint32_t)h[4] | ((uint32_t)h[5] << 8)
                    | ((uint32_t)h[6] << 16) | ((uint32_t)h[7] << 24);
        if ((uint8_t)(h[3] + 1u) > g.nblk)
            g.nblk = (uint8_t)(h[3] + 1u);
    }
}

/* Sum each block's payload as the flash actually holds it: compared against
 * the encoder's figure, it says whether the installer wrote all of it. */
static void checksum(void)
{
    const app_api_t *A = g.A;
    for (uint8_t i = 0; i < g.nblk && i < BLK_MAX; i++) {
        uint16_t pos = 0u, acc = 0u;
        uint16_t len = (i + 1u < g.nblk) ? BLOCK_PAY
                     : (uint16_t)(g.total - (uint32_t)i * (BLOCK_PAY / 3u * 8u)) / 8u * 3u;
        while (pos < len) {
            uint16_t n = (uint16_t)(len - pos);
            if (n > CHUNK)
                n = CHUNK;
            A->sys_storage_read(g.blk[i] + pos, g.buf, n);
            for (uint16_t j = 0; j < n; j++)
                acc = (uint16_t)(acc + g.buf[j]);
            pos = (uint16_t)(pos + n);
        }
        g.sum[i] = acc;
    }
}

static void measure(void)
{
    const app_api_t *A = g.A;
    uint32_t t0 = A->cycles_48mhz();
    for (uint8_t i = 0; i < 8u; i++)
        A->sys_storage_read(g.blk[0], g.buf, CHUNK);
    g.rd = (A->cycles_48mhz() - t0 + 4u) >> 3;
}

/* The standard IMA ADPCM step table, and the index adjustment for 3-bit
 * codes (sign bit <2>, two magnitude bits).  178 B of code, which the asset
 * area cannot spare. */
static const uint16_t STEP[89] = {
        7,     8,     9,    10,    11,    12,    13,    14,    16,    17,
       19,    21,    23,    25,    28,    31,    34,    37,    41,    45,
       50,    55,    60,    66,    73,    80,    88,    97,   107,   118,
      130,   143,   157,   173,   190,   209,   230,   253,   279,   307,
      337,   371,   408,   449,   494,   544,   598,   658,   724,   796,
      876,   963,  1060,  1166,  1282,  1411,  1552,  1707,  1878,  2066,
     2272,  2499,  2749,  3024,  3327,  3660,  4026,  4428,  4871,  5358,
     5894,  6484,  7132,  7845,  8630,  9493, 10442, 11487, 12635, 13899,
    15289, 16818, 18500, 20350, 22385, 24623, 27086, 29794, 32767
};
static const int8_t STEP_ADJ[4] = { -1, -1, 2, 4 };

static void stopTx(void)
{
    const app_api_t *A = g.A;
    A->bk_write(REG_70, 0);
    A->bk_write(REG_71, 0);
    A->tx_mute(true);
    A->tx_carrier(false);
    A->bk_write(REG_39, (uint16_t)(g.f0 >> 16));
    A->bk_write(REG_38, (uint16_t)g.f0);
    A->tx_end();
}

/* pllfm's full key-up, the one measured to carry (doc/doc.md section 8.4). */
static bool keyUp(void)
{
    const app_api_t *A = g.A;

    A->tx_set_params();
    A->tx_carrier(false);
    A->tx_mute(true);
    A->bk_write(REG_51, 0);          /* after the prepare: it sets sub-audio */
    A->bk_write(REG_70, 0);

    g.fchip = ((uint32_t)A->bk_read(REG_39) << 16) | A->bk_read(REG_38);
    g.norb = g.fchip < F_PLAUS_MIN || g.fchip > F_PLAUS_MAX;
    g.rbSeen = true;
    if (!g.norb) {
        uint32_t diff = g.fchip > g.f0 ? g.fchip - g.f0 : g.f0 - g.fchip;
        if (diff > F_BAND_TOL) {
            stopTx();
            g.status = S_MISMATCH;
            return false;
        }
    }

    A->bk_write(REG_38, (uint16_t)g.f0);
    A->bk_write(REG_39, (uint16_t)(g.f0 >> 16));
    A->bk_write(REG_30, TX_LINK_OFF);
    A->bk_write(REG_30, TX_LINK_NO_MIC);
    A->delay_ms(PLL_LOCK_MS);
    A->tx_carrier(true);
    A->tx_mute(false);               /* the DSP path, for the generator      */
    return true;
}

/* Park the DDS phase at the sine's peak, then stream the clip into the gain,
 * block after block.  The flash read is issued before the wait, so it runs in
 * the slack of the period: 1301 cycles measured, of the 6000 a period holds,
 * where one register write takes about 3850. */
static void play(void)
{
    const app_api_t *A = g.A;
    const bool open = g.stream && g.nstream == SR_OPEN;
    uint32_t left = g.stream ? g.nstream : g.total;
    uint32_t next, grp = 0u;
    int32_t  pred = 0;
    uint16_t bpos = 0u;              /* bytes used of the current block      */
    uint8_t  bi = 0u, avail = 0u, gi = 0u, idx = 0u, k = 8u;
    bool     under = false;

    g.sent = 0u;

    A->bk_write(REG_71, F_PARK);
    A->bk_write(REG_70, (uint16_t)(0x8000u | (127u << 8)));
    A->delay_ms(PARK_MS);
    A->bk_write(REG_71, 0);          /* freeze: the generator holds its peak */

    next = A->cycles_48mhz() + CPS;
    while (left--) {
        uint32_t code, step, diff, v;

        if (k >= 8u) {
            if (g.stream) {          /* the host feeds the next three bytes  */
                uint16_t wait = 0u;
                if (open) {          /* the host hanging up ends the burst   */
                    uint8_t st2 = A->serial_ctl(APP_SERIAL_USB, 0);
                    g.sevt |= (uint8_t)(st2 & (APP_SERIAL_LOST
                                               | APP_SERIAL_TIMEOUT));
                    if (!(st2 & APP_SERIAL_HOST))
                        break;
                }
                srTop();
                while (srUsed() < 3u) {
                    A->delay_ms(1u);
                    srTop();
                    if (++wait >= SR_WAIT_MS) {
                        under = true;
                        break;
                    }
                }
                if (under)
                    break;           /* the carrier drops with the burst     */
                if (wait)            /* we stalled: restart the sample clock */
                    next = A->cycles_48mhz() + CPS;
                grp  = (uint32_t)srGet();
                grp |= (uint32_t)srGet() << 8;
                grp |= (uint32_t)srGet() << 16;
            } else if (gi >= avail) {/* next read, crossing into a new block */
                uint16_t n;
                if (bpos >= BLOCK_PAY) {
                    if ((uint8_t)(bi + 1u) >= g.nblk)
                        break;
                    bi++;
                    bpos = 0u;
                }
                n = (uint16_t)(BLOCK_PAY - bpos);
                if (n > CHUNK)
                    n = CHUNK;
                A->sys_storage_read(g.blk[bi] + bpos, g.buf, n);
                bpos = (uint16_t)(bpos + n);
                avail = (uint8_t)n;
                gi = 0u;
            }
            if (!g.stream) {
                grp = (uint32_t)g.buf[gi] | ((uint32_t)g.buf[gi + 1u] << 8)
                                          | ((uint32_t)g.buf[gi + 2u] << 16);
                gi = (uint8_t)(gi + 3u);
            }
            k = 0u;
        }
        code = (grp >> (3u * k)) & 7u;
        k++;

        step = STEP[idx];            /* IMA ADPCM, 3 bits                    */
        diff = step >> 2;
        if (code & 2u)
            diff += step;
        if (code & 1u)
            diff += step >> 1;
        pred = (code & 4u) ? pred - (int32_t)diff : pred + (int32_t)diff;
        if (pred > 32767)
            pred = 32767;
        else if (pred < -32768)
            pred = -32768;
        idx = (uint8_t)(idx + STEP_ADJ[code & 3u]);
        if ((int8_t)idx < 0)
            idx = 0u;
        else if (idx > 88u)
            idx = 88u;

        v = (uint32_t)(64 + (pred >> 9));    /* the top 7 bits are the gain  */
        if (g.lin) {                 /* the control: see the header          */
            v = (v * 142u) >> 7;
            v = v > 14u ? v - 14u : 0u;
        }
        while (app_cycles_before(A->cycles_48mhz(), next)) { }
        next += CPS;
        A->bk_write(REG_70, (uint16_t)(0x8000u | (v << 8)));
        g.sent++;
    }
    if (under)
        g.status = S_UNDER;
}

static void draw(void);

static void transmit(void)
{
    const app_api_t *A = g.A;
    uint8_t st;

    if (!g.stream && (g.nblk == 0u || g.total == 0u)) {
        g.status = S_NOCLIP;
        draw();
        return;
    }
    st = A->tx_state();
    if (st) {
        g.status = S_DENIED;
        g.denial = st;
        if (g.stream)
            say("VTX DENIED\n");
        draw();
        return;
    }
    g.f0 = A->tx_freq();
    g.status = S_TX;
    draw();
    if (!keyUp()) {
        if (g.stream)
            say("VTX REFUSED\n");
        return;
    }
    if (g.stream) {
        say("VTX TX\n");
        play();
    } else {
        for (uint8_t r = 0; r < g.rep; r++) {
            play();
            if (r + 1u < g.rep)
                A->delay_ms(200u);   /* a gap, the carrier held at the park  */
        }
    }
    stopTx();
    if (g.status != S_UNDER)
        g.status = S_DONE;
    if (g.stream) {
        char s[24], *o = putS(s, g.status == S_UNDER ? "VTX UNDER " : "VTX OK ");
        o = A->append_u32(o, g.sent);
        *o++ = '\n';
        *o = 0;
        say(s);
        g.stream = false;
    }
    draw();                          /* or the screen reads ON AIR until the
                                        next key, which is a lie on a TX app */
}

/* ---- display ----
 * UI_PrintStringSmall centres with an unsigned subtraction (ui/helper.c:96),
 * so a normal-font line over 18 characters wraps into the rows below.  Only
 * the short lines use it. */
static void draw(void)
{
    const app_api_t *A = g.A;
    static const char *const STAT[] = { "MENU/PTT = TX", "ON AIR", "SENT",
                                        "NO CLIP", "TX DENIED ", "CHIP ON ",
                                        "HOST STALLED" };
    char s[40], *o;

    A->display_clear();
    A->status_clear();
    A->print_bold("VOICE TX " APP_VERSION, 0, 127, 0);

    o = putF(s, A->tx_freq());
    o = putS(o, " TX");
    *o = 0;
    A->print_normal(s, 0, 127, 1);

    o = putS(s, "CLIP ");
    o = A->append_u32(o, g.total >> 3);         /* 8 samples = 1 ms at 8 kHz */
    o = putS(o, "MS ");
    o = A->append_u32(o, g.nblk);
    o = putS(o, "BLK X");
    o = A->append_u32(o, g.rep);
    if (g.lin)
        o = putS(o, " LIN");
    *o = 0;
    A->print_tiny(s, 0, 17, false, true);

    o = putS(s, "SLOT");
    for (uint8_t i = 0; i < g.nblk && i < BLK_MAX; i++) {
        *o++ = ' ';
        o = A->append_u32(o, g.slot[i]);
    }
    o = putS(o, "  PAY ");
    o = A->append_u32(o, BLOCK_PAY);
    *o = 0;
    A->print_tiny(s, 0, 25, false, true);

    o = putS(s, "K");                   /* a checksum of each block in flash */
    for (uint8_t i = 0; i < g.nblk && i < BLK_MAX; i++) {
        if ((o - s) + 6 > 31)           /* 3x5 font, 4 px a char, 128 px     */
            break;
        *o++ = ' ';
        o = A->append_u32(o, g.sum[i]);
    }
    *o = 0;
    A->print_tiny(s, 0, 33, false, true);

    o = putS(s, "RD ");
    o = A->append_u32(o, g.rd);
    o = putS(o, "C OF ");
    o = A->append_u32(o, CPS);
    *o = 0;
    A->print_tiny(s, 0, 41, false, true);

    o = s;
    if (g.rbSeen) {
        o = putS(o, g.norb ? "NORB " : "RB ");
        o = putF(o, g.fchip);
        *o++ = ' ';
    }
    o = putS(o, g.host ? "USB HOST " : "USB - ");
    o = A->append_u32(o, g.srx);
    if (g.sevt) {                   /* lost / timeout / re-enumerated       */
        *o++ = ' ';
        if (g.sevt & APP_SERIAL_LOST)    *o++ = 'L';
        if (g.sevt & APP_SERIAL_TIMEOUT) *o++ = 'T';
        if (g.sevt & APP_SERIAL_ENUM)    *o++ = 'E';
    }
    *o = 0;
    A->print_tiny(s, 0, 49, false, true);

    o = putS(s, STAT[g.status]);
    if (g.status == S_DENIED)
        o = A->append_u32(o, g.denial);
    else if (g.status == S_MISMATCH)
        o = putF(o, g.fchip);
    *o = 0;
    A->print_normal(s, 0, 127, 6);

    A->print_tiny("1-2 REPEAT   4 LIN   MENU/PTT TX", 0, 1, true, true);
    A->blit_status();
    A->blit_full();
}

/* Watch the port for a stream header while idle: 'V','T','X','S' and then the
 * sample count, little-endian.  Anything that does not continue the magic
 * restarts the match, so line noise or a stray host cannot wedge it. */
static void pollStream(void)
{
    static const char MAGIC[4] = { 'V', 'T', 'X', 'S' };
    static uint32_t shown;
    uint8_t stat = g.A->serial_ctl(APP_SERIAL_USB, 0);
    if (!(stat & APP_SERIAL_OK))
        return;
    bool was = g.host;
    g.host = (stat & APP_SERIAL_HOST) != 0;
    g.sevt |= (uint8_t)(stat & (APP_SERIAL_LOST | APP_SERIAL_TIMEOUT
                                | APP_SERIAL_ENUM));
    if (g.host != was)
        draw();

    srTop();
    while (srUsed()) {
        uint8_t b = srGet();
        if (g.nhdr < 4u && b != (uint8_t)MAGIC[g.nhdr]) {
            g.nhdr = (b == (uint8_t)MAGIC[0]) ? 1u : 0u;
            continue;
        }
        g.hdr[g.nhdr++] = b;
        if (g.nhdr < 8u)
            continue;
        g.nhdr = 0u;
        g.nstream = (uint32_t)g.hdr[4] | ((uint32_t)g.hdr[5] << 8)
                  | ((uint32_t)g.hdr[6] << 16) | ((uint32_t)g.hdr[7] << 24);
        /* Nothing is stored, so the only bound is sanity: the flash budget
         * has no say here, and SR_OPEN says there is no length at all. */
        if (g.nstream == 0u || (g.nstream > SR_MAX && g.nstream != SR_OPEN)) {
            say("VTX BADLEN\n");
            return;
        }
        g.stream = true;
        transmit();
        draw();
        return;                      /* one burst per pass round the loop    */
    }
    if (g.srx != shown) {            /* bytes arrived but no header yet      */
        shown = g.srx;
        draw();
    }
}

static void keys(void)
{
    const app_api_t *A = g.A;
    uint8_t k = A->get_key();
    if (k == APP_KEY_INVALID || k == g.prevKey) {
        g.prevKey = k;
        return;
    }
    g.prevKey = k;
    A->backlight_on();

    switch (k) {
    case APP_KEY_EXIT:
        g.running = false;
        return;
    case APP_KEY_MENU:
    case APP_KEY_PTT:
        transmit();
        return;
    case APP_KEY_1:
    case APP_KEY_DOWN:
        g.rep = (uint8_t)(g.rep > 1u ? g.rep - 1u : REP_MAX);
        g.status = S_READY;
        break;
    case APP_KEY_2:
    case APP_KEY_UP:
        g.rep = (uint8_t)(g.rep < REP_MAX ? g.rep + 1u : 1u);
        g.status = S_READY;
        break;
    case APP_KEY_4:
        g.lin = !g.lin;
        break;
    default:
        break;
    }
    draw();
}

__attribute__((section(".text.entry"), used))
void app_main(const app_api_t *api)
{
    g.A = api;
    g.running = true;
    g.rep = 1u;

    scan();
    if (g.nblk) {
        measure();
        checksum();
    }
    draw();
    while (g.running) {
        pollStream();
        keys();
        api->battery_sample();
        api->backlight_update();
        api->delay_ms(20u);
    }
}

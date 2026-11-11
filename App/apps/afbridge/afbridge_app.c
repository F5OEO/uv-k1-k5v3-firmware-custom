/* Copyright 2026 Evariste F5OEO
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
 * AF Bridge - both directions of audio over the one USB-C port: the received
 * audio out, a transmission in. AF Stream and Voice TX in one overlay, lean
 * enough to fit: measured, the parts of those two worth keeping add up to
 * about 4.6 KiB against a 4 KiB wall, so this app drops what a bridge does
 * not need - the flash-clip machinery, the slot scan, the level bar, the
 * RSSI, the rate selector (8 kHz only, which is what the TX side runs at)
 * and most of the screen.
 *
 * THE RF IS HALF DUPLEX and cannot be otherwise: one VCO, one path, one PA.
 * Only the USB link is full duplex. The radio receives, or it transmits.
 *
 * And that is what the duplex link is for, rather than decoration. A live
 * microphone cannot be paced the way tools/beacon_say.py paces a file against
 * a fixed CLOCK = 1.0062: the host runs on its sound card's clock, this radio
 * on an RC oscillator that drifts with temperature, and the resident port's
 * 256-byte ring does not drop the excess when it laps - it FLUSHES, which
 * measured as 270 bytes of lead losing 273 bytes. So while transmitting,
 * when there is nothing to receive, the outbound direction reports the ring
 * fill ten times a second and the host servos its resampler on it. 3-bit
 * ADPCM is kept for the same reason: 0.6 % of 3 kB/s is 19 B/s of drift to
 * absorb, against 50 B/s for raw 8-bit.
 *
 * Out (radio -> host), little-endian halfwords:
 *   0x0000..0x0FFF  one audio sample, the ADC's 12 bits, silence at 2048
 *   0x1001 / 0x1002 transmission started / reception resumed
 *   0x2000 | fill   bytes waiting in this app's ring, 0..127 (flow control)
 *   0x3000 | code   a burst ended: 0 ok, 1 underrun, 2 denied, 3 frequency
 *                   mismatch, 4 implausible length
 * An audio sample never has its top nibble set, so a host tells the two
 * apart by value alone and the audio stays raw.
 *
 * In (host -> radio), exactly Voice TX 3.1's wire format, so beacon_say.py
 * works against this app unchanged:
 *   'V','T','X','S', the sample count as 32 bits little-endian, then the
 *   3-bit ADPCM stream, 8 codes to three bytes. A count of 0xFFFFFFFF is
 *   open-ended: the burst runs until the host stops feeding it (250 ms) or
 *   drops DTR.
 *
 * A PC now keys the PA, so every Voice TX guard stays: the transmission is
 * refused if tx_state() says so, the frequency is read back from the chip
 * and checked against the VFO before the carrier goes up, and the carrier
 * drops on an underrun, on DTR, or at the announced count.
 *
 * What the host must still do, because the radio cannot: resample to the
 * measured rate, and run an AGC and a limiter before the ADPCM. Voice TX's
 * own ablation puts numbers on it - interpolating to 8 kHz took the
 * correlation from 0.31 to 0.53, the AGC and limiter from 0.53 to 0.89.
 *
 * Keys: 1 the gate (send only while the squelch is open) · 2 the AF path,
 *       stock or REG_2B raw · EXIT quit. Both are saved.
 */

#include <stdbool.h>
#include <stdint.h>
#include "../app_api.h"
#include "afbridge_assets.h"

/* ---- PY32F071 registers, by hand: an overlay app links no HAL ---- */
#define REG32(a)        (*(volatile uint32_t *)(a))
#define RCC_AHBENR      REG32(0x40021038u)
#define RCC_APBENR1     REG32(0x4002103Cu)
#define RCC_APBENR2     REG32(0x40021040u)
#define SYSCFG_CFGR3    REG32(0x40010008u)
#define ADC_CR2         REG32(0x40012408u)
#define ADC_DR_ADDR     0x40012450u
#define DMA_ISR         REG32(0x40020000u)
#define DMA_IFCR        REG32(0x40020004u)
#define DMA1_C1_CCR     REG32(0x40020008u)
#define DMA1_C1_CNDTR   REG32(0x4002000Cu)
#define DMA1_C1_CPAR    REG32(0x40020010u)
#define DMA1_C1_CMAR    REG32(0x40020014u)
#define TIM3_CR1        REG32(0x40000400u)
#define TIM3_CR2        REG32(0x40000404u)
#define TIM3_EGR        REG32(0x40000414u)
#define TIM3_PSC        REG32(0x40000428u)
#define TIM3_ARR        REG32(0x4000042Cu)

#define DMAEN           (1u << 0)
#define TIM3EN          (1u << 1)
#define SYSCFGEN        (1u << 0)
#define ADC_DMA         (1u << 8)
#define ADC_CONT        (1u << 1)
#define ADC_EXTSEL      (7u << 17)
#define ADC_TRIG_TIM3   (4u << 17)
#define ADC_EXTTRIG     (1u << 20)
#define CCR_STREAM      ((1u << 7) | (1u << 5) | (1u << 8) | (1u << 10) | (2u << 12))
#define CCR_EN          (1u << 0)
#define DMA_HTIF1       (1u << 2)
#define DMA_TCIF1       (1u << 1)
#define DMA_CGIF1       (1u << 0)
#define TIM_MMS_UPDATE  (2u << 4)
#define TIM_CEN         (1u << 0)
#define TIM_UG          (1u << 0)

/* ---- BK4829 ---- */
#define REG_0C          0x0C       /* bit 1: the squelch is open             */
#define REG_2B          0x2B       /* bits 10:8: RX HPF, LPF, de-emphasis    */
#define REG_30          0x30
#define REG_38          0x38
#define REG_39          0x39
#define REG_70          0x70       /* tone 1: <15> enable, <14:8> gain       */
#define REG_71          0x71       /* tone 1 frequency                       */
#define REG_73          0x73       /* bit 4: AFC off                         */
#define RAW_2B          0x0700u
#define AFC_OFF_73      0x0010u
#define TX_LINK_NO_MIC  0xC3FAu
#define TX_LINK_OFF     0x0000u
#define PLL_LOCK_MS     2u
#define F_PARK          330u       /* 32 Hz: the tone that parks the DDS     */
#define PARK_MS         8u
#define F_PLAUS_MIN     1800000u
#define F_PLAUS_MAX     130000000u
#define F_BAND_TOL      100000u    /* 1 MHz: another band, another filter    */

/* ---- rates and buffers ---- */
#define FS              8000u
#define CPS             (48000000u / FS)   /* 6000 cycles a sample           */
#define TIM_ARR         (CPS - 1u)
#define BUF_SAMPLES     128u       /* 256 B: halves of 8 ms at 8 kHz         */
#define HALF            (BUF_SAMPLES / 2u)
#define SR_SIZE         128u       /* the app's own inbound ring             */
#define SR_MASK         (SR_SIZE - 1u)
#define SR_WAIT_SLOTS   2000u      /* 250 ms of patience, one sample period at
                                      a time: a dry ring used to cost
                                      delay_ms(1), which is eight periods of
                                      held DC - audible as a gap, and it
                                      stretches the clip by as much          */
#define SR_OPEN         0xFFFFFFFFu
#define SR_MAX          0x00FFFFFFu
#define CREDIT_EVERY    800u       /* samples between two fill reports: 100 ms */
#define OPEN_MAX        (180u * FS)/* 3 min: an open-ended burst still ends  */
#define FEED_BYTES      64u        /* screen bytes between two sends         */
#define DRAW_MS         300u
#define CFG_LEN         3u
#define CFG_MAGIC       0x6Au

enum { ST_OK = 0, ST_UNDER, ST_DENIED, ST_MISMATCH, ST_BADLEN, ST_TOT };

static struct {
    union {
        uint8_t set[CFG_LEN];
        struct { uint8_t magic, gate, raw; };
    };
    uint8_t  prevKey, nhdr, status, fill;
    bool     running, redraw, feeding, host, open, air, nocredit;
    uint8_t  hdr[4];
    uint8_t  sr[SR_SIZE];
    uint8_t  srh, srt;
    uint16_t lvl, ovr, to;
    uint16_t txFs;                 /* samples a second the last burst made  */
    uint32_t txMs;                 /* ticks_ms when the burst started       */
    uint16_t stalls;               /* sample periods spent on a dry ring    */
    uint16_t r2B, r73;
    uint32_t adcCr2, cfgr3, tim1, tim2, psc, arr, ccr, ahb, apb1, apb2;
    uint32_t out;                  /* bytes of audio to the host             */
    uint32_t nstream, txSent, f0;
    uint32_t drawn;
    const app_api_t *A;
    char     ui[UI_SIZE];
} g;

static uint16_t g_buf[BUF_SAMPLES];    /* the DMA's circular buffer, in .bss */

uint64_t __aeabi_uidivmod(uint32_t n, uint32_t d) { return g.A->uidivmod(n, d); }
uint64_t __aeabi_uidiv(uint32_t n, uint32_t d) __attribute__((alias("__aeabi_uidivmod")));
uint64_t __aeabi_idivmod(int32_t n, int32_t d) { return g.A->idivmod(n, d); }
uint64_t __aeabi_idiv(int32_t n, int32_t d) __attribute__((alias("__aeabi_idivmod")));

#define T(off) (&g.ui[off])

static char *put(char *o, const char *s) { while (*s) *o++ = *s++; return o; }
static char *putn(char *o, const char *s, uint8_t n) { while (n--) *o++ = *s++; return o; }
__attribute__((noinline))
static char *puti(char *o, int32_t v) { return g.A->append_i32(o, v); }
static unsigned subu(uint32_t *v, uint32_t d) { unsigned q = 0; while (*v >= d) { *v -= d; q++; } return q; }
static char *putFreq(char *o, uint32_t f)
{
    uint16_t mhz = 0;
    while (f >= 100000u) { f -= 100000u; mhz++; }
    o = puti(o, mhz);
    *o++ = '.';
    *o++ = (char)('0' + subu(&f, 10000u));
    *o++ = (char)('0' + subu(&f, 1000u));
    *o++ = (char)('0' + subu(&f, 100u));
    return o;
}
static void tiny(char *buf, uint8_t x, uint8_t y, char *end)
{ *end = '\0'; g.A->print_tiny(buf, x, y, false, true); }

/* ---- the inbound ring. The resident port keeps 256 bytes and FLUSHES when
 * it laps, so this is called from every loop that can last a millisecond. */
static uint8_t srUsed(void) { return (uint8_t)((g.srt - g.srh) & SR_MASK); }

static void srTop(void)
{
    uint8_t room = (uint8_t)(SR_MASK - srUsed());
    while (room) {
        uint8_t lin = (uint8_t)(SR_SIZE - g.srt);
        if (lin > room) lin = room;
        uint16_t n = g.A->serial_read(APP_SERIAL_USB, g.sr + g.srt, lin);
        if (!n) return;
        g.srt = (uint8_t)((g.srt + n) & SR_MASK);
        room = (uint8_t)(room - n);
    }
}
static uint8_t srGet(void)
{
    uint8_t b = g.sr[g.srh];
    g.srh = (uint8_t)((g.srh + 1u) & SR_MASK);
    return b;
}
static void srFlush(void)
{
    uint8_t sink[32];
    g.srh = g.srt = 0u;
    while (g.A->serial_read(APP_SERIAL_USB, sink, sizeof sink)) { }
}

/* One control halfword out. False when the host did not take it. */
static bool ctl(uint16_t w)
{
    uint8_t b[2] = { (uint8_t)w, (uint8_t)(w >> 8) };
    return g.A->serial_write(APP_SERIAL_USB, b, 2u);
}

/* ---- the receive path ---- */
static void path(void)
{
    const app_api_t *A = g.A;
    A->set_af(APP_AF_FM);          /* tones_off_rx leaves the AF muted       */
    A->bk_write(REG_2B, g.raw ? RAW_2B : g.r2B);
    A->bk_write(REG_73, g.raw ? AFC_OFF_73 : g.r73);
}

static void captureStart(void)
{
    RCC_APBENR2 |= SYSCFGEN;
    RCC_AHBENR  |= DMAEN;
    RCC_APBENR1 |= TIM3EN;
    DMA1_C1_CCR   = 0;
    SYSCFG_CFGR3  = g.cfgr3 & ~0x3Fu;      /* channel 1 <- ADC1 (request 0)  */
    DMA1_C1_CPAR  = ADC_DR_ADDR;
    DMA1_C1_CMAR  = (uint32_t)g_buf;
    DMA1_C1_CNDTR = BUF_SAMPLES;
    DMA_IFCR      = DMA_CGIF1 | DMA_TCIF1 | DMA_HTIF1;
    DMA1_C1_CCR   = CCR_STREAM | CCR_EN;
    ADC_CR2 = (g.adcCr2 & ~(ADC_EXTSEL | ADC_CONT)) | ADC_TRIG_TIM3 | ADC_EXTTRIG | ADC_DMA;
    TIM3_CR1 = 0;
    TIM3_PSC = 0;
    TIM3_ARR = TIM_ARR;
    TIM3_CR2 = TIM_MMS_UPDATE;
    TIM3_EGR = TIM_UG;
    TIM3_CR1 = TIM_CEN;
}

static void captureStop(void)
{
    TIM3_CR1    = 0;
    DMA1_C1_CCR = 0;
    ADC_CR2     = g.adcCr2;
    DMA_IFCR    = DMA_CGIF1 | DMA_TCIF1 | DMA_HTIF1;
}

static void rxOn(void)
{
    g.A->af_capture_open();        /* PA4 analog, the DAC bias, ADC ch 4     */
    g.A->set_agc(false);           /* tx_end() -> RADIO_SetupRegisters put it
                                      back on: a silence must stay silent    */
    captureStart();
    path();
    g.air = false;
    g.redraw = true;
}
static void rxOff(void)
{
    captureStop();
    g.A->af_capture_close();       /* PA4 back to the resident's state       */
    g.air = true;
    g.redraw = true;
}

/* Peak to peak of the half just sent: the one number that says whether audio
 * reaches the pin at all. */
static void level(const uint16_t *p)
{
    uint16_t mn = 4095u, mx = 0;
    for (unsigned n = 0; n < HALF; n++) {
        uint16_t v = (uint16_t)(p[n] & 0x0FFFu);
        if (v < mn) mn = v;
        if (v > mx) mx = v;
    }
    g.lvl = (uint16_t)(mx - mn);
}

static void serveRx(const uint16_t *half)
{
    const app_api_t *A = g.A;
    level(half);
    /* nothing goes out while nothing is received */
    g.open = !g.gate || ((A->bk_read(REG_0C) >> 1) & 1u) != 0u;
    if (g.host && g.open) {
        if (A->serial_write(APP_SERIAL_USB, half, HALF * 2u)) g.out += HALF * 2u;
        else if (g.to < 9999u) g.to++;
    }
}

/* ---- the transmit path, Voice TX's, stream only ---- */
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

/* pllfm's full key-up, the one measured to carry (doc/doc.md 8.4). */
static bool keyUp(void)
{
    const app_api_t *A = g.A;
    A->tx_set_params();
    A->tx_carrier(false);
    A->tx_mute(true);
    A->bk_write(REG_70, 0);
    /* the chip's own frequency, read back: a PC asked for this carrier */
    uint32_t f = ((uint32_t)A->bk_read(REG_39) << 16) | A->bk_read(REG_38);
    if (f >= F_PLAUS_MIN && f <= F_PLAUS_MAX) {
        uint32_t d = f > g.f0 ? f - g.f0 : g.f0 - f;
        if (d > F_BAND_TOL) { stopTx(); g.status = ST_MISMATCH; return false; }
    }
    A->bk_write(REG_38, (uint16_t)g.f0);
    A->bk_write(REG_39, (uint16_t)(g.f0 >> 16));
    A->bk_write(REG_30, TX_LINK_OFF);
    A->bk_write(REG_30, TX_LINK_NO_MIC);
    A->delay_ms(PLL_LOCK_MS);
    A->tx_carrier(true);
    A->tx_mute(false);
    return true;
}

/* Park the DDS at the sine's peak, then stream the host's ADPCM into the
 * gain field: one register write a sample, about 3850 cycles of the 6000 a
 * period holds. */
static void play(void)
{
    const app_api_t *A = g.A;
    const bool open = g.nstream == SR_OPEN;
    uint32_t left = g.nstream, next, grp = 0u, credit = 0u;
    int32_t  pred = 0;
    uint8_t  idx = 0u, k = 8u;

    g.txSent = 0u;
    g.status = ST_OK;
    g.nocredit = false;
    g.stalls = 0u;
    g.txMs = A->ticks_ms();
    A->bk_write(REG_71, F_PARK);
    A->bk_write(REG_70, (uint16_t)(0x8000u | (127u << 8)));
    A->delay_ms(PARK_MS);
    A->bk_write(REG_71, 0);        /* freeze: the generator holds its peak   */

    next = A->cycles_48mhz() + CPS;
    while (left--) {
        uint32_t code, step, diff, v;
        if (k >= 8u) {
            uint16_t wait = 0u;     /* sample periods spent waiting for bytes */
            if (open) {
                if (!(A->serial_ctl(APP_SERIAL_USB, 0) & APP_SERIAL_HOST))
                    break;         /* the host hung up                       */
                if (g.txSent >= OPEN_MAX) { g.status = ST_TOT; break; }
            }
            srTop();
            while (srUsed() < 3u) {
                uint32_t w = A->cycles_48mhz() + CPS;
                while (app_cycles_before(A->cycles_48mhz(), w)) { }
                srTop();
                if (g.stalls < 65535u) g.stalls++;
                if (++wait >= SR_WAIT_SLOTS) { g.status = ST_UNDER; break; }
            }
            if (g.status == ST_UNDER) break;
            if (wait) next = A->cycles_48mhz() + CPS;   /* the clock restarts */
            grp  = (uint32_t)srGet();
            grp |= (uint32_t)srGet() << 8;
            grp |= (uint32_t)srGet() << 16;
            k = 0u;
        }
        code = (grp >> (3u * k)) & 7u;
        k++;
        step = STEP[idx];          /* IMA ADPCM, 3 bits                      */
        diff = step >> 2;
        if (code & 2u) diff += step;
        if (code & 1u) diff += step >> 1;
        pred = (code & 4u) ? pred - (int32_t)diff : pred + (int32_t)diff;
        if (pred > 32767) pred = 32767;
        else if (pred < -32768) pred = -32768;
        idx = (uint8_t)(idx + STEP_ADJ[code & 3u]);
        if ((int8_t)idx < 0) idx = 0u;
        else if (idx > 88u) idx = 88u;

        v = (uint32_t)(64 + (pred >> 9));   /* the top 7 bits are the gain   */
        while (app_cycles_before(A->cycles_48mhz(), next)) { }
        next += CPS;
        A->bk_write(REG_70, (uint16_t)(0x8000u | (v << 8)));
        g.txSent++;

        /* Flow control, which is the whole point of the duplex link: the host
         * cannot pace a live source against our RC clock, so it servos on
         * this. The outbound direction is free - there is nothing to receive. */
        if (++credit >= CREDIT_EVERY) {   /* and the flow control itself    */
            credit = 0u;
            g.fill = srUsed();
            /* Measured on the air: 92 us, 0.7 of a sample period, so this
             * cannot be what slows a burst down. */
            if (!g.nocredit && !ctl((uint16_t)(0x2000u | g.fill))) g.nocredit = true;
            if ((int32_t)(A->cycles_48mhz() - next) > 0) next = A->cycles_48mhz() + CPS;
        }
    }
}

static void draw(void);

static void transmit(void)
{
    const app_api_t *A = g.A;
    uint8_t st = A->tx_state();
    if (st) {
        g.status = ST_DENIED; ctl(0x3000u | ST_DENIED); srFlush();
        g.redraw = true; return;
    }
    if (g.nstream == 0u || (g.nstream > SR_MAX && g.nstream != SR_OPEN)) {
        g.status = ST_BADLEN; ctl(0x3000u | ST_BADLEN); srFlush();
        g.redraw = true; return;
    }
    g.f0 = A->tx_freq();
    rxOff();                       /* nothing to capture, and the TX loop is
                                      cycle-timed: no DMA on the bus         */
    draw();
    A->blit_status();
    A->blit_full();
    g.feeding = false;             /* a blit ends the lcd_feed frame         */
    /* The marker goes out only once the carrier is up and play() is about to
     * drain: a host that starts streaming on it any earlier would fill the
     * resident 256-byte ring while nothing reads it, and that ring FLUSHES
     * when it laps - an arbitrary number of bytes gone, the 3-byte groups out
     * of phase, and every sample after it wrong with the carrier up. Voice TX
     * sends its VTX TX line at exactly this point for the same reason. */
    if (keyUp()) {
        ctl(0x1001u);
        play();
        stopTx();
    }
    {   /* what the loop really produced: a clip that sounds slowed is a loop
         * running under 8 kHz, and this is the only place it can be seen */
        uint32_t ms = A->ticks_ms() - g.txMs;
        g.txFs = ms ? (uint16_t)(g.txSent * 1000u / ms) : 0u;
    }
    ctl((uint16_t)(0x3000u | g.status));
    srFlush();                     /* whatever the host left is not a header */
    rxOn();
    ctl(0x1002u);
}

/* The header the host sends before a burst: 'V','T','X','S' then the count.
 * True once a whole one has been read. */
static bool hdrFeed(void)
{
    static const char MAGIC[4] = { 'V', 'T', 'X', 'S' };
    while (srUsed()) {
        uint8_t b = srGet();
        if (g.nhdr < 4u) {
            if (b == (uint8_t)MAGIC[g.nhdr]) g.nhdr++;
            else g.nhdr = (uint8_t)(b == 'V' ? 1u : 0u);
            continue;
        }
        g.hdr[g.nhdr - 4u] = b;
        if (++g.nhdr < 8u) continue;
        g.nhdr = 0u;
        g.nstream = (uint32_t)g.hdr[0] | ((uint32_t)g.hdr[1] << 8)
                  | ((uint32_t)g.hdr[2] << 16) | ((uint32_t)g.hdr[3] << 24);
        return true;
    }
    return false;
}

/* ---- display ---- */
static void draw(void)
{
    const app_api_t *A = g.A;
    char buf[36], *o;

    A->status_clear();
    A->print_tiny(T(T_TITLE), 2, 1, true, true);
    if (g.host) A->asset_read(BMP_USB, A->status_line + 52u, ICON_W);
    A->draw_battery();
    A->display_clear();

    o = putFreq(buf, g.air ? A->tx_freq() : A->rx_freq());
    if (g.gate) { o = put(o, T(T_SQ)); if (g.raw) *o++ = '?'; }
    if (g.raw) o = put(o, T(T_RAW));
    tiny(buf, 2, 1, o);
    A->print_normal(T(g.air ? T_AIR : T_RX), 2, 127, 2);

    o = put(buf, T(T_OUT));
    o = puti(o, (int32_t)(g.out >> 10));
    o = put(o, T(T_KB));
    o = put(o, T(T_PP));
    o = puti(o, g.lvl);
    tiny(buf, 2, 26, o);

    o = put(buf, T(T_IN));
    o = puti(o, (int32_t)g.txSent);
    o = put(o, T(T_FILL));
    o = puti(o, g.fill);
    tiny(buf, 2, 34, o);

    o = put(buf, T(T_OVR));
    o = puti(o, g.ovr);
    o = put(o, T(T_TO));
    o = puti(o, g.to);
    o = put(o, T(T_ST));
    o = putn(o, T(T_STAT) + 1u + g.status * 4u, 3u);
    o = put(o, T(T_C));            /* the rate the TX loop really produced  */
    o = puti(o, g.txFs);
    *o++ = '/';
    o = puti(o, g.stalls);
    tiny(buf, 2, 42, o);

    g.drawn = A->ticks_ms();
}

static void keys(void)
{
    const app_api_t *A = g.A;
    uint8_t key = A->get_key();
    if (key == g.prevKey) return;
    g.prevKey = key;
    if (key == APP_KEY_INVALID) return;
    if (key == APP_KEY_SAVER || key == APP_KEY_WAKE) { g.redraw = true; return; }
    A->backlight_on();
    switch (key) {
    case APP_KEY_EXIT: g.running = false; break;
    case APP_KEY_1: g.gate ^= 1u; break;
    case APP_KEY_2: g.raw ^= 1u; path(); break;
    default: return;
    }
    g.redraw = true;
}

/* One half-buffer out, then the host's bytes in, then the screen a few bytes
 * at a time - a whole blit is 11 ms and a half-buffer is 8 ms. */
static void loop(void)
{
    const app_api_t *A = g.A;
    while (g.running) {
        /* The DMA paces everything: one half is 8 ms, and the key scan alone
         * costs a fraction of a millisecond - it has no business in a spin
         * loop. Nothing below runs more than once per half. */
        uint32_t isr = DMA_ISR;
        if (!(isr & (DMA_HTIF1 | DMA_TCIF1))) continue;
        if ((isr & DMA_HTIF1) && (isr & DMA_TCIF1)) {
            if (g.ovr < 9999u) g.ovr++;            /* a half went unsent     */
            DMA_IFCR = DMA_HTIF1 | DMA_TCIF1;
        } else if (isr & DMA_HTIF1) {
            DMA_IFCR = DMA_HTIF1;
            serveRx(g_buf);
        } else {
            DMA_IFCR = DMA_TCIF1;
            serveRx(g_buf + HALF);
        }
        uint8_t st = A->serial_ctl(APP_SERIAL_USB, 0);
        g.host = (st & APP_SERIAL_HOST) != 0u;
        srTop();
        if (hdrFeed()) transmit();

        uint32_t now = A->ticks_ms();
        if (g.feeding) {
            g.feeding = A->lcd_feed(FEED_BYTES);
        } else if (g.redraw || now - g.drawn >= DRAW_MS) {
            g.redraw = false;
            draw();
            A->lcd_feed(0);
            g.feeding = true;
        }
        keys();
        A->backlight_update();
    }
}

__attribute__((section(".text.entry"), used))
void app_main(const app_api_t *api)
{
    g.A = api;
    g.prevKey = APP_KEY_INVALID;
    api->asset_read(0, g.ui, UI_SIZE);
    api->cfg_load(g.set, CFG_LEN);
    if (g.magic != CFG_MAGIC) { g.magic = CFG_MAGIC; g.gate = 1u; g.raw = 0; }
    g.gate = (uint8_t)(g.gate == 1u);
    g.raw  = (uint8_t)(g.raw == 1u);

    g.r2B = api->bk_read(REG_2B);
    g.r73 = api->bk_read(REG_73);
    g.cfgr3 = SYSCFG_CFGR3;
    g.tim1 = TIM3_CR1; g.tim2 = TIM3_CR2; g.psc = TIM3_PSC; g.arr = TIM3_ARR;
    g.ccr = DMA1_C1_CCR;
    g.ahb = RCC_AHBENR; g.apb1 = RCC_APBENR1; g.apb2 = RCC_APBENR2;
    g.adcCr2 = ADC_CR2;

    api->serial_ctl(APP_SERIAL_USB, 0);   /* claim the port: this also locks
                                             the K5Viewer out of the stream  */
    api->set_agc(false);
    api->backlight_on();
    g.running = true;
    g.redraw = true;
    rxOn();
    loop();

    captureStop();
    TIM3_CR1 = g.tim1; TIM3_CR2 = g.tim2; TIM3_PSC = g.psc; TIM3_ARR = g.arr;
    DMA1_C1_CCR = g.ccr;
    SYSCFG_CFGR3 = g.cfgr3;
    RCC_APBENR1 = g.apb1;
    RCC_AHBENR = g.ahb;
    RCC_APBENR2 = g.apb2;
    api->bk_write(REG_2B, g.r2B);
    api->bk_write(REG_73, g.r73);
    api->set_agc(true);
    api->af_capture_close();
    api->set_af(APP_AF_MUTE);
    api->audio_path(false);
    api->cfg_save(g.set, CFG_LEN);
}

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
 * AF Stream - the demodulated RX audio out of the USB-C port, live. The
 * mirror of tools/beacon_say.py, which streams audio IN to Voice TX.
 *
 * Why this can be gapless, when no other sampling app is. Every one of them
 * (ACARS, POCSAG, the sondes) busy-waits on cycles_48mhz and calls
 * af_capture_sample() by hand, so a blocking serial_write - up to 50 ms -
 * would eat the samples it waits through; kisstnc's own rule is that a frame
 * goes out in the housekeeping slot, "never inside the sampling loop". But an
 * overlay app is trusted native code with the peripherals, and the PY32F071
 * has what is needed to take the CPU out of the loop entirely:
 *
 *     TIM3 update -> TRGO -> ADC1 (channel 4 = PA4) -> DMA1 channel 1
 *                 -> a circular buffer in this app's own RAM
 *
 * The resident firmware leaves all of that free: board.c sets the ADC to
 * LL_ADC_REG_DMA_TRANSFER_NONE and a software trigger, only DMA1 channel 2 is
 * taken (the K-plug UART's receive ring) and the only timer in use is TIM7
 * (the backlight PWM). So the DMA keeps filling while serial_write spins, and
 * the audio has no holes in it - the stream is sent one half-buffer behind the
 * one being filled, the classic double buffer.
 *
 * Three consequences to respect:
 *   - battery_sample() must never be called: it switches the ADC to the
 *     battery channel. The battery icon therefore holds the level it had at
 *     launch. Nothing resident samples the ADC meanwhile - a modal app runs
 *     its own loop and no timeslice runs.
 *   - af_capture_close() restores six registers, none of them the ADC's
 *     trigger, the DMA or the timer: this app puts those back itself.
 *   - the screen goes out through lcd_feed(), a few bytes between two sends,
 *     because a whole blit is 11 ms and one half-buffer is 16 ms at 8 kHz.
 *
 * The wire format is raw: the ADC's 12-bit codes, little-endian halfwords,
 * 0 to 4095, silence at 2048. No header, no framing - tools/afstream.py
 * converts to a WAV, and nothing on the radio has to know the host's plans.
 * Claiming the port also locks the K5Viewer stream (app_overlay.c), so the
 * screen cannot inject itself into the audio.
 *
 * What comes out is PA4: the audio the BK4829's DSP reconstructs, after the
 * AF filters - 300 Hz to 3 kHz on the stock path, wider with REG_2B's raw
 * bits (key 2) - and gated by the squelch unless it is held open (key 3).
 * Not an IQ tap and not hi-fi; good enough to decode, to record and to
 * measure. Measuring is half the point: a tone sweep streamed to the PC
 * would settle doc/doc.md's open question 2, the ~1 kHz coupling at PA4 that
 * every edge-decoding app, LaCrosse RX included, currently assumes.
 *
 * Nothing goes out while nothing is being received. The gate (key 4) is the
 * point of that: OFF streams continuously, silence included, SQL follows the
 * BK4829's own squelch bit (REG_0C bit 1), and LVL follows the peak to peak
 * the level meter already computes, against a threshold UP/DOWN sets. SQL is
 * the user's own notion of reception, with the radio's hysteresis behind it,
 * but it cannot be used together with key 3 holding the squelch open - the
 * two are mutually exclusive, and selecting one clears the other. LVL is the
 * fallback for the RAW path, where afspectro saw the squelch bit stay closed
 * on a signal it could hear on PA4.
 *
 * A gate that opens late cuts the first syllable, so two things soften it:
 * the half-buffer sent at the moment it opens already holds up to 32 ms of
 * audio from before the decision (at 8 kHz), and it stays open for HANG_MS
 * after the signal goes, which also carries the squelch tail. There is no
 * real pre-roll: 0.2 s at 8 kHz is 3.2 kB and the overlay has not got it.
 *
 * Keys: MENU start / stop · 1 sample rate · 2 AF path · 3 squelch held open
 *       · 4 gate OFF/SQL/LVL · UP/DOWN the LVL threshold · EXIT quit.
 *       Everything but the stream state is saved.
 */

#include <stdbool.h>
#include <stdint.h>
#include "../app_api.h"
#include "afstream_assets.h"

/* ---- PY32F071 registers (py32f071xB.h, by hand: an app links no HAL) ---- */
#define REG32(a)        (*(volatile uint32_t *)(a))
#define RCC_AHBENR      REG32(0x40021038u)   /* bit 0  DMAEN                 */
#define RCC_APBENR1     REG32(0x4002103Cu)   /* bit 1  TIM3EN                */
#define RCC_APBENR2     REG32(0x40021040u)   /* bit 0  SYSCFGEN              */
#define SYSCFG_CFGR3    REG32(0x40010008u)   /* bits 5:0 DMA1 ch1 request    */
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
#define ADC_TRIG_TIM3   (4u << 17)           /* EXTSEL = TIM3 TRGO           */
#define ADC_EXTTRIG     (1u << 20)
/* peripheral -> memory, 16 bits both ends, memory incrementing, circular,
 * high priority */
#define CCR_STREAM      ((1u << 7) | (1u << 5) | (1u << 8) | (1u << 10) | (2u << 12))
#define CCR_EN          (1u << 0)
#define DMA_HTIF1       (1u << 2)
#define DMA_TCIF1       (1u << 1)
#define DMA_CGIF1       (1u << 0)
#define TIM_MMS_UPDATE  (2u << 4)            /* update event -> TRGO         */
#define TIM_CEN         (1u << 0)
#define TIM_UG          (1u << 0)

/* ---- BK4829 registers, as LaCrosse RX uses them ---- */
#define REG_2B          0x2B
#define REG_4D          0x4D
#define REG_4E          0x4E
#define REG_4F          0x4F
#define REG_73          0x73
#define REG_78          0x78
#define RAW_2B          0x0700u
#define AFC_OFF_73      0x0010u
#define OPEN_4D         0xA0FFu
#define OPEN_4F         0x7F7Fu
#define OPEN_78         0x0000u

/* ---- the capture ---- */
#define BUF_SAMPLES     256u                 /* 512 B of overlay, two halves */
#define HALF            (BUF_SAMPLES / 2u)
#define TIMER_HZ        48000000u
#define FEED_BYTES      64u                  /* screen bytes between sends   */
#define DRAW_MS         250u
#define RATES           4u
#define GATES           3u
#define HANG_MS       600u      /* the gate stays open this long after the signal */
#define THR_STEP       64u
#define THR_MAX      2048u
#define CFG_LEN         6u
#define CFG_MAGIC       0x5Bu
#define REG_0C          0x0C    /* bit 1: the squelch is open                */

/* 48 MHz / (ARR + 1): 8, 16, 32 kHz, then the 38.4 kHz the capture apps use -
 * the rate doc.md's open question 1 wants the AF roll-off measured at. */
static const uint16_t RATE_ARR[RATES] = { 5999u, 2999u, 1499u, 1249u };
static const uint16_t RATE_HZ[RATES]  = { 8000u, 16000u, 32000u, 38400u };

enum { PATH_STOCK = 0, PATH_RAW };
enum { G_OFF = 0, G_SQL, G_LVL };

static struct {
    union {
        uint8_t set[CFG_LEN];
        struct { uint8_t magic, rate, path, sq, gate, thr8; };
    };
    uint8_t  prevKey;
    bool     running, streaming, redraw, feeding, host, open;
    uint32_t hangUntil;
    uint16_t ovr, to, lvl;
    uint16_t r2B, r73, r4D, r4E, r4F, r78;   /* the VFO's AF path and squelch */
    uint32_t adcCr2, cfgr3, tim1, tim2, psc, arr, ccr;  /* what we borrow     */
    uint32_t ahb, apb1, apb2;
    uint32_t sent;                           /* bytes to the host            */
    uint32_t samples, fsT0;                  /* the measured sample rate     */
    uint16_t fs;
    uint32_t drawn;
    const app_api_t *A;
    char     ui[UI_SIZE];
} g;

/* The DMA's circular buffer. In the overlay's .bss, not on app_main's stack:
 * the 1 KiB resident stack also carries the USB interrupt that completes
 * every send. */
static uint16_t g_buf[BUF_SAMPLES];

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

/* ---- the BK4829 side: the AF path, and a squelch that stays out of the way ---- */
static void path(void)
{
    const app_api_t *A = g.A;
    A->set_af(APP_AF_FM);        /* the AM/FM detector's output, per doc 9.3 */
    A->bk_write(REG_2B, g.path == PATH_RAW ? RAW_2B : g.r2B);
    A->bk_write(REG_73, g.path == PATH_RAW ? AFC_OFF_73 : g.r73);
    A->bk_write(REG_4D, g.sq ? OPEN_4D : g.r4D);
    A->bk_write(REG_4E, g.sq ? (uint16_t)((g.r4E & 0xFF00u) | 0x00FFu) : g.r4E);
    A->bk_write(REG_4F, g.sq ? OPEN_4F : g.r4F);
    A->bk_write(REG_78, g.sq ? OPEN_78 : g.r78);
}

/* ---- the MCU side ---- */
static void captureStart(void)
{
    RCC_APBENR2 |= SYSCFGEN;
    RCC_AHBENR  |= DMAEN;
    RCC_APBENR1 |= TIM3EN;

    /* DMA1 channel 1 <- ADC1 (request 0), the resident UART owns channel 2 */
    DMA1_C1_CCR   = 0;
    SYSCFG_CFGR3  = g.cfgr3 & ~0x3Fu;
    DMA1_C1_CPAR  = ADC_DR_ADDR;
    DMA1_C1_CMAR  = (uint32_t)g_buf;
    DMA1_C1_CNDTR = BUF_SAMPLES;
    DMA_IFCR      = DMA_CGIF1 | DMA_TCIF1 | DMA_HTIF1;
    DMA1_C1_CCR   = CCR_STREAM | CCR_EN;

    /* the ADC converts on TIM3's TRGO and hands the result to the DMA */
    ADC_CR2 = (g.adcCr2 & ~(ADC_EXTSEL | ADC_CONT)) | ADC_TRIG_TIM3 | ADC_EXTTRIG | ADC_DMA;

    TIM3_CR1 = 0;
    TIM3_PSC = 0;
    TIM3_ARR = RATE_ARR[g.rate];
    TIM3_CR2 = TIM_MMS_UPDATE;
    TIM3_EGR = TIM_UG;                      /* load the prescaler            */
    TIM3_CR1 = TIM_CEN;

    g.samples = 0;
    g.fsT0 = g.A->ticks_ms();
    g.fs = 0;
}

static void captureStop(void)
{
    TIM3_CR1    = 0;
    DMA1_C1_CCR = 0;
    ADC_CR2     = g.adcCr2;
    DMA_IFCR    = DMA_CGIF1 | DMA_TCIF1 | DMA_HTIF1;
}

/* Peak to peak of the half just sent: the only diagnostic that says whether
 * audio is reaching the pin at all. */
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

    /* the frequency, the nominal rate, the path */
    o = putFreq(buf, A->rx_freq());
    *o++ = ' ';
    o = puti(o, RATE_HZ[g.rate]);
    o = put(o, T(T_HZ));
    o = putn(o, T(T_PATH) + 1 + g.path * 4u, 3u);
    if (g.sq) o = put(o, T(T_SQ));
    tiny(buf, 2, 1, o);

    if (!g.streaming) {
        A->print_normal(T(T_OFF), 2, 127, 2);
    } else if (!g.host) {
        A->print_normal(T(T_WAIT), 2, 127, 2);
    } else {
        /* the rate as the radio's own clock actually produces it */
        o = put(buf, T(T_FS));
        o = puti(o, g.fs);
        A->print_normal(buf, 2, 127, 2);
        *o = '\0';
    }

    /* peak to peak as a bar over 124 px, full scale 4096 */
    A->draw_rect(A->fb, 1, 26, 126, 33, true);
    uint8_t w = (uint8_t)(g.lvl >> 5);
    if (w > 122u) w = 122u;
    for (int16_t y = 28; w && y <= 31; y++)
        A->draw_line(A->fb, 2, y, (int16_t)(2u + w), y, true);
    o = put(buf, T(T_LVL));
    o = puti(o, g.lvl);
    *o++ = ' ';
    *o++ = g.streaming && g.open ? '*' : ' ';
    o = putn(o, T(T_GATE) + 1 + g.gate * 4u, 3u);
    if (g.gate == G_LVL) { *o++ = ' '; o = puti(o, (uint16_t)g.thr8 * 8u); }
    tiny(buf, 2, 36, o);
    o = puti(buf, A->rssi_dbm());
    o = put(o, T(T_DBM));
    tiny(buf, (uint8_t)(126u - 4u * (uint8_t)(o - buf)), 36, o);

    /* kilobytes out, then the two ways it can go wrong */
    uint32_t kb = g.sent >> 10;
    o = puti(buf, (int32_t)kb);
    o = put(o, T(T_KB));
    o = put(o, T(T_OVR));
    o = puti(o, g.ovr);
    o = put(o, T(T_TO));
    o = puti(o, g.to);
    tiny(buf, 2, 46, o);

    g.drawn = A->ticks_ms();
}

/* ---- keys ---- */
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
    case APP_KEY_MENU:
        g.streaming = !g.streaming;
        if (g.streaming) captureStart(); else captureStop();
        break;
    case APP_KEY_1:
        g.rate = (uint8_t)(g.rate + 1u < RATES ? g.rate + 1u : 0u);
        if (g.streaming) { captureStop(); captureStart(); }
        break;
    case APP_KEY_2:
        g.path = (uint8_t)(g.path == PATH_RAW ? PATH_STOCK : PATH_RAW);
        path();
        break;
    case APP_KEY_3:
        g.sq ^= 1u;
        if (g.sq && g.gate == G_SQL) g.gate = G_LVL;   /* they exclude each other */
        path();
        break;
    case APP_KEY_4:
        g.gate = (uint8_t)(g.gate + 1u < GATES ? g.gate + 1u : 0u);
        if (g.gate == G_SQL && g.sq) { g.sq = 0; path(); }
        g.hangUntil = A->ticks_ms();
        break;
    default: {
        int8_t dir = A->nav_dir(key);
        if (!dir) return;
        int16_t thr = (int16_t)((int16_t)g.thr8 + dir * (int16_t)(THR_STEP / 8u));
        if (thr < 0) thr = 0;
        if (thr > (int16_t)(THR_MAX / 8u)) thr = (int16_t)(THR_MAX / 8u);
        g.thr8 = (uint8_t)thr;
        break;
    }
    }
    g.redraw = true;
}

/* One half-buffer: to the host, then the level, the screen a few bytes at a
 * time, and the keys. All of it inside one half-period of the DMA, which
 * keeps filling the other half whatever happens here. */
static void serve(const uint16_t *half)
{
    const app_api_t *A = g.A;
    uint8_t st = A->serial_ctl(APP_SERIAL_USB, 0);
    g.host = (st & APP_SERIAL_HOST) != 0u;
    level(half);
    uint32_t now = A->ticks_ms();

    /* Is the radio receiving? Only then does anything leave for the host. */
    bool live = g.gate == G_OFF ||
                (g.gate == G_SQL ? ((A->bk_read(REG_0C) >> 1) & 1u) != 0u
                                 : g.lvl >= (uint16_t)g.thr8 * 8u);
    if (live) g.hangUntil = now + HANG_MS;
    bool was = g.open;
    g.open = live || (int32_t)(g.hangUntil - now) > 0;
    if (g.open != was) g.redraw = true;

    if (g.host && g.open) {
        if (A->serial_write(APP_SERIAL_USB, half, HALF * 2u))
            g.sent += HALF * 2u;
        else if (g.to < 9999u)
            g.to++;
    }

    g.samples += HALF;
    if (now - g.fsT0 >= 2000u) {            /* the real rate, every 2 s */
        g.fs = (uint16_t)(g.samples * 1000u / (now - g.fsT0));
        g.samples = 0;
        g.fsT0 = now;
        g.redraw = true;
    }
    /* The screen goes out between sends: a whole blit is 11 ms and a half
     * buffer is 4 ms at 32 kHz. The frame buffer may only change once the
     * frame it holds is out. */
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

static void stream(void)
{
    const app_api_t *A = g.A;
    while (g.running) {
        if (!g.streaming) {                 /* idle: the loop is the UI only */
            uint8_t st = A->serial_ctl(APP_SERIAL_USB, 0);
            g.host = (st & APP_SERIAL_HOST) != 0u;
            keys();
            if (g.redraw || A->ticks_ms() - g.drawn >= DRAW_MS) {
                g.redraw = false;
                draw();
                A->blit_status();
                A->blit_full();
            }
            A->backlight_update();
            A->delay_ms(20);
            continue;
        }
        uint32_t isr = DMA_ISR;
        if (!(isr & (DMA_HTIF1 | DMA_TCIF1))) continue;
        /* both at once means a half went by unsent: count it and resynchronise
         * on the half the DMA is not in */
        if ((isr & DMA_HTIF1) && (isr & DMA_TCIF1)) {
            if (g.ovr < 9999u) g.ovr++;
            DMA_IFCR = DMA_HTIF1 | DMA_TCIF1;
            continue;
        }
        if (isr & DMA_HTIF1) {
            DMA_IFCR = DMA_HTIF1;
            serve(g_buf);
        } else {
            DMA_IFCR = DMA_TCIF1;
            serve(g_buf + HALF);
        }
    }
}

__attribute__((section(".text.entry"), used))
void app_main(const app_api_t *api)
{
    g.A   = api;
    g.prevKey = APP_KEY_INVALID;
    api->asset_read(0, g.ui, UI_SIZE);

    api->cfg_load(g.set, CFG_LEN);
    if (g.magic != CFG_MAGIC) {
        /* Defaults where every mechanism is known to work: the radio's own
         * squelch decides what "receiving" means, on the stock AF path, with
         * nothing forced open. RAW, the held-open squelch and the level gate
         * are for measuring, and the * on screen shows at once whether the
         * squelch bit still follows the signal on that path. */
        g.magic = CFG_MAGIC; g.rate = 0; g.path = PATH_STOCK; g.sq = 0;
        g.gate = G_SQL; g.thr8 = (uint8_t)(1024u / 8u);
    }
    if (g.rate >= RATES) g.rate = 0;
    if (g.gate >= GATES) g.gate = G_LVL;
    if (g.thr8 > THR_MAX / 8u) g.thr8 = (uint8_t)(256u / 8u);
    g.path = (uint8_t)(g.path == PATH_RAW);
    g.sq   = (uint8_t)(g.sq == 1u);
    if (g.sq && g.gate == G_SQL) g.gate = G_LVL;

    /* what we borrow, to give back: the BK4829's AF path and squelch, then
     * the MCU's ADC trigger, DMA mapping, timer and clock gates */
    g.r2B = api->bk_read(REG_2B);
    g.r73 = api->bk_read(REG_73);
    g.r4D = api->bk_read(REG_4D);
    g.r4E = api->bk_read(REG_4E);
    g.r4F = api->bk_read(REG_4F);
    g.r78 = api->bk_read(REG_78);
    g.cfgr3 = SYSCFG_CFGR3;
    g.tim1 = TIM3_CR1; g.tim2 = TIM3_CR2; g.psc = TIM3_PSC; g.arr = TIM3_ARR;
    g.ccr  = DMA1_C1_CCR;
    g.ahb  = RCC_AHBENR; g.apb1 = RCC_APBENR1; g.apb2 = RCC_APBENR2;

    /* the port first: claiming it locks the K5Viewer stream, so no screen
     * frame can land in the audio */
    api->serial_ctl(APP_SERIAL_USB, 0);
    api->af_capture_open();      /* PA4 analog, the DAC bias, ADC channel 4 */
    g.adcCr2 = ADC_CR2;          /* after af_capture_open: the channel is set */
    api->set_agc(false);         /* a frozen gain, as every capture app does */
    path();
    api->backlight_on();
    g.running   = true;
    g.streaming = true;
    g.redraw    = true;
    captureStart();
    stream();

    captureStop();
    TIM3_CR1 = g.tim1; TIM3_CR2 = g.tim2; TIM3_PSC = g.psc; TIM3_ARR = g.arr;
    DMA1_C1_CCR  = g.ccr;
    SYSCFG_CFGR3 = g.cfgr3;
    RCC_APBENR1  = g.apb1;
    RCC_AHBENR   = g.ahb;
    RCC_APBENR2  = g.apb2;
    api->bk_write(REG_2B, g.r2B);
    api->bk_write(REG_73, g.r73);
    api->bk_write(REG_4D, g.r4D);
    api->bk_write(REG_4E, g.r4E);
    api->bk_write(REG_4F, g.r4F);
    api->bk_write(REG_78, g.r78);
    api->set_agc(true);
    api->af_capture_close();
    api->set_af(APP_AF_MUTE);
    api->audio_path(false);
    api->cfg_save(g.set, CFG_LEN);
}

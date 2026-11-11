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
 * LaCrosse RX - 433.92 MHz OOK weather-sensor receiver for the Fusion
 * firmware. Decodes the LaCrosse TX141 family (TX141TH-Bv2 and Bv3 with
 * humidity, TX141/TX141B temperature only is NOT covered: those frames carry
 * no check byte, so they cannot be told from noise on this receiver).
 *
 * Route 2 of doc/doc.md 9.3: the AM detector's envelope leaves on PA4 and the
 * overlay samples it at 38.4 kHz, which puts 8 samples in a 208 us pulse and
 * 16 in a 417 us one. dectx141.c slices and decodes; this file is the radio
 * setup, the display and the keys.
 *
 * The VFO must be on an AM channel: the AM detector is enabled by the VFO
 * (REG_31 bit 0), not by the AF mode (doc 9.3). The app adds, on top:
 *   - the AGC frozen, so a silence is not amplified into a mark;
 *   - the widest IF filter, because these sensors sit tens of kHz off
 *     nominal - the three carriers found on air were 433.843, 433.918 and
 *     433.965 MHz (doc 9.6);
 *   - REG_2B's raw bits, which take the 300 Hz high-pass, the 3 kHz low-pass
 *     and the de-emphasis out of the AF path, and the AFC off;
 *   - a fine offset on REG_38/39 (+-40 kHz, 1 kHz a step), by hand or hunted
 *     automatically while nothing decodes.
 *
 * Keys (UP/DOWN through nav_dir, so UV-K1 LEFT/RIGHT work too):
 *   UP/DOWN offset +-1 kHz (stops the hunt) · MENU offset back to 0
 *   1 beep on a reading · 2 clear · 3 AF path RAW/WID/STK · 4 hunt on/off
 *   * next sensor · EXIT quit.  The beep, the path, the hunt and the offset
 *   are saved on exit.
 */

#include <stdbool.h>
#include <stdint.h>
#include "../app_api.h"
#include "lacrosserx_assets.h"
#include "dectx141.c"

#define HOUSE_EVERY   1920u    /* samples between two housekeeping rounds: 50 ms */
#define REFRESH_MS    1000u    /* a redraw at least this often                   */
#define BUSY_MAX        60u    /* never starve the keys for more than 3 s        */
#define SENSORS          3u
#define OFF_MAX         40     /* kHz either side                                */
#define STEP_10HZ      100     /* one offset step: 1 kHz                         */
#define HUNT_N           9u
#define HUNT_MS      90000u    /* no reading for 90 s: the next offset           */
#define BEEP_HZ       1536u
#define BEEP_MS         80u
#define CFG_LEN          5u
#define CFG_MAGIC     0x4Cu

/* BK4829 registers the app changes and restores. */
#define REG_2B        0x2B     /* bits 10:8: RX HPF 300, LPF 3k, de-emphasis    */
#define REG_31        0x31     /* bit 0: the AM detector, set by the VFO         */
#define REG_38        0x38
#define REG_39        0x39
#define REG_43        0x43     /* IF filter bandwidth                           */
#define REG_4D        0x4D     /* 0xA000 | glitch threshold, squelch close      */
#define REG_4E        0x4E     /* delays, and glitch threshold squelch open     */
#define REG_4F        0x4F     /* noise thresholds: close << 8 | open           */
#define REG_78        0x78     /* RSSI thresholds: open << 8 | close            */
#define REG_47        0x47     /* bits 11:8: AF output                          */
#define REG_73        0x73     /* bit 4: AFC disabled                           */
#define RAW_2B      0x0700u
#define WIDE_43     0x7E2Cu    /* ~11 kHz, as AIS and Sonde M20                 */
#define AFC_OFF_73  0x0010u
/* A squelch that never closes: the AF output is muted while it is closed
 * (sigfind's note on REG_47), and a burst lasts 380 ms - far too short to
 * wait for a squelch to make up its mind. Open RSSI threshold 0, both noise
 * thresholds at their maximum, both glitch thresholds at theirs; REG_4E's
 * open and close delays (bits 13:9) are kept. */
#define OPEN_4D     0xA0FFu
#define OPEN_4F     0x7F7Fu
#define OPEN_78     0x0000u

enum { PATH_RAW = 0, PATH_WIDE, PATH_STOCK };

/* The offsets the hunt walks, kHz: the filter is ~11 kHz wide, so 5 kHz
 * steps cover +-20 kHz without a hole. */
static const int8_t HUNT[HUNT_N] = { 0, 5, -5, 10, -10, 15, -15, 20, -20 };

typedef struct {
    uint32_t ms;               /* ticks_ms of the reading, 0 = empty slot       */
    int16_t  t10;
    uint8_t  id, hum, ch, batt;
} slot_t;

/* Bytes first (the saved settings in cfg order), then halfwords, then words:
 * every field stays inside Thumb-1's immediate offsets. */
static struct {
    union {
        uint8_t set[CFG_LEN];
        struct { uint8_t magic, beep, path, hunt; int8_t off; };
    };
    uint8_t  prevKey, sel, nSlot, huntIx;
    bool     running, redraw, am;
    uint16_t peak, ovr, rx;
    uint16_t r2B, r43, r73;    /* the VFO's own AF path, for STK and for exit    */
    uint16_t r4D, r4E, r4F, r78;   /* and its squelch                           */
    uint32_t base;             /* the VFO frequency, 10 Hz units                */
    uint32_t lastRx, drawn;    /* ticks_ms                                      */
    int16_t  rssi;
    const app_api_t *A;
    tx141_t  *d;
    slot_t   *slot;
    char     ui[UI_SIZE];
} g;

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

/* Tenths, always signed: 21.4, -0.5. */
static char *put1(char *o, int32_t v)
{
    uint32_t u = (uint32_t)(v < 0 ? -v : v);
    if (v < 0) *o++ = '-';
    o = puti(o, (int32_t)(u / 10u));
    *o++ = '.';
    *o++ = (char)('0' + u % 10u);
    return o;
}
/* "433.925" from 10 Hz units. */
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
/* "12s", "7m", "3h": how old a reading is. */
static char *putAge(char *o, uint32_t ms)
{
    uint32_t s = ms / 1000u;
    if (s < 100u) { o = puti(o, (int32_t)s); *o++ = 's'; }
    else if (s < 6000u) { o = puti(o, (int32_t)(s / 60u)); *o++ = 'm'; }
    else { o = puti(o, (int32_t)(s / 3600u)); *o++ = 'h'; }
    return o;
}
static void tiny(char *buf, uint8_t x, uint8_t y, char *end)
{ *end = '\0'; g.A->print_tiny(buf, x, y, false, true); }

/* ---- radio ---- */

/* The AF path and the IF filter for the selected mode, after any call that
 * resets them (tones_off_rx, a beep, a retune). */
__attribute__((noinline))
static void path(void)
{
    const app_api_t *A = g.A;
    /* First, always: BK4819_TurnsOffTones_TurnsOnRX sets the AF to MUTE, so
     * every retune, beep and path change leaves PA4 deaf without this. */
    A->set_af(APP_AF_FM);        /* the AM detector feeds the FM output (doc 9.3) */
    A->bk_write(REG_43, g.path == PATH_STOCK ? g.r43 : WIDE_43);
    A->bk_write(REG_2B, g.path == PATH_RAW ? RAW_2B : g.r2B);
    A->bk_write(REG_73, g.path == PATH_RAW ? AFC_OFF_73 : g.r73);
    A->bk_write(REG_4D, OPEN_4D);
    A->bk_write(REG_4E, (uint16_t)((g.r4E & 0xFF00u) | 0x00FFu));
    A->bk_write(REG_4F, OPEN_4F);
    A->bk_write(REG_78, OPEN_78);
}

static void tune(void)
{
    uint32_t f = (uint32_t)((int32_t)g.base + (int32_t)g.off * STEP_10HZ);
    g.A->bk_write(REG_38, (uint16_t)(f & 0xFFFFu));
    g.A->bk_write(REG_39, (uint16_t)(f >> 16));
    g.A->tones_off_rx();      /* REG_30 to 0 then RX: VCO recalibration, relock */
    path();
    g.redraw = true;
}

static void setOff(int8_t off)
{
    if (off > OFF_MAX) off = OFF_MAX;
    if (off < -OFF_MAX) off = -OFF_MAX;
    if (off == g.off) return;
    g.off = off;
    tune();
}

/* ---- readings ---- */
static void store(const tx141_rec_t *r, uint32_t now)
{
    uint8_t s = 0;
    while (s < g.nSlot && g.slot[s].id != r->id) s++;
    if (s == g.nSlot) {
        if (g.nSlot < SENSORS) g.nSlot++;
        else {                                   /* replace the oldest slot */
            s = 0;
            for (uint8_t k = 1; k < g.nSlot; k++)
                if (now - g.slot[k].ms > now - g.slot[s].ms) s = k;
        }
    }
    g.slot[s].id   = r->id;
    g.slot[s].t10  = r->t10;
    g.slot[s].hum  = r->hum;
    g.slot[s].ch   = r->ch;
    g.slot[s].batt = r->batt;
    g.slot[s].ms   = now ? now : 1u;
    g.sel = s;
    g.rx++;
    g.lastRx = now;
    g.redraw = true;
}

/* ---- display ---- */
static void draw(void)
{
    const app_api_t *A = g.A;
    char buf[36], *o;

    A->status_clear();
    A->print_tiny(T(T_TITLE), 2, 1, true, true);
    if (g.beep) A->asset_read(BMP_BEEP, A->status_line + 50u, ICON_W);
    A->draw_battery();
    A->display_clear();

    /* the tuned frequency, the path, the hunt, then the frames accepted */
    o = putFreq(buf, (uint32_t)((int32_t)g.base + (int32_t)g.off * STEP_10HZ));
    if (g.off) { *o++ = ' '; if (g.off > 0) *o++ = '+'; o = puti(o, g.off); o = put(o, T(T_K)); }
    *o++ = ' ';
    o = putn(o, T(T_PATH) + 1 + g.path * 4u, 3u);
    if (g.hunt) o = put(o, T(T_AUTO));
    tiny(buf, 2, 1, o);
    o = put(buf, T(T_RX));
    o = puti(o, g.rx);
    tiny(buf, (uint8_t)(126u - 4u * (uint8_t)(o - buf)), 1, o);

    /* the selected sensor: the reading in big digits, or why there is none */
    const slot_t *s = &g.slot[g.sel];
    if (!s->ms) {
        A->print_normal(T(g.am ? T_NODATA : T_SETAM), 2, 127, 2);
    } else {
        o = put1(buf, s->t10);
        *o = '\0';
        A->display_freq(buf, 2, 2, false);
        uint8_t w = 2u;                 /* UI_DisplayFrequency: 13 px a glyph, 3 a point */
        for (const char *q = buf; *q; q++) w = (uint8_t)(w + (*q == '.' ? 3u : 13u));
        A->print_normal(T(T_DEG), (uint8_t)(w + 2u), 127, 3);
        o = put(buf, T(T_RH));
        o = puti(o, s->hum);
        o = put(o, T(T_PCT));
        if (s->batt) { *o++ = ' '; o = put(o, T(T_BATLOW)); }
        *o = '\0';
        A->print_normal(buf, 2, 127, 4);
        o = put(buf, T(T_ID));
        o = puti(o, s->id);
        o = put(o, T(T_CH));
        o = puti(o, s->ch + 1);
        *o++ = ' ';
        o = putAge(o, A->ticks_ms() - s->ms);
        tiny(buf, 2, 41, o);
    }

    /* the sensors that are not selected, newest first */
    o = buf;
    for (uint8_t k = 0; k < g.nSlot; k++) {
        if (k == g.sel || !g.slot[k].ms) continue;
        o = puti(o, g.slot[k].id);
        *o++ = ':';
        o = put1(o, g.slot[k].t10);
        *o++ = ' ';
    }
    if (o != buf) tiny(buf, 2, 49, o);
    o = puti(buf, g.rssi);
    o = put(o, T(T_DBM));
    tiny(buf, (uint8_t)(126u - 4u * (uint8_t)(o - buf)), 49, o);

    /* what the front end hears: transitions, the loudest envelope seen, the
     * samples the housekeeping dropped */
    o = put(buf, T(T_EV));
    o = puti(o, g.d->edges);
    o = put(o, T(T_CL));
    o = puti(o, g.d->nCell);
    o = put(o, T(T_PK));
    o = puti(o, g.peak);
    o = put(o, T(T_OVR));
    o = puti(o, g.ovr);
    tiny(buf, 2, 57, o);

    A->blit_status();
    A->blit_full();
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

    int8_t dir = A->nav_dir(key);
    A->backlight_on();
    if (dir) { g.hunt = 0; setOff((int8_t)(g.off + dir)); return; }
    switch (key) {
    case APP_KEY_EXIT: g.running = false; break;
    case APP_KEY_MENU: g.hunt = 0; setOff(0); break;
    case APP_KEY_1: g.beep ^= 1u; break;
    case APP_KEY_2:
        g.rx = g.peak = g.ovr = 0;
        g.nSlot = g.sel = 0;
        for (uint8_t k = 0; k < SENSORS; k++) g.slot[k].ms = 0;
        g.d->edges = g.d->nCell = g.d->good = 0;
        for (uint8_t k = 0; k < 2u; k++) {
            g.d->arm[k].havePend = false;
            g.d->arm[k].cells = 0;
        }
        break;
    case APP_KEY_3:
        g.path = (uint8_t)(g.path + 1u < 3u ? g.path + 1u : 0u);
        tune();                                 /* reapplies the whole path */
        break;
    case APP_KEY_4:
        g.hunt ^= 1u;
        g.huntIx = 0;
        g.lastRx = A->ticks_ms();
        break;
    case APP_KEY_STAR:
        if (g.nSlot) g.sel = (uint8_t)(g.sel + 1u < g.nSlot ? g.sel + 1u : 0u);
        break;
    default: return;
    }
    g.redraw = true;
}

/* ---- the sampling loop ---- */
static void listen(void)
{
    const app_api_t *A = g.A;
    uint32_t (*const clk)(void) = A->cycles_48mhz;
    uint16_t (*const adc)(void) = A->af_capture_sample;
    uint32_t next = clk();
    uint16_t n = 0;
    uint8_t  busyFor = 0;
    tx141_rec_t rec;

    while (g.running) {
        while ((int32_t)(clk() - next) < 0) {}
        if ((int32_t)(clk() - next) >= (int32_t)TX_SAMPLE_CYC && g.ovr < 9999u) g.ovr++;
        next += TX_SAMPLE_CYC;
        if (tx141_push(g.d, adc()) && tx141_fields(g.d->frame, &rec)) {
            store(&rec, A->ticks_ms());
            if (g.beep) {
                A->play_tone(BEEP_HZ, BEEP_MS);   /* takes the AF path with it */
                A->tones_off_rx();
                A->audio_path(false);
                path();
            }
            next = clk();
        }
        uint16_t env = (uint16_t)(g.d->envQ >> 8);
        if (env > g.peak) g.peak = env;
        if (++n < HOUSE_EVERY) continue;
        n = 0;
        /* A frame is 26 ms and a burst twelve of them: the housekeeping, and
         * above all a full screen, must not fall inside one. It waits while
         * bits are coming, and never longer than BUSY_MAX. */
        if (tx141_busy(g.d) && ++busyFor < BUSY_MAX) continue;
        busyFor = 0;
        uint32_t now = A->ticks_ms();
        keys();
        if (!g.running) break;
        if (g.hunt && now - g.lastRx > HUNT_MS) {
            g.huntIx = (uint8_t)(g.huntIx + 1u < HUNT_N ? g.huntIx + 1u : 0u);
            g.lastRx = now;
            setOff(HUNT[g.huntIx]);
        }
        if (g.redraw || now - g.drawn > REFRESH_MS) {
            g.rssi = A->rssi_dbm();
            g.redraw = false;
            draw();
        }
        A->battery_sample();         /* yields the capture's ADC itself */
        A->backlight_update();
        next = clk();
    }
}

__attribute__((section(".text.entry"), used))
void app_main(const app_api_t *api)
{
    tx141_t dec;
    slot_t  slots[SENSORS];

    for (unsigned k = 0; k < sizeof dec; k++) ((uint8_t *)&dec)[k] = 0;
    for (unsigned k = 0; k < sizeof slots; k++) ((uint8_t *)slots)[k] = 0;
    g.A    = api;
    g.d    = &dec;
    g.slot = slots;
    g.prevKey = APP_KEY_INVALID;
    api->asset_read(0, g.ui, UI_SIZE);

    api->cfg_load(g.set, CFG_LEN);
    if (g.magic != CFG_MAGIC) {
        g.magic = CFG_MAGIC; g.beep = 1u; g.path = PATH_RAW; g.hunt = 0; g.off = 0;
    }
    if (g.path > PATH_STOCK) g.path = PATH_RAW;
    if (g.off > OFF_MAX || g.off < -OFF_MAX) g.off = 0;
    g.beep = (uint8_t)(g.beep == 1u);
    g.hunt = (uint8_t)(g.hunt == 1u);

    g.am   = (api->bk_read(REG_31) & 1u) != 0u;   /* the VFO's AM detector */
    g.base = api->rx_freq();
    g.r2B = api->bk_read(REG_2B);
    g.r43 = api->bk_read(REG_43);
    g.r73 = api->bk_read(REG_73);
    g.r4D = api->bk_read(REG_4D);
    g.r4E = api->bk_read(REG_4E);
    g.r4F = api->bk_read(REG_4F);
    g.r78 = api->bk_read(REG_78);

    api->af_capture_open();      /* PA4 bias and ADC channel 4, restored by close */
    api->set_agc(false);         /* a frozen gain: silence must stay silent */
    tune();                      /* the offset, the filter and the AF path */
    api->delay_ms(50);
    api->backlight_on();
    g.lastRx = api->ticks_ms();
    g.running = true;
    g.redraw = true;
    listen();

    /* staged first: the offset found is worth keeping, and the retune below
     * clears it */
    api->cfg_save(g.set, CFG_LEN);
    if (g.off) { g.off = 0; tune(); }   /* back on the VFO's own frequency */
    api->bk_write(REG_2B, g.r2B);       /* after tune(), which reapplies path() */
    api->bk_write(REG_43, g.r43);
    api->bk_write(REG_73, g.r73);
    api->bk_write(REG_4D, g.r4D);
    api->bk_write(REG_4E, g.r4E);
    api->bk_write(REG_4F, g.r4F);
    api->bk_write(REG_78, g.r78);
    api->set_agc(true);
    api->af_capture_close();
    api->set_af(APP_AF_MUTE);
    api->audio_path(false);
}

/* Host test of the LaCrosse TX141 decoder (../dectx141.c).
 *
 *   ./run_tests.sh
 *
 * Synthesizes what PA4 sees: the OOK burst through the AM detector (envelope,
 * optionally the 3 kHz audio low-pass the stock path has), the PA4 coupling
 * (first-order high-pass, 1 kHz, as measured on the K1 with POCSAG and used by
 * sigfind/test/sweep_test.c), white noise, mid-scale bias and the 12-bit ADC,
 * sampled the way the app does. The transmitter follows rtl_433's description
 * of the family (doc/doc.md 9.5).
 */
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../dectx141.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define SEG_MAX 12000

static uint32_t rng = 1u;
static double urand(void) { rng = rng * 1664525u + 1013904223u; return ((rng >> 8) + 0.5) / 16777216.0; }
static double gauss(void) { return sqrt(-2.0 * log(urand())) * cos(2.0 * M_PI * urand()); }

/* ---- transmitter: a segment list in us, positive = carrier on ---- */
typedef struct { double us[SEG_MAX]; int n; } wave_t;

static void seg(wave_t *w, double us) { if (w->n < SEG_MAX) w->us[w->n++] = us; }

static void frame_bytes(const tx141_rec_t *r, uint8_t *b)
{
    uint16_t raw = (uint16_t)(r->t10 + 500);
    b[0] = r->id;
    b[1] = (uint8_t)((r->batt << 7) | (r->test << 6) | (r->ch << 4) | ((raw >> 8) & 0x0Fu));
    b[2] = (uint8_t)raw;
    b[3] = r->hum;
    b[4] = tx141_digest(b);
}

/* One packet: four preamble pulses then 40 (or 41) PWM bits. */
static void packet(wave_t *w, const uint8_t *b, int bits)
{
    for (int k = 0; k < 4; k++) { seg(w, 833.0); seg(w, -833.0); }
    for (int i = 0; i < bits; i++) {
        int bit = i < 40 ? (b[i >> 3] >> (7 - (i & 7))) & 1 : 0;
        seg(w, bit ? 417.0 : 208.0);
        seg(w, bit ? -208.0 : -417.0);
    }
}

static void burst(wave_t *w, const uint8_t *b, int copies, int bits)
{
    seg(w, -20000.0);
    for (int k = 0; k < copies; k++) packet(w, b, bits);
    seg(w, -40000.0);
}

/* ---- channel + receiver ---- */
typedef struct {
    double amp;        /* envelope amplitude, ADC LSB                   */
    double noise;      /* rms noise, ADC LSB                            */
    double lpHz;       /* audio low-pass (0 = the REG_2B raw path)      */
    double hpHz;       /* PA4 coupling                                  */
    double clockErr;   /* sample clock error, fraction                  */
    bool   invert;     /* the envelope upside down at PA4                */
} chan_t;

typedef struct { int frames; tx141_rec_t last; tx141_t d; } res_t;

static void run(const wave_t *w, const chan_t *c, res_t *out, uint32_t seed)
{
    double usPerSample = 1e6 / TX_FS * (1.0 + c->clockErr);
    double lp = 0.0, hpX = 0.0, hpY = 0.0;
    double ka = c->hpHz > 0 ? 1.0 / (1.0 + 2.0 * M_PI * c->hpHz * usPerSample * 1e-6) : 1.0;
    double kb = c->lpHz > 0 ? 1.0 - exp(-2.0 * M_PI * c->lpHz * usPerSample * 1e-6) : 1.0;
    double left = fabs(w->us[0]);
    int s = 0;
    rng = seed;

    for (;;) {
        double on = 0.0, need = usPerSample;
        while (need > 0.0 && s < w->n) {
            double take = left < need ? left : need;
            if (w->us[s] > 0.0) on += take;
            left -= take; need -= take;
            if (left <= 0.0 && ++s < w->n) left = fabs(w->us[s]);
        }
        if (s >= w->n) break;
        double x = c->amp * (on / usPerSample);
        if (c->invert) x = -x;
        lp += kb * (x - lp);
        double y = c->hpHz > 0 ? ka * (hpY + lp - hpX) : lp;
        hpX = lp; hpY = y;
        double v = 2048.0 + y + c->noise * gauss();
        uint16_t adc = (uint16_t)(v < 0 ? 0 : v > 4095 ? 4095 : v);
        if (tx141_push(&out->d, adc)) {
            out->frames++;
            tx141_fields(out->d.frame, &out->last);
        }
    }
}

/* A Flipper RAW file (flipper_tx141.py) through the same channel: the
 * generator and the decoder have to agree on the waveform before the files
 * are sent on the air. */
static bool load_sub(const char *path, wave_t *w)
{
    FILE *fp = fopen(path, "r");
    if (!fp) { perror(path); return false; }
    static char line[1 << 16];
    w->n = 0;
    while (fgets(line, sizeof line, fp)) {
        if (strncmp(line, "RAW_Data:", 9)) continue;
        char *q = line + 9, *e;
        for (long v; (v = strtol(q, &e, 10)), e != q; q = e)
            if (w->n < SEG_MAX) w->us[w->n++] = (double)v;
    }
    fclose(fp);
    return w->n > 0;
}

/* ---- cases ---- */
static int fails = 0;

static void check(const char *name, bool ok, const char *why)
{
    printf("%-34s %s%s%s\n", name, ok ? "ok" : "FAIL", ok ? "" : " - ", ok ? "" : why);
    if (!ok) fails++;
}

static bool eq(const tx141_rec_t *a, const tx141_rec_t *b)
{
    return a->id == b->id && a->hum == b->hum && a->ch == b->ch &&
           a->batt == b->batt && a->test == b->test && a->t10 == b->t10;
}

static void one(const char *name, tx141_rec_t tx, const chan_t *c, int copies,
                int bits, bool expect)
{
    static wave_t w;
    uint8_t b[5];
    res_t r;
    memset(&w, 0, sizeof w);
    memset(&r, 0, sizeof r);
    frame_bytes(&tx, b);
    burst(&w, b, copies, bits);
    run(&w, c, &r, 12345u);
    char why[160];
    snprintf(why, sizeof why, "frames %d, cells %u, edges %u, digest hits %u",
             r.frames, r.d.nCell, r.d.edges, r.d.good);
    if (!expect) { check(name, r.frames == 0, why); return; }
    check(name, r.frames > 0 && eq(&r.last, &tx), why);
}

/* The .sub files, named as flipper_tx141.py writes them. */
static const struct { const char *name; bool decode; } SUBS[] = {
    { "tx141_ref",    true  },
    { "tx141_cold",   true  },
    { "tx141_hot",    true  },
    { "tx141_bv3",    true  },
    { "tx141_two",    true  },
    { "tx141_single", false },
    { "tx141_badchk", false },
    { "tx141_tune",   false },
};

static void subs(const char *dir)
{
    static wave_t w;
    chan_t stock = { .amp = 600, .noise = 8, .lpHz = 3000, .hpHz = 1000, .clockErr = 0 };
    for (unsigned k = 0; k < sizeof SUBS / sizeof SUBS[0]; k++) {
        char path[512], name[80], why[160];
        res_t r;
        snprintf(path, sizeof path, "%s/%s.sub", dir, SUBS[k].name);
        snprintf(name, sizeof name, "%s.sub", SUBS[k].name);
        memset(&r, 0, sizeof r);
        if (!load_sub(path, &w)) { check(name, false, "no RAW_Data"); continue; }
        run(&w, &stock, &r, 4242u);
        snprintf(why, sizeof why, "frames %d, cells %u, edges %u",
                 r.frames, r.d.nCell, r.d.edges);
        if (SUBS[k].decode)
            check(name, r.frames > 0, why);
        else
            check(name, r.frames == 0 && r.d.edges > 0u, why);
    }
}

int main(int argc, char **argv)
{
    tx141_rec_t ref = { .id = 0xA7u, .hum = 54u, .ch = 1u, .batt = 0u, .test = 0u, .t10 = 214 };
    chan_t ideal = { .amp = 600, .noise = 0, .lpHz = 0, .hpHz = 0, .clockErr = 0 };
    chan_t raw   = { .amp = 600, .noise = 8, .lpHz = 0, .hpHz = 1000, .clockErr = 0 };
    chan_t stock = { .amp = 600, .noise = 8, .lpHz = 3000, .hpHz = 1000, .clockErr = 0 };

    /* the digest, against a frame rtl_433 accepts */
    uint8_t probe[5];
    frame_bytes(&ref, probe);
    check("digest round trip", tx141_digest(probe) == probe[4], "digest mismatch");

    /* The one external vector: rtl_433_tests tests/lacrosse/tx141th-bv2,
     * codes_test.txt, four rows of which only the first is valid. Its rows
     * are the slicer's output before rtl_433 inverts them, so they are this
     * decoder's bytes complemented - which is what pins the bit order, the
     * inversion and the digest to something not written here. */
    {
        static const uint8_t ROWS[4][5] = {
            { 0x18u, 0xEEu, 0xD3u, 0xF5u, 0x61u },
            { 0x19u, 0xEEu, 0xD3u, 0xF5u, 0x61u },
            { 0x18u, 0xEEu, 0xD2u, 0xF5u, 0x61u },
            { 0x18u, 0xEEu, 0xD3u, 0xF4u, 0x61u },
        };
        uint8_t b[5];
        tx141_rec_t r;
        bool ok = true;
        for (unsigned row = 0; row < 4u; row++) {
            for (unsigned k = 0; k < 5u; k++) b[k] = (uint8_t)~ROWS[row][k];
            bool pass = tx141_digest(b) == b[4] && tx141_fields(b, &r);
            if (pass != (row == 0u)) ok = false;
        }
        for (unsigned k = 0; k < 5u; k++) b[k] = (uint8_t)~ROWS[0][k];
        tx141_fields(b, &r);
        check("rtl_433 reference vector",
              ok && r.id == 231u && r.t10 == -200 && r.hum == 10u &&
              r.ch == 1u && r.batt == 0u, "fields or digest disagree");
        /* and the same frame as a 41-bit waveform, as the capture has it */
        tx141_rec_t vec = { .id = 231u, .hum = 10u, .ch = 1u, .batt = 0u,
                            .test = 0u, .t10 = -200 };
        one("rtl_433 vector, 41-bit burst", vec, &stock, 12, 41, true);
    }

    one("ideal envelope", ref, &ideal, 12, 40, true);
    one("raw path, noise", ref, &raw, 12, 40, true);
    one("stock path, 3 kHz low-pass", ref, &stock, 12, 40, true);

    chan_t weak = stock; weak.amp = 60; weak.noise = 10;   /* 6:1, close to the floor */
    one("weak signal", ref, &weak, 12, 40, true);

    chan_t fast = stock; fast.clockErr = +0.015;
    chan_t slow = stock; slow.clockErr = -0.015;
    one("sample clock +1.5 %", ref, &fast, 12, 40, true);
    one("sample clock -1.5 %", ref, &slow, 12, 40, true);

    chan_t rough = { .amp = 400, .noise = 8, .lpHz = 1200, .hpHz = 2300, .clockErr = 0.05 };
    one("narrow filter, 5 % clock", ref, &rough, 12, 40, true);

    tx141_rec_t cold = { .id = 0x3Cu, .hum = 88u, .ch = 2u, .batt = 1u, .test = 0u, .t10 = -75 };
    one("negative temperature", cold, &stock, 12, 40, true);

    tx141_rec_t hot = { .id = 0xFFu, .hum = 100u, .ch = 3u, .batt = 0u, .test = 1u, .t10 = 600 };
    one("field limits", hot, &stock, 12, 40, true);

    chan_t upside = stock; upside.invert = true;
    one("inverted envelope", ref, &upside, 12, 40, true);
    chan_t upRaw = raw; upRaw.invert = true;
    one("inverted, raw path", ref, &upRaw, 12, 40, true);

    one("Bv3, 41 bits", ref, &stock, 12, 41, true);
    one("four copies only", ref, &stock, 4, 40, true);
    one("a single copy is not believed", ref, &stock, 1, 40, false);

    /* a corrupted check byte must not get through */
    {
        static wave_t w;
        uint8_t b[5];
        res_t r;
        memset(&w, 0, sizeof w); memset(&r, 0, sizeof r);
        frame_bytes(&ref, b);
        b[4] ^= 0x20u;
        burst(&w, b, 12, 40);
        run(&w, &stock, &r, 7u);
        check("bad check byte rejected", r.frames == 0, "accepted a bad digest");
    }

    /* noise only: an 8-bit digest passes about one window in 256, so the
     * field ranges and the second copy have to keep them all out */
    {
        static wave_t w;
        res_t r;
        memset(&w, 0, sizeof w); memset(&r, 0, sizeof r);
        for (int k = 0; k < SEG_MAX - 1; k++) seg(&w, (k & 1) ? -200.0 : 200.0);
        chan_t n = { .amp = 0, .noise = 40, .lpHz = 3000, .hpHz = 1000, .clockErr = 0 };
        int frames = 0;
        for (uint32_t s = 1; s <= 40u; s++) {   /* ~40 x 1.6 s of noise */
            memset(&r, 0, sizeof r);
            run(&w, &n, &r, s * 7919u);
            frames += r.frames;
        }
        char why[80];
        snprintf(why, sizeof why, "%d frames out of noise", frames);
        check("noise only, no frame", frames == 0, why);
    }

    if (argc > 1) subs(argv[1]);

    printf(fails ? "\n%d test(s) FAILED\n" : "\nall tests passed\n", fails);
    return fails ? 1 : 0;
}

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
 * PLL FM - does the BK4829 accept direct FM, i.e. the audio written straight
 * into the frequency registers at sample rate, instead of through the tone
 * generator?  That is the one question between "TX can only send tones" and
 * "TX can send a recorded clip"; doc/doc.md section 8.4 leaves both halves of
 * it open.  Everything here is listened to on a second receiver; the radio
 * itself shows no result but the measured write cost.
 *
 * The experiment, in twelve modes (* cycles them, MENU or PTT sends a burst on
 * the TX VFO at its own power, 3 s by default):
 *
 *   PLL     the test proper: REG_38 (frequency, low 16 bits, 10 Hz units)
 *           rewritten at Fs = N x Fmod from a N-point sine of +-DEV, REG_39
 *           only when the high half changes.  1 kHz deviation and 300 Hz
 *           modulation by default.  Heard on an FM receiver: a clean 300 Hz
 *           note means direct FM works, and a clip becomes possible.
 *   TONE    the reference, same Fmod through the BK4829 tone generator
 *           (REG_70/REG_71, gain 66 as BK4819_TransmitTone uses): the
 *           known-good path, to judge PLL's level and quality against.
 *   STEP    +DEV / -DEV at 2 Hz, written exactly as PLL writes (REG_39 only
 *           when the high half moves, then REG_38), no REG_30 toggle: does a
 *           small retune take effect at all, and does it re-lock cleanly?  A
 *           +-1 kHz step is a DC shift, so judge it as a beat note in USB/CW
 *           or on an SDR waterfall, not on an FM receiver, which only thumps.
 *   STEP39  the same in BK4819_SetFrequency's order, REG_38 then REG_39 at
 *           every step: tells apart a chip that latches the frequency on the
 *           REG_39 write, which PLL mostly skips.
 *   STEP+T  the driver's order plus the REG_30 off/on toggle of spectrum.c
 *           SetF and CW Keyer, which both treat it as required for a
 *           frequency write to take effect.
 *   STEP+C  the same with only the VCO calibration bit <15> flipped, so the
 *           PLL and the PA stay powered: the cheapest toggle that might be
 *           compatible with a per-sample rate.  Untried anywhere in the tree,
 *           low power only.  The STEP modes separate the failure modes:
 *             STEP shifts, PLL silent      -> the PLL loop filters the audio,
 *                                             or Fs is too low
 *             STEP flat, STEP39 shifts     -> the latch is on REG_39: PLL must
 *                                             write both every sample, so
 *                                             budget two writes per sample
 *             only STEP+T shifts           -> the write needs the toggle, and
 *                                             direct FM is dead (the toggle
 *                                             drops the carrier every sample)
 *             STEP shifts and PLL is heard -> direct FM works
 *   CARR    a bare carrier, and the bisection of the key-up: key 7 picks how
 *           far it goes, S1 to S6 (keyUp below).  Measured on hardware
 *           (2026-11-10): S1 and S6 sag the battery by the same 0.12 V, so
 *           every stage keys the PA and the bisection found nothing to
 *           bisect.  The one thing v0.3, which was silent, still did and
 *           v0.4 dropped is the tx_prepare call - the likeliest cause, though
 *           the air test that would prove it was never run on v0.3 again.
 *   GDC     REG_71 = 0 and the REG_70 gain stepped at 2 Hz: does a stopped
 *           tone DDS hold a DC the gain scales?  See the block above runGstep.
 *   GAIN    the sine written into that gain field at Fs - REG_70 as a 7-bit
 *           baseband DAC into the modulator, the route REG_38 could not be.
 *   GTONE   the gain stepped at 2 Hz with the DDS running: the control, which
 *           must show two deviation levels whatever GDC does.
 *   RAW     the resident key-up alone - RADIO_SetTxParameters, a wait, back
 *           to RX - which is all FUNCTION_Transmit does on a PTT press
 *           (functions.c:167), and nothing else at all.  Confirmed on the air
 *           (2026-11-10): the radio does key from an app, so a silent mode is
 *           this app's sequence, never the radio.
 *
 * 4 measures the real cost of one register write (64 writes of REG_71 with
 * the tone generator off, timed with cycles_48mhz), shows it in cycles and as
 * the sample rate it allows, and picks N from it: 32 points, or 16 or 8 when
 * one write does not fit in a sample period.  Fs, N and the write cost are on
 * the screen, so a silent PLL burst can never be blamed on the bus; "SLOW"
 * means not even 8 points fit and the note is lower than Fmod.
 *
 * Every mode but RAW keys up through keyUp(), whose stages are listed there;
 * the frequency tx_set_params tuned is read back before stage 5 overwrites
 * it, because the filter path and the PA calibration come from gCurrentVfo,
 * the RX VFO under dual watch (radio.c:772): a reading that is a real
 * frequency more than 1 MHz from ours means another band, so another LPF, and
 * the burst is refused (key 5 forces).  A reading that is no frequency at all
 * only tells that REG_38/39 do not read back: "NORB", and the burst goes out.
 *
 * Keys: MENU or PTT send * mode  1 / F then 1 deviation  2 / F then 2
 * modulation  3 burst length  4 measure again  5 force  7 / F then 7 the
 * CARR stage  EXIT quit.
 *
 * ANSWERED ON HARDWARE, 2026-11-10 (UV-K1, 143.98750 MHz, low power, 3 s
 * bursts, received on a Maia SDR at 25 ksps and demodulated offline):
 *   TONE    ~3.0 kHz of deviation at 300 Hz - the generator works
 *   PLL     1.3 Hz at 300 Hz, the noise floor - DIRECT FM PRODUCES NOTHING
 *   STEP    flat to 8 Hz rms  - a bare REG_38 write does nothing
 *   STEP39  flat to 10 Hz rms - nor does REG_38 then REG_39
 *   STEP+T  a clean +-1000 Hz square at 2 Hz - the REG_30 toggle latches it
 *   STEP+C  identical - toggling bit 15 alone is enough, PLL and PA stay up
 * Re-recorded at 250 ksps, the toggle blanks the carrier HARD: the envelope
 * falls to ~1 % for 104-112 us at every edge, with no settling delay in
 * runStep, so that is the chip's own figure - one click per retune.  8 kHz
 * audio is a 125 us sample period, so direct FM is dead whatever the bus
 * costs; Doppler retuning, one click every few seconds, is comfortable.
 * The battery meter (below) agreed with all of it: every mode sagged 12 units
 * while the CARR S0 control sagged none.
 *
 * THE WAY ROUND IT, measured the same day with the four G modes:
 *   GTONE   the gain switches the deviation 5850 / 539 Hz rms inside one
 *           50 ms block - a REG_70 write is live and instantaneous
 *   GDC     nothing, +-1 Hz: with REG_71 written 0 before the generator was
 *           enabled the accumulator was already sitting at zero
 *   GPARK   run the DDS at 32 Hz, wait 8 ms, then write 0: the carrier parks
 *           at +6892 Hz (gain 126) / +769 Hz (gain 2) - A ZERO FREQUENCY WORD
 *           FREEZES THE PHASE, IT DOES NOT CLEAR IT
 *   GAIN    the sine in the gain field at Fs over a parked phase: 298 Hz at
 *           3.4 kHz of deviation, and 993 Hz at 3.2 kHz with Fmod 1 kHz,
 *           Fs 8 kHz, N 8 - the voice sample rate, one 80 us write a sample,
 *           no REG_30 and no blanking.  REG_70 <14:8> is a 7-bit baseband DAC
 *           into the modulator, so a clip on transmit is possible.
 * Its costs: the gain law is compressed (63:1 of gain for 9:1 of deviation,
 * ~11 % THD without a linearising table), the output is unipolar so the
 * carrier rides a ~+3.7 kHz pedestal, and the park must be redone at each
 * key-up.  See doc/doc.md section 8.4.
 *
 * The radio cannot hear itself, so every burst also measures the battery:
 * "V 760>712" is the pack on RX then under the keyed PA, in 10 mV units.  A
 * real carrier pulls the voltage down by several units; a burst that leaves
 * it flat put nothing in the PA.  It is a differential instrument - compare a
 * stage against RAW or CARR S1, which are known to carry.
 *
 * The title carries the blob version, and the status line is in the normal
 * font: a refusal (TX DENIED <code>, CHIP ON <frequency>) is meant to be
 * unmissable.  "RB <frequency>" is what REG_38/39 read back at the last
 * key-up, "NORB" that they do not read back at all.
 *
 * An API test app, like Handoff A/B and VFO Test: not built by
 * "compile-app.sh All", built by name.  Nothing is saved.
 */

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "../app_api.h"

/* ---- BK4829 ---- */
#define REG_30      0x30   /* link / DSP enables; the off-on toggle re-locks the PLL */
#define REG_38      0x38   /* frequency, low 16 bits, 10 Hz units              */
#define REG_39      0x39   /* frequency, high 16 bits                          */
#define REG_51      0x51   /* sub-audio: 0 = no CTCSS/DCS (BK4819_ExitSubAu)   */
#define REG_70      0x70   /* tone 1: <15> enable, <14:8> gain                 */
#define REG_71      0x71   /* tone 1 frequency, Hz x 10.32444                  */
#define TONE_LVL    66u    /* BK4819_TransmitTone's tone gain                  */
/* REG_30 words, CW Keyer's (cwkeyer_app.c:154): BK4819_EnableTXLink's value
 * with the mic ADC off, the same without the internal PA gain, and all off.
 * NO_VCO keeps everything but the VCO calibration bit <15>. */
#define TX_LINK_NO_MIC 0xC3FAu
#define TX_LINK_NO_PA  0xC3F2u
#define TX_LINK_NO_VCO 0x43FAu
#define TX_LINK_OFF    0x0000u
#define PLL_LOCK_MS    2u     /* CW Keyer's settling delay after the restart */
#define STAGE_MAX      6u     /* a full key-up, what the modulating modes need */
/* A reading of REG_38/39 is taken for a real frequency between these, in
 * 10 Hz units: 18 MHz to 1.3 GHz, the chip's own range. */
#define F_PLAUS_MIN 1800000u
#define F_PLAUS_MAX 130000000u
#define F_BAND_TOL  100000u   /* 1 MHz: beyond it, another band and another LPF */

#define F_PARK    330u     /* scale_freq(32 Hz): the tone used to park the DDS */
#define G_MIN       2u     /* the gain field swings 64 +- 62 ...              */
#define G_MAX     126u     /* ... so the DC probe steps between these two     */
#define NPTS_MAX    32u
#define SAMP_MARGIN 3u     /* a sample period must hold one write plus 1/8 of it */

enum { M_PLL = 0, M_TONE, M_STEP, M_STEP39, M_STEPT, M_STEPC, M_CARR, M_RAW,
       M_GDC, M_GAIN, M_GTONE, M_GPARK, M_COUNT };
enum { S_READY = 0, S_TX, S_DONE, S_DENIED, S_MISMATCH };

/* One struct, as the other apps: one base address instead of a literal-pool
 * word per global.  The loader zeroes the overlay (.bss) at every launch. */
static struct {
    const app_api_t *A;
    uint8_t  mode, npts, stride, dur, iMod, prevKey, status, denial;
    uint8_t  stage;                /* CARR only: how far the key-up goes, 0-6 */
    bool     running, fArm, carry;
    bool     slow;                 /* even N = 8 does not fit: Fs is not held  */
    bool     norb;                 /* REG_38/39 did not read back a frequency */
    bool     rbSeen;               /* a readback has been taken: show RB      */
    bool     force;                /* key 5: transmit despite a frequency mismatch */
    uint16_t dev;                  /* deviation, 10 Hz units (100 = 1 kHz)     */
    uint16_t fmod;                 /* modulating frequency, Hz                 */
    uint32_t cyc;                  /* cycles for one register write, measured  */
    uint32_t cps;                  /* cycles per sample at the chosen Fs       */
    uint32_t f0;                   /* TX frequency, 10 Hz units                */
    uint32_t fchip;                /* what REG_38/39 read back once keyed      */
    uint16_t vIdle, vTx;           /* battery, 10 mV: on RX, then under the PA */
    uint16_t lo[NPTS_MAX], hi[NPTS_MAX];   /* the sine, as register values     */
    uint8_t  gn[NPTS_MAX];         /* the same sine as a 7-bit REG_70 gain     */
    uint16_t pLo, pHi, mLo, mHi;   /* f0 + DEV and f0 - DEV, for STEP          */
} g;

/* 127 x sin(2 pi i / 32), one full cycle; N = 16 or 8 takes every 2nd or 4th. */
static const int8_t SIN32[NPTS_MAX] = {
       0,   25,   49,   71,   90,  106,  117,  125,
     127,  125,  117,  106,   90,   71,   49,   25,
       0,  -25,  -49,  -71,  -90, -106, -117, -125,
    -127, -125, -117, -106,  -90,  -71,  -49,  -25
};

static const uint16_t MOD_HZ[] = { 100u, 150u, 200u, 300u, 400u, 600u, 1000u };
#define MOD_COUNT  (sizeof(MOD_HZ) / sizeof(MOD_HZ[0]))
#define MOD_DEF    3u              /* 300 Hz */

#define DEV_MIN    10u             /* 100 Hz  */
#define DEV_MAX    500u            /* 5 kHz   */
#define DEV_STEP   10u             /* 100 Hz  */
#define DEV_DEF    100u            /* 1 kHz   */

static const uint8_t DUR_S[] = { 1u, 2u, 3u, 5u };
#define DUR_COUNT  (sizeof(DUR_S) / sizeof(DUR_S[0]))
#define DUR_DEF    2u              /* 3 s */

/* Divisions through the resident helpers (API level 2), as the other apps do:
 * GCC leaves an undefined __aeabi_uidiv in the object for a division by a
 * constant on a core without UMULL, so defining them here keeps libgcc's out. */
uint64_t __aeabi_idivmod(int32_t n, int32_t d) { return g.A->idivmod(n, d); }
uint64_t __aeabi_idiv(int32_t n, int32_t d) __attribute__((alias("__aeabi_idivmod")));
uint64_t __aeabi_uidivmod(uint32_t n, uint32_t d) { return g.A->uidivmod(n, d); }
uint64_t __aeabi_uidiv(uint32_t n, uint32_t d) __attribute__((alias("__aeabi_uidivmod")));

/* ---- text ---- */
static char *putS(char *o, const char *s)
{
    while (*s)
        *o++ = *s++;
    return o;
}

/* "145.50000" from 10 Hz units: MHz, a point, then five digits (VFO Test's). */
static char *putF(char *o, uint32_t f)
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

static uint32_t divu(uint32_t n, uint32_t d)
{
    return (uint32_t)g.A->uidivmod(n, d);
}

/* ---- rate: N from the measured write cost, then the sample period ---- */
static void pickRate(void)
{
    uint32_t need = g.cyc + (g.cyc >> SAMP_MARGIN);
    g.npts = (uint8_t)NPTS_MAX;
    g.stride = 1u;                 /* NPTS_MAX / npts, kept by shifting: no division */
    for (;;) {
        g.cps = divu(48000000u, (uint32_t)g.npts * g.fmod);
        if (g.cps >= need || g.npts <= 8u)
            break;
        g.npts >>= 1;
        g.stride <<= 1;
    }
    g.slow = g.cps < need;         /* the loop then runs as fast as it can     */
}

/* One register write costs the same whatever the register: time 64 writes of
 * REG_71 with the tone generator off, which changes nothing on the air. */
static void measure(void)
{
    const app_api_t *A = g.A;
    uint32_t t0;
    A->bk_write(REG_70, 0);
    t0 = A->cycles_48mhz();
    for (uint8_t i = 0; i < 64u; i++)
        A->bk_write(REG_71, 0);
    g.cyc = (A->cycles_48mhz() - t0 + 32u) >> 6;
    pickRate();
}

/* ---- the sine, as register values ---- */
static void build(void)
{
    g.f0 = g.A->tx_freq();
    g.carry = false;
    for (uint8_t i = 0; i < g.npts; i++) {
        int32_t d = ((int32_t)g.dev * SIN32[i * g.stride]) >> 7;
        uint32_t f = (uint32_t)((int32_t)g.f0 + d);
        g.lo[i] = (uint16_t)f;
        g.hi[i] = (uint16_t)(f >> 16);
        if (g.hi[i] != g.hi[0])
            g.carry = true;        /* two writes per sample near a 655.36 kHz step */
        g.gn[i] = (uint8_t)(64 + ((SIN32[i * g.stride] * 62) >> 7));
    }
    g.pLo = (uint16_t)(g.f0 + g.dev);
    g.pHi = (uint16_t)((g.f0 + g.dev) >> 16);
    g.mLo = (uint16_t)(g.f0 - g.dev);
    g.mHi = (uint16_t)((g.f0 - g.dev) >> 16);
}

/* ---- display ----
 * UI_PrintStringSmall centres with an unsigned subtraction (ui/helper.c:96),
 * so a normal-font line of more than 18 characters wraps into the rows below
 * and scribbles over them - v0.4 lost the readback that way.  Only the title,
 * the frequency and the status, all short, use the normal font; everything
 * that grows with the settings is tiny (4 px, 32 characters).  The key help
 * lives in the status line, where the battery would be: y = 57 is past the
 * seven-row frame buffer and lands in that line anyway. */
static void draw(void)
{
    const app_api_t *A = g.A;
    static const char *const MODE[M_COUNT] = { "PLL", "TONE", "STEP", "STEP39",
                                               "STEP+T", "STEP+C", "CARR", "RAW",
                                               "GDC", "GAIN", "GTONE", "GPARK" };
    static const char *const STAT[] = { "MENU/PTT = TX", "TRANSMIT", "SENT",
                                        "TX DENIED ", "CHIP ON " };
    char s[40], *o;

    A->display_clear();
    A->status_clear();
    A->print_bold("PLL FM " APP_VERSION, 0, 127, 0);

    o = putF(s, A->tx_freq());
    o = putS(o, " TX");
    *o = 0;
    A->print_normal(s, 0, 127, 1);

    o = putS(s, MODE[g.mode]);
    if (g.mode == M_CARR) {              /* which stage of the key-up it sends */
        *o++ = ' ';
        *o++ = 'S';
        o = A->append_u32(o, g.stage);
    }
    *o++ = ' ';
    o = A->append_u32(o, DUR_S[g.dur]);
    o = putS(o, "S DEV ");
    o = A->append_u32(o, (uint32_t)g.dev * 10u);
    if (g.force)
        o = putS(o, " FRC");
    *o = 0;
    A->print_tiny(s, 0, 17, false, true);

    o = putS(s, "MOD ");
    o = A->append_u32(o, g.fmod);
    o = putS(o, " FS ");
    o = A->append_u32(o, (uint32_t)g.npts * g.fmod);
    o = putS(o, " N");
    o = A->append_u32(o, g.npts);
    if (g.slow)
        o = putS(o, " SLOW");            /* Fs not held: the note is lower    */
    *o = 0;
    A->print_tiny(s, 0, 25, false, true);

    o = putS(s, "WR ");
    o = A->append_u32(o, g.cyc);
    o = putS(o, "C  MAX ");
    o = A->append_u32(o, divu(48000000u, g.cyc ? g.cyc : 1u));
    o = putS(o, "HZ");
    if (g.carry)
        o = putS(o, " C2W");             /* a sample crosses the 16-bit half  */
    *o = 0;
    A->print_tiny(s, 0, 33, false, true);

    /* What REG_38/39 read back at the last key-up, and the two flags that
     * change how a burst must be read. */
    o = s;
    if (g.rbSeen) {
        o = putS(o, g.norb ? "NORB " : "RB ");
        o = putF(o, g.fchip);
    }
    if (g.vIdle) {                       /* RX volts > volts under the PA     */
        o = putS(o, " V");
        o = A->append_u32(o, g.vIdle);
        *o++ = '>';
        o = A->append_u32(o, g.vTx);
    }
    *o = 0;
    A->print_tiny(s, 0, 41, false, true);

    o = putS(s, STAT[g.status]);
    if (g.status == S_DENIED)
        o = A->append_u32(o, g.denial);
    else if (g.status == S_MISMATCH)
        o = putF(o, g.fchip);
    *o = 0;
    A->print_normal(s, 0, 127, 6);

    A->print_tiny("1DEV 2MOD 3DUR 4MES 7STG *MODE", 0, 1, true, true);
    A->blit_status();
    A->blit_full();
}

/* ---- the three TX loops ---- */
/* REG_38 at Fs, REG_39 only when the high half moves. */
static void runPll(void)
{
    const app_api_t *A = g.A;
    uint32_t left = (uint32_t)g.npts * g.fmod * DUR_S[g.dur];
    uint32_t next;
    uint16_t hPrev = g.hi[0];
    uint8_t  i = 0;

    A->bk_write(REG_39, hPrev);
    next = A->cycles_48mhz() + g.cps;
    while (left--) {
        while (app_cycles_before(A->cycles_48mhz(), next)) { }
        next += g.cps;
        if (g.hi[i] != hPrev) {
            hPrev = g.hi[i];
            A->bk_write(REG_39, hPrev);
        }
        A->bk_write(REG_38, g.lo[i]);
        if (++i >= g.npts)
            i = 0;
    }
}

/* +DEV / -DEV at 2 Hz, in four write orders.  kind 0 is PLL's own sequence,
 * so a flat STEP and an audible STEP39 mean the chip latches the frequency on
 * REG_39 and PLL must write both registers at every sample; kind 1 is the
 * driver's order (REG_38 then REG_39, BK4819_SetFrequency); kind 2 adds the
 * REG_30 off-on toggle of spectrum.c SetF and CW Keyer; kind 3 flips only the
 * VCO calibration bit <15> instead, which leaves the PLL and the PA powered -
 * untried anywhere in the tree, so low power only. */
static void runStep(uint8_t kind)
{
    const app_api_t *A = g.A;
    uint8_t halves = (uint8_t)(DUR_S[g.dur] * 4u);   /* 2 Hz: 250 ms a half */
    uint16_t hPrev = (uint16_t)(g.f0 >> 16);
    for (uint8_t k = 0; k < halves; k++) {
        uint16_t lo = (k & 1u) ? g.mLo : g.pLo;
        uint16_t hi = (k & 1u) ? g.mHi : g.pHi;
        if (kind == 0u) {                /* as runPll: REG_39 only when it moves */
            if (hi != hPrev) {
                hPrev = hi;
                A->bk_write(REG_39, hi);
            }
            A->bk_write(REG_38, lo);
        } else {
            A->bk_write(REG_38, lo);
            A->bk_write(REG_39, hi);
            if (kind == 2u) {
                A->bk_write(REG_30, TX_LINK_OFF);
                A->bk_write(REG_30, TX_LINK_NO_MIC);
            } else if (kind == 3u) {
                A->bk_write(REG_30, TX_LINK_NO_VCO);
                A->bk_write(REG_30, TX_LINK_NO_MIC);
            }
        }
        A->delay_ms(250u);
    }
}

/* The reference: the tone generator at Fmod, at TransmitTone's own gain. */
static void runTone(void)
{
    uint32_t f = ((uint32_t)g.fmod * 1353245u + (1u << 16)) >> 17;   /* scale_freq */
    g.A->bk_write(REG_71, (uint16_t)f);
    g.A->bk_write(REG_70, (uint16_t)(0x8000u | (TONE_LVL << 8)));
    g.A->delay_ms((uint32_t)DUR_S[g.dur] * 1000u);
}

/* The resident key-up and nothing else.  FUNCTION_Transmit's whole RF part is
 * RADIO_SetTxParameters (functions.c:167) - no mute, no REG_30 restart, no
 * frequency write, no PA gating - so this mode is the baseline: if it is not
 * on the air, no app can key this radio and nothing else here means anything. */
/* The battery voltage, in 10 mV units, with the four-deep average flushed:
 * the only carrier detector the radio has on its own.  A keyed PA pulls
 * several hundred milliamps where RX pulls a few tens, so the pack sags by a
 * few units - the burst that does not sag did not transmit.  Judge it against
 * RAW or CARR S1, which are known to carry, not against an absolute figure. */
static uint16_t vsample(void)
{
    const app_api_t *A = g.A;
    for (uint8_t i = 0; i < 5u; i++)
        A->battery_sample();
    return *A->sys_battery_voltage;
}

static void runRaw(void)
{
    const app_api_t *A = g.A;
    A->tx_set_params();
    A->delay_ms((uint32_t)DUR_S[g.dur] * 1000u);
    g.vTx = vsample();                   /* still keyed: the sag, if any      */
    A->tx_end();
}

/* ---- REG_70 as a modulator input ----
 * aprstx rewrites REG_71 and REG_70 at every NRZI transition, every 833 us,
 * and never touches REG_30 (aprstx_app.c:290), so the tone registers do take
 * effect in flight - which is exactly what REG_38 does not.  Two questions
 * follow, and the SDR answers both:
 *   GDC    the gain stepped between G_MIN and G_MAX at 2 Hz with REG_71 = 0,
 *          the DDS stopped.  A square wave on the carrier means a stopped DDS
 *          holds a DC value and the gain scales it - a 7-bit baseband DAC.
 *          Nothing means the phase stopped at a zero crossing, or that a zero
 *          frequency silences the generator.
 *   GTONE  the same step with REG_71 at Fmod: the control.  It must show the
 *          tone's deviation switching between two levels, which proves a gain
 *          write is live and instantaneous whatever GDC says.
 *   GAIN   the real thing: the sine written into the gain field at Fs with the
 *          DDS stopped, one write per sample, no REG_30 - speech-rate audio
 *          straight into the modulator, if GDC works. */
static void runGstep(uint16_t f71)
{
    const app_api_t *A = g.A;
    uint8_t halves = (uint8_t)(DUR_S[g.dur] * 4u);
    A->bk_write(REG_71, f71);
    for (uint8_t k = 0; k < halves; k++) {
        A->bk_write(REG_70,
                    (uint16_t)(0x8000u | (((k & 1u) ? G_MIN : G_MAX) << 8)));
        A->delay_ms(250u);
    }
}

/* GDC found no DC with REG_71 written to 0 before the generator was enabled -
 * but the accumulator was already at zero then, so that says nothing about
 * whether a zero frequency word freezes the phase or clears it.  Park it
 * instead: run the tone at 32 Hz, wait a quarter period so the sine is at its
 * peak, then write 0.  A DDS that freezes now holds its maximum, and the gain
 * steps become a large frequency square wave; a DDS that clears stays silent
 * like GDC.  That is the whole of the baseband-DAC question. */
static void runGpark(void)
{
    const app_api_t *A = g.A;
    uint8_t halves = (uint8_t)(DUR_S[g.dur] * 4u);
    A->bk_write(REG_71, F_PARK);
    A->bk_write(REG_70, (uint16_t)(0x8000u | (G_MAX << 8)));
    A->delay_ms(8u);                     /* a quarter of 31.25 ms             */
    A->bk_write(REG_71, 0);              /* freeze, in principle at the peak  */
    for (uint8_t k = 0; k < halves; k++) {
        A->bk_write(REG_70,
                    (uint16_t)(0x8000u | (((k & 1u) ? G_MIN : G_MAX) << 8)));
        A->delay_ms(250u);
    }
}

static void runGain(void)
{
    const app_api_t *A = g.A;
    uint32_t left = (uint32_t)g.npts * g.fmod * DUR_S[g.dur];
    uint32_t next;
    uint8_t  i = 0;

    A->bk_write(REG_71, F_PARK);         /* park the phase at the peak first, */
    A->bk_write(REG_70, (uint16_t)(0x8000u | (G_MAX << 8)));
    A->delay_ms(8u);                     /* as GPARK: without this the DDS    */
    A->bk_write(REG_71, 0);              /* holds zero and nothing comes out  */
    next = A->cycles_48mhz() + g.cps;
    while (left--) {
        while (app_cycles_before(A->cycles_48mhz(), next)) { }
        next += g.cps;
        A->bk_write(REG_70, (uint16_t)(0x8000u | ((uint32_t)g.gn[i] << 8)));
        if (++i >= g.npts)
            i = 0;
    }
}

/* PA off, tone off, back on the nominal frequency, RX restored. */
static void stopTx(void)
{
    const app_api_t *A = g.A;
    A->bk_write(REG_70, 0);
    A->tx_mute(true);
    A->tx_carrier(false);
    A->bk_write(REG_39, (uint16_t)(g.f0 >> 16));     /* back on frequency, PA off */
    A->bk_write(REG_38, (uint16_t)g.f0);
    A->tx_end();                         /* PA off + RADIO_SetupRegisters     */
}

/* Key up in cumulative stages, so that one session finds the step that kills
 * the carrier.  Stage 1 is the resident key-up and nothing else, which is
 * confirmed on the air; stage 6 is what the modulating modes need (our own
 * frequency in REG_38/39, latched by the TX-link restart).  CARR sends the
 * stage on the screen, every other mode stage 6.
 *   0  tx_set_params, then the PA straight back down: the control.  The
 *      battery meter is only worth anything if this one does not sag.
 *   1  tx_set_params: RADIO_SetTxParameters, all FUNCTION_Transmit does
 *   2  the PA dropped while the rest is set up, then keyed again
 *   3  the modulation path muted (REG_50; Beacon holds a carrier like this)
 *   4  no sub-audio, no tone (REG_51, REG_70)
 *   5  our own TX frequency written into REG_38/39
 *   6  REG_30 off then back on, to latch it, plus the PLL settling delay
 * false means the burst was refused and the radio is back on RX. */
static bool keyUp(uint8_t stage)
{
    const app_api_t *A = g.A;

    A->tx_set_params();                  /* 1: PA on, mic live ~50 ms         */
    if (stage == 0u)
        A->tx_carrier(false);            /* 0: the control, the PA straight down */
    if (stage >= 2u)
        A->tx_carrier(false);            /* 2: PA off while we set up         */
    if (stage >= 3u)
        A->tx_mute(true);                /* 3                                 */
    if (stage >= 4u) {
        /* After tx_set_params, not before: RADIO_SetTxParametersEx ends by
         * programming the TX sub-audio of the VFO (radio.c:1104). */
        A->bk_write(REG_51, 0);          /* 4                                 */
        A->bk_write(REG_70, 0);
    }

    /* What tx_set_params tuned, read before stage 5 overwrites it.  The
     * frequency we set ourselves, but the TX filter path and the PA
     * calibration come from gCurrentVfo, the RX VFO under dual watch
     * (radio.c:772): a reading that is a real frequency more than F_BAND_TOL
     * away means another band, so another LPF - refuse rather than send
     * harmonics (key 5 forces).  A reading that is no frequency at all only
     * means REG_38/39 do not read back: NORB, and the burst goes out. */
    g.fchip = ((uint32_t)A->bk_read(REG_39) << 16) | A->bk_read(REG_38);
    g.norb = g.fchip < F_PLAUS_MIN || g.fchip > F_PLAUS_MAX;
    g.rbSeen = true;
    if (!g.norb && !g.force) {
        uint32_t diff = g.fchip > g.f0 ? g.fchip - g.f0 : g.f0 - g.fchip;
        if (diff > F_BAND_TOL) {
            stopTx();
            g.status = S_MISMATCH;
            return false;
        }
    }

    if (stage >= 5u) {
        A->bk_write(REG_38, (uint16_t)g.f0);          /* 5                    */
        A->bk_write(REG_39, (uint16_t)(g.f0 >> 16));
    }
    if (stage >= 6u) {
        A->bk_write(REG_30, TX_LINK_OFF);             /* 6                    */
        A->bk_write(REG_30, TX_LINK_NO_MIC);
        A->delay_ms(PLL_LOCK_MS);
    }
    if (stage >= 2u)
        A->tx_carrier(true);             /* the PA back on, as Beacon's keyOn */
    if (g.mode == M_TONE || g.mode >= M_GDC)
        A->tx_mute(false);               /* the DSP path, for the generators  */
    return true;
}

/* ---- one burst on the air ---- */
static void transmit(void)
{
    const app_api_t *A = g.A;
    uint8_t st = A->tx_state();
    if (st) {
        g.status = S_DENIED;
        g.denial = st;
        return;
    }
    build();
    g.status = S_TX;
    g.vTx = 0;
    draw();                              /* the screen shows TX before keying */
    g.vIdle = vsample();                 /* the pack on RX, before the PA     */

    if (g.mode == M_RAW) {               /* nothing but the resident key-up   */
        runRaw();
        g.status = S_DONE;
        return;
    }

    if (!keyUp(g.mode == M_CARR ? g.stage : STAGE_MAX))
        return;                          /* refused: stopTx already called    */

    switch (g.mode) {
    case M_PLL:    runPll();       break;
    case M_TONE:   runTone();      break;
    case M_STEP:   runStep(0u);    break;
    case M_STEP39: runStep(1u);    break;
    case M_STEPT:  runStep(2u);    break;
    case M_STEPC:  runStep(3u);    break;
    case M_GDC:    runGstep(0u);   break;
    case M_GTONE:  runGstep((uint16_t)(((uint32_t)g.fmod * 1353245u
                                        + (1u << 16)) >> 17)); break;
    case M_GAIN:   runGain();      break;
    case M_GPARK:  runGpark();     break;
    case M_RAW:    break;                /* handled above */
    default:       A->delay_ms((uint32_t)DUR_S[g.dur] * 1000u); break;
    }

    g.vTx = vsample();                   /* still keyed: the sag, if any      */
    stopTx();
    g.status = S_DONE;
}

/* ---- keys ---- */
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
    if (k == APP_KEY_F) {
        g.fArm = !g.fArm;
        draw();
        return;
    }
    bool back = g.fArm;                  /* F then a key: downwards, as APRS TX */
    g.fArm = false;

    switch (k) {
    case APP_KEY_EXIT:
        g.running = false;
        return;
    case APP_KEY_MENU:
    case APP_KEY_PTT:
        transmit();
        break;
    case APP_KEY_STAR:
        g.mode = (uint8_t)(g.mode + 1u >= M_COUNT ? 0u : g.mode + 1u);
        g.status = S_READY;
        break;
    case APP_KEY_1:
        if (back)
            g.dev = (uint16_t)(g.dev > DEV_MIN ? g.dev - DEV_STEP : DEV_MIN);
        else
            g.dev = (uint16_t)(g.dev + DEV_STEP > DEV_MAX ? DEV_MAX : g.dev + DEV_STEP);
        break;
    case APP_KEY_2:
        g.iMod = (uint8_t)(back ? (g.iMod ? g.iMod - 1u : MOD_COUNT - 1u)
                                : (g.iMod + 1u) % MOD_COUNT);
        g.fmod = MOD_HZ[g.iMod];
        pickRate();
        break;
    case APP_KEY_3:
        g.dur = (uint8_t)(back ? (g.dur ? g.dur - 1u : DUR_COUNT - 1u)
                               : (g.dur + 1u) % DUR_COUNT);
        break;
    case APP_KEY_4:
        measure();
        break;
    case APP_KEY_5:
        g.force = !g.force;              /* ignore the frequency readback check */
        break;
    case APP_KEY_7:                      /* CARR: how far the key-up goes     */
        if (back)
            g.stage = (uint8_t)(g.stage > 0u ? g.stage - 1u : STAGE_MAX);
        else
            g.stage = (uint8_t)(g.stage < STAGE_MAX ? g.stage + 1u : 0u);
        break;
    default:
        break;
    }
    build();                             /* DEV, MOD and N show their own CARRY */
    draw();
}

__attribute__((section(".text.entry"), used))
void app_main(const app_api_t *api)
{
    g.A = api;
    g.mode = M_PLL;
    g.dev = DEV_DEF;
    g.iMod = MOD_DEF;
    g.fmod = MOD_HZ[MOD_DEF];
    g.dur = DUR_DEF;
    g.running = true;
    g.stage = STAGE_MAX;

    measure();                           /* also picks N for the default Fmod */
    build();
    draw();
    while (g.running) {
        keys();
        api->battery_sample();
        api->backlight_update();
        api->delay_ms(20u);
    }
}

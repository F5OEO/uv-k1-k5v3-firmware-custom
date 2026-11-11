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
 * LaCrosse TX141 / TX141TH OOK decoder, three stages per sample:
 *
 * 1. Slicer. The PA4 tap is AC-coupled around 1 kHz, so a 417 us plateau has
 *    mostly drooped away by its end and the pulses arrive as edges (doc/doc.md
 *    9.4). A level threshold would therefore clip the long pulses short; a
 *    Schmitt trigger on the DC-removed signal does not, because the droop
 *    decays towards zero and only the real falling edge drives the signal
 *    through -h. The hysteresis follows the envelope, as sigfind's sweep.c
 *    does, so the trigger works at any level.
 *
 * 2. Cells. Each rising edge closes one high + low pair, which is exactly one
 *    PWM symbol. The decision is the pulse's share of its own cell rather than
 *    an absolute width, so a sample clock 1 % off or an AF chain that moves
 *    both edges changes nothing: 417 us high is a 1, 208 us high is a 0. Each
 *    falling edge closes the complementary pair for the other polarity, since
 *    the sign of the envelope at PA4 is not established anywhere.
 *
 * 3. Frame. The bits shift through a 40-bit register whose digest is checked
 *    at every bit, so a frame is read with or without its preamble (the AGC
 *    is frozen but the squelch and the receiver still need the first pulses).
 *    Any out-of-spec cell clears the register. A frame has to pass the digest,
 *    the field ranges and then arrive a second time before it is believed:
 *    the sensor sends twelve copies per burst, so that costs nothing.
 */

#include "dectx141.h"

bool tx141_fields(const uint8_t *b, tx141_rec_t *r)
{
    int16_t t10 = (int16_t)((int16_t)(((uint16_t)(b[1] & 0x0Fu) << 8) | b[2]) - 500);
    if (b[0] == 0u || b[3] == 0u || b[3] > 100u || t10 < -400 || t10 > 600)
        return false;
    r->id   = b[0];
    r->batt = (uint8_t)(b[1] >> 7);
    r->test = (uint8_t)((b[1] >> 6) & 1u);
    r->ch   = (uint8_t)((b[1] >> 4) & 3u);
    r->t10  = t10;
    r->hum  = b[3];
    return true;
}

static bool same5(const uint8_t *a, const uint8_t *b)
{
    for (uint8_t k = 0; k < 5u; k++) if (a[k] != b[k]) return false;
    return true;
}

/* One complete cell of one polarity: its bit, or a register cleared. A
 * preamble pulse, a glitch and the gap after the last bit all land in the
 * same branch - the digest is checked at every bit, so nothing has to
 * recognise the preamble. */
static bool cell(tx141_t *d, tx141_arm_t *a, uint16_t on, uint16_t off)
{
    uint16_t per = (uint16_t)(on + off);

    if (a->havePend && ++a->pendAge > TX_PEND_CELLS) a->havePend = false;

    if (on < TX_RUN_MIN || off < TX_RUN_MIN ||
        per < TX_CELL_MIN || per > TX_CELL_MAX) {
        a->cells = 0;
        return false;
    }
    d->nCell++;
    a->sr[0] = (uint8_t)((a->sr[0] << 1) | (a->sr[1] >> 7));
    a->sr[1] = (uint8_t)((a->sr[1] << 1) | (a->sr[2] >> 7));
    a->sr[2] = (uint8_t)((a->sr[2] << 1) | (a->sr[3] >> 7));
    a->sr[3] = (uint8_t)((a->sr[3] << 1) | (a->sr[4] >> 7));
    a->sr[4] = (uint8_t)((a->sr[4] << 1) | ((uint16_t)(on * 2u) > per ? 1u : 0u));
    if (a->cells < TX_BITS) a->cells++;
    if (a->cells < TX_BITS) return false;

    tx141_rec_t r;
    if (tx141_digest(a->sr) != a->sr[4] || !tx141_fields(a->sr, &r)) return false;
    d->good++;
    if (a->havePend && same5(a->pend, a->sr)) {
        for (uint8_t k = 0; k < 5u; k++) d->frame[k] = a->sr[k];
        a->pendAge = 0;
        return true;
    }
    for (uint8_t k = 0; k < 5u; k++) a->pend[k] = a->sr[k];
    a->havePend = true;
    a->pendAge  = 0;
    return false;
}

bool tx141_push(tx141_t *d, uint16_t adc)
{
    /* Four samples averaged: 104 us, an eighth of the shortest pulse, for
     * 6 dB on the ADC and receiver noise. */
    d->sum = (uint16_t)(d->sum + adc - d->ring[d->rp]);
    d->ring[d->rp] = adc;
    d->rp = (uint8_t)((d->rp + 1u) & 3u);
    adc = (uint16_t)(d->sum >> 2);

    d->dcQ += (((int32_t)adc << 8) - d->dcQ) >> 8;        /* corner ~24 Hz */
    int32_t y = (int32_t)adc - (d->dcQ >> 8);
    uint32_t a = (uint32_t)(y < 0 ? -y : y) << 8;
    if (a > d->envQ) d->envQ = a; else d->envQ -= d->envQ >> 8;   /* ~6.7 ms */
    int32_t h = (int32_t)(d->envQ >> 10);                  /* env / 4 */
    if (h < TX_HYST_MIN) h = TX_HYST_MIN;

    if (d->st) {
        if (y >= -h) { if (d->hi < TX_RUN_CAP) d->hi++; return false; }
        d->st = 0;
        d->edges++;
        /* the inverted polarity's cell: the low run was its pulse */
        bool got = cell(d, &d->arm[1], d->lo, d->hi);
        d->lo = 1;
        return got;
    }
    if (y <= h) {
        if (d->lo < TX_RUN_CAP) d->lo++;
        /* The last bit of a burst has no edge behind it: once the gap is
         * longer than any cell, close that bit on its pulse width alone (one
         * cell's worth of gap, so the same ratio decides it), then let the
         * caller have the CPU back. Exactly once per gap. */
        if (d->lo == TX_TAIL) {
            bool got = d->hi >= TX_RUN_MIN && d->hi + TX_RUN_MIN <= TX_CELL_NOM &&
                       cell(d, &d->arm[0], d->hi, (uint16_t)(TX_CELL_NOM - d->hi));
            d->arm[0].cells = 0;
            d->arm[1].cells = 0;
            return got;
        }
        return false;
    }
    d->st = 1;
    d->edges++;
    bool got = cell(d, &d->arm[0], d->hi, d->lo);
    d->hi = 1;
    return got;
}

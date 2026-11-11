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
 * LaCrosse TX141 family OOK receiver: the AM envelope on PA4 to five bytes.
 * Included by lacrosserx_app.c and by the host test, so it uses no API call,
 * no division and no library.
 */

#ifndef DECTX141_H
#define DECTX141_H

#include <stdbool.h>
#include <stdint.h>

/* Sample rate of the PA4 capture the decoder expects (doc/doc.md 9.5: 26 us
 * per sample leaves +-26 us of margin on the 208 / 417 us discriminant). */
#define TX_FS         38400u
#define TX_SAMPLE_CYC (48000000u / TX_FS)

/* Run lengths in samples: 208 us = 8, 417 us = 16, one 625 us cell = 24,
 * one 1666 us preamble cell = 64. The windows are wide: the AF chain shifts
 * both edges of a pulse and the MCU's RC clock is good to about 1 %. */
#define TX_CELL_MIN   17u
#define TX_CELL_MAX   32u
#define TX_SYNC_MIN   44u
#define TX_SYNC_MAX   84u
#define TX_RUN_MIN     3u    /* 78 us: shorter is a glitch, not an edge      */
#define TX_CELL_NOM   24u    /* 625 us: the cell the tail flush assumes      */
#define TX_TAIL       64u    /* 1.7 ms of silence closes the last bit        */
#define TX_RUN_CAP  4000u    /* run counters stop here (silence)             */

#define TX_HYST_MIN    6     /* hysteresis floor, ADC LSB (ADC noise)        */
#define TX_PEND_CELLS 4096u  /* cells a packet waits for its twin (~2.5 s)   */
#define TX_BITS       40u    /* TX141TH-Bv2 frame; Bv3 sends one bit more    */

/* One polarity. Nothing in the repo establishes the sign of the AM envelope
 * at PA4 - acarsrx deliberately synchronises in either polarity and sigfind
 * only counts transitions - and a sensor that speaks every 50 s is a poor
 * place to find out. So both pairings run: one closes its cell on the rising
 * edge, pulse then gap, the other on the falling edge, which is the same
 * stream seen upside down. Only one of them ever decodes anything. */
typedef struct {
    uint8_t  sr[5];          /* the last 40 bits, first bit in sr[0] bit 7   */
    uint8_t  pend[5];        /* a frame waiting to be seen a second time     */
    uint16_t cells;          /* consecutive valid data cells (bits in sr)    */
    uint16_t pendAge;        /* cells since pend was stored                  */
    bool     havePend;
} tx141_arm_t;

typedef struct {
    int32_t  dcQ;            /* DC level, Q8                                 */
    uint32_t envQ;           /* amplitude envelope, Q8                       */
    uint16_t hi, lo;         /* run length of the current / previous level   */
    uint16_t edges;          /* transitions, diagnostics                     */
    uint16_t nCell, good;    /* valid data cells, frames accepted            */
    uint16_t ring[4], sum;   /* the 104 us boxcar ahead of the slicer         */
    uint8_t  rp;
    uint8_t  st;             /* Schmitt state: 1 = the envelope is up        */
    uint8_t  frame[5];       /* the last confirmed frame                     */
    tx141_arm_t arm[2];      /* 0: pulse then gap · 1: the other polarity    */
} tx141_t;

/* One decoded reading. t10 is tenths of a degree Celsius, -400 to +600. */
typedef struct {
    uint8_t id, hum, ch, batt, test;
    int16_t t10;
} tx141_rec_t;

/* The check byte is not a CRC but a keyed LFSR digest over the first four
 * bytes: the key starts at 0xF4 and rolls left through the generator 0x31,
 * the message read from its last byte and each byte from its least
 * significant bit, the key XORed into the sum wherever a data bit is set.
 * rtl_433 names it lfsr_digest8_reflect(b, 4, 0x31, 0xf4). */
static inline uint8_t tx141_digest(const uint8_t *b)
{
    uint8_t sum = 0, key = 0xF4u;
    for (uint8_t k = 4u; k-- > 0u; ) {
        uint8_t d = b[k];
        for (uint8_t i = 0; i < 8u; i++) {
            if ((d >> i) & 1u) sum = (uint8_t)(sum ^ key);
            key = (uint8_t)((uint8_t)(key << 1) ^ (uint8_t)((key & 0x80u) ? 0x31u : 0u));
        }
    }
    return sum;
}

/* Split a frame that passed the digest. False when a field is out of range:
 * an 8-bit digest alone lets one window of noise in 256 through. */
bool tx141_fields(const uint8_t *b, tx141_rec_t *r);

/* Bits still waiting to make up a frame, either polarity: the caller may not
 * interrupt the sampling while this is true. */
static inline uint16_t tx141_busy(const tx141_t *d)
{ return (uint16_t)(d->arm[0].cells + d->arm[1].cells); }

/* One ADC sample of the AM envelope. True when a frame has been received
 * twice and waits in d->frame. */
bool tx141_push(tx141_t *d, uint16_t adc);

#endif /* DECTX141_H */

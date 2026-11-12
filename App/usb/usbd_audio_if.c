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
 * USB Audio Class 1.0 capture: the radio appears as a microphone, so any
 * program on the host records or listens to the received audio with no tool
 * of ours in the path. It is added NEXT TO the CDC serial port, not instead
 * of it - appload.py, UV Studio, K5Viewer and every afbridge mode need that
 * port - so the device is a composite: CDC on interfaces 0 and 1, audio on
 * 2 and 3, with the IAD the descriptor already declares.
 *
 * Why a class driver beats our own protocol over CDC. The stream becomes
 * device-clocked by construction: an asynchronous isochronous source hands
 * the host 7, 8 or 9 samples per frame as its own clock dictates, and the
 * host's audio stack resamples. All of tools/afstream.py's clock work - the
 * 1.0068 factor, the measured-rate sink, the silence padding - exists only
 * because a raw CDC stream has no way to say "this is my clock". Here that is
 * the protocol's job.
 *
 * The capture is TIM3 -> ADC -> DMA1 channel 1, circular, as the overlay apps
 * validated it - with one difference the resident firmware forces. An app can
 * simply never call battery_sample(); the firmware cannot, because
 * low-battery handling depends on the reading, and BOARD_ADC_GetBatteryInfo
 * retargets the ADC every 500 ms, which would punch a hole in the audio twice
 * a second. So the ADC runs a TWO-RANK scan per trigger - PA4 then the
 * battery channel - into one interleaved ring, and while the stream is up the
 * battery value is served from the odd samples instead of from a conversion
 * of its own. The ADC is then never retargeted at all.
 *
 * The 1 ms frame is the whole budget: at 8 kHz one frame is 8 samples, 16
 * bytes. The endpoint is declared for 9 (18 bytes) because the asynchronous
 * rule needs a ceiling: the frame carries 7, 8 or 9 samples depending on how
 * full the ring is, which is what makes the source genuinely device-clocked
 * rather than merely declared so. Sending a fixed 8 while the ADC runs at
 * about 7970 Hz would slip a 64-sample ring about every 4 seconds.
 *
 * AUDIO_TEST_SINE replaces the capture with the synthetic 250 Hz tone that
 * brought the descriptors up: one line back to a signal that cannot be the
 * ADC's fault.
 */

#include "usbd_core.h"
#include "usbd_audio.h"
#include "usbd_audio_if.h"
#include "driver/bk4819.h"
#include "driver/keyboard.h"
#include "driver/system.h"
#include "frequencies.h"
#include "helper/battery.h"
#include "misc.h"
#include "radio.h"
#include "scheduler.h"

#define AUDIO_IN_EP     0x84        /* CDC holds 0x81, 0x02 and 0x83 */
#define AUDIO_OUT_EP    0x05        /* playback: the host feeds the radio  */
#define AUDIO_AS_IN_INTF   0x03
#define AUDIO_AS_OUT_INTF  0x04
#define AUDIO_FREQ      8000u
#define AUDIO_FRAME     (AUDIO_FREQ / 1000u)        /* 8 samples a frame   */
#define AUDIO_MPS       ((AUDIO_FRAME + 1u) * 2u)   /* 9 samples: 18 bytes */

#define AUDIO_TEST_SINE  0          /* 1: the bring-up tone, no ADC at all */

/* ---- PY32F071 registers, as App/apps/afbridge does it: the overlay apps
 * carry the canonical copy of this sequence. ---- */
#define REG32(a)        (*(volatile uint32_t *)(a))
#define RCC_IOPENR      REG32(0x40021034u)
#define RCC_AHBENR      REG32(0x40021038u)
#define RCC_APBENR1     REG32(0x4002103Cu)
#define RCC_APBENR2     REG32(0x40021040u)
#define SYSCFG_CFGR3    REG32(0x40010008u)
#define GPIOA_MODER     REG32(0x50000000u)
#define DAC_CR          REG32(0x40007400u)
#define DAC_SWTRIGR     REG32(0x40007404u)
#define DAC_DHR12R1     REG32(0x40007408u)
#define ADC_CR1         REG32(0x40012404u)
#define ADC_CR2         REG32(0x40012408u)
#define ADC_SMPR3       REG32(0x40012414u)
#define ADC_SQR1        REG32(0x40012430u)
#define ADC_SQR3        REG32(0x40012438u)
#define ADC_DR_ADDR     0x40012450u
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
#define DACEN           (1u << 29)      /* RCC_APBENR1 */
#define SYSCFGEN        (1u << 0)
#define ADC_SCAN        (1u << 8)       /* CR1 */
#define ADC_DMA_EN      (1u << 8)       /* CR2 */
#define ADC_CONT        (1u << 1)
#define ADC_EXTSEL      (7u << 17)
#define ADC_TRIG_TIM3   (4u << 17)
#define ADC_EXTTRIG     (1u << 20)
#define CCR_STREAM      ((1u << 7) | (1u << 5) | (1u << 8) | (1u << 10) | (2u << 12))
#define CCR_EN          (1u << 0)
#define TIM_MMS_UPDATE  (2u << 4)
#define TIM_CEN         (1u << 0)
#define TIM_UG          (1u << 0)
#define DAC_BIAS        ((1u << 0) | (1u << 1) | (1u << 2) | (7u << 3))
#define BIAS_CODE       2048u
#define ADC_CH_PA4      4u
#define ADC_CH_BATT     8u
#define SMP4_POS        12u
#define SMP8_POS        24u

#define AUDIO_RING      64u         /* pairs: 8 ms at 8 kHz, 256 B of .bss  */
#define AUDIO_TARGET    24u         /* pairs the ring aims to hold          */
#define TIM_ARR         ((48000000u / AUDIO_FREQ) - 1u)

/* volatile: the DMA fills this behind the compiler's back, and the frame
 * builder reads it from the USB interrupt. */
static volatile uint16_t audio_ring[2u * AUDIO_RING];  /* PA4, battery, ... */
static uint16_t audio_rd;                      /* read cursor, in pairs        */
static uint16_t audio_batt = BIAS_CODE;        /* latest battery sample        */
static uint32_t audio_sqr1, audio_sqr3, audio_cr1, audio_cr2, audio_smpr3;
static uint32_t audio_moder, audio_dac, audio_dhr, audio_rcc1;
static uint8_t  audio_buf[AUDIO_MPS];
static uint16_t audio_phase;
static bool     audio_on;
static bool     audio_suspended;
static bool     audio_capturing;

/* ---- playback: what the host sends for the transmitter ----
 * Raw PCM here, not the CDC path's 3-bit ADPCM: an isochronous OUT endpoint
 * carries 16 kB/s without noticing, so the host needs no encoder and the
 * samples arrive unmangled. The ring only fills for now; the modal transmit
 * loop that drains it is the next step, and it will only ever run on an
 * explicit serial command. */
#define PLAY_RING       256u        /* samples: 32 ms, 512 B of .bss        */
/* volatile for the same reason, and because without it GCC simply deleted
 * the array: nothing reads it until the transmit loop exists, and a
 * write-only static is dead store. */
static volatile int16_t play_ring[PLAY_RING];
static uint16_t play_wr, play_rd;
static uint32_t play_total;         /* samples delivered since boot         */
static uint16_t play_lost;          /* samples dropped: nothing drains yet  */
static uint8_t  play_buf[AUDIO_MPS];
static bool     play_on;

#if AUDIO_TEST_SINE
/* A 32-point sine at 8 kHz is 250 Hz, loud enough to see on any host meter
 * and cheap enough to live in flash: the signal the descriptors came up on. */
static const int16_t AUDIO_SINE[32] = {
         0,   6392,  12539,  18204,  23170,  27245,  30273,  32137,
     32767,  32137,  30273,  27245,  23170,  18204,  12539,   6392,
         0,  -6392, -12539, -18204, -23170, -27245, -30273, -32137,
    -32767, -32137, -30273, -27245, -23170, -18204, -12539,  -6392
};
#endif

/* The capture, started only while a host has alt setting 1 selected. */
static void capture_start(void)
{
    if (audio_capturing)
        return;
    audio_moder = GPIOA_MODER;
    audio_rcc1  = RCC_APBENR1;
    audio_dac   = DAC_CR;
    audio_dhr   = DAC_DHR12R1;
    audio_cr1   = ADC_CR1;
    audio_cr2   = ADC_CR2;
    audio_sqr1  = ADC_SQR1;
    audio_sqr3  = ADC_SQR3;
    audio_smpr3 = ADC_SMPR3;

    /* PA4 analog with the MCU DAC holding it at mid-scale: the AF tap is
     * AC-coupled, so it needs a bias of its own (doc/doc.md 2.3). */
    RCC_APBENR2 |= SYSCFGEN;
    RCC_AHBENR  |= DMAEN;
    RCC_APBENR1 |= TIM3EN | DACEN;
    GPIOA_MODER  = audio_moder | (3u << 8);
    DAC_CR       = DAC_BIAS;
    DAC_DHR12R1  = BIAS_CODE;
    DAC_SWTRIGR  = 1u;

    /* Two ranks a trigger: PA4 then the battery, both at the battery's own
     * sample time, so one ring carries the audio and keeps the battery
     * reading alive without ever retargeting the ADC. */
    ADC_SMPR3 = (audio_smpr3 & ~(7u << SMP4_POS)) |
                (((audio_smpr3 >> SMP8_POS) & 7u) << SMP4_POS);
    ADC_SQR3  = (audio_sqr3 & ~0x3FFu) | ADC_CH_PA4 | (ADC_CH_BATT << 5);
    ADC_SQR1  = (audio_sqr1 & ~(0xFu << 20)) | (1u << 20);   /* L = 2 - 1 */
    ADC_CR1   = audio_cr1 | ADC_SCAN;

    DMA1_C1_CCR   = 0;
    SYSCFG_CFGR3  = SYSCFG_CFGR3 & ~0x3Fu;       /* channel 1 <- ADC1 */
    DMA1_C1_CPAR  = ADC_DR_ADDR;
    DMA1_C1_CMAR  = (uint32_t)audio_ring;
    DMA1_C1_CNDTR = 2u * AUDIO_RING;
    DMA_IFCR      = 0x7u;
    DMA1_C1_CCR   = CCR_STREAM | CCR_EN;

    ADC_CR2 = (audio_cr2 & ~(ADC_EXTSEL | ADC_CONT)) | ADC_TRIG_TIM3 |
              ADC_EXTTRIG | ADC_DMA_EN;

    TIM3_CR1 = 0;
    TIM3_PSC = 0;
    TIM3_ARR = TIM_ARR;
    TIM3_CR2 = TIM_MMS_UPDATE;
    TIM3_EGR = TIM_UG;
    TIM3_CR1 = TIM_CEN;

    audio_rd = 0;
    audio_capturing = true;
}

static void capture_stop(void)
{
    if (!audio_capturing)
        return;
    audio_capturing = false;
    TIM3_CR1    = 0;
    DMA1_C1_CCR = 0;
    DMA_IFCR    = 0x7u;
    ADC_CR2     = audio_cr2;        /* software trigger, no DMA              */
    ADC_CR1     = audio_cr1;        /* scan off                              */
    ADC_SQR1    = audio_sqr1;       /* one rank                              */
    ADC_SQR3    = audio_sqr3;       /* the battery channel back              */
    ADC_SMPR3   = audio_smpr3;
    DAC_CR      = audio_dac;
    DAC_DHR12R1 = audio_dhr;
    RCC_APBENR1 = audio_rcc1;
    GPIOA_MODER = audio_moder;
}

/* Pairs the DMA has written that we have not read. */
static uint16_t audio_avail(void)
{
    uint16_t wr = (uint16_t)(AUDIO_RING - (DMA1_C1_CNDTR >> 1));
    return (uint16_t)((wr - audio_rd) % AUDIO_RING);
}

/* How many samples this frame carries: 7, 8 or 9 according to the ring, which
 * is what hands the clock to the host. */
static uint8_t audio_fill(void)
{
#if AUDIO_TEST_SINE
    for (uint8_t i = 0; i < AUDIO_FRAME; i++) {
        audio_buf[2u * i]      = (uint8_t)AUDIO_SINE[audio_phase & 31u];
        audio_buf[2u * i + 1u] = (uint8_t)(AUDIO_SINE[audio_phase & 31u] >> 8);
        audio_phase++;
    }
    return (uint8_t)(AUDIO_FRAME * 2u);
#else
    uint16_t avail = audio_avail();
    uint8_t  n = AUDIO_FRAME;
    if (avail > AUDIO_TARGET + 4u)       n = AUDIO_FRAME + 1u;
    else if (avail + 4u < AUDIO_TARGET)  n = AUDIO_FRAME - 1u;
    if (avail < n)
        n = (uint8_t)avail;             /* nothing to invent: a short frame */
    for (uint8_t i = 0; i < n; i++) {
        uint16_t v = (uint16_t)(audio_ring[2u * audio_rd] & 0x0FFFu);
        audio_batt = (uint16_t)(audio_ring[2u * audio_rd + 1u] & 0x0FFFu);
        audio_rd = (uint16_t)((audio_rd + 1u) % AUDIO_RING);
        int16_t s = (int16_t)(((int16_t)v - (int16_t)BIAS_CODE) << 4);
        audio_buf[2u * i]      = (uint8_t)s;
        audio_buf[2u * i + 1u] = (uint8_t)((uint16_t)s >> 8);
    }
    return (uint8_t)(n * 2u);
#endif
}

/* The battery, while the stream owns the ADC: the odd samples of the ring,
 * which is why BOARD_ADC_GetBatteryInfo must not convert for itself. */
bool USBAUDIO_Battery(uint16_t *voltage)
{
    if (!audio_capturing)
        return false;
    *voltage = audio_batt;
    return true;
}

static void audio_send(void)
{
    if (!audio_on || audio_suspended)
        return;
    usbd_ep_start_write(AUDIO_IN_EP, audio_buf, audio_fill());
}

/* The host selected alt setting 1 (streaming) or 0 (idle): the only place
 * that knows whether anybody is listening, so the capture starts and stops
 * here rather than running for ever. */
void usbd_audio_open(uint8_t intf)
{
    if (intf == AUDIO_AS_OUT_INTF) {        /* the host starts feeding us */
        play_wr = play_rd = 0;
        play_lost = 0;
        play_on = true;
        usbd_ep_start_read(AUDIO_OUT_EP, play_buf, AUDIO_MPS);
        return;
    }
    audio_phase = 0;
    audio_on = true;
    if (!audio_suspended)
        capture_start();
    audio_send();                   /* prime the first frame */
}

void usbd_audio_close(uint8_t intf)
{
    if (intf == AUDIO_AS_OUT_INTF) {
        play_on = false;
        return;
    }
    audio_on = false;
    capture_stop();
}

static void usbd_audio_iso_in(uint8_t ep, uint32_t nbytes)
{
    (void)ep;
    (void)nbytes;
    audio_send();                   /* one frame out, the next one armed */
}

static void usbd_audio_iso_out(uint8_t ep, uint32_t nbytes)
{
    (void)ep;
    for (uint32_t i = 0; i + 1u < nbytes; i += 2u) {
        uint16_t next = (uint16_t)((play_wr + 1u) % PLAY_RING);
        if (next == play_rd) {
            if (play_lost < 65535u) play_lost++;
            continue;               /* the ring is full: the newest is kept
                                       out rather than the oldest thrown */
        }
        play_ring[play_wr] = (int16_t)((uint16_t)play_buf[i] |
                                       ((uint16_t)play_buf[i + 1u] << 8));
        play_wr = next;
    }
    play_total += nbytes / 2u;
    usbd_ep_start_read(AUDIO_OUT_EP, play_buf, AUDIO_MPS);
}

static struct usbd_endpoint audio_in_ep = {
    .ep_addr = AUDIO_IN_EP,
    .ep_cb = usbd_audio_iso_in
};

static struct usbd_endpoint audio_out_ep = {
    .ep_addr = AUDIO_OUT_EP,
    .ep_cb = usbd_audio_iso_out
};

/* ---- the transmitter, and it only ever runs on an explicit serial command ----
 *
 * A PC that merely opens the playback stream must NOT key the radio: measured
 * on this very firmware, PulseAudio adopts the new sink the moment it appears
 * and pushes silence into it for ever - 789800 samples before anyone asked
 * for anything. So the carrier goes up on command 0x0752 and for the number
 * of milliseconds that command names, never otherwise.
 *
 * The loop is modal and busy-waits, as the overlay apps' does, because the
 * BK4829's bus is bit-banged and not reentrant: a timer ISR writing REG_70
 * would cut a main-loop register read in half. One register write a sample,
 * about 3850 of the 6000 cycles a period holds.
 */
#define TX_MAX_MS       60000u      /* a commanded burst still ends         */
#define TX_LEAD         64u         /* samples in hand before the carrier   */
#define TX_WAIT_MS      300u        /* patience for the host to start        */
#define CPS             (48000000u / AUDIO_FREQ)
#define REG_30          0x30
#define REG_38          0x38
#define REG_39          0x39
#define REG_70          0x70
#define REG_71          0x71
#define TX_LINK_OFF     0x0000u
#define TX_LINK_NO_MIC  0xC3FAu     /* the generator modulates, not the mic */
#define PLL_LOCK_MS     2u
#define F_PARK          330u        /* 32 Hz: parks the DDS at its peak     */
#define PARK_MS         8u
#define F_PLAUS_MIN     1800000u
#define F_PLAUS_MAX     130000000u
#define F_BAND_TOL      100000u

/* app_overlay.c carries the canonical copy: the 10 ms tick and the SysTick
 * phase, read race-free. */
static uint32_t tx_cycles(void)
{
    uint32_t tick, val;
    do {
        tick = SCHEDULER_GetTick10ms();
        val  = SysTick->VAL;
    } while (tick != SCHEDULER_GetTick10ms());
    if (SCB->ICSR & SCB_ICSR_PENDSTSET_Msk) {
        val = SysTick->VAL;
        tick++;
    }
    return tick * (SysTick->LOAD + 1u) + (SysTick->LOAD - val);
}

/* The same refusals the overlay apps get from tx_state(). */
static uint8_t tx_refused(void)
{
    if (TX_freq_check(gTxVfo->pTX->Frequency) != 0 && gTxVfo->TX_LOCK) return 1;
    if (gBatteryDisplayLevel == 0) return 1;
    if (gBatteryDisplayLevel > 6)  return 1;
    if (gTxVfo->Modulation != MODULATION_FM) return 1;
    return 0;
}

uint8_t USBAUDIO_Transmit(uint16_t ms, uint32_t *sent, uint16_t *dry)
{
    *sent = 0;
    *dry = 0;
    if (ms == 0u || ms > TX_MAX_MS)
        return 4;                   /* implausible length                   */
    if (tx_refused())
        return 1;                   /* the radio itself says no             */

    /* Drop whatever the host's audio stack has been pushing: a burst must
     * start on fresh audio, not on PulseAudio's backlog of silence. */
    play_rd = play_wr;
    for (uint16_t waited = 0; ((play_wr - play_rd) % PLAY_RING) < TX_LEAD; waited++) {
        if (waited >= TX_WAIT_MS)
            return 2;               /* nobody is feeding us                 */
        SYSTEM_DelayMs(1u);
    }

    const uint32_t f0 = gTxVfo->pTX->Frequency;
    capture_stop();                 /* half duplex: the ADC is not needed   */

    RADIO_SetTxParameters();
    BK4819_ToggleGpioOut(BK4819_GPIO1_PIN29_PA_ENABLE, false);
    BK4819_EnterTxMute();
    BK4819_WriteRegister(REG_70, 0);

    /* The chip's own frequency, read back before the carrier: a PC asked for
     * this transmission. */
    uint32_t f = ((uint32_t)BK4819_ReadRegister(REG_39) << 16) |
                 BK4819_ReadRegister(REG_38);
    if (f >= F_PLAUS_MIN && f <= F_PLAUS_MAX) {
        uint32_t d = f > f0 ? f - f0 : f0 - f;
        if (d > F_BAND_TOL) {
            BK4819_ToggleGpioOut(BK4819_GPIO1_PIN29_PA_ENABLE, false);
            RADIO_SetupRegisters(true);
            return 3;               /* another band, another filter         */
        }
    }
    BK4819_WriteRegister(REG_38, (uint16_t)f0);
    BK4819_WriteRegister(REG_39, (uint16_t)(f0 >> 16));
    BK4819_WriteRegister(REG_30, TX_LINK_OFF);
    BK4819_WriteRegister(REG_30, TX_LINK_NO_MIC);
    SYSTEM_DelayMs(PLL_LOCK_MS);
    BK4819_ToggleGpioOut(BK4819_GPIO5_PIN1_RED, true);
    BK4819_ToggleGpioOut(BK4819_GPIO1_PIN29_PA_ENABLE, true);
    BK4819_ExitTxMute();

    /* Park the DDS at the sine's peak and freeze it: from here the gain
     * field alone carries the audio. */
    BK4819_WriteRegister(REG_71, F_PARK);
    BK4819_WriteRegister(REG_70, (uint16_t)(0x8000u | (127u << 8)));
    SYSTEM_DelayMs(PARK_MS);
    BK4819_WriteRegister(REG_71, 0);

    uint8_t status = 0;
    int16_t last = 0;
    uint32_t total = (uint32_t)ms * (AUDIO_FREQ / 1000u);
    uint32_t next = tx_cycles() + CPS;
    for (uint32_t n = 0; n < total; n++) {
        if (play_rd != play_wr) {
            last = play_ring[play_rd];
            play_rd = (uint16_t)((play_rd + 1u) % PLAY_RING);
        } else if (*dry < 65535u) {
            (*dry)++;               /* hold the last sample: a flat 125 us  */
        }
        int32_t v = 64 + (last >> 9);
        if (v < 0) v = 0;
        else if (v > 127) v = 127;
        while ((int32_t)(tx_cycles() - next) < 0) { }
        next += CPS;
        BK4819_WriteRegister(REG_70, (uint16_t)(0x8000u | ((uint32_t)v << 8)));
        (*sent)++;
        if ((n & 0x3FFu) == 0x3FFu && KEYBOARD_Poll() == KEY_EXIT) {
            status = 5;             /* the operator's own abort             */
            break;
        }
    }

    BK4819_WriteRegister(REG_70, 0);
    BK4819_WriteRegister(REG_71, 0);
    BK4819_EnterTxMute();
    BK4819_ToggleGpioOut(BK4819_GPIO1_PIN29_PA_ENABLE, false);
    BK4819_ToggleGpioOut(BK4819_GPIO5_PIN1_RED, false);
    BK4819_WriteRegister(REG_38, (uint16_t)f0);
    BK4819_WriteRegister(REG_39, (uint16_t)(f0 >> 16));
    RADIO_SetupRegisters(true);
    if (audio_on)
        capture_start();            /* back to being a microphone           */
    return status;
}

void USBAUDIO_PlayStats(uint32_t *delivered, uint16_t *queued, uint16_t *lost)
{
    *delivered = play_total;
    *queued = (uint16_t)((play_wr - play_rd) % PLAY_RING);
    *lost = play_lost;
}

static struct usbd_interface audio_ac_intf;
static struct usbd_interface audio_as_intf;
static struct usbd_interface audio_as_out_intf;

/* An overlay app reconfigures the ADC, TIM3 and DMA1 channel 1 for itself
 * (af_capture, AF Stream, AF Bridge), so the capture must stand down while
 * one runs. Phase A has nothing to stand down but the frames. */
void USBAUDIO_Suspend(void)
{
    audio_suspended = true;
    capture_stop();                 /* the app wants the ADC, TIM3 and DMA */
}

void USBAUDIO_Resume(void)
{
    audio_suspended = false;
    if (audio_on) {
        capture_start();
        audio_send();
    }
}

bool USBAUDIO_Streaming(void)
{
    return audio_on && !audio_suspended;
}

void USBAUDIO_Init(void)
{
    usbd_add_interface(usbd_audio_init_intf(&audio_ac_intf));
    usbd_add_interface(usbd_audio_init_intf(&audio_as_intf));
    usbd_add_interface(usbd_audio_init_intf(&audio_as_out_intf));
    usbd_add_endpoint(&audio_in_ep);
    usbd_add_endpoint(&audio_out_ep);
    /* No usbd_audio_add_entity(): it is the class's only usb_malloc() caller,
     * and this firmware has no heap (__min_heap_size=0, ENABLE_NO_HEAP). The
     * entity list exists to answer volume and mute requests, which the
     * minimal topology above does not advertise - there is no Feature Unit -
     * so a host has nothing to ask about, and --gc-sections drops the
     * function along with its malloc. */
}

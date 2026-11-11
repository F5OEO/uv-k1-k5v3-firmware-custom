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
 * PHASE A, which this file is: the descriptors, the isochronous endpoint and
 * a synthetic sine, so enumeration and ISO on this port are proven apart from
 * any capture bug. The sine is what a host hears until phase B wires PA4's
 * TIM3 -> ADC -> DMA ring in behind it.
 *
 * The 1 ms frame is the whole budget: at 8 kHz one frame is 8 samples, 16
 * bytes. The endpoint is declared for 9 (18 bytes), which is the ceiling the
 * asynchronous rule needs.
 */

#include "usbd_core.h"
#include "usbd_audio.h"
#include "usbd_audio_if.h"

#define AUDIO_IN_EP     0x84        /* CDC holds 0x81, 0x02 and 0x83 */
#define AUDIO_FREQ      8000u
#define AUDIO_FRAME     (AUDIO_FREQ / 1000u)        /* 8 samples a frame   */
#define AUDIO_MPS       ((AUDIO_FRAME + 1u) * 2u)   /* 9 samples: 18 bytes */

static uint8_t  audio_buf[AUDIO_MPS];
static uint16_t audio_phase;
static bool     audio_on;
static bool     audio_suspended;

/* A 32-point sine at 8 kHz is 250 Hz, loud enough to see on any host meter
 * and cheap enough to live in flash. Phase A's whole signal. */
static const int16_t AUDIO_SINE[32] = {
         0,   6392,  12539,  18204,  23170,  27245,  30273,  32137,
     32767,  32137,  30273,  27245,  23170,  18204,  12539,   6392,
         0,  -6392, -12539, -18204, -23170, -27245, -30273, -32137,
    -32767, -32137, -30273, -27245, -23170, -18204, -12539,  -6392
};

/* How many samples this frame carries. Phase A has no ring to look at, so it
 * is always the nominal count; phase B chooses 7, 8 or 9 from the DMA ring's
 * fill, which is what makes the source asynchronous. */
static uint8_t audio_fill(void)
{
    uint8_t n = AUDIO_FRAME;
    for (uint8_t i = 0; i < n; i++) {
        audio_buf[2u * i]      = (uint8_t)AUDIO_SINE[audio_phase & 31u];
        audio_buf[2u * i + 1u] = (uint8_t)(AUDIO_SINE[audio_phase & 31u] >> 8);
        audio_phase++;
    }
    return (uint8_t)(n * 2u);
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
    (void)intf;
    audio_phase = 0;
    audio_on = true;
    audio_send();                   /* prime the first frame */
}

void usbd_audio_close(uint8_t intf)
{
    (void)intf;
    audio_on = false;
}

static void usbd_audio_iso_in(uint8_t ep, uint32_t nbytes)
{
    (void)ep;
    (void)nbytes;
    audio_send();                   /* one frame out, the next one armed */
}

static struct usbd_endpoint audio_in_ep = {
    .ep_addr = AUDIO_IN_EP,
    .ep_cb = usbd_audio_iso_in
};

static struct usbd_interface audio_ac_intf;
static struct usbd_interface audio_as_intf;

/* An overlay app reconfigures the ADC, TIM3 and DMA1 channel 1 for itself
 * (af_capture, AF Stream, AF Bridge), so the capture must stand down while
 * one runs. Phase A has nothing to stand down but the frames. */
void USBAUDIO_Suspend(void)
{
    audio_suspended = true;
}

void USBAUDIO_Resume(void)
{
    audio_suspended = false;
    if (audio_on)
        audio_send();
}

bool USBAUDIO_Streaming(void)
{
    return audio_on && !audio_suspended;
}

void USBAUDIO_Init(void)
{
    usbd_add_interface(usbd_audio_init_intf(&audio_ac_intf));
    usbd_add_interface(usbd_audio_init_intf(&audio_as_intf));
    usbd_add_endpoint(&audio_in_ep);
    /* No usbd_audio_add_entity(): it is the class's only usb_malloc() caller,
     * and this firmware has no heap (__min_heap_size=0, ENABLE_NO_HEAP). The
     * entity list exists to answer volume and mute requests, which the
     * minimal topology above does not advertise - there is no Feature Unit -
     * so a host has nothing to ask about, and --gc-sections drops the
     * function along with its malloc. */
}

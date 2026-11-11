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

#ifndef APP_USBD_AUDIO_IF_H
#define APP_USBD_AUDIO_IF_H

#include <stdbool.h>
#include <stdint.h>

/* CherryUSB's AUDIO_AS_DESCRIPTOR_INIT hard-codes bmAttributes = 0x01, an
 * isochronous endpoint with NO synchronisation. A capture stream has to say
 * asynchronous (0x05) instead: the device is the clock master, the host
 * resamples what arrives, and that single bit is what moves the radio's
 * 7970 Hz from being our problem - every line of clock servo in
 * tools/afstream.py - to being the host audio stack's. The rest of this is
 * the vendored macro byte for byte.
 */
#define AUDIO_AS_IN_ASYNC_DESCRIPTOR_INIT(bInterfaceNumber, bTerminalLink,      \
                                          bNrChannels, bEndpointAddress,        \
                                          wMaxPacketSize, bInterval, ...)       \
    0x09, USB_DESCRIPTOR_TYPE_INTERFACE, bInterfaceNumber, 0x00, 0x00,          \
    USB_DEVICE_CLASS_AUDIO, AUDIO_SUBCLASS_AUDIOSTREAMING,                      \
    AUDIO_PROTOCOL_UNDEFINED, 0x00,                                             \
    0x09, USB_DESCRIPTOR_TYPE_INTERFACE, bInterfaceNumber, 0x01, 0x01,          \
    USB_DEVICE_CLASS_AUDIO, AUDIO_SUBCLASS_AUDIOSTREAMING,                      \
    AUDIO_PROTOCOL_UNDEFINED, 0x00,                                             \
    0x07, AUDIO_INTERFACE_DESCRIPTOR_TYPE, AUDIO_STREAMING_GENERAL,             \
    bTerminalLink, 0x01, WBVAL(AUDIO_FORMAT_PCM),                               \
    0x08 + PP_NARG(__VA_ARGS__), AUDIO_INTERFACE_DESCRIPTOR_TYPE,               \
    AUDIO_STREAMING_FORMAT_TYPE, AUDIO_FORMAT_TYPE_I, bNrChannels, 0x02, 0x10,  \
    (PP_NARG(__VA_ARGS__) / 3), __VA_ARGS__,                                    \
    0x09, USB_DESCRIPTOR_TYPE_ENDPOINT, bEndpointAddress,                       \
    0x05,                      /* isochronous, ASYNCHRONOUS: the one change */  \
    WBVAL(wMaxPacketSize), bInterval, 0x00, 0x00,                               \
    0x07, AUDIO_ENDPOINT_DESCRIPTOR_TYPE, AUDIO_ENDPOINT_GENERAL,               \
    0x00,                      /* no endpoint controls: see below         */  \
    0x00, 0x00, 0x00
/* bmAttributes 0x00 where the vendored macro advertises
 * AUDIO_EP_CONTROL_SAMPLING_FEQ. Advertising it makes Linux issue SET_CUR on
 * the endpoint, and this CherryUSB core cannot route an endpoint-recipient
 * class request: usbd_class_request_handler matches
 * intf->intf_num == ((wIndex >> 8) & 0xFF), while an endpoint request carries
 * its address in the LOW byte, so wIndex >> 8 is 0 - the CDC comm interface,
 * which has no endpoint handler. The request STALLs and the kernel gives up
 * with "cannot set freq 8000 to ep 0x84", measured on the radio. With one
 * declared frequency there is nothing to set, so the honest descriptor is the
 * one that claims no control. Fixing the core's dispatch would touch the
 * shared stack that CDC also runs on, for no gain here.
 */

/* Registers the audio interfaces and the isochronous endpoint, from
 * cdc_acm_init() so the composite is built in one place. */
void USBAUDIO_Init(void);

/* An overlay app owns the ADC, TIM3 and DMA1 channel 1 while it runs: the
 * loader brackets entry(&app_api) with these. */
void USBAUDIO_Suspend(void);
void USBAUDIO_Resume(void);

/* True while a host has alt setting 1 selected and no app has the hardware. */
bool USBAUDIO_Streaming(void);

#endif /* APP_USBD_AUDIO_IF_H */

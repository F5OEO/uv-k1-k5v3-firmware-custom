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
 * VTX Data - not a program, a brick of audio.
 *
 * A slot's asset area holds 3840 B, which at 3-bit ADPCM and 8 kHz is 1.27 s
 * of speech: not enough for a beacon announcement.  The app store is a plain
 * array though - 0x102000 + slot * 0x2000, assets at +0x100
 * (app_overlay.h:37) - and sys_storage_read addresses it directly, so a clip
 * can be spread over as many slots as it needs.  This app carries one block
 * and does nothing else; App/apps/voicetx finds it by the 'VTX' signature at
 * the start of the asset area, whatever slot it was installed in.
 *
 * Installing it is the only thing it is for, but a launcher entry has to do
 * something, so it says which block it holds and waits for EXIT.
 *
 * One build is one block, chosen by VTX_CHUNK, and the clip needs all of them:
 * VTX_CHUNK=1 ./build.sh, then 2, 3 and 4 for the clip as it stands, each
 * installed in a slot of its own.  Block 0 is Voice TX's own asset.  The clip
 * itself is read from
 * ../voicetx/clips.json, so there is only ever one copy of it.  Not built by
 * "compile-app.sh All".
 */

#include <stdint.h>
#include <stdbool.h>
#include "../app_api.h"
#include "vtxdata_assets.h"

__attribute__((section(".text.entry"), used))
void app_main(const app_api_t *api)
{
    uint8_t h[8];
    char s[32], *o = s;
    uint32_t n;

    api->asset_read(BLOCK, h, 8u);
    n = (uint32_t)h[4] | ((uint32_t)h[5] << 8)
      | ((uint32_t)h[6] << 16) | ((uint32_t)h[7] << 24);

    api->display_clear();
    api->status_clear();
    api->print_bold("VTX DATA " APP_VERSION, 0, 127, 0);
    *o++ = 'B'; *o++ = 'L'; *o++ = 'O'; *o++ = 'C'; *o++ = 'K'; *o++ = ' ';
    o = api->append_u32(o, BLOCK_IDX);
    *o++ = ' '; *o++ = 'O'; *o++ = 'F'; *o++ = ' ';
    o = api->append_u32(o, n);
    *o++ = ' '; *o++ = 'S'; *o++ = 'M'; *o++ = 'P';
    *o = 0;
    api->print_tiny(s, 0, 25, false, true);
    api->print_normal("CLIP FOR VOICE TX", 0, 127, 4);
    api->print_tiny("NOT A PROGRAM - EXIT", 0, 1, true, true);
    api->blit_status();
    api->blit_full();

    while (api->get_key() != APP_KEY_EXIT) {
        api->battery_sample();
        api->backlight_update();
        api->delay_ms(30u);
    }
}

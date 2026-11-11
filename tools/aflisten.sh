#!/usr/bin/env bash
# Copyright 2026 Evariste F5OEO
# https://github.com/F5OEO
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
#     Unless required by applicable law or agreed to in writing, software
#     distributed under the License is distributed on an "AS IS" BASIS,
#     WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#     See the License for the specific language governing permissions and
#     limitations under the License.
#
# Listen, with aplay, to the audio the AF Stream overlay sends over USB.
#
#   ./aflisten.sh                  # /dev/ttyACM0, 8 kHz
#   ./aflisten.sh -r 16000         # the rate selected on the radio (key 1)
#   ./aflisten.sh -g 4             # four times louder
#   ./aflisten.sh -s 300           # stop after five minutes
#   ./aflisten.sh -D null          # the plumbing, silently
#
# App/apps/afstream must be running on the radio. Ctrl-C stops.
#
# Two things this script is for. The tty line discipline would mangle the
# stream - icrnl rewrites 0x0D, ixon swallows 0x11 and 0x13, isig acts on
# 0x03 - so the port is put in raw mode first. And the wire carries the ADC's
# 12-bit codes, 0 to 4095 around 2048, which aplay has no way to centre or
# scale: afstream.py does that, finds the byte phase, and pipes the result to
# aplay. Without python3 the script falls back to handing the port straight to
# aplay, which plays but quietly and with a DC offset.
#
# With the app's gate on (key 4) nothing arrives between transmissions, and
# aplay reports an underrun at each gap. That is the gate working; key 4 to
# OFF for continuous listening.
set -euo pipefail

PORT=/dev/ttyACM0
RATE=8000
GAIN=1
DEVICE=default
SECONDS_=0

usage() {
    sed -n '17,34p' "$0" | sed 's/^# \?//'
    exit "${1:-0}"
}

while getopts "p:r:g:D:s:h" opt; do
    case "$opt" in
    p) PORT=$OPTARG ;;
    r) RATE=$OPTARG ;;
    g) GAIN=$OPTARG ;;
    D) DEVICE=$OPTARG ;;
    s) SECONDS_=$OPTARG ;;
    h) usage ;;
    *) usage 2 ;;
    esac
done

command -v aplay >/dev/null || { echo "aplay is missing: apt install alsa-utils" >&2; exit 1; }
[ -c "$PORT" ] || { echo "$PORT is not a character device - is the radio plugged in?" >&2; exit 1; }

# Raw mode, and reads that return as soon as a byte is there.
stty -F "$PORT" raw -echo -echoe -echok min 1 time 0 2>/dev/null ||
    { echo "cannot configure $PORT (permissions? dialout group?)" >&2; exit 1; }

HERE=$(dirname "$(readlink -f "$0")")
if command -v python3 >/dev/null && [ -f "$HERE/afstream.py" ]; then
    echo "listening on $PORT at $RATE Hz, gain $GAIN, device $DEVICE - Ctrl-C to stop" >&2
    exec python3 -B "$HERE/afstream.py" --play --port "$PORT" --rate "$RATE" \
                                        --gain "$GAIN" --device "$DEVICE" \
                                        --seconds "$SECONDS_"
fi

echo "no python3: handing the raw codes to aplay, which cannot centre or" >&2
echo "scale them - expect a quiet signal with a DC offset, and turn it up" >&2
exec aplay -q -D "$DEVICE" -t raw -f S16_LE -c 1 -r "$RATE" "$PORT"

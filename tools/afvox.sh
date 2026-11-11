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
# The radio as a VOX-driven USB headset: what it receives comes out of the PC's
# speakers, and what the PC's microphone hears goes on the air.
#
#   ./afvox.sh                     # /dev/ttyACM0, VOX at -35 dBFS
#   ./afvox.sh -t -30 -H 1.5       # less sensitive, longer hang
#   ./afvox.sh -s 600              # stop after ten minutes
#   ./afvox.sh -m "cat clip.raw"   # a file instead of the microphone
#
# App/apps/afbridge must be running on the radio, and nothing else may hold the
# port - stop aflisten.sh first. Ctrl-C stops.
#
# THIS TRANSMITS WITHOUT A HAND ON A KEY. The radio keys up on whatever the
# microphone hears above the threshold, on the VFO and at the power the radio
# is set to, with your callsign going out each time. Watch the hang time, set
# the threshold above the room, and do not leave it running unattended.
#
# The pieces it leans on: the overlay app refuses the transmission if
# tx_state() says so, drops the carrier 250 ms after the host stops feeding,
# and caps an open-ended burst at three minutes; this script caps one
# transmission at --max-tx too. The audio chain is the repo's own Agc and
# Adpcm, fed live, and a resampler servoed on the ring fill the radio reports
# absorbs the 0.4 % between the PC's clock and the radio's.
set -euo pipefail

PORT=/dev/ttyACM0
THR=-35
HANG=1.0
MAXTX=120
DEVICE=default
GAIN=2
SECS=0
MIC=""

usage() { sed -n '17,40p' "$0" | sed 's/^# \?//'; exit "${1:-0}"; }

while getopts "p:t:H:T:D:g:s:m:h" opt; do
    case "$opt" in
    p) PORT=$OPTARG ;;
    t) THR=$OPTARG ;;
    H) HANG=$OPTARG ;;
    T) MAXTX=$OPTARG ;;
    D) DEVICE=$OPTARG ;;
    g) GAIN=$OPTARG ;;
    s) SECS=$OPTARG ;;
    m) MIC=$OPTARG ;;
    h) usage ;;
    *) usage 2 ;;
    esac
done

command -v aplay >/dev/null || { echo "aplay is missing: apt install alsa-utils" >&2; exit 1; }
command -v arecord >/dev/null || { echo "arecord is missing: apt install alsa-utils" >&2; exit 1; }
[ -c "$PORT" ] || { echo "$PORT is not a character device - is the radio plugged in?" >&2; exit 1; }

stty -F "$PORT" raw -echo -echoe -echok min 1 time 0 2>/dev/null ||
    { echo "cannot configure $PORT (permissions? dialout group?)" >&2; exit 1; }

HERE=$(dirname "$(readlink -f "$0")")
ARGS=(--vox --port "$PORT" --vox-thr "$THR" --vox-hang "$HANG"
      --max-tx "$MAXTX" --device "$DEVICE" --gain "$GAIN" --seconds "$SECS")
[ -n "$MIC" ] && ARGS+=(--mic-cmd "$MIC")

echo "VOX on $PORT at $THR dBFS, hang ${HANG}s, cap ${MAXTX}s - Ctrl-C to stop" >&2
exec python3 -B "$HERE/afbridge.py" "${ARGS[@]}"

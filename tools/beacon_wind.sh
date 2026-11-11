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
# Speak a wind reading as the Bonneuil-Matours beacon.
#
#   ./beacon_wind.sh <mean> <direction> <max>
#   ./beacon_wind.sh 15 30 26            # degrees, as a vane reports them
#   ./beacon_wind.sh 15 NNE 26           # or a compass point, if you have one
#   ./beacon_wind.sh 15 30 26 -n         # build the audio, do not transmit
#
# The announcement is
#
#   "Balise de <site>, <mean> kilomètres heure, <direction>, <max>
#    kilomètres heure maximum."
#
# where <site> is Bonneuil-Matours unless SITE says otherwise.
#
# Direction is degrees, 0 to 360, rounded to the nearest of the sixteen
# points: 0 is nord, 30 nord-nord-est, 45 nord-est, 350 nord again.  Each
# point covers 22.5 degrees, so the boundaries fall on 11.25, 33.75 and so on
# and no whole degree can land on one.  A compass point is accepted too, in
# French (N E S O) or English (N E S W) - both NO and NW give "nord-ouest" -
# for a vane that reports letters.  Case does not matter.
#
# This is the thing a cron line calls every half hour: read the anemometer,
# call this, and the radio says the new figures.  Nothing is written to the
# radio's flash - the clip is streamed over USB at the moment of transmission
# - so there is no wear and no install, but Voice TX 3.2 or later has to be
# running on the radio.  See tools/beacon_say.py.
#
# Piper and its voice are not in this repository; TTS points at the install.
set -euo pipefail

HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
TTS=${TTS:-/media/hp-z2-dev/Variste/Doc/tmp/tts}   # where piper was installed
PIPER=${PIPER:-$TTS/venv/bin/piper}
PY=${PY:-$TTS/venv/bin/python}
MODEL=${MODEL:-$TTS/models/fr_FR-upmc-medium.onnx}
SPEAKER=${SPEAKER:-0}                              # 0 = jessica, 1 = pierre
SITE=${SITE:-Bonneuil-Matours}                     # spelt as it is to be said
PORT=${PORT:-/dev/ttyACM0}
# A cron line runs this every half hour, so the scratch has to go away again.
# An OUT given by the caller is theirs to keep.
if [ -n "${OUT:-}" ]; then
    mkdir -p "$OUT"
else
    OUT=$(mktemp -d "${TMPDIR:-/tmp}/balise.XXXXXX")
    trap 'rm -rf "$OUT"' EXIT
fi

usage() { sed -n '17,33p' "${BASH_SOURCE[0]}" | sed 's/^# \{0,1\}//'; exit 2; }

[ $# -ge 3 ] || usage
mean=$1 dir=$2 max=$3
transmit=yes
[ "${4:-}" = "-n" ] && transmit=no

for v in "$mean" "$max"; do
    [[ $v =~ ^[0-9]{1,3}$ ]] || { echo "not a wind speed: $v" >&2; exit 2; }
    [ "$v" -le 300 ] || { echo "wind speed out of range: $v" >&2; exit 2; }
done
[ "$max" -ge "$mean" ] || echo "note: the maximum ($max) is below the mean ($mean)" >&2

# The sixteen points, clockwise from north, as they are said.
POINTS=(nord nord-nord-est nord-est est-nord-est
        est  est-sud-est   sud-est sud-sud-est
        sud  sud-sud-ouest sud-ouest ouest-sud-ouest
        ouest ouest-nord-ouest nord-ouest nord-nord-ouest)

if [[ $dir =~ ^[0-9]{1,3}([.][0-9]+)?$ ]]; then
    # Degrees from a vane.  awk because the rounding is to 22.5 and bash has
    # only integers; the modulo brings 360 back round to north.
    awk -v d="$dir" 'BEGIN { exit !(d >= 0 && d <= 360) }'         || { echo "direction out of range: $dir (0 to 360 degrees)" >&2; exit 2; }
    idx=$(awk -v d="$dir" 'BEGIN { printf "%d", int(d/22.5 + 0.5) % 16 }')
    said=${POINTS[$idx]}
    from="${dir}° -> "
else
    # A compass point instead.  French and English spellings both map here, so
    # an anemometer reporting NW is as welcome as one reporting NO.
    case "${dir^^}" in
        N)       idx=0  ;;  NNE)     idx=1  ;;  NE)      idx=2  ;;
        ENE)     idx=3  ;;  E)       idx=4  ;;  ESE)     idx=5  ;;
        SE)      idx=6  ;;  SSE)     idx=7  ;;  S)       idx=8  ;;
        SSO|SSW) idx=9  ;;  SO|SW)   idx=10 ;;  OSO|WSW) idx=11 ;;
        O|W)     idx=12 ;;  ONO|WNW) idx=13 ;;  NO|NW)   idx=14 ;;
        NNO|NNW) idx=15 ;;
        *) echo "unknown direction: $dir - give degrees (0-360), or one of" \
                "N NNE NE ENE E ESE SE SSE S SSO SO OSO O ONO NO NNO" >&2; exit 2 ;;
    esac
    said=${POINTS[$idx]}
    from=""
fi

text="Balise de ${SITE}, ${mean} kilomètres heure, ${said}, ${max} kilomètres heure maximum."
printf "  %b%s\n" "$from" "$said"
echo "  $text"

[ -x "$PIPER" ] || { echo "piper not found at $PIPER - set TTS or PIPER" >&2; exit 1; }
[ -r "$MODEL" ] || { echo "voice not found at $MODEL - set TTS or MODEL" >&2; exit 1; }

wav="$OUT/balise.wav"
"$PIPER" -m "$MODEL" -s "$SPEAKER" --sentence-silence 0.0 -f "$wav" <<< "$text"

if [ "$transmit" = no ]; then
    echo "  $wav"
    trap - EXIT                 # the caller asked for the file: leave it
    exit 0
fi
"$PY" "$HERE/beacon_say.py" --port "$PORT" "$wav"

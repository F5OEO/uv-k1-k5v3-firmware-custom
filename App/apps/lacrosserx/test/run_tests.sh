#!/bin/sh
# Host test of the TX141 decoder: cc, run, done.
set -eu

cd "$(dirname "$0")"
OUT="${TMPDIR:-/tmp}/host_dectx141"
SUBS="${TMPDIR:-/tmp}/lacrosse_sub"
cc -std=c99 -Wall -Wextra -Werror -O2 -I.. host_dectx141.c ../dectx141.c -lm -o "$OUT"
# the bench files go through the same decoder before they go on the air
python3 -B flipper_tx141.py "$SUBS" >/dev/null
"$OUT" "$SUBS"

# AF Bridge

Both directions of audio over the one USB-C port: the received audio out, a
transmission in. AF Stream and Voice TX in a single overlay — 4004 B of the
4096 the overlay holds, 92 B to spare.

**The RF is half duplex and cannot be otherwise**: one VCO, one path, one PA.
The radio receives, or it transmits. Only the *USB link* is full duplex, and
that is not decoration — see "Pacing" below.

## Use

1. Tune the VFO. Any modulation; the AM detector is the VFO's business.
2. Install the app in a free slot and launch it. It receives at once.
3. Listen: `tools/aflisten.sh`. Transmit: `tools/afbridge.py message.wav`.
   One program at a time owns the port, so stop the listener before
   transmitting.

```
 AF Bridge                 [usb][bat]
 433.920 SQ
 RX
 OUT 183kB  PP 740
 IN 39835 FILL 42
 OVR 0 TO 0 ST OK C 83
```

| Field | Meaning |
|---|---|
| `SQ` | the gate is on (key 1): nothing is sent while the squelch is closed. `SQ?` means the `RAW` path is also on, where the squelch bit cannot be trusted |
| `RAW` | `REG_2B`'s raw bits (key 2): no 300 Hz high-pass, no 3 kHz low-pass, no de-emphasis, AFC off |
| `RX` / `ON AIR` | which way the radio is pointing |
| `OUT`, `PP` | bytes of audio sent, and the peak to peak of the last block out of 4096 |
| `IN`, `FILL` | samples transmitted in the last burst, and the bytes waiting in the app's 128-byte ring |
| `OVR`, `TO` | half-buffers the host was too slow for, and writes it did not take within 50 ms |
| `ST`, `C` | how the last burst ended, and the worst credit write in µs — the one thing that can put a hole in transmitted audio |

Keys: **1** the gate, **2** the AF path, **EXIT** quit. Both are saved.

## Wire format

Out (radio → host), little-endian halfwords:

| Word | Meaning |
|---|---|
| `0x0000`–`0x0FFF` | one audio sample, the ADC's 12 bits, silence at 2048 |
| `0x1001` / `0x1002` | the carrier is up / reception resumed |
| `0x2000 \| fill` | bytes waiting in the app's ring, 0–127 |
| `0x3000 \| code` | a burst ended: 0 OK, 1 underrun, 2 denied, 3 frequency mismatch, 4 implausible length, 5 three-minute cap |

An audio sample never has its top nibble set, so a host separates the two by
value alone and the audio stays raw — which is why `aflisten.sh` still works
while the app is bridging. (`afstream.py` *skips* words ≥ `0x1000`; masking
them would make a near-full-scale spike.)

In (host → radio) is Voice TX 3.1's format: `'V','T','X','S'`, the sample count
as 32 bits little-endian, then 3-bit ADPCM, 8 codes to three bytes. A count of
`0xFFFFFFFF` is open-ended and ends when the host stops feeding (250 ms), drops
DTR, or at a three-minute cap — a PC is keying the PA, so an open burst still
has to end.

`beacon_say.py` does **not** work against this app: it waits for the ASCII line
`VTX TX`, which the bridge replaces with `0x1001` so that the audio pipe stays
parseable by value. `tools/afbridge.py` is its counterpart here.

## Pacing, which is what the duplex link is for

A live source cannot be paced the way `beacon_say.py` paces a file against a
fixed `CLOCK = 1.0062`: the host runs on its sound card's clock, the radio on
an RC oscillator a few tenths of a percent off and drifting with temperature.
And the resident port's 256-byte ring does not drop the excess when it laps —
it **flushes**, measured at 270 bytes of lead costing 273 bytes and the rest of
the burst with them.

So while transmitting, when there is nothing to receive, the outbound direction
reports the ring fill ten times a second, and `afbridge.py` servos a
feed-forward of 3000 B/s on it (integral term, ±3 %, target 40 bytes, hard
back-off above 100). 3-bit ADPCM is kept for the same reason: 0.6 % of 3 kB/s
is 19 B/s of drift to absorb, against 50 B/s for raw 8-bit.

Two consequences worth knowing. The fill reported is the *app's* 128-byte ring;
the resident 256-byte ring upstream is invisible, so a target well below 127 is
what keeps it empty. And each credit write stalls a cycle-timed loop until the
host takes two bytes — that is what `C` on screen measures, and if it ever
exceeds a sample or two the credit rate should come down.

## Why it fits, and what was dropped

Measured with `arm-none-eabi-nm -S`, the parts of AF Stream (3128 B) and
Voice TX (3740 B) that a bridge keeps add up to about 4.6 KiB. What went:

- Voice TX's whole flash-clip machinery — the 48-slot scan, the block
  prefetch, the checksums, the repeat counter, the read-time measurement;
- AF Stream's rate selector (8 kHz only, which is what the TX side runs at),
  its level bar, the RSSI, the `LVL` gate and the held-open squelch;
- both screens, replaced by four tiny lines;
- the DMA buffer, halved to 128 samples: a half is 64 samples, 8 ms at 8 kHz,
  which is the deadline for one send plus the screen and the keys.

What is kept from Voice TX is the part that took measuring: `pllfm`'s full
key-up with the frequency read back from the chip, the DDS parked at the sine's
peak and frozen, one `REG_70` gain write per sample, the IMA ADPCM decoder and
step table, and every guard — `tx_state()` refusal, the band check, the
underrun and DTR drops.

The RX side is AF Stream's: TIM3 → TRGO → ADC1 (PA4) → DMA1 channel 1,
circular, so the DMA keeps filling while `serial_write` spins. The capture is
stopped for the duration of a transmission: there is nothing to sample, and it
takes the DMA off the bus for a loop timed in cycles.

## Measured on the air, 2026-11-11

A 3.90 s clip (Piper `fr_FR-siwis-medium`, through `encode_clip.py`: 31200
samples, 11700 B of ADPCM, 17.9 dB) transmitted from a PC and heard on a second
receiver.

| | |
|---|---|
| receive path, gate open | 79616 samples in 9.99 s, one burst, 7970.5 Hz, 100 % of samples in range |
| receive path, gate closed | nothing for six seconds on a quiet channel |
| transmit, effective rate | **7938 samples/s** against the radio's own 7970 |
| stalls on a dry ring | **115**, i.e. 14.4 ms over 3.93 s, 0.37 % |
| credit write | 92 µs worst case, 0.7 of a sample period |
| the app's ring under load | 82, 97, 91 against a target of 88 |
| audio by ear | correct rhythm, no gaps |
| receive by ear, gate open | continuous, channel hiss |
| receive by ear, gate closed | silent until the far station transmits |

7970 × (1 − 0.0037) = 7940: the loop runs at the radio's own clock and the
only remaining error is those 115 stalls, which is six cents of pitch.

**Two bugs the air found, both about starvation, and the second was the
interesting one.**

A dry ring used to cost `delay_ms(1)` — eight sample periods of the gain
register held, which is both a silence gap and eight periods of stretch. It
now waits one period at a time, so an incident costs 125 µs instead of 1 ms.

Then the first bursts came out progressively slowed with gaps, and the screen
said `C1729/65535`: 1729 samples a second instead of 8000, the stall counter
saturated. 1729 samples/s is 648 B/s of ADPCM, and the host tool was sending
640 — `Link.poll()` called `ser.read(4096)` on a port with a 50 ms timeout, and
during a transmission the radio sends almost nothing, so every poll blocked for
the full timeout: 20 iterations a second times a 32-byte write. The pace the
tool printed was a number it never achieved. Reading only `in_waiting` fixed
it. Nothing in the app was wrong, and no amount of reading the app would have
found it — which is the argument for `txFs` and the stall count being on the
screen at all.

## The host tools, and what each one is for

One program at a time owns the USB port, so the modes are the ways of having
both directions at once:

| | |
|---|---|
| `tools/aflisten.sh` | listen only |
| `afbridge.py clip.wav` | send a clip, nothing else |
| `afbridge.py --fifo` | hold the port, play what is received, and transmit whatever WAV path is echoed into `/tmp/afbridge.fifo` — the one that serves day to day |
| `afbridge.py --roger clip.wav` | answer every received transmission with a fixed clip |
| `afbridge.py --parrot` | send back what was just received, as received |
| `tools/afvox.sh` | the radio as a VOX headset: speakers out, microphone in |

### Measured, 2026-11-11, second session

| | |
|---|---|
| a 23.17 s clip, three times | `OK` each time, no dry spell |
| the pacing servo over 23 s | settled at **2979.8 B/s**, i.e. a clock factor of 1.0068 |
| the radio's ring through it | 84 to 96 against a target of 88 |
| **parrot round trips** | **1.7 s, 3.5 s and 16.6 s, all `OK`** |
| the round trip by ear | *"la chaîne est nickel, je ne sens pas la différence"* |

The servo's 1.0068 is worth keeping: it was measured blind, by the host
watching the ring fill, and it lands on `beacon_say.py`'s `CLOCK = 1.0062`
(fitted by correlation against the air) and on the 7970 Hz the receive path
measures. Three independent methods inside 0.06 %.

The parrot figure is the one that bounds the whole chain, because the same
signal makes the complete round trip: AM detector, PA4 with its ~1 kHz
coupling, the ADC, the DMA and USB on the way in, then the AGC, 3-bit ADPCM at
16.8 dB, the flow control and the gain field on the way out, and the air twice.
16.6 s of that came back indistinguishable by ear from what went in. Nothing
is trimmed either - the squelch's own noise at both ends of a transmission
goes back out with the speech.

### Eight things the air corrected

All of them in the host tools, none in the app, and only one was findable
without the radio:

1. the marker went out before key-up, so a host streaming on it filled a ring
   nobody was draining - and that ring flushes;
2. `tx_end()` calls `RADIO_SetupRegisters`, so every receive after a
   transmission ran with the AGC back on;
3. a dry ring cost `delay_ms(1)`, eight sample periods of held gain - a gap
   and eight periods of stretch at once;
4. `Link.poll()` read 4096 bytes from a port with a 50 ms timeout, which
   throttled the send loop to 640 B/s against the 3000 the radio eats: the
   screen read `C1729/65535`, 1729 samples a second with the stall counter
   saturated, and the audio was heard as "chirpy";
5. the VOX keyed with the jitter buffer in the *host*, leaving the radio's own
   ring empty, so the first scheduling hiccup starved it - the file path had
   had its 192 bytes of lead all along;
6. when the radio ended a burst itself, the host kept `tx` set and its
   "let the tail out" loop never fell through, so nothing keyed again;
7. the speakers fed the microphone and the VOX answered its own loudspeaker,
   which needed the VOX held off while received audio is still playing;
8. `encode()` blocks for two or three seconds in a subprocess, which starved
   the sink because nothing pumped it meanwhile - hence `prefill()`.

## Test order

1. **Receive only**: `tools/aflisten.sh`. Audio present, `OVR 0`, and the gate
   closing on a quiet channel.
2. **`tools/afbridge.py --watch`**: the control words arrive and parse.
3. **One short counted burst from a file, at low power, monitored on a second
   receiver**, with `C` on screen watched. This is a transmitter and a
   licence: it is the operator's call, not the tool's.
4. Only then open-ended bursts, and a live microphone after that.

## Known limits

- No live-microphone mode in `afbridge.py` yet: the servo is written and the
  app accepts open-ended bursts, but the host side needs a capture thread and
  real-time AGC, limiter and resampling. `encode_clip.py`'s ablation says that
  chain is worth more than anything in the radio: 0.31 → 0.53 for the
  interpolation, 0.53 → 0.89 for the AGC and limiter.
- 8 kHz only, both ways. AF Stream remains the app for 16, 32 and 38.4 kHz.
- The gate follows the squelch bit, which `afspectro` saw stay closed on a
  strong signal on the RAW path; the screen shows `SQ?` for that pairing.
- 16 B of overlay left: anything new here has to pay for itself.
- `aflisten.sh` needs two seconds of stream before any sound comes out: it
  measures the radio's own rate first, because a sink opened at the nominal
  8000 Hz starves every half minute against a source producing 7970. A
  transmission shorter than that is only heard when the session ends.
- The gate, the AF path and the rest are saved on exit, so the defaults above
  apply to a first launch only.

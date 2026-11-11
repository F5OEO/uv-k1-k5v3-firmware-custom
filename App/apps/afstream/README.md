# AF Stream

The radio's demodulated audio out of the USB-C port, live — the mirror of
`tools/beacon_say.py`, which streams audio *in* to Voice TX.

## Use

1. Tune the VFO to whatever you want to hear, in any modulation.
2. Install the app in a free slot and launch it. It starts streaming at once.
3. On the PC: **`tools/aflisten.sh`** to just listen, or
   `tools/afstream.py --seconds 10 --out af.wav` to record, `--split` for one
   WAV per transmission, `--raw -` to pipe it somewhere else.

```sh
tools/aflisten.sh              # /dev/ttyACM0, 8 kHz
tools/aflisten.sh -r 16000     # the rate selected on the radio (key 1)
tools/aflisten.sh -g 4         # four times louder
```

```
 AF Stream                 [usb][bat]
 433.920 8000Hz RAW SQ
 FS 7952
 [######################        ]
 PP 1284                     -97dBm
 183kB OVR 0 TO 0
```

| Field | Meaning |
|---|---|
| `8000Hz` | the rate selected (key 1); `FS` is the rate the radio's clock really produces |
| `RAW` / `STK` | the AF path (key 2); `STK` by default |
| `SQ` | the squelch is held open (key 3) |
| the bar, `PP` | peak to peak of the last block, out of 4096 ADC counts |
| `*OFF` / `*SQL` / `*LVL 256` | the gate (key 4) and, for `LVL`, its threshold; the `*` is lit while the gate is open and bytes are going out |
| `kB` | bytes sent to the host |
| `OVR` | half-buffers the host was too slow for: audio lost |
| `TO` | writes the host did not take within 50 ms |

Keys: **MENU** start/stop, **1** sample rate (8 / 16 / 32 / 38.4 kHz), **2** AF
path, **3** squelch held open, **4** gate, **UP/DOWN** the `LVL` threshold,
**EXIT** quit. Everything but the stream state is saved on exit. The USB icon in the status bar means a host has the port open;
nothing is sent before that, so the app can sit waiting.

The battery indicator holds the level it had at launch — see below.

## Nothing goes out while nothing comes in

A squelch closed does not stop the stream by itself: what the chip mutes is its
AF output, so the samples keep flowing and simply read 2048. At 8 kHz that is
16 kB/s of silence. The gate, key 4, is what stops it:

| Mode | Sends while |
|---|---|
| `OFF` | always — a continuous stream, silence included |
| `SQL` | the BK4829 reports its squelch open (`REG_0C` bit 1) |
| `LVL` | the peak to peak of the last block is at or above the threshold |

`SQL` is the default, together with the stock AF path and nothing forced open:
every mechanism in that combination is known to work, and it is the radio's own
notion of reception, with its `SQL` menu setting and hysteresis behind it. It cannot be combined with key 3 holding the squelch
open — the two exclude each other and selecting one clears the other. `LVL` is
the fallback for the `RAW` path, where `afspectro` saw the squelch bit stay
closed on a signal it could hear on PA4; **UP/DOWN** move its threshold in
steps of 64 ADC counts, and the bar plus `PP` are there to pick it: it has to
sit above the noise floor, which was 700 of 4096 on the first capture made
with the squelch held open on the RAW path, so 256 would have gated nothing.

A gate that opens late cuts the first syllable, so two things soften it: the
half-buffer sent when it opens already holds up to 32 ms from *before* the
decision (at 8 kHz), and it stays open 600 ms after the signal goes, which also
carries the squelch tail. There is no real pre-roll — 0.2 s at 8 kHz is 3.2 kB
and the overlay has not got it.

The stream then arrives in bursts, and `afstream.py` counts them, measures the
rate *inside* them (a silence would otherwise read as a slow clock), reports
the share of time spent sending, and with `--split` writes one WAV per burst,
which is what you want after a night of recording. A burst boundary always
falls on a half-buffer, so the byte phase survives the gaps.

## Why this one is gapless

Every other sampling app in this tree (ACARS, POCSAG, the sondes, LaCrosse RX)
busy-waits on `cycles_48mhz` and calls `af_capture_sample()` by hand, so a
blocking `serial_write` — up to 50 ms — would eat the samples it waits through.
`kisstnc` states the rule: a frame goes out in the housekeeping slot, *"never
inside the sampling loop"*.

An overlay app is trusted native code with the peripherals, though, and the
PY32F071 can take the CPU out of the loop completely:

```
TIM3 update -> TRGO -> ADC1 (channel 4 = PA4) -> DMA1 channel 1
            -> a circular 256-sample buffer in this app's RAM
```

The resident firmware leaves all of it free: `board.c` sets the ADC to
`LL_ADC_REG_DMA_TRANSFER_NONE` with a software trigger, only DMA1 channel 2 is
taken (the K-plug UART's receive ring) and the only timer running is TIM7 (the
backlight PWM). So the DMA keeps filling while `serial_write` spins, and the
stream is sent one half-buffer behind the one being filled — the classic double
buffer. A half is 16 ms at 8 kHz, 4 ms at 32 kHz; that is the budget for one
send plus the screen and the keys, and `OVR` counts every time it was missed.

Three consequences the app has to respect:

- **`battery_sample()` is never called**: it switches the ADC to the battery
  channel, which would punch holes in the audio. The icon therefore shows the
  level as it was at launch. Nothing resident samples the ADC meanwhile — a
  modal app runs its own loop, so no timeslice runs.
- **`af_capture_close()` restores six registers**, none of them the ADC's
  trigger, the DMA channel or the timer: the app saves and restores those
  itself, along with the BK4829's AF path and squelch.
- **The screen goes out through `lcd_feed()`**, 64 bytes between two sends: a
  whole blit is 11 ms and would not fit in a half-buffer. The frame buffer is
  only redrawn once the frame it holds is out.

Claiming the serial port also locks the K5Viewer stream
(`app_overlay.c: app_serial_claim`), so the screen cannot inject itself into
the audio.

## Wire format

The ADC's 12-bit codes, little-endian halfwords, 0 to 4095, silence at 2048.
No header, no framing: a capture can start and stop at any time, and the only
cost is that the host must find the byte phase. `afstream.py` does it with the
fact that the top four bits of every sample are zero — whichever of the two
offsets puts almost nothing above `0x0FFF` is the right one, and the same test
then measures how clean the link is.

Rates on the wire: 16 kB/s at 8 kHz, 32 kB/s at 16 kHz, 64 kB/s at 32 kHz,
76.8 kB/s at 38.4 kHz (the rate the capture apps run at, and the one
`doc/doc.md`'s open question 1 wants the AF roll-off measured at).
The only USB figure measured in this tree before this app was 3 kB/s *inbound*
(`beacon_say.py`), so treat the top rate as something to verify with `OVR` and
`TO` rather than as a promise.

## What you are actually listening to

PA4: the audio the BK4829's DSP **reconstructs**, after the AF filters. Not an
IQ tap, not a raw discriminator output, not hi-fi.

- 300 Hz to 3 kHz on the stock path; `RAW` sets `REG_2B`'s bits 10:8, which
  take out the 300 Hz high-pass, the 3 kHz low-pass and the de-emphasis, and
  turns the AFC off.
- The AF output is muted while the squelch is closed, so key 3 holds the
  squelch open for the session (and restores it on exit).
- The AGC is frozen at launch, as in every capture app, so a silence is not
  amplified.
### Voice, gated, on the air

73.5 s with the gate on `SQL` while a second radio transmitted on the channel
(2026-11-11, stock AF path, 8 kHz, `--split`): **7 bursts, 46 % of the time
sending**, the rest of the wire idle. Five bursts of 3.6 to 10.3 s carry the
transmissions; two of 16 ms are the squelch flickering on something brief.

It is speech, and measurably so: the energy sits at 300–1500 Hz and falls
28 dB by 3.4 kHz (the stock path's de-emphasis), and the envelope's own
spectrum peaks at **1.6 to 2.7 Hz**, five to nine times above its 15–25 Hz
floor — syllabic modulation, which noise does not have. Peak −17.9 dBFS over
the whole recording, nothing clipped; the audio swings about ±520 of the ADC's
±2048, so roughly nine effective bits on speech.

**No half-buffer was lost.** Over the 1008 half-buffer boundaries of the two
longest bursts, not one sample step is atypical: 215 mean step at a boundary
against 218 elsewhere, and zero boundaries above the 99.9th percentile where
the rest of the signal reaches it once per thousand samples. So the −0.46 %
the host measures against a nominal 8 kHz is the radio's own clock — the same
internal RC oscillator Voice TX measured 0.62 % slow on the air
(`beacon_say.py`, `CLOCK = 1.0062`) — and not dropped audio. That is also what
makes the measured rate in the WAV header the right one to keep.

Two bursts show the audio arriving 840 ms after the gate opened: an operator
keying up before speaking, not a delay in the chain — the other three start at
once.

### Two things the first captures settled

**The gate holds.** Six seconds on a quiet channel with the gate on `SQL`:
`nothing received in 6.0 s`. Then, with the gate on `OFF` and nothing else
changed, 47616 samples in 5.98 s, one burst, 99 % of the time sending, 100 % of
samples in range. So the silence is the gate's doing and not a broken stream.

**`REG_2B`'s raw bits do what the comment says** - an untested step, as
`doc/doc.md` §9.3 flagged. The same noise floor through both paths, Welch over
2048-point segments, dB on one scale:

| Band | `RAW` (REG_2B = 0x0700) | `STK` (the VFO's own path) |
|---|---|---|
| 50–200 Hz | 78.7 | 66.3 |
| 200–400 Hz | 87.4 | 91.7 |
| 400–800 Hz | 92.8 | 95.5 |
| 800–1500 Hz | 96.0 | 94.4 |
| 1500–2500 Hz | 96.7 | 90.4 |
| 2500–3200 Hz | 96.0 | 86.1 |
| 3200–3900 Hz | 71.6 | 60.6 |

`RAW` is flat from 800 to 3200 Hz; `STK` slopes down about 4 dB an octave above
700 Hz, which is the de-emphasis, and falls 12 dB further at the bottom, which
is the 300 Hz high-pass. Both are what bits 10:8 claim to remove, and the top
end opens by 11 dB as well.

**The AF is not muted by a closed squelch here.** The `STK` capture above was
taken with the squelch *closed* - the `SQL` gate had just proved it by sending
nothing for six seconds - and the audio was still on PA4 at 1282 rms. That
bounds `sigfind`'s note that "REG_47 is muted while the squelch is closed":
whatever it applies to, it is not the FM AF output on this firmware with the
detector the VFO enabled. Key 3 is therefore a belt-and-braces measure rather
than a necessity, and the two readings were not taken simultaneously - the
squelch bit was read closed on the same quiet channel half a minute earlier.

### The PA4 coupling, measured

`doc/doc.md`'s open question 2 — a coupling around 1 kHz at PA4, which makes
long marks droop and which every edge-decoding app in this tree assumes — was
a hypothesis with no measurement behind it. The first capture this app ever
produced puts a number on it.

10.03 s of squelch-open noise on the RAW path, 8 kHz, 80128 samples
(`tools/afstream.py --seconds 10`), Welch over 2048-point segments, fitted
against a first-order high-pass:

| Band | Level, relative to 1.2–2 kHz |
|---|---|
| 20–100 Hz | −29.0 dB |
| 100–300 Hz | −14.2 dB |
| 300–700 Hz | −5.4 dB |
| 700–1200 Hz | −1.5 dB |
| 1200–2000 Hz | 0.0 dB |
| 2000–3000 Hz | −0.0 dB |
| 3000–3900 Hz | −22.4 dB |

The best first-order fit over 40–2600 Hz is **fc ≈ 1050 Hz, rms error
1.17 dB**; 700 Hz and 1500 Hz give 1.57 and 1.46 dB, 300 Hz gives 3.29 dB. So
the corner really is near 1 kHz and the slope really is first order — which is
what `sweep.c`'s remark about a near-differentiator, and LaCrosse RX's
edge-based slicer, were both betting on.

Two caveats before this is called settled. The input is the detector's own
noise, assumed flat at that point; a known tone sweep into the radio is still
the clean measurement, and this app is what makes it a five-minute job. And
the −22.4 dB above 3 kHz is *not* the chip's audio low-pass — the RAW path
takes that out — so it is either the DSP's own reconstruction band or the
8 kHz sampling nearing Nyquist. Capturing at 38.4 kHz (key 1) separates the
two, which is open question 1.

## Host side, two traps

- **The tty line discipline mangles binary.** `afstream.py` goes through
  pyserial, which puts the port in raw mode, and `aflisten.sh` runs `stty raw`
  before anything else; a bare `cat` or `aplay` reading `/dev/ttyACM0` would
  have `icrnl` rewrite `0x0D`, `ixon` swallow `0x11` and `0x13` and `isig` act
  on `0x03`. Opening the port asserts DTR, which the app needs before it sends
  anything.
- **`aplay` cannot centre or scale the stream.** The wire carries 12-bit codes
  around 2048, so played as `S16_LE` straight off the port they are quiet and
  offset by 6 % of full scale. The conversion (centre, `× 16 × gain`, clip) is
  `afstream.py`'s, and `aflisten.sh` is the wrapper that joins the two; with no
  python3 it falls back to the raw port, which plays but badly.
- **With the gate on, `aplay` underruns at every gap.** That is the gate
  working, not a fault; key 4 to `OFF` for continuous listening.
- **The radio's clock is not the PC's.** Voice TX measured it 0.6 % slow on
  the air (`beacon_say.py`, `CLOCK = 1.0062`): 0.36 s a minute at 8 kHz, enough
  to make a player stutter. `afstream.py` therefore measures the rate from the
  bytes' arrival and writes *that* into the WAV header; `--rate` only says what
  to expect.

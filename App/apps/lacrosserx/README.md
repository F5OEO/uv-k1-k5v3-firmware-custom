# LaCrosse RX

Receive-only 433.92 MHz weather-sensor overlay: it decodes the LaCrosse
**TX141** family — TX141TH-Bv2 and TX141TH-Bv3, the temperature + humidity
sensors sold with the C85845 and similar stations — straight off the AM
detector, with no SDR in the path.

The temperature-only members of the family (TX141, TX141B, TX141-Bv3) are
deliberately **not** decoded: their frames carry no check byte, and without one
a 37-bit frame cannot be told from a noise burst on this receiver.

## Use

1. Tune the VFO to **433.920 MHz** in **AM**, bandwidth **W** (the wide AM
   filter). The AM detector is enabled by the VFO, not by the app: on an FM
   channel the app shows `VFO IS NOT AM` and will decode nothing.
2. Launch **LaCrosse RX** from Apps.
3. Wait. A TX141TH-Bv2 sends one burst of twelve identical frames about every
   50 s, so the first reading can take a minute.

A reading is displayed only after the **same frame has arrived twice**, which
is free with twelve copies per burst and keeps the 8-bit check byte from
letting noise through.

```
 LaCrosse                    [bat]
 433.925 +5k RAW AUTO    RX 7
   21.4 C
 RH 54%
 ID 167 CH1 12s      -97dBm
 E8421 C1286 P212 O0
```

| Field | Meaning |
|---|---|
| `433.925 +5k` | the frequency actually tuned, and the offset applied to the VFO |
| `RAW` / `WID` / `STK` | the AF path in use (key 3) |
| `AUTO` | the offset hunt is running (key 4) |
| `RX n` | frames accepted since launch |
| `ID` / `CH` | the sensor's identifier (it changes at every battery change) and its channel |
| `12s` | age of the reading |
| `E` `C` | transitions and valid 625 µs cells seen: the front end's vital signs |
| `P` | the loudest envelope since the last clear, in ADC counts |
| `O` | samples the display work arrived too late for — zero in normal use |

Up to three sensors are kept. The selected one is shown in full, the others as
`id:temperature` on the line above the counters; **\*** selects the next one.

Keys: **UP/DOWN** offset ±1 kHz, **MENU** offset back to 0, **1** beep on a
reading, **2** clear counters and sensors, **3** AF path, **4** offset hunt,
**\*** next sensor, **EXIT** quit. The beep, the path, the hunt and the offset
are saved on exit.

## Finding the sensor

**This is the real work**, not the decoding. These sensors use a cheap SAW
resonator and sit tens of kHz off nominal: the three carriers found on air
during the v1 study were at 433.843, 433.918 and 433.965 MHz (`doc/doc.md`
§9.6), while the AM filter is about 11 kHz wide even wide open.

- The quickest way is a **spectrum**: watch 433.8–434.0 MHz until a burst
  paints a line, then tune the VFO there. The resident analyser (F + 5) exists
  only in an edition built with `ENABLE_SPECTRUM`, which these presets no
  longer are; the **Spectrum 3D** overlay app does the same job and does it
  better here, since its ridge keeps twelve sweeps of history on screen — a
  380 ms burst is still visible seconds after it ended, where a live analyser
  needs you to be looking at that instant.
- Otherwise leave **AUTO** on (key 4). It walks 0, ±5, ±10, ±15, ±20 kHz,
  moving on after 90 s without a reading, and stops wherever frames arrive.
  Covering the ladder takes about fourteen minutes, so start it and come back.
- `E` and `C` rising while `RX` stays at 0 means the burst is being heard but
  not read: wrong offset by a few kHz, or an interferer. `C` close to a
  multiple of 40 with no frame is a signal too weak for the check byte.

## Decoder

The BK4829 has no OOK mode, so this is route 2 of `doc/doc.md` §9.3: the AM
detector's envelope leaves on PA4 and the overlay samples it at **38.4 kHz**,
which puts 8 samples in a 208 µs pulse and 16 in a 417 µs one.

- **Radio.** The AGC is frozen (`set_agc(false)`) — otherwise the gain climbs
  through every gap and noise reads as a mark. `RAW` additionally selects the
  widest IF filter (`REG_43 = 0x7E2C`, ~11 kHz) and takes the 300 Hz
  high-pass, the 3 kHz low-pass and the de-emphasis out of the AF path
  (`REG_2B |= 0x0700`), with the AFC off; `WID` keeps the wide filter and the
  stock audio path, `STK` changes nothing the VFO set. Every register is
  restored on exit.
- **Slicer.** PA4 is AC-coupled around 1 kHz, so a 417 µs plateau has largely
  drooped away by its end and the pulses arrive as edges. A level threshold
  would clip the long pulses short; a Schmitt trigger on the DC-removed signal
  does not, because the droop decays towards zero and only the real falling
  edge drives the signal through `-h`. The hysteresis follows the envelope, as
  `sigfind`'s `sweep.c` does, so it works at any level. Four samples (104 µs)
  are averaged ahead of it, worth about 6 dB.
- **Polarity.** Nothing in this firmware establishes the sign of the AM
  envelope at PA4 — `acarsrx` deliberately synchronises in either polarity and
  `sigfind` only counts transitions — and a sensor that speaks every 50 s is a
  poor place to find out. So both pairings are decoded in parallel, one closing
  its cell on the rising edge and one on the falling edge; only one of them
  ever produces a frame, and the cost is a second 40-bit register.
- **Cells.** Each rising edge closes one high + low pair, i.e. one PWM symbol,
  and the bit is the pulse's **share of its own cell** rather than an absolute
  width: a sample clock 1 % off, or an AF chain that moves both edges, changes
  nothing. 417 µs high is a 1, 208 µs is a 0, and anything else — a preamble
  pulse, a glitch, the gap after the last bit — clears the register.
- **Frame.** The 40 bits shift through a register whose digest is checked at
  every bit, so a frame is read with or without its preamble (the receiver and
  the squelch need the first pulses). The check byte is a keyed LFSR digest,
  not a CRC: `lfsr_digest8_reflect(b, 4, 0x31, 0xf4)` in rtl_433's terms.
  Fields then have to be in range (id ≠ 0, humidity 1–100 %, −40 to +60 °C)
  and the frame has to arrive a second time.

The frame itself, from rtl_433's `lacrosse_tx141x` and `doc/doc.md` §9.5:
`id8 · battery_low1 test1 channel2 · temp12` (tenths of a degree Celsius,
offset 500) `· humidity8 · check8`, OOK PWM, 625 µs a cell, four 833 µs
preamble pulses, twelve copies a burst.

## Tests

```sh
test/run_tests.sh
```

`test/host_dectx141.c` builds the real decoder for the host and pushes
synthesized bursts through a model of the chain: the AM envelope, the 3 kHz
audio low-pass of the stock path, the 1 kHz PA4 coupling, noise and the 12-bit
ADC, the same model `sigfind/test/sweep_test.c` uses. It covers the ideal
envelope, the raw and stock paths, an inverted envelope on both, a weak signal
(6:1 against the noise, close to the floor), a sample clock up to 5 % off with
a narrow filter, negative temperatures, the field limits, a 41-bit Bv3 frame, a
four-copy burst, a bad check byte, a frame seen only once, and about 96 s of
pure noise, which must never produce a reading.

One case comes from outside this repository: the four rows of
`tests/lacrosse/tx141th-bv2/codes_test.txt` in `rtl_433_tests`, of which only
the first is valid. They are the slicer's output *before* rtl_433 inverts it,
so they are this decoder's bytes complemented — which is what pins the bit
order, the inversion and the digest to something not written here. The frame
reads id 231, −20.0 °C, 10 %, channel 2. It then regenerates the Flipper bench files and runs them
through the same model, so the generator and the decoder cannot drift apart.

## Flipper Zero bench frames

`test/flipper_tx141.py` writes Sub-GHz RAW files that carry the real waveform —
a TX141 is already OOK on 433.92 MHz, so unlike the ACARS bench files these are
not a substitute signal.

1. `python3 -B test/flipper_tx141.py test/flipper`
2. Copy `test/flipper/*.sub` into `subghz/` on the Flipper.
3. Tune the radio to **433.920 MHz AM**, launch LaCrosse RX, and send one file
   at a time from `Sub-GHz > Saved`.

| File | Expected result |
|---|---|
| `tx141_ref.sub` | `21.4 C`, `RH 54%`, `ID 167 CH1` |
| `tx141_cold.sub` | `-7.5 C`, `RH 88%`, `BAT LOW`, `CH2` |
| `tx141_hot.sub` | `60.0 C`, `RH 100%`, `CH3` |
| `tx141_bv3.sub` | the same reading from a 41-bit Bv3 frame |
| `tx141_two.sub` | a two-copy burst is still accepted |
| `tx141_single.sub` | nothing displayed: one copy is never believed |
| `tx141_badchk.sub` | nothing displayed, `E` and `C` rise |
| `tx141_tune.sub` | 5 s of keyed carrier to peak the offset on |

Use only a frequency your region permits, and keep the test brief: 433.92 MHz
is shared with every doorbell in the street.

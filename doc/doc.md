# RX signal paths to the MCU on the UV-K1 / UV-K5 V3

**Question:** can the MCU sample the received signal with its own ADC, and can it get IQ?

**Answers:** ADC — **yes**, it already does, on PA4, and ~15 overlay apps are built on it.
IQ — **no**. True IQ exists inside the BK4829, but no package pin brings it out.

Everything below is sourced from the firmware in this repository, from the
BK4829 and PY32F071 datasheets (in this folder, from
[armel/k1-teardown](https://github.com/armel/k1-teardown)), and from the
decompiled factory firmware in that same teardown repository. Claims that are
inference rather than fact are labelled.

---

## 1. Hardware architecture

```
antenna ──→ BK4829 (QFN32)
              │   LNA → quadrature mixer → IF/I, IF/Q → BPF → VGA
              │        → sigma-delta ADC → Do/I, Do/Q → DSP → AF DAC
              │
              ├─ SCK PB8 / SDATA PB9 / SCN PF9 ── 3-wire register bus (bit-banged GPIO)
              │     scalars only: RSSI REG_67, glitch REG_63, noise REG_65,
              │     AFC, FSK modem, DTMF, status REG_0C
              │
              └─ EARO (pin 8) ──1 µF──→ audio path ──→ PA8 audio amp → speaker
                                           │
                                           └─ PA4 = ADC_IN4  ← the only waveform tap
```

Other devices: PY25Q16HB 2 MiB SPI flash (SPI2, PA0–PA2, CS PA3), ST7565 LCD
(SPI1, PA5/PA7, A0 PA6), BK1080 broadcast-FM receiver (PF5/PF6). Board is
marked `K1-V5.0 ZG13`; a 4-pad SWD header (3V3 / SWDIO / SWDCLK / GND) is
exposed at the top edge.

### BK4829 pin inventory (datasheet §4, Table 4-1)

| Function | Pins |
|---|---|
| RF | LNAIN (15), PAOUT (17), VRAMP (18) |
| Analog audio | **EARO (8)** "Earpiece output", MICN (13), MICP (14) |
| Digital | SCK (25), SCN (26), SDATA (27), GPIO0–GPIO6 |
| Other | XI (5), XO (4), VCC (3, 11) |
| **NC** | **6, 7, 9, 10, 12, 16, 19, 20, 21, 22, 23, 24 — 13 of 32 pins** |

No IF pin. No IQ pins. No I2S or serial-audio port. 18–580 MHz and
760–1160 MHz, 26 MHz crystal, 3-wire interface up to 8 Mbps, 4 × 4 mm QFN32.

---

## 2. The ADC path that exists

### 2.1 How it works

`BOARD_ADC_Init` (`App/board.c:149`) sets up the single ADC1: 12-bit, clock
PCLK/4, software trigger, single conversion, scan off, **DMA request NONE**,
sequencer rank 1 = channel 8 (battery), sample time 41.5 cycles. `App/board.c:152`
puts PB0 and PB1 into analog mode.

The audio capture lives in `App/apps/app_overlay.c:776-812`, published to
overlay apps at API level 3 as `af_capture_open / sample / close`
(`App/apps/app_api.h:324`):

- PA4 is the MCU's **voice-DAC pin**, AC-coupled into the audio path, so it has
  no DC reference. `open` enables DAC channel 1 **with the output buffer off**
  and parks PA4 at code 2048 to create one, then points `ADC_SQR3` at channel 4
  and copies channel 8's sample time into `SMPR3`.
- `sample()` is one bounded polled conversion (SWSTART, spin on EOC, 2000-iteration cap).
- `close` restores all six touched registers; the loader also closes a capture
  an app leaves open (`app_overlay.c:1427`).
- `BOARD_ADC_GetBatteryInfo` cooperates through `APP_AfCaptureYieldAdc()` /
  `ResumeAdc()` (`App/board.c:182`), so battery reads interleave safely.

Apps pace their own loop off `cycles_48mhz()` rather than a timer.

### 2.2 What the tap carries — selectable by register

`BK4819_SetAF` writes `REG_47 = 0x6042 | (AF << 8)` (`App/driver/bk4829.c:840`).
Modes are in `App/driver/bk4819.h:25`: MUTE(0), FM(1), BASEBAND1/RAW(4),
BASEBAND2/USB(5), AM(7), BYP(9).

AIS RX is the reference example (`App/apps/aisrx/gen_assets.py`):

| Register | Value | Purpose |
|---|---|---|
| `0x47` | `0x6942` | AF mode 9 = BYP (raw discriminator) |
| `0x43` | `0x7E2C` | filter bandwidth |
| `0x73` | set bit 4 | AFC off |
| `0x2B` | set `0x0700`, clear `0x0007` | bypass the AF filters |

The same `REG_2B` incantation appears in EPIRB 406 (`epirb406_app.c:362`) and the
RS41 sonde app.

### 2.3 Rates actually achieved

| Rate | Apps |
|---|---|
| 9.6 kHz | APRS RX/TX/DIGI, KISS TNC, SSTV, ATIS DSC, EPIRB 406 |
| 19.2 kHz | ACARS, RS41 and M10 sondes |
| **38.4 kHz** | **AIS RX, AF Scope's fastest timebase** |

38.4 kHz is the highest anything in the tree does.

### 2.4 The real ceiling — and why raising it may be pointless

PY32F071 Table 5-23: FADC **1–16 MHz** max (VCC ≥ 2.3 V), tconv **12 Tclk**,
teoc **0.5 Tclk**, tsamp **3.5–41.5 Tclk**; the datasheet's own current figure
is quoted "@0.75 MSPS".

| Configuration | Rate |
|---|---|
| Current firmware: 12 MHz ADC clock, 41.5-cycle sampling | **222 ksps** |
| 12 MHz, 13.5 cycles (settling floor, see below) | ~460 ksps |
| Datasheet test point | 750 ksps |

PCLK/2 would be 24 MHz — out of spec — so **PCLK/4 is already the fastest legal
divider**.

> **Clock caveat — partly resolved, one factor of 2 still open.** The 48 MHz
> core/timer clock is now confirmed: the factory voice DAC is paced by TIM6 at
> PSC 3 / ARR 1499, which gives exactly 8000.0 Hz only at a 48 MHz timer clock
> (§6.3). But on this part TIMxCLK = 2×PCLK whenever the APB prescaler is not 1,
> so **HCLK 48 MHz with PPRE = 2 also yields exactly 8 kHz** — and the ADC clock
> would then be 6 MHz, halving the figures above to ~111 ksps and ~230 ksps.
> PPRE = 1 is the likely case but is **unverified**: the bootloader writes
> `RCC_CFGR` from a config struct rather than a literal, and `LL_USART_Init`
> derives its baud from the *measured* PCLK, so neither settles it statically.
> Reading `RCC->CFGR` bits 12–14 (`RCC_CFGR_PPRE`) on a live radio closes this
> in seconds. The teardown README's "72 MHz" is the part maximum, not the
> configured clock.

**Sample time cannot simply be shortened.** DAC output impedance with the
buffer off is **RO ≤ 15 kΩ** (Table 5-24) and ADC CIN is 5–8 pF (Table 5-23),
so τ ≈ 120 ns and 12-bit settling needs ~9τ ≈ 1.1 µs. At 83 ns per Tclk that is
**~13 cycles minimum**: 3.5-cycle sampling genuinely cannot settle, 13.5 is
about the floor, and the inherited 41.5 is conservative but safe.

**More importantly — the information ceiling is not the PY32 ADC.** The BK4829
chain is IF → sigma-delta ADC → DSP → EARO, with no analog path from the IF
section to EARO anywhere in the block diagram. So *every* AF mode, BYP
included, is **DSP output leaving through the chip's own AF DAC** (hence
`REG_30` ENABLE_AF_DAC and `REG_48` AF DAC gain). The ceiling is therefore the
BK4829's internal audio sample rate, which is undocumented. Sampling much
beyond twice that rate only oversamples a reconstructed waveform.

### 2.5 Unused capability on the MCU side

- **ADC DMA and timer triggers exist and are unused.** `LL_SYSCFG_DMA_MAP_ADC1`
  is defined, as are triggers TIM1_CH1/CH2/CH3, TIM2_CH2, TIM3_TRGO,
  TIM15_TRGO and EXTI line 11. Of 7 DMA channels, 2 (USART1 RX), 4 and 5
  (SPI2 flash) and 7 (backlight TIM7) are taken — **1, 3 and 6 are free**.
  Timer-paced block capture into RAM would remove the polling jitter.
- **PA4 also carries COMP1_INP8 / COMP1_INN4 / COMP2_INP4.** An analog
  comparator sits on the same pin, so a 1-bit slicer or zero-cross detector
  feeding timer input capture is available with no ADC load at all — a
  plausible low-CPU path for FSK or CW.

---

## 3. Why there is no IQ

### 3.1 It exists, on the die

BK4829 datasheet §2.3, *FM Receiver*:

> "The RF front-end comprises a LNA and a **quadrature mixer**… the
> down-converted **in-phase IF signal (IF/I) and quadrature-phase IF signal
> (IF/Q)** are first filtered by the BPF, and then amplified by the VGA. The
> **Sigma-Delta ADC** samples analog IF signal from VGA, and converts it to
> digital IF signal. Then the digital signal will be sent to DSP for second
> down-conversion and audio processing."

Figure 2-2 draws `LNA → Mixer → IF/I, IF/Q → Filter+VGA+ADC → Do/I, Do/Q → DSP`.
A genuine low-IF image-reject receiver with digital IQ internally.

### 3.2 No pin brings it out

See the pin inventory in §1. Do/I and Do/Q never leave the die. The only two
BK4829 → MCU connections on this board are the EARO analog node and the 3-wire
register bus.

### 3.3 Could IQ come out over the register bus?

Bandwidth alone does not rule it out:

| | Rate |
|---|---|
| Today's bit-bang (`bk4829.c`, 40 NOPs per half-bit; 24 bits ≈ 40 µs) | ~25k reads/s |
| Datasheet 3-wire maximum, 8 Mbps | ~330k reads/s |

Decimated narrowband complex baseband (~50 kS/s IQ ≈ 100k reads/s) would fit
inside the spec rate. The actual blockers are that **no documented register
exposes samples** — Beken's public datasheet contains no register map at all —
and that unlatched reads of a free-running signal would jitter.

**Cheap decisive test:** with the radio idle and a carrier present, sweep
read-only across unused addresses in the 7-bit register space looking for a
value that tracks the signal. Build with `ENABLE_UART_RW_BK_REGS` (UART
commands `0x0601` read / `0x0602` write, `App/app/uart.c:692`) to do it from
the host without reflashing. **Skip REG_02 (IRQ flags) and REG_5F (FSK FIFO) —
those reads have side effects.** Prior odds are low.

The BK4829 GPIOs are not an alternative: the datasheet documents them as plain
general-purpose I/O with internal pull-downs, with no internal-signal routing.
The firmware allocates GPIO0 (RX enable), GPIO1 (PA enable), GPIO3 (UHF LNA),
GPIO4 (VHF LNA), GPIO5 (red LED) and GPIO6 (green LED) via `REG_33`
(`BK4819_ToggleGpioOut`, bit = `0x40 >> Pin`), leaving one bit unused.

### 3.4 What real IQ would require

1. **External hardware** — tap the IF and feed an outboard quadrature mixer, or
   bolt on a separate SDR front end. Nothing inside the BK4829 is accessible.
2. **Two analog inputs.** PA0–PA7 are fully committed (SPI2 on PA0–PA2, flash CS
   PA3, AF tap PA4, SPI1 on PA5/PA7, LCD A0 PA6). PB0 is the battery input.
3. **Accepting no simultaneous sampling.** There is **one** ADC — `ADC2` does
   not appear in `Drivers/CMSIS/Device/PY32F071/Include/py32f071xB.h`, and the
   datasheet contradicts itself ("Two 12-bit ADC" on the front page vs "one
   12-bit ADC" in the overview). I and Q would have to alternate conversions
   and absorb the phase skew.
4. **Living in 16 KiB of RAM**, 4 KiB per overlay app, on a Cortex-M0+ with no
   FPU and no DSP extensions.

---

## 4. Corrections to earlier assumptions

| Assumption | Correction |
|---|---|
| EARO is an analog tap off the demodulator | It is a **DAC output fed by the DSP**. Every AF mode, BYP included, is reconstructed audio. The information ceiling is the chip's internal AF rate, not the PY32 ADC. |
| The ~1 kHz high-pass is the board's AC coupling | The reference design couples EARO through **1 µF**, far too large for a 1 kHz corner. See the hypothesis in §5. |
| DMA on the ADC would move the wall to RAM | It removes jitter, but §2.4 means extra rate buys little until the chip's AF rate is measured. |
| PB1 / ADC_IN9 is a spare input worth using | The **factory** firmware also writes `current = 0` — see `FUN_0800dcfc`, the stock equivalent of `BOARD_ADC_GetBatteryInfo`. The second return value is a vestigial API from the DP32G030 era; neither firmware ever reads IN9. |
| The factory ADC function is at `0x0800b4fc` | **Wrong address.** That came from the teardown RetDec dump, whose addresses are all shifted — see §6.1. The true address is `0x0800dcfc`, and `0x0800b4fc` is not a function entry at all. |
| ~220 ksps was an estimate | Now backed by datasheet Table 5-23 (§2.4). |

---

## 5. Open questions and experiments

1. **What is the BK4829's internal AF sample rate?** This sets the ceiling for
   every current and future capture app, and it bounds everything else - run
   it first (ordering argument in §7.5). Method: BYP mode, squelch open on
   noise, fastest capture available, then look for the AF DAC's roll-off or
   reconstruction images in the spectrum. For scale, the factory voice DAC
   runs at exactly 8 kHz (§6.3); if the receive side is the same order, it
   caps symbol rates well below what the IF filter would allow.
2. **Where is the ~1 kHz high-pass?** `App/apps/aisrx/aisrx_app.c:454` describes
   it making long bit runs droop. *Hypothesis:* it is formed at PA4 itself —
   15 kΩ of buffer-off DAC output impedance against a ~10 nF coupling cap gives
   ~1 kHz. Unverified; confirming needs a K1 schematic, which the teardown
   repository does not include.
3. **Is there an undocumented sample register?** See the sweep in §3.3.
4. **Does timer + DMA capture work in a 4 KiB overlay?** DMA channels 1, 3 and 6
   are free — and the factory firmware already runs exactly this pattern in the
   other direction (TIM6 → DMA1 ch3 → DAC, §6.3), which is encouraging.
5. **What is the APB prescaler?** One live read of `RCC->CFGR` bits 12–14
   decides whether the ADC ceiling is ~222 ksps or ~111 ksps (§2.4).
6. **Does REG_43 `<5:4> = 11` widen the IF filter?** The one unexplored margin
   on receive bandwidth. Protocol in §7.4.
7. **Is the 48 MHz system clock HSI or crystal-derived?** Decides whether
   on-board timekeeping is good enough for the Doppler options 2 and 3 in §8.3.
   One read of `RCC->CR`/`CFGR` settles it.
8. **Does a sub-kHz retune re-lock without the REG_30 toggle, and is the toggle
   audible?** Bounds how smooth any Doppler correction can be (§8.4).
9. **What does one BK4819 register read actually cost, and how often does RSSI
   really update?** **Answered on the sibling BK4819 radio - see §9.6 - and the
   answer kills route 1 there.** RSSI is low-passed with a 2.3-3.8 ms time
   constant (autocorrelation on noise, confirmed at +30 dB SNR), so a 625 µs
   bit cell survives in it at 0.04 dB; and the read cost was 4.4x the figure
   counted from the source. Both still have to be re-measured *here*, the
   BK4829 being a different die behind a different MCU: time 1000 reads of
   REG_67 with `cycles_48mhz` (`App/apps/app_api.h:335`) for the bus cost, then
   take the autocorrelation of a block of back-to-back reads on noise rather
   than counting identical runs - run length conflates the register's response
   with the quantisation, the ACF does not.

---

## 6. Second analysis: independent Ghidra decompilation

The teardown repository ships a **RetDec** decompilation
(`openocd/fw_decompiled.c`, `fw_annotated.c`, `fw_function_map.txt`). To check
the findings above against a second tool, the same flash dump was re-analysed
with **Ghidra 12.2** headless. Scripts and output are in `doc/ghidra/`.

### 6.1 The teardown RetDec dump is offset by 0x2800 — and has no bootloader

RetDec was run on `K1_PY32F071_firmware.bin` (120,832 B = 0x1D800, the
application region) loaded at base `0x08000000`. That image actually lives at
`0x08002800`, so **every address in the RetDec output is 0x2800 too low**, and
the bootloader is absent entirely.

| RetDec address | + 0x2800 | Ghidra |
|---|---|---|
| `function_800b4fc` (ADC read) | `0x0800dcfc` | `FUN_0800dcfc`, identical code |
| `function_800cf34` (DAC / PA4) | `0x0800f734` | `FUN_0800f734`, identical code |
| highest address `0x801242c` | `0x08014c2c` | app ends `0x08014d0f` |

Disassembling real `0x0800b4fc` gives `adds r1,#245 / movs r0,#1 / bl …` —
mid-function code with no prologue. That is evidence *for* the offset (a RetDec
address read naively as a flash address lands in the middle of an unrelated
function), not evidence that RetDec invented a boundary; RetDec never claimed a
function at real `0x0800b4fc`.
**When correlating the teardown decompile with a live radio or with this
repository, add 0x2800.**

### 6.2 Tool comparison

| | RetDec (teardown) | Ghidra 12.2 (here) |
|---|---|---|
| Input | app image only, mis-based | full 128 KiB dump at `0x08000000` |
| Functions, default settings | 468 | 520 = 103 bootloader + 417 application |
| Functions, tuned (§6.6) | — | **583 = 107 bootloader + 476 application** |
| Code coverage of app region | not reported | 61.8 % default → **74.9 % tuned** |
| Peripheral constants | resolved (`g1350 = 0x40012400`) | unresolved by default — fixed by `LabelPeriph.java` |
| Failures | not reported | 17 of 583 functions |

Neither tool is strictly better: RetDec folds literal-pool constants and finds
more code, Ghidra gives reliable xrefs and a clean bootloader. Labelling the
152 literal-pool peripheral pointers from this repository's own CMSIS header
gives Ghidra the first of those. See §6.6 for why the counts differ.

### 6.3 What the second pass confirmed, and one new number

- **The ADC read** (`FUN_0800dcfc`): `|0x500000` (SWSTART | EXTTRIG), poll SR
  bit 1, clear, read `+0x50` (DR), then `*param_2 = 0`. The factory firmware
  hardcodes "battery current" to zero.
- **The stock ADC init** enables only `GPIOB` MODER bits 0–1 (PB0 analog) and
  sets EXTSEL = software trigger. It does not configure PB1.
- **PA4 is the DAC node, named rather than inferred** (`FUN_0800f734`):
  `GPIOA = GPIOA & 0xfffffcff | 0x300` is MODER bits 8–9 = analog = PA4.
- **Stock leaves the DAC output buffer ON**, clearing `BOFF1`; F4HWN's
  `af_capture_open` sets it to turn the buffer **off**. That is deliberate — a
  buffered DAC output would fight the incoming audio — and it is why the 15 kΩ
  buffer-off output impedance behind the §5 high-pass hypothesis applies to the
  capture configuration specifically.
- **New: the factory voice path is TIM6 → DMA1 channel 3 → DAC at exactly
  8 kHz.** `FUN_0800f82c` sets TIM6 PSC = 3, ARR = 1499 (literal at
  `0x0800f850`), CR2 MMS = 010 (update → TRGO); `FUN_0800f7a4` wires DMA1 ch3
  into `DAC + 0x08` (DHR12R1), and DAC TSEL1 = 000 is
  `LL_DAC_TRIG_EXT_TIM6_TRGO`. 48 MHz / (4 × 1500) = 8000.0 Hz.
  Two consequences: it pins the timer clock at 48 MHz (§2.4), and DMA channel 3
  is one of the three F4HWN leaves free — the factory firmware already runs the
  timer+DMA pattern §2.5 proposes, just in the opposite direction.
  **This 8 kHz is the MCU's playback rate, not the BK4829's internal AF rate;
  open question 1 in §5 stands.**

### 6.4 Peripheral census

A static scan of the dump for word-aligned flash literals holding a peripheral
address (tool-independent, so it does not depend on what any decompiler
reached):

```
periph     boot   app        periph       boot   app
RCC          10    18        DAC1            0     4
USBD         12    12        SYSCFG          1     3
GPIOB         2    15        TIM6            0     3
GPIOF         1    15        TIM2            0     2
DMA1          2    10        SPI1            0     2
GPIOC         3     4        ADC1            0     2
USART1        2     4        USART2/3/4      0     1 each
EXTI          3     3        ------------------------
SPI2          0     5        TOTAL          43   107
FLASH_R       5     0
PWR           2     2
```

**No pointer to COMP, OPA, TIM1, TIM3, TIM7 or TIM14-17 anywhere.** ADC1 appears
twice (init + read), matching a factory firmware that uses the ADC for nothing
but the battery. FLASH_R is bootloader-only (5 / 0), as expected for USB-C
flashing. USBD is split evenly (12 / 12) because the **same USB CDC stack is
linked into both images** - see §6.7.

Caveats: this counts literals only, so anything reached by base+offset
arithmetic is invisible; and SYSCFG / COMP1-3 / OPA sit only 0x10-0x300 apart,
so attribution within that cluster is unreliable. (An earlier unaligned version
of this scan produced a phantom `COMP3` hit from the data word `0x400102ef`.)

### 6.5 Reproducing it

```sh
GHIDRA=/media/hp-z2-dev/Variste/Doc/opt/ghidra_12.2_PUBLIC
$GHIDRA/support/analyzeHeadless <project-dir> K1 \
  -import K1_PY32F071.bin \
  -processor ARM:LE:32:Cortex \
  -loader BinaryLoader -loader-baseAddr 0x08000000 \
  -scriptPath doc/ghidra \
  -preScript  SetupPy32.java \
  -postScript SeedPrologues.java \
  -postScript LabelPeriph.java doc/ghidra/periph_table.txt \
  -postScript ExportAll.java  <output-dir>
```

`SetupPy32.java` adds the SRAM / PERIPH / IOPORT blocks the raw dump lacks,
enables the Aggressive Instruction Finder and seeds both vector tables;
`SeedPrologues.java` then creates a function at every unclaimed `push {..,lr}`
and re-analyses so Ghidra follows the direct calls those functions make,
looping until stable; `LabelPeriph.java` names the peripheral bases and types
the literal-pool pointers; `ExportAll.java` writes the function map and the
decompilation. `periph_table.txt` is generated from
`Drivers/CMSIS/Device/PY32F071/Include/py32f071xB.h`.

**Known limits:** 17 of 583 functions fail to decompile, roughly a quarter of
the application is still not claimed as code, and the run emits many "unable to
resolve constructor" warnings where data sits in code regions — normal for a
raw dump with no section map.


### 6.6 Why the function counts differ, and closing the gap

**The diagnosis (default settings).** 468 against 417 in the same application
region. Comparing entry-point sets after correcting the 0x2800 offset: 392
agree, 76 RetDec-only, 25 Ghidra-only. The 76 break down as:

| Class | Count | Verdict |
|---|---|---|
| Real Thumb prologues in space Ghidra never disassembled | **57** | Ghidra missed them |
| Non-prologue addresses in unclaimed space | 11 | likely RetDec false positives (data as code) |
| Branch targets inside one host function (`FUN_08004fbc`) | 5 | RetDec over-split a state machine |
| Real prologues merged into a neighbour | 3 | Ghidra over-merged |

**Root cause: recursive-descent coverage.** Ghidra's default analysis walks
outward from entry points and direct calls. Of the 57 missed functions, 42 *are*
direct `BL` targets — but for **38 of them every call site lies in code Ghidra
never disassembled**. One unresolved indirect dispatch (a function-pointer
table, or a switch whose jump table could not be recovered) severs the whole
subgraph behind it. In aggregate Ghidra claimed only 46,394 of 75,024 bytes
(61.8 %) of the application. RetDec augments recursive descent with
pattern-based function detection, which finds prologues whether or not anything
reachable calls them — at the cost of the 11 false positives and 5 splits.

**The fix.** Two changes, both in the scripts in `doc/ghidra/`:

1. Enable Ghidra's non-default **Aggressive Instruction Finder** (`SetupPy32.java`).
2. **`SeedPrologues.java`** — create a function at every unclaimed
   `push {..,lr}`, then call `analyzeChanges` so Ghidra follows the direct
   calls those functions make; loop until no new function appears.

Step 2 must promote addresses the finder has *already* turned into code but
left outside any function — skipping those was a bug in the first version of
the seeder and cost 15 functions.

**Result:**

| | default | tuned |
|---|---|---|
| Functions, application | 417 | **476** (RetDec: 468) |
| Functions, total | 520 | **583** |
| Application coverage | 61.8 % | **74.9 %** |
| Entry points agreeing with RetDec | 392 | **443** |
| RetDec-only | 76 | **25** (16 unclaimed, only **6** real prologues) |
| Ghidra-only | 25 | 33 |

Ghidra now finds more application functions than RetDec and agrees with it on
443 entry points. Six real prologues remain unclaimed, and about a quarter of
the application is still not decoded as code — the residue of indirect dispatch
that neither tool fully resolves. The three functions this document relies on
(`FUN_0800dcfc`, `FUN_0800f734`, `FUN_0800f82c`) are present and unchanged in
both passes.
### 6.7 The factory application has its own USB CDC stack

USB is not bootloader-only. The nine functions touching the USBD peripheral in
the bootloader have an exact counterpart in the application - same sizes, same
xref counts, same order:

```
0x08000fbc / 0x08011820  324 B      0x08001804 / 0x08012a60   66 B
0x080014c8 / 0x08012724   28 B      0x08001850 / 0x08012aac   96 B
0x080016a8 / 0x08012904   76 B      0x080018bc / 0x08012b18  160 B
0x080016fc / 0x08012958   48 B      0x08001bdc / 0x08012e38   18 B
0x08001730 / 0x0801298c  204 B
```

Of those 1020 bytes, eight functions are **bit-for-bit identical**; the ninth
differs in 17 bytes, all inside relative branch immediates - the signature of
the same object linked at a different address.

The descriptor block is duplicated too: `0x08002000` in the bootloader,
`0x080132b4` in the application, identical over the first 0x80 bytes.

```
12 01 00 02 ef 02 01 40 b7 36 01 00 00 01 01 02 03 01
```

USB 2.0; `bDeviceClass` EF / 02 / 01 is the Interface Association Descriptor
signature of a **CDC composite** device; VID **0x36B7**, PID **0x0001**;
64-byte EP0. The configuration descriptor that follows declares
`wTotalLength` 75 and **2 interfaces** (CDC control + data), bus-powered,
100 mA, with CDC header (`05 24 00`) and union (`05 24 06`) functional
descriptors present in both copies.

So the factory application enumerates as a USB CDC ACM serial port in its own
right - the native path for host tools in normal mode, separate from the
bootloader's flashing mode. This firmware does not reuse that stack: it builds
its own from CherryUSB (`Middlewares/CherryUSB/`, `App/usb/usbd_cdc_if.c`,
`App/driver/vcp.c`) under `ENABLE_USB`.

**It is started unconditionally at boot.** Two independent confirmations:

1. The application's *own* vector table carries a USB interrupt handler.
   Slot 47 (`0x080028bc`, = IRQ31 = `USB_IRQn` per `py32f071xB.h`) holds
   `0x08011971`, i.e. `FUN_08011970`, which is the only USB function with no
   ordinary caller.
2. The init path from reset contains no conditionals:

```
reset vector 0x080028d5
  -> 0x080028d4  ldr r0,[pc,#16] ; 0x08011811 / blx r0     low-level init
                 ldr r0,[pc,#16] ; 0x080028c1 / bx  r0
  -> 0x080028c0  mov sp,#0x200032c0 / bl 0x0800319c        .data + .bss
                 ldr r0,[pc,#0]  ; 0x08012509 / bx  r0
  -> FUN_08012508   factory main()
     -> FUN_0800f5c8    board init aggregator
        -> FUN_0800f734 (the PA4 / DAC setup of SS6.3)
        -> FUN_08010a0c -> FUN_0801236c -> FUN_08012dfc -> USB
```

Every edge is a straight-line call, and the whole chain runs before `main`
reaches its first boot-mode branch. Note that reset reaches `main` through
`bx r0` on a literal, not a direct call, which is why Ghidra's call graph
never linked the two.

`FUN_08012508` is clearly the ancestor of this repository's `Main()`: it calls
`FUN_0800dcfc` (the ADC battery read) with a pointer pair, then fills a
four-entry array with `FUN_0800dcfc(i * 2 + base, ...)` - the uint16_t stride
of `App/main.c`'s `for (i = 0; i < ARRAY_SIZE(gBatteryVoltages); i++)
BOARD_ADC_GetBatteryInfo(&gBatteryVoltages[i], &gBatteryCurrent);` - before
branching on two flags the way `BOOT_GetMode()` does.

## 7. Receive bandwidth: the ceiling, and how to measure it

Separate axis from §2 (which is about getting *samples* into the MCU). This is
about how much *spectrum* the BK4829 will pass before the samples are taken.
It decides whether any wideband digital mode is receivable at all.

### 7.1 The documented ceiling is already in use

`BK4819_SetFilterBandwidth` (`App/driver/bk4829.c:636-726`) decodes REG_43:
bits `<14:12>` set the RF filter from 2.0 to 5.5 kHz, **doubled when `<5>` is
set**, and `<5:4>` selects the channel mode (`00` 12.5k, `01` 6.25k,
`10` 25k/20k).

The firmware presets do not use the maximum; the data apps do:

| source | REG_43 | resulting RF filter |
|---|---|---|
| preset `BW_WIDE` | `0x3028` | 3.5 kHz x2 = 7 kHz |
| Spectrum3D (`spectrum3d/gen_assets.py:31`) | `0x3628` | 3.5 kHz x2 = 7 kHz |
| **AIS RX, RS41** (`aisrx/gen_assets.py:52`) | `0x7E2C` | **5.5 kHz x2 = 11 kHz** |

`aisrx/gen_assets.py:47` calls `0x7E2C` "the widest IF filter". So **11 kHz of
baseband (~22 kHz RF) is the ceiling of the documented field**, and an app
already sits on it.

### 7.2 The audio filters are *not* the limit

Worth knowing, because it is counter-intuitive. REG_2B is documented at
`bk4829.c:1179-1186`:

```
bit10: Disable AF Rx HPF300
bit 9: Disable AF Rx LPF3K
bit 8: Disable AF Rx de-emphasis
```

The data apps write `REG_2B |= 0x0700`, switching all three off; the AFC goes
too (REG_73 bit 4). Without that the path would be capped at 3 kHz. This is
why AIS can decode 9600 baud. The AF chain is therefore not the wall - the IF
filter is.

### 7.3 The only unexplored margins

- **REG_43 `<5:4> = 11`.** The driver table lists only `00`, `01` and `10`.
  Since `<5>` is also the x2 doubler, `11` might be a wider mode, or invalid.
  One register write settles it.
- **REG_43 `<3>` and `<1:0>`**, marked "remain undocumented here"
  (`bk4829.c:681`).

Against this, the datasheet (BK4829 SS1.1) advertises channel spacings of
12.5 / 25 / 6.25 / 20 kHz. 25 kHz is the design envelope of a low-IF receiver
whose channel filter, sigma-delta ADC and decimator are all sized for it, so
the prior against a hidden wider mode is strong.

### 7.4 Measuring the real IF response

Doable without reflashing, and it replaces all conjecture:

1. Build with `ENABLE_UART_RW_BK_REGS`, which adds UART commands `0x0601`
   (read) and `0x0602` (write) for any BK4819 register (`App/app/uart.c:692`).
2. Inject a carrier from a signal generator or a second radio and sweep its
   offset +/- 30 kHz around the tuned frequency.
3. Watch the demodulated level in the **AF Spectro** app.
4. Repeat for `REG_43 = 0x7E2C`, then `0x7E3C` (`<5:4> = 11`).

That yields the actual IF response curve, and a definitive answer on mode `11`.

### 7.5 Consequence for wideband protocols, and the right order

Worked through for FLARM and ADS-L (both 868 MHz, both inside the chip's
760-1160 MHz range and the firmware's 840-1300 MHz band 2,
`App/frequencies.c:28` - so frequency is not the obstacle):

| | occupied BW | symbol rate |
|---|---|---|
| FLARM | ~250 kHz (±50 kHz dev) | ~100 kbit/s |
| ADS-L M-band | ~250 kHz (±50 kHz dev) | 100 kbit/s, Manchester |
| **ADS-L O-band** (869.525 MHz) | **~40-60 kHz** (±10 kHz dev, GFSK BT 0.5) | **38.4 kbit/s** |
| available here | ~22 kHz RF | 1.2 kbit/s via the chip's FSK modem |

FLARM is out by a factor of 10 to 25. ADS-L O-band is out by only 2 to 3 -
close enough that §7.3's untested mode matters. Note also that ADS-L is an
open EASA specification, so unlike FLARM there is no legal obstacle to
decoding it.

**But winning the bandwidth argument would not be enough**, and this sets the
order of work: even with a 44 kHz RF filter, 38.4 kbit/s has to cross an AF
path whose internal rate is unmeasured and may be ~8-16 kHz (§6.3: the factory
voice DAC runs at 8 kHz), while the chip's own FSK modem tops out at 1.2 kbit/s
(`bk4829.c:1135-1143`). **Measure the internal AF rate (open question 1) before
spending any effort on the IF filter** - it bounds everything downstream.


### 7.6 Second worked example: io-homecontrol (Somfy / VELUX)

The protocol behind Somfy, VELUX and SIMU shutters, awnings, pergola motors and
remotes - and behind the ESPHome component `laberning/home_io_control`, whose
device matrix lists about twenty confirmed devices, with as many again
reported, partial or listen-only. Same exercise as §7.5.

| | value |
|---|---|
| channels | 868.25 / 868.95 / 869.85 MHz |
| modulation | 2-FSK, NRZ, UART-framed bytes (start / 8 LSB-first / stop) |
| symbol rate | **38.4 kbit/s** |
| deviation | ±19.2 kHz |
| occupied BW | **~77 kHz** (Carson: 2 x (19.2 + 19.2)) |
| frame | 11-32 B: 2 control bytes, 3 B dest + 3 B source node ID, command, data, rolling code, 6-byte truncated AES-128 MAC, CRC-16/KERMIT |
| available here | ~22 kHz RF, 1.2 kbit/s via the chip's FSK modem |

Frequency is again not the obstacle - 868 MHz sits in band 2
(`App/frequencies.c:28`). The verdict:

- **TX is the decisive one, and it settles the device matrix.** Operating a
  device means transmitting, and the 2-way devices expect an ACK from the
  controller as well. The PA and output LPF here are 2 m / 70 cm, and 868 MHz is
  a non-amateur SRD band with listen-before-talk and duty-cycle limits
  (EN 300220, as the protocol's own link-layer notes state). Nothing in §7.3 or
  open question 1 changes that: **control is out, categorically.**
- **Bandwidth**, for receive: the two tones sit at ±19.2 kHz, entirely outside
  today's ±11 kHz baseband filter - about 3.5x short on occupied bandwidth.
  Even if §7.3's untested REG_43 mode `11` doubled the filter, it would still be
  ~1.75x short. Unlikely to close it, but untested.
- **Symbol rate**, for receive: the chip's own FSK modem tops out at 1.2 kbit/s
  (`bk4829.c:1135-1143`), so hardware framing is out - but that is not the
  fallback that matters. Software demodulation from the discriminator tap is
  exactly how the AIS app reads 9600 bit/s GMSK (§7.2,
  `App/apps/aisrx/aisrx_app.c:18`). Receiving io-homecontrol is therefore the
  same open case as ADS-L O-band, at the same 38.4 kbit/s, and bounded by the
  same unmeasured internal AF rate (open question 1) - just with 2x the
  deviation to pass.
- **Not the obstacles**: AES-128 and a 6-byte truncated MAC are cheap on the
  M0+; the per-device `system_key` has to be extracted from a vendor remote or
  hub (TaHoma, KLR 200/300), which is a procedure, not a resource limit.

So the two halves part company. **Receiving** is the ADS-L O-band question with
a wider deviation: blocked today by the IF filter, and worth revisiting only
after open question 1. **Controlling anything in that device matrix** needs a
transmitter this radio does not have and may not legally be - which leaves an
external SX1262 / CC1101, at which point the ESP32 host of the upstream project
is the simpler build.

The PHY figures above are community reverse engineering
(`Velocet/iown-homecontrol`); the official specification is restricted to
io-homecontrol alliance members.


## 8. Tuning resolution, and Doppler correction

A third axis, independent of §2 (getting samples in) and §7 (how much spectrum
gets through): how *finely* the receiver can be placed. This one comes out in
favour of the hardware.

### 8.1 The step is 10 Hz

`BK4819_SetFrequency` (`App/driver/bk4829.c:754`) writes the frequency into
REG_38 (low 16 bits) and REG_39 (high 16 bits) in **units of 10 Hz** - the
register's own unit, and the unit every frequency in the firmware is stored in (hence `BX4819_band2_upper = 130000000` for 1300 MHz,
`App/frequencies.c:25`). The UI exposes the same floor: `gStepFrequencyTable`
(`App/frequencies.c:66`) starts at `STEP_0_01kHz = 1`, i.e. 10 Hz, and runs up
to 500 kHz.

10 Hz is a programming granularity, not an accuracy. A few ppm of
reference-crystal error is a fixed offset of a much larger order - 3 ppm is
1.3 kHz at 435 MHz - so the fine step is only worth having together with a
calibration offset.

### 8.2 Doppler fits inside it with room to spare

| band | Doppler at LEO | peak rate near TCA |
|---|---|---|
| 145 MHz | ±3.5 kHz | ~30 Hz/s |
| 435 MHz | ±10 kHz | ~100-150 Hz/s |

(overhead pass, ~800 km; an ISS-altitude pass is roughly twice those rates)

10 Hz at 435 MHz is 0.023 ppm, two to three orders finer than needed. Holding an
FM downlink inside ±300 Hz means one retune every 2-5 s at the worst point of a
pass. Resolution is not the limit; the time source and the orbit propagator are.

### 8.3 Three implementations, by increasing cost

1. **Host-driven.** The PC or phone runs SGP4 and the radio only obeys, so
   neither the MCU clock nor on-board TLEs matter. The primitive already exists:
   `CMD_0602_WriteBK4819Reg` (`App/app/uart.c:717`) writes any BK4819 register,
   and the dispatcher is port-agnostic, so it works over USB CDC
   (`UART_PORT_VCP`) as well as the K-plug UART. Two caveats:
   - `ENABLE_UART_RW_BK_REGS` is `false` in the `default` preset and no edition
     overrides it (`CMakePresets.json:103`), so this is a build-it-yourself
     path, and by the preset file's own policy an unsupported one. It is the
     same flag §7.4 needs.
   - Poking REG_38/39 does not hold. `RADIO_SetupRegisters`
     (`App/radio.c:792`, the write at `:855`) retunes from
     `gRxVfo->pRX->Frequency`, and `RADIO_SetTxParametersEx` (`:1048`, write at
     `:1077`) from `gCurrentVfo->pTX->Frequency`. `RADIO_SetupRegisters` has
     some twenty call sites - key actions (`App/app/action.c:204,224,602`), scan
     steps (`App/app/chFrScanner.c:960,1011,1164`), end of transmit
     (`App/apps/app_overlay.c:890`), app launch and exit, and the main loop
     (`App/app/app.c:731,1180,1613`) - so anything that calls it overwrites the
     correction; and a bare write skips the REG_30 off/on
     toggle that `SetF` (`App/app/spectrum.c:445`) uses to re-lock the PLL, so
     the host would have to send 38, 39, then REG_30 = 0 and REG_30 = value.
     Good enough for an RX-only experiment.

   The clean version is a dedicated command that writes the **VFO** frequency
   and calls the existing retune, so TX picks up the corrected uplink too -
   which is what FM satellites need, being split V/U.
2. **Precomputed Doppler curve.** A list of (t, delta-f) points for one pass,
   played back from a keypress at AOS. No SGP4, no TLEs, no time entry, and the
   overlay API already has what it needs: `bk_read`/`bk_write` for REG_38/39 and
   REG_30, `rx_freq`/`tx_freq` for the uncorrected centre, and `ticks_ms` for
   the timebase (`App/apps/app_api.h:193-201, 261`). The catch is delivery: app
   assets are **read-only** (`asset_read`, same file), so a table shipped that
   way means repacking and reflashing the app for every pass. A handful of
   polynomial coefficients entered on the keypad, or computed from an AOS/LOS
   and a TCA offset, avoids that and costs less than 3840 B of assets.
3. **On-board SGP4.** Does not fit the 4 KiB overlay budget, and soft-float
   double on an M0+ costs real resident flash - plus it needs TLE and clock
   entry. The most work for the least gain.

### 8.4 What has to be settled on hardware

- **Clock source**, for options 2 and 3 only: `APP_SystemClockConfig`
  (`Core/Src/main.c:68`) just calls `LL_SetSystemCoreClock(48000000)` under the
  comment "Bootloader has setup clock for us". §6.3's TIM6 arithmetic pins the
  *rate* at 48 MHz but says nothing about the source, and there is no RTC and no
  clock feature anywhere in the firmware.
- **Whether a small retune re-locks cleanly**, i.e. whether the REG_30 toggle is
  needed for a sub-kHz step and whether it mutes or clicks. Hence the threshold
  approach above rather than continuous retuning.
- **Reference calibration**, per §8.1 - without it the correction lands on a
  fixed error larger than itself.


## 9. OOK: the case that fits

Worth stating after §7.5 and §7.6, because it is the counter-example. On-off
keying - 433 MHz remotes, doorbells, weather stations, and keyed-carrier Morse -
sits inside the limits that ruled out §7.5 and §7.6, and one app already does it.

### 9.1 A keyed carrier is already received on hardware: `sigfind`

**`App/apps/sigfind/sweep.c` is the precedent that matters.** Its ELT detector
samples PA4 at **9.6 kHz**, paced by `cycles_48mhz` (`CYC_PER_SAMPLE = 5000`) in
50 ms windows through `af_capture_open/sample/close`
(`sigfind_app.c:478-493`, `:514`), and per sample it does exactly what an OOK front end
does: DC removal (IIR, ~24 Hz corner), an **amplitude envelope tracker**, then a
**Schmitt trigger whose hysteresis follows that envelope** (env/4, floor 6 ADC
LSB) counting the transitions.

What makes it decisive is how it was validated. Its README marks "detector on
the radio with the Flipper Zero files" **Done (v1.7)**, and those files
(`test/flipper_homer.py`, `test/flipper/*.sub`) are Flipper Sub-GHz RAW in
preset `FuriHalSubGhzPresetOok650Async` - **a keyed carrier, i.e. OOK**, received
in **AM on 433.650 MHz**, because the Flipper's CC1101 cannot amplitude-modulate.
At 50 % duty and a 1600 Hz top tone, the on-pulses are **312 µs** - the pulse
width of a cheap 433 MHz remote (EV1527 is ~350 µs). What that proves is bounded
but real: edges 312 µs apart come through the AM-envelope chain cleanly enough
for the Schmitt trigger to count them. It does **not** show that pulse *widths*
can be classified - at 9.6 kHz such a pulse is only 3 samples, and `sweep.c` only
counts transitions per 25 ms window to estimate a tone frequency. A remote
decoder measures widths, so it wants a higher rate (§2.3 reaches 38.4 kHz).

It comes with a host test bench whose **channel model** an OOK decoder can reuse
unchanged, swapping only the detector: `test/sweep_test.c` `run_sub()` reads a
Flipper `.sub` and pushes it through a model of the AM demodulator (envelope,
3 kHz audio low-pass), the PA4 high-pass, noise and the ADC, "sampled as the app
does" (`:92-94`). `.sub` RAW is also the format a captured remote is stored in.

The second precedent is **`cwdecode`**, which is route 1 rather than route 2:
`App/apps/cwdecode/cwdecode_app.c:18-22` decodes keyed-carrier Morse by
**following the RSSI envelope**, since the BK4829 cannot demodulate CW into a
sidetone - median of 3 samples, adaptive noise floor, hysteresis (`sample()` at
`:377`). It leaves the AGC as a user setting defaulting to **on** (`:214`,
`:665`), which is survivable at its rate but not at OOK rates (§9.4). That rate
is `SAMPLE_MS = 10` (`:30`), i.e. **100 Hz** - right for Morse at 20 WPM (60 ms
dot), 100 to 200x too slow for a remote. In both apps the algorithm transfers;
only the rate is the work.

### 9.2 Why OOK clears the bars that §7.6 did not

- **Frequency**: 433.92 MHz is in band 6, 400-470 MHz (`App/frequencies.c:45`) -
  the native band, with front end, LNA and antenna all designed for it. Not
  band 2.
- **Bandwidth**: OOK at 1-4 kbit/s is narrow and fits the ~11 kHz baseband /
  ~22 kHz RF ceiling of §7.1 with room to spare. There is no ±19.2 kHz tone pair
  to pass.
- **Rate**: a few hundred microseconds per symbol, i.e. 1-4 kbit/s. The real
  ceiling is the BK4829's internal AF rate, not the MCU's 38.4 kHz sampling
  (§2.4, open question 1) - but even if that rate is of the order of §6.3's
  8 kHz, it still clears 1-4 kbit/s OOK by about an order of magnitude. This is
  the one protocol in this document that does not hang on open question 1.

### 9.3 Three routes

Routes 1 and 2 are both CPU-bound polling loops, so an app picks one.

1. **RSSI polling** - `cwdecode`'s route (§9.1), sped up. `rssi_dbm()`
   (`App/apps/app_api.h:192`) or `bk_read(0x67)` reaches REG_67
   (`App/driver/bk4829.c:1550`) over the bit-banged 3-wire bus. Cost per read is
   **~40-50 µs, estimated from the bit-bang source and unmeasured** (24 clocked
   bits, each half-period a 40-nop `SHORT_DELAY()` at 48 MHz: `bk4829.c:42`,
   `:204`, `:229`). That caps polling near 20 kHz with the CPU
   doing nothing else, so ~10 kHz in practice: 3 to 7 points on a 350 µs pulse -
   enough to classify pulse widths, tight for precise edge timing. Its real
   advantage is being DC-coupled, hence immune to the ~1 kHz coupling of open
   question 2.
   **Measured on the BK4819 this route is dead, and not for the reason above:
   the RSSI register is low-passed over 2.3-3.8 ms, so the sample rate is
   irrelevant (§9.6). Both the cost estimate and the rate argument here are
   superseded; read §9.6 before building on this route.**
2. **AM demodulator + AF capture** - `sigfind`'s route (§9.1), and the one with
   hardware evidence behind it. The envelope leaves on PA4 and rides the capture
   path that already runs at 9.6 / 19.2 / 38.4 kHz (§2.3): faster than route 1,
   and 312 µs on-pulses already come through cleanly at the low end of that
   range (§9.1), with 19.2 or 38.4 kHz available when widths must be measured.

   **How AM is actually enabled** - worth getting right, because the AM
   demodulator is not what the AF mode selects. `RADIO_SetModulation` turns it on
   by setting **bit 0 of REG_31**, leaving the AF mode at `BK4819_AF_FM`, with
   the comment "AM no longer needs special AF setting" (`App/radio.c:1157`,
   `:1181`); that is why `sigfind` detects AM by reading
   `bk_read(BK_REG_31) & 1` (`:509`). An overlay app therefore **requires the
   user to be on an AM channel** - which is exactly what both READMEs ask for -
   and the AF mode on top is its own choice: `sigfind` leaves it at FM,
   `acarsrx` selects `APP_AF_AM = 7` (`App/apps/app_api.h:480`,
   `App/apps/acarsrx/acarsrx_app.c:613`) and decodes 2400 bps AM-MSK from PA4 at
   19.2 kHz. Both combinations are proven; AF mode 7 on an *FM* channel is not
   tested.

   **What §9.1 settles, and it is more than it looks**: `sigfind` writes neither
   `REG_43` nor `REG_2B` and still slices a keyed carrier. The filter it inherits
   is whatever the channel's bandwidth gives, and `RADIO_GetAMFilterBandwidth`
   (`App/radio.c:787-790`) maps **W** to `BK4819_FILTER_BW_WIDE` (`0x3028`,
   3.5 kHz doubled to 7 kHz RF) and **N** to the stock AM preset
   `BK4819_FILTER_BW_AM` (`0x345C`, 3.5 kHz in 6.25k mode) -
   `bk4829.c:686-718`. `0x3028` has `<5:4> = 10`, the **25k/20k channel mode**,
   and the comment at `radio.c:788` says reusing it for AM "wide" is
   intentional. So AM in 25k mode is shipped behaviour, not a question, and a
   widening to 7 kHz is already one user setting away.

   **What is still untested** is only the rest of the way to §7.1's ceiling.
   Against `0x3028`, the AIS value `0x7E2C` (11 kHz) differs in the RF filter
   field `<14:12>`, the weak-RF field `<11:9>` and bit 2; `REG_2B |= 0x0700`
   (`App/apps/aisrx/gen_assets.py:52`, §7.2) is a second untested step, since
   both come from an FM app. That is what would keep pulse edges sharp and give a
   drifting transmitter somewhere to sit. One look with AF Scope on a keyed
   carrier settles it; until then the known-good configuration is the resident AM
   one, N or W, with W giving the 7 kHz filter. The validation in §9.1 records
   only "AM on 433.650 MHz", not which of the two.
3. **Comparator + timer input capture** (§2.5). PA4 also carries COMP1_INP8, so
   a 1-bit slicer feeding input capture yields edge timestamps with no sampling
   CPU at all - the textbook OOK front end. It is not in `app_api.h` though, so
   it needs direct COMP/TIM register access: an optimisation, not the first
   thing to try.

### 9.4 The real obstacles

- **Freeze the gain** - unlike `cwdecode`, which defaults to AGC on because its
  symbols are 60 ms long. Use `set_agc(false)` as
  `App/apps/sigfind/sigfind_app.c:230` and `App/apps/foxhunt/foxhunt_app.c:150`
  do. Otherwise the AGC lifts the gain through each silence and noise reads as a
  mark. Clipping on strong signals is
  harmless for a binary decision; the actual difficulty is choosing a fixed gain
  high enough for weak transmitters.
- **Carrier offset is the field problem**, more than demodulation. Cheap
  SAW-based remotes often sit tens of kHz off nominal - more than the filter is
  wide. The workflow is therefore: find the carrier in the spectrum analyser,
  then tune to it.
- **The ~1 kHz coupling at PA4** (open question 2, still unverified) makes long
  marks droop on route 2. Decode edges, not levels. Route 1 does not have the
  problem. Note that §9.1's evidence does **not** cover this: a homer is a
  balanced 50 % square wave, whereas a remote frame has long gaps and a sync
  gap. `sweep.c`'s own remark that the PA4 coupling is "close to a
  differentiator" supports the hypothesis without measuring it.

Transmitting or replaying OOK is a separate question, not analysed here.


### 9.5 Worked example: LaCrosse TX141 / TX141TH

A concrete target for §9.3 route 2, and a reminder to take the PHY from a
decoder that works: the timing tables circulating for this family do not all
agree, so the figures below are `rtl_433`'s, from the single `r_device` that
covers TX141-Bv2, TX141TH-Bv2/Bv3, TX141W and TX145wsdth
(`src/devices/lacrosse_tx141x.c:317-324` and its header comment).

| | value |
|---|---|
| carrier | 433.92 MHz, OOK |
| modulation | `OOK_PULSE_PWM`, **fixed 625 µs period** per bit |
| bit 0 | 208 µs high + 417 µs low (`short_width`) |
| bit 1 | 417 µs high + 208 µs low (`long_width`) |
| preamble | 833 µs high + 833 µs low, 4 times (`sync_width`) |
| limits | `gap_limit` 625 µs, `reset_limit` 1700 µs |
| burst | 12 identical packets back to back, every 50 s (4 on TX141-Bv3) |

**Sampling rate.** The discriminant is the high pulse: 208 against 417 µs, so a
threshold near 310 µs with ±104 µs of margin.

| rate | step | 208 µs | 417 µs | width error |
|---|---|---|---|---|
| 9.6 kHz | 104 µs | 2 samples | 4 samples | ±104 µs - the whole margin |
| 19.2 kHz | 52 µs | 4 | 8 | ±52 µs, workable |
| **38.4 kHz** | **26 µs** | **8** | **16** | **±26 µs, comfortable** |

So this one wants the top of §2.3's range, not `sigfind`'s 9.6 kHz. Route 1 is
out here: at ~40-50 µs per RSSI read (§9.3) the sampling step alone eats the
margin - subject to open question 9. And because the period is fixed, the robust
decision is not an absolute threshold but the **high-to-period ratio inside each
625 µs cell**, which self-calibrates and absorbs distortion.

**What actually deforms the pulses** is the AF chain, not the quantisation. On
the stock AM path REG_2B is untouched (§9.3), so the 3 kHz audio low-pass is in
circuit and contributes edges of the order of 100 µs - substantial on a 208 µs
pulse. If open question 2's ~1 kHz coupling holds (τ ≈ 160 µs), the 208 to 833 µs
plateaus droop as well and the pulses arrive mostly as edges. Two consequences:

- the slicer must be a **hysteresis comparator on the DC-removed signal**, i.e.
  `sweep.c`'s `sw_push` (§9.1); a threshold against a DC mean would fail;
- the right order of magnitude is already demonstrated: `acarsrx` decodes
  2400 bit/s AM-MSK, ≈417 µs per bit - exactly this `long_width` - from PA4 at
  19.2 kHz.

The decisive check costs nothing: push these timings through `run_sub()`'s
channel model (§9.1), which contains both the low-pass and the high-pass.

**Frame**, as the driver states it: 40 bits for TX141TH-Bv2 (41 for Bv3, 37 for
TX141, 32 for TX141B, 65 for TX141W), **bit-inverted** (`bitbuffer_invert`), in
5 bytes - `id8`, `flags4` (battery low, test button, channel), `temp12` (scaled
by 10, offset 500, -40 to +60 °C), `humi8`, `chk8`. The check is **not a CRC**
but a keyed LFSR digest, `lfsr_digest8_reflect(data, 4, 0x31, 0xf4)` (`:139`);
only TX141W uses a real CRC-8, poly 0x31 init 0x00 over 7 bytes. With 12 repeats
per burst a majority vote is cheap, and one packet passing the digest is enough -
which is what `rtl_433` itself relies on.

All of this fits an overlay app without strain. The remaining obstacle is
§9.4's: find the carrier on the spectrum first, the AM filter being 7 kHz at
best (§9.3) - and cheap sensors do sit well off nominal: the three carriers
found on air during the v1 work were at 433.843, 433.918 and 433.965 MHz
(§9.6).

**Build it on route 2.** Route 1 is not merely tight here, it is closed: on the
sibling BK4819 radio the RSSI register is low-passed over 2.3-3.8 ms and a
625 µs bit cell survives in it at 0.04 dB, measured against a transmitter 30 dB
over the noise (§9.6). The PA4 AF tap is therefore the whole value of this
radio for this target.


### 9.6 Measured on the sibling radio: route 1 is closed, route 2 is the only one

Everything in §9.3 ranked route 2 (AM envelope on PA4) above route 1 (RSSI
polling) on grounds of rate alone. Route 1 is now **measured, on hardware, and
it is not a rate problem at all** - the RSSI register itself is low-passed over
milliseconds, which no sampling rate can undo.

The measurement was taken on the **UV-K5 v1** (DP32G030 + **BK4819**), the one
radio where route 1 is the *only* option, because it has no AF tap into the MCU
at all: `BOARD_ADC_Init()` there wires only PA9/CH4 (battery volts) and
PA14/CH9 (battery current), and nothing on the audio path. A debug feature
(`ENABLE_RSSI_CAPTURE`, UART command 0x0603) was added to the F4HWN v1 fork for
it: it freezes the front-end gain, times one register read, validates a fast
bit-bang reader against the stock one, then captures 4096 consecutive reads
into RAM with interrupts masked and dumps the block as text. Four on-air
sessions, 2026-11-01, at 433.918 / 433.965 / 433.843 MHz.

#### The method, which transfers to this radio unchanged

- **Autocorrelation on noise is the input-independent probe.** Noise at the
  antenna through a ~7 kHz channel decorrelates in ~140 µs, so whatever width
  the register's output shows *is* the register's own response.
- **A sine fit at the rate of interest quantifies what survives**, in dB, which
  beats arguing about sample counts.

#### What it found

| register | role | ACF 1/e on noise |
|---|---|---|
| REG_67 | RSSI | **2.29 ms** and **3.81 ms**, two captures |
| REG_65 | noise indicator | **3.39 ms** |
| REG_63 | glitch indicator | **7.63 ms** |

Confirmed against a transmitter 25-30 dB over the floor, with a 25.5 dB
envelope swing inside the window and 0.5 dB resolution:

| | result |
|---|---|
| ACF 1/e at +30 dB SNR | **3.71 ms** - identical to the noise figure |
| ACF through 337-1011 µs | **strictly monotonic**, no 625 µs cell |
| sine fit, 625 µs cell rate (800 Hz) | **0.04 dB** |
| sine fit, 833 µs preamble pair (1200 Hz) | **0.01 dB** |
| sine fit, 33 ms packet rate (30 Hz) | 0.49 dB |

A TX141-family burst was positively identified on 433.918 MHz by an ACF maximum
at **33.3-33.9 ms**, which is the packet length: 4 x 833 µs of preamble plus
40 x 625 µs of data is 31.7 ms, plus the inter-packet gap. **The packet envelope passes the
register and the keying inside it does not.** On a frequency where the keying
was plainly audible in the speaker, REG_67 never rose more than 4.5 dB in 60 s
of 100 %-duty monitoring and carried no structure at all.

#### Also: the §5 question 9 bus estimate was wrong, and in an instructive way

Counting the bit-bang source gave ~40-50 µs per read. On the v1, the
delay-paced driver measured **220 µs**, and stripping every delay out left
**83 µs** - a floor set by the GPIO read-modify-writes and by plain instruction
throughput (its NOP-loop iterations cost ~26 cycles, so flash wait states with
no prefetch dominate), not by the deliberate pacing. **Counting instructions
underestimated the real cost by 4.4x.** Expect the same on the PY32F071: time
it with `cycles_48mhz()` before planning anything around it.

#### What this does and does not say about the BK4829

- **Does not prove** anything about this chip. The BK4829 is a different die,
  behind a different MCU and a different board. The RSSI smoothing has to be
  re-measured here.
- **Is a strong prior**, same vendor and the same register layout. Note also
  that `cwdecode` is entirely consistent with ms-scale smoothing: it samples
  RSSI at 100 Hz for 60 ms dots (§9.1), so it would work unchanged with a 3 ms
  low-pass in the way.
- **Says nothing about route 2.** The PA4 AF tap is a different signal path and
  is untouched by this result.

#### Consequence for §9.5

Treat **route 1 as closed** for TX141 unless a measurement on the BK4829 says
otherwise, and build the LaCrosse app on **route 2**, the AM envelope captured
on PA4 at 19.2 or 38.4 kHz. That is the route this radio has and the v1 does
not, which makes the K1 / K5 V3 the right platform for this target - and the
reason the v1 would need a hardware mod (BK4819 AF output through a coupling cap
into a SARADC pin) to get the same thing.

#### Two measurements worth stealing

1. **Re-run the noise ACF on REG_67 here**, via `bk_read(0x67)` in an overlay
   app paced off `cycles_48mhz()`. Half an hour, and it either confirms route 1
   is dead on this radio too or reopens it.
2. **Run the same ACF and sine fit on the `af_capture` stream**, which answers
   **open question 1** - the BK4829's internal AF sample rate, the number that
   bounds every capture app in this tree. Capture noise at 38.4 kHz with the AF
   filters bypassed (`REG_2B |= 0x0700`), and the ACF 1/e of that stream is the
   reconstruction interval; a sine fit near 10-19 kHz shows where the roll-off
   really is. The v1 work shows the technique separates "register is slow" from
   "input is slow" cleanly, which is exactly what §2.4 could not settle by
   argument.

## Appendix: reference data

### PY32F071 pins of interest

| Pin | ADC | Other functions | Used for |
|---|---|---|---|
| PA4 | **ADC_IN4** | **DAC_OUT1**, COMP1_INP8, COMP1_INN4, COMP2_INP4, SPI1_NSS/I2S1_WS, SPI2_MOSI, USART2_CK/TX, TIM14_CH1 | **the RX audio tap** |
| PB0 | ADC_IN8 | COMP2_INN6, TIM1_CH2N, TIM3_CH3 | battery voltage |
| PB1 | ADC_IN9 | COMP3_OUT, TIM1_CH3N, TIM3_CH4 | analog mode set, never read |

### ADC characteristics (Table 5-23)

| Symbol | Value |
|---|---|
| FADC | 1–16 MHz (VCC 2.3–5.5 V); 1–8 MHz (VCC 1.7–2.3 V) |
| tsamp | 3.5 – 41.5 Tclk |
| tconv | 12 Tclk |
| teoc | 0.5 Tclk |
| CIN | 5–8 pF |
| Resolution | 12-bit, one ADC, 16 external channels |

### DAC characteristics (Table 5-24)

| Symbol | Value |
|---|---|
| RO, buffer **OFF** | **≤ 15 kΩ** |
| CLOAD (buffer on) | ≤ 50 pF |
| tSETTLING | 4–10 µs |

### Factory internal-flash layout (teardown analysis)

- Bootloader `0x08000000`–`0x080027FF` (10 KiB, includes USB-C support)
- Application from `0x08002800` — matches `Core/py32f071xb.ld`

### Sources

- `BK4829-BEKEN.pdf` — DS-BK4829-E01 V1.0, 2023-05-26, 28 pp. §2.3 receiver
  architecture, §4 pin description, §5 application schematic.
- `PY32F071_Datasheet_Rev0.7_EN.pdf` — 78 pp. Pin tables, §5.3.15 ADC,
  §5.3.16 DAC.
- [armel/k1-teardown](https://github.com/armel/k1-teardown) — board photos,
  SWD pinout, OpenOCD recipes, decompiled factory firmware, flash dumps.
- [Velocet/iown-homecontrol](https://github.com/Velocet/iown-homecontrol) —
  reverse-engineered io-homecontrol PHY (`docs/radio.md`) and link layer
  (`docs/linklayer.md`), used in §7.6.
- [laberning/home_io_control](https://github.com/laberning/home_io_control) —
  ESPHome io-homecontrol component; `docs/supported-devices.md` is the device
  matrix referred to in §7.6.
- [rtl_433 — `src/devices/lacrosse_tx141x.c`](https://github.com/merbanan/rtl_433/blob/master/src/devices/lacrosse_tx141x.c)
  — the LaCrosse TX141 family PHY and frame layout used in §9.5.
- `uv-k5-firmware-custom` (the F4HWN v1 fork, sibling repository):
  `app/rssi_capture.c` and `utils/rssi_capture/` - the `ENABLE_RSSI_CAPTURE`
  bench instrument, its host tool and the full record of the four on-air
  sessions whose results are in §9.6.
- This repository: `App/board.c`, `App/apps/app_overlay.c`, `App/apps/app_api.h`,
  `App/driver/bk4829.c`, `App/driver/bk4819.h`, `App/apps/aisrx/`.
- `doc/ghidra/` — the Ghidra 12.2 decompilation of the factory firmware
  (`ghidra_decompiled.c`, `ghidra_function_map.txt`) and the scripts that
  produce it. Ghidra itself is installed at
  `/media/hp-z2-dev/Variste/Doc/opt/ghidra_12.2_PUBLIC`.

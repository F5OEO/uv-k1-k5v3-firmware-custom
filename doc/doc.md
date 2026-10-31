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
   every current and future capture app. Method: BYP mode, squelch open on
   noise, fastest capture available, then look for the AF DAC's roll-off or
   reconstruction images in the spectrum.
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
- This repository: `App/board.c`, `App/apps/app_overlay.c`, `App/apps/app_api.h`,
  `App/driver/bk4829.c`, `App/driver/bk4819.h`, `App/apps/aisrx/`.
- `doc/ghidra/` — the Ghidra 12.2 decompilation of the factory firmware
  (`ghidra_decompiled.c`, `ghidra_function_map.txt`) and the scripts that
  produce it. Ghidra itself is installed at
  `/media/hp-z2-dev/Variste/Doc/opt/ghidra_12.2_PUBLIC`.

# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this is

F4HWN custom firmware for the Quansheng **UV-K1 / UV-K5 V3**, whose MCU is a Puya
**PY32F071** (Cortex-M0+, 128 KiB flash, 16 KiB RAM). It is a port of the older
UV-K5 V1 (DP32G030) firmware lineage DualTachyon → Egzumer → F4HWN. One single
image serves both the K1 and the K5v3; the keypad-layout difference is resolved
at runtime through the hidden `SetNav` menu, so there is no per-model build.

## Commits

**Never add a co-author trailer.** No `Co-Authored-By:`, and in particular none
naming Claude or any other assistant, whatever the tooling suggests by default.
F5OEO is the sole author of every commit in this repository.

## Build

Everything goes through Docker (image `uvk1-uvk5v3`, built from `Dockerfile`,
ARM GCC 13.3 in `/opt/toolchain`):

```bash
./compile-firmware.sh                 # default preset: Fusion
./compile-firmware.sh Labs            # one preset
./compile-firmware.sh All             # Fusion Transfer FieldOps Labs FFVL Max
./compile-firmware.sh Fusion -DENABLE_FEAT_F4HWN_GAME=ON   # extra -D go to cmake --preset
./compile-app.sh                      # every overlay app (= All)
./compile-app.sh fm foxhunt           # one or more apps
```

- Valid firmware presets (`compile-firmware.sh` + `CMakePresets.json`, **not**
  the stale list in README.md): `Custom`, `Fusion`, `Transfer`, `FieldOps`,
  `Labs`, `FFVL`, `Max`, `Fusion_`, `Service_`, `All`. There is no `Service` preset.
- Output: `build/<Preset>/f4hwn.<preset-lowercased>.{elf,bin,hex,map}`; apps land
  in `build/Apps/<AppName>.app`. The basename comes from the preset's `TARGET`,
  so `FFVL` is the exception: `build/FFVL/f5oeo.ffvl.bin`.
- Each run does `cmake --fresh`, so a build is always a full reconfigure+rebuild.
- The Docker image is built **only if absent**. After editing `Dockerfile`:
  `docker rmi uvk1-uvk5v3`.
- `-DDEV=ON` is Fusion-only and overwrites the tracked
  `archive/f4hwn.fusion.development.bin` (commit it only deliberately).
- A native build is possible — `cmake/gcc-arm-none-eabi.cmake` just prefixes
  `arm-none-eabi-` and takes the toolchain from PATH — but it needs **binutils
  ≥ 2.39** (`-Wl,--no-warn-rwx-segment`, which older `ld` rejects outright) and
  **CMake ≥ 3.24** (`--fresh`). The Docker image pins ARM GCC 13.3.rel1, which
  satisfies both; a distro `arm-none-eabi-gcc` often does not. Prefer the script:
  it is what CI runs and it prints the budget tables.
- `compile-with-docker.sh` is a deprecated alias for `compile-firmware.sh`.

CI (`.github/workflows/main.yml`, push to `main`) runs `./compile-firmware.sh All`
then `./compile-app.sh All` and uploads `build/*/*.bin` and `build/Apps/*.app`.

## Tests

There is **no unit-test suite** and nothing runs on the host. Verification is:

1. **Build gates** that fail the build automatically:
   - `cmake/check_printf_formats.py` (target `check_printf_formats`, a dependency
     of the firmware target) scans `App/**/*.{c,h}` except `external/` and
     `*/test/*`.
   - `cmake/check_mb_ramfunc.cmake`, a POST_BUILD check run when
     `ENABLE_FEAT_F4HWN_MULTIBOOT_OVERLAY` is on: it rejects the image if the
     multiboot restore stub branches outside its RAM section. Deliberately hard —
     a violation could make a restore unrecoverable without DFU.
   - Per-app `build.sh` plus `pack_app.py` reject an overlay blob over 4 KiB.
2. **Budget tables** printed by both scripts (flash/RAM per preset, code+assets
   per app). Watch these on every change; they are the real regression signal.
3. **Source-level differential checks** in `tools/`, which diff current source
   against a pinned baseline commit and re-evaluate the logic in JS. They need
   both `node` **and `rtk` on PATH**:
   ```bash
   rtk run "node tools/check-menu-settings.mjs"
   rtk run "node tools/check-multiboot.mjs"
   ```

The nearest thing to "running one test" is building one preset or one app.

## Hard budgets — these drive most design decisions

| Resource | Limit |
|---|---|
| Internal flash | 118 KiB at `0x08002800` (factory bootloader lives below; never touch it) |
| RAM | 16 KiB total, incl. 1 KiB stack; `ENABLE_NO_HEAP` zeroes the 512 B heap |
| Overlay app code | 4 KiB, pinned VMA `0x20000280` |
| Overlay app assets | 3840 B in external flash (not in RAM) |

`compile-firmware.sh` only *reports* the 118 KiB / 16 KiB figures; an overflow
actually fails at link time against the `MEMORY` regions and `ASSERT`s in
`Core/py32f071xb.ld`, which holds the authoritative layout. Resident-vs-overlay is the standard
way to buy flash back: a feature that fits the overlay should be an app.

`printf` is the minimal `App/external/printf` build (`App/printf_config.h`).
Only `%d %u %o %s %c %%` are allowed, with flags `0`, `+` and space and
width/precision (`*` included). Rejected: `%x`/`%X`/`%p`/`%f`/`%e`, the `-`
(left-justify) and `#` flags, and **any length modifier** — so `%lu`, `%ld` and
`%hu` all fail the build. On ARM `uint32_t` is `unsigned long`, which is the trap:
use `%u`/`%d` and cast. The checker only inspects literal format strings, so a
format built at runtime slips past it and then misbehaves at runtime.

## Architecture

### Boot and main loop

`Core/Src/main.c` configures the clock and calls `Main()` in `App/main.c`.
`Main()` must call `PY25Q16_SetBankBase(MB_BankBase(MB_BootResolveState()))`
**before any settings/EEPROM access** — that resolves the active Multiconfig
bank and adopts the running image as multiboot slot 0. Then it initialises the
board, radio and settings, handles the boot modes (`BOOT_GetMode()`: multiboot
selector, rescue ops, …) and enters:

```c
while (true) {
    APP_Update();                  // App/app/app.c — foreground work
    if (gNextTimeslice) {
        APP_TimeSlice10ms();
        if (gNextTimeslice_500ms) APP_TimeSlice500ms();   // nested: 500 ms only on a 10 ms tick
    }
}
```

`SysTick_Handler` in `App/scheduler.c` ticks every 10 ms and only decrements
countdowns and raises `gSchedule*` flags; all real work happens in the timeslices.
Modal foreground loops (spectrum, foxhunt, overlay apps) run their own loop and
bypass `APP_Update()`, and therefore the backlight fade and `BLTime` service too;
they call `APP_ModalBacklightTick(allowScreenSaver)` instead — see the note at
`App/app/app.c:339`.

### Storage: there is no EEPROM

The PY32 port keeps the old `EEPROM_ReadBuffer`/`WriteBuffer` API but implements
it in `App/driver/eeprom_compat.c` over the external **PY25Q16** SPI flash, via
the `ADDR_MAPPINGS` table. A write is a read-modify-write of a whole 4 KiB
sector through the cache in `App/driver/py25q16.c`: unchanged bytes are skipped,
and the sector is erased only when a bit must flip 1→0 — but then **the erase
alone takes ~300 ms** and blocks. So batch writes and keep them off hot paths.
That 4 KiB sector cache is the same RAM the overlay apps and the multiboot RAM
stub run in.

### Legacy files that are NOT compiled

`App/CMakeLists.txt` is the only source list. These files are still in the tree
but unbuilt — editing them does nothing:
`App/init.c`, `App/sram-overlay.c`, `App/driver/adc.c`, `App/driver/bk4819.c`,
`App/driver/eeprom.c`, `App/driver/flash.c`, `App/driver/spi.c`
(`driver/aes.c` is likewise only a commented-out line).
In particular the RF transceiver driver is **`App/driver/bk4829.c`**, which
implements the `driver/bk4819.h` API and keeps the `BK4819_*` names.

### Feature flags

Flags flow preset → CMake → preprocessor:

1. `CMakePresets.json`: flags are declared in the hidden `default` preset
   (mostly off, but UART, USB, VOX, `F4HWN_SPECTRUM`, `F4HWN_SLEEP` and others
   are on; a few such as `OVERLAY_BEAM`, `OVERLAY_INFO` and `EXT_FLASH_RW` are
   not listed there at all), and editions override. `Fusion` is the base the others
   inherit (`FieldOps`, `Transfer`, `Labs`, `Max` inherit it; `FFVL`
   inherits `Labs` and only renames the edition and the output; `Service_`
   inherits `Fusion_`).
2. `App/CMakeLists.txt`: `enable_feature(FLAG [sources…])` adds the define and
   the conditional sources. Inter-flag dependencies are enforced there with
   `message(FATAL_ERROR …)` — add a new one next to its siblings.
3. Source: `#ifdef FLAG`.

Note the preset file's own support policy: options outside `ENABLE_FEAT_F4HWN_*`
that are `false` in `default` are unsupported; flipping them may well not build
or not work.

Caveats worth knowing: `ENABLE_FEAT_F4HWN_OVERLAY_APPS` is **off** in `Fusion`
(only `Labs`, `FFVL` and `Fusion_` enable it), despite what README.md implies; it requires
`MULTIBOOT_OVERLAY`. `ENABLE_FMRADIO` + no overlay apps additionally defines
`ENABLE_FMRADIO_EMBEDDED` (the resident FM state machine); with overlay apps, FM
is the `fm` app instead.

Simple persistent byte settings are declared once as X-macros in
`App/app/menu_settings.def` (`MENU_SETTING(id, lvalue, min, max)`) and expanded
for both validation and table generation. Put a plain byte setting there, not in
`menu.c`; anything with a callback or a channel/VFO write does not belong in it.

### Multiboot / Multiconfig (brick-critical)

`App/driver/mb_flash.c` + `ui/multiboot.c` reprogram the internal application
flash from an image in external flash, **running from a RAM stub** while flash is
unavailable. Invariants: header + CRC32 are validated *before* any erase; the
device-specific calibration sector is never erased or copied; the restore stub
must not reference anything outside its RAM section (the POST_BUILD gate). Slot 0
is the firmware-managed backup, slots 1–4 are user slots, 128 KiB stride.
Each slot has a matching config bank (`CFG M`, `CFG 1`–`CFG 4`), selectable at
runtime by `SetCfg` when `MULTIBOOT_HOT_CFG` is on.

### Overlay apps

An app is a standalone ≤4 KiB blob in external flash, copied into the overlay RAM
to run and then discarded. It is linked `NOCROSSREFS` and **must not reference any
resident firmware symbol**: every service arrives through the `app_api_t` table
passed to `void app_main(const app_api_t *api)` at blob offset 0.

- `App/apps/app_api.h` is the shared ABI, included by both the loader and the
  apps. Within `APP_ABI_MAJOR` it is **append-only**: never move, remove or
  re-sign an existing field. Appending a service means bumping `APP_API_LEVEL`
  (and the app's `APP_API_MIN` in its `build.sh`).
- `App/apps/app_overlay.c` is the loader (header/CRC validation, slot layout);
  `app_menu.c` is the launcher UI. The loader never writes internal flash, so a
  bad blob is refused or watchdog-resets — but a launched app is trusted native
  code with full access to memory and peripherals. No MPU, no sandbox.
- Each app is `App/apps/<name>/` with its own `build.sh` (the only per-app knobs
  are `APP_NAME`, `APP_VER`, `APP_API_MIN` and the `pack_app.py` flags), `app.ld`,
  `<name>_app.c`, optional `gen_assets.py`. Discovery is "has a `build.sh`", so a
  new directory with one is picked up automatically by `compile-app.sh`.
- `handoffa`, `handoffb` and `vfotest` are API test apps, excluded from `All` and
  buildable only by name.

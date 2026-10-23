# Typing Tutor IV — REA reverse-engineering report

First static pass: 2026-10-22–23. Target: the owner's TT/TT.EXE.
The analysis uses official [REA](https://github.com/morluto/rea), with Ghidra's DOS adapter.
The [REA DOS guide](https://github.com/morluto/rea/blob/main/docs/ghidra-dos.md) explains its real-mode address and packed-executable boundaries.

## Result
Recovered the original menu hierarchy, menu handlers, screen coordinates, color packing, practice input/correction paths, and numerical scoring helpers.
Exported assembly and pseudocode for all **377 functions in the current analyzed inventory**, totaling **26,555 assembly lines**.
This is a substantial static analysis pass, not a claim that every byte or behavior has been understood.

The browser app under dist/ has not been changed during this investigation.
Its redesigned interface and provisional scoring remain distinct from the original.

## Reviewable artifacts
- [Recovered menu-frame HTML](../analysis/recovered/main-menu-frame.html)
- [Chrome image of that reconstruction](screenshots/recovered-main-menu-frame.png)
- [80×25 text frame](../analysis/recovered/main-menu-frame.txt)
- [Decoded menus and handlers](../analysis/recovered/menus.json)
- [Function index and Evidence IDs](../analysis/recovered/function-index.json)
- [All assembly](../analysis/recovered/all-functions.asm)
- [All pseudocode](../analysis/recovered/all-functions.c)
- [Coverage and limitations](../analysis/recovered/coverage.json)
- [Toolchain and transformation hashes](../analysis/toolchain.json)
- [Initial verified load image](../analysis/rea/load-image.json)
- [Seeded verified load image](../analysis/rea/seeded-load-image.json)
- [Retained initial snapshot](../analysis/rea/initial.snapshot.json)
- [Retained seeded snapshot](../analysis/rea/seeded.snapshot.json)
- [Evidence file integrity index](../analysis/evidence-index.json)

The HTML/PNG is a reconstruction of the statically established frame, not a screenshot of a running DOS program.
Its font and Student name are placeholders. The later idle help panel is deliberately omitted.

## Toolchain and input preparation
- REA 6.7.0 and its MCP client are installed under .tools/rea/, with exact dependency manifests retained under analysis/toolchain/.
- Ghidra 12.1.4 was downloaded from the NSA project's official release. Its archive SHA-256 matched the release metadata.
- The archive contained no macOS ARM64 decompiler. Built its supplied source with make ghidra_opt for arm64 and installed it inside the same project-local distribution.
- Used the machine's standalone OpenJDK 21.0.12.1. No Python environment or tooling from another project was borrowed.
- No global Codex/MCP registration was changed. A project-local stdio MCP driver kept the Ghidra session resident.
- Optional Frida install scripts were not enabled; Frida is not used for this analysis.

TT.EXE is EXEPACK-packed. The original is 100,592 bytes, SHA-256:
22b70fb15d9dbef9d1c2e00a3a0e6dca6a20486fc0bdca8cc8371b6f3b8026b7.

David Fifield's exepack 1.4.0 unpacked a separate analysis/derived/TT.unpacked.exe.
That copy is 100,912 bytes, SHA-256:
6e80ab0186040beef29c8be8b39a36ddc0e2c9b15ca20e0eedd4055d76379288.

The original executable and both companion files remain byte-identical to their recorded reference hashes.
Unpacking is a static transformation; the DOS target was not executed.

## Address convention and load verification
All 0x addresses below are REA/Ghidra linear analysis addresses, not file offsets or DOS runtime addresses.

The unpacked entry is 0x1f19c, corresponding to original CS:IP 0000:f19c at analysis load segment 0x1000.
The initialized image has 100,400 bytes, three relocations, and no appended overlay.
The startup's data-segment value and the mapped block establish data at 0x1f8e0, source file offset 0xfae0.
For the initialized image, a typical source mapping is file offset = analysis address - 0x10000 + 0x200.
Relocated words differ from file bytes; consult the verified mapping rather than applying that formula blindly.

Both load-image inspections returned verified for source identity, initialized mappings, relocation fixups and entry.
That verifies the static import, not runtime correctness.

Ghidra initially discovered 250 functions. Indirect menu callbacks remained undefined.
scripts/seed-tt-analysis.py recorded 205 explicit seeds matching MOV AX, local-size; CALL 0xe7bd within CODE_0.
These seeds are analyst assertions based on an observed compiler convention.
The seeded analysis reported 377 functions; it does not prove exhaustive code ownership.

## Recovered menus
Menu records begin at DS offset 0x134c (analysis address 0x20c2c), with **31 bytes per record**:
a title pointer, a one-byte item count, seven two-byte label pointers, and seven signed two-byte actions.

Nonnegative actions select a submenu. Negative actions select a near handler through the DS:0x1759 table.
This was established from the menu dispatcher's assembly/pseudocode, then checked against the retained table bytes.

| Index | Menu | Items |
| --- | --- | --- |
| 0 | Main Menu | Lessons, Tests, Reports, Options, Game, Help, Quit |
| 1 | Lessons Menu | Practice, Fingering, Keypad, Help |
| 2 | Tests Menu | Practice, All-keys, Disk, Keypad, Help |
| 3 | Reports Menu | Progress, Speed, Accuracy, Help |
| 4 | Options Menu | WPM, Time, Drills, Sound, Name, Intro, Help |
| 5 | Game Menu | Play, Scores, Help |
| 6 | Instructor Main Menu | Encrypt, Reports, Password, Delete, Help, Quit |
| 7 | Instructor Reports Menu | Composite, Progress, Speed, Accuracy, Help |

The last two menu roles are inferred from their operations and corroborated by TT.HLP. Their stored titles are simply Main Menu and Reports Menu.

## Interface observations
Coordinates are zero-based.

| Observation | Machine-code location / retained Evidence |
| --- | --- |
| Cursor bounds are 80 columns × 25 rows | 0x1f7da; cursor-position-assembly.json |
| Header title starts at row 0, col 0 with a leading space | 0x12692; screen-header.json |
| Student name starts at col 79 minus its length | 0x12692; screen-header.json |
| Row 1 contains 80 CP437 0xcd double-rule characters | 0x12692; screen-header.json |
| Menu labels occupy row 3 and have two spaces between them | 0x1366e; menu-screen-layout.json |
| Row 4 previews submenu items or describes the selected action | 0x137f2; menu-feature-bar.json |
| Highlight column is the sum of earlier label lengths plus two spaces each | 0x13a2e; menu-current-description.json |
| Footer is centered on row 24; normally prefixes Esc -> | 0x12612; screen-footer.json |
| Left/Right arrows and Space move through horizontal items with wraparound | 0x132ed, 0x135f5; menu-dispatcher.json, menu-navigation.json |
| Enter activates; first-letter shortcuts activate; Escape may map to Quit | 0x132ed, 0x138f1; menu-dispatcher.json, 0x138f1.c |

There is also an idle instruction panel: 0x1370e draws a box at (7,3)–(21,76) and wraps four instruction strings.
Its full placement/text progression is retained but not yet rendered in the frame artifact.

The color path at 0x1b1f3 calls 0x1f6bf for color displays.
The latter packs (background << 4) | foreground, sets intensity bit 3, and controls blink bit 7.
Observed common attributes are:

| Use | Attribute | Standard DOS palette interpretation |
| --- | --- | --- |
| Body and header | 0x1f | Bright white on blue |
| Normal menu bar | 0x5f | Bright white on magenta |
| Selected menu text / preview / footer | 0x5e | Yellow on magenta |
| Practice boxes | 0x2f | Bright white on green |
| Practice error pointer | 0x2c | Bright red on green |

Attribute numbers are binary observations. RGB palette values and browser font rendering in the HTML are reconstruction choices; hardware palette/display modes still need runtime confirmation.
A separate monochrome branch exists.

## Practice and correction
- Lessons → Practice reaches 0x12741. Keypad reaches 0x1282a; these are separate handlers.
- The keyboard practice loop is 0x13a6d; the line input routine is 0x14a70.
- Practice screen builder 0x14232 draws separate exercise, focus-key and feedback boxes using 0x1ae2b.
- Arrow characters are CP437 0x18 (up) and 0x19 (down), established by the input/marker calls.
- A mismatch marks a byte in the line error array at DS:0x900 and draws a downward pointer (0x14dcd).
- Backspace moves the text cursor back, clears that position's error byte, and removes the downward pointer (0x14d5f).
- At line completion, 0x14e95 counts clear versus set error bytes, including a terminating position.
  Enter, Space and + are accepted as unmarked terminators there; other final keys are marked as an error.
- Consequently, corrected errors can disappear from **line-summary accuracy**. Per-key attempt history is updated separately by 0x14f6c, so this does not prove that correction erases every historical penalty.
- This differs from v0.1's attempt-based accuracy. Do not change it merely by substituting a percentage formula; the counters and timing boundaries must also be matched.

The original key-presentation sequence is retained at DS:0x7a53 and begins:
asdfjkl;eit.nro,hcpumygwvbxqz
It continues with punctuation, digits and symbols. The complete string is in the binary; the remake's six coarse stages do not reproduce this sequence.

## Numerical scoring kernels
These arithmetic operations are clearer in assembly than in decompiler output:
- 0x1529a: when a+b is nonzero, unsigned integer division of 100*a by a+b; zero denominator returns zero.
- 0x152dc: when t is nonzero, unsigned integer division of 1200*(a+b) by t; zero denominator returns zero.
- The arithmetic is bounded by 16/32-bit implementation details, not JavaScript floating-point semantics.
- 0x14cb5 converts the BIOS tick value using multiplication by 549 and division by 100. The intended centisecond scale is an inference from that conversion and the 1200 speed multiplier.
- Practice callers adjust the numerator by two positions per drill and use a timing accumulator.
- 0x14b92 includes interval smoothing/capping, and 0x14e95 subtracts an effective final interval from elapsed time.
  Exact timing compatibility therefore requires more than total wall-clock duration.

See accuracy-formula-assembly.json, speed-formula-assembly.json, clock-conversion-assembly.json,
timing-accumulator-assembly.json and line-summary-assembly.json under analysis/rea/.
These observations establish the kernels and important differences; they do not establish a complete validated scoring specification.

## Further subsystem entry points
| Subsystem | Address / role |
| --- | --- |
| Key introduction decision | 0x15584 |
| Practice speed threshold calculation | 0x154c1 |
| Progress report | Handler 0x12d82 → 0x18c42 |
| Speed / accuracy graphs | Handlers 0x12de2 / 0x12e3b → 0x1853c |
| Letter Invaders | Play handler 0x12f68 → 0x1ab36 |
| Game scores | Handler 0x12f7f → 0x17a3a |
| Original input conversion | BIOS reader 0x1f831 → 0x1f858 |

These paths are navigation leads. The entire adaptive algorithm, game physics and history structure have not yet been explained or tested.

## Questions and coverage
| Question | State | Remaining work |
| --- | --- | --- |
| Can REA analyze this DOS executable? | Answered | Verified unpacked MZ import and real 16-bit analysis |
| Can the original interface be recovered from machine code? | Answered for menu frame | Font raster, idle panel and other screen families need reconstruction/verification |
| How are menu choices dispatched? | Answered statically | Runtime check remains |
| How do correction and line accuracy differ from the prototype? | Partly answered | Validate complete session/per-key accounting |
| What are the speed/accuracy arithmetic kernels? | Answered statically | Verify counter meanings, timing, rounding and boundary cases end to end |
| What is the exact adaptive curriculum? | Partly answered | Trace thresholds, weighting, drill generation and key introduction |
| Can every original feature now be reproduced exactly? | Unresolved | Game, history, reports, keypad and runtime conformance remain |

## Verification and next work
Passed: original-file hashes, original-to-unpacked identity chain, Ghidra loaded-image verification, 377 paired exports,
eight decoded menu records, full table-byte equality, 80×25 frame dimensions and Chrome rendering/color checks.
A test initially stripped significant trailing spaces with trimEnd; changed it to remove only the final newline.

Both REA binary sessions were closed with snapshots; terminal sessions exited.
No DOS program, browser app server or hosted service was left running by this investigation.

Next: replace the redesigned menu with an 80×25 renderer using these recovered tables, then reconstruct the practice screen and original counters.
Corroborate the static reconstruction with the standalone DOSBox-X runtime on a disposable copy before claiming visual or behavioral parity.

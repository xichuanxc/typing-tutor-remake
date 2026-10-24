# Original program findings

Evidence inspected on 2026-10-22. These are static findings, not runtime observations.

## Reference files
- TT.EXE: 100,592 bytes, DOS executable; contains Typing Tutor IV branding.
- TT.HLP: 12,651 bytes, ASCII with CRLF line endings. Help sections use @ and ^ separators. Credits TiANWEi's January 2000 Y2K fix.
- TT.HIS: 18,319 bytes, binary data. Help describes saved student history; layout and existing records are unknown.

The executable also contains Typing Tutor III text, so embedded strings alone do not identify every active screen.

## Feature map
| Area | Features supported by help text | Evidence |
| --- | --- | --- |
| Introduction | Student goals, typing experience, practice time, customized course | TT.HLP introduction |
| Main menu | Lessons, Tests, Reports, Options, Game, Help, Quit | TT.HLP main-menu help |
| Lessons | Practice, Fingering, Keypad | TT.HLP lessons help |
| Tests | Practice, All-keys, Disk, Keypad | TT.HLP tests help |
| Reports | Progress, Speed, Accuracy; current session versus history | TT.HLP reports help |
| Options | WPM goal, weekly time, drills per lesson, sound, name, intro | TT.HLP options help |
| Game | Letter Invaders, play and high scores; learned-key practice | TT.HLP game help and introduction |
| Instructor tools | Encrypt tests, reports, password, delete student; composite and individual reports | TT.HLP instructor menu sections |

## Typing interaction documented in help
- Escape leaves the current activity; the bottom line identifies its destination.
- The top line identifies the screen and student.
- A practice lesson uses one-line drills. An upward pointer identifies the next character; a downward pointer marks errors.
- Backspace corrects mistakes. Enter or Space completes a regular line.
- Lessons start with left-hand home keys, introduce right-hand home keys, then more keys and Shift. Exact progression rules are unverified.
- Fingering charts explain new keys. Focus keys need improvement; completed drills show speed and accuracy.
- Default lesson length is ten drills and can be changed.
- Tests contain multiple lines. Practice tests use introduced keys; All-keys tests include the whole keyboard.
- Keypad lessons start with 456, use three-line drills and use + to end lines.
- Practice and keypad test results enter saved history and Progress Reports.
- Reports include average speed, accuracy, keys above the WPM goal, and letter/number/symbol speed breakdowns.

The help uses * and # placeholders for some home-key strings. Executable text explicitly describes ASDF and JKL; fingering. Do not display the placeholders as actual lesson keys.

## Additional executable evidence
Printable strings support registration, name entry, beginner/two-finger/touch-typist experience choices, date confirmation and a save-session-on-exit choice.

An initial test references initial.tst. That file is not among the supplied three main files; investigate whether onboarding can skip it. Do not assume all disk-test content is bundled.

Letter Invaders strings describe descending words, practice/full-keyboard modes, levels, one or two players, escalating letter points (10, then 20, then 30), a 10-point miss penalty, Boomlets, Word Ships and accuracy bonuses. Runtime timing, spawning, collisions and bonus rules remain unverified.

## Runtime inspection checklist
- Use a separate working copy, preserving the three reference hashes.
- Capture welcome, registration/returning student, main menu and keyboard navigation.
- Run a home-row lesson: correct input, wrong input, correction, end-of-line and Escape.
- Record a practice test and its summary; compare session versus saved history.
- Inspect settings, graphs, keypad practice and Letter Invaders.
- Record current-date compatibility, missing-file behavior and any crash.
- For each observation, record actions, expected/actual result, and screenshot or transcript location.

## Unknowns
No runtime screenshots yet. Exact layout/colors, scoring formulas, timer boundaries, progression thresholds, full lesson generation, binary history structure and modern-date behavior are unresolved. A modern remake must document its own choices where the original cannot be established.

## Machine-code investigation update (2026-10-23)
The initial help/string inventory above is superseded where applicable by [the REA report](reverse-engineering.md). REA/Ghidra has now produced 377 paired function exports, decoded menu tables and a static menu-frame reconstruction. Runtime screenshots and complete parity remain outstanding.

## F3 static scoring update (2026-10-23)
The earlier unknown scoring/timing boundaries now have an assembly-backed translation and deterministic traces.
See [practice/scoring](practice-scoring.md). Native runtime parity, adaptive generation and the complete binary history remain unresolved.

## F4a static curriculum update
Original alphabetic thresholds, presentation/focus rules, weighted grammar and compressed word resources now have a tested browser translation. See [adaptive curriculum](adaptive-curriculum.md). This does not establish live DOS parity or complete punctuation/numeric, history or game recovery.

## F4b static recovery update
Full-key grammar callbacks, six-line keyboard tests, Progress tables and per-key graphs now have tested browser translations. See [tests and reports](tests-and-reports.md). Evidence is retained assembly plus Chrome observation; native DOS execution, full history import and remaining lesson branches stay open.

## F4c lesson recovery update
Retained assembly confirms the shared reach routine for punctuation, digits and symbols through index 63, including delayed character appearance, immediate input and Escape cleanup. These paths now have unit and Chrome coverage. See [full keyboard lessons](full-keyboard-curriculum.md). This remains static translation plus remake observation, not native DOS execution.

## F5a static recovery update
Fingering, keypad outlines, separate learning/generation, nine-entry reach drills, three-number lesson batches, 24-number tests, summary speed discrepancy and report category suppression now have tested browser translations. See [fingering and keypad](fingering-and-keypad.md). Native DOS execution and complete history/onboarding remain open.

## F5b static recovery update
Disk file enumeration, token/byte readers, rotated envelope,72-column wrapping, short/empty EOF lines, packed Escape behavior, six-line page accounting and separate history now have tested browser translations. See [Disk tests](disk-tests.md). Native runtime comparison and full original programme parity remain open.

## F5c static recovery update (2026-10-24)
Letter Invaders setup, temporary key generation, 90 case-sensitive slots, missile/ground physics, score arithmetic, two-player transitions and global score-table insertion now have unit-tested browser translations. These supersede the initial string-only game findings above. See [Letter Invaders](letter-invaders.md) for function evidence and browser choices. Chrome captures establish remake behavior; native DOS runtime, full history/onboarding and complete parity remain open.

## Earlier help comparison (2026-10-24)
The supplied OLD/TT.HLP confirms an intact original welcome without the Y2K programmer credits, but also contains two overwritten/non-text spans. A 12,508-byte credit-free reconstruction matches the earlier file outside 0x400–0x800 and 0x2000–0x2800. Missing prose is corroborated only by the readable fixed copy. See [the comparison](help-comparison.md) and its 17-page reconstructed Intro. Neither reference nor the app's current help has been replaced.

## Internet verification of earlier help (2026-10-24)
An independently archived 12,508-byte tt.hlp from Internet Archive exactly matches the credit-free candidate across the entire file, including both damaged local OLD spans. Its archive-listed SHA-1/MD5 match the download. The saved 17-page Intro is therefore independently corroborated; the previous missing-text uncertainty is superseded. See [verification details](help-comparison.md) and [the receipt](../analysis/help-comparison/internet-verification.json). This does not verify executable behavior or publisher-original media provenance.

## Verified Intro applied (2026-10-24)
The owner authorized applying the archived original Intro to the app. Its 17 source parts now replace the modified welcome/credit parts in Options → Intro; the browser groups them into seven fitted reader screens. Other Help sections still use the preserved fixed reference. Source hashes are embedded in generated resource evidence, and attribution is retained in THIRD_PARTY.md.

## 2026-10-24 — Startup and profile-file static audit

Retained assembly confirms TT.HIS is the native student-history file:0x10128 opens it r+,0x10f47 enumerates26-byte names at0x7cc-byte strides across eight scanned slots, and0x10e3f/0x10ddc load an existing1996-byte record or an unnamed template. This refines the initial unknown-layout finding without claiming a complete importer. No names/history were exported or references modified.

0x1095c/0x10c43/0x1ca33 recover title correction, keyboard, copyright/logo and0x17e47 case7 startup melody. The browser first-user gate is an owner-requested adaptation; native startup precedes student selection. See [startup evidence and remaining runtime limits](startup-welcome.md). These are assembly/data findings, not help-text or native runtime observations.

## 2026-10-24 — Registration after welcome

Static startup order at0x10860 is welcome, student selection/registration (0x10e3f,0x10ddc,0x10d63), then Date (0x10f9a). DS01c9 is Registration and DS01ae is Please type your name. Shared editor0x1b751 yields the same row9–17, column17–62 frame and row13/column27 name entry already used for Options → Name. No native DOS run was performed. The browser now requires name entry after fresh welcome and omits DOS date confirmation as an owner-suggested browser adaptation. Saved-profile behavior and remaining native questionnaires/history recovery are separate.

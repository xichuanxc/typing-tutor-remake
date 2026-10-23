# F4b — original keyboard tests and reports

Delivered 2026-10-23. This is a JavaScript translation of retained REA/Ghidra assembly, verified in installed Google Chrome. It is not a native DOS runtime comparison.

## Delivered behavior

Tests → Practice Test uses the learned keyboard range, excluding the pending new key. All-keys Test temporarily enables the full 64-key grammar without advancing the teaching position. Both generate six lines upfront, each at most 72 characters, in the recovered green frame. Each line starts its own timer. Correction, boundary input and integer scoring share the original practice engine. The result dialog offers another test, Practice Lesson or Main Menu.

Reports → Progress Report, Speed Graph and Accuracy Graph are active. Any ordinary key cycles reports; Escape returns to Main Menu. The original table geometry, 75 graph columns, current/history colors, legend placement and empty keypad group are reconstructed. Reports do not modify the student session.

Full text generation now includes punctuation, paired quotes/brackets, addresses, money, arithmetic, dates, times, telephone numbers and social-security-number formats. Native formatting quirks are retained. Lessons remain bounded at alphabetic index 28 until the remaining teaching branches are implemented.

## Evidence

| Retained assembly | Translation |
| --- | --- |
| 0x12952, 0x12a2c, 0x13a6d | Practice/All-keys dispatch, temporary key range, six lines of width 72, completion accounting |
| 0x14802 | Test frame and input coordinates |
| 0x154c1 | Threshold recalculation after temporary range changes |
| 0x15854, 0x157cc | Full-range grammar/category selection |
| 0x12d82, 0x12de2, 0x12e3b | Report dispatch and cycling |
| 0x18c42, 0x18857, 0x18ad2 | Progress table, category display adjustment and rows |
| 0x18357, 0x18383, 0x18497, 0x184d1, 0x1853c | Graph values, byte conversion, bars and legend |

[Report resource receipt](../analysis/reports/resources.json) records function Evidence identifiers, geometry and extraction hashes. [Curriculum resources](../analysis/curriculum/resources.json) record decoded grammar and numeric resources. Both reuse the immutable first-stage exports.

## Counters and persistence

Final accuracy excludes corrected errors; timed expected-key observations retain them. Timed spaces contribute to category totals but not individual key arrays. Aborted tests retain timed observations, but do not create completed-test rows or contribute final line totals. The native Session practice aggregate includes completed keyboard tests as well as lessons.

The latest four completed keyboard tests appear in Progress. Session and History split at explicit successful Quit/save. Save failure retains working data; discard restores saved data. Tests use versioned keyboard-test-f4b records in the existing faithful v2 namespace. Older records remain recoverable. Older adaptive records lack timed spaces, so unknown category breakdowns stay blank; F3 fixtures and prototype scores are not relabeled as faithful report data.

Graph speed preserves the native low-byte conversion before the cap: 300 WPM becomes 44, then eight five-unit rows. The unusual category-speed display adjustment is also preserved. Dates use browser local calendar dates, an explicit adapter rather than legacy history parsing.

## Verification

- 78 unit tests pass, including full-range generation, native arithmetic/formatting, screen geometry, scoring, aborts, validation, report aggregation and atomic persistence.
- Generator checks cover 30,360 lines across alphabetic and full-key ranges.
- Installed-Chrome workflows cover menus/settings, practice, adaptive tutorials, preserved prototype and tests/reports. Tests/reports cover correction, six-line completion, aborts, summaries, report cycling, save/reload/discard, current/history and narrow layout.
- Three DOS references and all 1,588 immutable analysis files match their recorded hashes.
- Captures: [All-keys](screenshots/faithful-test-all-keys.png), [results](screenshots/faithful-test-result.png), [progress](screenshots/faithful-progress.png), [speed](screenshots/faithful-speed-graph.png), [accuracy](screenshots/faithful-accuracy-graph.png).
- Automated typing produces artificially high speeds in captures; these are verification data.

Review corrected threshold calculation to use the temporarily enabled test range before restoring teaching flags. Browser verification also corrected two timing assumptions: the first key is untimed, and short intervals can fall within one BIOS-like clock tick. Tests now create explicit timed observations.

## Limits and next delivery

Complete DOS parity is still open. Native execution, Safari, exact font/audio, complete onboarding, disk-text test slots, long-history normalization/import, instructor features, keypad and game remain unverified or pending. Keypad report cells correctly show no data.

Next bounded delivery: F4c punctuation and numeric lesson progression, including the original new-key guides and teaching branches, before lifting the lesson cap. Then continue fingering/keypad features and native runtime comparisons using disposable DOS copies.

## F4c continuation
Lessons now continue through index 63, using the full-key generator and original reach guides. Reports accept adaptive-keyboard-f4c records alongside earlier records. The lesson cap and F4c next-step references above describe the prior delivery; see [full keyboard lessons](full-keyboard-curriculum.md) for current scope.

## F5a continuation
Keypad tests now share the latest four beginner test rows, Lesson - Keypad has Session/History rows, and graphs use keypad slots 64–74. Keypad categories stay blank as in the original. See [fingering and keypad](fingering-and-keypad.md).

## F5b continuation
Progress now retains four separate Disk-test slots alongside four keyboard/keypad slots. Completed Disk screens contribute to Session practice totals even if a later screen is aborted. See [Disk tests](disk-tests.md) for the current contract and maximum table height.

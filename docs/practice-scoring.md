# F3 — practice screen and scoring

Historical F3 delivery record, 2026-10-23. [F4a](adaptive-curriculum.md) now replaces its fixed drills and unknown focus/ranking fields on the main route; the counter/timing contract below still applies.

This delivery translates the retained REA/Ghidra assembly into a browser typing loop.
It is a JavaScript remake, not a browser DOS emulator. No DOS runtime comparison has been performed.

## Delivered behavior

Choose **Lessons → Practice**. Type each line, then press Enter or Space. Incorrect input advances the
upward pointer and places a red downward marker above the error. Backspace moves back and clears that
position's final error marker. The selected 5/10/15/20 drills setting controls lesson length.
After each drill the lower box shows that drill's integer WPM and accuracy.
The last drill displays End of Lesson; any supported input key, including Escape, opens the summary.
The summary offers the original Continue lessons / Take a practice test / Return to Main Menu choices.
Practice tests remain an explicitly marked F4 action.

Escape during typing returns to Main Menu immediately. Completed drills and timed attempts from the
unfinished line remain in the working session; an unfinished line contributes no final-line score.
Quit → Yes commits settings and practice together; No discards them; Return keeps working.
Closing a dirty tab prompts the browser's ordinary leave-page warning. No automatic save occurs.

The fixed home-key corpus is a **remake fixture**, not the original adaptive generator.
Focus keys and summary key rankings display `--` until F4 recovers the original weights and selection.
The browser note identifies this scope. No stage advancement, guessed key rankings or old prototype
scores are inserted into the faithful result set.

## Static evidence map

Addresses refer to retained `analysis/recovered/0xADDRESS.asm` and paired pseudocode.
The assembly is authoritative when inferred decompiler parameters disagree.

| Function | Evidence used |
| --- | --- |
| 0x12741, 0x13a6d | Practice dispatch; drill count; line calls; accumulating summary; subtract two positions per line for WPM; original next-activity strings |
| 0x14232, 0x14344, 0x14802 | Exercise box (5,22)–(10,57); focus box (13,25)–(15,54); instruction box (17,4)–(20,75); subsequent results box (17,31)–(20,48) |
| 0x14a70, 0x14d5f, 0x14dcd | Input loop; ↑/↓; Backspace clears final error flag; Escape aborts; every accepted input updates timing |
| 0x14b92, 0x14cb5, 0x14cd6 | First-input epoch; raw/smoothed intervals; 500-unit cap; BIOS tick conversion; midnight adjustment |
| 0x14e95 | Completion boundary; CR/Space/Plus acceptance; final error scan; elapsed minus final effective interval |
| 0x14f2b, 0x14f6c | Timed attempts attributed to expected key; zero-interval skips; per-key spaces skipped; correction does not undo attempts |
| 0x1529a, 0x152dc | Integer accuracy and speed helpers; unsigned 32-bit arithmetic and low 16-bit return |
| 0x1b21d | Summary listbox placement, compact layout, keyboard choices |

Original labels and summary choices are generated from verified executable resources by
`scripts/build-faithful-resources.py`. The scoring tests reference the retained assembly anchors.
The immutable first-stage evidence baseline remains unchanged.

## Counter and timing contract

For target length L, finishing the line scans **L + 1** error flags: the characters and one boundary.
Thus C + E = L + 1, including a correct or incorrect final key.
A corrected error no longer contributes to E. The original per-key timed attempt remains recorded.
An early Enter or Tab consumes a character position and normally marks an error.
At the boundary any supported character completes the line; only CR, Space and Plus avoid a boundary error.
The original help recommends Enter or Space; Plus acceptance is established by code.

- Accuracy = floor((100 × C mod 2^32) / ((C + E) mod 2^32)).
- Per-drill WPM = floor((1200 × (C + E − 2) mod 2^32) / T).
- Lesson WPM uses summed C, E and T, subtracting two positions for every completed drill.
- A zero denominator returns zero. Helper results retain their low 16 bits.
- Errors do not directly reduce the WPM numerator. Corrections can add duration.

The clock helper converts BIOS ticks using integer ticks × 549 / 100, approximately centiseconds.
The first input establishes the epoch and has effective interval zero, even if it is Backspace.
For subsequent input, raw = elapsed − previous elapsed. When the preceding raw interval is positive,
effective = trunc((2 × previous raw + 8 × raw) / 10); otherwise effective = raw.
Effective intervals above 500 are capped at 500. **Previous raw** is retained, not the smoothed value.
Final duration T = elapsed − effective interval of the boundary key.
A long pause remains in elapsed time; the cap does not pause the lesson.
Midnight subtraction adds 0x83d600 when the current clock is below the epoch.

Examples with integer clock values:

| Trace for target asd | Clock values | C / E | T | WPM / accuracy |
| --- | --- | --- | --- | --- |
| a s d Enter | 100,200,300,400 | 4 / 0 | 200 | 12 / 100% |
| a x d Space | 100,200,300,400 | 3 / 1 | 200 | 12 / 75% |
| a x Backspace s d Enter | 100,200,300,400,500,600 | 4 / 0 | 400 | 6 / 100% |
| a s [pause] d Enter | 100,200,1200,1300 | 4 / 0 | 920 | 2 / 100% |

In the last trace the d interval is capped at 500. The final interval is 280 because its preceding
raw interval was 1000; it is not derived from the capped 500.

## Browser adaptation and data

`dist/practice.js` is independent of the DOM. Its clock input accepts day-relative integer units.
The browser adapter quantizes monotonic `performance.now()` to nominal PC timer ticks
(65536 / 1193182 seconds), then applies 549/100. This approximates native tick cadence;
DOS tick phase, machine scheduling and browser scheduling are not identical.
There is no automatic pause on blur, focus change or hidden tab. Inactivity counts.
Lines reset their timing; reading time before the first key of each line is excluded.

Browser Shift/modifier events, composition, non-ASCII text and navigation/function keys are ignored;
Ctrl/Meta/Alt browser shortcuts remain available. Enter, Tab, Backspace, Escape and printable ASCII
are handled explicitly. Tab is typing input during practice rather than browser focus navigation.
Complete BIOS extended-key behavior and held-key repeat cadence are not claimed.

The optional `practiceRecords` field extends existing faithful v2 profiles without relabeling old scores.
Each record has its own version 1 and kind `home-keys-f3`, the goal/drill setting snapshot, completed flag,
completed lines/counters, timed expected-key attempts and unfinished-line attempts.
These are raw practice observations for later analysis, **not a complete TT.HIS-compatible profile**.
Original adaptive penalty bytes, category aggregates, historical caps and rankings remain F4 work.
Session settings and record lists use deep copies, so discard and failed saves preserve their boundaries.
Schema validation verifies counters and recomputed totals; corrupt or incompatible saved records are
retained without overwrite. Existing export includes saved data, working records and active-line observations.
Starting/aborting activity marks a working session dirty even when no timed attempt was collected;
retaining such aborted activity records is a documented browser accounting choice.

The earlier v0.1 namespace and app are preserved, including their different attempt-based scoring.

## Fidelity and verification

| Area | Status / evidence type |
| --- | --- |
| Practice boxes, colors, pointer positions, results and summary layout | Static reconstruction; Chrome screenshot review |
| Final accuracy, WPM, correction and timing kernels | Assembly translation; deterministic integer traces |
| Chrome practice, summary, continuation, Escape, export, save/discard/reload | Automated browser observation |
| Native DOS font and PC speaker waveform | Still approximated |
| Adaptive text generation, focus, key rankings, full per-key profile updates | Deferred to F4; visible placeholders |
| Initial home-key fingering introduction and later new-key tutorial screens | Deferred with onboarding/curriculum |
| Live DOS timing/screen comparison; Safari | Unverified |

Run `npm test`, `npm run test:practice`, `npm run test:browser` and `npm run test:prototype`.
The 28 unit tests include 11 practice/scoring cases; Chrome uses project-local Playwright and installed
Google Chrome with temporary profiles. Browser checks stop their own servers.
Representative captures: [practice](screenshots/faithful-practice.png),
[error marker](screenshots/faithful-practice-error.png),
[drill result](screenshots/faithful-practice-results.png),
[summary](screenshots/faithful-practice-summary.png),
[narrow viewport](screenshots/faithful-practice-mobile.png).
The high WPM in automated captures reflects machine-generated test input.

Scaled screen backgrounds are merged across adjacent rows to avoid fractional-scaling seams.
The native glyph raster remains a separate F6 limitation. Historical F1/F2 artifact hashes remain
a receipt of that earlier version; the new F3 receipt describes the current delivery.

Next: recover adaptive penalty weights, key-introduction/focus decisions and original text generation,
then use those to replace the home-key fixtures and enable meaningful key rankings and practice tests.

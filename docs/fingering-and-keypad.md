# F5a — fingering review and numeric keypad

Delivered 2026-10-23. The main browser app now implements Lessons → Fingering, Lessons → Keypad and Tests → Keypad. This is a translation of retained REA assembly with Chrome verification; native DOS runtime comparison remains open.

## Fingering review

The original overview highlights ASDF and JKL; and shows the recovered hand-position instructions. Choose an original reach key to begin its three unscored counterpart drills immediately. On completion, return to the overview; Escape leaves the review.

The learner's pending keyboard introduction is preserved. Review consumes the original random sequence and resets the selected eligible alphabetic key's weight to 255 on completion or tutorial Escape. It does not add timed observations or scored lesson records. Consequently, review changes still belong to the working session and use explicit Quit/save or discard.

## Keypad lessons and tests

The keypad has its own presentation sequence: 4567891230 followed by decimal. The unnamed reference template starts with 456 introduced. Its key samples occupy slots 64–74, separate from the main keyboard's digits and period.

A lesson drill contains three right-aligned numbers. The original Drills option selects 5, 10, 15 or 20 drills per lesson. Numbers are four to nine characters long, selected with adaptive weights from the introduced range. Once decimal is introduced, it replaces the third-last character to form two decimal places.

The next keypad key is introduced when fewer than three currently introduced keypad keys remain unmastered. If the new character appears in the three generated entries, it receives nine untallied reach entries in three groups. The initial home-position explanation and original hand/finger chart are reconstructed.

A keypad test contains 24 entries in four columns of six, entered column by column. It uses the currently learned keypad range and does not introduce keys. It does not automatically enable all digits.

Plus, Enter or Space completes an entry under the shared native line-input rules. Backspace clears a final error marker while timed errors remain recorded. Both normal digit keys and numeric keypad ASCII input work: native input consumes characters, despite toggling DOS NumLock. Mapping physical Numpad codes with NumLock off is an explicit browser adapter; the app does not change the operating system's NumLock state.

## Scoring, reports and storage

Native keypad accounting commits final counters only after an entire three-number drill or 24-number test. An aborted partial drill/test retains timed observations for individual keys, but excludes its incomplete batch from final totals. Tutorial observations remain excluded entirely.

The original lesson display has a speed discrepancy: it subtracts two boundary positions per three-number drill. Progress report speed subtracts two per number. The remake preserves that distinction through separate display totals and stored report totals.

Progress now populates Lesson - Keypad with Session and History. Completed keypad tests share the latest four beginner test rows with keyboard tests. Keypad work does not enter Lesson - Practice totals, and native Letter/Number/Symbol breakdowns remain blank for keypad activity. Speed and Accuracy graphs use the existing eleven keypad columns.

New records use version 1, kind keypad-f5a, and activity lesson or test. Existing faithful v2 profiles gain optional keypad teaching fields when first used. Earlier records and the prototype namespace remain unchanged. Save, reload, discard, failed saves and stale-tab protection retain the current session contract.

## Evidence

| Retained function | Recovered behavior |
| --- | --- |
| 0x1291c → 0x1cd9b | Fingering overview, key selection and preservation of pending introduction |
| 0x14557, 0x14757, 0x16298 | Shared unscored keyboard reach drills and cleanup |
| 0x1282a, 0x12cc6 | Keypad lesson/test dispatch, initial explanation and NumLock handling |
| 0x1cf2e, 0x1d14c, 0x1d1b8, 0x1d2c9 | Keypad outlines, positions, highlights and instruction/stat panels |
| 0x1d368 | Nine unscored keypad reach entries |
| 0x1d6a0 | Three-entry lesson batches, 24-entry tests, final counters and summary discrepancy |
| 0x1def0, 0x1e08c, 0x1e0a7, 0x1e0c9, 0x1e15d, 0x1e1ad | Rankings, separate indices, learned-key filtering, weighted numbers and introduction |
| 0x14f6c, 0x151c5, 0x18c42, 0x18f6e | Per-key updates, category suppression, shared test history and report groups |

[Resource receipt](../analysis/keypad/resources.json) records original string/table offsets, Evidence identifiers, source identities and extraction hashes. Regenerate with npm run resources:keypad. The original files and immutable first-stage analysis are never edited.

## Verification

103 unit tests pass, including 3,600 generated keypad numbers, screen coordinates, review/pending-state preservation, tutorial isolation, corrected errors, completed-batch accounting, displayed/report speed differences, separate report groups, record validation, save/reload/discard and failed-save retention. Earlier generator checks cover 30,360 keyboard lines.

All six installed-Chrome workflows pass. The dedicated keypad workflow checks fingering, nine reach entries, a five-drill lesson, a 24-entry test, corrections, physical Numpad mapping, summaries, Session/History, graph layout, narrow windows, save/reload/discard and the untouched prototype namespace. Its synthetic keyboard events target the focused terminal, matching real keyboard delivery.

Representative captures: [fingering](screenshots/fingering-overview.png), [keypad introduction](screenshots/keypad-intro.png), [lesson](screenshots/keypad-lesson.png), [test](screenshots/keypad-test.png), [summary](screenshots/keypad-summary.png), [progress](screenshots/keypad-progress.png). Automated typing speeds are verification data.

All three DOS reference hashes and all 1,588 immutable evidence files match. Current resource/settings hashes, JavaScript syntax and documentation links pass. Test servers stop after verification; nothing is published.

## Remaining work

Native DOS execution, Safari, exact font/audio, complete onboarding, legacy long-history normalization/import and instructor features remain open. Browser adapter choices are not native runtime observations.

Next bounded delivery: original Disk tests, with recovered file-selection/text behavior and an explicit local browser file adapter. Letter Invaders and its scoring follow as a separate delivery.

## F5b continuation
Disk tests are delivered with a local file picker, original byte/line handling and separate test-history slots. See [Disk tests](disk-tests.md). Next is Letter Invaders and scores.

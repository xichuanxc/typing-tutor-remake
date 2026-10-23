# F5b — original Disk tests

Delivered 2026-10-23. Tests → Disk now implements the recovered file picker, original byte reader and six-line test screens. This is static REA translation plus installed-Chrome observation, not a native DOS runtime comparison.

## Use it

Choose Tests → Disk, then **Choose local test files** below the screen. Select .tst or .txt files. The browser keeps the first eight matching files in selected order and displays stable uppercase DOS-style 8.3 aliases. Use Up/Down or Space to choose, Enter to start, or Escape to return.

The original searches *.tst through DOS directory enumeration. Local file selection, accepting .txt, filename aliases and the 1 MiB per-file limit are explicit browser adapters. No test text is bundled: the supplied three DOS references contain no .TST files. File reads and hashing happen locally in the browser.

The picker does not change the student session. Malformed or unsupported input leaves working data unchanged and allows another selection. Imported file handles last only for the current page lifetime; select them again after reloading.

## Original reader and typing behavior

Plain input follows the DOS seven-bit byte reader: mask the high bit, skip NUL and carriage return, and stop at Ctrl-Z. Tabs, line feeds and other bytes at or below Space act as spacing; they do not force paragraph breaks. Spacing inside lines follows the native token reader, while split-boundary whitespace is removed.

Lines wrap at 72 columns. An overlong first word is cut at 72 and its remaining characters are discarded, following the recovered routine. The EOF-returning line counts even when it has one character or is empty. The existing LineInput defaults remain unchanged; only Disk lines explicitly allow these short targets and preserve unsigned arithmetic.

A first byte of 1 selects the original rotated-byte envelope: a little-endian signed length and the repeating one-through-seven-bit rotation decoder. The native length cutoff excludes the final lookahead byte. No UTF-8 normalization or modern punctuation substitution is applied.

The next screen starts immediately after six completed lines. A final partial screen still requires completing every displayed line, including any blank EOF entry. Each line uses the original first-key timing, correction, terminator and integer scoring rules.

Plain files allow Escape to abort. In rotated-format files, the native input routine treats Escape as a typing error, including at the line boundary. That behavior is retained; the browser session note identifies it even though the original footer label remains unchanged.

## Accounting and storage

Final counters commit after each complete screen. Aborting a later plain-file screen retains earlier screens in Session practice totals. Completed lines and partial timed observations from the unfinished screen remain available for audit, but that screen adds no final totals and no completed Disk-test history row.

Disk results have their own latest-four history slots, alongside the four keyboard/keypad test slots. They do not displace those earlier test rows. The original maximum-height Progress table can place its bottom border on row 24, sharing the footer row; report cycling and Escape still work. This is tested without inventing pagination.

Version 1 disk-test-f5b records contain the display alias, original basename, source byte count/format/SHA-256, committed page counts, completed target lines, timed observations and final totals. Raw input bytes and file handles are not persisted, but completed target text is retained with the results. Saving is explicit through Quit. Discard, failed-save retention, stale-tab handling and earlier records retain the existing session contract.

Unsupported recovered-keyboard characters and truncated rotated envelopes are rejected explicitly. This is a bounded browser implementation rather than a reproduction of native out-of-range memory writes.

## Evidence

| Retained function | Recovered behavior |
| --- | --- |
| 0x12b58 | Disk dispatch, file open/title, repeated pages, completion and Disk-history group |
| 0x1b5b2, 0x1b714 | *.tst enumeration, eight-file limit and original selection behavior |
| 0x1b21d, 0x1b194, 0x1b12a | Picker geometry, width 13, navigation and empty-file dialog |
| 0x15ff7, 0x15fad, 0x1e38e | Text tokens, plain bytes, rotated decoder and EOF boundaries |
| 0x1639e | Wrapping, carry and overlong-word truncation |
| 0x13a6d | Six-line screens, short final screen, per-screen counter commits |
| 0x14a70 | Correction, timing and rotated-file Escape behavior |
| 0x151c5, 0x18c42 | Separate four-slot Disk history and report layout |
| 0x12565 | Original result choices |

[Resource receipt](../analysis/disk/resources.json) records strings, Evidence identifiers and source/output hashes. Regenerate it with npm run resources:disk.

## Verification and limits

All 120 unit tests pass: 103 prior, four picker/resource, ten parser/engine and three report/persistence integration checks. New coverage includes known rotated-byte vectors, whitespace/wrapping, empty/one-character EOF lines, Escape semantics, page aborts, correction samples, separate history slots, source metadata, schema tampering and failed saves.

All seven installed-Chrome workflows pass. Dedicated Disk checks cover the empty/eight-file picker, long-name .txt aliases, multi-page typing without acknowledgement, corrections and boundaries, Disk history beside four keyboard rows, later-page abort totals, rotated Escape errors, malformed-input recovery, empty files, explicit save/reload/discard, narrow layout and the preserved prototype namespace. No page errors remain.

Representative captures: [picker](screenshots/disk-picker.png), [typing](screenshots/disk-test.png), [results](screenshots/disk-result.png), [Progress](screenshots/disk-progress.png), [rotated Escape error](screenshots/disk-rotated-error.png). Capture speeds come from automated input.

The three DOS references and all 1,588 immutable analysis files remain unchanged. Current resource/settings hashes, JavaScript syntax and documentation links pass. Test servers stop after verification; nothing is published.

Native DOS runtime parity, Safari, exact font/audio, complete onboarding, binary history import/normalization and instructor features remain open. Next bounded delivery: Letter Invaders, including original difficulty, playfield, controls, timing, scoring, score table and explicit session persistence.

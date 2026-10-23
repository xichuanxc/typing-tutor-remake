# F4c — full keyboard lesson progression

Delivered 2026-10-23. Lessons → Practice now continues past Z through all 64 presentation entries. This extends the recovered browser teaching engine; the evidence remains static REA assembly plus Chrome observation, with native DOS runtime comparison still open.

## Behavior

The remaining sequence is apostrophe, colon, quotation mark, question mark, exclamation mark, parentheses, hyphen, digits in the original order, then arithmetic and other symbols, ending with caret and underscore. The existing per-key mastery rules choose when to introduce each key. The last index is 63; practice continues there without adding a fictitious next key.

A pending new key receives its guide when it first occurs in the generated scored line. Until then, the pending introduction and original text continuation remain intact. The guide uses the original home counterpart and hand/finger instruction. Three warmup drills precede the scored line. Warmups, including corrected errors, do not update lesson totals, per-key samples or report categories.

Reach drills now accept typing immediately. The previous extra browser acknowledgement has been removed. Home-key and Shift explanation acknowledgements remain. Escape during a reach drill clears the pending introduction, following the original cleanup path; Escape from a scored line which has not yet reached the pending character leaves that introduction pending.

## Retained evidence

| Source | Rule |
| --- | --- |
| [0x15584](../analysis/recovered/0x15584.asm) | Pending key retention, mastery count, presentation through index 63, home/Shift explanations |
| [0x14557](../analysis/recovered/0x14557.asm) | Check pending character in scored text; immediate input; three warmups; cleanup on completion or Escape |
| [0x14757](../analysis/recovered/0x14757.asm) | Counterpart highlight, hand/finger instruction and original positions |
| [0x1bdcb](../analysis/recovered/0x1bdcb.asm) | Counterpart table lookup |
| [0x16298](../analysis/recovered/0x16298.asm) | First alternating group and subsequent shuffled four-key groups |
| [0x13a6d](../analysis/recovered/0x13a6d.asm) | Guide invocation before scored line, normal lesson counters |
| [0x1618a](../analysis/recovered/0x1618a.asm), [0x15a53](../analysis/recovered/0x15a53.asm) | Text continuation versus explicit grammar restart |

There is no separate numeric-specific guide branch in these paths. Punctuation, digits and symbols use the same original reach routine and extracted tables as alphabetic keys.

The review corrected grammar restarts: returning an already pending key does not restart the phrase. Later introductions also retain continuation; the native fresh flag is set for the early home/Shift transition. This matters for delimiters whose closing character occurs on a later line.

## Storage and reports

The existing faithful v2 profile can now save introduced indices through 63. New lessons which reach past index 28 use versioned kind adaptive-keyboard-f4c. Alphabetic lessons retain adaptive-alpha-f4; earlier F3 and prototype records stay unchanged.

Full-key target validation accepts only recovered keys within the recorded introduced range, preserves the 26-character limit and validates counters/observations. Reports include the new records using the existing current/history and category rules. Saving remains explicit through Quit; discard, failed-save retention and stale-tab conflict handling retain the existing session contract.

## Verification

84 unit tests pass. New checks exercise all 35 later-key guides, original counterparts, three untallied drills, delayed key appearance, immediate input, tutorial Escape, phrase continuation, complete full-key lessons, last-key stability, record validation, save/reload/discard and report compatibility. Existing generator checks cover 30,360 lines.

All five installed-Chrome workflows pass. The expanded adaptive workflow uses deterministic saved-state fixtures for apostrophe, digit 4, plus and underscore; it checks keyboard highlights, first-key input, correction, warmup isolation, scored errors, explicit save/reload, History reports and discard. Fixtures represent prior learning, not imported DOS history. The alphabetic-only screenshot fixture now uses unmastered keys so it does not intentionally advance into punctuation.

Captures: [punctuation guide](screenshots/full-key-punctuation-guide.png), [digit guide](screenshots/full-key-number-guide.png), [symbol guide](screenshots/full-key-symbol-guide.png), [last-key guide](screenshots/full-key-last-key-guide.png), [symbol practice](screenshots/full-key-symbol-practice.png).

All three original files remain unchanged, as do the 1,588 retained analysis files. Current resource/settings hashes, JavaScript syntax and documentation links are verified. No test server remains running.

## Remaining work

This completes the bounded F4c lesson extension, not full original-program parity. Full onboarding, native long-history normalization/import, disk texts, fingering review, numeric keypad lessons/tests, instructor features, Letter Invaders, exact font/audio, Safari and live DOS corroboration remain open.

Next bounded delivery: original fingering review and numeric keypad lessons/tests, with their own input mapping, guides, scoring/report integration and persistence checks. Continue using disposable copies if executing the original DOS programme.

## F5a continuation
Original fingering review and numeric keypad lessons/tests are delivered, including separate counters, nine-entry reach warmups and Progress integration. See [fingering and keypad](fingering-and-keypad.md).

# F4a — original alphabetic curriculum

This is the next bounded delivery after F3. Practice now uses recovered adaptive rules and original
word resources instead of the fixed home-key fixtures. It remains a JavaScript remake, with static
REA evidence and browser tests kept distinct from unperformed DOS runtime comparisons.

## Use it

Start the local server as described in README.md, then choose Lessons → Practice.
The initial ASDF fingering screen introduces the home position. Press a key to begin.
Practice introduces J, K, L and semicolon, explains Shift, then introduces the remaining alphabetic
keys in the original presentation order. A new reach key receives three short Home Key Lesson drills;
those tutorials do not enter scored lesson totals or update adaptive samples.

Focus keys now appear in the original box. Lesson summaries show Best Keys, Keys to Work on and
Keys Above the selected WPM goal. The existing 5/10/15/20 drills setting still controls scored drills.
Use Quit → Yes to save both results and teaching state. No discards working changes.

This delivery covers the alphabetic path through introduced index 28 (Z). It also includes semicolon,
period and comma because they appear in that path. The original can go further; the browser currently
continues practice with the learned alphabet at this boundary. The browser note identifies punctuation
and numeric lessons as pending. Tests, report graphs, keypad and Letter Invaders remain separate work.

## Recovered rules

| Area | Original rule translated | Retained assembly |
| --- | --- | --- |
| Timed key observations | Attribute to expected key; exclude first/zero-interval input and per-key spaces; corrections retain attempts | 0x14f2b, 0x14f6c |
| Correct-attempt weight | After updating current samples: min(255, ((old + 3 × trunc(2040 / divisor)) mod 65536) unsigned-shift-right 2), divisor = signed-16-bit current WPM or 1 when zero | 0x14f6c |
| Error weight | min(255, old + floor(old / 32) + 1) | 0x14f6c |
| Current performance | No current attempts needs no extra practice; otherwise compare current WPM to the group threshold and current accuracy to 80% | 0x1531a |
| Saved performance | Check saved speed and accuracy; require at least 30 saved-plus-current correct samples | 0x153a7 |
| Mastery | Introduced key, no pending introduction exclusion, current performance qualifies, and either saved performance qualifies or current correct samples are strictly greater than 30 | 0x1544e |
| Dynamic threshold | Average individual combined saved/current WPM with integer division, multiply by two, divide by four (five after index 28); alpha floor 10, other floor 5; goal cap and signed-16-bit intermediates | 0x154c1 |
| Introduction | Introduce the next key when fewer than four introduced keys remain unmastered; retain pending keys; Shift follows semicolon | 0x15584 |
| Focus and rankings | Rank adaptive weights; lowercase display; best-key ties favor later entries, focus/worst ties preserve earlier entries; retain the native introductory omissions | 0x14427 |
| Keys Above goal | Count current-session individual key speeds at or above the goal; no added accuracy filter | 0x18f6e |

The normal presentation sequence starts:
`asdfjkl;eit.nro,hcpumygwvbxqz`.
There is no whole-lesson 95% promotion rule. A high final drill accuracy alone does not introduce a key:
the individual timed evidence and sample thresholds control that decision.

The rankings are the native insertion algorithm, including its tie/duplicate quirks; they are not a
new statistical ranking. The summary's keys-above value concerns the current session, while threshold
calculation and mastery distinguish current observations from saved history.

## Original word generator

`scripts/extract-curriculum-data.py` validates the verified unpacked executable identity before reading
its data segment. It reads an unnamed history template for initial teaching fields and exports no
named student data. Source/output hashes and resource coverage are retained in
[the resource receipt](../analysis/curriculum/resources.json).

Recovered resources include:

- 51 grammar offsets and 481 grammar bytes.
- 46 dictionary classes × 23 alphabetic levels, referencing 1,058 independently addressed blocks.
- 4,019 encoded word entries; duplicates and proper names remain as stored.
- MSB-first five-bit symbols, including conditional hyphen/period substitutions.
- Character classification/index tables, word-class aliases, guide text, keyboard positions and home-key counterparts.

The alphabetic generator translates the original weighted key/category selection, triangular dictionary
level selection, fallback search, grammar calls, word suffixes, sentence casing/spacing and line carry.
Lines break at the recovered 26-character boundary. It can produce unusual phrases because its resources
and grammar are those recovered from the original programme.

The random helper updates seed = (seed × 0xe4f5 + 0x3619) mod 65536.
For a requested range N it returns floor(N × floor(seed / 256) / 256).
The new teaching state starts with seed zero, matching the observed unnamed template, then saves its
evolving seed. No claim is made that every native onboarding path uses that seed or consumes an identical
number of random calls before the first lesson.

The pure introduction module retains the complete 64-key sequence for continued investigation.
The browser enables only the alphabetic generator path; unimplemented numeric/arithmetic grammar
callbacks cannot silently become substitute text.

## Screens and persistence

The keyboard chart follows 0x1c78e/0x1c831/0x1c98e; the initial explanation and new-home-key guide use
0x12741/0x15584. Shift text comes from 0x15a80. New reach keys use 0x14557/0x14757 and the alternating,
then shuffled, groups recovered from 0x16298. The existing practice screen and scoring remain F3's
reconstruction. A browser guide acknowledgement precedes reach practice; this extra acknowledgement
keeps the instruction visible before typing and is a remake interaction choice.

A versioned optional `curriculum` field extends faithful v2 profiles. It stores introduced/alphabetic
indices, pending introduction/Shift flags, thresholds, 75 weights, current and saved per-key counters,
the random seed and a browser intro acknowledgement flag.
Saving merges current counters into saved counters on a clone, writes once, and only then updates the
working/saved profile. Failure and stale-tab conflict preserve the working state; discard restores the
previous committed snapshot. Save cannot double-count samples on repeated commits.

Older faithful settings and F3 records remain readable. Their records retain kind `home-keys-f3`;
new results use `adaptive-alpha-f4`. Earlier records are not replayed into teaching state because they
were collected under different drill selection. Teaching starts from the unnamed beginner template
while keeping those records available in export. The v0.1 app and its namespace remain untouched.

The browser remembers the initial ASDF explanation after acknowledgement. This is a browser convenience,
rather than a claim to reproduce the native activity-total condition for repeating that screen.
There is no TT.HIS importer or complete legacy history schema. Native long-history normalization,
category aggregates and report arrays are not yet reproduced.

Correction to the earlier settings audit: DS:0x90a6 is the random-generator seed. The two-byte no-save
write in 0x10335 writes that seed, not date bytes. The browser intentionally discards its working seed
together with the rest of an unsaved session. Earlier process entries retain the historical wording;
the current settings document and integrity manifest record the corrected interpretation.

## Checks and remaining work

The deterministic suite checks thresholds, 80% and 30/31 sample boundaries, penalties, integer wrapping,
introduction order, Shift, ranking ties, seed vectors, dictionary inventory, line generation, tutorials,
failed saves, repeated saves, discard and compatibility. It generates 9,360 lines across alphabetic
levels and seeds and checks that they use introduced keys only. That is a browser-remake property test,
not a native runtime trace.

All 52 unit tests and four installed-Chrome workflows pass: menus/settings, practice, dedicated
adaptive tutorials and the preserved prototype. The adaptive check verifies instruction persistence
and D/E highlights before and throughout the three reach drills, plus save/reload/discard and F3 retention.
The test waits for fonts and painted frames before capturing tutorial screens.
Review found and corrected an extra article lookup in callback 33 (native 0x1c63b); its regression
checks that plural formation consumes only the original noun lookup.

| Area | Status |
| --- | --- |
| Alphabetic rules, dictionary resources, generator and key rankings | Static translation with deterministic checks |
| Home position, new home key, Shift, reach drills and save/reload | Browser verification; native glyph raster still approximate |
| Punctuation/number grammar after index 28 | Pending; browser progression deliberately bounded |
| Practice/all-keys tests, progress and per-key report graphs | Next F4 delivery |
| Complete onboarding, native history normalization/import, keypad/game | Pending |
| DOS runtime corroboration and Safari | Unverified |

Run `npm test`, `npm run test:adaptive`, `npm run test:practice`,
`npm run test:browser` and `npm run test:prototype`.
Regenerate curriculum resources with `npm run resources:curriculum`; the app itself needs neither
REA nor Ghidra installed. All browser tooling remains project-local and uses installed Google Chrome.

Representative Chrome captures: [new home key](screenshots/adaptive-home-key.png),
[Shift](screenshots/adaptive-shift.png), [reach practice](screenshots/adaptive-reach.png),
[generated words](screenshots/adaptive-words.png) and [summary](screenshots/adaptive-summary.png).
Automated typing explains the high WPM in these captures; it is not a human performance sample.

Final capture review investigated apparent missing white text in the image preview. Direct decoding
of the PNG confirmed white glyph pixels in the header, target, borders and D/E cells; CSS visibility,
opacity and color also matched. No app rendering fault was established and no speculative rendering
rewrite was made. The actual artifact and pixel evidence take precedence over that preview appearance.

## F4b continuation
Full-key text generation is now active in All-keys tests, alongside six-line Practice tests and Progress/Speed/Accuracy reports. The lesson cap remains index 28. See [tests and reports](tests-and-reports.md) for the current delivery and next scope.

## F4c continuation
The alphabetic boundary is now lifted through all 64 entries. Reach drills accept typing immediately, pending introductions preserve phrase continuation, and tutorial Escape follows original cleanup. The earlier extra-acknowledgement decision above is superseded. See [full keyboard lessons](full-keyboard-curriculum.md).

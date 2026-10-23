# Process and development plan

## Objective
Remake Typing Tutor IV as a simple, useful typing tutor. Preserve its teaching workflow, keyboard operation, and clear feedback. Investigate the original before deciding which behavior to reproduce exactly.

## Working rules
- Keep TT/TT.EXE, TT/TT.HLP, and TT/TT.HIS unchanged. Run DOS experiments on a disposable copy: the original writes history.
- At each meaningful milestone, update this file with changes, evidence, checks, limitations, and the next step.
- Distinguish documented behavior, observed runtime behavior, and remake design decisions. Do not claim parity from help text alone.
- Keep changes small and reviewable. Record dependencies and important design choices before relying on them.
- Validate each milestone before marking it complete. Record failures and deferred work explicitly.
- Keep a runnable preview available once implementation begins. Record how to start it.
- Public GitHub publication was explicitly authorized on 2026-10-24; original DOS references and local tools remain excluded. Earlier local-only boundaries below describe their historical milestones.

## Milestones
| Stage | Status | Deliverable and completion check |
| --- | --- | --- |
| 0. Reference preparation | Complete | Three reference files retained; hashes match source |
| 1. First static recovery | Complete — accepted by owner | REA evidence, menu tables and recovered frame accepted; deeper discovery/runtime parity tracked in the faithful-remake plan |
| 2. Remake design | Complete for v0.1 | Choose target platform, interface direction and first-release scope; specify timing, accuracy, correction and saving behavior |
| 3. First usable typing loop | Complete | Main menu → home-row drill → mistakes/corrections → results; keyboard operation and meaningful scoring tests |
| 4. Teaching and history | In progress | Progressive lessons, practice tests, settings and saved progress; verify persistence and per-key metrics |
| 5. Additional original features | Planned | Fingering, keypad, disk/custom tests, graphs and Letter Invaders in small reviewed increments |
| 6. Finish and acceptance | Planned | Compare agreed workflows with original; usability, regression and packaging checks; document remaining differences |

Stage 5 ordering and instructor-mode scope are provisional. Avoid making every historical feature a prerequisite for a useful first version.

## Decisions
| ID | Date | Decision | Basis |
| --- | --- | --- | --- |
| D001 | 2026-10-22 | Keep only TT.EXE, TT.HLP and TT.HIS in TT/ | Owner instruction |
| D002 | 2026-10-22 | Maintain this log, a feature map and a reference hash manifest | Owner requests a supervised, well-recorded pipeline |
| D003 | 2026-10-22 | Start with original discovery; implement the core typing loop before expansion | Simple, useful programme; original behavior is not yet runtime-verified |

## Activity log
### 2026-10-22 — Import
- Copied /Users/xc/Documents/DosBox_Root/DosGames/DOSUTILS/TT into this project's TT/.
- Verified complete copy against source using diff -rq; no differences.

### 2026-10-22 — Reference cleanup and discovery
- Removed only the project copies of OLD/, TT(已解决Y2K问题).zip, TT.rar, and readme.txt at the owner's request to retain three main files. External source folder untouched.
- Read TT.HLP, inspected file headers and extracted printable executable strings without running the DOS program.
- Established Typing Tutor IV identity and documented its menus, lesson interactions, progress reports and game.
- Recorded SHA-256 hashes and added a reference verification command.
- The removed readme identifies this executable as a TiANWEi Y2K fix. TT.HLP also credits that fix. This is provenance information, not a runtime verification of current-date compatibility.
- Checks passed: exact three-file inventory; byte-for-byte comparison with external source; python3 scripts/verify-originals.py (sizes and SHA-256); all local documentation links resolve.
- Limitations: no DOS runtime observation yet. No dosbox or dosbox-x command found on PATH. No scoring or adaptive algorithm has been reconstructed. The binary history file remains undecoded.
- Next: locate a usable DOS environment, capture the original's welcome/menu/home-row/test/results flow using a working copy, then select the remake platform and implement the first typing loop.

## Open questions to resolve
- Platform resolved: local browser app with a DOS-inspired interface (owner choice).
- Fidelity direction resolved: reproduce original screen layouts, controls and teaching behavior; the owner confirmed the recovered menu frame matches the original.
- Exact speed/accuracy formula, correction penalties and timing rules.
- Adaptive key-selection thresholds and progression rules.
- Whether legacy student history import and instructor tools are needed.

## 2026-10-22 — First usable browser version
- Owner selected a local browser app with a DOS-inspired interface. Decision D004: buildless HTML/CSS/JavaScript, with a pure typing engine and Python loopback static server. Applied the Sites skill's local-only workflow; nothing published.
- Implemented Lessons, Tests, Reports, Options and Help; six selectable practice stages, correction, results, automatic pausing, local history, per-key accuracy and JSON export.
- Decision D005: explicit provisional scoring/progression rules are recorded in docs/remake-design.md. They are not verified as identical to DOS TT.
- Decision D006: owner requested Chrome or Safari. Automated browser checks use installed Google Chrome and this project's Playwright dev dependency. No other project's environment is required.
- Tooling correction: an initial browser-test attempt referenced QuarkPanTool's existing Playwright environment. The owner interrupted it before a test result was obtained. Replaced the unused Python smoke script with a project-local Node/Playwright Chrome script; no QuarkPanTool application code/data was used.
- Checks passed: nine Node core tests; Google Chrome end-to-end workflow test; JavaScript syntax checks; original reference hash verification. Chrome checks cover corrections, completion, progression, tests, pausing/discarding, reload persistence, reports/export, keyboard navigation, mobile-width overflow and isolation of TT files from HTTP serving. No JavaScript page errors.
- Test corrections: floating-point assertion now uses a tolerance; browser menu test now moves upward from Tests to Lessons. Both failures were test expectations, not scoring/navigation implementation changes.
- Evidence: docs/screenshots/main-menu.png, practice-lesson.png, mobile-lesson.png. Browser tests use a fresh temporary profile and stop their server on completion.
- Run: python3 scripts/serve.py, then open http://127.0.0.1:8080 in Chrome or Safari. Core tests: npm test. Browser checks: npm ci then npm run test:browser.
- Limitations: no DOS runtime observation yet; original discovery stays in progress. Safari automation not run. Stage 4 remains in progress because adaptive targeting, detailed speed graphs and original session/history comparison are incomplete. Keypad, Letter Invaders, custom text tests and instructor tools remain planned.
- Next: review the usable loop, obtain DOS runtime evidence, then improve the curriculum and per-key feedback before adding keypad practice and Letter Invaders.

## 2026-10-22–23 — REA machine-code investigation
- Owner requested the official morluto/rea tool to reverse-engineer the original, following feedback that v0.1's redesigned interface differs from DOS TT.
- Decision D007: recover original interface and behavior from machine-code evidence before further visual redesign. Static observations, analyst seeds, reconstruction choices and runtime unknowns must remain distinct.
- Installed REA 6.7.0, its MCP client and Ghidra 12.1.4 in project-local .tools/. Built Ghidra's supplied decompiler for this Mac's ARM64 architecture. Used standalone system JDK 21; no unrelated project environment or global agent configuration changes.
- Confirmed EXEPACK packing. Built David Fifield's exepack 1.4.0 and generated a separate 100,912-byte unpacked analysis copy; the three originals remain unchanged. Artifact/source hashes and tool/dependency versions are retained.
- REA/Ghidra verified the unpacked MZ memory mappings, entry and three relocation fixups. Initial inventory: 250 functions. A reproducible shared-prologue scan supplied 205 analyst seeds; final analyzed inventory: 377 functions.
- Exported pseudocode and assembly for all 377 inventory functions (26,555 assembly lines). Decoded all eight menu records and their callback/submenu mappings. Raw Evidence, IDs, snapshots, readable exports and integrity inventory are retained under analysis/.
- Recovered the 80×25 menu frame, horizontal navigation, header/footer positions, color-attribute packing, practice handlers, correction paths and numerical scoring kernels. Important correction: original line-summary accuracy counts remaining error markers after correction; it is not v0.1's attempt-based metric. Per-key history is separate.
- Generated a clearly labeled static menu-frame HTML/text/PNG from recovered coordinates, labels and attributes. Browser font/name and RGB palette mapping are reconstruction choices. It is not a DOS runtime screenshot.
- Checks passed: reference hashes; verified loaded image; complete export pairing; full decoded table bytes; eight-menu hierarchy; 80×25 frame; Chrome rendering/colors; retained evidence integrity. Trailing-space stripping in the frame verification test was corrected.
- Sessions: initial and seeded REA sessions closed with saved snapshots; terminal sessions exited. No DOS target was executed; no app server started. Browser test used installed Chrome and this project's Playwright.
- Full report: docs/reverse-engineering.md. Remake dist/ code was not changed during this investigation.
- Stage 1 remains in progress: broad static export is complete, but game, history, adaptive thresholds, remaining screen families and runtime conformance are unresolved.
- Next: replace the redesigned menu using recovered tables, reconstruct the practice screen/counters, then compare with the standalone DOSBox-X runtime using disposable copies.

## 2026-10-23 — Stage acceptance, settings audit and next plan
- Owner accepted the first stage and confirmed recovered-main-menu-frame reflects the original display. Recorded as owner visual confirmation, distinct from independent DOS runtime verification.
- Reused retained REA Evidence to trace every Options handler, listbox behavior, name validation, onboarding highlights and Quit persistence. No new provider setup or external project environment needed.
- Recovered WPM tiers 10–19 through 100+; weekly-hour ranges; 5/10/15/20 drills; Sound/No sound; 25-character names; Intro/Help actions. Distinguished blank-history defaults from onboarding selections.
- Mapped the relevant active-profile bytes and 1,996-byte record reads/writes. Options changes remain in memory until Quit's save choice; the no-save path can still update separate date bytes. Full legacy history parsing remains incomplete.
- Added scripts/audit-tt-settings.py, analysis/settings/specification.json and docs/original-settings.md. The audit checks original byte tables and setting writers; it does not claim a live settings session.
- Decision D008: next delivery is the faithful 80×25 display shell plus original Options dialogs and session save semantics (F1/F2), followed by original practice/scoring (F3). Retain v0.1 data and distinguish old metrics. Detailed milestones and acceptance checks: docs/next-steps.md.
- Stage 1 now means the accepted first static-recovery pass; remaining code/runtime investigation stays open in F3–F6. Earlier activity-log entries retain their historical status.
- Application files under dist/ were not changed. No server or DOS runtime was started.
- Checks passed: settings extraction/assembly assertions; option choice counts; all three reference hashes; the first-stage 1,588-file evidence baseline; settings extension integrity; all settings/plan links.
- Next: implement F1/F2 as the next bounded, reviewable delivery; no further platform decision is required.

## 2026-10-23 — F1/F2 faithful browser delivery
- Owner authorized the next bounded delivery. Implemented the recovered 80×25 display shell, all six student menus, original horizontal controls, exact discrete Options choices, name editor, original HLP Introduction/Help and idle instruction panel.
- Built a CP437 glyph mapping and logical cell renderer. The initial menu text matches the accepted recovered frame across all 25 rows. Browser font raster, exact help pagination/idle wrapping and audio waveform remain fidelity limits.
- Decision D009: preserve v0.1 at /prototype/ and its original data key. Use a distinct versioned settings store for the faithful shell; no silent migration or relabeling of old scores. A beginner-style default profile is a documented bootstrap choice, not complete onboarding.
- Implemented working versus saved settings, dirty-session close warning, Quit save/discard/return, failed-save retention and stale-tab conflict handling. The original date-byte no-save write is outside the browser settings model.
- Unfinished faithful practice/test/report/game actions are visibly marked as planned. Existing typing practice remains available via the earlier prototype link. No guessed adaptive logic was added.
- Resources are generated reproducibly from the retained verified executable, menu/settings artifacts and TT.HLP. Original binary references and first-stage analysis files remain unchanged.
- Checks passed: 17 unit tests; full faithful Chrome workflow; preserved prototype Chrome workflow; no JavaScript page errors; JavaScript syntax; original reference hashes; 1,588-file analysis integrity. Screenshots under docs/screenshots/faithful-*.png.
- Validation fixed a focus/redraw mouse-activation bug and scaled-grid rendering/overflow. Browser test expectations were corrected for cell text, option roles, restart routing and resize timing. No unresolved check failure remains.
- Browser checks used project-local Playwright, installed Chrome and temporary profiles. Test-owned servers were stopped; no publication or DOS execution.
- Delivery/fidelity record: docs/faithful-delivery.md. F1/F2 are complete within the defined scope; Safari/runtime parity, original teaching engine and the remaining features are not complete.
- Next: F3 original practice screen, correction/counters and integer timing/scoring traces.

- Final delivery checks passed: all delivered artifact hashes and documentation links resolve. The settings extension manifest records the intentional next-plan revision; the original 1,588-file analysis baseline remains unchanged. No test server is listening on 8765 or 8766.

## 2026-10-23 — F3 original practice screen and scoring core
- Owner requested continuation with the original screen and scoring. Translated retained REA assembly; no new provider/toolchain setup or DOS execution.
- Reconstructed the practice, focus, instruction/results boxes, ↑/↓ markers, Backspace, first-input timing, line boundary and end-of-lesson summary/next-activity dialog.
- Decision D010: distinguish original final-line accuracy from timed expected-key attempts; corrected errors disappear from the former and remain in the latter. Match integer speed, boundary counts, elapsed-minus-final-interval and previous-raw interval smoothing/cap. Do not reuse v0.1 scores.
- Decision D011: keep F3 usable with explicitly labeled home-key fixtures. Adaptive generation, penalty weights, focus and rankings remain F4 work; unknown fields display --. This is a JavaScript remake, not DOS emulation or full runtime parity.
- Extended faithful v2 profiles with separately versioned home-keys-f3 records, including completed drills and aborted-line attempts. Working/save/discard boundaries are deep-copied; old v2 settings load without migration and the prototype store remains untouched.
- Added deterministic scoring/correction/timing, arithmetic, summary, abort, schema/persistence and recovered-coordinate checks. Chrome practice covers wrong/corrected input, early CR, incorrect boundary, five drills, summary/continue, abort, export, explicit save/reload/discard and narrow viewport.
- Initial verification passed: 28 unit tests; practice and existing menus/settings Chrome workflows; no browser JavaScript errors. Reviewed representative Chrome screenshots. Found fractional-scale background seams on green boxes and merged adjacent background runs to remove internal row seams; final checks follow below.
- Evidence/formulas/fidelity matrix: docs/practice-scoring.md. Fixed corpus, browser timer cadence/key mapping, aborted-activity retention, missing adaptive rankings and native font/audio/runtime differences are explicitly documented.
- Next: final regressions/integrity checks, then F4 adaptive key weights/introduction/focus and original text generation; corroborate native behavior with disposable DOS runtime copies.

- Final verification passed after the background fix: all 28 unit tests; installed Chrome practice, menus/settings and preserved-prototype workflows; no page errors; JavaScript syntax; all three original hashes; all 1,588 retained analysis files; current settings extension hashes; documentation links.
- Reviewed final practice/results captures: green row seams removed. Native character border/font raster remains approximate.
- All test-owned servers stopped (8765/8766/8767). No server left running and nothing published. Delivery receipt: analysis/delivery-f3.json; prior F1/F2 receipt is historical.

## 2026-10-23 — F4a alphabetic teaching engine
- Owner requested continuation. Applied the already installed REA reverse-engineering skill and reused retained evidence. Its instruction to split independent evidence questions supported parallel resource decoding and adaptive-state implementation while the main agent integrated grammar, tutorials and persistence.
- Recovered original per-key weights, current/saved mastery checks, 80% accuracy and 30/31 correct-sample boundaries, dynamic WPM thresholds, presentation sequence, focus/best/worst ranking behavior and current-session keys-above-goal count.
- Extracted 51 grammar offsets/481 bytes, 46×23 dictionary addressing, 1,058 independently bounded blocks and 4,019 encoded words. Resources include guide text, keyboard geometry and home-key counterparts. Used only an unnamed history template; no names exported or originals changed.
- Decision D012: main Practice now follows the recovered alphabetic curriculum through introduced index28 (Z), including home-key, Shift and three-drill reach tutorials. Punctuation/numeric grammar callbacks are not substituted or guessed; the visible browser scope identifies them as pending.
- Decision D013: keep current versus saved adaptive counters separate; merge on a cloned profile only during successful explicit Quit/save. Preserve older settings/F3 records and the v0.1 namespace without replaying old observations as adaptive history. New records use adaptive-alpha-f4.
- Reconstructed weighted original grammar, dictionary-level fallback, five-bit word decoding, casing/spacing/line carry and native random arithmetic. Seed starts zero as in the observed unnamed template. Native onboarding random-call parity remains unverified.
- Corrected prior audit interpretation: DS90a6 is the random-generator seed, including the two-byte no-save write in10335, not date bytes. Updated the current settings document/integrity manifest; historical process wording remains visible.
- Review caught callback33 incorrectly adding an article: native1c63b is noun alias7 plus plural only. Fixed that lookup/RNG-consumption error and added a regression. Also rejected negative character indices in the generator's known-key check.
- Initial checks passed:52 unit tests including13 adaptive-state and11 generator/integration cases;9,360 generated lines respect introduced keys; Chrome practice and menus/settings pass with no page errors. Dedicated guide captures and final integrity checks follow.
- Evidence and boundaries: docs/adaptive-curriculum.md and analysis/curriculum/resources.json. This is static translation plus browser observation; no DOS execution or Safari verification.
- Next: complete final guide/persistence browser verification and delivery receipt, then practice/all-keys tests, progress/per-key graphs and remaining punctuation/numeric generation.

- Final checks passed:52 unit tests, all four installed-Chrome workflows (menus/settings, practice, adaptive guides and preserved prototype), JavaScript syntax, three original reference hashes,1,588 immutable REA evidence files, settings/curriculum hashes and local documentation links.
- Dedicated Chrome checks cover home-key/Shift/reach instructions, D/E at recovered coordinates, three tutorial lines excluded from scored/adaptive samples, original-word drills/focus, five-drill rankings, corrected errors, save/reload/discard and exact preservation of earlier F3 records. Fixed a test selector expectation from Main Menu to the original Return to Main Menu label.
- Final screen review caught a real UI omission: the finger instruction disappeared after reach-guide acknowledgement. Moved it into the shared tutorial renderer at original row10 so it stays visible across all three lines; refreshed captures and verified highlights/instruction persistence.
- Investigated an apparent white-text disappearance in image preview. Direct PNG decoding confirmed white pixels in header/target/borders/D/E regions, with visible CSS and RGB255 foreground; no application rendering defect was established. Kept application rendering unchanged, stabilized captures with font/frame readiness, and recorded this evidence distinction.
- Delivery is F4a alphabetic teaching, not completion of all F4 features. Punctuation/numeric generation after index28, practice/all-keys tests, report graphs, native long-history normalization, DOS runtime comparisons and Safari remain open.
- All test-owned servers on8765–8768 are stopped. No production preview/server left running and nothing published. Delivery receipt:analysis/delivery-f4a.json; F1/F2 and F3 receipts remain historical.

## 2026-10-23 — F4b keyboard tests and original reports
- Owner authorized continuation. Reused retained REA assembly and the previously applied reverse-engineering skill; independent resource/generator/screen work was integrated and verified with project-local tooling.
- Delivered original six-line Practice and All-keys tests, width 72, correction markers, independent line timers and result/next-activity dialog. Practice masks the pending new key; All-keys temporarily enables the full keyboard without teaching promotion.
- Completed full-key grammar callbacks for punctuation, paired delimiters, addresses, money, arithmetic and date/time/telephone formats. Preserved native integer/formatting quirks. Alphabetic lesson cap remains index 28 until remaining teaching guides/branches are recovered.
- Delivered Progress, Speed and Accuracy reports with recovered geometry, 75 key columns, Session/History/Both display and original any-key cycling. Reports are read-only. Native low-byte-before-cap graph behavior and category-speed display adjustment are covered by tests.
- Decision D014: retain timed spaces separately for category statistics while keeping individual key arrays space-free. Older adaptive records remain valid with unknown category breakdowns blank. F3 fixtures and prototype scores are retained/exportable and excluded from faithful reports.
- Decision D015: aborted tests retain timed observations but contribute neither completed-test rows nor final session line totals. Completed tests also contribute to the original Lesson - Practice Session aggregate. Latest four completed keyboard tests are shown; disk slots and full native onboarding remain outside this delivery.
- Review corrected threshold recalculation to use the temporarily enabled test key range before restoring teaching flags. Chrome test expectations were corrected for the untimed first key and intervals inside one BIOS-like tick; explicit timed input now makes correction/abort checks meaningful.
- Checks passed: 78 unit tests, including 30,360 generated lines across alphabetic/full-key ranges; all five installed-Chrome workflows (menus/settings, practice, adaptive tutorials, tests/reports, preserved prototype); no browser page errors. Save/reload/discard, failure retention, report cycling, current/history, summaries and narrow layout verified.
- Reviewed current All-keys, Progress and Speed captures; representative results/accuracy/mobile captures retained under docs/screenshots. Machine-driven capture speeds are test data, not human performance.
- Integrity passed: exactly three original DOS references unchanged; all 1,588 retained evidence files match; curriculum/report/settings hashes, JavaScript syntax and local documentation links match. Previous delivery receipts remain historical.
- Current contract: docs/tests-and-reports.md. Next bounded delivery is F4c punctuation/numeric lesson progression and original guides, then fingering/keypad features. Native DOS runtime parity, Safari, complete onboarding/history/import, exact font/audio, instructor features and game remain open.
- No test listener remains on ports 8765–8769. No production server left running and nothing published. Delivery receipt: analysis/delivery-f4b.json.

## 2026-10-23 — F4c full keyboard lessons
- Owner authorized the next delivery. Continued the retained REA investigation using project-local files; an independent read-only audit checked introduction, tutorial, cleanup and keyboard rendering paths. No native DOS execution or toolchain reconfiguration.
- Lifted the lesson boundary from alphabetic index 28 through all 64 presentation entries, ending at index 63. Reused original full-key grammar, counterparts, keyboard coordinates and hand/finger instructions. The same three reach drills apply to punctuation, digits and symbols; no invented numeric guide screen.
- Decision D016: use adaptive-keyboard-f4c records for lessons reaching past index 28. Keep alphabetic/F3/prototype records and their validation rules distinct. Faithful v2 profiles accept the full introduced range; reports include new records and preserve explicit save/discard semantics.
- Matched immediate reach input by removing the previous extra acknowledgement. Home/Shift explanation acknowledgements remain. This supersedes the F4a browser convenience for reach practice.
- Fixed pending-introduction phrase continuation: returning an existing pending key does not restart grammar or drop carried text. Later new-key introductions also retain continuation; explicit early home/Shift fresh transitions remain. Delimiter guides can therefore appear when their character occurs on a later line.
- Matched tutorial Escape cleanup: clear pending key, reset eligible alphabetic weight and retain no tutorial timing/scoring observations. A scored-line abort before the pending character appears preserves that pending key.
- New deterministic checks cover all 35 later-key guides, delayed appearance, counterpart groups, untallied correction/warmups, tutorial abort, phrase continuation, full-key lesson completion, record validation, report compatibility, last-key stability and save/reload/discard.
- Verification exposed assumptions in tests: not every pending key occurs on the first generated line, and a previously mastered Z fixture now correctly advances to punctuation. Revised coverage to follow generated lines/seeds and keep the alphabetic-only screenshot fixture unmastered. No unresolved check failure remains.
- Final checks passed: 84 unit tests; all five installed-Chrome workflows (menus/settings, practice, adaptive/full-key lessons, tests/reports, preserved prototype), with no page errors. The expanded Chrome workflow checks apostrophe, digit 4, plus and underscore guides, immediate first-key input, highlights, corrections, warmup isolation, scored attempt retention, save/reload, History reports and discard.
- Captures retained as docs/screenshots/full-key-*-guide.png and full-key-*-practice.png. Reviewed number/final-key guide and symbol-practice artifacts; automated speeds are verification samples.
- Integrity checks passed: exactly three DOS references unchanged, all 1,588 retained analysis files unchanged, current resource/settings hashes, JavaScript syntax and local documentation links. Prior delivery receipts remain historical.
- Current evidence/contract: docs/full-keyboard-curriculum.md. Next bounded delivery: original fingering review and numeric keypad lessons/tests. Complete onboarding/history/import, disk texts, instructor features, game, exact font/audio, Safari and native runtime corroboration remain open.
- All test-owned listeners on ports 8765–8769 stopped. No production server left running and nothing published. Delivery receipt: analysis/delivery-f4c.json.

## 2026-10-23 — F5a fingering review and numeric keypad
- Owner authorized continuation. Applied the previously read local REA reverse-engineering skill to independent engine and screen questions, then integrated against retained assembly. Project-local Chrome verification remained separate from static findings; no native DOS execution, toolchain setup or external project environment.
- Delivered Lessons → Fingering: original home-key overview, hand instructions and immediate three-drill reach practice. Review preserves the pending keyboard introduction, consumes the original random sequence and performs eligible-letter weight cleanup; it adds no timed observations or scored records.
- Delivered keypad home introduction, original keypad outlines/highlights, weighted four-to-nine-character numeric entries, original 4567891230/decimal introduction, nine untallied reach entries and three-number lesson drills. Drills uses the existing 5/10/15/20 choice.
- Delivered 24-entry Keypad Test in four columns of six. It uses the introduced keypad range rather than enabling every digit; tests do not advance teaching state.
- Decision D017: extend faithful v2 with optional keypad teaching fields and versioned keypad-f5a lesson/test records. Keep keypad samples in slots64–74, separate from main-keyboard digits. Preserve earlier records and the prototype namespace; explicit Quit/save/discard remains the persistence boundary.
- Decision D018: preserve native completed-batch accounting and the displayed-speed discrepancy. Final lesson totals commit only after a complete three-number drill; a test commits after all24 entries. Timed observations from aborted work remain available. Native lesson display subtracts two positions per drill, while reports subtract two per number.
- Progress now includes separate keypad Session/History rows; completed keypad tests share the latest four beginner test rows with keyboard tests. Keypad Letter/Number/Symbol breakdowns remain blank, following native suppression. Existing75-column graphs now receive keypad samples.
- Native input consumes ASCII and toggles BIOS NumLock. Both top-row digit characters and keypad characters work. Physical Numpad code mapping with NumLock off is an explicit browser adapter; it does not change OS NumLock.
- Checks passed:103 unit tests (84 prior plus8 keypad engine,8 fingering/screen,3 report/persistence integration), including3600 keypad-number generation checks in addition to30360 keyboard lines. Original screen positions, learned-range tests, unscored corrections/warmups, aborts, validation, save/reload/discard and failed-save retention verified.
- All six installed-Chrome workflows pass: menus/settings, practice, adaptive/full-key lessons, tests/reports, preserved prototype and dedicated fingering/keypad. Dedicated checks cover pending-key preservation, nine warmups,15 lesson entries,24 test entries, corrected timed errors, separate counters, result dialogs, reports/graphs, History after save, narrow layout and unchanged legacy namespace.
- Browser verification corrected a test-only synthetic-event target: dispatching on document differed from real keyboard delivery and lacked an element target. Dispatching on the focused terminal verifies the actual adapter. Final run also covers NumLock-off digit input and physical NumpadAdd entry completion. No unresolved check failure or page error remains.
- Retained11 new Chrome captures; reviewed fingering overview, keypad intro/lesson/test/summary/progress. Automated capture speeds are verification data.
- Integrity passed: exactly three unchanged original files; all1588 immutable retained evidence files; current curriculum/report/keypad/settings hashes, JavaScript syntax and local documentation links. New resource extraction: scripts/extract-keypad-data.py and analysis/keypad/resources.json.
- Contract and remaining limits: docs/fingering-and-keypad.md. Next bounded delivery is original Disk tests with a documented local file adapter, then Letter Invaders/scoring. Native DOS comparisons, Safari, exact font/audio, complete onboarding/history/import and instructor features remain open.
- All test-owned ports8765–8770 stopped. No production server left running and nothing published. Current receipt:analysis/delivery-f5a.json; earlier receipts remain historical.

## 2026-10-23 — F5b original Disk tests
- Owner authorized continuation with unfinished work. Reused retained REA assembly, with independent parser/engine, picker/resource and browser verification work under the previously applied skill. No DOS execution, toolchain reconfiguration or unrelated project environment.
- Delivered Tests → Disk: recovered empty-file dialog, width-13 picker, eight-file limit, original prompt/navigation and standard results/next-activity dialog. No test text is bundled because no .TST files accompany the three originals.
- Delivered the DOS seven-bit plain reader and rotated-byte envelope, whitespace/token handling, 72-column wrapping, native overlong-word truncation and immediate continuation between six-line screens. EOF-returning one-character and empty lines are counted as in the assembly.
- Decision D019: preserve original short-line integer behavior through explicit LineInput options; existing practice/test defaults remain unchanged. Preserve the packed-file Escape rule: it becomes a typing error rather than aborting. The browser note identifies the behavior while retaining the original footer.
- Decision D020: Disk records use version 1, kind disk-test-f5b, source basename/alias/byte count/format/SHA-256, committed page counts, completed target lines and timed observations. Only completed screens contribute final totals; a later abort retains earlier screen totals in Session practice but adds no completed Disk history row.
- Progress keeps four separate Disk-test slots beside four keyboard/keypad slots. Tested original maximum-height table behavior: its bottom border can share footer row 24. Kept all history rather than inventing pagination or dropping rows.
- Decision D021: use an explicit browser File API adapter. Selected .tst/.txt files retain caller order, receive stable DOS-style aliases and are capped at eight entries and 1 MiB per file. File handles/raw bytes are not persisted; result records retain completed target text and source identity. Input is read locally, with no uploads. Empty/malformed/unsupported loads do not dirty or replace working data.
- Unsupported recovered-keyboard characters and truncated rotated envelopes produce explicit errors rather than native out-of-range writes. Byte decoding is not UTF-8 normalization. Browser choices and static findings are distinguished in docs/disk-tests.md.
- Checks passed: 120 unit tests (103 prior, four picker/resource, ten parser/engine and three report/persistence integration). Coverage includes known rotation vectors, whitespace/wrapping, EOF boundaries, page commits/aborts, packed Escape, correction samples, separate history, source metadata, tamper validation, save/reload/discard and failed-save retention.
- All seven installed-Chrome workflows pass: menus/settings, practice, adaptive/full-key lessons, tests/reports, keypad/fingering, preserved prototype and dedicated Disk tests. Dedicated tests verify picker order/cap/navigation, local aliases, multi-page automatic flow, corrections/boundaries, separate history beside four prior tests, later-page aborts, rotated Escape errors, malformed-input recovery, empty files, save/reload/discard, narrow layout and legacy namespace preservation. No page errors or unresolved failures.
- Eight Disk captures retained; reviewed picker, typing, results, Progress and packed Escape error. Automated typing speeds are verification data.
- Integrity passed: exactly three unchanged DOS references; all 1,588 immutable retained evidence files; current curriculum/report/keypad/Disk/settings hashes, JavaScript syntax and local documentation links. Resource extraction is recorded in scripts/extract-disk-data.py and analysis/disk/resources.json.
- Current contract: docs/disk-tests.md. Next bounded delivery is Letter Invaders: original difficulty, playfield, controls, timing, scoring, score table and persistence. Native comparisons, Safari, exact font/audio, full onboarding/history compatibility and instructor features remain open.
- All test-owned listeners on ports 8765–8771 stopped. No production server left running and nothing published. Receipt: analysis/delivery-f5b.json; earlier receipts remain historical.

## 2026-10-24 — F5c Letter Invaders and global scores
- Continued the authorized unfinished delivery using retained REA exports and project-local tooling. Independent engine, screen/resource and Chrome work was integrated; interrupted screen work was completed locally. No original DOS execution or unrelated project environment.
- Delivered Game → Play with original Practice Keys/Full Keyboard choices, one/two players, second-name entry, round instructions, clipped city/playfield, case-sensitive word targeting/reset, missiles, Boomlets, Word Ships, ground destruction, round results and next-activity dialog. Game → Scores shows the two original five-place tables.
- Decision D022: translate the recovered game loop rather than invent difficulty tiers or lives. Forty payloads per round, shortened intervals with native floors, one update per changed BIOS-like tick, normal/word/special points, ten-point penalties and signed 16-bit bonus intermediate follow retained assembly. Teaching state and typing counters are preserved except the original random seed.
- Escape in play surrenders the active player; another surviving player continues. Escape at a ready/between-round prompt submits remaining scores and returns directly to Main Menu. Preserve native submission order, including duplicate first-player submissions on the recovered death/next-prompt Escape path.
- Decision D023: add optional profile letter-invaders-f5c audit records and global gameScores to faithful v2. Apply ordered submissions to working tables when the whole game finishes; explicit Save commits profile/tables together. No discards both, Return retains both, stale/failed saves retain working data. Strict signed score comparison, stable ties and zero exclusion are preserved. No original history names/scores imported; browser ISO game dates are an adapter.
- Completed screen review corrected %ld replacement, explosion length mapping and bright-red missile attributes. Engine review corrected Word Ship odd-frame movement/fixed aim, per-round generator reset and wrong-control-key penalties. Tests distinguish these assembly-backed behaviors from browser clock/date/font/audio choices.
- Checks passed: 143 unit tests (120 prior +11 engine +6 screen/resource +2 score-table +4 session). Covers fixed seeds, temporary ranges, tick boundaries, word lock, missile points, overlapping ground, Boomlets/ships, signed bonus wrap, ordered submissions, record validation, global tables and explicit/failed/stale save semantics.
- All eight installed-Chrome workflows pass: menus/settings, practice, adaptive/full-key lessons, tests/reports, fingering/keypad, Disk tests, preserved prototype and Letter Invaders. Game checks cover real keyboard input, targeting reset, collision points, penalties, two-player turns, table ties, save/reload/discard, unchanged teaching counters, narrow layout and legacy storage. A browser-test rendering assertion needed bounded event-loop polling under controlled time; no unresolved app failure remains.
- Seven game captures retained under docs/screenshots/invaders-*.png and visually reviewed. Automated scores are verification data. Contract/evidence: docs/letter-invaders.md.
- Integrity checks: three original DOS references unchanged, all 1,588 retained analysis files unchanged, current resource/settings hashes, JavaScript syntax and local documentation links verified. Previous delivery receipts remain historical; current receipt is analysis/delivery-f5c.json.
- All test-owned listeners on ports8765–8772 stopped. No production server left running and nothing published.
- Next bounded task: F6 native comparison with a disposable DOS copy, then onboarding/missing initial.tst and history compatibility, font/audio and Safari. Static recovery and Chrome remake observation do not establish full native runtime parity. Instructor tools remain separate scope.

## 2026-10-24 — First public GitHub release preparation
- Owner explicitly requested a public GitHub repository and first release, superseding the earlier local-only publication boundary. Corrected the public project name to Typing Tutor IV Remake and repository/package name to typing-tutor-remake. Local directory and existing browser storage identifiers stay unchanged for compatibility.
- Prepared https://github.com/xichuanxc/typing-tutor-remake on the authenticated xichuanxc account. Retained v0.2.0 as the first public release version rather than implying finished v1.0 parity.
- Added clone/run/storage instructions, a release record, original-resource provenance and GitHub Actions unit/evidence checks. Original DOS references, personal TT.HIS history, unpacked binaries, local tools, environment files, logs and dependencies are excluded by Git ignore rules. Generated resources and retained static evidence remain available for inspection.
- No blanket open-source license was applied to mixed original-derived resources. This publication does not change the provenance or known fidelity limits of the remake.
- Existing F1–F5c receipts remain immutable historical snapshots. Publication has its own analysis/public-release-v0.2.0.json receipt. Tests and staging checks are recorded there; publication outcome is recorded in GitHub's repository, tag and release.
- Next development remains F6 native fidelity comparison, onboarding/history compatibility, font/audio and Safari. No hosted website or server is part of this publication.
- Publication verification passed: clean staged checkout without TT/, node_modules/ or local tools runs all 143 unit tests and validates all 1,588 baseline evidence files. Current local originals also pass their hash check. Public staging contains 1,773 files before the publication receipt, with no excluded paths or credential patterns. All 135 local documentation links resolve. Source whitespace checks pass outside immutable recovered exports, whose original whitespace is preserved.

## 2026-10-24 — Release held for earlier Intro comparison
- Owner paused release publication to compare the supplied earlier programme under the external OLD folder, starting with TT.HLP. No original executable run. Public xichuanxc/typing-tutor-remake repository and initial commit already exist; GitHub Actions passed. Verified no v0.2.0 release was published after the interrupted command. Further push/release work is held for the Intro review.
- Read both HLP files without modifying or copying originals into TT/. Earlier copy is 12,508 bytes (SHA-256 2584400a6f63f44f9f8cbbecdb30901dc3da44935b6d0c1cec3e1ac12e328140); fixed reference remains 12,651 bytes with its established hash.
- Confirmed the fixed copy adds TiANWEi Y2K credits/contact details and splits the welcome. The email @ is also parsed as a page delimiter. Earlier copy unexpectedly contains 2,134 zero bytes and 477 high bytes, including overwritten Intro prose and a mostly zero-filled Reports/Options span. Cause is unknown; do not infer pristine provenance or execute embedded bytes.
- A candidate formed from the intact earlier welcome plus readable fixed continuation is exactly the earlier file's length and matches all bytes except 0x400–0x800 and 0x2000–0x2800 (end exclusive). This supports reconstruction but does not prove lost wording independently.
- Added reproducible scripts/compare-tt-help.py, analysis/help-comparison/comparison.json, a 17-page intro-reconstructed.txt and docs/help-comparison.md. Draft preserves * and # substitutions and @ pages. Both source files are rechecked unchanged by the script. No application resource changes, no push and no release during this comparison.
- Initial ASCII decoding exposed the non-text bytes; byte comparisons established the exact damaged ranges instead of treating CP437 rendering as valid prose. Existing three reference hashes and retained evidence remain the integrity baseline.
- Next bounded action: review/apply the credit-free Intro reconstruction with provenance attribution and reader pagination verification, then resume first-release preparation when authorized.

## 2026-10-24 — Intact earlier HLP found online
- Owner requested an internet search for an intact original help file. Located Internet Archive item Typing_Tutor_IV_DOS (1987 Kriya Systems attribution; public since October 2016). Retrieved its metadata and only tt.hlp, not its executables or history.
- Download URL: https://archive.org/download/Typing_Tutor_IV_DOS/tt.hlp. Stored in ignored .runtime/help-research/ia-tt.hlp. File is 12,508 bytes; SHA-256 b7dc2e9a7e3c30e8bd817c3c4e4c61f7d03c841784d6f861746d5876afadc8cf. SHA-1 ca89875d21cf47e8a132117d79dbf9ad675b27c0 and MD5 6449edf2a52d837c936d0b53b12822ed match archive metadata.
- Direct byte comparison confirms the entire downloaded file equals the previous credit-free candidate. No zero or high bytes. Both damaged local spans are independently supplied, and the 17-page Intro text exactly matches the draft. This supersedes the earlier reconstruction uncertainty about missing prose.
- Added analysis/help-comparison/internet-verification.json and updated docs/help-comparison.md/original-program.md with source, hashes, evidence and provenance limits. Raw source remains outside Git. No local source reference or application resource changed; no executable run.
- Integrity rechecked: original three references and all 1,588 baseline evidence files remain unchanged. Release remains on hold; no push/release for this research task. Next bounded action is to use the verified Intro in the app and check pagination before resuming release preparation.

## 2026-10-24 — Verified original Intro applied and committed
- Owner authorized using the verified earlier Intro in the current app and committing the result. Updated scripts/build-faithful-resources.py to check the included Intro excerpt against its verification receipt, then replace only Help section zero. Generated dist/original-data.js now restores the full welcome paragraph and removes Y2K-credit/contact fragments from Intro; other Help sections and all original references are unchanged.
- Embedded the Intro source path, SHA-256 and archive URL alongside the existing fixed-help source hash. Retained TiANWEi's historical Y2K-fix credit in THIRD_PARTY.md and documented the comparison/independent archive confirmation. Included the comparison script, evidence receipts and exact verified text with this commit. Raw archive download stays ignored.
- Clarified that 17 @-delimited source parts are grouped by the existing browser reader into seven fitted screens; no reader layout behavior was changed. Options → Intro, Enter through the final screen, PageDown/PageUp and Escape are covered. Reading leaves the session clean and preserves saved/legacy data.
- Verification passed: all 143 unit tests, the expanded installed-Chrome menus/settings workflow with complete Intro-text comparison, first/last screenshots and no page errors, three original hashes and all 1,588 baseline evidence files. The first Chrome assertion inadvertently included box-border characters; scoped extraction to the text area and the full-content check passed. Reviewed the first screenshot. No unresolved failure remains.
- Resource review confirmed only Intro and evidence metadata changed; other generated settings/menu/help fields are identical. Source excerpt matches the archived file's first section exactly. Local documentation links and source syntax checked. Test server on8765 stopped.
- Receipt: analysis/help-comparison/application.json. Previous delivery/publication receipts remain historical snapshots. Commit requested by owner; release publication remains held. Next action is to resume release preparation when requested, then F6 fidelity work.

- Commit verification caught Git's automatic CRLF normalization of the archived Intro excerpt. Added a path-specific -text attribute and restaged its exact DOS bytes so fresh clones retain the verified SHA-256. This affects source preservation, not browser text rendering.
- Fresh staged checkout verification passed all 143 unit tests; its archived Intro bytes and staged Git blob match the verified SHA-256 exactly.

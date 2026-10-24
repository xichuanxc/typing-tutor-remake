# Remake design — first usable version

Recorded 2026-10-22. Platform explicitly chosen by the owner: local browser app with a DOS-inspired interface.

## Structure
- dist/index.html, style.css, app.js: buildless interface and navigation.
- dist/engine.js: pure typing state, drill generation, scoring and aggregation.
- dist/storage.js: versioned localStorage validation and persistence.
- scripts/serve.py: loopback-only static server exposing only dist/.
- tests/engine.test.mjs: deterministic core tests with supplied timestamps.
- tests/browser-smoke.mjs: project-local Playwright driving installed Google Chrome with an isolated test profile.

Python and Node are used only for serving and verification. The application uses browser APIs without runtime dependencies. Playwright is a development dependency pinned through package-lock.json.

## Behavior contract
Documented original interaction: current-character pointer, error pointer, Backspace correction, Enter/Space to end a regular line, lessons/tests/reports/options/help.

Remake decisions below are provisional and do not claim original algorithm parity:
- Lessons contain 1–20 lines (default 10); tests contain 3 lines.
- Lines contain six four-character groups separated by spaces.
- Incorrect printable input advances one position. Backspace removes the preceding visible character.
- Every printable attempt increments the denominator. Correct attempts increment the numerator. Corrections never erase earlier attempts.
- WPM = correct character attempts / 5 / active minutes. Accuracy = correct attempts / all attempts × 100.
- The timer starts on the first printable character and ends on final line confirmation. Reading/reviewing and correcting a line count.
- Escape or leaving the window/tab pauses. Paused time is excluded; after resume timing restarts on the next printable character. Enter/Space-only confirmations after resume add no time until a printable character starts timing again.
- Zero measured duration returns 0 WPM, avoiding nonfinite values.
- Per-key statistics are attributed to the expected key, including errors and spaces.
- Latency samples exclude the first key, first key after pause and first key of each new line. Per-key speed graphs are deferred.
- A completed lesson at >=95% accuracy and >= the WPM goal advances one stage. Tests never advance the stage. Options allows manual selection.
- Six coarse practice stages are a first-version curriculum, not a reconstruction of the original adaptive system.
- Completed exercises save immediately. Incomplete/discarded exercises never save.
- History aggregation weights by total active time and attempts.
- Unreadable storage produces an explicit notice and defaults; data is not overwritten until a save action. Save failures preserve in-memory progress and display a notice.
- Export downloads current settings and history as JSON; import is deferred.

## Boundaries
No hosted services, account system, telemetry or publication. No modification to original DOS references.
Physical keyboard practice is supported. Mobile screenshots check layout, not touch keyboard functionality.
Legacy TT.HIS data is not read by the remake.

## Verification recorded
- Nine core tests passed after fixing an overly strict floating-point assertion.
- Google Chrome automated checks passed for correction, completion, progression, test non-progression, pause/resume/discard, persistence, reports, export, arrow-key navigation, narrow-screen overflow and reference-file HTTP isolation.
- Initial Chrome test navigation expectation was wrong (ArrowDown from Tests selects Reports); changed the test to ArrowUp to select Lessons.
- Screenshots captured in Chrome under docs/screenshots/.
- Safari was not automatically tested.

## F1/F2 update (2026-10-23)
The v0.1 behavior above is preserved under dist/prototype/. The main route now implements the recovered display shell and settings. Read [the current delivery record](faithful-delivery.md) for the distinct v2 settings store, original controls, fidelity matrix and outstanding F3 work.

## F3 update (2026-10-23)
The main app now uses the recovered practice screen, line counters and timing/scoring kernels.
Read [the current scoring contract](practice-scoring.md) for formulas, evidence, browser adapters,
working/saved result semantics and explicit F4 curriculum limits. The v0.1 rules above apply only to the preserved prototype.

## F4a update
The main Practice action now uses recovered alphabetic adaptive rules, original word dictionaries/grammar and key tutorials. Read [the current adaptive contract](adaptive-curriculum.md). F3 fixture records remain distinct and exportable; punctuation/numeric generation, tests and report graphs remain open.

## F4b update
The main route now includes six-line Practice/All-keys tests and original Progress/Speed/Accuracy reports. Tests do not promote teaching position; explicit save merges current observations. Category totals include timed spaces. Aborted tests retain observations but no completed-test totals. See [the current contract](tests-and-reports.md).

## F4c update
Practice now spans all 64 keyboard entries. Full-key lesson records use adaptive-keyboard-f4c; existing alphabetic records remain unchanged. Reach drills start immediately, exclude warmups from scored/timed records, preserve phrase continuation while a key is pending, and clear that pending key on tutorial Escape. See [the full keyboard contract](full-keyboard-curriculum.md).

## F5a update
Fingering review preserves pending introductions and adds no scored records, while retaining native random/eligible-weight changes in the working session. Keypad lessons/tests use separate counters 64–74, optional keypad teaching fields and keypad-f5a records. Only complete three-number drills or 24-number tests contribute final report totals. Physical NumLock-off mapping is a browser adapter. See [the current contract](fingering-and-keypad.md).

## F5b update
Disk tests use the original seven-bit/rotated byte readers and immediate six-line paging. Only complete screens add final counters; aborted work retains timed observations. Disk records have their own four history slots. Local selection, .txt support, DOS filename aliases, a 1 MiB limit and rejection of unsupported characters/truncated envelopes are browser adapters. See [the Disk contract](disk-tests.md).

## F5c update (2026-10-24)
Letter Invaders now uses recovered setup, generation, case-sensitive targeting, tick-driven movement, collisions, ground loss, round bonuses and one/two-player turns. Global Practice/Full score tables are separate from typing counters. Optional gameRecords provide browser audit history; gameScores commits atomically with the profile on explicit Save. Browser clock/date/audio and completion-time table application are documented adapters. See [the game contract](letter-invaders.md).

## Verified original Intro update (2026-10-24)
Options → Intro uses the earlier 17-part text independently confirmed against the archived DOS help. The resource builder checks the source excerpt's SHA-256; other Help content and browser reader grouping remain unchanged. Y2K-fix attribution is preserved in provenance. See [the comparison and source](help-comparison.md).

## Static deployment preparation (2026-10-24)
The owner requested online deployment packaging for proposed tt.xcstudio.dev. The app remains entirely browser-side; static hosting replaces the local Python file server. New implementation is MIT licensed with historical resources separately identified. See [deployment](deployment.md) for the reproducible ZIP, manual Pages workflow, DNS setup and browser-origin storage boundary. No website/DNS change is included in this preparation.

## GitHub-hosted automatic deployment (2026-10-24)
The owner selected GitHub Pages for hosting while retaining tt.xcstudio.dev at Cloudflare. Pages/custom-domain settings are enabled, and pushes to main run tests, package and deploy automatically. Cloudflare DNS access is not connected; the documented tt CNAME and subsequent HTTPS verification are the remaining external setup. The VPS and existing tunnels are not used for this app.

## Game audio and published scope correction (2026-10-24)
The owner reported the missing fast-letter warning. Boomlet sound now uses the recovered pitch sequence and initializes Web Audio from the game-start gesture; mute and special-target removal stop it. The earlier prototype stays in dist/prototype/ for repository/local reference but has no main-screen link and is excluded from static publication. See [game evidence](letter-invaders.md) and [deployment](deployment.md).

## Word Ship audio and literal percent handling (2026-10-24)
Word Ships now use their recovered85-tone melody with quantized rests, sharing special-target mute/lifecycle handling with Boomlets. Summary rendering decodes native printf %% tokens in one pass without reinterpreting substituted text. The scoring engine is unchanged. See [game evidence](letter-invaders.md).

## Game sound coverage (2026-10-24)
All five Letter Invaders effect kinds now map to recovered definitions. Short cues use a single occupied speaker voice; physics frames do not truncate them. Automated event-inventory checks and real-Chrome scenarios replace reliance on manual discovery. Native startup title/audio and general interface feedback remain separate fidelity work. See [the audit](game-sound-audit.md).

## 2026-10-24 — First-user welcome

The owner requested the recovered startup animation/music only when no saved user data exists. The startup module reads faithful/legacy storage without writing a seen flag; corrupt/unavailable storage preserves warnings and bypasses startup. A gesture starts audio, Escape skips, completion/cancellation returns to the main menu. Existing saves bypass it. See [startup evidence, tests and limits](startup-welcome.md); explicit session persistence remains unchanged.

## 2026-10-24 — Explicit browser reset

Owner approved Reset all Typing Tutor data beside Export. A browser-native modal explains deletion of saved profiles/settings/history/scores, earlier prototype data and the current unsaved session, with Export first, Clear data and Cancel. Cancel receives initial focus; Escape closes only the modal. Export uses the existing backup format and leaves confirmation open; import remains unavailable. Clear removes only the two known app localStorage entries, verifies removal, bypasses the existing dirty-session unload prompt only for the confirmed reload, and returns to the fresh welcome. Errors leave the modal/session open and report that removal may be incomplete; localStorage does not provide a multi-key transaction. This is a browser design choice, not a recovered DOS feature.

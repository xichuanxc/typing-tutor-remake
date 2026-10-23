# Next steps — faithful browser remake

Plan recorded 2026-10-23 after the owner accepted the first static-recovery stage and confirmed its menu-frame reconstruction reflects the original.
This plan supersedes v0.1's visual redesign and coarse six-stage curriculum as the target behavior.
The local browser platform and project-local Chrome verification remain unchanged.

## Stage boundary
Completed: reference preservation; first REA/Ghidra static pass; 377 paired function exports;
decoded menus; recovered menu frame; focused Options/settings audit.
Owner feedback is visual acceptance of the recovered frame, not proof of complete runtime parity.

Outstanding research stays visible: complete long-history behavior, live corroboration of timing/counter boundaries,
remaining onboarding screens, complete history format and DOS runtime comparisons.

## Implementation sequence
| Milestone | Work | Evidence / acceptance |
| --- | --- | --- |
| F1. Original display shell — delivered | Replace the redesigned main screen with a fixed 80×25 cell renderer; CP437 glyph mapping; original header, rule, menu bar, descriptions, colors, footer and navigation. Add all student submenu layouts and the idle instruction panel. | Match the accepted recovered frame; verify cell positions and colors; test Left/Right, Space, first-letter activation, Enter, Escape and submenu return. Clearly mark unfinished actions during development. |
| F2. Options and student session — delivered | Recreate vertical choice dialogs, original WPM tiers, weekly goals, 5/10/15/20 drills, sound, name editing, Intro and Help. Separate working settings from committed profile data. Reproduce Quit save/discard/cancel flow. | Compare each dialog with the recovered tables; verify wraparound, initial selection, Enter commit, Escape cancellation, name limits/duplicates and save/reload/discard behavior. Keep v0.1 data recoverable. |
| F3. Original practice loop — delivered core | Rebuild exercise/focus/results boxes, arrows, correction and line ending behavior. Implement the original accuracy/speed kernels and separate final-line counters from per-key attempt records. | Deterministic traces: correct line, uncorrected error, corrected error, repeated Backspace, first-key timing, line terminator, long pause, Escape and summary. Check integer arithmetic and time units against assembly; corroborate unresolved boundaries in DOS. |
| F4. Curriculum and progress — full keyboard lessons, tests and reports delivered | Recover the real presentation sequence, adaptive thresholds and drill generation; add practice/all-key tests, student progress and per-key graphs. | Trace decisions to function Evidence; test key introduction and focus selection with fixed inputs. Compare session/history totals. Do not replace unknown adaptive rules with the old six-stage scheme. |
| F5. Remaining student features — delivered | F5a adds fingering review and numeric keypad lessons/tests; F5b adds original Disk tests with local file selection; F5c adds Letter Invaders and global score tables. Treat instructor features as a separate scope item. | Validate each feature's layout and behavior individually; document compatibility differences and missing original resources. |
| F6. Fidelity and release review | Compare core flows against the running original and the accepted visual references; finish font/glyph rendering, sound and browser behavior. | Reproducible comparison captures and a remaining-differences list. Verify Chrome, manually check Safari, and confirm saved data/export behavior. Packaging remains local unless separately requested. |

F1 and F2 are complete for the scoped menus/settings delivery. See [the delivery record](faithful-delivery.md) for verification and remaining fidelity limits. The F3 practice/scoring core is delivered; see [its evidence and limits](practice-scoring.md). F4a replaces those fixtures with recovered alphabetic progression, original dictionary/grammar drills, key tutorials and focus/summary rankings; see [the current adaptive delivery](adaptive-curriculum.md). F4b adds six-line Practice/All-keys tests, full-key text generation and Progress/Speed/Accuracy reports; see [tests and reports](tests-and-reports.md). F4c extends lessons through punctuation, digits and symbols to index 63; see [full keyboard lessons](full-keyboard-curriculum.md). F5a delivers [fingering and keypad lessons/tests](fingering-and-keypad.md), including separate report counters. F5b adds [original Disk tests](disk-tests.md), including separate history and complete-screen accounting. F5c adds [Letter Invaders and global score tables](letter-invaders.md), including two-player turns and explicit score persistence. Live DOS corroboration remains open.

Runtime comparison can proceed alongside static reconstruction when useful. It is not a prerequisite for every known screen.
Use the standalone DOSBox-X installation only with disposable copies of TT; preserve hashes before and after.

## Decisions for the next delivery
- Keep the original layout and vocabulary. Browser resizing scales the character grid; it does not rearrange menus into cards.
- Support physical-keyboard operation throughout, with mouse support as an additional convenience.
- Preserve the accepted frame as the first visual baseline. Font rasterization remains a separate fidelity issue; record any temporary approximation.
- Use the recovered menu/settings tables as data, keeping rendering, typing logic and storage independent.
- Match the original option choices rather than arbitrary numeric inputs.
- Distinguish student goal settings from the adaptive teaching state. A manual six-stage selector is not an original Options feature.
- Maintain working versus saved profiles. On Quit: Save commits; Do not save discards session changes; Cancel resumes. A browser-tab close cannot guarantee showing the original Quit dialog, so document that browser limitation and avoid silently claiming autosave equivalence.
- Preserve v0.1 records under their existing schema or provide an export/migration path. Old attempt-based scores must not be relabeled as original-compatible results.
- Keep original binary history import outside F1/F2. Its partial field map is useful evidence, not a complete importer specification.
- Intro and Help use original content/section boundaries; handle the HLP placeholders deliberately.
- Do not implement guessed game/scoring/curriculum behavior to fill unknowns.

## Checks and supervision
At each milestone, record:
1. What changed and which recovered function/table supports it.
2. A runnable local preview and representative screenshots.
3. Checks passed and any failed/revised assumptions.
4. Remaining differences and the next bounded task.

Keep a short fidelity matrix with evidence type: static observation, owner confirmation, runtime observation or remake decision.
Use the existing prototype's tests only where their expectations still apply; revise conflicting scoring/navigation tests explicitly.
Do not mark full original discovery or full programme parity complete merely because the first static pass is accepted.

## Before F1 implementation
- Reference/data-integrity checks pass.
- Owner's platform choice and fidelity direction are recorded.
- Original settings spec is available at analysis/settings/specification.json.
- No further platform/framework selection is needed. Continue with buildless HTML/CSS/JavaScript.

## Next bounded delivery after F5c
F6 begins with a reproducible fidelity audit of core screens, input and timing against the original running in a disposable working copy. Record native observations separately from static findings and Chrome remake captures. Then address complete onboarding (including missing initial.tst behavior), history compatibility, font/audio and Safari. Keep all eight Chrome workflows and current records as regression baselines. Instructor features remain separate scope; packaging stays local.

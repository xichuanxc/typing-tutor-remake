# Resource provenance

Typing Tutor IV Remake reconstructs the DOS Typing Tutor IV interface and teaching behavior. The original programme's branding, help text, dictionaries, screen strings and data tables are the sources of the generated resources in dist/*-data.js and portions of the retained static analysis. Comments, extraction scripts and analysis/*/resources.json identify these sources.

The public repository excludes TT.EXE, TT.HLP, TT.HIS, unpacked executables and local reverse-engineering tool installations. No original students' named history or high-score tables are imported into the browser app.

The new implementation is open source under MIT; see LICENSE and COPYING.md for scope. This grant does not claim ownership of or relicense the original programme, branding or recovered content.

Development uses Playwright (Apache-2.0), installed separately through npm. Reverse-engineering work used [REA](https://github.com/morluto/rea), [Ghidra](https://github.com/NationalSecurityAgency/ghidra) and [David Fifield's exepack](https://www.bamsoftware.com/software/exepack/). Their installations are not bundled; toolchain versions and source locations are recorded in analysis/toolchain.json.

The local reference copy of TT.HLP credits TiANWEi (January 2000) for a Y2K fix. The app's Intro now uses the earlier 17-part text, independently verified against [the archived DOS help](https://archive.org/download/Typing_Tutor_IV_DOS/tt.hlp). Other Help sections still derive from the preserved fixed reference. The programmer's historical credit is retained here and in the source-comparison record rather than displayed as original Intro prose.

# Resource provenance

Typing Tutor IV Remake reconstructs the DOS Typing Tutor IV interface and teaching behavior. The original programme's branding, help text, dictionaries, screen strings and data tables are the sources of the generated resources in dist/*-data.js and portions of the retained static analysis. Comments, extraction scripts and analysis/*/resources.json identify these sources.

The public repository excludes TT.EXE, TT.HLP, TT.HIS, unpacked executables and local reverse-engineering tool installations. No original students' named history or high-score tables are imported into the browser app.

This repository does not claim ownership of the original programme or grant a license to its materials. No blanket open-source license has been applied to this mixed-source release.

Development uses Playwright (Apache-2.0), installed separately through npm. Reverse-engineering work used [REA](https://github.com/morluto/rea), [Ghidra](https://github.com/NationalSecurityAgency/ghidra) and [David Fifield's exepack](https://www.bamsoftware.com/software/exepack/). Their installations are not bundled; toolchain versions and source locations are recorded in analysis/toolchain.json.

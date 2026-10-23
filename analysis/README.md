# Reproducing the REA analysis

Read docs/reverse-engineering.md first. This is a project-local CLI/MCP workflow; it does not require registering REA globally.

The exact package manifests are under analysis/toolchain/. Restore them into .tools/rea/ and run npm ci there.
The official REA package and MCP client versions are pinned by that lock.
Ghidra and EXEPACK source URLs, archive hashes, versions and native build flags are in analysis/toolchain.json.

1. Download the pinned Ghidra archive from its recorded official release; verify its SHA-256 before extracting under .tools/.
2. Build its supplied decompiler on macOS ARM64 using the recorded command; copy ghidra_opt to Ghidra/Features/Decompiler/os/mac_arm_64/decompile.
3. Download/build exepack 1.4.0 from the recorded author source; verify the recorded source archive SHA-256.
4. Run .tools/exepack-1.4.0/target/release/exepack -d TT/TT.EXE analysis/derived/TT.unpacked.exe.
5. Verify that the unpacked SHA-256 matches analysis/toolchain.json.
6. Run python3 scripts/seed-tt-analysis.py.
7. Run node scripts/rea-session.mjs --seeded and send newline-delimited tool requests. Inputs and output files for the completed investigation are retained in analysis/rea/*.json.
8. After opening the exact unpacked path with provider_id ghidra, use binary_overview, list_procedures and targeted assembly/pseudocode tools. All addresses are linear analysis coordinates.
9. Use close_binary with a new absolute snapshot_path when finished; then send EOF if needed.
10. Run python3 scripts/export-tt-analysis.py to regenerate the readable exports from the retained responses.
11. Run node scripts/check-tt-analysis.mjs for the recovered-frame Chrome check.
12. Run python3 scripts/verify-originals.py and python3 scripts/verify-tt-analysis.py for reference/evidence integrity.

The drivers currently select this machine's standalone OpenJDK 21 path; adjust that setting for a different machine and record the new toolchain.
The retained snapshots are observations, not permanent Ghidra projects or proof of exhaustive disassembly.
Raw function Evidence is saved separately, so re-reading existing results needs no running analysis provider.

No global configuration or tools in unrelated projects are needed. .tools/ and analysis/derived/ are ignored by Git; retained Evidence, scripts, reports and dependency locks remain project artifacts.

## Public release boundary

The public repository includes retained evidence, scripts and generated browser resources. Original files under TT/, unpacked executables under analysis/derived/, local tools, logs and browser saves are excluded. Running the app and npm test requires no DOS references. Regenerating resources and verifying the original-file hashes requires separately supplied local references; historical delivery receipts intentionally retain those reference identities.

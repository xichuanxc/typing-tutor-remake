"""Run project-local REA CLI with its dedicated Ghidra installation."""
from pathlib import Path
import os
import subprocess
import sys

root = Path(__file__).resolve().parents[1]
env = dict(os.environ,
    GHIDRA_INSTALL_DIR=str(root / ".tools/ghidra_12.1.4_PUBLIC"),
    JAVA_HOME="/opt/homebrew/opt/openjdk@21/libexec/openjdk.jdk/Contents/Home",
    REA_GHIDRA_STARTUP_TIMEOUT_MS="300000")
raise SystemExit(subprocess.call(["node", str(root / ".tools/rea/node_modules/rea-agents/scripts/rea.mjs"), *sys.argv[1:]], env=env))

/* ev_3b3022fdd59878b19dd6aff1c45d9361cbf7d82a0d34fbf24ee08e379a919222 */

uint __cdecl16near FUN_1000_e31a(undefined2 param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = FUN_1000_e3ce(param_1);
  if ((uVar1 != 0xffff) && (iVar2 = FUN_1000_e3ce(param_1), iVar2 != -1)) {
    return iVar2 << 8 | uVar1;
  }
  return 0xffff;
}


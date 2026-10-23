/* ev_3a38db09a64c2e42b70de0710faea1f9ebb1d02ed301b05e90c1c5e6555425cb */

uint __cdecl16near FUN_1000_e913(undefined2 *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined2 unaff_DS;
  
  uVar2 = 0;
  if (param_1 == (undefined2 *)0x0) {
    uVar2 = 0xffff;
  }
  else {
    if (*(char *)(param_1 + 3) != '\0') {
      if ((*(byte *)(param_1 + 3) & 4) != 0) {
        uVar2 = FUN_1000_e983(param_1,0xffff);
      }
      uVar1 = FUN_1000_f416((int)*(char *)((int)param_1 + 7));
      uVar2 = uVar2 | uVar1;
      if ((*(byte *)(param_1 + 3) & 2) != 0) {
        FUN_1000_ec0b(param_1[2]);
      }
      if ((*(byte *)(param_1 + 3) & 0x20) != 0) {
        FUN_1000_f44d(*(undefined2 *)((int)param_1 + 0xb));
        FUN_1000_ec0b(*(undefined2 *)((int)param_1 + 0xb));
      }
    }
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    *(undefined1 *)(param_1 + 3) = 0;
  }
  return uVar2;
}


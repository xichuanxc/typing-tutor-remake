/* ev_cc6fbd2e62f134e8cb58ff2eccfcd678966427170d3c77fc8571e25e6f1c1151 */

int __cdecl16near FUN_1000_efbb(undefined2 param_1,uint param_2)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  undefined2 unaff_DS;
  
  uVar3 = param_2 & 3 | 0x3d00;
  if ((param_2 & 0x200) != 0) {
    uVar3 = 0x3c00;
  }
  iVar2 = FUN_1000_f156(uVar3,param_1,0);
  if (iVar2 == -1) {
    if ((param_2 & 0x100) != 0) {
      iVar2 = FUN_1000_f156(0x3c,param_1,0);
    }
  }
  else if ((param_2 & 0x400) != 0) {
    FUN_1000_f416(iVar2);
    *(undefined2 *)0x8f00 = 0x13;
    return -1;
  }
  if (-1 < iVar2) {
    if ((param_2 & 0x800) != 0) {
      FUN_1000_f42e(iVar2,0,0,2);
    }
    uVar1 = FUN_1000_f592(iVar2);
    *(undefined1 *)(iVar2 + -0x70e0) = uVar1;
  }
  return iVar2;
}


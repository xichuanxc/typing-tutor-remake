/* ev_3b2120adcca52b03681caa461e7d0a4df273d84ce39a39c252215d7368f4656f */

int __cdecl16near FUN_1000_e15d(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_DS;
  
  iVar2 = FUN_1000_bd74(6);
  iVar2 = iVar2 + 4;
  for (iVar3 = 0; iVar3 < iVar2; iVar3 = iVar3 + 1) {
    uVar1 = FUN_1000_e0c9(0x2116);
    *(undefined1 *)(param_1 + iVar3) = uVar1;
  }
  iVar3 = FUN_1000_e0a7(0x2e);
  if (iVar3 != 0) {
    *(undefined1 *)(param_1 + iVar2 + -3) = 0x2e;
  }
  *(undefined1 *)(param_1 + iVar2) = 0;
  return param_1;
}


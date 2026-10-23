/* ev_5dc4c189a7266f7988afca4cdd6d2bd1c96454af2cf3aed188db7eb6b83c58f2 */

int __cdecl16near FUN_1000_57cc(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int unaff_BP;
  uint uVar4;
  int iVar5;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar5 = 0;
  for (uVar4 = *(uint *)(unaff_BP + 4);
      ((int)uVar4 < *(int *)(unaff_BP + 6) && (uVar4 <= *(byte *)0x90af)); uVar4 = uVar4 + 1) {
    iVar1 = FUN_1000_544e(uVar4);
    if ((iVar1 == 0) && ((0x15 < *(int *)(unaff_BP + 4) || (0x1c < (int)uVar4)))) {
      uVar2 = (uint)*(byte *)(uVar4 + 0x90bb) * 7;
    }
    else {
      uVar2 = (uint)*(byte *)(uVar4 + 0x90bb);
    }
    iVar5 = iVar5 + uVar2;
  }
  iVar1 = FUN_1000_bd74(iVar5);
  iVar5 = *(int *)(unaff_BP + 4);
  for (; -1 < iVar1; iVar1 = iVar1 - uVar4) {
    iVar3 = FUN_1000_544e(iVar5);
    if ((iVar3 == 0) && ((0x15 < *(int *)(unaff_BP + 4) || (0x1c < iVar5)))) {
      uVar4 = (uint)*(byte *)(iVar5 + -0x6f45) * 7;
    }
    else {
      uVar4 = (uint)*(byte *)(iVar5 + -0x6f45);
    }
    iVar5 = iVar5 + 1;
  }
  return iVar5 + -1;
}


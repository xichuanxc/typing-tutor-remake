/* ev_ab84f6590602eafe990802da1f190ee867328cf8565a8a81bd713978b696e09d */

void __cdecl16near FUN_1000_b0a9(void)

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  iVar1 = *(int *)(unaff_BP + 4);
  if (iVar1 == -1) {
    FUN_1000_f7da(*(undefined2 *)(unaff_BP + 8),*(int *)(unaff_BP + 10) + 2);
  }
  else if (iVar1 == 0) {
    iVar1 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 6));
    FUN_1000_f7da(*(undefined2 *)(unaff_BP + 8),
                  (((*(int *)(unaff_BP + 0xc) - *(int *)(unaff_BP + 10)) + -3) - iVar1) / 2 +
                  *(int *)(unaff_BP + 10) + 2);
  }
  else if (iVar1 == 1) {
    iVar1 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 6));
    FUN_1000_f7da(*(undefined2 *)(unaff_BP + 8),(*(int *)(unaff_BP + 0xc) + -1) - iVar1);
  }
  FUN_1000_f6a4(0x8510,*(undefined2 *)(unaff_BP + 6));
  return;
}


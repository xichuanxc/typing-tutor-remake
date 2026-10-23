/* ev_ad12449ae7e1326d64614feb13addf868638c3e725f0ddca9d117ec24990f626 */

void __cdecl16near FUN_1000_c98e(void)

{
  char cVar1;
  int iVar2;
  undefined2 uVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if (*(char *)(unaff_BP + 8) < '!') {
    return;
  }
  if (*(char *)(unaff_BP + 10) == '\x01') {
    FUN_1000_b1f3(1,1,7);
  }
  else {
    FUN_1000_b1f3(0,1,2);
  }
  iVar2 = FUN_1000_722b((int)*(char *)(unaff_BP + 8));
  cVar1 = *(char *)(iVar2 * 2 + -0x7746);
  *(int *)(unaff_BP + -2) = (int)*(char *)(iVar2 * 2 + -0x7745);
  iVar2 = cVar1 * 2;
  FUN_1000_f7da((uint)*(byte *)(unaff_BP + 4) + iVar2 + 2,
                (uint)*(byte *)(unaff_BP + 6) + *(int *)(unaff_BP + -2) / 3 + iVar2 +
                *(int *)(unaff_BP + -2) + 3);
  uVar3 = FUN_1000_e793((int)*(char *)(unaff_BP + 8));
  FUN_1000_f873(uVar3);
  FUN_1000_b1f3(0,1,7);
  return;
}


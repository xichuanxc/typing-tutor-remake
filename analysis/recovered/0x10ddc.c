/* ev_0759850f0b2306647142fd5d8aed7cc88b52fea77a84901f270cd54dc99c015f */

undefined2 __cdecl16near FUN_1000_0ddc(void)

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  *(undefined2 *)0x9d34 = 1;
  FUN_1000_2723(0x843);
  iVar1 = FUN_1000_0d63(*(undefined2 *)(unaff_BP + 4));
  if (iVar1 == -1) {
    return 0xffff;
  }
  FUN_1000_e247(*(undefined2 *)0x9070,(long)*(int *)(unaff_BP + 4) * 0x7cc,0);
  FUN_1000_e1f4(0x9072,1,0x7cc,*(undefined2 *)0x9070);
  FUN_1000_e74e(0x9072,*(undefined2 *)0x6d5);
  return *(undefined2 *)(unaff_BP + 4);
}


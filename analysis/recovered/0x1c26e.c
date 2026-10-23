/* ev_a6993941b9d83bed684f83b17852bacfa2ea1e3541b5b0a299ff3865b232df8b */

void __cdecl16near FUN_1000_c26e(void)

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar1 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 4));
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + iVar1;
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + -1;
  if (*(char *)*(undefined2 *)(unaff_BP + 4) != 'e') {
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  }
  FUN_1000_e74e(*(undefined2 *)(unaff_BP + 4),0x85f4);
  return;
}


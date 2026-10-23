/* ev_04b0d191642782478f787abb55536948b2731ea2b750b4ec2072a84a4c142826 */

void __cdecl16near FUN_1000_c29a(void)

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
  FUN_1000_e74e(*(undefined2 *)(unaff_BP + 4),0x85f7);
  return;
}


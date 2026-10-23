/* ev_20d00753d66f6034e8518469b98a4b1e7ee65652437357407ff707d249eb7fb1 */

void __cdecl16near FUN_1000_c22d(void)

{
  undefined1 *puVar1;
  int iVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar2 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 4));
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + iVar2;
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  if ((puVar1[-1] == 's') || ((puVar1[-1] == 'h' && ((puVar1[-2] == 's' || (puVar1[-2] == 'c'))))))
  {
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = 0x65;
  }
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = 0x73;
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  return;
}


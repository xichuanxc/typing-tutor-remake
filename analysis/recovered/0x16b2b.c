/* ev_cf1ae2bd2c42352dc4c36fee6c97df4e3e7f6551b60efaedb4040629d5c970ed */

void __cdecl16near FUN_1000_6b2b(void)

{
  undefined1 *puVar1;
  int iVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = 0x24;
  *(undefined2 *)(unaff_BP + -2) = *(undefined2 *)(unaff_BP + 4);
  FUN_1000_73cc(unaff_BP + 4);
  for (iVar2 = FUN_1000_bd74(8); 0 < iVar2; iVar2 = iVar2 + -1) {
    FUN_1000_73ad(unaff_BP + 4);
  }
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  FUN_1000_74ab(*(undefined2 *)(unaff_BP + -2),1);
  iVar2 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 4));
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + iVar2;
  return;
}


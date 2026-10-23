/* ev_85db2897384851ae388473ca5647c318d9e42c197258179b35f14e53ff575944 */

void __cdecl16near FUN_1000_8497(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  *(char *)(unaff_BP + 6) = *(char *)(unaff_BP + 6) + '\x01';
  while (*(byte *)(unaff_BP + 6) <= *(byte *)(unaff_BP + 8)) {
    FUN_1000_f7da(0x16 - (uint)*(byte *)(unaff_BP + 6),*(undefined1 *)(unaff_BP + 4));
    FUN_1000_f873(*(undefined1 *)(unaff_BP + 10));
    *(char *)(unaff_BP + 6) = *(char *)(unaff_BP + 6) + '\x01';
  }
  return;
}


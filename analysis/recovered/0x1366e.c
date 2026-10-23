/* ev_a545e9e0b8b411f8891b88f927bbecac71d83fb858ce2203b5196d830ec64423 */

void __cdecl16near FUN_1000_366e(void)

{
  byte bVar1;
  byte bVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  *(undefined1 *)(unaff_BP + -1) = 0;
  if (*(char *)0x17a5 != '\0') {
    FUN_1000_2692(*(undefined2 *)((uint)*(byte *)(unaff_BP + 4) * 0x1f + 0x134c),
                  *(undefined2 *)(unaff_BP + 8));
    FUN_1000_b1f3(0,5,7);
    FUN_1000_f7da(3,0);
    FUN_1000_f74a();
    while (*(byte *)(unaff_BP + -1) < *(byte *)((uint)*(byte *)(unaff_BP + 4) * 0x1f + 0x134e)) {
      bVar1 = *(byte *)(unaff_BP + 4);
      bVar2 = *(byte *)(unaff_BP + -1);
      *(char *)(unaff_BP + -1) = *(char *)(unaff_BP + -1) + '\x01';
      FUN_1000_f6a4(*(undefined2 *)((uint)bVar1 * 0x1f + (uint)bVar2 * 2 + 0x134f));
      FUN_1000_f6a4(0x1a45);
    }
    FUN_1000_394a(*(undefined1 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + 6));
  }
  return;
}


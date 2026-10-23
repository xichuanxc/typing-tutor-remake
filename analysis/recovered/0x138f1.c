/* ev_4ae3bae754b74a2e38d20f5ac82a64ac747cccbb3ceaf78b35d6eda6bbcf2f17 */

ulong __cdecl16near FUN_1000_38f1(void)

{
  undefined2 uVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  uVar1 = FUN_1000_e793(*(undefined2 *)(unaff_BP + 6));
  *(undefined2 *)(unaff_BP + 6) = uVar1;
  *(undefined1 *)(unaff_BP + -1) = 0;
  while( true ) {
    if (*(byte *)((uint)*(byte *)(unaff_BP + 4) * 0x1f + 0x134e) <= *(byte *)(unaff_BP + -1)) {
      return 0xffff;
    }
    if ((int)*(char *)*(undefined2 *)
                       ((uint)*(byte *)(unaff_BP + 4) * 0x1f + (uint)*(byte *)(unaff_BP + -1) * 2 +
                       0x134f) == *(int *)(unaff_BP + 6)) break;
    *(char *)(unaff_BP + -1) = *(char *)(unaff_BP + -1) + '\x01';
  }
  return (ulong)*(byte *)(unaff_BP + -1);
}


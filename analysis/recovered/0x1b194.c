/* ev_a41c97bd1342e62b4e05a3093098ff498f607b4eedef58f5e4205647cbed4c1c */

void __cdecl16near FUN_1000_b194(void)

{
  uint uVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  *(undefined1 *)(unaff_BP + -1) = (char)(0x19 - *(byte *)(unaff_BP + 8) >> 1);
  uVar1 = 0x50 - *(byte *)(unaff_BP + 6) >> 1;
  *(undefined1 *)(unaff_BP + -2) = (char)uVar1;
  FUN_1000_b12a(*(undefined2 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + -1),
                *(undefined1 *)(unaff_BP + -2),
                (uint)*(byte *)(unaff_BP + -1) + (uint)*(byte *)(unaff_BP + 8) + -1,
                (uVar1 & 0xff) + (uint)*(byte *)(unaff_BP + 6) + -1);
  return;
}


/* ev_d960fb6e84726f8a3b687d1c18c7de9f3233162c1a862725357363abde9a73e2 */

void __cdecl16near FUN_1000_5c49(void)

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  iVar1 = FUN_1000_b5b2(0xffe,1,0,unaff_BP + -0x1c);
  if (iVar1 == -1) {
    return;
  }
  if (*(int *)(unaff_BP + -0x1c) == 0) {
    FUN_1000_b194(0x12fb,0x23,4);
    FUN_1000_2612(0x183,0);
    FUN_1000_f831();
    return;
  }
  FUN_1000_e74e(unaff_BP + -0x1a,*(undefined2 *)(unaff_BP + -0x1c));
  FUN_1000_b194(0x2015,0x23,4);
  FUN_1000_8247(unaff_BP + -0x1a);
  return;
}


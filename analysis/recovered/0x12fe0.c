/* ev_e3a63bda74efcdd00df9697e2623726d1c5ef00ef89d48eb707f883e57fd8eb3 */

void __cdecl16near FUN_1000_2fe0(void)

{
  int iVar1;
  undefined2 uVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  FUN_1000_2692(0x12d5,0x101e);
  iVar1 = FUN_1000_b5b2(0xffe,0,1,unaff_BP + -2);
  if (iVar1 == -1) {
    FUN_1000_e74e(0x17a0,0x1004);
    return;
  }
  if (*(int *)(unaff_BP + -2) == 0) {
    FUN_1000_b194(0x12fb,0x23,4);
    FUN_1000_2612(0x183,0);
    FUN_1000_f831();
    return;
  }
  FUN_1000_e74e(0x9d3e,*(undefined2 *)(unaff_BP + -2));
  uVar2 = FUN_1000_e74e(0xcbc,0x1733,0x9d3e,0x173f,0x1751);
  uVar2 = FUN_1000_e717(uVar2);
  uVar2 = FUN_1000_e717(uVar2);
  FUN_1000_2692(uVar2);
  FUN_1000_2612(0x183,0);
  FUN_1000_8c42(10,0x9d3e);
  FUN_1000_e74e(0x17a0,0x1004);
  return;
}


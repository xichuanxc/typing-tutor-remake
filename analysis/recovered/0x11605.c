/* ev_846db92ccfcc7573652d85b7c74628a8385ba7ccbf2ce566722b43ca3959ee87 */

void __cdecl16near FUN_1000_1605(void)

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar1 = FUN_1000_b21d(3,0x11,0x83d,*(undefined2 *)(unaff_BP + 4),0,0xfcb);
  if (iVar1 == -1) {
    FUN_1000_e74e(0x17a0,0x1004);
  }
  else if (iVar1 == 0) {
    FUN_1000_e74e(0x17a0,0xfe9);
    *(undefined1 *)0x17a5 = 0;
  }
  else if (iVar1 == 1) {
    FUN_1000_e74e(0x17a0,0xfec);
    *(undefined1 *)0x17a5 = 0;
  }
  else if (iVar1 == 2) {
    *(undefined1 *)0x17a0 = 0;
  }
  return;
}


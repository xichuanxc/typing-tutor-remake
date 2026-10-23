/* ev_bd8b13de624820193b89c71370a7d3288821c478e29fe662b51018e4f91a521a */

undefined2 __cdecl16near FUN_1000_0d63(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  do {
    bVar1 = false;
    iVar2 = FUN_1000_b751(0x1ae,*(undefined2 *)0x6d5,0x1a,0);
    if (iVar2 == -1) {
      return 0xffff;
    }
    for (iVar2 = 1; iVar2 <= *(int *)(unaff_BP + 4); iVar2 = iVar2 + 1) {
      iVar3 = FUN_1000_f105(*(undefined2 *)0x6d5,*(undefined2 *)(iVar2 * 2 + 0x6d5));
      if (iVar3 == 0) {
        bVar1 = true;
        FUN_1000_b12a(0xed1,0x13,0x10,0x16,0x40);
        break;
      }
    }
    if (!bVar1) {
      FUN_1000_e74e(0x9072,*(undefined2 *)0x6d5);
      return 0;
    }
  } while( true );
}


/* ev_8cea7698fbb3f5123bb27bb74c13076044fdb773ddd5bc71654c99377a57c374 */

undefined1 __cdecl16near FUN_1000_0bbb(void)

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar1 = FUN_1000_f84a();
  if (0 < iVar1) {
    return 0x1b;
  }
  FUN_1000_c98e(*(undefined1 *)0x168,*(undefined1 *)0x169,
                (int)*(char *)*(undefined2 *)(unaff_BP + 4),1);
  FUN_1000_7e47(4);
  iVar1 = FUN_1000_4d14(*(undefined1 *)(unaff_BP + 6),0,1);
  if (iVar1 == 1) {
    return 0x1b;
  }
  FUN_1000_c98e(*(undefined1 *)0x168,*(undefined1 *)0x169,
                (int)*(char *)*(undefined2 *)(unaff_BP + 4),0);
  FUN_1000_b1f3(0,2,7);
  return *(undefined1 *)*(undefined2 *)(unaff_BP + 4);
}


/* ev_84fe9a6617e49d70ce692aeb53fcd568469aa215c85a0f26385a398e5c4043b2 */

void __cdecl16near FUN_1000_394a(void)

{
  undefined2 uVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_b1f3(1,5,6);
  uVar1 = FUN_1000_3a2e(*(undefined1 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + 6));
  FUN_1000_f7da(3,uVar1);
  if (*(char *)0x17a5 != '\0') {
    FUN_1000_f6a4(*(undefined2 *)
                   ((uint)*(byte *)(unaff_BP + 4) * 0x1f + (uint)*(byte *)(unaff_BP + 6) * 2 +
                   0x134f));
  }
  FUN_1000_b1f3(0,5,7);
  if (*(char *)0x17a5 != '\0') {
    FUN_1000_f6a4(0x1a4d);
  }
  return;
}


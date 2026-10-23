/* ev_08b5ac1c389d01fffaccecca17f3b7b1c38f3ea2ff0c0b26824ad9e543b1b05a */

void __cdecl16near FUN_1000_73cc(void)

{
  char cVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  cVar1 = FUN_1000_7251(0x2121);
  *(char *)*(undefined2 *)*(undefined2 *)(unaff_BP + 4) = cVar1;
  if (cVar1 != '\0') {
    *(int *)*(undefined2 *)(unaff_BP + 4) = *(int *)*(undefined2 *)(unaff_BP + 4) + 1;
  }
  return;
}


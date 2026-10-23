/* ev_cf8340d431f0e7f53779ffb379e88f49082f64f13325e0ce865b864c1c4eafda */

void __cdecl16near FUN_1000_253e(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if (*(int *)*(undefined2 *)(unaff_BP + 6) == 3) {
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 2;
  }
  else {
    *(undefined2 *)*(undefined2 *)(unaff_BP + 6) = 3;
    *(int *)*(undefined2 *)(unaff_BP + 4) = *(int *)*(undefined2 *)(unaff_BP + 4) + 2;
  }
  return;
}


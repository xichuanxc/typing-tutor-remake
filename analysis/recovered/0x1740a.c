/* ev_260c4659744f3a43461741a4d0d664cf6fcd3ef1545c938038b245aacad600a0 */

void __cdecl16near FUN_1000_740a(void)

{
  char cVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  cVar1 = FUN_1000_7251(0x2134);
  *(char *)*(undefined2 *)*(undefined2 *)(unaff_BP + 4) = cVar1;
  if (cVar1 != '\0') {
    *(int *)*(undefined2 *)(unaff_BP + 4) = *(int *)*(undefined2 *)(unaff_BP + 4) + 1;
  }
  return;
}


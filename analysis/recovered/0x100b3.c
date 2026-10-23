/* ev_b47de38d52999c1d2a8bcc602cdaee751071d3f7f716f69c519e192d0a5db5ee */

void __cdecl16near FUN_1000_00b3(void)

{
  undefined2 uVar1;
  int iVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_0079();
  if (*(byte *)(unaff_BP + 4) < 2) {
    uVar1 = 0xa1;
    if (*(char *)(unaff_BP + 4) != '\0') {
      uVar1 = 0xa8;
    }
    FUN_1000_e74e(8,uVar1);
    uVar1 = 0xa1;
    if (*(char *)(unaff_BP + 4) != '\0') {
      uVar1 = 0xa8;
    }
    iVar2 = FUN_1000_f139(uVar1);
    *(undefined1 *)(iVar2 + 8) = 0x20;
    FUN_1000_b194(3,0x32,6);
  }
  else {
    FUN_1000_b194(0xed,0x2a,3);
  }
  FUN_1000_f7da(0xe,0);
  FUN_1000_f3ba();
  return;
}


/* ev_2df98ba8beabcc5fe86f394c2084d1cc6352cda31c57c9d0fd8eb0ee7b055c89 */

/* WARNING: Removing unreachable block (ram,0x00010c6b) */

undefined2 __cdecl16near FUN_1000_0c43(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  char cVar3;
  int iVar4;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_f7da(*(int *)(unaff_BP + 8) + -1,*(undefined2 *)(unaff_BP + 10));
  FUN_1000_f6a4(0xece,*(undefined2 *)(unaff_BP + 4));
  while( true ) {
    while( true ) {
      uVar1 = *(undefined2 *)(unaff_BP + 0xc);
      uVar2 = *(undefined2 *)(unaff_BP + 6);
      *(int *)(unaff_BP + 6) = *(int *)(unaff_BP + 6) + 1;
      cVar3 = FUN_1000_0bbb(uVar2,uVar1);
      *(char *)(unaff_BP + -1) = cVar3;
      if (cVar3 == '\x1b') {
        FUN_1000_b1f3(0,1,7);
        return 0xffff;
      }
      if (*(char *)(unaff_BP + -1) != '\b') break;
      uVar1 = *(undefined2 *)(unaff_BP + 10);
      *(int *)(unaff_BP + 10) = *(int *)(unaff_BP + 10) + -1;
      FUN_1000_4e79(*(undefined2 *)(unaff_BP + 8),uVar1,0x20);
      FUN_1000_4e79(*(undefined2 *)(unaff_BP + 8),*(undefined2 *)(unaff_BP + 10),0x18);
      FUN_1000_4e79(*(int *)(unaff_BP + 8) + -2,*(undefined2 *)(unaff_BP + 10),0x20);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + -1;
    }
    iVar4 = 0x20;
    if (' ' < *(char *)(unaff_BP + -1)) {
      iVar4 = (int)*(char *)(unaff_BP + -1);
    }
    uVar1 = *(undefined2 *)(unaff_BP + 10);
    *(int *)(unaff_BP + 10) = *(int *)(unaff_BP + 10) + 1;
    FUN_1000_4e79(*(undefined2 *)(unaff_BP + 8),uVar1,iVar4);
    if (*(char *)(unaff_BP + -1) == '\0') break;
    if (*(char *)(unaff_BP + -1) != *(char *)*(undefined2 *)(unaff_BP + 4)) {
      FUN_1000_b1f3(0,2,4);
      FUN_1000_4e79(*(int *)(unaff_BP + 8) + -2,*(int *)(unaff_BP + 10) + -1,0x19);
      FUN_1000_b1f3(0,2,7);
      FUN_1000_7e47(5);
    }
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    FUN_1000_4e79(*(undefined2 *)(unaff_BP + 8),*(undefined2 *)(unaff_BP + 10),0x18);
  }
  return 0;
}


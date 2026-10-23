/* ev_8ea99500464372656d279491fda3884b1bc28e8bba84bb5a1c0fd2765b1fa344 */

void __cdecl16near FUN_1000_5bca(void)

{
  undefined1 uVar1;
  int unaff_BP;
  char cVar2;
  int iVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  cVar2 = '\x02';
  for (iVar3 = 0; iVar3 < 5; iVar3 = iVar3 + 1) {
    *(char *)(unaff_BP + iVar3 + -6) = *(char *)(iVar3 + -0x67c2) - cVar2;
    uVar1 = FUN_1000_e793((int)*(char *)(*(int *)(unaff_BP + 4) + iVar3));
    *(undefined1 *)(*(int *)(unaff_BP + 4) + iVar3) = uVar1;
    cVar2 = cVar2 * '\x02';
  }
  *(undefined1 *)(unaff_BP + -1) = 0;
  iVar3 = FUN_1000_f105(*(undefined2 *)(unaff_BP + 4),unaff_BP + -6);
  if (iVar3 == 0) {
    iVar3 = FUN_1000_f84a();
    if (iVar3 < 1) {
      FUN_1000_095c(1);
    }
    FUN_1000_bd1f();
    FUN_1000_32ed(6,0xffff);
  }
  else {
    FUN_1000_00b3(2);
  }
  FUN_1000_0335();
  return;
}


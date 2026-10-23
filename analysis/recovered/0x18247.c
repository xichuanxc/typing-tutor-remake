/* ev_e353dd29d44c13386527b28acfb93c4adff68b666911dc221cc3ef44a8399bf8 */

void __cdecl16near FUN_1000_8247(void)

{
  undefined2 uVar1;
  int iVar2;
  int unaff_BP;
  int iVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  uVar1 = FUN_1000_e7cd(*(undefined2 *)(unaff_BP + 4),0x7e02);
  *(undefined2 *)0x9070 = uVar1;
  uVar1 = FUN_1000_e7cd(0x7e04,0x7e0d);
  *(undefined2 *)0xa04e = uVar1;
  iVar3 = 0;
  while( true ) {
    iVar2 = FUN_1000_e38e(*(undefined2 *)0x9070);
    if (iVar2 == -1) break;
    FUN_1000_e892(iVar2,*(undefined2 *)0xa04e);
    iVar3 = iVar3 + 1;
  }
  FUN_1000_e913(*(undefined2 *)0x9070);
  FUN_1000_e913(*(undefined2 *)0xa04e);
  uVar1 = FUN_1000_e7cd(*(undefined2 *)(unaff_BP + 4),0x7e0f);
  *(undefined2 *)0x9070 = uVar1;
  uVar1 = FUN_1000_e7cd(0x7e11,0x7e1a);
  *(undefined2 *)0xa04e = uVar1;
  FUN_1000_e8c5(1,*(undefined2 *)0x9070);
  FUN_1000_e352(iVar3,*(undefined2 *)0x9070);
  iVar3 = 1;
  while( true ) {
    iVar2 = FUN_1000_e38e(*(undefined2 *)0xa04e);
    if (iVar2 == -1) break;
    if (iVar2 < 0x21) {
      iVar2 = 0x20;
    }
    if (iVar3 == 8) {
      iVar3 = 1;
    }
    *(undefined1 *)(unaff_BP + -1) = (char)(iVar2 << ((byte)iVar3 & 0x1f));
    *(byte *)(unaff_BP + -1) = *(byte *)(unaff_BP + -1) | (byte)(iVar2 >> (8 - (byte)iVar3 & 0x1f));
    FUN_1000_e8c5(*(undefined1 *)(unaff_BP + -1),*(undefined2 *)0x9070);
    iVar3 = iVar3 + 1;
  }
  FUN_1000_e913(*(undefined2 *)0x9070);
  FUN_1000_e913(*(undefined2 *)0xa04e);
  FUN_1000_e56c(0x1a,unaff_BP + -0x2c);
  FUN_1000_e56c(0x41,0x7e1c,0);
  return;
}


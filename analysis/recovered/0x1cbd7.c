/* ev_68dcbf8d962ea3015864f4ceb34aabef22ddea46533e9b75c2bb9c0f57f266f5 */

uint __cdecl16near FUN_1000_cbd7(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar4 = 10;
  for (iVar3 = 0; iVar3 < 10; iVar3 = iVar3 + 1) {
    FUN_1000_e61c(*(undefined2 *)(iVar3 * 2 + 0x6d5),0x8a2f,iVar4,iVar4 + 9);
    iVar4 = iVar4 + 10;
  }
  FUN_1000_e74e(*(int *)((iVar3 + -1) * 2 + 0x6d5) + 3,0x8a39);
  uVar1 = (*(byte *)0x90b8 - 10) / 10;
  uVar2 = FUN_1000_b21d(10,9,0x6d5,0,uVar1,0xd38);
  if (uVar2 == 0xffff) {
    FUN_1000_e74e(0x17a0,0x1004);
    return 0xffff;
  }
  if (uVar2 != uVar1) {
    *(char *)0x90b8 = (char)uVar2 * '\n' + '\n';
    FUN_1000_54c1(0);
    uVar2 = FUN_1000_54c1(1);
    *(undefined1 *)0x906e = 1;
  }
  return uVar2;
}


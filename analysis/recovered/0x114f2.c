/* ev_2da2492718ac30ee9436b1c5f348ad34abb423132dfb18a50fa667ce77f6e7f5 */

undefined2 __cdecl16near FUN_1000_14f2(void)

{
  int unaff_BP;
  int iVar1;
  int iVar2;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_2692(0xfa6,0x843);
  iVar2 = (uint)*(byte *)0x90b5 * 10 + 10;
  *(int *)(unaff_BP + -2) = iVar2;
  for (iVar1 = 0; iVar1 < 8; iVar1 = iVar1 + 1) {
    FUN_1000_e61c(*(undefined2 *)(iVar1 * 2 + 0x6d5),0xfb1,iVar2,iVar2 + 9);
    iVar2 = iVar2 + 10;
  }
  FUN_1000_e74e(*(int *)((iVar1 + -1) * 2 + 0x6d5) + 3,0xfbb);
  if (*(char *)0x90b5 == '\0') {
    *(undefined1 *)0x90b8 = 0x14;
  }
  else if (*(char *)0x90b5 == '\x01') {
    *(undefined1 *)0x90b8 = 0x1e;
  }
  iVar1 = 7;
  if (*(byte *)0x90b8 < 100) {
    iVar1 = (*(byte *)0x90b8 / 10 - 1) - (uint)*(byte *)0x90b5;
  }
  iVar1 = FUN_1000_b21d(8,9,0x6d5,0,iVar1,0xd38);
  if (iVar1 == -1) {
    return 0xffff;
  }
  *(char *)0x90b8 = (char)iVar1 * '\n' + (char)*(undefined2 *)(unaff_BP + -2);
  FUN_1000_2692(0xfbd,0x843);
  iVar1 = FUN_1000_b21d(7,8,0x7fb,0,1,0xdd1);
  if (iVar1 == -1) {
    return 0xffff;
  }
  *(undefined1 *)0x90b7 = (char)iVar1;
  return 0;
}


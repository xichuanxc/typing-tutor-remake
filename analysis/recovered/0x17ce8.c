/* ev_09c645ae18db5aa74c340e91bf11c8e22becb8aaf3f806acb12e0decc1770dc5 */

void __cdecl16near FUN_1000_7ce8(void)

{
  uint uVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  while( true ) {
    iVar2 = *(int *)0x8f52;
    *(int *)0x8f52 = *(int *)0x8f52 + -1;
    if (iVar2 != 0) {
      return;
    }
    if (*(int *)0xa04a == *(int *)0xa04c) break;
    uVar1 = (*(int *)0xa04c + 1U) % 0xaa;
    *(uint *)0xa04c = uVar1;
    iVar2 = uVar1 * 4;
    *(undefined2 *)0x8f52 = *(undefined2 *)(iVar2 + -0x625c);
    iVar2 = *(int *)(iVar2 + -0x625e);
    if (iVar2 == 0) {
      FUN_1000_7e2a();
    }
    else {
      FUN_1000_7d9c(iVar2);
      FUN_1000_7e0d();
    }
  }
  *(undefined2 *)0x8f52 = 0;
  FUN_1000_7e2a();
  return;
}


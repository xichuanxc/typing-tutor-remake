/* ev_05003b37f5fecf2162e0d6d64e59b0df38b8e1e39fa62357132294be2cd8d9d4 */

void __cdecl16near FUN_1000_c4d0(void)

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uVar2;
  
  FUN_1000_e7bd();
  uVar2 = *(undefined2 *)(unaff_BP + 4);
  iVar1 = FUN_1000_bd74(4,uVar2);
  if (iVar1 == 0) {
    iVar1 = FUN_1000_bd74(2,uVar2);
    iVar1 = iVar1 + 9;
  }
  else {
    iVar1 = 0xb;
  }
  FUN_1000_665a(*(undefined2 *)(iVar1 * 2 + -0x7787));
  return;
}


/* ev_15fdc8a5a8c3459a5293224691ef8bd04cae52c3475be59ed3960f68bf9d2941 */

void __cdecl16near FUN_1000_c131(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_DS;
  
  for (iVar2 = 1; *(char *)(param_1 + iVar2) != '-'; iVar2 = iVar2 + 1) {
  }
  *(undefined1 *)(param_1 + iVar2) = 0;
  for (iVar3 = iVar2 + 1; *(char *)(param_1 + iVar3) != '-'; iVar3 = iVar3 + 1) {
  }
  *(undefined1 *)(param_1 + iVar3) = 0;
  iVar3 = FUN_1000_e469(param_1 + iVar3 + 1);
  uVar1 = FUN_1000_e469(param_1,iVar3 + 0x76c);
  uVar1 = FUN_1000_e469(param_1 + iVar2 + 1,uVar1);
  FUN_1000_bfc7(uVar1);
  return;
}


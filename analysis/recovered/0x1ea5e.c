/* ev_668b0ee392c05dad42a252b63a6b564429621bc2e234542750822ae20a9e8ba9 */

void __cdecl16near FUN_1000_ea5e(int param_1)

{
  int iVar1;
  undefined2 unaff_DS;
  
  iVar1 = FUN_1000_f592((int)*(char *)(param_1 + 7));
  if ((iVar1 == 0) && (iVar1 = FUN_1000_eb10(0x400), iVar1 != 0)) {
    *(undefined2 *)(param_1 + 9) = 0x400;
    *(byte *)(param_1 + 6) = *(byte *)(param_1 + 6) | 2;
    *(int *)(param_1 + 4) = iVar1;
    return;
  }
  *(undefined2 *)(param_1 + 9) = 1;
  *(int *)(param_1 + 4) = param_1 + 8;
  return;
}


/* ev_ff6fbe55a057b61f3740f03aa2d7d19812e678f2750d97d49757f121cb84c5c5 */

void __cdecl16near FUN_1000_97bc(int param_1)

{
  int iVar1;
  undefined2 unaff_DS;
  
  iVar1 = 0;
  *(undefined2 *)0xa060 = 0;
  while( true ) {
    if (*(int *)0xa062 < iVar1) {
      return;
    }
    if (((*(char *)(iVar1 + 0x7a94) == '\'') || (*(char *)(iVar1 + 0x7a94) == ',')) ||
       (*(char *)(iVar1 + 0x7a94) == '-')) {
      iVar1 = iVar1 + 1;
    }
    if (*(char *)(iVar1 + 0x7a94) == '_') break;
    if (*(int *)0xa062 < iVar1) {
      return;
    }
    *(undefined1 *)(param_1 + *(int *)0xa060 + 0x51e) = *(undefined1 *)(iVar1 + 0x7a94);
    iVar1 = iVar1 + 1;
    *(int *)0xa060 = *(int *)0xa060 + 1;
  }
  return;
}


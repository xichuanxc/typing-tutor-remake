/* ev_9e46aa06fb7e523de86d65a871655def6b741c956407f7d28d9bd89aeaab7059 */

int __cdecl16near FUN_1000_0f47(void)

{
  int iVar1;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  for (iVar1 = 1; iVar1 < 9; iVar1 = iVar1 + 1) {
    FUN_1000_e247(*(undefined2 *)0x9070,(long)(iVar1 + -1) * 0x7cc,0);
    FUN_1000_e1f4(*(undefined2 *)(iVar1 * 2 + 0x6d5),1,0x1a,*(undefined2 *)0x9070);
    if (*(char *)*(undefined2 *)(iVar1 * 2 + 0x6d5) == '\0') break;
  }
  return iVar1 + -1;
}


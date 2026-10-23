/* ev_83a51bfb81f102e1379902a2c1392baf24c916aa2b549ae05c7dd43f8253ac68 */

int __cdecl16near FUN_1000_f486(undefined2 param_1,undefined2 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  iVar2 = *(int *)0xa090;
  if (iVar2 == 0) {
    iVar1 = FUN_1000_f3cc(param_1,0x8f60,0x104);
    iVar2 = iVar1;
    if ((iVar1 != 0) && (*(char *)(iVar1 + -0x70a1) == '\n')) {
      iVar2 = iVar1 + -1;
      *(undefined1 *)(iVar1 + -0x70a2) = *(undefined1 *)0x8f38;
    }
    *(undefined2 *)0x9064 = 0x8f60;
    *(int *)0xa090 = iVar2;
  }
  if (param_3 < iVar2) {
    iVar2 = param_3;
  }
  if (iVar2 != 0) {
    FUN_1000_f54d(*(undefined2 *)0x9064,param_2,iVar2);
  }
  *(int *)0x9064 = *(int *)0x9064 + iVar2;
  *(int *)0xa090 = *(int *)0xa090 - iVar2;
  return iVar2;
}


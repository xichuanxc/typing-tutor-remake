/* ev_611280463ca091be61f6b8cec623f1403d28c244b3f89736a572a66e318abae5 */

int __cdecl16near FUN_1000_91df(char param_1)

{
  int iVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  iVar1 = FUN_1000_722b((int)param_1);
  if (iVar1 < 0x1d) {
    if (iVar1 < 0x10) {
      if (iVar1 < 0xc) {
        iVar2 = iVar1;
        if (7 < iVar1) {
          iVar2 = iVar1 + -1;
        }
      }
      else {
        iVar2 = iVar1 + -2;
      }
    }
    else {
      iVar2 = iVar1 + -3;
    }
    if ((*(byte *)(param_1 + -0x7183) & 1) != 0) {
      iVar2 = iVar2 + 1;
    }
  }
  else {
    iVar2 = 0x1a;
  }
  return iVar1 + iVar2;
}


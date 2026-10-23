/* ev_38311902649e778daa22d9cd7a2898178039706e112a5d1dc22d0abd4fb7aef6 */

undefined2 __cdecl16near FUN_1000_544e(void)

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if ((((*(char *)0x9d4c != '\x03') &&
       ((*(uint *)(unaff_BP + 4) <= (uint)*(byte *)0x90af || (0x3f < *(int *)(unaff_BP + 4))))) &&
      (((uint)*(byte *)0x90af != *(uint *)(unaff_BP + 4) || (*(char *)0x90b2 == '\0')))) &&
     (iVar1 = FUN_1000_531a(*(undefined2 *)(unaff_BP + 4)), iVar1 == 0)) {
    iVar1 = FUN_1000_53a7(*(undefined2 *)(unaff_BP + 4));
    if (iVar1 != 0) {
      iVar1 = *(int *)(unaff_BP + 4) * 4;
      if ((*(int *)(iVar1 + -0x652a) == 0) && (*(uint *)(iVar1 + -0x652c) <= (uint)*(byte *)0x1c91))
      {
        return 0;
      }
    }
    return 1;
  }
  return 0;
}


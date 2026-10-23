/* ev_787efed673adbf1441fb9734ef0ae26de977a125562bf6465a2d385044c8f11f */

int __cdecl16near FUN_1000_72ff(void)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  uVar1 = FUN_1000_7251(*(undefined2 *)(unaff_BP + 4));
  *(undefined1 *)(unaff_BP + -1) = uVar1;
  if (*(char *)(unaff_BP + -1) != '\0') {
    uVar2 = FUN_1000_bd74(0x7f);
    iVar3 = FUN_1000_722b((int)*(char *)(unaff_BP + -1));
    if (uVar2 <= *(byte *)(iVar3 + -0x6f45)) {
      return (int)*(char *)(unaff_BP + -1);
    }
  }
  return 0;
}


/* ev_2d844dabb9fc3c2f31b0c5edc575fe5d6e557dd5273d57e69dc5e1398bd3123c */

void __cdecl16near FUN_1000_07c9(void)

{
  byte bVar1;
  uint uVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  bVar1 = FUN_1000_e6a2(0x17,0x40);
  *(byte *)(unaff_BP + -1) = bVar1 & *(byte *)(unaff_BP + 4);
  if (((*(char *)(unaff_BP + -1) != '\0') && (*(char *)(unaff_BP + 6) == '\0')) ||
     ((*(char *)(unaff_BP + -1) == '\0' && (*(char *)(unaff_BP + 6) != '\0')))) {
    if (*(char *)(unaff_BP + 6) == '\0') {
      bVar1 = FUN_1000_e6a2(0x17,0x40);
      FUN_1000_e6c0(0x17,0x40,bVar1 & ~*(byte *)(unaff_BP + 4));
    }
    else {
      uVar2 = FUN_1000_e6a2(0x17,0x40);
      FUN_1000_e6c0(0x17,0x40,uVar2 | *(byte *)(unaff_BP + 4));
    }
  }
  return;
}


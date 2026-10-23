/* ev_a3e93358ce2657ac1a9304680e50ef8e05e7936ab9edbcc068731af8bbb268f7 */

void __cdecl16near FUN_1000_3149(void)

{
  int iVar1;
  undefined2 uVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_bd1f();
  if (*(char *)0x9d4e != '\x01') {
    FUN_1000_2692(0x114f,*(undefined2 *)(unaff_BP + 4));
    iVar1 = FUN_1000_5ec5();
    if (iVar1 == -1) {
      return;
    }
  }
  *(undefined1 *)0x9d4e = 0;
  FUN_1000_e74e(0x9072,*(undefined2 *)0x6d5);
  uVar2 = FUN_1000_e74e(0xcbc,0x111a,0x1009,0x115b);
  uVar2 = FUN_1000_e717(uVar2);
  uVar2 = FUN_1000_e717(uVar2);
  FUN_1000_2692(0x114f,uVar2);
  iVar1 = FUN_1000_853c(0);
  if (iVar1 != 0x1b) {
    *(undefined1 *)0x9d4e = 1;
    FUN_1000_e74e(0x17a0,0x1755);
  }
  FUN_1000_e74e(0x9072,0x1314);
  return;
}


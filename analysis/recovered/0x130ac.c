/* ev_1288f46e0840533d31948e021a1b67d6fcbf0e117d969432c0c62be9ae2e5446 */

void __cdecl16near FUN_1000_30ac(void)

{
  int iVar1;
  undefined2 uVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_bd1f();
  if (*(char *)0x9d4e == '\0') {
    FUN_1000_2692(0x113f,*(undefined2 *)(unaff_BP + 4));
    iVar1 = FUN_1000_5ec5();
    if (iVar1 == -1) {
      return;
    }
  }
  *(undefined1 *)0x9d4e = 0;
  FUN_1000_e74e(0x9072,*(undefined2 *)0x6d5);
  uVar2 = FUN_1000_e74e(0xcbc,0x111a,0x1009,0x114f);
  uVar2 = FUN_1000_e717(uVar2);
  uVar2 = FUN_1000_e717(uVar2);
  FUN_1000_2692(0x113f,uVar2);
  iVar1 = FUN_1000_8c42(8,0x1752);
  if (iVar1 != 0x1b) {
    *(undefined1 *)0x9d4e = 1;
    FUN_1000_e74e(0x17a0,0x1753);
  }
  FUN_1000_e74e(0x9072,0x1314);
  return;
}


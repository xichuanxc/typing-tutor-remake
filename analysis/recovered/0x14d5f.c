/* ev_7172839c349b438eb0d6db782d2e7cdbe2d06ebcf5eba63d3982de6600c6e544 */

void __cdecl16near FUN_1000_4d5f(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  if (*(int *)0x9d70 == param_1) {
    FUN_1000_7e47(5);
  }
  else {
    uVar1 = *(undefined2 *)0x9d6e;
    *(int *)0x9d6e = *(int *)0x9d6e + -1;
    FUN_1000_4e79(*(undefined2 *)0x9d6c,uVar1,0x20);
    FUN_1000_4e79(*(undefined2 *)0x9d6c,*(undefined2 *)0x9d6e,0x18);
    *(int *)0x9d70 = *(int *)0x9d70 + -1;
    iVar2 = *(int *)0x9d70;
    if (*(char *)((iVar2 - param_1) + 0x900) != '\0') {
      FUN_1000_4e79(*(int *)0x9d6c + -2,*(undefined2 *)0x9d6e,0x20);
      *(undefined1 *)((iVar2 - param_1) + 0x900) = 0;
    }
  }
  return;
}


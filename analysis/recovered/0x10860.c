/* ev_f8544d81f41437974f201cd38ce050aa4dfc2f4c82e96d66542b3f394d3f282d */

undefined2 __cdecl16near FUN_1000_0860(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar3 = FUN_1000_f84a();
  if (iVar3 < 1) {
    FUN_1000_095c(0);
  }
  FUN_1000_b1f3(0,1,7);
  FUN_1000_bd1f();
  iVar3 = FUN_1000_0e3f();
  *(int *)0x9d2e = iVar3;
  if (iVar3 == -1) {
    FUN_1000_e913(*(undefined2 *)0x9070);
    return 0xffff;
  }
  FUN_1000_e913(*(undefined2 *)0x9070);
  FUN_1000_bd1f();
  iVar3 = FUN_1000_0f9a();
  if (iVar3 == -1) {
    return 0xffff;
  }
  uVar2 = *(undefined2 *)0x99a6;
  uVar1 = *(undefined2 *)0x99a4;
  *(undefined2 *)0x9711 = uVar2;
  *(undefined2 *)0x970f = uVar1;
  *(undefined2 *)0x97af = uVar2;
  *(undefined2 *)0x97ad = uVar1;
  *(undefined1 *)0x9d38 = 0;
  FUN_1000_bd1f();
  *(undefined2 *)0x9d3a = 0x962;
  *(undefined2 *)0x9d3c = 0xa4c;
  if (*(int *)0x9d34 == 0) {
    FUN_1000_1699();
    FUN_1000_bd1f();
  }
  else {
    uVar1 = *(undefined2 *)0x99a4;
    *(undefined2 *)0x908e = *(undefined2 *)0x99a6;
    *(undefined2 *)0x908c = uVar1;
    iVar3 = FUN_1000_9018(0,0xe5d,0x8b5);
    if (iVar3 == -1) {
      return 0xffff;
    }
    FUN_1000_bd1f();
    iVar3 = FUN_1000_1170();
    if (iVar3 == -1) {
      return 0xffff;
    }
    FUN_1000_bd1f();
    iVar3 = FUN_1000_14f2();
    if (iVar3 == -1) {
      return 0xffff;
    }
    FUN_1000_2692(0xe6a,0x843);
    FUN_1000_1605(0);
    FUN_1000_bd1f();
  }
  if (*(char *)0x90b5 == '\x02') {
    *(undefined1 *)0x1c91 = 0xf;
  }
  return 0;
}


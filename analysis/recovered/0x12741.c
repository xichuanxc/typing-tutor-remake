/* ev_6d2a7f05cb9e09f3f13391c91d55e2c1b10bde7f77e5b32a317ec0af8ac3b4b3 */

void __cdecl16near FUN_1000_2741(void)

{
  int iVar1;
  undefined2 unaff_DS;
  bool bVar2;
  
  FUN_1000_e7bd();
  *(undefined2 *)0x9d2c = 8;
  *(undefined2 *)0x9d4c = 0;
  *(undefined1 *)0x9d4e = 1;
  bVar2 = false;
  if (*(int *)0x9715 + *(int *)0x9764 + (uint)CARRY2(*(uint *)0x9713,*(uint *)0x9762) ==
      *(int *)0x949d) {
    bVar2 = *(uint *)0x9713 + *(uint *)0x9762 == *(int *)0x949b;
  }
  if ((bVar2) && (*(byte *)0x90b5 < 2)) {
    FUN_1000_2692(0x1043,0x183);
    FUN_1000_c78e(3,0xd);
    for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {
      FUN_1000_c98e(3,0xd,(int)*(char *)(iVar1 + 0x7a53),1);
    }
    FUN_1000_ae2b(0xf,0xd,0x15,0x43,0,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
    FUN_1000_af51(0x1567,0xffff,0xf,0xd,0x16,0x43,0,0);
    FUN_1000_f831();
  }
  FUN_1000_3a6d(7,1,0x1a,0);
  return;
}


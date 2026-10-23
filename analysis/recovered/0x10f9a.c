/* ev_7a4deb5ba35fdba20e57fb2e1bde40ed28d20fbf5eebe6dc4ef07a2b5df516dc */

/* WARNING: Removing unreachable block (ram,0x00011082) */

uint __cdecl16near FUN_1000_0f9a(void)

{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  int unaff_BP;
  undefined2 unaff_DS;
  undefined4 uVar4;
  
  FUN_1000_e7bd();
  uVar4 = FUN_1000_114b();
  uVar3 = (undefined2)((ulong)uVar4 >> 0x10);
  *(undefined2 *)0x99a6 = uVar3;
  *(undefined2 *)0x99a4 = (int)uVar4;
  *(undefined2 *)0x9d32 = uVar3;
  *(undefined2 *)0x9d30 = (int)uVar4;
  if ((*(int *)0x99a6 <= *(int *)0x9092) &&
     ((*(int *)0x99a6 != *(int *)0x9092 || (*(uint *)0x99a4 < *(uint *)0x9090)))) {
    uVar3 = *(undefined2 *)0x9090;
    *(undefined2 *)0x99a6 = *(undefined2 *)0x9092;
    *(undefined2 *)0x99a4 = uVar3;
  }
  FUN_1000_c0c6(*(undefined2 *)0x99a4,*(undefined2 *)0x99a6,0x868);
  *(undefined1 *)0x870 = 0x3f;
  do {
    if (*(int *)0x9d34 == 0) {
      FUN_1000_2692(0x1c4);
    }
    else {
      FUN_1000_2692(0x1c4);
    }
    iVar1 = FUN_1000_b21d(2,4,0x8c7,0,0);
    if (iVar1 != -1) {
      if (iVar1 == 0) {
        return 0;
      }
      FUN_1000_2723();
      while( true ) {
        iVar1 = FUN_1000_b751(0xf2e,unaff_BP + -9,9);
        if (iVar1 == -1) {
          return 0xffff;
        }
        uVar4 = FUN_1000_c131();
        iVar1 = (int)((ulong)uVar4 >> 0x10);
        uVar2 = (uint)uVar4;
        *(int *)0x99a6 = iVar1;
        *(uint *)0x99a4 = uVar2;
        if ((*(int *)0x9092 < iVar1) || ((iVar1 == *(int *)0x9092 && (*(uint *)0x9090 <= uVar2))))
        break;
        FUN_1000_ae2b(0x12,10,0x14,0x40,0,0xcd,0xb3,0xd5,0xb8,0xd4);
        FUN_1000_af51(0xf56,0xffff,0x12,10,0x14,0x40,0);
        iVar1 = FUN_1000_f831();
        if (iVar1 == 0x1b) {
          return 0xffff;
        }
        FUN_1000_ae2b(0x12,10,0x14,0x40,1,0x20,0x20,0x20,0x20,0x20);
      }
      return uVar2;
    }
    if (*(int *)0x9d34 == 0) {
      return 0xffff;
    }
    FUN_1000_2692(0x1c9);
    iVar1 = FUN_1000_0d63();
  } while (iVar1 != -1);
  return 0xffff;
}


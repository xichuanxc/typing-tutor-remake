/* ev_97162e6c09b9bc21a3ea6334e0f04cb2f106c876fa805ac59704d3b4059a3ebd */

/* WARNING: Removing unreachable block (ram,0x0001ab5b) */
/* WARNING: Removing unreachable block (ram,0x0001ac00) */
/* WARNING: Removing unreachable block (ram,0x0001ac0c) */

void __cdecl16near FUN_1000_ab36(void)

{
  int iVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  long lVar4;
  undefined1 local_701 [1636];
  undefined1 local_9d [147];
  undefined4 local_a;
  undefined4 local_6;
  
  iVar1 = FUN_1000_9538(local_701);
  if (iVar1 == -1) {
    FUN_1000_7d49();
  }
  else {
    while( true ) {
      iVar1 = FUN_1000_980e(local_701);
      if (iVar1 == -1) break;
      lVar4 = FUN_1000_c1c4();
      *(undefined2 *)0xa064 = 0;
      *(undefined2 *)0xa056 = 0;
      local_6 = lVar4;
      lVar4 = local_a;
      while( true ) {
        local_a = lVar4;
        if ((*(int *)(*(int *)0xa07e * 2 + -0x5f98) == 0) ||
           ((*(int *)0xa05e == 0 && (0x27 < *(int *)0xa064)))) goto LAB_1000_ac2f;
        iVar1 = FUN_1000_9f66(local_701);
        if (iVar1 == -1) break;
        lVar4 = FUN_1000_c1c4();
        if ((local_6 < lVar4) || (lVar4 < local_6)) {
          local_a = lVar4;
          lVar4 = FUN_1000_c1c4();
          local_6 = lVar4;
          FUN_1000_a541(local_701);
          FUN_1000_9d9a(local_701);
          lVar4 = local_a;
        }
      }
      *(undefined2 *)(*(int *)0xa07e * 2 + -0x5f98) = 0;
LAB_1000_ac2f:
      FUN_1000_9bec(local_701);
      if (*(int *)(*(int *)0xa07e * 2 + -0x5f98) == 0) {
        FUN_1000_f7da(9,0x15);
        if (*(int *)0xa07c != 0) {
          FUN_1000_f6a4(0x84a7,*(int *)0xa07e + 1);
        }
        uVar2 = 0x9072;
        if (*(int *)0xa07e != 0) {
          uVar2 = *(undefined2 *)0x6d5;
        }
        FUN_1000_f6a4(0x84b3,uVar2);
        FUN_1000_768e(*(undefined2 *)0xa07a,*(undefined2 *)0xa07e);
        FUN_1000_bd1f();
      }
      if ((*(int *)0xa07c == 0) || (*(int *)((uint)(*(int *)0xa07e == 0) * 2 + -0x5f98) == 0)) {
        if (*(int *)(*(int *)0xa07e * 2 + -0x5f98) == 0) {
          if (*(int *)0xa07c != 0) {
            FUN_1000_f7da(10,0x15);
            FUN_1000_f6a4(0x84c9,0x9072,*(undefined2 *)0x9d9a,*(undefined2 *)0x9d9c);
            FUN_1000_f7da(0xb,0x15);
            FUN_1000_f6a4(0x84db,*(undefined2 *)0x6d5,*(undefined2 *)0x9d9e,*(undefined2 *)0x9da0);
          }
          FUN_1000_787b(*(undefined2 *)0xa07a,0xd);
          FUN_1000_2612(0x183,0);
          FUN_1000_f831();
          FUN_1000_2692(0x8008,0x843);
          FUN_1000_bd1f();
          iVar1 = FUN_1000_b21d(3,0x14,0x7ff0,0,0,0x102e);
          if (iVar1 == -1) {
            FUN_1000_e74e(0x17a0,0x1006);
          }
          else if (iVar1 == 0) {
            FUN_1000_e74e(0x17a0,0x84ed);
          }
          else if (iVar1 == 1) {
            FUN_1000_e74e(0x17a0,0x84ef);
          }
          else if (iVar1 == 2) {
            FUN_1000_e74e(0x17a0,0x1004);
          }
          goto LAB_1000_add2;
        }
        *(int *)0xa086 = *(int *)0xa086 + 1;
      }
      else {
        if (*(int *)0xa07e != 0) {
          *(int *)0xa086 = *(int *)0xa086 + 1;
        }
        *(uint *)0xa07e = (uint)(*(int *)0xa07e == 0);
      }
    }
    FUN_1000_768e(*(undefined2 *)0xa07a,0);
    if (*(int *)0xa07c != 0) {
      FUN_1000_768e(*(undefined2 *)0xa07a,1);
    }
    FUN_1000_e74e(0x17a0,0x1004);
LAB_1000_add2:
    *(undefined1 *)0x90af = (char)*(undefined2 *)0xa080;
    *(undefined1 *)0x90ba = (char)*(undefined2 *)0xa082;
    *(undefined1 *)0x90ae = (char)*(undefined2 *)0xa084;
    if (*(int *)0xa07a != 0) {
      for (iVar1 = 0; iVar1 < 0x40; iVar1 = iVar1 + 1) {
        *(undefined1 *)(iVar1 + -0x6f45) = local_9d[iVar1];
      }
    }
    *(undefined2 *)0x9d36 = 0;
    for (uVar3 = 0; uVar3 < *(byte *)0x90ae + 4; uVar3 = uVar3 + 1) {
      iVar1 = FUN_1000_722b((int)*(char *)(uVar3 + 0x7aee));
      *(int *)0x9d36 = *(int *)0x9d36 + (uint)*(byte *)(iVar1 + -0x6f45);
    }
  }
  return;
}


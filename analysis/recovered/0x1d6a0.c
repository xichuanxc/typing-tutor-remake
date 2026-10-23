/* ev_454b9c2bab764c17c9b99e94bb83f8aa21906a30324914fbffb64c0f32314d7b */

int __cdecl16near FUN_1000_d6a0(int param_1)

{
  uint *puVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined2 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined2 unaff_DS;
  bool bVar10;
  undefined1 local_109;
  undefined1 local_108;
  undefined1 local_107;
  uint local_106;
  int local_104;
  uint local_102;
  int local_100;
  uint local_fe;
  uint local_fc;
  uint local_fa;
  int local_f8;
  uint local_f6;
  int local_f4;
  undefined1 local_f2 [240];
  
  local_fa = 1;
  local_100 = 0;
  local_102 = 0;
  iVar9 = 0;
  iVar8 = 0;
  do {
    if (*(int *)0x9d2c == 10) {
      uVar2 = FUN_1000_e1ad();
      *(undefined1 *)0x90b1 = uVar2;
    }
    if (local_fa == 1) {
      FUN_1000_54c1(1);
    }
    for (local_f4 = 0; local_f4 < param_1; local_f4 = local_f4 + 1) {
      local_f6 = 0;
      while( true ) {
        iVar3 = 6;
        if (param_1 == 1) {
          iVar3 = 3;
        }
        if (iVar3 <= (int)local_f6) break;
        FUN_1000_e15d(local_f2 + local_f4 * 0x3c + local_f6 * 10);
        local_f6 = local_f6 + 1;
      }
    }
    if ((*(int *)0x9d2c == 10) && (iVar3 = FUN_1000_d368(local_f2,local_fa), iVar3 == -1)) {
      FUN_1000_07c9(0x20,0);
      iVar8 = FUN_1000_e74e(0x17a0,0x1004);
      return iVar8;
    }
    for (local_f4 = 0; local_f4 < param_1; local_f4 = local_f4 + 1) {
      FUN_1000_b1f3(0,2,7);
      if (*(char *)0x906a == '\0') {
        iVar3 = 0x2f;
        if (param_1 != 1) {
          iVar3 = local_f4 * 0x11 + 0x15;
        }
        uVar6 = 0x16;
        if (param_1 == 1) {
          uVar6 = 0xe;
        }
        iVar4 = 0x21;
        if (param_1 != 1) {
          iVar4 = local_f4 * 0x11 + 7;
        }
        FUN_1000_ae2b(3,iVar4,uVar6,iVar3,0,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
      }
      else {
        iVar3 = 0x2f;
        if (param_1 != 1) {
          iVar3 = local_f4 * 0x11 + 0x15;
        }
        uVar6 = 0x16;
        if (param_1 == 1) {
          uVar6 = 0xe;
        }
        iVar4 = 0x21;
        if (param_1 != 1) {
          iVar4 = local_f4 * 0x11 + 7;
        }
        FUN_1000_ae2b(3,iVar4,uVar6,iVar3,1,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
      }
      local_f6 = 0;
      while( true ) {
        iVar3 = 6;
        if (param_1 == 1) {
          iVar3 = 3;
        }
        if (iVar3 <= (int)local_f6) break;
        iVar3 = 0x24;
        if (param_1 != 1) {
          iVar3 = local_f4 * 0x11 + 10;
        }
        FUN_1000_f7da(local_f6 * 3 + 5,iVar3);
        FUN_1000_f6a4(0x8ca8,local_f2 + local_f4 * 0x3c + local_f6 * 10);
        local_f6 = local_f6 + 1;
      }
    }
    FUN_1000_bd1f();
    local_104 = 0;
    local_106 = 0;
    local_fe = 0;
    local_fc = 0;
    for (local_f4 = 0; local_f4 < param_1; local_f4 = local_f4 + 1) {
      local_f6 = 0;
      while( true ) {
        iVar3 = 6;
        if (param_1 == 1) {
          iVar3 = 3;
        }
        if (iVar3 <= (int)local_f6) break;
        iVar3 = 0x24;
        if (param_1 != 1) {
          iVar3 = local_f4 * 0x11 + 10;
        }
        iVar3 = iVar3 + 9;
        iVar4 = FUN_1000_f139(local_f2 + local_f4 * 0x3c + local_f6 * 10,iVar3,
                              local_f2 + local_f4 * 0x3c + local_f6 * 10,&local_fc,&local_fe,
                              &local_106);
        iVar3 = FUN_1000_4a70(local_f6 * 3 + 6,iVar3 - iVar4);
        if (iVar3 == -1) {
          FUN_1000_07c9(0x20,0);
          FUN_1000_e74e(0x17a0,0x1004);
          return -1;
        }
        local_f6 = local_f6 + 1;
      }
    }
    if (*(int *)0x9d2c < 8) {
      iVar3 = *(int *)0x9d3a;
      *(int *)(iVar3 + 0x17) = (int)local_fc >> 0xf;
      *(uint *)(iVar3 + 0x15) = local_fc;
      iVar3 = *(int *)0x9d3a;
      *(int *)(iVar3 + 0x1b) = (int)local_fe >> 0xf;
      *(uint *)(iVar3 + 0x19) = local_fe;
      iVar3 = *(int *)0x9d3a;
      *(int *)(iVar3 + 0x13) = local_104;
      *(uint *)(iVar3 + 0x11) = local_106;
      iVar3 = 6;
      if (param_1 == 1) {
        iVar3 = 3;
      }
      iVar4 = *(int *)0x9d3a;
      *(int *)(iVar4 + 0x1f) = iVar3 * param_1 >> 0xf;
      *(int *)(iVar4 + 0x1d) = iVar3 * param_1;
    }
    puVar1 = (uint *)0x97b5;
    uVar7 = *puVar1;
    *puVar1 = *puVar1 + local_fc;
    *(int *)0x97b7 = *(int *)0x97b7 + ((int)local_fc >> 0xf) + (uint)CARRY2(uVar7,local_fc);
    puVar1 = (uint *)0x97b9;
    uVar7 = *puVar1;
    *puVar1 = *puVar1 + local_fe;
    *(int *)0x97bb = *(int *)0x97bb + ((int)local_fe >> 0xf) + (uint)CARRY2(uVar7,local_fe);
    puVar1 = (uint *)0x97b1;
    uVar7 = *puVar1;
    *puVar1 = *puVar1 + local_106;
    *(int *)0x97b3 = *(int *)0x97b3 + local_104 + (uint)CARRY2(uVar7,local_106);
    iVar3 = 6;
    if (param_1 == 1) {
      iVar3 = 3;
    }
    uVar5 = iVar3 * param_1;
    puVar1 = (uint *)0x97bd;
    uVar7 = *puVar1;
    *puVar1 = *puVar1 + uVar5;
    *(int *)0x97bf = *(int *)0x97bf + ((int)uVar5 >> 0xf) + (uint)CARRY2(uVar7,uVar5);
    iVar8 = iVar8 + local_fc;
    iVar9 = iVar9 + local_fe;
    bVar10 = CARRY2(local_102,local_106);
    local_102 = local_102 + local_106;
    local_100 = local_100 + local_104 + (uint)bVar10;
    if (*(int *)0x9d2c == 10) {
      FUN_1000_b1f3(0,2,7);
      for (local_f6 = 0; (int)local_f6 < 9; local_f6 = local_f6 + 1) {
        FUN_1000_f7da(local_f6 + 4,0x24);
        for (local_f4 = 0; local_f4 < 10; local_f4 = local_f4 + 1) {
          FUN_1000_f873(0x20);
        }
      }
      FUN_1000_f7da(0x12,0x2e);
      FUN_1000_f873(0x20);
      FUN_1000_f7da(0x13,0x2e);
      FUN_1000_f873(0x20);
      if (*(char *)0xa08e == '\0') {
        *(undefined1 *)0xa08e = 1;
        FUN_1000_b1f3(0,1,7);
        for (local_f4 = 0x11; local_f4 < 0x15; local_f4 = local_f4 + 1) {
          FUN_1000_f7da(local_f4,0);
          FUN_1000_f74a();
        }
        FUN_1000_b1f3(0,2,7);
        FUN_1000_d2c9();
      }
      FUN_1000_f7da(0x12,0x28);
      iVar3 = local_fc + local_fe + -2;
      uVar6 = FUN_1000_52dc(iVar3,iVar3 >> 0xf,0,0,local_106,local_104);
      *(undefined2 *)0x9d56 = uVar6;
      FUN_1000_f6a4(0x8cac,uVar6);
      FUN_1000_f7da(0x13,0x2b);
      uVar6 = FUN_1000_529a(local_fc,(int)local_fc >> 0xf,local_fe,(int)local_fe >> 0xf);
      *(undefined2 *)0x9d54 = uVar6;
      FUN_1000_f6a4(0x8cb3,uVar6);
      if (local_fa < *(byte *)0x90b6) {
        local_fa = local_fa + 1;
      }
      else {
        FUN_1000_f7da(9,0x22);
        FUN_1000_b1f3(1,1,7);
        FUN_1000_f6a4(0x1ae3);
        FUN_1000_b1f3(0,1,7);
        FUN_1000_2612(0x183,0);
        FUN_1000_4d14(0xfa,0,1);
        FUN_1000_bd1f();
        FUN_1000_2692(0x8cb8,0x101e);
        FUN_1000_ae2b(3,0x1b,9,0x35,0,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
        FUN_1000_f7da(4,0x1d);
        iVar3 = iVar8 + iVar9 + local_fa * -2;
        uVar6 = FUN_1000_52dc(iVar3,iVar3 >> 0xf,0,0,local_102,local_100);
        FUN_1000_f6a4(0x8cce,uVar6);
        FUN_1000_f7da(5,0x1d);
        local_fa = 1;
        uVar6 = FUN_1000_529a(iVar8,iVar8 >> 0xf,iVar9,iVar9 >> 0xf);
        FUN_1000_f6a4(0x8cdc,uVar6);
        local_f8 = 0;
        for (local_f6 = 0x40; local_f6 <= *(byte *)0x90b0; local_f6 = local_f6 + 1) {
          iVar8 = local_f6 * 4;
          uVar7 = FUN_1000_52dc(*(undefined2 *)(iVar8 + -0x652c),*(undefined2 *)(iVar8 + -0x652a),
                                *(undefined2 *)(iVar8 + -0x6400),*(undefined2 *)(iVar8 + -0x63fe),
                                *(undefined2 *)(iVar8 + -0x6658),*(undefined2 *)(iVar8 + -0x6656));
          if (*(byte *)0x90b8 <= uVar7) {
            local_f8 = local_f8 + 1;
          }
        }
        FUN_1000_f7da(6,0x1d);
        FUN_1000_f6a4(0x8ceb,*(undefined1 *)0x90b8,local_f8);
        FUN_1000_def0(1,*(byte *)0x90b0 - 0x3f,0x7b14,&local_109);
        FUN_1000_f7da(7,0x1d);
        FUN_1000_f6a4(0x8d01,local_109,local_108,local_107);
        FUN_1000_def0(2,*(byte *)0x90b0 - 0x3f,0x7b14,&local_109);
        FUN_1000_f7da(8,0x1d);
        FUN_1000_f6a4(0x8d15,local_109,local_108,local_107);
        FUN_1000_07c9(0x20,0);
        iVar8 = FUN_1000_b21d(3,0x15,0x8bb2,10,0,0x102e);
        if (iVar8 == -1) {
          iVar8 = FUN_1000_e74e(0x17a0,0x1006);
          return iVar8;
        }
        if (iVar8 == 1) {
          iVar8 = FUN_1000_e74e(0x17a0,0x8d2f);
          return iVar8;
        }
        if (iVar8 == 2) {
          iVar8 = FUN_1000_e74e(0x17a0,0x1004);
          return iVar8;
        }
        FUN_1000_07c9(0x20,1);
        local_100 = 0;
        local_102 = 0;
        iVar9 = 0;
        iVar8 = 0;
      }
    }
    else {
      *(undefined1 *)0x9d38 = 1;
    }
    if (*(int *)0x9d2c != 10) {
      return *(int *)0x9d2c;
    }
  } while( true );
}


/* ev_132f0be684dab0b0a33295b933a79846669945ee557e867e0f0351ee08cb9212 */

int __cdecl16near FUN_1000_ece8(code *param_1,char *param_2,int *param_3)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  undefined2 unaff_DS;
  bool bVar5;
  char local_d1 [187];
  char *local_16;
  int local_14;
  char *local_12;
  int local_10;
  char *local_e;
  int local_c;
  uint local_a;
  int local_8;
  int *local_6;
  int local_4;
  
  local_8 = 0;
  local_6 = param_3;
  do {
    while( true ) {
      local_4 = (int)*param_2;
      if (local_4 == 0) {
        return local_8;
      }
      if (local_4 == 0x25) break;
      iVar2 = (*param_1)(local_4);
      if (iVar2 == -1) {
        return -1;
      }
      local_8 = local_8 + 1;
      param_2 = param_2 + 1;
    }
    local_d1[1] = 0;
    local_c = 0x20;
    local_e = (char *)0x2710;
    local_4 = (int)param_2[1];
    bVar5 = local_4 == 0x2d;
    pcVar3 = param_2 + 2;
    if (bVar5) {
      pcVar3 = param_2 + 3;
      local_4 = (int)param_2[2];
    }
    local_a = (uint)!bVar5;
    pcVar4 = pcVar3;
    if (local_4 == 0x30) {
      local_c = 0x30;
      pcVar4 = pcVar3 + 1;
      local_4 = (int)*pcVar3;
    }
    if (local_4 == 0x2a) {
      local_10 = *local_6;
      pcVar3 = pcVar4 + 1;
      local_4 = (int)*pcVar4;
      local_6 = local_6 + 1;
    }
    else {
      local_10 = 0;
      pcVar3 = pcVar4;
      while ((*(byte *)(local_4 + -0x7183) & 4) != 0) {
        local_10 = local_10 * 10 + local_4 + -0x30;
        local_4 = (int)*pcVar3;
        pcVar3 = pcVar3 + 1;
      }
    }
    if (local_4 == 0x2e) {
      pcVar4 = pcVar3 + 1;
      local_4 = (int)*pcVar3;
      if (local_4 == 0x2a) {
        local_e = (char *)*local_6;
        pcVar3 = pcVar3 + 2;
        local_4 = (int)*pcVar4;
        local_6 = local_6 + 1;
      }
      else {
        local_e = (char *)0x0;
        pcVar3 = pcVar4;
        while ((*(byte *)(local_4 + -0x7183) & 4) != 0) {
          local_e = (char *)((int)local_e * 10 + local_4 + -0x30);
          local_4 = (int)*pcVar3;
          pcVar3 = pcVar3 + 1;
        }
      }
    }
    local_12 = (char *)0x2;
    if (local_4 == 0x6c) {
      local_4 = (int)*pcVar3;
      local_12 = (char *)0x4;
      param_2 = pcVar3 + 1;
    }
    else {
      param_2 = pcVar3;
      if (local_4 == 0x68) {
        param_2 = pcVar3 + 1;
        local_4 = (int)*pcVar3;
      }
    }
    if (local_4 == 99) {
      local_4 = *local_6;
      local_6 = local_6 + 1;
LAB_1000_ee8e:
      local_16 = local_d1;
      local_d1[0] = (char)local_4;
LAB_1000_eebc:
      local_12 = local_d1 + (1 - (int)local_16);
    }
    else {
      if (local_4 == 100) {
        local_14 = -10;
LAB_1000_ee4d:
        local_16 = (char *)FUN_1000_ec2e(local_6,local_14,local_d1 + 1,local_12);
        local_6 = (int *)((int)local_6 + (int)local_12);
        goto LAB_1000_eebc;
      }
      if (local_4 == 0x6f) {
        local_14 = 8;
        goto LAB_1000_ee4d;
      }
      if (local_4 != 0x73) {
        if (local_4 == 0x75) {
          local_14 = 10;
        }
        else {
          if (local_4 != 0x78) goto LAB_1000_ee8e;
          local_14 = 0x10;
        }
        goto LAB_1000_ee4d;
      }
      local_16 = (char *)*local_6;
      local_6 = local_6 + 1;
      local_12 = (char *)FUN_1000_f139(local_16);
    }
    if ((int)local_e < (int)local_12) {
      local_12 = local_e;
    }
    if (local_a != 0) {
      if (((*local_16 == '-') || (*local_16 == '+')) && (local_c == 0x30)) {
        local_10 = local_10 + -1;
        pcVar1 = local_16;
        local_16 = local_16 + 1;
        iVar2 = (*param_1)((int)*pcVar1);
        if (iVar2 == -1) {
          return -1;
        }
      }
      while (iVar2 = local_10 + -1, bVar5 = (int)local_12 < local_10, local_10 = iVar2, bVar5) {
        iVar2 = (*param_1)(local_c);
        if (iVar2 == -1) {
          return -1;
        }
        local_8 = local_8 + 1;
      }
    }
    for (local_14 = 0; (*local_16 != '\0' && (local_14 < (int)local_e)); local_14 = local_14 + 1) {
      pcVar1 = local_16;
      local_16 = local_16 + 1;
      iVar2 = (*param_1)((int)*pcVar1);
      if (iVar2 == -1) {
        return -1;
      }
    }
    local_8 = local_8 + local_14;
    if (local_a == 0) {
      while (iVar2 = local_10 + -1, bVar5 = (int)local_12 < local_10, local_10 = iVar2, bVar5) {
        iVar2 = (*param_1)(0x20);
        if (iVar2 == -1) {
          return -1;
        }
        local_8 = local_8 + 1;
      }
    }
  } while( true );
}


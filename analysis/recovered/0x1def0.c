/* ev_3ae864350b58e0800838b8de7e2a109479560027b3137ccb398f33f70fa42720 */

void __cdecl16near FUN_1000_def0(int param_1,int param_2,int param_3,undefined1 *param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  int local_9;
  int local_7;
  byte local_5 [3];
  
  for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {
    param_4[iVar3] = 0x20;
    bVar1 = 0;
    if (param_1 == 1) {
      bVar1 = 0xff;
    }
    local_5[iVar3] = bVar1;
  }
  iVar3 = 0;
  do {
    iVar2 = 3;
    if (param_1 != 0) {
      iVar2 = 1;
    }
    if (iVar2 <= iVar3) {
      if (((*(byte *)0x90b0 < 0x44) && (param_1 != 0)) ||
         ((*(char *)0x90b0 == 'D' && (param_1 == 2)))) {
        param_4[2] = 0x20;
      }
      if ((*(char *)0x90b0 == 'B') && (param_1 == 2)) {
        param_4[1] = 0x20;
      }
      return;
    }
    local_9 = 0;
    while( true ) {
      iVar2 = param_2;
      if (param_1 == 0) {
        iVar2 = FUN_1000_f139(iVar3 * 10 + param_3);
      }
      if (iVar2 <= local_9) break;
      iVar2 = FUN_1000_e08c((int)*(char *)(iVar3 * 10 + param_3 + local_9));
      bVar1 = *(byte *)(iVar2 + -0x6f45);
      local_7 = 0;
      while( true ) {
        if ((2 < local_7) || (param_4[local_7] == *(char *)(iVar3 * 10 + param_3 + local_9)))
        goto LAB_1000_e043;
        if (((param_1 == 1) && (bVar1 <= local_5[local_7])) ||
           ((param_1 != 1 && (local_5[local_7] < bVar1)))) break;
        local_7 = local_7 + 1;
      }
      if (local_7 < 2) {
        param_4[2] = param_4[1];
        local_5[2] = local_5[1];
      }
      if (local_7 == 0) {
        param_4[1] = *param_4;
        local_5[1] = local_5[0];
      }
      param_4[local_7] = *(undefined1 *)(iVar3 * 10 + param_3 + local_9);
      local_5[local_7] = bVar1;
LAB_1000_e043:
      local_9 = local_9 + 1;
    }
    iVar3 = iVar3 + 1;
  } while( true );
}


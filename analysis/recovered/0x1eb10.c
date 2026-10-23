/* ev_dc99326dcc45a9ada461b7e6c92c69e7cb6fee5c9884ac801489230154d5ba8f */

uint * __cdecl16near FUN_1000_eb10(int param_1)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  undefined2 unaff_DS;
  int local_8;
  int local_6;
  uint *local_4;
  
  uVar1 = param_1 + 3U & 0xfffe;
  if (*(int *)0x8f58 == 0) {
    *(undefined2 *)0x8f56 = 0x8f56;
    *(uint *)0x8f56 = *(uint *)0x8f56 | 1;
    *(undefined2 *)0x8f58 = 0x8f56;
  }
  local_8 = 0;
  puVar3 = (uint *)*(undefined2 *)0x8f58;
  local_4 = puVar3;
  do {
    if ((puVar3 == (uint *)*(undefined2 *)0x8e66) && (local_8 = local_8 + 1, 1 < local_8)) {
      local_6 = 0x400;
      puVar2 = (uint *)FUN_1000_f5b2(0x400);
      if (puVar2 == (uint *)0xffff) {
        return (uint *)0x0;
      }
      if (puVar3 + 1 != puVar2) {
        *puVar3 = (uint)puVar2;
        *puVar3 = *puVar3 | 1;
        local_6 = 0x3fe;
        puVar3 = puVar2;
      }
      puVar2 = (uint *)((int)puVar3 + local_6);
      *puVar3 = (uint)puVar2;
      *puVar2 = 0x8f56;
      *puVar2 = *puVar2 | 1;
      *(undefined2 *)0x8e66 = puVar2;
      if ((uint *)(*local_4 & 0xfffe) == puVar3) {
        puVar3 = local_4;
      }
    }
    if ((*puVar3 & 1) == 0) {
      while (puVar2 = (uint *)(*puVar3 & 0xfffe), (*puVar2 & 1) == 0) {
        *puVar3 = *puVar2;
      }
      local_4 = puVar3;
      if (uVar1 <= (uint)((int)puVar2 - (int)puVar3)) {
        if (uVar1 < (uint)((int)puVar2 - (int)puVar3)) {
          *puVar3 = (int)puVar3 + uVar1;
          *(undefined2 *)0x8f5a = *(undefined2 *)((int)puVar3 + uVar1);
          *(undefined2 *)*puVar3 = puVar2;
        }
        *(uint *)0x8f58 = *puVar3;
        *puVar3 = *puVar3 | 1;
        return puVar3 + 1;
      }
    }
    puVar3 = (uint *)(*puVar3 & 0xfffe);
  } while( true );
}


/* ev_e9193da6e78fcdd72ad2d235c757171c72427d1df1e116e993c514e42b4f269f */

void __cdecl16near FUN_1000_bc24(int param_1)

{
  undefined1 uVar1;
  undefined2 unaff_DS;
  undefined1 local_5;
  undefined1 local_4;
  
  local_4 = 0;
  local_5 = FUN_1000_f139(param_1);
  for (; local_5 = local_5 - 1, local_4 < local_5; local_4 = local_4 + 1) {
    uVar1 = *(undefined1 *)((uint)local_4 + param_1);
    *(undefined1 *)((uint)local_4 + param_1) = *(undefined1 *)((uint)local_5 + param_1);
    *(undefined1 *)((uint)local_5 + param_1) = uVar1;
  }
  return;
}


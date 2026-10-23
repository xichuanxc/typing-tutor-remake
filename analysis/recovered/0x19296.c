/* ev_7bb1b917bd6ec1a80286bde053c782fa0739f7568676d1a927277e1d9208b2cc */

void __cdecl16near FUN_1000_9296(undefined2 param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 unaff_DS;
  undefined2 local_8;
  undefined2 local_6;
  
  FUN_1000_b1f3(1,1,3);
  uVar1 = *(undefined2 *)0x90a6;
  *(undefined2 *)0x90a6 = *(undefined2 *)0xa088;
  local_6 = 0;
  local_8 = FUN_1000_bd74(3);
  while (local_6 < 0x50) {
    iVar2 = FUN_1000_bd74(3);
    if (iVar2 == 2) {
      FUN_1000_925f(param_1,local_8 + 0x16,local_6,0xcd);
      local_6 = local_6 + 1;
    }
    else if (local_8 == 0) {
      FUN_1000_925f(param_1,0x16,local_6,0xbb);
      if (iVar2 == 0) {
        FUN_1000_925f(param_1,0x17,local_6,200);
        local_8 = 1;
      }
      else {
        FUN_1000_925f(param_1,0x17,local_6,0xba);
        FUN_1000_925f(param_1,0x18,local_6,200);
        local_8 = 2;
      }
      local_6 = local_6 + 1;
    }
    else if (local_8 == 1) {
      if (iVar2 == 0) {
        FUN_1000_925f(param_1,0x17,local_6,0xbc);
        FUN_1000_925f(param_1,0x16,local_6,0xc9);
        local_8 = 0;
      }
      else {
        FUN_1000_925f(param_1,0x17,local_6,0xbb);
        FUN_1000_925f(param_1,0x18,local_6,200);
        local_8 = 2;
      }
      local_6 = local_6 + 1;
    }
    else if (local_8 == 2) {
      FUN_1000_925f(param_1,0x18,local_6,0xbc);
      if (iVar2 == 0) {
        FUN_1000_925f(param_1,0x17,local_6,0xc9);
      }
      else {
        FUN_1000_925f(param_1,0x17,local_6,0xba);
        FUN_1000_925f(param_1,0x16,local_6,0xc9);
      }
      local_6 = local_6 + 1;
      local_8 = (uint)(iVar2 == 0);
    }
  }
  *(undefined2 *)0x90a6 = uVar1;
  FUN_1000_b1f3(0,1,7);
  return;
}


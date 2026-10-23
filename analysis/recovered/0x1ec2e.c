/* ev_29ef50791932ef058a2aaeeeff63813ce0a4f6a3744f610c00e66a7db248c6bf */

undefined1 * __cdecl16near FUN_1000_ec2e(int *param_1,int param_2,undefined1 *param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined2 unaff_DS;
  long lVar4;
  int local_4;
  
  if (param_4 == 4) {
    local_4 = param_1[1];
  }
  else if (param_2 < 1) {
    local_4 = *param_1 >> 0xf;
  }
  else {
    local_4 = 0;
  }
  bVar1 = false;
  if (((param_2 < 0) && (local_4 < 1)) && (local_4 != 0)) {
    bVar1 = true;
  }
  do {
    puVar3 = param_3;
    iVar2 = FUN_1000_f09f();
    param_3 = puVar3 + -1;
    *param_3 = *(undefined1 *)(iVar2 + -0x7196);
    lVar4 = FUN_1000_f0a7();
  } while (lVar4 != 0);
  if (bVar1) {
    param_3 = puVar3 + -2;
    *param_3 = 0x2d;
  }
  return param_3;
}


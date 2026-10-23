/* ev_720fdeeef953cb8cac1e3412f80a1972ad2fd2026656e3a5b52bdc32aaf39b04 */

undefined4 __cdecl16near FUN_1000_bfc7(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = 0x1a;
  uVar6 = 0x431f;
  if (param_2 < 3) {
    param_3 = param_3 + -1;
  }
  lVar3 = FUN_1000_f04d(0x431f,0x1a,0x3ab1,2,param_3 / 100,param_3 / 100 >> 0xf);
  lVar4 = FUN_1000_f04d();
  lVar5 = FUN_1000_f04d();
  lVar5 = lVar3 + lVar4 + lVar5;
  uVar1 = (uint)lVar5;
  uVar2 = uVar1 + param_1;
  return CONCAT22((int)((ulong)lVar5 >> 0x10) + ((int)param_1 >> 0xf) + (uint)CARRY2(uVar1,param_1)
                  + iVar7 + (uint)CARRY2(uVar2,uVar6),uVar2 + uVar6);
}


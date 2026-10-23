/* ev_53b3ec035cbb30aa49f9c5c7bbc57d502d4192dc7c7158014579c4ea03b83175 */

/* WARNING: Removing unreachable block (ram,0x00014d3b) */

undefined2 __cdecl16near FUN_1000_4d14(undefined2 param_1,undefined2 param_2,char param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  long lVar4;
  
  uVar2 = FUN_1000_4cb5();
  do {
    uVar3 = FUN_1000_4cb5(uVar2);
    lVar4 = FUN_1000_4cd6(uVar3);
    if (CONCAT22(param_2,param_1) < lVar4) {
      return 0;
    }
    iVar1 = FUN_1000_f84a();
  } while ((iVar1 < 1) || (param_3 == '\0'));
  return 1;
}


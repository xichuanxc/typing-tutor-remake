/* ev_b30158ac880ecc9b6f2af3404247a1033e95d906b3751b2cd8cd70f5c69af9f2 */

int __cdecl16near FUN_1000_bbea(undefined1 param_1,byte param_2,int param_3)

{
  undefined2 unaff_DS;
  undefined1 local_3;
  
  local_3 = 0;
  while (local_3 < param_2) {
    *(undefined1 *)((uint)local_3 + param_3) = param_1;
    local_3 = local_3 + 1;
  }
  *(undefined1 *)((uint)local_3 + param_3) = 0;
  return param_3;
}


/* ev_afd126eb44a1a09bd0b400a578a64dfed937bf6e8835ac0c100bfd2dd711b2ba */

/* WARNING: Removing unreachable block (ram,0x0001bce8) */

int __cdecl16near FUN_1000_bc82(undefined2 param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_DS;
  long lVar4;
  
  iVar3 = 0;
  do {
    iVar2 = iVar3;
    cVar1 = FUN_1000_f07b();
    iVar3 = iVar2 + 1;
    *(char *)(iVar2 + param_3) = cVar1 + '0';
    lVar4 = FUN_1000_f04d();
  } while (0 < lVar4);
  if ((param_2 < 1) && (param_2 != 0)) {
    *(undefined1 *)(iVar3 + param_3) = 0x2d;
    iVar3 = iVar2 + 2;
  }
  *(undefined1 *)(param_3 + iVar3) = 0;
  FUN_1000_bc24(param_3);
  return param_3;
}


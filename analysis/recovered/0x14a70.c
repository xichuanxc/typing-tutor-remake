/* ev_05209849878248a03378af42c758425c16e5fd3575b98c5764cb4b488dc8f90f */

/* WARNING: Removing unreachable block (ram,0x00014ace) */

undefined2 __cdecl16near
FUN_1000_4a70(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
             undefined2 param_5,undefined2 param_6)

{
  undefined2 uVar1;
  char cVar2;
  char *pcVar3;
  char cVar4;
  int iVar5;
  undefined2 unaff_DS;
  
  *(undefined2 *)0x9d66 = 0xffff;
  *(undefined2 *)0x9d64 = 0xffff;
  *(undefined2 *)0x9d70 = param_3;
  *(undefined2 *)0x9d6c = param_1;
  *(undefined2 *)0x9d6e = param_2;
  FUN_1000_b1f3(0,2,7);
  FUN_1000_4e79(*(undefined2 *)0x9d6c,*(undefined2 *)0x9d6e,0x18);
  for (iVar5 = 0; iVar5 < 0x51; iVar5 = iVar5 + 1) {
    *(undefined1 *)(iVar5 + 0x900) = 0;
  }
  while( true ) {
    while( true ) {
      cVar4 = FUN_1000_4d07();
      FUN_1000_4b92();
      if ((cVar4 == '\x1b') && (*(char *)0x9d50 == '\0')) {
        FUN_1000_b1f3(0,1,7);
        return 0xffff;
      }
      if (cVar4 != '\b') break;
      FUN_1000_4d5f(param_3);
    }
    if (*(int *)0x9d4c != 0) {
      FUN_1000_48d7();
    }
    pcVar3 = (char *)*(undefined2 *)0x9d70;
    *(int *)0x9d70 = *(int *)0x9d70 + 1;
    cVar2 = *pcVar3;
    iVar5 = 0x20;
    if (' ' < cVar4) {
      iVar5 = (int)cVar4;
    }
    uVar1 = *(undefined2 *)0x9d6e;
    *(int *)0x9d6e = *(int *)0x9d6e + 1;
    FUN_1000_4e79(*(undefined2 *)0x9d6c,uVar1,iVar5);
    if (cVar2 == '\0') break;
    FUN_1000_4e79(*(undefined2 *)0x9d6c,*(undefined2 *)0x9d6e,0x18);
    FUN_1000_4dcd((int)cVar4,(int)cVar2,param_3);
  }
  FUN_1000_4e95((int)cVar4,param_3,param_4,param_5,param_6);
  return 0;
}


/* ev_07f875d0d5ed312581cceb5b788ecabeb027ede9c27d0b5e1946fdda3a5711a4 */

void __cdecl16near FUN_1000_4b92(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 unaff_DS;
  undefined4 uVar5;
  long lVar6;
  
  if ((*(int *)0x9d66 < 1) && (*(int *)0x9d66 != 0)) {
    *(undefined2 *)0x9d6a = 0;
    *(undefined2 *)0x9d68 = 0;
    *(undefined2 *)0x9d5e = 0;
    *(undefined2 *)0x9d5c = 0;
    *(undefined2 *)0x9d62 = 0;
    *(undefined2 *)0x9d60 = 0;
    *(undefined2 *)0x9d66 = 0;
    *(undefined2 *)0x9d64 = 0;
    uVar5 = FUN_1000_4cb5();
    *(undefined2 *)0x9d5a = (int)((ulong)uVar5 >> 0x10);
    *(undefined2 *)0x9d58 = (int)uVar5;
  }
  else {
    uVar5 = FUN_1000_4cb5(*(undefined2 *)0x9d58,*(undefined2 *)0x9d5a);
    lVar6 = FUN_1000_4cd6(uVar5);
    *(undefined2 *)0x9d66 = (int)((ulong)lVar6 >> 0x10);
    *(undefined2 *)0x9d64 = (int)lVar6;
    lVar6 = lVar6 - CONCAT22(*(undefined2 *)0x9d62,*(undefined2 *)0x9d60);
    uVar1 = (undefined2)lVar6;
    uVar3 = (undefined2)((ulong)lVar6 >> 0x10);
    *(undefined2 *)0x9d5e = uVar3;
    *(undefined2 *)0x9d5c = uVar1;
    if ((-1 < *(int *)0x9d6a) && ((*(int *)0x9d6a != 0 || (*(int *)0x9d68 != 0)))) {
      uVar5 = FUN_1000_f04d();
      *(undefined2 *)0x9d5e = (int)((ulong)uVar5 >> 0x10);
      *(undefined2 *)0x9d5c = (int)uVar5;
    }
    if ((*(int *)0x9d5e < 0) || ((*(int *)0x9d5e == 0 && (*(uint *)0x9d5c < 0x1f5)))) {
      uVar4 = *(undefined2 *)0x9d5e;
      uVar2 = *(undefined2 *)0x9d5c;
    }
    else {
      uVar4 = 0;
      uVar2 = 500;
    }
    *(undefined2 *)0x9d5e = uVar4;
    *(undefined2 *)0x9d5c = uVar2;
    *(undefined2 *)0x9d6a = uVar3;
    *(undefined2 *)0x9d68 = uVar1;
    uVar1 = *(undefined2 *)0x9d64;
    *(undefined2 *)0x9d62 = *(undefined2 *)0x9d66;
    *(undefined2 *)0x9d60 = uVar1;
  }
  return;
}


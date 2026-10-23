/* ev_09aa656890de3cff10b612b472cd80134fabe531b99f68da8b25ce2a73232d09 */

undefined2 __cdecl16near FUN_1000_7b92(void)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  long lVar2;
  undefined4 uVar3;
  
  FUN_1000_7c0a();
  lVar2 = FUN_1000_81e3(0x60);
  if (lVar2 == 0) {
    lVar2 = FUN_1000_81e3(0x61);
    if (lVar2 == 0) {
      *(undefined2 *)0x8f4e = 0;
      *(undefined2 *)0x8f4c = 0;
      uVar3 = FUN_1000_81e3(0x1c);
      *(undefined2 *)0x8f46 = (int)((ulong)uVar3 >> 0x10);
      *(undefined2 *)0x8f44 = (int)uVar3;
      FUN_1000_81ff(0x61,uVar3);
      FUN_1000_7c98(0x1c,0x81c3);
      *(undefined2 *)0x8f4a = 0;
      *(undefined2 *)0x8f48 = 0;
      *(undefined2 *)0x8f50 = 1;
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffff;
    }
  }
  else {
    uVar1 = 0xffff;
  }
  return uVar1;
}


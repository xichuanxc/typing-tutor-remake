/* ev_aa7e9e36339c07b7aeead8ce2c8f1248bbb6adad0206edf4abb68bd244b9b2b9 */

void __cdecl16near FUN_1000_9d9a(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined2 unaff_DS;
  
  for (iVar4 = 0; iVar4 < *(int *)0xa066; iVar4 = iVar4 + 1) {
    uVar3 = (uint)*(byte *)(param_1 + iVar4 + 0x6af);
    iVar2 = *(int *)(iVar4 * 2 + param_1 + 0x6c1);
    bVar1 = *(byte *)(param_1 + iVar4 + 0x6e5);
    FUN_1000_922d(uVar3 - 1,iVar2 + -1,0x20);
    FUN_1000_922d(uVar3,iVar2 + -1,0x20);
    FUN_1000_922d(uVar3,iVar2 + -2,0x20);
    FUN_1000_922d(uVar3 + 1,iVar2 + -1,0x20);
    for (iVar5 = 0; iVar5 < (int)(uint)bVar1; iVar5 = iVar5 + 1) {
      FUN_1000_922d(uVar3 - 1,iVar2 + iVar5,0x20);
      FUN_1000_922d(uVar3,iVar2 + iVar5,0x20);
      FUN_1000_922d(uVar3 + 1,iVar2 + iVar5,0x20);
    }
    FUN_1000_922d(uVar3 - 1,iVar2 + iVar5,0x20);
    FUN_1000_922d(uVar3,iVar2 + iVar5,0x20);
    FUN_1000_922d(uVar3,iVar2 + iVar5 + 1,0x20);
    FUN_1000_922d(uVar3 + 1,iVar2 + iVar5,0x20);
  }
  *(undefined2 *)0xa066 = 0;
  return;
}


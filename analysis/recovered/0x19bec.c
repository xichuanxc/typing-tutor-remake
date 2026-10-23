/* ev_7b2300e8538311c7d39ada56a9940ca28e285f532be90ee3252f577a587515a9 */

void __cdecl16near FUN_1000_9bec(undefined2 param_1)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  uint uVar7;
  undefined2 unaff_DS;
  
  if (*(int *)(*(int *)0xa07e * 2 + -0x5f98) == 0) {
    FUN_1000_2723(0x8447);
    FUN_1000_f7da(0x18,0);
    FUN_1000_f74a();
    FUN_1000_9296(param_1);
  }
  iVar4 = FUN_1000_529a(*(int *)0xa076,*(int *)0xa076 >> 0xf,*(int *)0xa078,*(int *)0xa078 >> 0xf,
                        0x3b,0,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
  if (iVar4 < 0x5b) {
    uVar5 = 7;
  }
  else {
    uVar5 = 8;
  }
  uVar6 = 3;
  if (*(int *)0xa07c != 0) {
    uVar6 = 2;
  }
  FUN_1000_ae2b(uVar6,0x15,uVar5);
  if (*(int *)0xa07c != 0) {
    FUN_1000_f7da(3,0x17);
    uVar5 = 0x9072;
    if (*(int *)0xa07e != 0) {
      uVar5 = *(undefined2 *)0x6d5;
    }
    FUN_1000_f6a4(0x8448,*(int *)0xa07e + 1,uVar5);
  }
  FUN_1000_f7da(4,0x17);
  FUN_1000_f6a4(0x8456,*(undefined2 *)0xa076);
  FUN_1000_f7da(5,0x17);
  FUN_1000_f6a4(0x845f,*(undefined2 *)0xa078);
  FUN_1000_f7da(6,0x17);
  FUN_1000_f6a4(0x846a,iVar4);
  if (0x5a < iVar4) {
    uVar7 = (iVar4 + -0x5a) * *(int *)0xa076;
    FUN_1000_f7da(7,0x17);
    FUN_1000_b1f3(1,1,6);
    FUN_1000_f6a4(0x8479,uVar7);
    iVar4 = *(int *)0xa07e;
    puVar1 = (uint *)(iVar4 * 4 + -0x6266);
    uVar3 = *puVar1;
    *puVar1 = *puVar1 + uVar7;
    piVar2 = (int *)(iVar4 * 4 + -0x6264);
    *piVar2 = *piVar2 + ((int)uVar7 >> 0xf) + (uint)CARRY2(uVar3,uVar7);
    FUN_1000_f7da(0,0x26);
    FUN_1000_b1f3(1,5,6);
    FUN_1000_f6a4(0x848c,*(undefined2 *)(*(int *)0xa07e * 4 + -0x6266),
                  *(undefined2 *)(*(int *)0xa07e * 4 + -0x6264));
    FUN_1000_b1f3(0,1,7);
  }
  FUN_1000_7d49();
  return;
}


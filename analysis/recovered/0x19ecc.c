/* ev_058f163dc2279e4a432637f1f4346ff5b1a6bdca1d62de9d2077ff441fa0eec1 */

void __cdecl16near FUN_1000_9ecc(void)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  undefined2 unaff_DS;
  
  FUN_1000_7e47(5);
  FUN_1000_07c9(0x40,0);
  *(int *)0xa078 = *(int *)0xa078 + 1;
  iVar3 = *(int *)0xa07e * 4;
  puVar1 = (uint *)(iVar3 + -0x6266);
  uVar2 = *puVar1;
  *puVar1 = *puVar1 - 10;
  *(int *)(iVar3 + -0x6264) = *(int *)(iVar3 + -0x6264) - (uint)(uVar2 < 10);
  if ((*(int *)(iVar3 + -0x6264) < 1) && (*(int *)(iVar3 + -0x6264) != 0)) {
    *(undefined2 *)(iVar3 + -0x6264) = 0;
    *(undefined2 *)(iVar3 + -0x6266) = 0;
  }
  FUN_1000_f7da(0,0x26);
  FUN_1000_b1f3(1,5,6);
  FUN_1000_f6a4(0x8492,*(undefined2 *)(*(int *)0xa07e * 4 + -0x6266),
                *(undefined2 *)(*(int *)0xa07e * 4 + -0x6264));
  FUN_1000_b1f3(0,1,7);
  return;
}


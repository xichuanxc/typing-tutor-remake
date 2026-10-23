/* ev_c5aac710168207ae0ef4418acd1603efb59130ea0e4f7ad49b953703179020c2 */

/* WARNING: Removing unreachable block (ram,0x00017b14) */

undefined2 __cdecl16near FUN_1000_7a75(int param_1,int param_2)

{
  undefined2 uVar1;
  uint uVar2;
  undefined2 unaff_DS;
  
  uVar2 = (*(int *)0xa04a + 1U) % 0xaa;
  if (uVar2 == *(uint *)0xa04c) {
    uVar1 = 0xffff;
  }
  else {
    uVar1 = 0;
    if (param_2 != 0 || param_1 != 0) {
      uVar1 = FUN_1000_f04d();
    }
    *(undefined2 *)(uVar2 * 4 + -0x625e) = uVar1;
    uVar1 = FUN_1000_f04d();
    *(undefined2 *)(uVar2 * 4 + -0x625c) = uVar1;
    *(uint *)0xa04a = uVar2;
    uVar2 = (uVar2 + 1) % 0xaa;
    if (uVar2 == *(uint *)0xa04c) {
      uVar1 = 0xffff;
    }
    else {
      *(undefined2 *)(uVar2 * 4 + -0x625e) = 0;
      uVar1 = FUN_1000_f04d();
      *(undefined2 *)(uVar2 * 4 + -0x625c) = uVar1;
      *(uint *)0xa04a = uVar2;
      uVar1 = 0;
    }
  }
  return uVar1;
}


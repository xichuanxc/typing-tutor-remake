/* ev_2f3d1f7ca741033283b129ff9d3a18866b22154c3c884b35b433b58db8566304 */

undefined2 __cdecl16near FUN_1000_531a(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar4 = *(int *)(unaff_BP + 4) * 4;
  if (*(int *)(iVar4 + -0x652a) + *(int *)(iVar4 + -0x63fe) +
      (uint)CARRY2(*(uint *)(iVar4 + -0x652c),*(uint *)(iVar4 + -0x6400)) == 0 &&
      *(uint *)(iVar4 + -0x652c) + *(uint *)(iVar4 + -0x6400) == 0) {
    return 0;
  }
  if (*(int *)(unaff_BP + 4) < 0x1d) {
    bVar1 = *(byte *)0x90b3;
  }
  else {
    bVar1 = *(byte *)0x90b4;
  }
  uVar3 = (uint)bVar1;
  uVar2 = FUN_1000_52dc(*(undefined2 *)(iVar4 + -0x652c),*(undefined2 *)(iVar4 + -0x652a),
                        *(undefined2 *)(iVar4 + -0x6400),*(undefined2 *)(iVar4 + -0x63fe),
                        *(undefined2 *)(iVar4 + -0x6658),*(undefined2 *)(iVar4 + -0x6656));
  if (uVar3 <= uVar2) {
    iVar4 = *(int *)(unaff_BP + 4) * 4;
    uVar3 = FUN_1000_529a(*(undefined2 *)(iVar4 + -0x652c),*(undefined2 *)(iVar4 + -0x652a),
                          *(undefined2 *)(iVar4 + -0x6400),*(undefined2 *)(iVar4 + -0x63fe));
    if (*(byte *)0x1c90 <= uVar3) {
      return 0;
    }
  }
  return 1;
}


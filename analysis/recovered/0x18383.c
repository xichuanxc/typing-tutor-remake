/* ev_60a09eb0bf002a9d97f9f20b747b7ea99ff5fa7b7984fefbf44dd61a54182ec6 */

byte __cdecl16near FUN_1000_8383(void)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if (*(char *)(unaff_BP + 8) == '\0') {
    if (*(char *)(unaff_BP + 6) == '\0') {
      iVar4 = (uint)*(byte *)(unaff_BP + 4) * 4;
      iVar5 = (uint)*(byte *)(unaff_BP + 4) * 4;
      iVar3 = (uint)*(byte *)(unaff_BP + 4) * 4;
      bVar1 = FUN_1000_52dc(*(undefined2 *)(iVar3 + -0x6dce),*(undefined2 *)(iVar3 + -0x6dcc),
                            *(undefined2 *)(iVar5 + -0x6ca2),*(undefined2 *)(iVar5 + -0x6ca0),
                            *(undefined2 *)(iVar4 + -0x6efa),*(undefined2 *)(iVar4 + -0x6ef8));
    }
    else {
      iVar4 = (uint)*(byte *)(unaff_BP + 4) * 4;
      iVar5 = (uint)*(byte *)(unaff_BP + 4) * 4;
      iVar3 = (uint)*(byte *)(unaff_BP + 4) * 4;
      bVar1 = FUN_1000_52dc(*(undefined2 *)(iVar3 + -0x652c),*(undefined2 *)(iVar3 + -0x652a),
                            *(undefined2 *)(iVar5 + -0x6400),*(undefined2 *)(iVar5 + -0x63fe),
                            *(undefined2 *)(iVar4 + -0x6658),*(undefined2 *)(iVar4 + -0x6656));
    }
    *(byte *)(unaff_BP + 4) = bVar1;
    if (0x68 < bVar1) {
      *(undefined1 *)(unaff_BP + 4) = 100;
    }
  }
  else {
    if (*(char *)(unaff_BP + 6) == '\0') {
      iVar4 = (uint)*(byte *)(unaff_BP + 4) * 4;
      iVar5 = (uint)*(byte *)(unaff_BP + 4) * 4;
      uVar2 = FUN_1000_529a(*(undefined2 *)(iVar5 + -0x6dce),*(undefined2 *)(iVar5 + -0x6dcc),
                            *(undefined2 *)(iVar4 + -0x6ca2),*(undefined2 *)(iVar4 + -0x6ca0));
    }
    else {
      iVar4 = (uint)*(byte *)(unaff_BP + 4) * 4;
      iVar5 = (uint)*(byte *)(unaff_BP + 4) * 4;
      uVar2 = FUN_1000_529a(*(undefined2 *)(iVar5 + -0x652c),*(undefined2 *)(iVar5 + -0x652a),
                            *(undefined2 *)(iVar4 + -0x6400),*(undefined2 *)(iVar4 + -0x63fe));
    }
    *(undefined1 *)(unaff_BP + 4) = uVar2;
  }
  return *(byte *)(unaff_BP + 4) / 5;
}


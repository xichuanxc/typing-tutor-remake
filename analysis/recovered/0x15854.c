/* ev_1e0affa47a9209793f57145fb1bdcc7514672f69b198ed1eea51939aa7babf6f */

int __cdecl16near FUN_1000_5854(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined2 uVar4;
  int unaff_BP;
  uint uVar5;
  int iVar6;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  uVar5 = 0;
  if (0x1c < *(byte *)0x90af) {
    uVar5 = 0x15;
  }
  *(uint *)(unaff_BP + -2) = uVar5;
  *(undefined2 *)(unaff_BP + -6) = 0;
  for (iVar6 = 0; iVar6 < 3; iVar6 = iVar6 + 1) {
    *(undefined2 *)(iVar6 * 2 + unaff_BP + -0xc) = 0;
    for (; ((int)uVar5 < *(int *)(iVar6 * 2 + 0x1ed2) && (uVar5 <= *(byte *)0x90af));
        uVar5 = uVar5 + 1) {
      iVar2 = FUN_1000_544e(uVar5);
      if ((iVar2 == 0) && (0x1c < (int)uVar5)) {
        uVar3 = (uint)*(byte *)(uVar5 + 0x90bb) << 1;
      }
      else {
        uVar3 = (uint)*(byte *)(uVar5 + 0x90bb);
      }
      piVar1 = (int *)(iVar6 * 2 + unaff_BP + -0xc);
      *piVar1 = *piVar1 + uVar3;
    }
    *(int *)(unaff_BP + -6) = *(int *)(unaff_BP + -6) + *(int *)(iVar6 * 2 + unaff_BP + -0xc);
  }
  iVar6 = FUN_1000_bd74(*(undefined2 *)(unaff_BP + -6));
  iVar6 = iVar6 - *(int *)(unaff_BP + -0xc);
  *(int *)(unaff_BP + -4) = iVar6;
  if (iVar6 < 1) {
    uVar4 = FUN_1000_57cc(*(undefined2 *)(unaff_BP + -2),0x25);
    switch(uVar4) {
    case 0xf:
      iVar6 = FUN_1000_bd74(4);
      return iVar6 + 0xc;
    case 0x1d:
    case 0x1f:
      iVar6 = FUN_1000_bd74(3);
      return iVar6 + 0x28;
    case 0x1e:
      iVar6 = FUN_1000_bd74(2);
      return iVar6 + 0x30;
    case 0x20:
      iVar6 = FUN_1000_bd74(7);
      return iVar6 + 0x1a;
    case 0x21:
      iVar6 = FUN_1000_bd74(2);
      return iVar6 + 0x2e;
    case 0x22:
    case 0x23:
      return 0x15;
    case 0x24:
      iVar6 = FUN_1000_bd74(2);
      return iVar6 + 0xe;
    }
    if (*(byte *)0x90af < 9) {
      iVar6 = FUN_1000_bd74(*(undefined1 *)(*(byte *)0x90ae + 0x1ed8));
      return iVar6 + 5;
    }
    iVar6 = FUN_1000_bd74(*(byte *)(*(byte *)0x90ae + 0x1ed8) - 2);
    return iVar6 + 7;
  }
  if (*(int *)(unaff_BP + -4) - *(int *)(unaff_BP + -10) < 1) {
    iVar6 = FUN_1000_bd74(7);
    return iVar6 + 0x21;
  }
  iVar6 = FUN_1000_57cc(0x2f,0x40);
  switch(iVar6 + -0x2f) {
  case 0:
  case 2:
  case 3:
  case 5:
  case 7:
    return 0x16;
  case 1:
    iVar6 = FUN_1000_bd74(2);
    return iVar6 + 0x2c;
  case 4:
    iVar6 = FUN_1000_bd74(2);
    return iVar6 + 0x30;
  case 6:
    return 0x2b;
  case 8:
  case 9:
    iVar6 = FUN_1000_bd74(2);
    return iVar6 + 0x15;
  case 10:
    iVar6 = FUN_1000_bd74(3);
    return iVar6 + 0x16;
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
    return 0x15;
  case 0xf:
  case 0x10:
    return 0x32;
  default:
    return iVar6 + -0x2f;
  }
}


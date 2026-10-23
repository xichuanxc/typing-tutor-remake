/* ev_932dd8714fd05f65b08138f4ec8f3cca013d9fc54ec576e7f22264ed654bec7d */

void __cdecl16near FUN_1000_4f6c(char param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  bool bVar4;
  int local_c [3];
  int local_6;
  uint local_4;
  
  local_c[1] = 0;
  local_c[0] = 0;
  bVar4 = false;
  if (*(int *)0x9d5e == 0) {
    bVar4 = *(int *)0x9d5c == 0;
  }
  if (!bVar4) {
    if (param_1 != ' ') {
      if (*(char *)0x9d4f == '\0') {
        local_6 = FUN_1000_722b((int)param_1);
      }
      else {
        local_6 = FUN_1000_e08c((int)param_1);
      }
      if (param_2 == 0) {
        iVar2 = local_6 * 4 + -0x6400;
      }
      else {
        iVar2 = local_6 * 4 + -0x652c;
      }
      FUN_1000_4f2b(local_6 * 4 + *(int *)0x9d3c,local_c,local_6 * 4 + -0x6658,iVar2);
      if (*(int *)0x9d2c < 8) {
        if (param_2 == 0) {
          piVar1 = (int *)(local_6 * 2 + *(int *)0x9d3c + 0x1c2);
          *piVar1 = *piVar1 + local_c[0];
        }
        else {
          piVar1 = (int *)(local_6 * 2 + *(int *)0x9d3c + 300);
          *piVar1 = *piVar1 + local_c[0];
        }
      }
      if (param_2 == 0) {
        local_4 = (uint)(*(byte *)(local_6 + -0x6f45) >> 5) + (uint)*(byte *)(local_6 + -0x6f45) + 1
        ;
      }
      else {
        iVar2 = local_6 * 4;
        iVar2 = FUN_1000_52dc(*(undefined2 *)(iVar2 + -0x652c),*(undefined2 *)(iVar2 + -0x652a),
                              *(undefined2 *)(iVar2 + -0x6400),*(undefined2 *)(iVar2 + -0x63fe),
                              *(undefined2 *)(iVar2 + -0x6658),*(undefined2 *)(iVar2 + -0x6656));
        if (iVar2 == 0) {
          iVar2 = 1;
        }
        local_4 = (int)(0x7f8 / (long)iVar2) * 3 + (uint)*(byte *)(local_6 + -0x6f45) >> 2;
      }
    }
    if (((*(byte *)(param_1 + -0x7183) & 3) == 0) &&
       ((iVar2 = FUN_1000_e677(0x1c83,(int)param_1), iVar2 == 0 || (*(char *)0x9d4f != '\0')))) {
      if (((*(byte *)(param_1 + -0x7183) & 4) == 0) || (*(char *)0x9d4f != '\0')) {
        if (*(char *)0x9d4f == '\0') {
          uVar3 = 0x9743;
          if (param_2 == 0) {
            iVar2 = *(int *)0x9d3a + 0x41;
          }
          else {
            uVar3 = 0x973f;
            iVar2 = *(int *)0x9d3a + 0x3d;
          }
          FUN_1000_4f2b(*(int *)0x9d3a + 0x39,iVar2,0x973b,uVar3);
        }
      }
      else {
        uVar3 = 0x9737;
        if (param_2 == 0) {
          iVar2 = *(int *)0x9d3a + 0x35;
        }
        else {
          uVar3 = 0x9733;
          iVar2 = *(int *)0x9d3a + 0x31;
        }
        FUN_1000_4f2b(*(int *)0x9d3a + 0x2d,iVar2,0x972f,uVar3);
      }
    }
    else {
      uVar3 = 0x972b;
      if (param_2 == 0) {
        iVar2 = *(int *)0x9d3a + 0x29;
      }
      else {
        uVar3 = 0x9727;
        iVar2 = *(int *)0x9d3a + 0x25;
      }
      FUN_1000_4f2b(*(int *)0x9d3a + 0x21,iVar2,0x9723,uVar3);
    }
    if (param_1 != ' ') {
      if (0xff < local_4) {
        local_4 = 0xff;
      }
      if ((*(byte *)(param_1 + -0x7183) & 3) != 0) {
        *(int *)0x9d36 = *(int *)0x9d36 + (local_4 - *(byte *)(local_6 + -0x6f45));
      }
      *(undefined1 *)(local_6 + -0x6f45) = (char)local_4;
    }
  }
  return;
}


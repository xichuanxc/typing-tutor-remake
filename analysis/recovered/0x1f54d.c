/* ev_93f6707ede3359a9361baed1414d5f14e76a80eac7bd929af2d2f86f3f598386 */

void __cdecl16near FUN_1000_f54d(undefined2 *param_1,undefined2 *param_2,uint param_3)

{
  undefined1 *puVar1;
  undefined2 *puVar2;
  undefined1 *puVar3;
  undefined2 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined2 unaff_DS;
  byte bVar7;
  
  bVar7 = 0;
  if (param_2 != param_1) {
    if (param_2 < param_1) {
      if ((param_3 & 1) != 0) {
        puVar4 = param_2;
        param_2 = (undefined2 *)((int)param_2 + 1);
        puVar2 = param_1;
        param_1 = (undefined2 *)((int)param_1 + 1);
        *(undefined1 *)puVar4 = *(undefined1 *)puVar2;
      }
    }
    else {
      bVar7 = 1;
      puVar6 = (undefined1 *)((int)param_2 + (param_3 - 1));
      puVar5 = (undefined1 *)((int)param_1 + (param_3 - 1));
      if ((param_3 & 1) != 0) {
        puVar3 = puVar6;
        puVar6 = (undefined1 *)((int)param_2 + (param_3 - 2));
        puVar1 = puVar5;
        puVar5 = (undefined1 *)((int)param_1 + (param_3 - 2));
        *puVar3 = *puVar1;
      }
      param_2 = (undefined2 *)(puVar6 + -1);
      param_1 = (undefined2 *)(puVar5 + -1);
    }
    param_3 = param_3 >> 1;
    if (param_3 != 0) {
      for (; param_3 != 0; param_3 = param_3 - 1) {
        puVar4 = param_2;
        param_2 = param_2 + (uint)bVar7 * -2 + 1;
        puVar2 = param_1;
        param_1 = param_1 + (uint)bVar7 * -2 + 1;
        *puVar4 = *puVar2;
      }
    }
  }
  return;
}


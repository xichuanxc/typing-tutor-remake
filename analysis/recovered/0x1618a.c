/* ev_847e9a5bd89cbb247ad64aa35afd0b28b283bf3578d03c4afb742935561aefbd */

undefined2 __cdecl16near FUN_1000_618a(void)

{
  char cVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  int unaff_BP;
  int iVar4;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if (*(char *)0x9d4e != '\0') {
    FUN_1000_5a53();
  }
  if (*(char *)0x9d88 == '\0') {
    *(undefined2 *)*(undefined2 *)(unaff_BP + 4) = 1;
  }
  else {
    *(undefined2 *)*(undefined2 *)(unaff_BP + 4) = 0;
    *(undefined1 *)0x9d88 = 0;
  }
LAB_1000_61b6:
  do {
    cVar1 = FUN_1000_64cc();
    *(char *)(unaff_BP + -1) = cVar1;
    if (cVar1 != '\0') {
      if (*(char *)0x9bb == '\0') goto LAB_1000_61b6;
    }
    if (*(char *)(unaff_BP + -1) == '\0') {
      FUN_1000_5a53();
      *(undefined1 *)0x9bb = 0;
      *(undefined1 *)0x9d4e = 1;
    }
    if (*(char *)(unaff_BP + -1) != '\0') {
      if (*(char *)0x9d4e == '\0') {
        if (*(char *)0x9d8b != '\0') {
          uVar2 = FUN_1000_e793((int)*(char *)0x9bb);
          *(undefined1 *)0x9bb = uVar2;
          *(undefined1 *)0x9d8b = 0;
        }
        iVar4 = (int)*(char *)0x9bb;
        if ((((((*(byte *)(iVar4 + -0x7183) & 7) == 0) && (*(char *)0x9d88 == '\0')) &&
             (iVar4 != 0x24)) && ((iVar4 != 0x2d && (iVar4 != 0x5f)))) &&
           ((iVar4 != 0x5e && ((iVar4 != 0x26 && (iVar4 != 0x28)))))) {
          *(undefined2 *)*(undefined2 *)(unaff_BP + 4) = 0;
        }
      }
      else {
        uVar3 = 1;
        if (*(char *)0x90ba != '\0') {
          uVar3 = 2;
        }
        *(undefined2 *)*(undefined2 *)(unaff_BP + 4) = uVar3;
        if ((*(char *)0x9bb == '\'') || (*(char *)0x9bb == '\"')) {
          *(undefined1 *)0x9d8b = 1;
        }
        else {
          uVar2 = FUN_1000_e793((int)*(char *)0x9bb);
          *(undefined1 *)0x9bb = uVar2;
        }
        *(undefined1 *)0x9d4e = 0;
      }
      if (*(char *)0x90ba == '\0') {
        for (iVar4 = 0; *(char *)(iVar4 + 0x9bb) != '\0'; iVar4 = iVar4 + 1) {
          uVar2 = FUN_1000_e7a7((int)*(char *)(iVar4 + 0x9bb));
          *(undefined1 *)(iVar4 + 0x9bb) = uVar2;
        }
      }
      return 0;
    }
  } while( true );
}


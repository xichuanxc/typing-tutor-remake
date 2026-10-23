; ev_a41f1a7e3a21d1b41dc3fdfe8bef12e0e52eeb8c1d2e62678dd3f1177b994203
0x173cc: MOV AX, 0x0
0x173cf: CALL 0x1000:e7bd
0x173d2: MOV AX, 0x2121
0x173d5: PUSH AX
0x173d6: CALL 0x1000:7251
0x173d9: POP CX
0x173da: MOV BX, word ptr [BP + 0x4]
0x173dd: MOV BX, word ptr [BX]
0x173df: MOV byte ptr [BX], AL
0x173e1: TEST AL, AL
0x173e3: JZ 0x1000:73ea
0x173e5: MOV BX, word ptr [BP + 0x4]
0x173e8: INC word ptr [BX]
0x173ea: RET

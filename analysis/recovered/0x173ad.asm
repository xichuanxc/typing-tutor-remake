; ev_51dc8569c6f365cb2bb7bee6dcb75459c3e36dcc65f45b492c773afa00a5eb8a
0x173ad: MOV AX, 0x0
0x173b0: CALL 0x1000:e7bd
0x173b3: MOV AX, 0x2116
0x173b6: PUSH AX
0x173b7: CALL 0x1000:7251
0x173ba: POP CX
0x173bb: MOV BX, word ptr [BP + 0x4]
0x173be: MOV BX, word ptr [BX]
0x173c0: MOV byte ptr [BX], AL
0x173c2: TEST AL, AL
0x173c4: JZ 0x1000:73cb
0x173c6: MOV BX, word ptr [BP + 0x4]
0x173c9: INC word ptr [BX]
0x173cb: RET

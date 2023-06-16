format  MZ ;allows multiple segments

        entry main:start ;the beginning of the program

;=========================================================================================================================================================================
segment main

a               db      10
b               db      4
task            db      'Task: A^2/B+B$'
message1        db      10, 13, 'Using stack: $'
message2        db      10, 13, 'Using paramenters: $'
message3        db      10, 13, 'Using global values: $'

start:

        mov     ax, cs ;updating the pointer to the data segment (because "MOV DS, CS" is not a legal 8086 instruction)
        mov     ds, ax ;real offset of the segment in which the data resides

        mov     di, task
        push    di
        call    typeProcedure

        ;=================================================================================================================================================================
        mov     di, message1
        push    di
        call    typeProcedure

        mov     di, word [a]
        push    di
        mov     di, word [b]
        push    di

        call    stackProcedure
        push    ax
        call    outputProcedure

        ;==================================================================================================================================================================
        mov     di, message2
        push    di
        call    typeProcedure

        mov     al, [a]
        mov     bl, [b]
        call    far Procedures: regProcedure
        push    ax
        call    outputProcedure

        ;==================================================================================================================================================================
        mov     di, message3
        push    di
        call    typeProcedure

        call    far Procedures: valProcedure
        push    ax
        call    outputProcedure

        mov     ah, 08h ;wait to close window on key press
        int     21h

        mov     ah, 4ch ;program terminates control to the operating system
        int     21h

stackProcedure:
        push    bp
        mov     bp, sp
        mov     bl, [bp+6]
        mov     al, bl
        mul     bl
        mov     bl, [bp+4]
        div     bl
        add     al, [bp+4]
        pop     bp
        ret     4

typeProcedure:
        push    bp
        mov     bp, sp
        mov     dx, [bp+4]
        mov     ah, $09
        int     21h
        pop     bp
        ret     2

outputProcedure:
        push    bp
        mov     bp, sp
        mov     ax, [bp+4]

        xor      cx, cx
        mov      bx, 10
 
pushing:
        xor     dx, dx
        div     bx
        add     dl, '0'
        push    dx
        inc     cx

        test    ax, ax
        jnz     pushing
 
poping:
        pop     dx
        mov     ah, $02
        int     21h
        loop    poping
        pop     bp

        ret     2

;=========================================================================================================================================================================
segment Procedures

;outputProcedure:
        mov     dl, al
        mov     ah, $02
        add     dl, '0'
        int     21h
        retf

regProcedure:
        mov     cl, al
        mul     cl
        div     bl
        add     al, bl
        retf

valProcedure:
        mov     bl, [a]
        mov     al, bl
        mul     bl
        mov     bl, [b]
        div     bl
        add     al, [b]
        retf
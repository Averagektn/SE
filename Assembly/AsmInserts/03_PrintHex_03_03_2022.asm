        org 100h

EntryPoint:
        mov     bx, 42

        mov     cx, 4
.PrintLoop:
        rol     bx, 4
        mov     ax, bx
        and     ax, 0000'0000_0000'1111b

;        cmp     ax, 10
;        jae     .Letter
;.Digit:
;        add     ax, '0'
;        jmp     .EndIf
;.Letter:
;        add     ax, 'A' - 10
;.EndIf:

        cmp     al, 10
        sbb     al, $69
        das

        mov     ah, $02
        mov     dl, al
        int     21h

        loop    .PrintLoop

        mov     ax, $0C08
        int     21h
        test    al, al
        jnz     @F
        mov     ah, $08
        int     21h
@@:
        ret
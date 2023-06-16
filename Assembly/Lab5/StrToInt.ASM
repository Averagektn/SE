org 100h

        mov ah,09h
        mov dx,Char
        int 21h

        mov dx,NewStr
        int 21h

        xor si,si
Count:
        cmp [Char+si],'$'
        je @F
        add si,2
        jmp Count
@@:
        sub si,2


        xor cx,cx
StackPush:
        push [Char+si]
        sub si,2
        cmp si,0
        jb @F
        inc cx
        jae StackPush
@@:
        xor si,si
        dec cx

CharToInt:
        pop [Num+si]
        sub [Num+si],'0'
        add si,2
        loop CharToInt

        mov [Num+si],'$'



        mov ah,09h
        mov dx,Num
        int 21h


        mov ax, 0c08h
        int 21h
        test al,al
        jnz Exit
        mov ah,08h
        int 21h
Exit:
        ret

Char dw '10','12','23','$'
Num dw ?
NewStr dw 10,13,'$'
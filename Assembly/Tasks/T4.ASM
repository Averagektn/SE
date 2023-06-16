org 100h

Start:

        mov ah,09h
        mov dx,S
        int 21h

        mov ah,09h
        mov dx,NewStr
        int 21h

        mov ah,09h
        mov dx,Arr
        int 21h

        mov ah,09h
        mov dx,NewStr
        int 21h

        push 8d

        call Proc

        add ax,'0'
        mov [A],ax

        mov ah,09h
        mov dx,A
        int 21h

        mov ah,08h
        int 21h

ret

S db 'Result: $'
NewStr db 13,10,'$'
Arr db ' 1a1 ','$'
A dw 5 dup(?),'$'

Proc:
        push bp
        mov bp,sp
        push bx

        mov bx,[bp + 4]
        xor ax,ax

.C:
        scasb
        je .C
        dec di

        xor ax,ax
.C1:
        shl ax,1
        shr bx,1
        adc ax,0
        test bx,bx
        jnz .C1

        pop bx
        pop bp
        ret 2



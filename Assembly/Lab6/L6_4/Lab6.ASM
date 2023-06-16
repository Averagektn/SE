org 100h

Start:

        mov ah,0Ah
        mov dx,InputA
        int 21h

        mov cx,[InputA]
        dec cx
        mov ax,cx
        mov bx,2

CPush:
        push [InputA + bx]
        add bx,2
        loop CPush

        mov cx,ax

        call ConvertToStr

        mov [Buf],bx

        mov ah,09h
        mov dx,NewStr
        int 21h

        mov ah,09h
        mov dx,Buf
        int 21h

        mov ax,0C08h
        int 21h
        test al,al
        jnz @f
        mov ah,08h
        int 21h
@@:
ret

Buf dw ?,'$'
NewStr dw 13,10,'$'
InputA dw 4,0
InputB dw 4,0
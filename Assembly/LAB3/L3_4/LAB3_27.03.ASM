org 100h
Start:
        ;перевод сивола в число

        mov ax,35
        mov bx,10
        mov bp,0
Convert:
        xor dx,dx
        div bx
        add dl,'0'
        push dx
        inc bx
        cmp ax,0

        je Output
        jmp Convert

        mov cx,bx
Mem:
        pop [Res+bx]
        loop Mem

Output:
        mov ah,09h
        mov dx,Res
        int 21h

        mov ah,08h
        int 21h

ret

Res dw 17 dup('$')
Arr db 10,4,5,3,9,74,56,12,34,54

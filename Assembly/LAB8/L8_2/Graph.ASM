        org 100h

Start:

        mov ah,0Fh
        int 10h

        mov [BOldMode],al
        mov [BOldPage],ah

        ; set video mode = mov ax,0003h
        mov ax,0013h
        int 10h

        push $A000
        pop es

        xor di,di
        mov al,$0F
        mov cx,320*100
        rep stosb

        mov di,320*100
        mov al,27h
        mov cx,320*100
        rep stosb

        xor di,di
        mov al,20h
        mov bx,1
        mov cx,100
.CycleUp:
        push cx
        mov cx,bx
        push cx
        inc bx
        rep stosb
        pop cx
        sub di,cx
        add di,320
        pop cx
        loop .CycleUp

        mov di,320*100
        mov al,20h
        mov bx,100
        mov cx,100
.CycleDown:
        push cx
        mov cx,bx
        push cx
        dec bx
        rep stosb
        pop cx
        sub di,cx
        add di,320
        pop cx
        loop .CycleDown

        mov ax,0c08h
        int 21h
        test al,al
        jnz @F
        mov ah,08h
        int 21h
@@:

        movzx ax,[BOldMode]
        int 10h

        mov ah,05h
        mov al,[BOldPage]
        int 10h

ret

BOldMode db ?
BOldPage db ?
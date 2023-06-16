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

        xor di,di           ; fill with white
        mov al,$0F
        mov cx,320*200
        rep stosb

        xor di,di           ; paint black left rectangle
        mov al,00h
        mov cx,200
.C1:
        push cx
        mov cx,60
        rep stosb
        add di,320 - 60
        pop cx
        loop .C1

        mov di,320 - 60     ; paint black right rectangle
        mov al,00h
        mov cx,200
.C2:
        push cx
        mov cx,60
        rep stosb
        add di,320 - 60
        pop cx
        loop .C2

        mov di,200 - 15 + 60  ; paint up right part with blue
        mov al,20h            ; 200: size of the square
        mov cx,15             ; 15: half of the blue line size
        mov bx,15             ; 60: (320 - 200) / 2
                              ; cx - number of lines, bx - length of the first line
C1:
        push cx
        mov cx,bx
        inc bx
        rep stosb
        sub di,bx            ; 320 - bx = di: length of the field - length of the line
        add di,320
        pop cx
        loop C1

                             ; paint main part with blue
        mov cx,170           ; cx = 170 = 200 - 15 - 15: 15 - number of lines on the top and bottom
C2:
        push cx
        mov cx,30            ; 30 - length of the line
        rep stosb
        add di,320           ; di = 320 - length of the line - 1
        sub di,30
        dec di
        pop cx
        loop C2
                             ; paint left bottom part of the flag with blue
        mov cx,15            ; cx - number of lines
        mov bx,30            ; bx - length of the line
C3:
        push cx
        mov cx,bx
        dec bx
        rep stosb
        add di,320           ; di = 320 - length of the line - 1
        sub di,bx
        dec di
        pop cx
        loop C3

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
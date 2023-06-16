org 100h

Start:

        mov ah,$0A ; Input
        mov dx,buf
        int 21h

        mov bh,[buf + 4]  ; Convertions
        mov ch,[buf + 5]
        mov [buf + 4],ch
        mov [buf + 5],bh

        mov ch,[buf + 9]
        mov bh,[buf + 6]
        sub ch,bh
        mov bh,[buf + 2]
        sub bh,ch
        mov [buf + 7],bh

        mov ah,02h ;New string
        mov dl,10
        int 21h

        mov ah,09h ;Displaying result
        mov dx,message
        int 21h

        mov ah,$09
        mov dx,buf + 2
        int 21h

        mov ax,$0c08 ;Keep console on the screen
        int 21h
        test al,al
        jnz @F
        mov ah,08h
        int 21h
@@:
        ret


buf db 9,0,10 dup ('$')
message : db 13,10,'Result : $'
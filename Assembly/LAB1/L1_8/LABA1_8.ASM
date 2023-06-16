org 100h

Start:

        mov ah,$09
        mov dx,Message
        int 21h

        mov ah,$0A
        mov dx,buf
        int 21h

        mov ah,$09
        mov dx,Message2
        int 21h

        mov dx,buf + 2
        int 21h

        mov bh,[buf + 4]
        mov ch,[buf + 5]
        mov [buf + 4],ch
        mov [buf + 5],bh

        mov bh,[buf + 6]
        mov ch, [buf + 9]
        sub ch ,bh
        mov cl , [buf + 2]
        sub cl, ch
        mov [buf + 7], cl

        mov dx,buf + 2
        int 21h

        mov ax,0c08h
        int 21h
        test al, al
        jnz @F
        mov ah, 08h
        int 21h
@@:
        ret

Message db 'Enter your text ',13,10,'$'
Message2 db 13,10,'Your text after all changes: ',13,10,'$'
buf db 10,0,11 dup('$')





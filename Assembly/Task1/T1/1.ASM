org 100h

Start:

        mov ah,0ah
        mov dx,Input + 7
        int 21h

        mov ah,02h
        mov dl,10
        int 21h

        mov ah,09h
        mov dx,Input + 2
        int 21h

        mov ax,0c08h
        int 21h

        test al,al
        jnz @F

        mov ah,08h
        int 21h

@@:

        ret

Input db 255,0,'Hello,',247 dup ('$')




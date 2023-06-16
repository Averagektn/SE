org 100h

Start:

        mov ah,0ah
        mov dx,Input
        int 21h

        mov ah,09h
        mov dx,NewStr
        int 21h

        mov bh,0
        mov bl,[Input+1]
        mov [Input+bx+2],'!'
        mov [Input+bx+3],'$'


        mov ah,09h
        mov dx,Message
        int 21h

        mov ah,09h
        mov dx,Input+2
        int 21h

        mov ah,08h
        int 21h

        ret

NewStr db 13,10,'$'
Message db 13,10,'Hello,$'
Input db 255,0




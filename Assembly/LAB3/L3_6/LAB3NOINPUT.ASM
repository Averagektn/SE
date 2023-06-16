org 100h

Start:

Input:

        mov ah,09h
        mov dx,Mes
        int 21h

        mov dx,NewStr
        int 21h

        mov dh,[Mas]
        mov dl,[Mas]
        mov ax,0
        mov si,0
        mov cx,4
Find:
        mov bx,cx
        cmp dh,[Mas+bx]
        jae More
        cmp dl,[Mas+bx]
        jbe Less
        jmp LoopArr
More:
        mov dh,[Mas+bx]
        mov ax,bx
        jmp LoopArr
Less:
        mov dl,[Mas+bx]
        mov si,bx

LoopArr:
        loop Find

        mov bx,ax
        mov [Mas+bx],'0'
        mov bx,si
        mov [Mas+bx],'0'

        mov ah,09h
        mov dx,Mas
        int 21h

Exit:
        mov ax,0c08h
        int 21h
        test al,al
        jnz @F
        mov al,08h
        int 21h
@@:

        ret

Mes db 'Enter data$'

Mas db 5,1,20,25,5,'$'

NewStr db 13,10,'$'

pop ax
mov bx,10
Convert:
div bx
push dx
test ax,ax
jnz @




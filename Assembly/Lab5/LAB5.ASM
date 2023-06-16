org 100h
        
;====== START ======;
        mov ah, 09h
        mov dx, Mes1
        int 21h

        mov ah, 09h
        mov dx, Input
        int 21h
        
        mov ah, 09h
        mov dx, NewStr
        int 21h
        
        mov ah, 09h
        mov dx, Mes2
        int 21h

        mov ah,01h
        int 21h

        mov di,Input
        mov cx,13
        xor bx,bx

Find:
        scasb
        jae Skip
        inc bx
Skip:
        loop Find

        mov ah,09h
        mov dx,NewStr
        int 21h

        mov dx,Mes3
        int 21h

        mov ax,bx
        call Output

        mov ax, 0c08h
        int 21h
        test al,al
        jnz Exit
        mov ah,08h
        int 21h
Exit:
        ret

        Mes1 db "Enter the string: $"
        Mes2 db "Code of compareing symbol $"
        Mes3 db "Result: $"
        NewStr db 13, 10, '$'
        Arr dw ?
        Input db '123','4','5','6','7','8','9','2','3','4','5','$'

Output:
        mov bx,10
        xor cx,cx

@@:
        xor dx,dx
        div bx
        push dx
        inc cx
        test ax,ax
        jnz @B

@@:
        pop [Arr]
        add [Arr],'0'
        mov ah,02h
        mov dx,[Arr]
        int 21h
        loop @B

ret
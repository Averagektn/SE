org 100h

; Message1+NewStr
        mov ah,09h
        mov dx,Mes1
        int 21h
        mov dx,NewStr
        int 21h

; Output of arrays
        call Convertion
        call Swap
        mov ah,09h
        mov dx,NewStr
        int 21h
        call Convertion
        mov dx,NewStr
        int 21h

; Message3+NewStr
        mov dx,NewStr
        int 21h
        mov dx,Mes3
        int 21h


; Prepares
        xor bp,bp
        xor di,di
Start:
        xor si,si

        mov ax,[Mas+bp]
Search:

; Finding equal elements
        cmp ax,[NewMas+si]
        jne Iteration

; Incrementing numer of repeats and showing equal number
        inc di
        call Output

; Modifyng cycle parameters
Iteration:
        add si,2
        cmp si,20d
        jne Search

        add bp,2
        cmp bp,20d
        jne Start



        mov ah,09h
        mov dx,NewStr
        int 21h
        mov dx,Mes2
        int 21h
        mov ax,di
        call Output

        mov ax,0c08h
        int 21h
        test al,al
        jnz @f
        mov ah,08h
        int 21h
@@:
        ret

Mes1 db 'Original arrays: $'

Mes2 db 'Number of repeats: $'

Mes3 db 'Elements thet repeat: $'

NewStr db 13,10,'$'

Mas dw 6,254,2,134,562,76,83,228,8,255,'$'

NewMas dw 2,34,32,1488,75,8,83,23,18,255,'$'

Arr dw 1 dup('?')

Swap:
        mov bx,20d
@@:
        mov si,[Mas+bx]
        mov dx,[NewMas+bx]
        mov [Mas+bx],dx
        mov [NewMas+bx],si
        sub bx,2
        cmp bx,-2d
        jne @B
ret

; Начальные параметры
; ax - число, занесенное в стек
; bx - деление на 10 позволяет занести цифры в стек отдельно
; cx - число цифр в числе
; si - адрес в памяти
; dx - вывод
Convertion:
        push si
        push ax
        push bx
        push dx
        push cx

        xor si,si
CC0:
        mov ax,[Mas+si]
        call Output

; Modifying si by adding 2 (2 bytes = word)
        add si,2
        cmp si,20d
        jne CC0

; Returning registers
        pop cx
        pop dx
        pop bx
        pop ax
        pop si

ret

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

; Inserting space
        mov ah,02h
        mov dx,' '
        int 21h
ret
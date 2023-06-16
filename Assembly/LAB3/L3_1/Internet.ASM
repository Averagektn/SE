org 100h

; Начальные параметры
; ax - число, занесенное в стек
; bx - деление на 10 позволяет занести цифры в стек отдельно
; cx - число цифр в числе
        xor si,si
C0:
        push [Mas+si]
        pop ax
        mov bx,10
        xor cx,cx
; Цикл 1 - занесение цифр числа на стек
C1:
; dx - остаток от деления
        xor dx,dx
        div bx
        push dx
        inc cx
        test ax,ax
        jnz C1

C2:
        mov bx,cx
        pop [Arr+bx]
        add [Arr+bx],'0'
        mov ah,02h
        mov dx,[Arr+bx]
        int 21h
        loop C2

        mov ah,02h
        mov dx,' '
        int 21h

        inc si
        cmp si,9
        jne C0


        mov ah,08h
        int 21h

ret

Mas dw 10,100,23,43,56,76,83,23,8,3,'$'
Arr dw 16 dup('$')
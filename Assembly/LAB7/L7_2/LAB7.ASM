org 100h
;A^2 and B^3
jmp start
 
mes0   db  13,10,'Formula: A^2 and B^3'
       db  13,10,'---------------------'
mes1   db  13,10,'Type A: $'
mes2   db  13,10,'Type B: $'
mes3   db  13,10,'Result: $'
mes4 db 13,10,'A^2 and B^3 = $'
NewStr db 13,10,'$'
tmp0 dw ?
tmp1 dw ?

start:
    mov   ah,09h          ;
    mov   dx,mes0         ;
    int   21h

    mov   ah,01h            ; ввод с эхом
    int   21h

    and   ax,0fh          ; символ --> цифра
    imul  ax              ; результ в квадрат

    mov [tmp0],ax

    mov   ah,09h          ;
    mov   dx,mes2        ;
    int   21h

    mov   ah,01h            ; ввод с эхом
    int   21h

    and   ax,0fh          ; символ --> цифра
    push  ax              ; запомним
    mov [tmp1],ax

    mov   ah,09h          ;
    mov   dx,mes3         ;
    int   21h             ;

    pop   ax              ;
    imul  [tmp1]              ; результ в квадрат
    imul  [tmp1]
    mov [tmp1],ax

    mov   bx,10           ; вывод на экран в DEC
    call  hex2asc         ;

    mov   ah,09h          ;
    mov   dx,mes3         ;
    int   21h             ;

    mov ax,[tmp0]

    mov   bx,10           ; вывод на экран в DEC
    call  hex2asc         ;

    mov   ah,09h          ;
    mov   dx,mes4         ;
    int   21h             ;

    mov ax,[tmp1]
    mov bx,[tmp0]
    and ax,bx

    mov   bx,10           ; вывод на экран в DEC
    call  hex2asc         ;

    mov ah,08h
    int 21h

ret
 
;нннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннн
hex2asc:                  ; Функция переводит числа в символы
    pusha                 ; Вход:  АХ = число, BX = система счисления
    xor   cx,cx           ; Выход: на экране
isDiv:                    ;
    xor   dx,dx           ;
    div   bx              ;
    push  dx              ;
    inc   cx              ;
    or    ax,ax           ;
    jnz   isDiv           ;
isOut:                    ;
    pop   ax              ;
    cmp   al,9            ;
    jle   noHex           ;
    add   al,7            ;
noHex:                    ;
    add   al,30h          ;
    int   29h             ;
    loop  isOut           ;
    popa                  ;
ret                       ;
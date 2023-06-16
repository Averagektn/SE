org 100h

Start:

        push mes0
        call print_string

        push Input1
        call get_string

        push Input1
        call to_int
        push ax

        push mes2
        call print_string

        push Input2
        call get_string

        push Input2
        call to_int

        push ax

        push mes4
        call print_string

        call Count

Exit:
        mov ax,0c08h
        int 21h
        test al,al
        jnz @f
        mov ah,08h
        int 21h
@@:

ret

mes0   db  13,10,'Formula: A^2 or B^3'
       db  13,10,'---------------------'
mes1   db  13,10,'Type A: $'
mes2   db  13,10,'Type B: $'
mes3   db  13,10,'Result: $'
mes4 db 13,10,'A^2 or B^3 = $'
NewStr db 13,10,'$'
tmp0 dw 2 dup('$')
tmp1 dw 2 dup('$')
Input1 db 4,0,5 dup('$')
Input2 db 4,0,5 dup('$')

hex2asc:
        mov bx,10
        pusha
        xor   cx,cx

isDiv:
         xor   dx,dx
         div   bx
         push  dx
         inc   cx
         or    ax,ax
         jnz   isDiv
isOut:
         pop   ax
         cmp   al,9
         jle   noHex
         add   al,7
noHex:
         add   al,30h
         int   29h
         loop  isOut
         popa
ret

to_int:
        push si
        push dx
        push bp

        mov bp, sp

        mov si, [bp + 8]                        ; initialization
        add si, 2
        xor dx, dx
.creating_num:                                  ; going through string cicle
        xor ax, ax
        lodsb                                   ; get next symbol of string

        cmp al, '$'                             ; if it is '$' go to exit
        je .ext

        cmp al, '9'                             ; if it is more then '9' go to exit
        ja .creating_num
        cmp al, '0'                             ; if it is less then '0' go to exit
        jb .creating_num

        sub ax, '0'                             ; make number from symbol

        shl dx, 1                               ; multiple the whole number on 10 and add symbol
        add ax, dx
        shl dx, 2
        add dx, ax

        jmp .creating_num

.ext:
        mov ax, dx

        mov sp, bp

        pop bp                                       ; repair registers
        pop dx
        pop si
ret 2

print_string:                                   ; procedure of printing string
        push ax                                  ; saving registers
        push dx
        push bp

        mov bp, sp                               ; get pointer to stack

        mov ah, 09h                              ; printing string with 09 DOS function
        mov dx, [bp + 8]
        int 21h

        mov sp, bp
        pop bp
        pop ax                                   ; repairing registers
        pop dx
ret 2

get_string:                                     ; procedure of getting string
        push ax                                 ; saving registers
        push dx
        push si
        push bp

        mov bp, sp

        mov ah, 0Ah                             ; getting string using 0A DOS function
        mov dx, [bp + 10]
        int 21h

        mov sp, bp
        pop bp
        pop si                                  ; repairing registers
        pop dx
        pop ax
ret 2

Count:
        push ax
        push cx

        mov bp,sp

        mov ax,[bp + 8]
        imul ax
        mov bx,ax

        mov ax,[bp + 6]
        mov cx,ax
        imul cx
        imul cx

        or ax,bx

        call  hex2asc

        pop cx
        pop ax
ret 4
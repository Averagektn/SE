       Format MZ                                ; format for exe program

       entry Main:start                         ; set entry point to program

segment Dat
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

segment Main                                    ; segment of main part of program
start:
        mov ax, Dat                              ; setting segment of Data
        mov ds, ax

        mov bp,mes0
        call far Procedures: print_string

        mov bp,Input1
        call far Procedures: get_string
        mov bp, Input1
        call far Procedures: to_int
        mov di,bp

        mov bp,mes2
        call far Procedures: print_string

        mov bp,Input2
        call far Procedures: get_string

        mov bp,Input2
        call far Procedures: to_int
        mov si,bp

        mov bp,mes4
        call far Procedures: print_string

        call far Procedures: Count

Exit:
        mov ax,0c08h
        int 21h
        test al,al
        jnz @f
        mov ah,08h
        int 21h
@@:
        mov ah, 4Ch
        int 21h


segment Procedures
print_string:                                   ; procedure of printing string
        push ax                                  ; saving registers
        push dx
        push di
        push si

        mov ah, 09h                              ; printing string with 09 DOS function
        mov dx, bp
        int 21h

        pop si
        pop di
        pop ax                                   ; repairing registers
        pop dx
retf

get_string:                                     ; procedure of getting string
        push ax                                 ; saving registers
        push dx
        push di
        push si

        mov ah, 0Ah                             ; getting string using 0A DOS function
        mov dx, bp
        int 21h

        pop si                                  ; repairing registers
        pop di
        pop dx
        pop ax
retf

to_int:                                         ; saving registers
        push si
        push dx
        push ax

        add bp, 2                               ; initialization
        mov si, bp
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
        mov bp, dx
                                                ; repair registers
        pop ax
        pop dx
        pop si
retf

Count:
        push cx

        mov ax,di
        imul ax
        mov bx,ax

        mov ax,si
        mov cx,ax
        imul cx
        imul cx

        or ax,bx

        call far Procedures: hex2asc

        pop cx
retf

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
retf
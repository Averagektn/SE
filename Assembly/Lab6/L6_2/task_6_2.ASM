       Format MZ                                ; format for exe program

       entry Main:start                         ; set entry point to program

segment Dat                                     ; segment of varibales and constants
EnterX   db 'Enter X number: $'
EnterY   db 10,13,'Enter Y number: $'
EnterZ   db 10,13,'Enter Z number: $'

NewStr   db 13, 10, '$'

Result    db 10,13,'The result of the equation rol (2*X^2 + Y - 5*Z), X is: $'

                                                ; X, Y and Z variables in string format
Xstr        db 6, 0, 7 dup('$')
Ystr        db 6, 0, 7 dup('$')
Zstr        db 6, 0, 7 dup('$')

Buf      dw ?
EBuf     dd ?

X       dd ?
Y       dd ?
Z       dd ?

segment Main                                    ; segment of main part of program
start:
       mov ax, Dat                              ; setting segment of Data
       mov ds, ax

       mov bp, EnterX                           ; request of X
       mov [Buf], bp
       call far Procedures:print_string

       mov bp, Xstr                                ; get X as a string
       mov [Buf], bp
       call far Procedures:get_string

       mov bp, Xstr                                ; convert X to integer
       mov [Buf], bp
       call far Procedures:to_int
       movzx edi, [Buf]
       mov [X], edi

       mov bp, EnterY                           ; request of Y
       mov [Buf], bp
       call far Procedures:print_string

       mov bp, Ystr                                ; get Y as a string
       mov [Buf], bp
       call far Procedures:get_string

       mov bp, Ystr                                ; convert Y to integer
       mov [Buf], bp
       call far Procedures:to_int
       movzx esi, [Buf]
       mov [Y], esi

       mov bp, EnterZ                           ; request of Z
       mov [Buf], bp
       call far Procedures:print_string

       mov bp, Zstr                                ; get Z as a string
       mov [Buf], bp
       call far Procedures:get_string

       mov bp, Zstr                                ; convert Z to integer
       mov [Buf], bp
       call far Procedures:to_int
       movzx ecx, [Buf]
       mov [Z], ecx

       mov bp, Result                           ; show result message
       mov [Buf], bp
       call far Procedures:print_string

       call far Procedures:calculate

       mov [EBuf], eax                          ; print result
       call far Procedures:print_num

exit:
       mov ax, 080Ch                            ; wait for pressing a button
       int 21h
       test al, al
       jnz @F

       mov ah, 08h
       int 21h
@@:                                             ; return control to operating system
       mov ah, 4Ch
       int 21h

segment Procedures                               ; segment of subprogrmas
print_string:                                    ; procedure of printing string
       push ax                                   ; saving registers
       push dx

       mov ah, 09h                               ; printing string with 09 DOS function
       mov dx, [Buf]
       int 21h

       pop ax                                    ; repairing registers
       pop dx
       retf

get_string:                                      ; procedure of getting string
        push ax                                  ; saving registers
        push dx
        push si

        mov ah, 0Ah                              ; getting string using 0A DOS function
        mov dx, [Buf]
        int 21h

        pop si                                   ; repairing registers
        pop dx
        pop ax
        retf

to_int:                                          ; procedure of ñonverting string to integer
        push si                                  ; saving registers
        push dx
        push ax

        add bp, 2                                ; initialization
        mov si, [Buf]
        xor dx, dx
.creating_num:                                   ; going through string cicle
        xor ax, ax
        lodsb                                    ; get next symbol of string

        cmp al, '$'                              ; if it is '$' go to exit
        je .ext

        cmp al, '9'                              ; if it is more then '9' go to exit
        ja .creating_num
        cmp al, '0'                              ; if it is less then '0' go to exit
        jb .creating_num

        sub ax, '0'                              ; make number from symbol

        shl dx, 1                                ; multiple the whole number on 10 and add symbol
        add ax, dx
        shl dx, 2
        add dx, ax

        jmp .creating_num

.ext:
        mov [Buf], dx

        pop ax                                   ; repair registers
        pop dx
        pop si
        retf


print_num:                                       ; procedure of printing a number like a number
        push eax                                 ; save registers
        push edx
        push ecx
        push si

        mov eax, [EBuf]                          ; get number from parametrs

        mov ecx, 10                              ; initialize registers
        xor si, si
        xor edx, edx
.get_digits:                                     ; cicle of getting digits from number
        div ecx                                  ; get digit of a number divising by 10
        push dx                                  ; save digit to stack
        inc si                                   ; increase amount of digits

        xor edx, edx

        cmp eax, 0                               ; if the result of division is 0 exit from cicle
        jne .get_digits

        mov cx, si                               ; set cicle counter
.print_digits:                                   ; cicle of printing digits
        pop dx                                   ; get digit from stack
        add dl, '0'                              ; translate digit to symbol

        mov ah, 02h                              ; print symbol using 02 DOS function
        int 21h

        loop .print_digits

        pop si                                   ; repair registers
        pop ecx
        pop edx
        pop eax
        retf

calculate:
        push ebx

        mov edi, [X]
        mov esi, [Y]
        mov ecx, [Z]

        mov ax, di
                                                ; get square of X
        imul edi, edi                            ; calculate 2*X^2 + Y
        lea ebx, [edi*2 + esi]                   ; calculate 5*Z
        imul ecx, 5                              ; calculate 2*X^2 + Y - 5*Z
        sub ebx, ecx

        mov cl, 32
        div cl                                   ; get remainder of division of X on 32
        mov cl, ah
        rol ebx, cl                              ; cicle rotate left

        mov eax, ebx

        pop ebx

        retf
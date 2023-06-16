       Format MZ                                ; format for exe program

       entry Main:start                         ; set entry point to program

segment Dat                                     ; segment of varibales and constants
EnterX   db 'Enter X number: $'
EnterY   db 10,13,'Enter Y number: $'
EnterZ   db 10,13,'Enter Z number: $'

NewStr   db 13, 10, '$'

Result    db 10,13,'The result of the equation rol (2*X^2 + Y - 5*Z), X is: $'

                                                ; X, Y and Z variables in string format
X        db 6, 0, 7 dup('$')
Y        db 6, 0, 7 dup('$')
Z        db 6, 0, 7 dup('$')

segment Main                                    ; segment of main part of program
start:
       mov ax, Dat                              ; setting segment of Data
       mov ds, ax

       mov bp, EnterX
       call far Procedures:print_string         ; request of X

       mov bp, X
       call far Procedures:get_string           ; get X as a string
       mov bp, X
       call far Procedures:to_int               ; convert X to integer
       movzx edi, bp

       mov bp, EnterY
       call far Procedures:print_string         ; request of Y

       mov bp, Y
       call far Procedures:get_string           ; get Y as a string
       mov bp, Y
       call Procedures:to_int                   ; convert Y to integer
       movzx esi, bp

       mov bp, EnterZ
       call far Procedures:print_string         ; request of Z

       mov bp, Z
       call far Procedures:get_string           ; get Z as a string
       mov bp, Z
       call far Procedures:to_int               ; convert Z to integer
       movzx ecx, bp

       mov bp, Result
       call far Procedures:print_string         ; show result message

       call far Procedures:calculate

       mov ebp, eax
       call far Procedures:print_num            ; print result

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

segment Procedures                              ; segment of subprogrmas
print_string:                                   ; procedure of printing string
       push ax                                  ; saving registers
       push dx
                                                ; printing string with 09 DOS function
       mov ah, 09h
       mov dx, bp
       int 21h

       pop ax                                   ; repairing registers
       pop dx
       retf

get_string:                                     ; procedure of getting string
        push ax                                 ; saving registers
        push dx
        push si

        mov ah, 0Ah                             ; getting string using 0A DOS function
        mov dx, bp
        int 21h

        pop si                                  ; repairing registers
        pop dx
        pop ax
        retf
                                                ; procedure of ñonverting string to integer
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


print_num:                                      ; procedure of printing a number like a number
        push eax                                ; save registers
        push edx
        push ecx
        push si

        mov eax, ebp                            ; get number from parametrs

        mov ecx, 10                             ; initialize registers
        xor si, si
        xor edx, edx
.get_digits:                                    ; cicle of getting digits from number
        div ecx                                 ; get digit of a number divising by 10
        push dx                                 ; save digit to stack
        inc si                                  ; increase amount of digits

        xor edx, edx

        cmp eax, 0                              ; if the result of division is 0 exit from cicle
        jne .get_digits

        mov cx, si                              ; set cicle counter
.print_digits:                                  ; cicle of printing digits
        pop dx                                  ; get digit from stack
        add dl, '0'                             ; translate digit to symbol

        mov ah, 02h                             ; print symbol using 02 DOS function
        int 21h

        loop .print_digits

        pop si                                  ; repair registers
        pop ecx
        pop edx
        pop eax
        retf

calculate:
        push ebx

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

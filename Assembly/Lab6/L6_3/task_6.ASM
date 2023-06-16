       org 100h
start:
       push EnterX
       call print_string         ; request of X

       push X
       call get_string           ; get X as a string
       push X
       call to_int               ; convert X to integer
       movzx edi, ax

       push EnterY
       call print_string         ; request of Y

       push Y
       call get_string           ; get Y as a string
       push Y
       call to_int                   ; convert Y to integer
       movzx esi, ax

       push EnterZ
       call print_string         ; request of Z

       push Z
       call get_string           ; get Z as a string
       push Z
       call to_int               ; convert Z to integer
       movzx ecx, ax

       push Result
       call print_string         ; show result message

       push edi
       push esi
       push ecx
       call calculate

       push eax
       call print_num                           ; print result

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

;-------------------------Subprogrmas Section-----------------------------

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
                                                ; procedure of ñonverting string to integer
to_int:                                         ; saving registers
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


print_num:                                      ; procedure of printing a number like a number
        push eax                                ; save registers
        push edx
        push ecx
        push si
        push bp

        mov bp, sp

        mov eax, [bp + 20]                      ; get number from parametrs
        shl eax, 16
        mov eax, [bp + 18]

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

        mov sp, bp

        pop bp
        pop si                                  ; repair registers
        pop ecx
        pop edx
        pop eax
        ret 4


calculate:
        push edi
        push esi
        push ebx
        push ecx
        push bp

        mov bp, sp

        mov edi, [bp + 30]
        shl edi, 16
        mov edi, [bp + 28]
        mov esi, [bp + 26]
        shl esi, 16
        mov esi, [bp + 24]
        mov ecx, [bp + 22]
        shl ecx, 16
        mov ecx, [bp + 20]

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

        mov sp, bp

        pop bp
        pop ecx
        pop ebx
        pop esi
        pop edi

        ret 12

;---------------------Data section----------------------------------

EnterX   db 'Enter X number: $'
EnterY   db 10,13,'Enter Y number: $'
EnterZ   db 10,13,'Enter Z number: $'

NewStr   db 13, 10, '$'

Result    db 10,13,'The result of the equation rol (2*X^2 + Y - 5*Z), X is: $'

                                                ; X, Y and Z variables in string format
X        db 6, 0, 7 dup('$')
Y        db 6, 0, 7 dup('$')
Z        db 6, 0, 7 dup('$')

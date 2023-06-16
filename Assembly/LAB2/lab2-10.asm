        org 100h
start:
        mov ah, 09h             ;Output strStart
        mov dx, strStart
        int 21h

        mov ah, 0ah             ;Input string
        mov dx, strInp
        int 21h

        mov dh, 3               ;Set bound of string
        mov al, byte [strInp+1]
        cmp al, dh              ;Compare with length
        jl Error

        mov al, [strInp+3] ;Check if strInp[1] == strInp[4]
        cmp al, [strInp+4]
        jne Error

        mov dh, 'A'             ;Check if strInp[2] is digit
        mov dl, 'Z'
        mov al, [strInp+5]
        cmp al, dh
        jl Error
        cmp al, dl
        ja Error

        mov bh, 0
        mov bl, [strInp+1]      ;Check if strInp[L-1] is digit
        mov al, [strInp+bx+1]
        cmp al, dh
        jl Error
        cmp al, dl
        ja Error

        mov ah, 09h             ;Output if line is valid
        mov dx, strFinish
        int 21h
        jmp Exit

Error:
        mov ah,09h
        mov dx,MessageNo
        int 21h

Exit:

        mov ax, 0c08h
        int 21h
        test al, al
        jnz @F
        mov ah, 08h
        int 21h
@@:
        ret


strStart:
        db 'Enter string in range 3 < Length <= 10:',10,13,'$'
strFinish:
        db 10, 13, 'Yes$'
strInp db 11, 0, 12 dup ($')
MessageNo db 10,13, 'No$'




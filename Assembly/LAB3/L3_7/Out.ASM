org 100h

; Messages
        mov ah,09h
        mov dx,Mes1
        int 21h
        mov dx,NewStr
        int 21h

; Out Array
        call Convertion

        mov dx,NewStr
        int 21h

; Prepareings
        mov bx,20d
        mov si,16d
        mov di,16d

; Searching
; bx - counter
; si,di - pointers on the min max elements
Find:
        sub bx,2
        mov ax,[Mas+bx]
        cmp ax,[Mas+si]
        ja More
        cmp ax,[Mas+di]
        jb Less
        jmp Iteration
More:
        mov si,bx
        jmp Iteration
Less:
        mov di,bx
Iteration:

        cmp bx,0
        jne Find

        mov [Mas+si],0
        mov [Mas+di],0

        mov ah,09h
        mov dx,NewStr
        int 21h
        mov dx,Mes2
        int 21h
        mov dx,NewStr
        int 21h

        Call Convertion

        mov ax,0c08h
        int 21h
        test al,al
        jnz @f
        mov ah,08h
        int 21h
@@:
        ret

Mes1 db 'Original array:$'

Mes2 db 'New array:$'

NewStr db 13,10,'$'

Mas dw 6,254,2,134,56,76,83,23,8,255,'$'

Arr dw 16 dup('1'),'$'

; ��������� ���������
; ax - �����, ���������� � ����
; bx - ������� �� 10 ��������� ������� ����� � ���� ��������
; cx - ����� ���� � �����
; si - ����� � ������
; dx - �����
Convertion:
        push si
        push ax
        push bx
        push dx
        push cx
        xor si,si
C0:
        mov ax,[Mas+si]
        mov bx,10
        xor cx,cx

; ���� 1 - ��������� ���� ����� �� ����
; dx - ������� �� �������
; cx - ����� �����
; ax - ��������� �������
C1:
        xor dx,dx
        div bx
        push dx
        inc cx
        test ax,ax
        jnz C1

; Cycle 3 - output
; [Arr] - bufer
C2:
        pop [Arr]
        add [Arr],'0'
        mov ah,02h
        mov dx,[Arr]
        int 21h
        loop C2

; Inserting space
        mov ah,02h
        mov dx,' '
        int 21h

; Modifying si by adding 2 (2 bytes = word)
        add si,2
        cmp si,20d
        jne C0

; Returning registers
        pop cx
        pop dx
        pop bx
        pop ax
        pop si

ret
org 100h

; ��������� ���������
; ax - �����, ���������� � ����
; bx - ������� �� 10 ��������� ������� ����� � ���� ��������
; cx - ����� ���� � �����
        xor si,si
C0:
        push [Mas+si]
        pop ax
        mov bx,10
        xor cx,cx
; ���� 1 - ��������� ���� ����� �� ����
C1:
; dx - ������� �� �������
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
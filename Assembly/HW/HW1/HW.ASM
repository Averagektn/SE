org 100h

start:

mov ah,$09
mov dx,strHello
int 21h

mov ah,$08
int 21h
ret

strHello db "Hello,World!$"
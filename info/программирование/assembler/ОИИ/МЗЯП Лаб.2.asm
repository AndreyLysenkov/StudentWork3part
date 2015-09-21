.model small
.stack 100th
.data
message db 'Hello, World!', '$'
perem 1 db 0ffh
perem 2 dw 3a7fh
perem 3 dd 0f54d567ah
mas db 10 dup (' ')
pole_1 db 5 dup (?)
adr dw perem_3
adr_full dd perem_3
numbers db 'End $'
.code
start
mov ax,@data
mov ds,ax
mov ah,09h
mov dx,offset message
int 21h
mov ah,7h
int 21h
mov ax,4c00h
int 21h
end start 
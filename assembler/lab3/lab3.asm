.model small
.stack 100h
.data
	message1 db 'Hard is the full step', '$'
	message2 db 'Varro, Mark Terence', '$'
	message3 db '116-27 years. BC', '$'
	myname db 'Lysenkov', '$'
	mygroup db 'IT-31', '$'
	myfaculty db 'FNC', '$'
.code
start:
    mov ax, @data
    mov ds, ax
    mov ax, 0600h
    mov bh, 4eh
    mov cx, 0000
    mov dx, 184fh
    int 10h       ;Конец очистки экрана
    mov ah, 02h
    mov dh, 10   ;номер строки
    mov dl, 25  ;номер столбца
    mov bh, 0
    int 10h
    mov ah, 09h
    mov dx, offset message1
    int 21h     ;вывод сообщения
    mov ah, 02h
    mov dh, 11
    mov dl, 25
    mov bh, 0
    int 10h
    mov ah, 09h
    mov dx, offset message2
    int 21h
    mov ah, 02h
    mov dh, 12
    mov dl, 25
    mov bh, 0
    int 10h
    mov ah, 09h
    mov dx, offset message3
    int 21h
    mov ah, 02h
    mov dh, 0
    mov dl, 0
    mov bh, 0
    int 10h
    mov ah, 09h
    mov dx, offset myname
    int 21h
    mov ah, 02h
    mov dh, 0
    mov dl, 74
    mov bh, 0
    int 10h
    mov ah, 09h
    mov dx, offset mygroup
    int 21h
    mov ah, 02h
    mov dh, 24
    mov dl, 0
    mov bh, 0
    int 10h
    mov ah, 09h
    mov dx, offset myfaculty
	int 21h
	mov ah, 02h
	mov dh, 24
	mov dl, 73
	mov bh, 0
	int 10h
	mov ah, 09h
	mov al, '!'
	mov bl, 10001100b
	mov cx, 5
	int 10h
	mov ah, 7h 
	int 21h
	mov ax, 4c00h 
	int 21h
end start
.model small
.stack 100h
.data
	a dw 0h
	b dw 0h
	x dw 0h
	Aout db 'Enter a = $'
	Bout db 'Enter b = ', '$'
	Xout db 'Answer x =', '$'

.code

mPush macro
	push ax
	push bx
	push cx
	push dx
endm

mPop macro
	pop dx
	pop cx
	pop bx
	pop ax
endm

mClrScr macro
	;; Очистка экрана
	mPush
	mov ax, 0600h
	mov bh, 4eh
	mov cx, 0000
	mov dx, 184fh
	int 10h
	mPop
endm

mPrntStr macro string
	;; Вывод строки на экран
	mPush
	mov ah, 09h
	mov dx, offset string
	int 21h
	mPop
endm


mPrntNumb macro 
local positive, findDigit, getDgt, prntDgt
	test ax, ax
	jns positive
	mPrntStr '-', '$'
	neg ax
positive:
	xor cx, cx 
	mov bx, 0Ah
findDigit:
	xor dx,dx 
	div bx
	push dx
	inc cx
	test ax,ax
	jnz findDigit
	mov ah,02h 
getDgt:
	pop dx
	cmp dl, 9d
	jbe mac4
	add dl,7d
prntDgt:
	add dl,'0'
	int 21h 
	loop mac3 
endm 

mSetPoint macro row: REQ, column: REQ
	;; Установка курсора
	mPush
	mov bx, 0
	mov ah, 2
	mov dh, row
	mov dl, column
	int 10h
	mPop
endm

start:
mov ax,@data
mov ds,ax
mClrScr
mSetPoint 10, 10
mPrntStr Aout
mov ax, -5d
mPrntNumb
jmp exit


exit:
mov ax,4C00h
int 21h
end start
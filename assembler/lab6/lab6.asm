.model small
.stack 100h
.data
	a dw 0h
	b dw 0h
	x dw 0h
	Aout db 'Enter a = $'
	Bout db 'Enter b = ', '$'
	Xout db 'Answer x =', '$'
	minus db '-$'
	errorNmb db 'Number incorrect'
	buffer  db 6,7 dup (?)
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

mReadNumb macro value, buffer
	;; Чтение числа
local positive, positive2, ext, wrong, getDgt
	mov ah, 0Ah
	xor di, di
	mov dx, offset buffer
	int 21h
	mov dl, 0Ah
	mov ah, 02h
	int 21h
	mov si, offset buff+2
	cmp byte ptr [si], "-"
	jnz positive
	mov di, 1
	inc si
positive:
	xor ax, ax
	mov bx, 0Ah
getDgt:
	mov cl, byte ptr[si]
	cmp cl, 0Dh
	jz ext
	cmp cl, '0'
	jl wrong
	cmp cl, '9'
	jg wrong
	sub cl, '0'
	mul bx
	add ax, cx
	inc si
	jmp getDgt	
wrong:
	mPrntStr errorNmb
ext:
	cmp di, 1
	jnz positive2
	neg ax
positive2:
	mov value, ax
endm

mPrntNumb macro value
	;; Печать числа
local positive, findDigit, gtDgt, prntDgt
	mov ax, value
	test ax, ax
	jns positive
	mPrntStr minus
	neg ax
positive:
	xor cx, cx 
	mov bx, 0Ah
findDigit:
	xor dx, dx 
	div bx
	push dx
	inc cx
	test ax, ax
	jnz findDigit
	mov ah, 02h 
gtDgt:
	pop dx
	cmp dl, 9d
	jbe prntDgt
	add dl,7d
prntDgt:
	add dl, '0'
	int 21h 
	loop gtDgt
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
	xor ax, ax
	xor dx, dx
	mClrScr
	mSetPoint 5, 3
	mPrntStr Aout
	mReadNumb a, buffer
	mSetPoint 6, 3
	mReadNumb b, buffer
	mov ax,a
	cmp ax,b
	je equal
	jl less
	jg more
equal:
	xor ax, ax
	jmp result
less:
	xor ax, ax
	jmp result
more:
	xor ax, ax
	jmp result

result:
	;; Вывод результата
	xor ax, ax
	mSetPoint 7, 3
	mPrntStr Xout
	mPrntNumb x
	xor ax, ax
	mov ah, 7h
	int 21h
	jmp exit
exit:
	;; выход из программы
	mov ax,4C00h
	int 21h
end start
.model small
.stack 100h
.data
	strTypeN db 'Type n: $'
	strTypeD db 'Type d: $'
	strTypeArr db 'Type array: $'
	color db 1eh
	arr dw 10 dup(?)
	n db 0d
	d db 0d
	count db 0d
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
	mPush
	mov ax, 0600h
	mov bh, color
	mov cx, 0000h
	mov dx, 184Fh
	int 10h
	mPop
endm

mSetPoint macro row: REQ, column: REQ
	mPush
	mov ah, 02h
	mov dh, row
	mov dl, column
	mov bx, 0
	int 10h
	mPop
endm

mPrintStr macro string
	mPush
	mov ah, 09h
	mov dx, offset string
	int 21h
	mPop
endm

mPrintNumb macro value
	mov eax, value
	
endm

mPrntNumb macro value
local positive3, findDigit, gtDgt, prntDgt
	;; Печать числа
	mov ax, value
	test ax, ax
	jns positive3
	mPrntStr minus
	neg ax
positive3:
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

start:
	
	
end start
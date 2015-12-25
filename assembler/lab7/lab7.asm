.model small
.stack 100h
.data
	strTypeN db 'Type n: $'
	strTypeD db 'Type d: $'
	strTypeArr db 'Type array: $'
	strError db 'Error :($'
	minus db '-$'
	color db 3ah
	base dw 10d
	arr dw 10 dup (?)
	n dw 0d
	d dw 0d
	tmpB db 0d
	tmpW dw 0d
	count db 0d
	buffer db 10 dup (?)
.code

mPush macro
	push ax
	push bx
	push cx
	push dx
	push si
endm

mPop macro
	pop si
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

mBr macro
	mPush
	mov ah, 02h
	mov dl, 0Ah
	int 21h
	mPop
endm

mPrintStr macro string
	mPush
	mov ah, 09h
	mov dx, offset string
	int 21h
	mPop
endm

mPrintDigit macro value
	mPush
	mov ah, 02h
	mov dl, byte ptr [value]
	add dl, '0'
	int 21h
	mPop
endm

mPrintNumb macro value
local positive, nextDigit, printDigit, printD, exitMc
	mov ax, value
	cmp ax, 0
	jg positive
	mPrintStr minus
	neg ax
positive:
	xor cx, cx
	mov bx, base
nextDigit:
	xor dx, dx
	div bx
	push dx
	inc cx
	cmp ax, 0
	jnz nextDigit
	mov ah, 02h
printDigit:
	pop dx
	cmp dx, base
	jl printD
	jmp exitMc
printD:
	add dl, '0'
	int 21h
	loop printDigit
exitMc:
	xor dx, dx
endm

mPrintTest macro
	mov si, offset buffer+1
m1:
	inc si
	cmp byte ptr [si], '0'
	jl exit0
	cmp byte ptr [si], '9'
	jg exit0
	mov ah, 02h
	mov dl, byte ptr [si]
	int 21h
	jmp m1
exit0:
	xor ax, ax
endm

mReadNumb macro value
local nextDigit, exit0, exit1
	mov ah, 0Ah
	xor bx, bx
	xor dx, dx
	mov dx, offset buffer
	int 21h
	mov bx, 10d
	mov value, 0d
	mov si, offset buffer+2
	cmp byte ptr [si], '-'
	jnz nextDigit
	mov tmpB, 1
	inc si
nextDigit:
	xor cx, cx
	cmp byte ptr [si], '0'
	jl exit0
	cmp byte ptr [si], '9'
	jg exit0
	mov cl, byte ptr [si]
	sub cl, '0'
	mov ax, value
	mul bx
	add ax, cx
	mov value, ax
	inc si
	jmp m1
exit0:
	cmp tmpB, 0
	jz exit1
	neg value
exit1:
	xor ax, ax
endm


start:
	mov ax, @data
	mov ds, ax
	mClrScr
	mPrintStr strTypeN
	mPrintNumb -1005d
	mBr
	mReadNumb n
	mBr
	mPrintNumb n
	;mSetPoint 3, 0
	;mPrintNumb -13d
	;mSetPoint 6, 0

exit:
	mov ah,7h
	int 12h
	mov ax,4C00h
	int 21h
end start
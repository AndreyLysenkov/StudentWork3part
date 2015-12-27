.model small
.stack 100h
.data
	strTypeN db 'Type n: $'
	strTypeD db 'Type d: $'
	strTypeC db 'Type c: $'
	strTypeArr db 'Type array: $'
	strAnswer db 'Answer: $'
	strTypeElement db ' >  $'
	minus db '-$'
	color db 30h
	base dw 10d
	arr dw 10 dup (?)
	n dw 0d
	d dw 0d
	cnumb dw 0d
	tmpB db 0d
	tmpW dw 0d
	count dw 0d
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
	xor bh, bh
	mov ax, 0600h
	mov bh, color
	mov cx, 0000h
	mov dx, 184Fh
	int 10h
	mPop
endm

mSetPoint macro row: REQ, column: REQ
	push ax
	push bx
	push dx
	mov ax, 0200h
	mov dh, row
	mov dl, column
	mov bx, 0
	int 10h
	pop dx
	pop bx
	pop ax
endm

mBr macro
	push ax
	push dx
	mov ax, 0200h
	mov dx, 000Ah
	int 21h
	pop dx
	pop ax
endm

mPrintStr macro string
	push ax
	push dx
	mov ax, 0900h
	mov dx, offset string
	int 21h
	pop dx
	pop ax
endm

mPrintDigit macro value
	push ax
	push dx
	xor dx, dx
	mov ax, 0200h
	mov dl, byte ptr [value]
	add dl, '0'
	int 21h
	pop dx
	pop ax
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

mReadNumb macro value
local nextDigit, exit0, exit1
	mPush
	xor ax, ax
	xor bx, bx
	mov value, bx
	xor dx, dx
	mov ah, 0Ah
	mov dx, offset buffer
	int 21h
	mov bx, 10d
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
	jmp nextDigit
exit0:
	cmp tmpB, 0
	je exit1
	mov ax, value
	neg ax
	mov value, ax
exit1:
	mPop
endm


start:
	mov ax, @data
	mov ds, ax
	mClrScr
	mSetPoint 5, 5
	mPrintStr strTypeN
	mReadNumb n
	mSetPoint 6, 5
	mPrintStr strTypeD
	mReadNumb d
	mSetPoint 7, 5
	mPrintStr strTypeC
	mReadNumb cnumb
	mSetPoint 8, 5
	mPrintStr strTypeArr
	mBr
	xor cx, cx
	mov cx, n
	xor si, si
	xor bx, bx
	mov bx, offset arr
	;lea bx, arr
nextElement:
	mPrintStr strTypeElement
	mReadNumb [bx][si]
	mBR
	inc si
	inc si
loop nextElement
	mov cx, 2d
	mov ax, n
	mul cx
	mov cx, ax
next:
	mov ax, [bx][si]
	sub ax, cnumb
	sub ax, d
	cmp ax, 0d
	jl skp
	add count, 1d
skp:
	inc si
	inc si
loop next
	mPrintStr strAnswer
	mPrintNumb count
	mov ax, 0700h
	int 12h
	mov ax, 4C00h
	int 21h
end start
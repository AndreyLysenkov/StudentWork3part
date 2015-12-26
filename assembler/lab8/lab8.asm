MASM
.model small
.stack 100h
.data
	minus db '-$'
	value dw 0d
	buffer db 27, 1 dup (64)
	tmpB db 0d
	tmpW db 0d
	n db 0d
	m db 0d
.code

mData macro
	push ax
	mov ax,@data
	mov ds,ax
	pop ax
endm

mPush macro
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
endm

mClear macro
	xor bx, bx
	xor cx, cx
	xor dx, dx
endm

mSetPoint macro row: REQ, column: REQ
	push ax
	push dx
	push bx
	mov ax, 0200h
	mov dh, row
	mov dl, column
	mov bx, 0
	int 10h
	pop bx
	pop dx
	pop ax
endm

mBr macro
	push ax
	push dx
	xor dx, dx
	mov ax, 0200h
	mov dl, 000Ah
	int 21h
	pop dx
	pop ax
endm

mGetIndex macro i: REQ, j: REQ, sz: REQ
	;NB: sz = 1byte
	mPush
	mov ax, i
	mul sz
	add j
	mPop
endm

mGetIndexes macro n: REQ, sz: REQ
	mPush
	mov ax, n
	div sz
	
	mPop
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

mPrintDigit macro x
	push ax
	push dx
	xor dx, dx
	mov ax, 0200h
	mov dl, x
	add dl, '0'
	int 21h
	pop dx
	pop ax
endm

mGetValueStack macro
	push bx
	push ax
	pop bx
endm

pReadNumb proc near
	mPush
	mData
	mClear
	xor ax, ax
	mov ax, 0A00h
	lea dx, buffer
	int 21h
	xor dx, dx
	xor ax, ax
	mov si, offset buffer+2
	cmp byte ptr [si], '-'
	jnz nextDigit
	mov cx, 1
	inc si
nextDigit:
	cmp byte ptr [si], '0'
	jl notNumb
	cmp byte ptr [si], '9'
	jg notNumb
	xor bx, bx
	mov bh, byte ptr [si]
	sub bh, '0'
	mov bl, 10d
	mul bl
	add ax, bx
	inc si
jmp nextDigit
notNumb:
	cmp cx, 0
	jz positive
	neg ax
positive:
	mPop
	ret 0
pReadNumb endp

pPrintNumb proc near
	mGetValueStack
	mPush
	mData
	mClear
	mov bx, 10d
	cmp ax, 0d
	jge nextDigit2
	mPrintStr minus
	neg ax
nextDigit2:
	xor dx, dx
	div bx
	push dx
	inc cx
	cmp ax, 0d
jg nextDigit2
	xor ax, ax
	mov ax, 0200h
printDigit:
	pop dx
	add dl, '0'
	int 21h
loop printDigit
	mPop
	ret 0
pPrintNumb endp

main proc near
	mData
	call pReadNumb
	mBr
	call pPrintNumb
	mov ax, 0700h
	int 12h	
	mov ax, 4C00h
	int 21h
main endp



start:
	call main
end start
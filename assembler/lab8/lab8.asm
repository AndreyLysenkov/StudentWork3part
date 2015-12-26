.model small
.stack 100h
.data
	color db 30h
	minus db '-$'
	value dw 0d
	base dw 10d
	buffer db 27 dup (?)
	tmpB db 0d
	tmpW db 0d
.code

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
	xor ax, ax
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

pClrScr proc near
	mPush
	mov ax, 0600h
	mov bh, color
	mov cx, 0000h
	mov dx, 184Fh
	int 10h
	mPop
	ret 0
pClrScr endp

pReadNumb proc near
	mGetValueStack
	
	ret 0
pReadNumb endp


start:
	mov ax,@data
	mov ds,ax
	call pClrScr
	mov ax, 5d
	push ax
	call pReadNumb
	
	mov ax, 4C00h
	int 21h
end start
.model small
.stack 100h
assume cs: code, ds: data
data segment
	minus db '-$'
	color db 3Eh ;38h
	string db 127,127 dup ('$')
	string2 db 127,127 dup ('$')
	buffer db 127,127 dup ('$')
	tmp db 0d
	bool db 0d
	bool2 db 0d
	lenght0 db 0d
	counter db 0d
	counter2 db 0d
	value dw 0d
	menu1StringEnter db '  1 > Enter String $'
	menu2StringPrint db '   2 > Print String $'
	menu3TaskA db '   3 > Task A$'
	menu4TaskB db '   4 > Task B$'
	menu5TaskC db '   5 > Task C$'
	menu0Exit db ' 0 > Exit$'
	msgInput db '     > $'
	msgNext db ' --- Press <Enter> ---$'
data ends

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

mData macro
	push ax
	mov ax, data
	mov ds, ax
	mov es, ax 
	pop ax
endm

mClear macro
	xor bx, bx
	xor cx, cx
	xor dx, dx
	xor di, di
endm

mClrScr macro
	push ax
	push bx
	push dx
	xor bx, bx
	mov ax, 0600h
	mov bh, color
	mov cx, 0000h
	mov dx, 184Fh
	int 10h
	pop dx
	pop bx
	pop ax
endm

mBr macro
	push ax
	push dx
	xor dx, dx
	mov ax, 0200h
	mov dl, 0Ah
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

mReadln macro
	push ax
	push dx
	mov ax, 0A00h
	lea dx, buffer
	int 21h
	pop dx
	pop ax
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

mCopy macro startChar: REQ, endChar: REQ
	push cx
	push si
	push di
	mov cx, endChar
	sub cx, startChar
	inc cx
	cld
rep movsb
	add si, cx
	pop di
	pop si
	pop cx
endm

mRead macro
	push ax
	push dx
	mov ax, 0A00h
	lea dx, buffer
	int 21h
	pop dx
	pop ax
endm

code segment





main proc near
	mData
menu:
	mClrScr
	mSetPoint 3d, 1d
	mPrintStr menu1StringEnter
	mBr
	mPrintStr menu2StringPrint
	mBr
	mPrintStr menu3TaskA
	mBr
	mPrintStr menu4TaskB
	mBr
	mPrintStr menu5TaskC
	mBr
	mPrintStr menu0Exit
	mBr
	mPrintStr msgInput
	xor ax, ax
	call pReadNumb
	cmp al, 0d
	je term0
	cmp al, 1d
	je term1
	cmp al, 2d
	je term2
	cmp al, 3d
	je term3
	cmp al, 4d
	je term4
	cmp al, 5d
	je term5
jmp menu
term1:
	mBr
	mov ax, offset string
	call pReadString
	mov lenght0, al
jmp menu
term2:
	call pMenuPrintString
jmp menu
term3:
	call pTask1
jmp menu
term4:
	call pTask2
jmp menu
term5:
	mBr
	call pTask3
jmp menu
term0:
	mov ax, 0700h
	int 12h
	mov ax, 4C00h
	int 21h
main endp

start:
	call main
code ends
end start
.model small
.stack 100h
assume cs: code, ds: data
data segment
	color db 3Eh ;38h
	string db 127 dup ('$')
	buffer db 127 dup ('$')
	reader db 7,1 dup (?)
	menu1StringEnter db '  1 > Enter String $'
	menu2StringPrint db '  2 > Print String $'
	menu3StringSearch db '  3 > Search String $'
	menu4TaskA db '   4 > Task A$'
	menu5TaskB db '   5 > Task B$'
	menu6TaskC db '   6 > Task C$'
	menu0Exit db '  0 > Exit$'
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
	mov ax, @data
	mov ds, ax
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

code segment

pReadNumb proc near
	mPush
	mData
	mClear
	mov ax, 0A00h
	lea dx, buffer
	int 21h
	xor dx, dx
	xor ax, ax
	mov si, offset buffer+2
	cmp byte ptr [si], '-'
	jnz nextDigit
	mov cl, 1d
	inc si
nextDigit:
	cmp byte ptr [si], '0'
	jl notNumb
	cmp byte ptr [si], '9'
	jg notNumb
	mov bx, 10d
	mul bx
	xor bx, bx
	mov bl, byte ptr [si]
	sub bl, '0'
	add ax, bx
	inc si
jmp nextDigit
notNumb:
	cmp cl, 0d
	je positive
	neg ax
positive:
	mPop
	ret 0
pReadNumb endp

main proc near
	mData
menu:
	mClrScr
	mSetPoint 3d, 1d
	mPrintStr menu1StringEnter
	mBr
	mPrintStr menu2StringPrint
	mBr
	mPrintStr menu3StringSearch
	mBr
	mPrintStr menu4TaskA
	mBr
	mPrintStr menu5TaskB
	mBr
	mPrintStr menu6TaskC
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
	cmp al, 6d
	je term6
jmp menu
term1:
	
jmp menu
term2:
	
jmp menu
term3:
	
jmp menu
term4:
	
jmp menu
term5:
	
jmp menu
term6:
	
jmp menu
term0:
	mov ax, 0700h
	int 12h
	mov ax, 4C00h
	int 21h
main endp

.start
	call main
end start
code ends
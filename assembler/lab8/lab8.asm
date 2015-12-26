MASM
.model small
.stack 100h
.data
	color db 3Eh ;38h
	minus db '-$'
	value dw 0d
	buffer db 27, 1 dup (64)
	menu1MatrixEnter db '   1> Enter Matrix$'
	menu2MatrixPrint db '   2> Print Matrix$'
	menu3TaskA db '   3> TaskA$'
	menu4TaskB db '   4> TaskB$'
	menu5TaskC db '   5> TaskC$'
	menu0Exit db ' 0> Exit$'
	msgMatrixSize db '   Type matrix size: $'
	msgMatrixSizeRow db ' row> $'
	msgMatrixSizeCol db ' col> $'
	msgMatrixElement db '    > $'
	msgNext db ' --- Press <Enter> ---$'
	tmpB db 0d
	tmpW db 0d
	n db 0d
	m db 0d
	matrix db 10, 10 dup(?)
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
	push si
	push di
	mov ax, 0200h
	mov dh, row
	mov dl, column
	mov bx, 0
	int 10h
	pop di
	pop si
	pop bx
	pop dx
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

mClrScr macro
	mPush
	mov ax, 0600h
	mov bh, color
	mov cx, 0000h
	mov dx, 184Fh
	int 10h
	mPop
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

pPrintNumb proc near
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

pEnterMatrix proc near
	mPush
	mData
	mClear
	mClrScr
menuSize:
	mPrintStr msgMatrixSize
	mBr
	mPrintStr msgMatrixSizeRow
	call pReadNumb
	mov n, al
	mBr
	mPrintStr msgMatrixSizeCol
	call pReadNumb
	mov m, al
	mBr
	mov al, n
	mov ah, m
	cmp al, 1d
jl menuSize
	cmp al, 10d
jg menuSize
	cmp ah, 1d
jl menuSize
	cmp ah, 10d
jg menuSize
	xor cx, cx
	xor ax, ax
	mov al, n
	mov cl, m
	imul cl
	mov cx, ax
	xor si, si
	lea bx, matrix
enterNext:
	mBr
	mPrintStr msgMatrixElement
	call pReadNumb
	mov [bx][si], al
	inc si
loop enterNext
	mPop
	xor ax, ax
	ret 0
pEnterMatrix endp

pPrintMatrix proc near
	mPush
	mData
	mClear
	mClrScr
	mov cl, 3d
	mov ch, 20d
	mSetPoint cl, ch
	xor si, si
	lea bx, matrix
printNext:
	mSetPoint cl, ch
	mov ax, [bx][si]
	xor ah, ah
	call pPrintNumb
	add ch, 5d
	mov ax, si
	inc si
	div m
	inc ah
	cmp ah, m
	jne checkEnd
	inc cl
	mov ch, 20d
checkEnd:
	inc al
	cmp al, n
jl printNext
	cmp ah, m
jl printNext
ggg:
	mPrintStr msgNext
	mReadln
	mPop
	xor ax, ax
	ret 0
pPrintMatrix endp

main proc near
	mData
	mClrScr
menu:
	mClrScr
	mSetPoint 3d, 0d
	mPrintStr menu1MatrixEnter
	mBr
	mPrintStr menu2MatrixPrint
	mBr
	mPrintStr menu3TaskA
	mBr
	mPrintStr menu4TaskB
	mBr
	mPrintStr menu5TaskC
	mBr
	mPrintStr menu0Exit
	mBr
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
	call pEnterMatrix
jmp menu
term2:
	call pPrintMatrix
jmp menu
term3:
	xor ax, ax
jmp menu
term4:
	xor ax, ax
jmp menu
term5:
	xor ax, ax
jmp menu
term6:
	xor ax, ax
jmp menu
term0:
	mov ax, 0700h
	int 12h	
	mov ax, 4C00h
	int 21h
main endp

start:
	call main
end start
MASM
.model small
.stack 100h
.data
	color db 3Eh ;38h
	minus db '-$'
	value dw 0d
	counter db 0d
	counter2 db 0d
	buffer db 27, 1 dup (64)
	menu1MatrixEnter db '   1> Enter Matrix$'
	menu2MatrixPrint db '   2> Print Matrix$'
	menu3MatrixTran db '   3> Trans Matrix$'
	menu4TaskA db '   4> TaskA$'
	menu5TaskB db '   5> TaskB$'
	menu6TaskC db '   6> TaskC$'
	menu7Task0 db '   7> Task0$'
	menu0Exit db ' 0> Exit$'
	msgMatrixSize db '   Type matrix size: $'
	msgMatrixSizeRow db ' row> $'
	msgMatrixSizeCol db ' col> $'
	msgInput db '    > $'
	msgNext db ' --- Press <Enter> ---$'
	msgInputNumber db 'Enter number: $'
	tmpB db 0d
	tmpW db 0d
	tmpA db 0d
	answer0 db 0d
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


pTask0 proc far
	mPush
	mData
	mClrScr
	mClear
	xor ax, ax
	mov value, ax
	mov counter, al
	mov counter2, al
	mov cl, n
	mov al, m
	mul cx
	mov cx, ax
	xor si, si
	lea bx, matrix
printNext0:
	xor ax, ax
	mov ax, [bx][si]
	cmp ax, 0d
	jb wrong0
	inc counter2
wrong0:
	push cx
	mov ax, cx
	dec ax
	xor cx, cx
	mov cl, m
	div cx
	cmp counter2, cl
	jne nxt0
	pop cx
	mov answer0, cl
	mov cl, n
	div cl
	mov answer0, al
	push cx
nxt0:
	dec cl
	cmp dl, cl
	jne wr0
	xor ax, ax
	mov counter2, al
wr0:
	xor cx, cx
	pop cx
	inc si
loop printNext0
	mBr
	xor ax, ax
	mov al, counter
	sub al, n
	neg al
	call pPrintNumb
	mBr
	mPrintStr msgNext
	mReadln
	mPop
	xor ax, ax
	retf
pTask0 endp

pTaskA proc far
	mPush
	mData
	mClear
	mClrScr
	mSetPoint 3d, 3d
	mPrintStr msgInput
	call pReadNumb
	mov value, ax
	xor cx, cx
	xor ax, ax
	xor dx, dx
	mov counter, al
	mov al, m
	mov cl, n
	mul cx
	mov cx, ax
	xor si, si
	lea bx, matrix
nxt:
	mov ax, [bx][si]
	xor ah, ah
	cmp ax, value
	jge more
	inc dl
more:
	inc si
loop nxt
	mBr
	mov ax, ax
	mov al, dl
	call pPrintNumb
	mBr
	mPrintStr msgNext
	mReadln
	mPop
	xor ax, ax
	retf
pTaskA endp

pTaskB proc far
	mPush
	mData
	mClrScr
	mClear
	xor ax, ax
	mov value, ax
	mov counter, al
	mov counter2, al
	mov cl, n
	mov al, m
	mul cx
	mov cx, ax
	xor si, si
	lea bx, matrix
printNext2:
	xor ax, ax
	mov ax, [bx][si]
	cmp ax, 0d
	jne wrong
	inc counter2
wrong:
	push cx
	mov ax, cx
	dec ax
	xor cx, cx
	mov cl, m
	div cx
	cmp counter2, cl
	jne nxt2
	inc counter
nxt2:
	dec cl
	cmp dl, cl
	jne wr
	xor ax, ax
	mov counter2, al
wr:
	xor cx, cx
	pop cx
	inc si
loop printNext2
	mBr
	xor ax, ax
	mov al, counter
	sub al, n
	neg al
	call pPrintNumb
	mBr
	mPrintStr msgNext
	mReadln
	mPop
	xor ax, ax
	retf
pTaskB endp

pTaskC proc far
	mPush
	mData
	mClrScr
	mClear
	xor ax, ax
	mov value, ax
	mov cl, n
	mov al, m
	mul cx
	mov cx, ax
	xor si, si
	lea bx, matrix
nxt3:
	xor ax, ax
	xor dx, dx
	mov ax, si
	mov dl, m
	div dl
	cmp al, ah
	jge skip3
	xor ax, ax
	mov ax, [bx][si]
	xor ah, ah
	add ax, value
	mov value, ax
skip3:
	inc si
loop nxt3
	mBr
	mov ax, value
	call pPrintNumb
	mBr
	mPrintStr msgNext
	mReadln
	mPop
	xor ax, ax
	retf
pTaskC endp

pMatrixTrans proc far
	mPush
	mData
	mClear
	mClrScr
	mov cl, 3d
	mov ch, 3d
	xor si, si
	lea bx, matrix
printNext11:
	mSetPoint ch, cl
	mov ax, [bx][si]
	xor ah, ah
	call pPrintNumb
	add ch, 2d
	mov ax, si
	inc si
	div m
	inc ah
	cmp ah, m
	jne checkEnd0
	add cl, 3d
	mov ch, 3d
checkEnd0:
	inc al
	cmp al, n
jl printNext11
	cmp ah, m
jl printNext11
	mBr
	mPrintStr msgNext
	mReadln
	mPop
	xor ax, ax
	retf
pMatrixTrans endp

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
	mPrintStr msgInput
	call pReadNumb
	mov [bx][si], ax
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
	mov ch, 3d
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
	mov ch, 3d
checkEnd:
	inc al
	cmp al, n
jl printNext
	cmp ah, m
jl printNext
	mBr
	mPrintStr msgNext
	mReadln
	mPop
	xor ax, ax
	ret 0
pPrintMatrix endp

main proc near
	mData
menu:
	mClrScr
	mSetPoint 3d, 1d
	mPrintStr menu1MatrixEnter
	mBr
	mPrintStr menu2MatrixPrint
	mBr
	mPrintStr menu3MatrixTran
	mBr
	mPrintStr menu4TaskA
	mBr
	mPrintStr menu5TaskB
	mBr
	mPrintStr menu6TaskC
	mBr
	mPrintStr menu7Task0
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
	cmp al, 7d
	je term7
jmp menu
term1:
	call pEnterMatrix
jmp menu
term2:
	call pPrintMatrix
jmp menu
term3:
	call far ptr pMatrixTrans
jmp menu
term4:
	call far ptr pTaskA
jmp menu
term5:
	call far ptr pTaskB
jmp menu
term6:
	call far ptr pTaskC
jmp menu
term7:
	call far ptr pTask0
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
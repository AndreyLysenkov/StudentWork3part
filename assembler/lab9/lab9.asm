.model small
.stack 100h
assume cs: code, ds: data
data segment
	color db 3Eh ;38h
	string db 127 dup ('$')
	buffer db 127 dup ('$')
	reader db 7,1 dup (?)
	tmp db 0d
	bool db 0d
	lenght0 db 0d
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

code segment




pTask2 proc near
	mPush
	mData
	mBr
	mClear
	mov tmp, bx
	mov bool, 1d	; хранит: текущий сивол первый в слове?
	lea bx, string
	mov cl, lenght0
	xor si, si
nextSymbol:
	xor dx, dx
	mov dl, [bx][si]
	cmp bool, 0d
	je skip
	mov bool, 0d
	cmp dl, 'a'
	je count
	cmp dl, 'e'
	je count
	cmp dl, 'u'
	je count
	cmp dl, 'i'
	je count
	cmp dl, 'o'
	je count
	cmp dl, 'y'
	je count
	cmp dl, 'A'
	je count
	cmp dl, 'E'
	je count
	cmp dl, 'U'
	je count
	cmp dl, 'I'
	je count
	cmp dl, 'O'
	je count
	cmp dl, 'Y'
	je count
	jmp skip
count:
	inc tmp
skip:
		; проверка начала текущего слова
	cmp dl, ' '
	je stillWord
	cmp dl, '	'
	je stillWord
	mov bool, 1d
stillWord:
	inc si
loop nextSymbol
	mBr
	mPrintStr msgInput
	xor ax, ax
	mov al, tmp
	call pPrintNumb
	mBr
	mPrintStr msgNext
	call pReadNumb
	mPop
	ret 0
pTask2 endp

pTask1 proc near
	mPush
	mData
	mBr
	mClear
	lea bx, string
	mov cl, lenght0
	xor si, si
nextSymbol:
	xor dx, dx
	mov dl, [bx][si]
	cmp dl, ' '
	je skip
	cmp dl, '	'
	je skip
	mov ax, 0200h
	int 21h
skip:
	inc si
loop nextSymbol
	mBr
	mPrintStr msgNext
	call pReadNumb
	mPop
	ret 0
pTask1 endp

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

pReadString proc
	mPush
	mData
	mClear
	mPrintStr msgInput
	mov di, ax
	cld
readSymbol:
	mov ax, 0100h	; функция ввода символа
	int 21h			; символ в регистре ah
	cmp al, 13d		; #13#10 - перенос строки в Windows
	je stopRead
	stosb
	add tmp, 1
jmp readSymbol
stopRead:
	mov al, '$'		; конец строки
	stosb
	mPop
	xor ax, ax
	mov al, tmp
	ret 0
pReadString endp

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

pMenuPrintString proc near
	mData
	mBr
	mPrintStr msgInput
	mPrintStr string
	mBr
	mPrintStr msgNext
	call pReadNumb
	ret 0
pMenuPrintString endp

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
	
jmp menu
term5:
	
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
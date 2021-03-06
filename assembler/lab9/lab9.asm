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

pTask3 proc near
	mPush
	mData
	mClear
	mBr
	mPrintStr msgInput
	mRead
	mov al, buffer+2
	mov tmp, al
	mov counter, 0d
	mov counter2, 0d
	mov bool2, 1d
	mov si, offset string
	mov di, offset string2
	mov cl, lenght0
nextSymbol3:
	xor dx, dx
	mov dl, [si]
	; проверка начала текущего слова
	cmp dl, ' '
	je tabulation3
	cmp dl, '	'
	je tabulation3
	jmp stillWord3
tabulation3:
	cmp counter2, 2d
	jl notCopy
	push cx
	push si
	xor cx, cx
	mov cl, counter
	sub si, cx
	cld
rep movsb
	pop si
	pop cx
notCopy:
	mov counter2, 0d
	mov counter, 0d
stillWord3:
	cmp dl, tmp
	jne notCount
	add counter2, 1d
notCount:
	inc counter
	inc si
loop nextSymbol3
	mBr
	mPrintStr string2
	mBr
	mPrintStr msgNext
	mReadln
	mPop
	ret 0
pTask3 endp

pTask2 proc near
	mPush
	mData
	mClear
	mPrintStr msgInput
	mov tmp, bl
	mov bool, 1d	; хранит: текущий сивол первый в слове?
	lea bx, string
	mov cl, lenght0
	xor si, si
nextSymbol:
	xor dx, dx
	mov dl, [bx][si]
	mov ax, 0200h
	int 21h
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
	je tabulation
	cmp dl, '	'
	je tabulation
	jmp stillWord
tabulation:
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
	mPrintStr msgInput
	lea bx, string
	mov cl, lenght0
	xor si, si
nextSymbol2:
	xor dx, dx
	mov dl, [bx][si]
	cmp dl, ' '
	je skip2
	cmp dl, '	'
	je skip2
	mov ax, 0200h
	int 21h
skip2:
	inc si
loop nextSymbol2
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
	inc tmp
jmp readSymbol
stopRead:
	mov al, ' '
	stosb
	inc tmp
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
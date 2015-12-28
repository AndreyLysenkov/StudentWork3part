.model small
.stack 100h
assume cs: code, ds: data
data segment
	minus db '-$'
	color db 3Eh ;38h
	file db 'data.txt', 0
	file2 db 'data2.txt', 0	
	fileLink dw 0d
	fileLink2 dw 0d
	content db 0, 0, 127 dup ('$')
	content2 db 127, 0, 127 dup ('$')
	buffer db 127, 0, 127 dup ('$')
	readBufferSize dw 127d
	maxLength db 0d
	count db 0d
	msgInput db '     > $'
	msgNext db ' --- Press <Enter> ---$'
	msgErrorLocate db ' Error: Can', 39d, 't locate file$'
	msgErrorCreate db ' Error: Can', 39d, 't create file$'
	msgErrorRead db ' Error: Can', 39d, 't read file$'
	msgErrorWrite db ' Error: Can', 39d, 't write in file$'
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

mError macro msg: REQ
	mPrintStr msgInput
	mPrintStr msg
	jmp exit
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

mOpenFile macro filename: REQ, link: REQ
local success
	push ax
	push cx
	push dx
	xor cx, cx
	mov ax, 3D00h
	mov dx, offset filename
	int 21h
	mov link, ax
	jnc success
	mError msgErrorLocate
success:
	pop dx
	pop cx
	pop ax
endm

mCreateFile macro filename: REQ, link: REQ
local success
	push ax
	push cx
	push dx
	xor cx, cx
	mov dx, offset filename
	mov ax, 3C00h
	int 21h
	mov link, ax
	jnc success
	mError msgErrorCreate
success:
	pop dx
	pop cx
	pop ax
endm

mLengthString macro string: REQ
local nextSymbol
	push si
	push bx
	xor ax, ax
	mov si, offset string
nextSymbol:
	inc si
	inc ax
	mov bl, [si]
	cmp bl, '$'
jne nextSymbol
	pop bx
	pop si
endm

mReadFile macro link: REQ, content: REQ
local success
	push ax
	push bx
	push cx
	push dx
	mov cx, readBufferSize
	mov bx, link
	mov dx, offset content
	mov ax, 3F00h
	int 21h
	jnc success
	mError msgErrorRead
success:
	pop dx
	pop cx
	pop bx
	pop ax
endm

mWriteFile macro link: REQ, content
local success
	push ax
	push bx
	push cx
	push dx
	mov bx, link
	xor cx, cx
	mLengthString content
	mov cx, ax
	mov dx, offset content
	mov ax, 4000h
	int 21h
	jnc success
	mError msgErrorWrite
success:
	pop dx
	pop cx
	pop bx
	pop ax
endm

mCloseFile macro link: REQ
	push ax
	push bx
	mov bx, link
	mov ax, 3E00h
	int 21h
	pop bx
	pop ax
endm

mLength macro link: REQ
local nextSymbol, done
	push cx
	xor ax, ax
	mov cx, readBufferSize
	mov si, link
nextSymbol:
	lodsb
	cmp al, ' '
	je done
	cmp al, '$'
	je done
jmp nextSymbol
done:
	mov ax, si
	sub ax, link
	pop cx
endm

mFindMaxLength macro string: REQ
local nextWord, less
	cld
	mov si, offset string
	mov cx, 0d
nextWord:
	mov bx, si
	mLength bx
	cmp ax, cx
	jl less
	mov cx, bx
less:
	inc si
	lodsb
	cmp al, '$'
jne nextWord
	mov maxLength, cx
endm

mFindEqualLength macro curLength
local nextWord, skip
	cld
	mov si, offset string
	mov cx, 0d
nextWord:
	mov bx, si
	mLength bx
	cmp ax, curLength
	jne less
	inc cx
skip:
	inc si
	lodsb
	cmp al, '$'
jne nextWord
	mov count, cx
endm

code segment

start:
	mData
	mClear
	mClrScr
	mSetPoint 3d, 0d
	mOpenFile file, fileLink
	mCreateFile file2, fileLink2
	mReadFile fileLink, content 
	mPrintStr msgInput
	mPrintStr content
	mBr
	mFindMaxLength content
	mFindEqualLength maxLength
	mov dl, count
	add dl, '0'
	mov ah, 02h
	int 21h
	mWriteFile fileLink2, content2
exit:
	mCloseFile fileLink
	mCloseFile fileLink2
	mBr
	mPrintStr msgNext
	mReadln
	mov ax, 0700h
	int 12h
	mov ax, 4C00h
	int 21h
code ends
end start
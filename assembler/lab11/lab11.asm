.model small
.stack 100h
assume cs: code, ds: data
data segment
	minus db '-$'
	color db 3Eh
	file db 'data.txt', 0
	file2 db 'data2.txt', 0	
	link dw 0d
	link2 dw 0d
	content db 62, 0, 62 dup ('$')
	content2 db 62, 0, 62 dup ('$')
	maxLength db 0d
	count db 0d
	msgInput db '     > $'
	msgNext db ' --- Press <Enter> ---$'
	msgErrLocate db ' Error: Can', 39d, 't locate file$'
	msgErrCreate db ' Error: Can', 39d, 't create file$'
	msgErrRead db ' Error: Can', 39d, 't read file$'
	msgErrWrite db ' Error: Can', 39d, 't write in file$'
data ends

code segment

mBr macro
	mov ax, 0200h
	mov dl, 0Ah
	int 21h
endm

mPrintStr macro string
	mov ax, 0900h
	mov dx, offset string
	int 21h
endm

mError macro msg
	mPrintStr msgInput
	mPrintStr msg
	jmp exit
endm

mOpenFile macro filename, link
local success
	xor cx, cx
	mov ax, 3D00h
	mov dx, offset filename
	int 21h
	mov link, ax
	jnc success
	mError msgErrLocate
success:
endm

mCreateFile macro filename: REQ, link: REQ
local success
	xor cx, cx
	mov dx, offset filename
	mov ax, 3C00h
	int 21h
	mov link, ax
	jnc success
	mError msgErrCreate
success:
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
	mov cx, readBufferSize
	mov bx, link
	mov dx, offset content
	mov ax, 3F00h
	int 21h
	jnc success
	mError msgErrRead
success:
endm

mWriteFile macro link: REQ, content
local success
	mov bx, link
	xor cx, cx
	mLengthString content
	mov cx, ax
	mov dx, offset content
	mov ax, 4000h
	int 21h
	jnc success
	mError msgErrWrite
success:
endm

mCloseFile macro link
	mov bx, link
	mov ax, 3E00h
	int 21h
endm

mLength macro link: REQ
local nextSymbol, done
	push cx
	xor ax, ax
	mov cx, readBufferSize
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
	inc ax
	pop cx
endm

mFindMaxLength macro string: REQ
local nextWord, less, addThat
	cld
	mov si, offset string
	inc si
	mov cx, 0d
	mov dx, 0d
nextWord:
	mov bx, si
	mLength bx
	cmp ax, cx
	je addThat
	jl less
	mov cx, ax
	mov dx, 0d
	jmp less
addThat:
	inc dx
less:
	inc si
	lodsb
	cmp al, '$'
jne nextWord
	mov count, dl
	mov maxLength, cl
endm

mWriteWord macro
local nextSymbol, done
	push cx
	xor ax, ax
	cld
nextSymbol:
	lodsb
	cmp al, ' '
	je done
	cmp al, '$'
	je done
	stosb
jmp nextSymbol
done:
	stosb
	pop cx
endm

mWriteTask macro 
local nextWord, skip
	cld
	mov si, offset content
	mov di, offset content2
	inc si
nextWord:
	mov bx, si
	mLength bx
	cmp al, curLength
	jne skip
	push si
	mov si, cx
	mWriteTask
	pop si
	mov cx, si
skip:
	inc si
	lodsb
	cmp al, '$'
jne nextWord
	mov count, cl
endm

start:
	mov ax, data
	mov ds, ax
	mov es, ax
	mov ax, 0600h
	mov bh, color
	mov cx, 0000h
	mov dx, 184Fh
	int 10h
	mOpenFile file, link
	mCreateFile file2, link2
	mReadFile link, content 
	mFindMaxLength content
	mov dl, count
	add dl, '0'
	mov ah, 02h
	int 21h
	mWriteTask
	mWriteFile link2, content2
exit:
	mCloseFile link
	mCloseFile link2
	mPrintStr msgNext
	mov ax, 0A00h
	lea dx, content
	int 21h
	mov ax, 0700h
	int 12h
	mov ax, 4C00h
	int 21h
code ends
end start
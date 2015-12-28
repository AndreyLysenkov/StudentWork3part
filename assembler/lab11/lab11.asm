.model small
.stack 100h
assume cs: code, ds: data
data segment
	minus db '-$'
	color db 3Eh ;38h
	file db 'data.txt','0'
	file2 db 'data2.txt','0'	
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

mOpenFile macro filename: REQ, string: REQ
local success
	push ax
	push dx
	mov ax, 3D00h
	mov dx, offset filename
	int 21h
	jnc success
	
success:
	pop dx
	pop ax
endm

code segment

start:
	mData
	mClear
	
	
mov ah,3Dh
sub al,al 
mov dx,offset file 
sub cx,cx 
int 21h 
mov filePerem,ax
jnc step1
jmp errSearch 
 
	
	
	mBr
	mPrintStr msgNext
	mReadln
	mov ax, 0700h
	int 12h
	mov ax, 4C00h
	int 21h
code ends
end start
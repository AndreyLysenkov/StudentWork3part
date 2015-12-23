.model small
.stack 100h
.data 
	a db -3d
	b db -4d
	c db 2d
.code
start:
	mov ax,@data
	mov ds,ax

	mov ax, 1
	imul b
	mov bl, c
	idiv bl
	mov bl, 4
	imul bl
	add al, 1
	mov bl, al
	; bl = 4 * b / c + 1

	mov ax, 1
	imul a
	mov cx, 2
	add al, cl
	mov cl, al
	mov ax, 1
	imul c
	imul cl
	mov cl, al
	mov ax, 1
	imul b
	sub cl, al
	; cl = (2 + a)*c - b

	mov al, bl
	idiv cl

	mov ax,4C00h
	int 21h
end start

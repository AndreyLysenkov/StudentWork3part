.model small
.stack 100h
.data 
	a db 01h
	b db 06h
	c db 03h
.code
start:
	mov ax,@data
	mov ds,ax
	sub ax,ax
	
	mov al, b
	mov bl, c
	div bl
	mov bl, 4
	mul bl
	add al, 1
	mov bl, al
	; bl = 4 * b / c + 1
	
	mov al, 2
	mov cl, a
	add al, cl
	mov cl, c
	mul cl
	mov cl, b
	sub al, cl
	mov cl, al
	; cl = (2 + a)*c - b
	
	mov al, bl
	div cl
	
	mov ax,4C00h
	int 21h
end start
.model small
.stack 100h
.data 
	B_TAB db 1Ah, 2Bh, 3Ch, 4Dh, 5Eh, 6Fh, 7Ah, 8Bh
	W_TAB dw 1A2Bh, 3C4Dh, 5E6Fh, 7A8Bh
	B_TAB1 db 0Ah, 8 dup(0)
	W_TAB1 dw 8 dup(0)
	W_TAB2 dw 11h, 12h, 13h, 14h, 15h, 16h, 17h, 18h
.code
start:
	mov ax, @data
	mov ds, ax
	mov al, -3
	mov ax, 3
	mov B_TAB, -3
	mov W_TAB, -3
	mov ax, 2a1bh
	mov bl, al
	mov bh, al
	sub ax, bx
	sub ax, ax
	mov ax, W_TAB
	mov ax, W_TAB+3
	mov ax, W_TAB+5
	mov al, byte ptr W_TAB+6
	mov al, B_TAB
	mov al, B_TAB+2
	mov ax, word ptr B_TAB
	mov ax, 4C00h
	int 21h
end start

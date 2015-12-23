.model small
.stack 100h
.data 
	B_TAB db 1h, 2h, 3h, 4h, 5h, 6h, 7h, 8h
.code
start:
	mov ax, @data
	mov ds, ax
	mov ah, B_TAB
	mov al, B_TAB+7
	mov B_TAB, al
	mov B_TAB+7, ah
	mov ah, B_TAB+1
	mov al, B_TAB+6
	mov B_TAB+1, al
	mov B_TAB+6, ah
	mov ah, B_TAB+2
	mov al, B_TAB+5
	mov B_TAB+2, al
	mov B_TAB+5, ah
	mov ah, B_TAB+3
	mov al, B_TAB+4
	mov B_TAB+3, al
	mov B_TAB+4, ah
	xchg al, B_TAB+1
	xchg al, B_TAB+2
	xchg al, B_TAB+3
	xchg al, B_TAB+4
	xchg al, B_TAB+5
	xchg al, B_TAB+6
	xchg al, B_TAB+7
	mov ah, 07h
	int 21h
	mov ax, 4C00h
	int 21h
end start
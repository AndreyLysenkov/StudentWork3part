.model small
.stack 100h
.data
message db 'Hard is the full step', '$'
fullname db 'Varro, Mark Terence', '$'
lifeyears db '116-27 years. BC', '$'
studentsurname db 'Turchenko', '$'
groupnumber db 'ITD-31', '$'
faculty db 'FNC', '$'
.code
start:
    mov ax, @data
    mov ds, ax
    mov ax, 0600h
    mov bh, 3fh
    mov cx, 0000
    mov dx, 184fh
    int 10h       ;Конец очистки экрана
    mov ah, 2
    mov dh, 10   ;номер строки - 10
    mov dl, 26   ;номер столбца - 26
    mov bh, 0
    int 10h      ;координаты message
    mov ah, 09h
    mov dx, offset message
    int 21h
    mov ah, 2
    mov dh, 11   ;номер строки - 11
    mov dl, 26   ;номер столбца - 26
    mov bh, 0
    int 10h      ;координаты fullname
    mov ah, 09h
    mov dx, offset fullname
    int 21h
    mov ah, 2
    mov dh, 12   ;номер строки - 12
    mov dl, 26   ;номер столбца - 26
    mov bh, 0
    int 10h
    mov ah, 09h
    mov dx, offset lifeyears
    int 21h
    mov ah, 2
    mov dh, 0   ;номер строки - 0
    mov dl, 0   ;номер столбца - 0
    mov bh, 0
    int 10h      ;координаты lifeyears
    mov ah, 09h
    mov dx, offset studentsurname
    int 21h
    mov ah, 2
    mov dh, 0   ;номер строки - 0
    mov dl, 74   ;номер столбца - 75
    mov bh, 0
    int 10h      ;координаты groupnumber
    mov ah, 09h
    mov dx, offset groupnumber
    int 21h
    mov ah, 2
    mov dh, 24   
    mov dl, 0  
    mov bh, 0
    int 10h      ;координаты faculty
    mov ah, 09h
    mov dx, offset faculty
	int 21h       
	mov ah, 2
    mov dh, 24   
    mov dl, 75 
    mov bh, 0
    int 10h     
    mov ah, 02
    mov dl, '!'
	int 21h    
    mov dl, '!'
	int 21h          
    mov dl, '!'
	int 21h          
    mov dl, '!'
	int 21h         
    mov dl, '!'
	int 21h
    mov ah, 7h
	int 21h
    mov ax, 4c00h
	int 21h
end start
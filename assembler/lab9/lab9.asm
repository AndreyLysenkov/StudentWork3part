assume cs: code, ds:data 

data segment 
inputString db 50,0,50 dup('$') 
inputString2 db 50,0,50 dup('$') 
lengthString dw 0d 
tempf db 0d 
countElements db 0d 
countNotRepeat db 0d 
printCount db 'Count words without repeat chars:','$' 
different db 'Different on number: ','$' 
col db 0d 
row db 0d 
command dw 0d 
flag db 0d 
isGood db 0d 
menu db 'Commands:','$' 
trans db '[1]Transpored ' , '$' 
task db '[2]Task ' , '$' 
endMenu db '[~]Exit ' , '$' 
printTitle db 'Type string|>','$' 
equals db 'Strings equal!','$' 
br db 0Dh,0Ah,'$' 
prb db ' ' 
tb db ' ' 
message42 db 0Dh,0Ah,'|> ', '$' 
message41 db '|> ' , '$' 
message43 db 'Type pick|> ' , '$' 
mcerror db 'Error, sorry... :c' , 0Dh,0Ah,'$' 
param db 7,1 dup(?) 
data ends 
code segment 
mClrScr macro 
mov ax,0600h 
mov bh,0eh 
mov cx,0000 
mov dx,184fh 
int 10h 
endm 

mGotoRowCol macro row: REQ, column: REQ 
push ax 
push bx 
push dx 
mov ah, 2 
mov dh, row 
mov dl, column 
mov bh, 0 
int 10h 
pop dx 
pop bx 
pop ax 
endm 

mDisplayStr macro string 
push ax 
push dx 
mov ah,9h 
mov dx, offset string 
int 21h 
pop dx 
pop ax 
endm 

mPrintElem macro 
local mac1, mac2, mac3, mac4 
push bx 
push dx 
push cx 
test ax,ax 
jns mac1 
mov cx,ax 
mov ah,02h 
mov dl,'-' 
int 21h 
mov ax,cx 
neg ax 
mac1: 
xor cx,cx 
mov bx, 10d 
mac2: 
xor dx,dx 
div bx 
push dx 
inc cx 
test ax,ax 
jnz mac2 
mov ah,02h 
mac3: 
pop dx 
cmp dl,9d 
jbe mac4 
add dl,7d 
mac4: 
add dl,'0' 
int 21h 
loop mac3 
pop cx 
pop dx 
pop bx 
endm 

mEnterElem macro s1,buff,merror 
local mac21,mac22,mac23,oshibka,vih 
push bx 
push dx 
push cx 
push si 
mov ah,0ah 
xor di,di 
mov dx,offset buff 
int 21h 
mov dl,0ah 
mov ah,02h 
int 21h 
mov si,offset buff+2 
cmp byte ptr [si],"-" 
jnz mac21 
mov di,1 
inc si 
mac21: 
xor ax,ax 
mov bx,10d 
mac22: 
mov cl,byte ptr[si] 
cmp cl,0dh 
jz vih 
cmp cl,'0' 
jl oshibka 
cmp cl,'9' 
jg oshibka 
sub cl,'0' 
mul bx 
add ax,cx 
inc si 
jmp mac22 
oshibka: 
mov dx,offset merror 
mov ah,09h 
int 21h 
vih: 
cmp di,1 
jnz mac23 
neg ax 
mac23: 
mov s1,ax 
pop si 
pop cx 
pop dx 
pop bx 
endm 

mEnterString macro string 
local met1, met2 
push cx 
push dx 
push si 
mov cx, 0 
mov di, offset string 
cld 
met1: ; ввод символа 
mov ah, 01h 
int 21h 
cmp al, 13 
je met2 
stosb 
add lengthString,1d 
jmp met1 
met2: 
mov al, '$' 
stosb 
pop si 
pop dx 
pop cx 
endm 

mTask1 macro string,char 
local met1,met2 
mov si,offset string 
mov di,si 
mov cx,lengthString 
met1: 
lodsb 
cmp al,char 
jz met2 
stosb 
met2: 
loop met1 
mov al, '$' 
stosb 
endm 

mTask2 macro string 
local met1,met2,met3,met4,met5,met6,met7 
mov tempf,0 
mov countNotRepeat,0 
sub ax,ax 
lea di,string 
mov si,di 
met1: 
sub ax,ax 
mov al,byte ptr[si] 
cmp ax,',' 
je met5 
cmp al,'.' 
je vixod 
met2: 
inc di 
sub bx,bx 
mov bl,byte ptr[di] 
cmp bl,',' 
je met4 
cmp bl,'.' 
je met4 
cmp bx,ax 
je met3 
jmp met2 
met3: 
inc tempf 
jmp met2 
met4: 
inc si 
mov di,si 
jmp met1 
met5: 
inc si 
mov di,si 
sub ax,ax 
mov al,tempf 
cmp ax,0 
je count 
mov tempf,0 
jmp met1 
count: 
inc countNotRepeat 
jmp met1 
vixod: 
mov al,tempf 
cmp ax,0 
je met7 
met6: 
sub ax,ax 
mov al,countNotRepeat 
mPrintElem 
jmp exet 
met7: 
inc countNotRepeat 
jmp met6 
exet: 
mov ah,7 
int 21h 
endm 

mTask3 macro 

sub dx,dx 
mov ah,1h 
int 21h 
mov char,al 
sub cx,cx 
mov cl,lengthString 
lea si,inputString 
lea di,inputString2 
chek: 
mov bx,si 
mov tempf,0d 
chekWord: 
sub ax,ax 
mov al,char 
cmp al,byte ptr[si] 
je met1 
mov dl,byte ptr[si] 
cmp dl,',' 
je met2 
cmp dl,'.' 
je met3 
inc si 
jmp chekWord 

met1: 
inc tempf 
inc si 
jmp chekWord 

met2: 
sub ax,ax 
mov al,tempf 
cmp al,2 
jge copy 
inc si 
jmp chek 

copy: 
mov cx,si 
sub cx,bx 
inc cx 
push si 
cld 
mov si,bx 
rep movsb 
pop si 
jmp
21:15:54	
chek 

copy_end: 
mov cx,si 
sub cx,bx 
inc cx 
push si 
cld 
mov si,bx 
rep movsb 
pop si 
jmp exit_to4 

met3: 
sub ax,ax 
mov al,tempf 
cmp al,2 
jge copy_end 
exit_to4: 
mov cl,lengthString 
lea si,inputString 
lea di,inputString2 
cld 
repe cmpsb 
je equal 
mov ax,si 
sub ax,2d 
mDisplayStr br 
mDisplayStr different 
mPrintElem 
mov ah,7 
int 21h 
jmp menu 
equal: 
mDisplayStr br 
mDisplayStr equals 
exit: 
mov ah,7 
int 21h 
endm 

start: 
mClrScr 
mGotoRowCol 0,0 
mov ax, data 
mov ds, ax 
mov es, ax 

mDisplayStr printTitle 
mEnterString inputString 
mTask2 
mov ax,4C00h 
int 21h 
code ends 
end start
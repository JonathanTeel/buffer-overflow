BITS 32

;
; 32-bit exit
;
; http://blog.markloiseau.com/2012/06/64-bit-linux-shellcode/
;

; sys_exit without nulls
xor eax, eax
mov al, 1
xor ebx, ebx
int 0x80

; shellcode: "\x31\xc0\xb0\x01\x31\xdb\xcd\x80"

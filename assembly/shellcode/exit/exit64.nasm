BITS 64

;
; 64-bit exit assembly routine
;
; http://blog.markloiseau.com/2012/06/64-bit-linux-shellcode/
;

%define NONULLS 1

%if NONULLS

; sys_exit without nulls (good for shellcode)
xor rax, rax
add rax, 60			; rax = 60
xor rdi, rdi		; return code (0)
syscall				; execute
; shellcode: "\x48\x31\xc0\x48\x83\xc0\x3c\x48\x31\xff\x0f\x05"

%else

; sys_exit with nulls (bad for shellcode)
mov rax, 60		; syscall 60 = sys_exit
xor rdi, rdi	; return code (0)
syscall			; execute

; shellcode: "\x48\xb8\x3c\x00\x00\x00\x00\x00\x00\x00\x48\x31\xff\x0f\x05"
%endif

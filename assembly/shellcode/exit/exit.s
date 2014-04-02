# GAS version of the sys_exit routine

.globl _start
_start:
   xor %eax, %eax   # xor anything with itself is 0, so %eax = 0
   movb $1, %al     # move byte 1 into al(a low), eax contains syscall number
   xor %ebx, %ebx   # set ebx to 0, ebx contains return value
   int $0x80        # call kernel

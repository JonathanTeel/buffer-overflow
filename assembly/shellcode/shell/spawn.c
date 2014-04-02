/*
 *  spawn.c - example c program to spawn a shell with execve
 *
 *  http://blog.markloiseau.com/2012/06/64-bit-linux-shellcode/
 */
 
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  execve("/bin/sh", NULL, NULL);
}

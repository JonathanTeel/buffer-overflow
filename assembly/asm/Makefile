LNK=ld

CC=gcc
CFLAGS=-Wall -s -nostartfiles -nostdlib -Xlinker --build-id=none

AS=nasm
AFLAGS=-f elf64

all: normal tiny

normal: hello32.o hello64.o
	$(LNK) -o hello32 hello32.o
	$(LNK) -o hello64 hello64.o

tiny: hello32.o hello64.o
	$(CC) $(CFLAGS) -o tinyhello32 hello32.o
	$(CC) $(CFLAGS) -o tinyhello64 hello64.o

hello32.o:
	$(AS) $(AFLAGS) -o hello32.o hello32.nasm

hello64.o:
	$(AS) $(AFLAGS) -o hello64.o hello64.nasm

clean:
	rm -rf *.o hello64 hello32 tinyhello32 tinyhello64

tidy:
	rm -rf *.o

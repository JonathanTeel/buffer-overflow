all: exploit3.out infinite_loop.out myexploit.out overflow1.out skip_x.out\
	stsi_jump.out vulnerable.out

execsh64.out: execsh64.c
	gcc -ggdb -fno-stack-protector -O0 -o execsh64.out execsh64.c
	execstack -s execsh64.out

%.out: %.c
	gcc -m32 -ggdb -fno-stack-protector -O0 -o $*.out $*.c
	execstack -s $*.out

clean:
	-rm *.out break



all: bindshell-4444.out execsh64.out exploit3.out forkbomb.out infinite_loop.out\
    myexploit.out overflow1.out remote-file-download.out skip_x.out\
    stsi_jump.out vulnerable.out downloadexec.out execsh32.out\
    netcat_connectback.out netcat_connectback_2.out

execsh64.out: execsh64.c
	gcc -ggdb -fno-stack-protector -O0 -o execsh64.out execsh64.c
	execstack -s execsh64.out

%.out: %.c
	gcc -m32 -ggdb -fno-stack-protector -O0 -o $*.out $*.c
	execstack -s $*.out

clean:
	-rm *.out break



all: bindshell-4444.out exec_sh.out exploit3.out forkbomb.out infinite_loop.out\
    myexploit.out overflow1.out remote-file-download.out skip_x.out\
    stsi_jump.out test.out vulnerable2.out vulnerable.out downloadexec.out\
    netcat_connectback.out netcat_connectback_2.out

exec_sh.out: exec_sh.c
	gcc -ggdb -fno-stack-protector -O0 -o exec_sh.out exec_sh.c
	execstack -s exec_sh.out

test.out: test.c
	gcc -ggdb -fno-stack-protector -O0 -o test.out test.c
	execstack -s test.out

%.out: %.c
	gcc -m32 -ggdb -fno-stack-protector -O0 -o $*.out $*.c
	execstack -s $*.out

clean:
	-rm *.out break



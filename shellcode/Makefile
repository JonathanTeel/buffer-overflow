all: bindshell-4444.out downloadexec.out execsh32.out execsh64.out forkbomb.out\
    netcat_connectback_2.out netcat_connectback.out remote-file-download.out\
    reverse_tcp_bindshell.out

execsh64.out: execsh64.c
	gcc -ggdb -fno-stack-protector -O0 -o execsh64.out execsh64.c
	execstack -s execsh64.out

%.out: %.c
	gcc -m32 -ggdb -fno-stack-protector -O0 -o $*.out $*.c
	execstack -s $*.out

clean:
	-rm *.out break



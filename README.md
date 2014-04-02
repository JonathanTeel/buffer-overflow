# Buffer Overflow Presentation
## Tommy Bozeman and Jeremiah Laforge
This repository hosts code for a few demonstrative buffer overflow / shellcode
related programs. This is all currently designed for a linux environment (not
sure if these packages exist in the redhat repositories!)

Right now the demonstration goes roughly as such:


1. install execstack (to be able to make stack memory executable in ELF
   executables)
  - `sudo apt-get install execstack`
2. install gcc-multilib (if running on an x64 machine!)
  - `sudo apt-get install gcc-multilib`
  - (if you're not sure if your machine is x32 or x64,
    run `uname -a` and check!)
3. turn off address space randomization
  - `sudo -s`
  - `echo 0 > /proc/sys/kernel/randomize_va_space`
  - `exit`
4. compile the executables
  - `make`
5. run `vulnerable.out` and `myexploit.out` separately (just to see how they
   behave)
  - `./vulnerable.out`
  - `./myexploit.out`
  - vulnerable.out echoes back anything passed to it as an argument
  - myexploit prints out some ascii gibberish (and accepts up to two integer
    arguments: the first is the size of the buffer, and the second is the
    offset applied to the return address)
6. feed the output of `myexploit.out` to `vulnerable.out` on the command line
   (pick a random offset!)
  - `./vulnerable.out $(./myexploit.out 600 -8)`
  - if you're exceptionally lucky, you'll get a shell on the first try
7. try a lot more offsets!

```sh
for i in {-32..32}; do
    ./vulnerable.out $(./myexploit 600 $[i*8])
    if [ -f break ]; then
        break
    fi
done
```
  - this will try 64 different addresses, each a byte appart
  - (when done correctly, I've never had this spawn fewer than a dozen shells)
  - (once you get a shell a few times, say `touch break` to end the loop)

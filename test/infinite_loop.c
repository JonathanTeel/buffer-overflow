#include <stdio.h>

/**
 * A quick program to demonstrate the power of the return address
 * causes an infinte loop!
 */

void function(int a, int b, int c) {
   int *ret;

   // grab the address on the stack two bytes before `ret`. this ought to be
   // the saved return address from before this function was executed.
   ret = (int*)(&ret) + 0x02;
   // decrement it by 36 bytes (go back 36 bytes in the program, to before this
   // function was called!)
   (*ret) -= 0x036;
}

void main() {
  int x;

  x = 0;
  printf("%d\n",x);
  function(1,2,3);
  x = 1;
  printf("%d\n",x);
}

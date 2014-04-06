#include <stdio.h>

/**
 * A quick program to demonstrate the power of the return address
 * skips the `x = 1;` assignment.
 */

void function(int a, int b, int c) {
   int *ret;

   // grab the address on the stack two bytes before `ret`. this ought to be
   // the saved return address from before this function was executed.
   ret = (int*)(&ret) + 0x02;
   // increment it by 6 bytes (skip the assignment!)
   (*ret) += 0x06;
}

void main() {
  int x;

  x = 0;
  printf("%d\n",x);
  function(1,2,3);
  x = 1;
  printf("%d\n",x);
}

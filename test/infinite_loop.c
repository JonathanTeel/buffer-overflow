#include <stdio.h>

void function(int a, int b, int c) {
    char buffer1[5];
    int i;
    int *ret;

    for (i = -32; i < 0; i += 4){
        ret = buffer1 + i;
        (*ret) -= 64;
    }
}

void main() {
    int x;

    x = 0;
    printf("%d\n",x);
    function(1,2,3);
    x = 1;
    printf("%d\n",x);
}

#include <stdio.h>
void Example(int num) {
    char buf1[5];
    char buf2[10];
    int *ret;
    long ebp;
    asm ("movl %%ebp, %0\n" :"=r"(ebp));
    ret = ebp + 4;
    (*ret) += 0xc;
}

int main(int argc, char **argv) {
    printf("1st Print\n");
    Example(1);
    printf("2nd Print --> you have to jump me:)\n");
    printf("3rd Print\n");
    return 0;
}

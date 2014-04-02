#include <stdio.h>

void exploit() {
    char buffer[32];
    gets(buffer);
    printf("%s\n", buffer);
}

int main() {
    printf("Start State\n");
    printf("Stack:\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p"\
            "\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p"\
            "\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p"\
            "\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p"\
            "\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\n");

    printf("Getting Input:\n>> ");
    exploit();

    printf("Stack:\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p"\
            "\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p"\
            "\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p"\
            "\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p"\
            "\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\n");

    return 0;
}

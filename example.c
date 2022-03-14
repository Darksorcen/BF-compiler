#include "stdio.h"
int main()
{
    char array[30000] = {0};
    unsigned char *ptr = array;
    (*ptr) = getchar();
    while(*ptr) {
    putchar(*ptr);
    (*ptr) = getchar();
    }
    return 0;
}

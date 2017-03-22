#include <stdio.h>

int main(void)
{
/*
    char *p = (void *)0x12345678;
    printf("p = %s\n", p);
*/
    char *p = "hello world\n";
    *p = 'H';

    return 0;
}

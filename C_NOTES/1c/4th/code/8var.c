#include <stdio.h>

#define SIZE 1024 * 1024 * 1024

//已杀死  data段的数据不能等于3G
char a1[SIZE] = {};
char a2[SIZE] = {};
char a3[SIZE] = {};

int main(void)
{

    printf("hello world\n");
    
    return 0;
}

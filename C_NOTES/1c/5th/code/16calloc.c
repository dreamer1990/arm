#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int *p = 0;
    int i = 0;

    //分配内存空间,10个元素,每个元素为4个字节,并且将初始化为0
    p = calloc(10, sizeof(int));
    //p = malloc(10 * sizeof(int));
    if (NULL == p)
    {
        printf("calloc failed..\n"); 
        goto err0;
    }

    for (i = 0; i < 10; i++)
    {
        printf("%2d  ", *(p + i)); 
    }
    putchar('\n');

    
    free(p); 

    return 0;
err0:
    return -1;
}

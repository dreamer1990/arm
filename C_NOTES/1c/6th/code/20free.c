#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p = NULL;

    p = malloc(2 * sizeof(int));
    if (NULL == p)
    {
        printf("malloc failed..\n"); 
        goto err0;
    }

    *p = 88;
    //*(p + 1) = 99;
    *++p = 99;

    printf("*p = %d *(p + 1) = %d\n", *(p - 1), *p);
    //建议free之后  给指针赋值NULL
    free(p - 1);
    --p;
    p = NULL;

    //访问就出现段错误
    //printf("*p = %d *(p + 1) = %d\n", *(p - 1), *p);


    return 0;

err0:
    return -1;
}

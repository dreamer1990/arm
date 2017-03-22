#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int *p = NULL;
    int *p1 = NULL;

    //堆上面的空间
    p = malloc(4);
    if (NULL == p)
    {
        printf("malloc failed..\n"); 
        goto err0;
    }
    printf("p = %p\n", p);

    //用0填充p
    memset(p, 0, 4);

    free(p);
    //不能free两次
    //free(p);
    //什么都不执行
    free(NULL);

    p1 = malloc(4);
    if (NULL == p1)
    {
        printf("malloc failed..\n"); 
        goto err0;
    }

    //地址可能与p相同
    printf("p1 = %p\n", p1);

    free(p1);


    return 0;
err0:
    return -1;
}

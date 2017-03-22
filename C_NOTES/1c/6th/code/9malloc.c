#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int a = 33;
    int *p = NULL;
    int **p2 = NULL;
    int **p3 = NULL;

    //第一种简单的方式
    p2 = &p;
    p = &a;

    printf("a = %d  *p = %d  **p2 = %d\n", a, *p, **p2);

    //分配内存空间  大小为1个sizeof(int *)
    //malloc 返回值为void *类型 因此赋值兼容
    p3 = malloc(sizeof(int *));
    if (NULL == p3)
    {
        printf("mallco failed..\n"); 
        goto err0;
    }
    //用0填充新分配的内存空间
    memset(p3, 0, sizeof(int *));
    //*p3就是int *类型  &a也相当于int *类型  赋值兼容
    *p3 = &a;
    printf("a = %d  **p3 = %d\n", a, **p3);

    free(p3);
    return 0;
err0:
    return -1;
}

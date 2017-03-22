#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//指针函数
//避免返回局部变量的地址
int *fun(int a, int b)
{
    int result;

    result = a + b;

    //返回局部变量的地址
    //警告：函数返回局部变量的地址
    return &result;
}

//返回堆上面的空间
int *fun1(int a)
{
    int *new = NULL;
    new = malloc(4);
    if (NULL == new)
    {
        printf("malloc failed...\n"); 
        goto err0;
    }

    *new = a;

    return new;
err0:
    return NULL;
}


int main(void)
{
    int *p = NULL;
    int a = 3;
    int b = 4;

    p = fun(a, b);

    //此时为7
    printf("*p = %d\n", *p);

    printf("===========================%d\n", 100);

    //这里已经被改变了,原来的值不存在
    printf("*p = %d\n", *p);

    p = fun1(100);
    printf("*p = %d\n", *p);

    //谁分配 谁释放
    free(p);
    return 0;
}

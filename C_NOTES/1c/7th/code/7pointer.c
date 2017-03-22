#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
 *3. 指针函数
 *
 *    返回指针值的函数
 *    一个函数可以返回一个整型值、字符值、实型值等，也可以返回指针型的数据，即地址。其概念与以前类似，只是返回的值的类型是指针类型而已
 *    
 *    定义返回指针值的函数的一般形式为
 *    类型名 *函数名(参数表列);
 *
 */

//指针函数
//返回值是int *类型
//分配count * sizeof(int)个字节
int *alloc_int(int count)
{
    int *new = NULL;
    //从堆中分配内存
    new = malloc(count * sizeof(int));
    if (NULL == new)
    {
        printf("malloc failed..\n"); 
        goto err0;
    }

    memset(new, 0, count * sizeof(int));

    return new;
err0:
    return NULL;
}

//给新分配的空间赋值
int array_random(int *p, int count)
{
    int i = 0;

    srandom(time(NULL));
    for (i = 0; i < count; i++)
    {
        *(p + i) = random() % 100;
    }

    return 0;
}

//打印
int array_show(int *p, int count)
{
    int i = 0;
    for (i = 0; i < count; i++)
    {
        printf("%2d ", *(p + i));
    }
    putchar('\n');
}

int main(void)
{
    int *p = NULL;

    //动态分配内存
    p = alloc_int(10);
    if (NULL == p)
    {
        printf("alloc_int failed..\n"); 
        goto err0;
    }

    array_random(p, 10);
    array_show(p, 10);

    //释放malloc分配的内存
    free(p);
    //断错误
    //free(p + 1);

    return 0;
err0:
    return -1;
}

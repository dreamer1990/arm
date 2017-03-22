
#include "stack.h"

#define MAX 10

int main(void)
{
    stack_t *t = NULL;

    int i = 0;
    int a[MAX] = {0};
    int n = 0;


    //创建栈的头信息结构体
    t = stack_create(sizeof(int), MAX, NULL);
    if (NULL == t)
    {
        goto err0;
    }

    for (i = 0; i < 10; i ++)
    {
        a[i] = random() % 100; 
    }

    //输出数组中的元素
    for (i = 0; i < 10; i++)
    {
        printf("%2d  ", a[i]); 
    }
    putchar('\n');

    //进栈
    for (i = 0; i < 10; i++) 
    {
        stack_push(t, &a[i]); 
    }


    //获取栈顶的数组
    stack_top(t, &n);
    printf("========> %d\n", n);

    //出栈
    while(!stack_is_empty(t))
    {
        stack_pop(t, &n); 
        printf("%d  ", n);
    }

    printf("\n");

    stack_destroy(t);

    return 0;
err0:
    return - 1;
}

#include "stack.h"

//栈的应用
//十进制转二进制

int main(void)
{
    int n = 0;
    int r = 0;

    stack_t *t = NULL;

    //创建
    t = stack_create(sizeof(int), NULL);
    if (NULL == t)
        goto err0;

    printf("please input a number:    ");
    scanf("%d", &n);

    //将余数依次进栈
    while(n)
    {
        r = n % 2;
        stack_push(t, &r);  
        n = n / 2;
    }
    //依次出栈
    while(!stack_is_empty(t)) 
    {
        stack_pop(t, &n);  
        printf("%d", n);
    }
    printf("B\n");
    



    return 0;
err0:
    return -1;
}

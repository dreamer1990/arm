#include <stdio.h>


/*2. 用递归求n!*/

//递归函数:直接或者间接调用本身的函数
unsigned long fun(int n)
{
    //递归必须要有一个结束的条件,否则出现段错误
    if (0 == n || 1 == n)
       return 1;
    
    return fun(n - 1) * n;
}

int main(void)
{
    int n = 0;

    printf("please input a number:   \n");
    scanf("%d", &n);

    printf("%d! = %lu\n", n, fun(n));

    return 0;
}


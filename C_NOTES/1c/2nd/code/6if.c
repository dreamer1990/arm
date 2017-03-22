#include <stdio.h>

//用户输入两个数， 然后从小到大输出

int main(void)
{
    int a, b;
    int tmp;

    printf("please input two numbers:   \n");
    //等待用户输入两个数
    scanf("%d  %d", &a, &b);

    //判断a > b 如果条件成立 就实现两数的交换
    if (a > b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }

    printf("a = %d  b = %d\n", a , b);

    return 0;
}

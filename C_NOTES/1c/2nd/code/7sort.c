#include <stdio.h>

/*
 *2. 用户输入3个int的数， 要求从小到大排序输出
 *    a = 3;  b = 5;  c = 4;
 *    排序后
 *    a = 3; b = 4; c = 5;
 *    printf("a = %d  b = %d  c = %d\n", a, b, c);
 */

int main(void)
{
    int a, b, c;
    int tmp;
    printf("please input three numbers:    \n");
    scanf("%d, %d, %d", &a, &b, &c);
    printf("a = %d  b = %d  c = %d\n", a, b, c);

    // a与b比较  
    if (a > b)
    {
    #if 1
        a ^= b;
        b ^= a;
        a ^= b;
    #else
        tmp = a;
        a = b;
        b = tmp;
    #endif
    }

    //a与c比较
    if (a > c)
    {
        tmp = a;
        a = c;
        c = tmp;
    }

    //b与c比较
    if (b > c)
    {
        tmp = b;
        b = c;
        c = tmp;
    }

    printf("a = %d  b = %d c = %d\n", a, b, c);

    return 0;
}

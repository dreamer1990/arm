#include <stdio.h>

int main(void)
{
    int a = 0;
    int b = 0;

    a = 0x11ffffff;
    printf("%#x\n", a);
    //将a的低4位清零
    a = a & (~0xf);
    printf("%#x\n", a);

    //将高4为置1
    a = a | 0xf << 28; 
    printf("%#x\n", a);

    a = 3;
    b = 4;

    printf("%#x\n", a ^ b);

    //0与任何数异或都为本身  本身与本身异或为0
    //偶数个相同的异或结果为0
    printf("%d\n", a ^ a ^ a ^ a ^ b);
    printf("%d\n", a ^ b ^ a ^ a ^ a);
    printf("%d\n", b ^ a ^ a ^ a ^ a);
    printf("%d\n", a ^ a ^ b ^ a ^ a);

    //~ 取反
    a = 0xffffff00;
    printf("%#x\n", ~a);

    //左移
    printf("3 << 1:  %d\n", 3 << 1);
    //左移右移负数位有警告
    //printf("3 << -1:  %d\n", 3 << (-1));

    //右移
    printf("7 >> 1:  %d\n", 7 >> 1);

    printf("-(8 >> 1): %d\n", -(8 >> 1));
    printf("-8 >> 1:  %d\n", -8 >> 1);


    return 0;
}

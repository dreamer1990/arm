#include <stdio.h>

int main(void)
{

    float i = 3.14;

    unsigned int a = 3;
    int b = -4;


    //3 转为float类型 然后在与i相加
    i = i + 3;

    printf("i = %f\n", i);

    //a + b 转为unsigned类型 最后赋值给a
    a = a + b;
    printf("a + b: %x\n", a);


    //将float double类型强制转换为int 会丢弃小数部分, 但是不改变i原来的值, ()不能少
    a = (int)i;
    printf("a = %d i = %f\n", a, i);

    //隐式转换
    i = a;
    
    i = 3.14;
    //只是将i的值强制转换为int 
    a = (int)i + 3.99;
    printf("a = %d\n", a);
    //是将i + 3.99的结果强转为int
    a = (int)(i + 3.99);
    printf("a = %d\n", a);

    return 0;
}

#include <stdio.h>

int main(void)
{
    //指针实际上是32为的无符号的int类型一个数字
    int a = 3;
    unsigned int u = (unsigned int)&a;
    //访问内存非法  出现断错误
    //u = 0x1234;

    printf("&a = %p  u = %p\n", &a, u);

    //%d  u必须强制转换为int *类型 否则出现错误：‘unary *’ 的实参类型无效
    printf("%d   %d\n", a, *(int *)u);

    return 0;
}

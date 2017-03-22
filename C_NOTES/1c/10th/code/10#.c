#include <stdio.h>

//# 将后面的表达式字符串化
#define DPRINT(x) printf("test--> %s = %d\n", #x, x);

int main(void)
{
    int a = 3;
    int b = 4;

    DPRINT(a);

    //预处理
    DPRINT(a + b);
    DPRINT(a * b);
    DPRINT(a / b);
    DPRINT(a - b);

    return 0;
}

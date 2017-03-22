#include <stdio.h>

/*
 *
 *    7):浮点类型
 *        浮点型数据是用来表示具有小数点的实数
 *        float型(单精度浮点型)
 *        double型(双精度浮点型)编译系统为double型变量分配8个字节，15位有效数字
 *        long double(长双精度)型
 *
 */

int main(void)
{
    float f = 1.0 / 3;
    double d = 1.0 / 3;

    d = 3.141592612345;
    f = (float)d;

    printf("%f\n", f);
    printf("%lf\n", d);

    return 0;
}

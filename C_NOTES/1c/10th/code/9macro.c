#include <stdio.h>

/*
 *__LINE__    代表当前所在行
 *__func__    代表当前所在的函数
 *__TIME__    代表当前的时间
 *__DATE__    代表当前的日期
 *__FILE__    代表当前所在的文件
 */

int test(void)
{
    printf("line: %d\n", __LINE__);
    printf("func: %s\n", __func__);
    printf("time: %s\n", __TIME__);
    printf("date: %s\n", __DATE__);
    printf("file: %s\n", __FILE__);

    return 0;
}

int main(void)
{
    printf("line: %d\n", __LINE__);
    printf("func: %s\n", __func__);
    printf("time: %s\n", __TIME__);
    printf("date: %s\n", __DATE__);
    printf("file: %s\n", __FILE__);

    printf("====================\n");

    test();
    return 0;
}


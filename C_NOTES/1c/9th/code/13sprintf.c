#include <stdio.h>


/*
 *    int sprintf(char *str, const char *format, ...);
 *    功能: 类似于printf,但是输出不是标准输出,而是向字符串str输出
 *    参数:
 *        str: 指向字符串buf
 *        format: 格式控制列表
 *        ...: 变参
 *    返回值:
 *        同printf
 *
 *
 *    int sscanf(const char *str, const char *format, ...);
 *    功能: 类似于scanf,但是输入不是标准输入,而是向字符串str输入
 *    参数:
 *        str: 指向字符串buf
 *        format: 格式控制列表
 *        ...: 变参
 *    返回值:
 *        同scanf
 *
 */

int main(void)
{
    char buf[64];
    int a[4];
    //将字符串"a = 1 b = 2 c = 3 d = 4"保存到buf中
    sprintf(buf, "a = %d b = %d c = %d d = %d\n", 1, 2, 3, 4);
    printf(buf);

    sprintf(buf, "%d.%d.%d.%d\n", 192, 168, 0, 11);
    printf(buf);
    
    //buf --> 192.168.0.11\n
    sscanf(buf, "%d.%d.%d.%d", &a[0], &a[1], &a[2], &a[3]);

    printf("a[0] = %d  a[1] = %d  a[2] = %d a[3] = %d\n", a[0], a[1], a[2], a[3]);

    return 0;
}







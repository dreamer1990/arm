#include <stdio.h>
#include <stdarg.h>

#if 0
int printf(const char *format, ...);
...代表变参
#endif


/*
 *#include <stdarg.h>
 *初始化va_list变量,必须第一次被调用
 *  void va_start(va_list ap, last);
 *从va_list变量中取出一个type类型的值
 *  type va_arg(va_list ap, type);
 *与va_start匹配调用
 *  void va_end(va_list ap);
 *
 */

int test(int a, ...)
{
    va_list ap;
    va_start(ap, a);
    
    printf("%d\n", a);
    printf("%c\n", va_arg(ap, int));
    printf("%s\n", va_arg(ap, char*));
    printf("%lf\n", va_arg(ap, double));
    printf("%d\n", va_arg(ap, int));
    return 0;
}

int main(void)
{
    test(3, 'a', "hello uplooking", 3.14, 44);
    return 0;
}

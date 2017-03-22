#include <stdio.h>

//##args代表参数列表
#define PRINT(format, args ...) printf(format, ##args);

#define DEBUG(format, args ...)                 \
        printf("file: %s  func: %s line: %d  ",     \
        __FILE__, __func__, __LINE__);              \
        printf(format, ##args);

//  \是续行符 续行符后面不能有空格
#define DEBUG_V1(format, args ...)      {           \
        printf("file: %s  func: %s line: %d  ",     \
        __FILE__, __func__, __LINE__);              \
        printf(format, ##args);                     \
}

#define DEBUG_V2(format, args ...)  printf("file: %s \
    func: %s line: %d" format, __FILE__, __func__,    \
        __LINE__, ##args) 


int main(void)
{

    int a = 3;
    int b = 4;

    //与printf("--->%d  %d\n", a, b); //等价
    printf("--->%d " "%d\n", a, b);

    PRINT("print:  a = %d  b = %d\n", a, b);

    DEBUG_V1("a = %d  b = %d\n", a, b)

    if (a + b > 0)
        //编译出错,在定义宏的时候,加上花括号形成语句块
        //DEBUG("a = %d  b = %d\n", a, b);
        DEBUG_V1("a = %d b = %d\n", a,  b)
    else
        /*do nothing*/;

    //debug2
    DEBUG_V2("a = %d b = %d\n", a, b);

    return 0;
}

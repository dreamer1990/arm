#include <stdio.h>

//{}不推荐这种定义格式, 一般使用do{}while(0)
#define DEBUG(format, args ...) {               \
    printf("file: %s  func: %s  line: %d\n",    \
        __FILE__, __func__, __LINE__);          \
    printf(format, ##args);                     \
}


#define DEBUG_V1(format, args ...) do{             \
    printf("file: %s  func: %s  line: %d\n",    \
        __FILE__, __func__, __LINE__);          \
    printf(format, ##args);                     \
}while(0)

int main(void)
{
    int a = 3;
    int b = 4;

    if (a + b > 0)
        //报错
        //DEBUG("a = %d b = %d\n", a, b);
        DEBUG_V1("a = %d b = %d\n", a, b);
    else
        printf("a + b <= 0\n");

    return 0;
}

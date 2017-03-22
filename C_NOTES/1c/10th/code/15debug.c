#include <stdio.h>

//以下两种等价
#define PRINT(format, ...) printf(format, __VA_ARGS__)

#define PRINT_V1(format, args ...) printf(format, ##args)

//出错 
//#define PRINT_V2(format, args ...) printf(format, __VA_ARGS__)


int main(void)
{
    int a = 3;
    int b = 4;

    PRINT("a = %d b = %d\n", a, b);
    PRINT_V1("a = %d b = %d\n", a, b);
    //PRINT_V2("a = %d b = %d\n", a, b);

    return 0;
}

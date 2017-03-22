#include "arith.h"


int main(void)
{
    int a = 10;
    int b = 5;

    printf("a + b = %d\n", add(a, b));
    printf("a - b = %d\n", sub(a, b));
    printf("a * b = %d\n", mul(a, b));
    printf("a / b = %d\n", div(a, b));

    return 0;
}

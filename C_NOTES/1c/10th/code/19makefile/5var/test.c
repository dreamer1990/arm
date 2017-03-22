#include <stdio.h>
#include "a.h"
#include "b.h"

int main(void)
{
    int a = 3;
    int b = 4;

    printf("a + b = %d\n", add(a, b));
    printf("a - b = %d\n", sub(a, b));
    printf("a * b = %d\n", mul(a, b));
    printf("a / b = %d\n", div(a, b));

    return 0;
}

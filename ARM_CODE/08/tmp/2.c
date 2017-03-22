
#include <stdio.h>

int func(void)
{
    printf("%p\n", func);
}

int main(void)
{
    func();
}

#include <stdio.h>

#define NL "\n"
#define D "%d"
#define D1 D NL
#define D2 D D NL
#define D3 D D D NL


int main(void)
{
    printf(D1, 1);
    printf(D2, 1, 2);
    printf(D3, 1, 2, 3);

    return 0;
}

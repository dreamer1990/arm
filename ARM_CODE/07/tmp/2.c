#include <stdio.h>

int ar[102400] = {1,2,3,4};   //.data 占代码空间;
int br[102400];               //.bss  不占代码空间;
int sum = 0;
int main(void)
{
    int i;
    for(i = 0; i < 102400; i++)
        printf("br[%d] = %d\n", i, br[i]);
    printf("sum = %d\n", sum);
}

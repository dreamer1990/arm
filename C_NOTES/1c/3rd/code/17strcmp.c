#include <stdio.h>
#include <string.h>

int main(void)
{
    //strcmp的返回值
    //1     s1 > s2
    //-1    s1 < s2
    //0     s1 == s2
    if (strcmp("hello", "hellp") < 0)
    {
        printf("hello < hellp\n"); 
    }
    else
    {
        printf("hello > hellp\n"); 
    }

    return 0;
}

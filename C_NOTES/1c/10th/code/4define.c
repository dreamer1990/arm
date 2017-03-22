#include <stdio.h>

#define DL "%d"
#define DL2  DL DL

int main(void)
{

    printf(DL, 1);
    printf(DL2, 1, 2);

    //字符串有自动粘贴的功能 hello world hahahh ....
    printf("hello world  " "hahha ....\n");
    return 0;
}

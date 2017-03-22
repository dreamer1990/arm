#include <stdio.h>

int main(void)
{
    int i = 0;
    //str[0] str[1] str[2]相当于一维字符数组 
    char str[3][64];

    printf("please input three strings:  \n");

    //获取三个字符串
    for (i = 0; i < 3; i++)
    {
        gets(str[i]); 
    }


    //输出三个字符串
    for (i = 0; i < 3; i++)
    {
        //自动输出换行符到标准输出
        puts(str[i]);
    }

    return 0;
}

#include <stdio.h>

int main(void)
{
    char a[32];

    printf("please input a string....\n");

    //从标准输入获取字符串
    //遇到空格 回车 \t就输入结束
    scanf("%s", a);

    printf("%s\n", a);

    return 0;
}

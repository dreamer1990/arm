#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[64];
    
    //错误：赋值时类型不兼容
    //a = "hello world";
    
    strcpy(a, "hello world, Welcom to ShenZhen");
    printf("%s\n", a);

    //不会默认添加\0
    strncpy(a, "ABCDEFGHILKLMNOPA", 10);
    printf("%s\n", a);

    printf("strlen:  %d\n", strlen(a));
    //如果参数为NULL 则出现段错误
    //printf("strlen:  %d\n", strlen(NULL));

    //这种是比较两个字符串的地址
    if ("hello shenzhen" < "hello Shenzhen")
    {
        printf("str1 < str2\n");    
    }

    return 0;
}

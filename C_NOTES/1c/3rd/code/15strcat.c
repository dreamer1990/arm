#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[16] = "HA ";
    char dest[128] = "hello ";
    char src[64] = "   world";

    strcat(dest, src);
    printf("dest:  %s\n", dest);

    strncat(dest, "ABCDEFGHIJKLMN", 5);
    printf("dest:  %s\n", dest);

    
    //错误：赋值时类型不兼容
    //src = "hello world";
    //段错误 原因str空间太小了,不能存放dest中的字符串
    //strcat(str, dest);
    //printf("str:  %s\n", str);

    return 0;
}

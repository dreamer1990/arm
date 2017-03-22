#include <stdio.h>

int main(void)
{


/*
 *    如果一个字符数组中包含多个’\0’，则遇第一个’\0’时输出就结束
 *    可以用scanf函数输入一个字符串
 *    scanf函数中的输入项c是已定义的字符数组名，输入的字符串应短于已定义的字符数组的长度
 *
 */
    char a[10] = {'A', 'B', 'C', 'D', 0, 'F', 'G', '\0', 'I', 'J'};
    char b[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    //如果初始化的字符串长度小于数组的大小，那么数组没有初始化都默认为0
    char c[11] = "ABCDEFGHIJ";
    char d[] = {"AAAAAAAA"};

    printf("a: %p  &a[9]: %p  b: %p  &b[9]:%p\n", a, &a[9], b, &b[9]);
    //%s 输出字符串 遇到\0结束输出
    printf("a:  %s\n", a);
    printf("b:  %s\n", b);
    printf("c:  %s\n", c);
    printf("d: %s\n", d);


    return 0;
}

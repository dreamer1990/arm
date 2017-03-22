#include <stdio.h>
/*
 *
 *    4.1 指针数组
 *    一个数组，若其元素均为指针类型数据，称为指针数组，也就是说，指针数组中的每一个元素都存放一个地址，相当于一个指针变量。
 *
 *    4.2 指针数组定义的形式
 *    定义一维指针数组的一般形式为
 *    类型名*数组名[数组长度];
 *    int *p[4];
 *    
 *    指针数组比较适合用来指向若干个字符串，使字符串处理更加方便灵活
 *    可以分别定义一些字符串，然后用指针数组中的元素分别指向各字符串
 *    由于各字符串长度一般是不相等的，所以比用二维数组节省内存单元
 *
 */

int main(void)
{
    int i = 0;
    char *str[5] = {"ShenZhen", "GuangZhou", "ShangHai", "BeiJing", "HangZhou"};

    //5个指针 每个指针占用4个字节
    printf("sizeof(str): %d\n", sizeof(str));

    for (i = 0; i < 5; i++)
    {
        printf("str[%d]:  %s\n", i, str[i]);
    }

    //只读数据段 段错误
    //*str[0] = 's';

    printf("%c\n", *str[0]);


    return 0;
}

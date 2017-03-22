#include <stdio.h>


// sizeof: 求类型所占的字节数 sizeof是运算符
// sizeof (type)
// sizeof (变量名)
// sizeof 变量名
// sizeof 常量

int main(void)
{
    int a = 3;

    //sizeof后面为类型的时候  ()不能省略
    printf("sizeof(int):  %d\n", sizeof(int));
    //sizeof a 和 sizeof(a)是等价  ()可以省略
    printf("sizeof(a): %d\n", sizeof(a));
    printf("sizeof(a): %d\n", sizeof a );

    //字符类型实际上先转换成ascii  然后在保存
    printf("sizeof('M'): %d\n", sizeof 'M');  //sizeof 'M' == sizeof 65
    printf("sizeof(123): %d\n", sizeof 123);  // sizeof(int)

    //浮点类型3.14默认为double类型 3.14f 就是float类型
    printf("sizeof(3.14): %d\n", sizeof(3.14f));// sizeof(float)
    printf("sizeof(3.14): %d\n", sizeof(3.14));// sizeof(double)
    //求字符串所占用的空间大小 包括\0
    printf("sizeof(\"hello\"): %d\n", sizeof("hello"));

    return 0;
}

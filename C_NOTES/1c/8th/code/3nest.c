#include <stdio.h>

//结构体的嵌套

//定义一个结构体类型
struct Info {
    int age;
    char name[32];
    char sex;
};

//定义一个结构题类型
struct Stu{
    struct Info info1;  //嵌套其他结构体类型作为一个结构体的成员
    char class[32];
};

int main(void)
{
    //40个字节  = 4 + 32 + 4
    printf("sizeof(struct Info):  %d\n", sizeof(struct Info));
    //72个字节 = 40 + 32
    printf("sizeof(struct Stu):   %d\n", sizeof(struct Stu));

    return 0;
}

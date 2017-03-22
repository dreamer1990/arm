#include <stdio.h>

//位段
struct stu_t {
    unsigned int a:2; //a占两位 2bits
    unsigned int b:2;
    unsigned int c:4; //c占4位 4bits
    unsigned char d:1;
};

struct s_t {
    int a;
    int b;
    int c;
};

int main(void)
{
    struct stu_t t;

    //这里是结构体的初始化,并不是位段
    struct s_t t1 = {
        a:3,
        b:4,
        c:5,
    };

    //四个字节
    printf("sizeof(t):  %d\n", sizeof(t));

    // 警告：隐式常量转换溢出
    //t.a = 4;
    //a占用2位,一定要防止溢出
    t.a = 2;

    t.b = 3;
    t.c = 15;

    t.d = 1;

    //位段的访问方式
    printf("t.a = %u  t.b = %u t.c = %u t.d = %u\n", t.a, t.b, t.c, t.d);

    printf("t1.a = %d  t1.b = %d t1.c = %d\n", t1.a, t1.b, t1.c);


    return 0;
}

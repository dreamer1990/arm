#include <stdio.h>

struct stu {
    char sex;
    int age;
    char a;
}; //后面的分号不能省略

struct A{
    char a;
    char b;
    int c;
};

struct B{
    char a;
    char b;
    char c;
};

struct C{
    char a;
    char b;
    char c;
    int d;
};

struct D{
    double d; //8
    char a; //1
    char b; //1
    int c;  //4
};

struct E{
    char a;     //1
    char b;     //1
    double c;   //8
    int d;      //4
    char e;     //1
};



int main(void)
{
    //定义一个结构体变量,分配了存储空间
    struct A a;

    //12个字节
    printf("sizeof(struct stu):  %d\n", sizeof(struct stu));

    //8个字节
    printf("sizeof(struct A):  %d\n", sizeof(struct A));
    printf("a:  %p  b:  %p  c: %p\n", &a.a, &a.b, &a.c);

    //3个字节
    printf("sizeof(struct B):  %d\n", sizeof(struct B));

    //8个字节
    printf("sizeof(struct C): %d\n", sizeof(struct C));

    //16个字节 
    printf("sizeof(struct D):  %d\n", sizeof(struct D));

    //20个字节
    printf("sizeof(struct E:):  %d\n", sizeof(struct E));


    return 0;
}

#include <stdio.h>


/*
 *8. 共用体
 * (1) 基本概念
 *    有时想用同一段内存单元存放不同类型的变量。
 *    使几个不同的变量共享同一段内存的结构，称为 “共用体”类型的结构。
 *
 *    定义共用体类型变量的一般形式为：
 *    union　共用体名
 *    { 成员表列
 *    }变量表列； 
 */

//声明一个联合体类型
union stu_t {
    char a;
    int b;
    long c;
};

struct stu_t1 {
    char a; //1
    int b;  //4
    long c; //4
};

int main(void)
{
    //4
    printf("sizoef(union stu_t):  %d\n", sizeof(union stu_t));


/*
 * (2) 共用体与结构体的区别
 *“共用体”与“结构体”的定义形式相似，但它们的含义是不同的。
 *结构体变量所占内存长度是各成员占的内存长度之和，每个成员分别占有其自己的内存单元。而共用体变量所占的内存长度等于最长的成员的长度。
 *
 */
    //12
    printf("sizeof(struct stu_t1): %d\n", sizeof(struct stu_t1));

    union stu_t t;
    //不能同时初始化
    //union stu_t t = {1, 2, 3};

    //它们都是共享一个内存空间
    printf("%p  %p  %p\n", &t.a, &t.b, &t.c);
    t.a = 'a';
    printf("%c  %d  %ld\n", t.a, t.b, t.c);

    t.b = 0xffff;
    printf("%d  %d %ld\n", t.a, t.b, t.c);

    //e. 不能对共用体变量名赋值，也不能企图引用变量名来得到一个值。
    //错误：赋值时类型不兼容
    //t = 100;



    return 0;
}

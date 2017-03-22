#include <stdio.h>

//不同类型的集合
//姓名       char*
//年龄       int
//员工ID号   long int
//员工的住址 char*


/*
 *struct 结构体名称
 *{
 *    char name[32];
 *    int age;
 *    long int id;
 *    char addr[32];
 *};
 *
 */


/*
 *    (1)结构体类型并非只有一种，而是可以设计出许多种结构体类型，例如
 *    struct Teacher
 *    struct Worker
 *    struct Date等结构体类型
 *    各自包含不同的成员
 *
 */

//结构体类型的定义, 没有分配空间,因为struct stu只是一个结构体类型
struct stu{
    int id;         //学号
    char name[32];  //姓名
};

struct teacher{
    int id;         //员工编号
    char name[32];  //姓名
    char pro[32];   //职称
};

int main(void)
{
    //结构体类型所占的空间是所有成员所占的空间的总和,并且要考虑对齐问题
    //36个字节  = 4 + 32
    printf("sizeof(struct stu):  %d\n", sizeof(struct stu));
    //68个字节 = 4 + 32 + 32
    printf("sizeof(struct teacher):  %d\n", sizeof(struct teacher));

    return 0;
}

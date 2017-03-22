#include <stdio.h>

//结构体变量定义的三种方式


/*
 *    (1). 先声明结构体类型，再定义该类型变量
 *    声明结构体类型struct Student，可以用它来定义变量
 *     struct Student  student1,student2;
 *
 */

//结构体类型
struct stu{
    int id;
    char name[32];
};

//(2)声明结构体类型的时候,定义结构体变量
struct stu_1 {
    int id;
    char sex;
    char addr[32];
}stu2, stu3;


/*
 *    (3). 不指定类型名而直接定义结构体类型变量
 *    其一般形式为:
 *       struct
 *       { 成员表列 }变量名表列; 
 *    指定了一个无名的结构体类型 。
 *
 */
//匿名结构体, 用的比较少
struct {
    int id;
    char addr[32];
}stu4, stu5;

int main(void)
{
    //struct stu是结构体类型, 类型是不占空间的
    //stu1是结构体变量, 变量是占空间
    struct stu stu1;

    //结构体首地址与结构体中第一个成员的地址在数值上相等
    printf("&stu1:  %p\n", &stu1);
    printf("&stu1.id:  %p\n", &stu1.id);

    printf("&stu1.name:  %p\n", &stu1.name);

    printf("=========================\n");
    printf("&stu2:  %p  &stu3:  %p\n", &stu2, &stu3);

    printf("&stu4:  %p\n", &stu4);

    return 0;
}

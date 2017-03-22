#include <stdio.h>


/*
 *    说明:
 *    (1) 结构体类型与结构体变量是不同的概念，不要混同。只能对变量赋值、存取或运算，而不能对一个类型赋值、存取或运算。在编译时，对类型是不分配空间的，只对变量分配空间。
 *
 *    (2) 结构体类型中的成员名可以与程序中的变量名相同，但二者不代表同一对象。
 *    (3) 对结构体变量中的成员（即“域”），可以单独使用，它的作用与地位相当于普通变量。
 *
 */


/*
 *3. 结构体的初始化和引用
 *    (1) 在定义结构体变量时可以对它的成员进行初始化。
 *    (2) 可以引用结构体变量中成员的值,引用方式为 结构体变量名.成员名
 *    (3) 如果成员本身有属于一个结构体类型,则要用若干个成员运算符,一级一级的找到最低一级的成员。
 *    (4) 对结构体变量的成员可以像普通变量一样进行各种运算。
 *    (5) 同类结构体可以相互赋值
 *    (6) 可以引用结构体变量成员的地址, 也可以引用结构体变量的地址
 *
 */
struct stu_t{
    int id;
    char sex;
    char name[32];
};


int main(void)
{
    //方式一: 结构体初始化
    struct stu_t stu = {32, 'M', "Uplooking"};

    //方式二: 结构体初始化 内核初始化结构体的方式
    struct stu_t stu1 = {
        .id = 100,
        .sex = 'M',
        .name = "ShenZhen",
    };

    //方式三: 结构体初始化  这种方式用的比较少
    struct stu_t stu2 = {
        id:3,
        sex:'F',
        name:"GuangZhou",
    };

    //. 成员访问符  stu.id与普通的int类型的变量一样 
    //引用方式:  结构体变量明.成员名
    printf("id: %d  sex:  %c name: %s\n", stu.id, stu.sex, stu.name);

    stu.id = 100;
    stu.sex = 'F';
    printf("id: %d  sex:  %c name: %s\n", stu.id, stu.sex, stu.name);

    printf("==========================\n");
    printf("id:  %d  sex:  %c  name:  %s\n", stu1.id, stu1.sex, stu1.name);

    printf("=============================\n");
    printf("id:  %d  sex:  %c   name: %s\n", stu2.id, stu2.sex, stu2.name);


    return 0;
}

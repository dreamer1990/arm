#include <stdio.h>

struct info_t {
    char sex;
    int age;
    char name[32];
};

//结构体中有结构体成员
struct stu_t {
    //结构体变量
    struct info_t info;
    int id;
};


/*
 *    (2) 可以引用结构体变量中成员的值,引用方式为 结构体变量名.成员名
 *
 *    (3) 如果成员本身又属于一个结构体类型,则要用若干个成员运算符,一级一级的找到最低一级的成员。
 *
 */
int main(void)
{
    struct stu_t stu = {{'M', 32, "ZhangSan"}, 2016};
    struct stu_t stu1 = {'M', 32, "ZhangSan", 2016};

    struct stu_t stu2;

    //stu.info.sex 是stu结构体中有info成员, info成员又是一个结构体, sex属于info结构体的成员
    printf("sex:  %c  age:  %d  name: %s id: %d\n", stu.info.sex, stu.info.age, stu.info.name, stu.id);

    //相同类型的结构体可以相互赋值
    stu2 = stu;
    printf("sex:  %c  age: %d name: %s id: %d\n", stu2.info.sex, stu2.info.age, stu2.info.name, stu2.id);

    return 0;
}

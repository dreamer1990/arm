#include <stdio.h>

/*
 *5. 结构体指针
 *
 *    指向结构体对象的指针变量既可以指向结构体变量，也可以用来指向结构体数组中的元素。
 *    指针变量的基类型必须与结构体变量的类型相同。例如：
 *    struct Student *pt; 
 */

struct stu_t {
    int id;
    char name[32];
};

int main(void)
{
    //定义一个结构体变量
    struct stu_t stu = {
        .id = 100,
        .name = "ceacsz",
    };

    //结构体类型 * 指针变量名;
    struct stu_t *p = NULL;
    p = &stu;

    printf("stu ---> id:  %d  name:  %s\n", stu.id, stu.name);
    //(*p).id 中的括号不能省略 .的优先级比*高
    printf("*p ----> id:  %d  name:  %s\n", (*p).id, (*p).name);

    return 0;
}

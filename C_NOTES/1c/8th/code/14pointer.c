#include <stdio.h>

/*
 *    说明：
 *    为了使用方便和直观，C语言允许把(*p).num用p->num来代替
 *    (*p).name等价于p->name
 *    如果p指向一个结构体变量stu，以下等价：
 *    ①  stu.成员名(如stu.num)
 *    ②  (*p).成员名(如(*p).num)
 *         p->成员名(如p->num)
 *
 */

struct stu_t {
    int id;
    char name[32];
};

int main(void)
{
    struct stu_t stu = {
        .id = 101,
        .name = "uplooking",
    };
    
    struct stu_t *p = NULL;

    //p指向结构体stu
    p = &stu;

    //三种方式
    printf("id:  %d  name:  %s\n", stu.id, stu.name);
    printf("id:  %d  name:  %s\n", (*p).id, (*p).name);
    printf("id:  %d  name:  %s\n", p->id, p->name);

    return 0;
}

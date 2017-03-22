#include <stdio.h>

struct stu_t {
    int id;
    char name[32];
};

int main(void)
{
    int i = 0;

    //结构体数组
    struct stu_t stu[3] = {
    {
        .id = 111, 
        .name = "aaaaaa",
    },
    {
        .id = 222,
        .name = "bbbbbb",
    },
    {
        .id = 333,
        .name = "cccccc",
    },
    
    };

    //定义一个结构体指针
    struct stu_t *p = NULL;
    //p = &stu[0];
    p = stu;

    //p++ --->  + sizeof(stu)
    //指针指向结构体数组中的某一个元素
    for (p = stu; p < stu + 3; p++)
    {
        printf("===>  id:  %d  name:  %s\n", p->id,  p->name); 
    }

    //free(p);
    return 0;
}

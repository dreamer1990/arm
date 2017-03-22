#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stu_t {
    int id;
    char *name;
};

int main(void)
{
    //定义一个结构体变量
    struct stu_t stu = {
        .id = 101,
    };

    struct stu_t stu2, stu1;

    stu.name = malloc(32 * sizeof(char));
    if (NULL == stu.name)
    {
        printf("malloc failed...\n"); 
        goto err0;
    }
    //将新分配的空间用0填充
    memset(stu.name, 0, 32);

    strcpy(stu.name, "Uplooking");
    printf("stu ---> id:  %d name:  %s\n", stu.id, stu.name);

    //浅拷贝
    memcpy(&stu2, &stu, sizeof(stu));
    printf("stu2 --> id:  %d name:  %s\n", stu2.id, stu2.name);

    memcpy(&stu1, &stu, sizeof(stu));
    //深拷贝
    stu1.name = malloc(32 * sizeof(char));
    if (NULL == stu1.name)
    {
        printf("malloc failed...\n"); 
        goto err1;
    }
    memset(stu1.name, 0, 32);
    //拷贝结构体的数据
    //拷贝stu.name中的数据
    strcpy(stu1.name, stu.name);

    printf("stu1 ---> id:   %d  name:  %s\n", stu1.id, stu1.name);

    //释放空间
    free(stu.name);
    //free(stu2.name); //不能free两次

    free(stu1.name);
    return 0;
err1:
    free(stu.name);
err0:
    return -1;
}

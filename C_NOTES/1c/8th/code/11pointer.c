#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stu_t {
    int id;
    char *name;
};

int main(void)
{

    struct stu_t stu = {
        .id = 100,
        .name = "ShenZhen",
    };

    struct stu_t stu1 = {
        .id = 101, 
    };

    printf("id:  %d  name:  %s\n", stu.id, stu.name);
    //断错误  只读数据段
    //strcpy(stu.name, "Uplooking");
    //"Uplooking"也是在只读数据段中
    stu.name = "Uplooking";
    printf("id:  %d  name:  %s\n", stu.id, stu.name);

    printf("================================\n");
    //动态分配空间
    stu1.name = malloc(32 * sizeof(char));
    if (NULL == stu1.name)
    {
        printf("malloc failed..\n"); 
        goto err0;
    }

    strcpy(stu1.name, "zhangshan");
    printf("stu1 --->  name:  %s  id:  %d\n", stu1.name, stu1.id);

    //stu1.name = "aaaaaaa";
    //printf("stu1 --->  name:  %s  id:  %d\n", stu1.name, stu1.id);


    free(stu1.name);
    return 0;
err0:
    return -1;
}

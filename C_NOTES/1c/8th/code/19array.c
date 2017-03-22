#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//以下两种不定长数组是等价
struct stu_t {
    int id;
    int age;
    char name[0]; //数组长度为0  
};

struct stu_t1 {
    int id;
    int age;
    char name[];
};

int main(void)
{

    struct stu_t *p = NULL;
    struct stu_t1 *p1 = NULL;

    //不定长数组
    p = malloc(sizeof(struct stu_t) + 32 * sizeof(char));
    if (NULL == p)
    {
        printf("malloc failed...\n"); 
        goto err0;
    }

    p->id = 100;
    p->age = 147;
    //p->name = "hello world";  //错误
    strcpy(p->name, "shenzhen");

    printf("id:  %d  age:   %d  name:  %s\n", p->id, p->age, p->name);
    printf("===============================\n");

    p1 = malloc(sizeof(struct stu_t1) + 32 * sizeof(char));
    if (NULL == p1)
    {
        printf("malloc failed..\n");
        goto err1;
    }

    p1->id = 111;
    p1->age = 120;
    strcpy(p1->name, "Uplooking");
    printf("id:  %d  age:   %d  name:  %s\n", p1->id, p1->age, p1->name);

    free(p1);
    free(p);
    return 0;
err1:
    free(p);
err0:
    return -1;
}

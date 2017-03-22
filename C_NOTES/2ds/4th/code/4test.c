#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//结构体
typedef struct _stu_t{
    int id;
    char sex;
    char *name;
}stu_t;


int main(void)
{
    stu_t stu1 = {
        .id = 1,
        .sex = 'M',
        .name = "uplook",
    }, stu2;

    stu_t *t3 = NULL, *t4 = NULL;

    memcpy(&stu2, &stu1, sizeof(stu1));

    printf("id: %d  sex: %c  name: %s\n", stu1.id, stu1.sex, stu1.name);
    printf("id: %d  sex: %c  name: %s\n", stu2.id, stu2.sex, stu2.name);


    t3 = malloc(sizeof(stu_t));
    
    t3->id = 3;
    t3->sex = 'M';
    t3->name = malloc(32);
    //t3->name = "hello";
    strcpy(t3->name, "uplooking");
    
    printf("id:  %d  sex: %c name: %s\n", t3->id, t3->sex, t3->name);

    t4 = malloc(sizeof(stu_t));


    //浅拷贝
    memcpy(t4, t3, sizeof(stu_t));

    free(t3->name);
    t3->name = NULL;
    free(t3);
    t3 = NULL;

    printf("id:  %d  sex: %c name: %s\n", t4->id, t4->sex, t4->name);


    return 0;
}





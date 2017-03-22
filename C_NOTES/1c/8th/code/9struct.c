#include <stdio.h>

struct stu_t {
    int id;
    char name[32];
};


int main(void)
{
    struct stu_t stu1 = {
        .id = 100,
        .name = "ceac",
    };


    printf("sizoef(stu1):  %d\n", sizeof(stu1));
    printf("&stu1:  %p\n", &stu1);

    //&stu1 + 1 ---> stu1的地址 加上sizeof(stu1)
    printf("&stu1 + 1: %p\n", &stu1 + 1);



    return 0;
}

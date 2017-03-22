#include <stdio.h>
#include <string.h>

struct stu_t {
    int id;
    char name[32];
};

int main(void)
{
    struct stu_t stu1 = {
        .id = 100,
        .name = "Hello",
    };

    struct stu_t stu2 = {
        .id = 1,
        .name = "Boy",
    };

	//(4) 对结构体变量的成员可以像普通变量一样进行各种运算。
    printf("id: %d  name:   %s\n", stu1.id, stu1.name);
    stu1.id = stu2.id + 88;
    strcpy(stu1.name, "ceac");
    printf("id: %d  name:   %s\n", stu1.id, stu1.name);

    //stu1与普通变量意义差不多,但是stu1访问成员必须通过.访问
    printf("stu1:  %p\n", stu1);
    printf("stu1:  %d\n", stu1); //89
    printf("stu1:  %s\n", (void*)&stu1 + 4);

    //结构体不能整体输出
    //printf("stu1:  %s\n", stu1);

    return 0;
}

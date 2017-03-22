#include <stdio.h>
#include <string.h> 
/*
 *1. 声明一个结构体类型如下:
 */
struct stu_t {
    int id;
    char sex;
    char name[32];
    char addr[32];
};

int main(void)
{
    struct stu_t stu1 = {100, 'M', "ZhangSan", "ShangHai"};
    struct stu_t stu2 = {
        .id = 100,
        .sex = 'F',
        .name = "LiSi",
        .addr = "BeiJing",
    };

    struct stu_t stu3 = {
        id:88,
        sex:'M',
        name:"WangWu",
        addr:"ShenZhen",
    };

    struct stu_t stu4;
    stu4.id = 33;
    stu4.sex = 'M';
    //stu4.name = "MaLiu"; //error
    strcpy(stu4.name, "MaLiu");
    strcpy(stu4.addr, "GuangZhou");
    
    printf("=====================================\n");
    printf("id:  %d  sex: %c name: %s addr: %s\n", stu1.id, stu1.sex, stu1.name, stu1.addr);
    printf("id:  %d  sex: %c name: %s addr: %s\n", stu2.id, stu2.sex, stu2.name, stu2.addr);
    printf("id:  %d  sex: %c name: %s addr: %s\n", stu3.id, stu3.sex, stu3.name, stu3.addr);
    printf("id:  %d  sex: %c name: %s addr: %s\n", stu4.id, stu4.sex, stu4.name, stu4.addr);
    printf("=====================================\n");


}

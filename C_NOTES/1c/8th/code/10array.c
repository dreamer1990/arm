#include <stdio.h>


/*
 *4. 结构体数组
 *
 *    struct Person               
 *    {  
 *        char name[20];       
 *        int count;                   
 *    }leader[3]={“Li”,0,“Zhang”,0,“Sun”,0};   
 *
 *(1) 定义结构体数组一般形式是
 *① struct 结构体名
 *    {成员表列} 数组名[数组长度];
 *② 先声明一个结构体类型，然后再用此类型定义结构体数组：
 *     结构体类型  数组名[数组长度];
 *   如：
 *     struct Person  leader[3]; 
 *
 *(2)对结构体数组初始化的形式是在定义数组的后面加上：
 *＝｛初值表列｝; 
 * 如：
 *struct Person  leader[3]= {"Li",0,"Zhang",0,"Fun",0}; 
 *
 */

struct stu_t {
    int id;
    char name[32];
};

int main(void)
{
    int i = 0;

    //结构体数组中的每一个元素是结构体类型
    //只是相同类型元素的集合
    struct stu_t stu[3] = {
    {
        .id = 100,
        .name = "GZ",
    },
    {
        .id = 110,
        .name = "SZ",
    },
    {
        .id = 120,
        .name = "SH",
    }
    };     

    //第二种初始化方式
    struct stu_t stu1[3] = {
        {100, "HZ"},
        {111, "ZJ"},
        {222, "FJ"},
    };

    //第三中方式  可以都写在一起,但是一定要匹配
    struct stu_t stu2[3] = {444, "HN", 555, "HB", 666, "SC"};

    for (i = 0; i < 3; i++)
    {
        printf("i:  %d ===>  id: %d name: %s\n", i, stu[i].id, stu[i].name);
    }
    printf("==================================\n");
    for (i = 0; i < 3; i++)
    {
        printf("i: %d ===>  id:  %d  name: %s\n", i, stu1[i].id, stu1[i].name); 
    }

    printf("=================================\n");
    for (i = 0; i < 3; i++)
    {
        printf("i:  %d ===>  id:  %d  name:  %s\n", i, stu2[i].id, stu2[i].name); 
    }


    return 0;
}

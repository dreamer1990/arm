#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 *(2) 用结构体变量作实参。
 *    用结构体变量作实参时，将结构体变量所占的内存单元的内容全部按顺序传递给形参，形参也必须是同类型的结构体变量
 *    在函数调用期间形参也要占用内存单元。这种传递方式在空间和时间上开销较大
 *    在被调用函数期间改变形参（也是结构体变量）的值，不能返回主调函数
 *    一般较少用这种方法
 *
 *(3)用指向结构体变量（或数组元素）的指针作实参，将结构体变量（或数组元素）的地址传给形参。
 *
 */

struct stu_t {
    int id;
    char name[32];
};

//分配一个struct stu_t类型大小的空间
struct stu_t *stu_alloc(int size)
{
    struct stu_t *tmp = NULL;

    //分配空间
    tmp  = malloc(size);
    if (NULL == tmp)
    {
        printf("malloc failed...\n"); 
        goto err0;
    }
    //初始化
    memset(tmp, 0, size);

    return tmp;
err0:
    return NULL;
}

//随机给结构体变量赋值
int stu_random(struct stu_t *stu)
{
    stu->id = random() % 100;
    sprintf(stu->name, "%c%c%c%c%c%c", 'A' + random() % 26,
                'a' + random() % 26, 'a' + random() % 26,
                'a' + random() % 26, 'a' + random() % 26,
                'a' + random() % 26);
}

// 传的是一个结构体变量  效率比较低, 一般建议传结构体指针
int stu_show(struct stu_t stu)
{
    printf("id:  %d  name: %s\n", stu.id, stu.name);
}

int main(void)
{

    struct stu_t *p;

    p = stu_alloc(1 * sizeof(struct stu_t));

    srandom(time(NULL));

    //随机赋值
    stu_random(p);
    stu_show(*p);

    free(p);
    return 0;
}

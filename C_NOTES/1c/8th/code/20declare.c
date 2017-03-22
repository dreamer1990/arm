#include <stdio.h>

typedef struct B B_t;  //前向声明

//错误：字段 ‘b’ 的类型不完全
struct A{
    int a;
    int c;
    B_t *bb; //在它之前 B_t一定要先定义
    //struct B bbb;
};
struct B {
    int aa;
    int bb;
};

struct C{
    int a;
    int b;
    struct C *next; //只是预分配4个字节给next
};




int main(void)
{
    struct A aaaa;
    return 0;
}

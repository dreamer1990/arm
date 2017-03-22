#include <stdio.h>

struct s_t {
    int i;          //4
    char j;         //1
    float k;        //4
    double d;       //8
    char name[32];  //32
};

int main(void)
{

    struct s_t s;
    void *p = NULL;
    
    unsigned long offset = 0;


    printf("&s:   %p\n", &s);


    p = &s.k;
    printf("p = %p\n", p);

    //struct s_t *tmp = NULL;
    //tmp = (struct s_t*)0  将0地址强制转换为struct s_t* 类型
    //&tmp->k       计算k的地址
    //地址只能强制转换为unsigned long 类型  否则出现警告
    offset =  (unsigned long)(&((struct s_t*)0)->k);

    printf("offset:  %u\n", offset);

    //段错误 访问地址非法
    //((struct s_t *)0)->k = 3.14;

    
    printf("p - offset:  %p\n", p - offset);

    

    return 0;
}

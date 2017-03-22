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

    printf("sizeof(int):  %d\n", sizeof(int));
    printf("sizeof(char):  %d\n", sizeof s.j);
    printf("sizeof(float):  %d\n", sizeof(float));
    printf("sizeof(double):  %d\n", sizeof(double));
    printf("sizeof(name):  %d\n", sizeof(s.name));

    //56  8字节对齐
    printf("sizeof(struct s_t):  %d\n", sizeof(struct s_t));

    //打印各个成员的地址
    printf("&s:   %p\n", &s);

    printf("&s.i:  %p\n", &s.i);
    printf("&s.j:  %p\n", &s.j);
    printf("&s.k:  %p\n", &s.k);
    printf("&s.d:  %p\n", &s.d);
    printf("&s.name:  %p\n", s.name);

    //计算出偏移量
    printf("&s.k - &s = %d\n", (void*)&s.k - (void*)&s);




    return 0;
}

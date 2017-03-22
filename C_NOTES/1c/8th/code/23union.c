#include <stdio.h>

union data_t {
    char a;
    int b;
    long c;
};

void test(union data_t t)
{
    printf("========> t.a:  %d\n", t.a);
}

int main(void)
{
    union data_t d;
    //联合体指针变量
    union data_t *p;
    d.a = 120;

    p = &d;

    printf("d.a:  %d  p->a: %d\n", d.a, p->a);
    test(d);



    
    return 0;
}

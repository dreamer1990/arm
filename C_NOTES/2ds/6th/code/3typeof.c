#include <stdio.h>


/*
 * swap - swap value of @a and @b
 */
#define swap(a, b) \
	do { typeof(a) __tmp = (a); (a) = (b); (b) = __tmp; } while (0)


struct s_t{
    int i;
    int j;
    int k;
    char c;
};

int main(void)
{

    struct s_t s1 = {3, 4, 5, 'M'}, s2;

    int a  = 3;

    //与int b = 4;等价
    //typeof(a) 就是int类型
    typeof(a) b = 4;

    printf("a = %d  b = %d\n", a, b);


    //相同类型的结构体可以整体赋值
    s2 = s1;
    printf("i:  %d  j:  %d  k: %d c: %c\n", s1.i, s1.j, s1.k, s1.c);
    printf("i:  %d  j:  %d  k: %d c: %c\n", s2.i, s2.j, s2.k, s2.c);

    printf("sizeof(int):  %d\n", sizeof(typeof(a)));

    return 0;
}

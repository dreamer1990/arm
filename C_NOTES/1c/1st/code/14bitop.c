
#include <stdio.h>

/*
 *2.  a = 0x33445566; 将a的高4位置为0xa a的第4-7位置为0xf
 *3.  a = 0x0; 将第0,2,3,7位置为1
 *4.  a = 0xffffffff  将a的第4，7，9，12位置0
 *
 */

int main(void)
{
    int a = 0;
    a = 0x33445566;

    //将高4位清零
    a &=~(0xf << 28);
    a = a | (0xa << 28);
    //将第4－7位置为0xf
    a = a | (0xf << 4) ;

    printf("a = %p\n", a);

    a = 0;
    a = a | (1 | 1 << 2 | 1 << 3 | 1 << 7);
    printf("a = %p\n", a);

    //a = 0xffffffff  将a的第4，7，9，12位置0
    a = -1;
    a = a & (~(1 << 4 | 1 << 7 | 1 << 9 | 1 << 12));
    printf("a = %p\n", a);



    return 0;
}
    

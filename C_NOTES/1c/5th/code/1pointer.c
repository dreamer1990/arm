#include <stdio.h>


/*
 *    运算符：
 *    (1) ＆  取地址运算符。
 *        &a是变量a的地址
 *    (2) *  指针运算符（“间接访问”运算符）
 *        如果： p指向变量a，则*p就代表a。
 *        k=*p;       (把a的值赋给k)
 *        *p=1;       (把1赋给a)
 *
 */

/*
 * *指针运算符
 * &取地址运算符
 */


/*
 *    定义指针变量的一般形式为：
 *        类型  * 指针变量名;
 */

/*
 * 指针真可怕，使用要初始化
 * int *p = NULL;
 *
 * p  是int * 类型
 * *p 是int类型 
 * p 指向int类型
 */

int main(void)
{
    int a = 3;

    //p是指针变量   存放一个地址的变量, 变量p本身也有地址
    int *p = NULL;

    //类型决定类型之上的操作
    p = &a;

    //&a 变量a的地址
    printf("&a = %p a = %d\n", &a,  a);

    //&p是变量p的地址   p是指针变量的值
    printf("&p = %p  p = %p\n", &p, p);

    //*&a  ---->  a
    //*p 取p所指向的值
    printf("*p = %d  a = %d\n", *p, a);
    printf("*&a = %d\n  a = %d\n", *&a, a);

    return 0;
}

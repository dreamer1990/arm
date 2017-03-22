#include <stdio.h>

//变量的定义
//类型  变量名;

//只读变量的定义
//const 类型 变量名 = 值;
//类型 const 变量名 = 值;

int main(void)
{
    //只读变量一般要初始化
    const int a = 3;

    int const b = 4;

    int c = 3;
    // %d 打印整形类型  \n换行
    printf("a = %d  b = %d\n", a, b);

    //错误：向只读变量 ‘a’ 赋值 不能給只读变量赋值
    //a = 44;
    
    //是一个普通的变量
    c  = 88;
    printf("c = %d\n", c);

    return 0;
}

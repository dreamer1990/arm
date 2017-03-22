#include <iostream>
using namespace std;


/*
 *
 *    C语言没有提供逻辑型数据，关系表达式的值(真或假)分别用数值1和0代表。C++增加了逻辑型数据。逻辑型常量只有两个，即false(假)和true(真)。
 *    逻辑型变量要用类型标识符bool来定义，它的值只能是true和false之一。如
 *    bool found,flag=false;       //定义逻辑变量found和flag，并使flag的初值为false
 *    found=true;                  //将逻辑常量true赋给逻辑变量found
 *    由于逻辑变量是用关键字bool来定义的，因此又称为布尔变量。逻辑型常量又称为布尔常量。所谓逻辑型，就是布尔型。
 *    
 *    在编译系统处理逻辑型数据时，将false处理为0，将true处理为1。因此，逻辑型数据可以与数值型数据进行算术运算。
 *    如果将一个非零的整数赋给逻辑型变量，则按“真”处理，如
 *    flag=123;                      //赋值后flag的值为true
 *    cout<<flag;
 *    输出为数值1。
 *
 *
 */

int main(void)
{
    bool b1 = true;
    bool b2 = false;
    int a = 33;

    //逻辑真 输出结果为1
    cout << "b1 = " << b1 << endl;
    //逻辑假 输出结果为0
    cout << "b2 = " << b2 << endl;
    //布尔变量可以参与算数运算
    a = a + b1;
    cout << "a = " << a << endl;

    return 0;
}

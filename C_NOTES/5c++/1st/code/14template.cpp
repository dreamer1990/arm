#include <iostream>
using namespace std;


/*
 *    
 *14. 函数的模板
 *    
 *    C++提供了函数模板(function template)。所谓函数模板，实际上是建立一个通用函数，其函数类型和形参类型不具体指定，用一个虚拟的类型来代表。这个通用函数就称为函数模板。凡是函数体相同的函数都可以用这个模板来代替，不必定义多个函数，只需在模板中定义一次即可。在调用函数时系统会根据实参的类型来取代模板中的虚拟类型，从而实现了不同函数的功能。
 *    
 *    定义函数模板的一般形式为 
 *    template < typename T>  或  template <class T>
 *    通用函数定义                          通用函数定义
 *    
 */

//max是系统一个函数 因此一般要尽量避免与系统函数名同名

//template一定要与函数模板一起使用  T1代表一个虚拟类型 
template <typename T1>
T1 my_max(T1 x, T1 y)
{
    return x > y ? x : y;
}

int main(void)
{
    int x = 33;
    int y = 44;
    long l1 = 333, l2 = 444;
    float f1 = 3.14, f2 = 3.15926;

    //系统会自动识别类型 T1为int类型
    cout << "max(x, y) = " << my_max(x, y) << endl;
    //错误：对‘my_max(int&, long int&)’的调用没有匹配的函数
    //cout << "max(x, l1) = " << my_max(x, l1) << endl;
    //会自动识别T1为long
    cout << "max(l1, l2) = " << my_max(l1, l2) << endl;
    //自动识别T1为float类型
    cout << "max(f1, f2) = " << my_max(f1, f2) << endl;
    return 0;
}






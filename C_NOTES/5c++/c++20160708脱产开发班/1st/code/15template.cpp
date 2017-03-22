#include <iostream>

using namespace std;


#if 0
函数的模板
    
    C++提供了函数模板(function template)。所谓函数模板，实际上是建立一个通用函数，其函数类型和形参类型不具体指定，用一个虚拟的类型来代表。这个通用函数就称为函数模板。凡是函数体相同的函数都可以用这个模板来代替，不必定义多个函数，只需在模板中定义一次即可。在调用函数时系统会根据实参的类型来取代模板中的虚拟类型，从而实现了不同函数的功能。
    
    定义函数模板的一般形式为 
    template < typename T>  或  template <class T>
    通用函数定义                          通用函数定义
#endif

//前提是函数的实现必须一致  只是参数类型不一样
//template <class T>
template <typename T>
T add(T x, T y)
{
    return x + y;
}


int main(void)
{
    cout << "add(3, 4): " << add(3, 4) << endl;
    cout << "add(3.3, 4.4): " << add(3.3, 4.4) << endl;

    return 0;
}

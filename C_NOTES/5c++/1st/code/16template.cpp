#include <iostream>
using namespace std;



/*
 *    可以看到，用函数模板比函数重载更方便，程序更简洁。但应注意它只适用于函数的参数个数相同而类型不同，且函数体相同的情况，如果参数的个数不同，则不能用函数模板。
 *
 */

//函数模板  定义两个虚拟类型T1 T2
//typename 与 class是等价的  但是一般建议使用typename
//template <typename T1, typename T2>
//template <class T1, class T2>
template <typename T1, class T2>
T1 fun(T1 x, T1 y, T2 x2, T2 y2)
{
    cout << "x + y = " << x + y << endl;
    cout << "x2 + y2 = " << x2 + y2 << endl;

    return x + y;
}
//函数重载 与函数模板可以混用 但是参数的个数一定不能一样
int fun(int x, int y, int z)
{
    return x + y + z;
}

int main(void)
{
    int x = 3, y = 4;
    long x2 = 33, y2 = 44;

    cout << "return = " << fun(x, y, x2, y2) << endl;;
    
    cout << "fun(1, 2, 3) = " << fun(1, 2, 3) << endl;

    return 0;
}

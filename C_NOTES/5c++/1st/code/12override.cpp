#include <iostream>
using namespace std;


/*
 *
 *    C++允许用同一函数名定义多个函数，这些函数的参数个数和参数类型不同。这就是函数的重载(function overloading)。即对一个函数名重新赋予它新的含义，使一个函数名可以多用。
 *    
 *    参数的个数和类型可以都不同。但不能只有函数的类型不同而参数的个数和类型相同。
 *    
 *    在使用重载函数时，同名函数的功能应当相同或相近，不要用同一函数名去实现完全不相干的功能，虽然程序也能运行，但可读性不好，使人莫名其妙。
 *    
 *
 */

//参数个数相同  参数类型不一样
//函数的重载
int max(int x, int y)
{
    return x > y ? x : y;
}

long max(long x, long y)
{
    return x > y ? x : y;
}

double max(double x, double y)
{
    return x > y ? x : y;
}

int main(void)
{
    int i1 = 3, i2 = 4;
    long l1 = 33, l2 = 44;
    float f1 = 3.14, f2 = 3.33;

    cout << "max(3, 4): " << max(i1, i2) << endl;
    cout << "max(33, 44): " << max(l1, l2) << endl;
    cout << "max(3.14, 3.33): " << max(f1, f2) << endl;

    return 0;
}

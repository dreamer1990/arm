#include <iostream>

using namespace std;
    

#if 0
 函数的重载
    
    在编程时，有时我们要实现的是同一类的功能，只是有些细节不同。例如希望从3个数中找出其中的最大者，而每次求最大数时数据的类型不同，可能是3个整数、3个双精度数或3个长整数。程序设计者往往会分别设计出3个不同名的函数，其函数原型为：
    int max1(int a，int b, int c);              //求3个整数中的最大者
    double max2(double a，double b，double c);  //求3个双精度数中最大者
    long  max3(long a，long b，long c);      //求3个长整数中的最大者

    C++允许用同一函数名定义多个函数，这些函数的参数个数和参数类型不同。这就是函数的重载(function overloading)。即对一个函数名重新赋予它新的含义，使一个函数名可以多用。
    
    参数的个数和类型可以都不同。但不能只有函数的类型不同而参数的个数和类型相同。
    
    在使用重载函数时，同名函数的功能应当相同或相近，不要用同一函数名去实现完全不相干的功能，虽然程序也能运行，但可读性不好，使人莫名其妙。

#endif
    

//三个数中最大值
int max(int x, int y, int z)
{
    int max = -1;
    max = x > y ? x : y;
    max = max > z ? max : z;

    return max;
}

//两个数中最大值
int max(int x, int y)
{
    return x > y ? x : y;
}

//浮点类型的最大值
double max(double x, double y, double z)
{
    double max = -1;
    max = x > y ? x : y;
    max = max > z ? max : z;
    return max;
}

int main(void)
{
    cout << "max(3, 5): " << max(3, 5) << endl;
    cout << "max(3, 4, 5): " << max(3, 4, 5) << endl;
    cout << "max(3.3, 4.4, 5.5): " << max(3.3, 4.4, 5.5) << endl;

    return 0;
}

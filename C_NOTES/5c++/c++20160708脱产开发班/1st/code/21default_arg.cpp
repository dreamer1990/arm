#include <iostream>

using namespace std;

#if 0
    在使用带有默认参数的函数时有两点要注意：
    (1) 如果函数的定义在函数调用之前，则应在函数定义中给出默认值。如果函数的定义在函数调用之后，则在函数调用之前需要有函数声明，此时必须在函数声明中给出默认值，在函数定义时可以不给出默认值(如例4.8)。
    (2) 一个函数不仅既作为重载函数，又作为有默认参数的函数。因为当调用函数时如果少写一个参数，系统无法判定是利用重载函数还是利用默认参数的函数，出现二义性，系统无法执行。
    
#endif

//函数声明
int add(int x = 3, int y = 4);
//在声明的时候不指定默认值
int sub(int x, int y);


int main(void)
{
    cout << "add(): " << add() << endl;
    cout << "add(1): " << add(1) << endl;
    cout << "add(1, 2): " << add(1, 2) << endl;

    //如果在声明的时候没有指定默认值 即使在后面定义指定了默认值  则该函数的默认值无效
    //cout << "sub(): " << sub() << endl;
    cout << "sub(10, 2): " << sub(10, 2) << endl;
    return 0;
}

//函数定义
//如果声明和定义指定的默认参数不一致 则报错
//int add(int x = 5, int y = 5)
//如果在声明中指定了默认值  那么在定义的时候不能指定默认值 否则报错
//int add(int x = 3, int y = 4)
int add(int x, int y)
{
    return x + y;
}

int sub(int x = 10, int y = 5)
{
    return x - y;
}



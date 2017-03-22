#include <iostream>

using namespace std;

//函数模板
//T1是自己命名的  临时的一个虚拟的类型
template <typename T1>
T1 add(T1 x, T1 y, T1 z)
{
    return x + y + z;
}


//函数定义
int add(int x, int y, int z)
{
    cout << "hello world" << endl;
    return x + y + z;
}

int main(void)
{
    int a = 3;
    int b = 4;
    int c = 5;

    double d1 = 3.3;
    double d2 = 4.4;
    double d3 = 5.5;

    //是调用的add  还是调用的模板的add
    //如果模板和普通函数同名了 则调用的时候优先调用普通函数
    cout << "add(a, b, c): " << add(a, b, c) << endl;

    cout << "add(d1, d2, d3): " << add(d1, d2, d3) << endl;
    return 0;
}


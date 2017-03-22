#include <iostream>

using namespace std;

//带有多个类型的函数模板
template <typename T1, typename T2>
T1 add(T1 x, T2 y)
{
    return x + T1(y);
}

int main(void)
{
    int a = 3;
    double b = 3.44444;

    cout << "add(a, b): " << add(a, b) << endl;
    

    cout << "add(b, a): " << add(b, a) << endl;

    return 0;
}

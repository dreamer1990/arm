#include <iostream>

using namespace std;

//引用:  别名

int main(void)
{
    int a = 3;;
    int c = 44;
    //引用必须在声明的时候初始化
    //初始化之后不能在更改..
    //b没有独立开辟空间  
    int &b = a;

    cout << "a = " << a << " b = " << b << endl;
    cout << "&a = "  << &a << "  &b = " << &b << endl;

    //a和b的存储空间相同
    b = 100;
    cout << "a = " << a << " b = " << b << endl;

    return 0;
}

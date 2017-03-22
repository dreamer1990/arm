#include <iostream>
using namespace std;

//namespace是关键字 ns1是命名空间名
namespace ns1
{
    //命名空间中的一些成员
    //a还是属于全局变量 
    int a = 32;
}

namespace ns2
{
    int a = 88;
}



#if 0
	2.2 使用命名空间成员的方法
	在引用命名空间成员时，要用命名空间名和作用域分辨符对命名空间成员进行限定，以区别不同的命名空间中的同名标识符。即
	命名空间名::命名空间成员名
#endif

int main(void)
{
    //访问第一个命名空间中的成员a
    cout << ns1::a << endl;
    //访问第二个命名空间的成员a
    cout << ns2::a << endl;

    return 0;
}

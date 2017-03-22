#include <iostream>
//使用标准命名空间
using namespace std;

#if 0
extern int a;
extern int a;
extern int a;
extern int b;
extern int b;
extern int b;
#endif

//全局变量
namespace ns1{
    int a = 3;
    int b = 4;
    namespace ns2{
        int a = 333;
        int b = 444;
    };
};

//全局变量
int a = 33;
int b = 44;

int main(void)
{

    cout << "a = " << a << "  b = " << b << endl;

    cout << "a = " << ns1::a << "  b = " << ns1::b << endl;

    cout << "a = " << ns1::ns2::a << "  b = " << ns1::ns2::b << endl;

    return 0;
}

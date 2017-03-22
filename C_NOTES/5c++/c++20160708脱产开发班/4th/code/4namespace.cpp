#include <iostream>
//使用标准命名空间
//using namespace std;
using std::cout;
using std::endl;

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
    //命名空间别名
    namespace S = ns1;

    cout << "a = " << a << "  b = " << b << endl;

    cout << "a = " << ns1::a << "  b = " << ns1::b << endl;

    cout << "a = " << ns1::ns2::a << "  b = " << ns1::ns2::b << endl;

    cout << "a = " << S::a << "  b = " << S::b << endl;

    //cout << "&S = " << &S << endl;
    return 0;
}

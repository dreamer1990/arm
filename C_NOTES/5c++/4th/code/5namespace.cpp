#include <iostream>

using namespace std;

//命名空间可以嵌套的
namespace s {
    //a可以同名
    int a;

    namespace s1
    {
        int a; 
    }

}

int main(void)
{

    s::a = 33;
    s::s1::a = 88;

    cout << "s::a " << s::a << endl;
    cout << "s::s1::a " << s::s1::a << endl;

    return 0;
}

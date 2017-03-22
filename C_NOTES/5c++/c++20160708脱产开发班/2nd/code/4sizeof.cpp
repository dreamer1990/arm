#include <iostream>
using namespace std;

class A{
public:
    void fun1(void)
    {
        cout << "fun1" << endl; 
    }

    void fun2(void)
    {
        cout << "fun2" << endl;
    }

private:
    int a;
    int b;
};

//空类
class B{


};


int main(void)
{

    A a;
    B b;

    //对象所占的空间就是数据成员所占的空间
    cout << "sizeof (class A): " << sizeof(A) << endl;
    cout << "sizeof (a): " << sizeof a << endl;
    //空类占用一个字节
    cout << "sizeof b: " << sizeof b << endl;

    return 0;
}

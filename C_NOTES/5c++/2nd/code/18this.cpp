#include <iostream>
using namespace std;

class A{
private:
    int n;
public:
    A(int n);
    ~A();
    void show(void);
    
};

//构造函数
A::A(int n)
{
    //不会报错 但是得不到预期结果
    //n = n;
    //this是指向当前对象的
    this->n = n;
    cout << "constructor called " << n << endl;
}

//析构函数
A::~A()
{
    cout << "destructor called " << n << endl;
}

//成员函数的定义
void A::show(void)
{
    cout << "this: " << this << endl;
    cout << "n = " << n << endl;
}

int main(void)
{
    A a(3);

    cout << "&a: " << &a << endl;
    a.show();
    return 0;
}

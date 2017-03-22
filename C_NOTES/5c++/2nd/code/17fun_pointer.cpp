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
    cout << "n = " << n << endl;
}

int main(void)
{
    A a(3);

/*
 *    定义指向公用成员函数的指针变量的一般形式为 
 *    数据类型名 (类名::*指针变量名)(参数表列)；
 *
 */
    void(A::*p)(void) = NULL;

    a.show();   
    //错误：ISO C++ 不允许通过取已绑定的成员函数的地址来构造成员函数指针。请改用‘&A::show’
    //p = &a.show;

/*
 *
 *    使指针变量指向一个公用成员函数的一般形式为 
 *    指针变量名=&类名∷成员函数名;
 *
 */
    p = &A::show;
    (a.*p)();


    return 0;
}

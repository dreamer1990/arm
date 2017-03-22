#include <iostream>
using namespace std;

//多级继承
class A{
public:
    A();
    A(int);
    ~A();
    void show(void);
private:
    int a;
};

//B公有继承A
class B:public A
{
public:
    B();
    B(int, int);
    ~B();
    void show(void);
private:
    int b;
};

class C:public B
{
public:
    C();
    C(int, int, int);
    ~C();
    void show(void);
private:
    int c;
};

//C类中相关定义
C::C():B()
{
    c = 0;
    cout << "C constructor" << endl;
}

C::C(int _a, int _b, int _c):B(_a, _b), c(_c)
{
    cout << "C constructor" << endl;
}

//析构函数
C::~C()
{
    cout << "C destructor" << endl;
}


void C::show(void)
{
    B::show();
    cout << "c = " << c << endl;
}

//B类相关的操作
B::B():A()
{
   b = 0; 
   cout << "B constructor" << endl;
}

B::B(int _a, int _b):A(_a), b(_b)
{
   cout << "B constructor" << endl;
}

//析构函数
B::~B()
{
    cout << "B destructor" << endl;
}

void B::show(void)
{
    //调用A类中的成员函数
    A::show(); 
    cout << "b = " << b << endl;
}

//A类相关的一些定义
A::A()
{
    a = 0;
    cout << "A constructor" << endl;
}

A::A(int _a):a(_a)
{
    cout << "A constructor" << endl;
}

A::~A()
{
    cout << "A destructor" << endl;
}

void A::show(void)
{
    cout << "a = " << a << endl;
}

int main(void)
{

    //先执行基类的构造函数 然后执行派生类的构造函数
    //先构造的对象后析构
    C c(1, 2, 3);
    c.show();
    cout << "==================" << endl;
    c.B::show();
    cout << "==================" << endl;
    c.A::show();

    return 0;
}

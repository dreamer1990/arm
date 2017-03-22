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

class C
{
public:
    C();
    C(int);
    ~C();
    void show(void);
private:
    int c;
};

//B公有继承A
class B:public A
{
public:
    B();
    B(int, int, int);
    ~B();
    void show(void);
private:
    int b;
    //数据成员包含对象
    C c;
};

//C类中相关定义
C::C()
{
    c = 0;
    cout << "C constructor" << endl;
}

C::C(int _c):c(_c)
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
    cout << "c = " << c << endl;
}

//B类相关的操作
//注意：子对象的初始化
B::B():A(), c()
{
   b = 0; 
   cout << "B constructor" << endl;
}

//注意：子对象的初始化
B::B(int _a, int _b, int _c):A(_a), c(_c), b(_b)
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
    c.show();
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
    B b(1, 2, 3);
    b.show();

    B b1;
    b1.show();

    return 0;
}

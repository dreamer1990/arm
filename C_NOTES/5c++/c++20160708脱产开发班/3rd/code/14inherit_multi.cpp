#include <iostream>
using namespace std;

//A类
class A{
public:
    A();
    A(int);
    ~A();
    void show();

private:
    int a;
};

//B类
class B{
public:
    B();
    B(int);
    ~B();
    void show();

private:
    int b;
};

//C类  多重继承
//调用构造函数的顺序是根据派生类声明的顺序决定的
//class C:public A, public B
class C:public B, public A
{
public:
    C();
    C(int, int, int);
    ~C();
    void show();

private:
    int c;
};

//C类相关的操作
C::C():A(), B()
{
    c = 0;
    cout << "C constructor" << endl;
}

C::C(int _a, int _b, int _c):A(_a), B(_b), c(_c)
{
    cout << "C constructor" << endl;
}

C::~C()
{
    cout << "C destructor" << endl;
}

void C::show(void)
{
    A::show();
    B::show();
    cout << "c = " << c << endl;
}

//B 类相关的操作
B::B()
{
    b = 0;
    cout << "B constructor" << endl;
}

B::B(int _b)
{
    b = _b;
    cout << "B constructor" << endl;
}

B::~B()
{
    cout << "B destructor" << endl;
}

void B::show(void)
{
    cout << "b = " << b << endl;
}


//A 类相关的操作
A::A()
{
    a = 0;
    cout << "A constructor" << endl;
}

A::A(int _a)
{
    a = _a;
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
    C c(1, 2, 3);
    c.show();


    return 0;
}

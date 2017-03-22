#include <iostream>
using namespace std;

//多层继承

//基类
class Base
{
public:
    Base();
    Base(int _x);
    void show(void);
private:
    int x;
};

//A类继承Base类
class A:public Base
{
public:
    A();
    A(int _x, int _y);
    void show(void);
private:
    int y;
};

class B:public A
{
public:
    B();
    B(int _x, int _y, int _z);
    void show(void);
    
private:
    int z;
};

//基类相关操作
Base::Base()
{
    x = 0;
    cout << "Base constructor" << endl;
}

Base::Base(int _x)
{
    x = _x;
    cout << "Base constructor" << endl;
}

void Base::show(void)
{
    cout << "base x = " << x << endl;
}

//派生类A的操作

A::A():Base()
{
    y = 0;
    cout << "A constructor" << endl;
}

A::A(int _x, int _y):Base(_x)
{
    y = _y;
    cout << "A constructor" << endl;
}
void A::show(void)
{
    Base::show();
    cout << "A y = " << y << endl;
}

//派生类B的操作
B::B():A()
{
    z = 0;
    cout << "B constructor.." << endl;
}

B::B(int _x, int _y, int _z):A(_x, _y)
{
    z = _z;
    cout << "B constructor.." << endl;
}

void B::show(void)
{
    A::show();
    cout << "z = " << z << endl;

}

int main(void)
{

    B b(1, 2, 3);
    b.show();;


    return 0;
}


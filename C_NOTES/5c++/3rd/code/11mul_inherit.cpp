#include <iostream>
using namespace std;

//基类A
class A
{
public:
    A() { x = 0; cout << "A constructor" << endl;}
    A(int _x) {x = _x; cout << "A constructor" << endl;}
    ~A() {cout << "A destructor..." << endl;}
    void show(){cout << "x = " << x << endl;}
private:
    int x;
};

//基类B
class B
{
public:
    B() { y = 0; cout << "B constructor" << endl;}
    B(int _y) {y = _y; cout << "B constructor" << endl;}
    ~B(){cout << "B destructor" << endl;}
    void show(){cout << "y = " << y << endl;}
private:
    int y;
};

//基类的构造顺序与继承时写的顺序相关
//多重继承
class C:public B, public A
{
public:
    C();
    C(int , int , int );
    ~C();
    void show(void);
private:
    int z;
};

C::C():A(), B()
{
    z = 0;
    cout << "C constructor." << endl;
}

C::C(int _x, int _y, int _z):A(_x), B(_y)
{
    z = _z;
    cout << "C constructor." << endl;
}

C::~C()
{
    cout << "C destructor.." << endl;
}

void C::show(void)
{
    A::show();
    B::show();
    cout << "z = " << z << endl;
}


int main(void)
{
    C c(1, 2, 3);
    c.show();

    return 0;
}


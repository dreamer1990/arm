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
public:
    int x;
};

//基类B
class B
{
public:
    B() { x = 0; y = 0; cout << "B constructor" << endl;}
    B(int _x, int _y) { x = _x; y = _y; cout << "B constructor" << endl;}
    ~B(){cout << "B destructor" << endl;}
    void show(){cout <<"x = " << x <<  " y = " << y << endl;}
public:
    int x;
    int y;
};

//基类的构造顺序与继承时写的顺序相关
//多重继承
class C:public B, public A
{
public:
    C();
    C(int , int , int , int);
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

C::C(int _x, int x1, int _y, int _z):A(_x), B(x1, _y)
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
    //A::show();
    //B::show();
    //对于X的访问有歧义  因为x在A和B中都存在
    //cout << "x = " << x << endl;
    //通过类名和域访问控制符可以消除歧义
    cout << "x = " << A::x << endl;
    cout << "x = " << B::x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
}


int main(void)
{
    C c(1, 2, 3, 4);
    c.show();

    return 0;
}


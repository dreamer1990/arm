#include <iostream>
using namespace std;

//基类
class A
{
public:
    A();
    A(int, int);
    void show(void);

protected:
    int x;
    int y;
};

//B继承A
class B:public A
{
public:
    B();
    B(int, int, int);
    void show(void);
protected:
    int z1;
};

//C继承A
class C:public A
{
public:
    C();
    C(int, int, int);
    void show(void);
protected:
    int z2;
};

//D类继承B 和C
class D:public B, public C
{
public:
    D();
    D(int _x, int _y, int _z1, int _z2, int _w);
    void show(void);
private:
    int w;
};

D::D():B(),C()
{
    w = 0;
    cout << "D constructor" << endl;
}

D::D(int _x, int _y, int _z1, int _z2, int _w):B(_x + 1, _y + 1, _z1), C(_x, _y, _z2)
{
    w = _w;
    cout << "D constructor" << endl;
}

void D::show(void)
{
    B::show();
    C::show();
    cout << "w = " << w << endl;
}



B::B():A()
{
    z1 = 0;
    cout << "B constructor" << endl;
}
B::B(int _x, int _y, int _z):A(_x, _y)
{
    z1 = _z;
    cout << "B constructor" << endl;
}

void B::show(void)
{
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z1 = " << z1 << endl;
}

C::C():A()
{
    z2 = 0;
    cout << "C constructor" << endl;
}
C::C(int _x, int _y, int _z):A(_x, _y)
{
    z2 = _z;
    cout << "C constructor" << endl;
}

void C::show(void)
{
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z2 = " << z2 << endl;
}


A::A()
{
    x = 0;
    y = 0;
    cout << "A constructor" << endl;
}

A::A(int _x, int _y)
{
    x = _x;
    y = _y;
    cout << "A constructor" << endl;
}

void A::show(void)
{
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}



int main(void)
{
    A a(3, 4);
    a.show();

    B b(1, 2, 3);
    b.show();

    C c(4, 5, 6);
    c.show();

    cout << "==========================" << endl;
    D d(1, 2, 3, 4, 5);
    d.show();


    return 0;
}

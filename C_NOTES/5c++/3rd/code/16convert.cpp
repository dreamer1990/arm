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
class B: virtual public A
{
public:
    B();
    B(int, int, int);
    void show(void);
protected:
    int z1;
};

//C继承A
class C:virtual public A
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

//初始化列表中没有直接基类的初始化 那么A类中的元素将不会被初始化
D::D(int _x, int _y, int _z1, int _z2, int _w):A(_x, _y), B(_x, _y, _z1), C(_x, _y, _z2)
{
    w = _w;
    cout << "D constructor" << endl;
}

void D::show(void)
{
    //排除了二义性
    //B::show();
    //C::show();
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;
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
/*
 *     
 *    (1) 派生类对象可以向基类对象赋值。
 *    可以用子类(即公用派生类)对象对其基类对象赋值。如
 *    A a1;              //定义基类A对象a1
 *    B b1;                //定义类A的公用派生类B的对象b1
 *    a1=b1;               //用派生类B对象b1对基类对象a1赋值
 *    在赋值时舍弃派生类自己的成员。实际上，所谓赋值只是对数据成员赋值，对成员函数不存在赋值问题。 
 *
 *    请注意: 赋值后不能企图通过对象a1去访问派生类对象b1的成员，因为b1的成员与a1的成员是不同的。假设age是派生类B中增加的公用数据成员，分析下面的用法:
 *    
 */

    //派生类
    B b(1, 2, 3); 
    //基类
    A a;

    b.show();
    cout << "=================" << endl;
    //将派生类赋值给基类
    a = b;
    a.show();

    //不能将基类赋值给派生类
    //b = a;

    return 0;
}






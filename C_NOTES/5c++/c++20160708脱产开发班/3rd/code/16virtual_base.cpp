#include <iostream>
using namespace std;


/*
 *
 *    注意: 在定义类D的构造函数时，与以往使用的方法有所不同。规定: 在最后的派生类中不仅要负责对其直接基类进行初始化，还要负责对虚基类初始化。
 *    C++编译系统只执行最后的派生类对虚基类的构造函数的调用，而忽略虚基类的其他派生类(如类B和类C) 对虚基类的构造函数的调用，这就保证了虚基类的数据成员不会被多次初始化。
 *
 */

//基类
class A{
public:
    A();
    A(int);
    ~A();
    void show1(void);

private:
    int a;
};

//派生类B 公有继承A
class B:virtual public A
{
public:
    B();
    B(int, int);
    ~B();
    void show(void);
private:
    int b;
};

//派生类C 公有继承A
class C:virtual public A
{
public:
    C();
    C(int, int);
    ~C();
    void show(void);
private:
    int c;
};

//派生类D
class D:public B, public C
{
public:
    D();
    D(int, int, int, int);
    ~D();
    void show(void);
private:
    int d;
};

D::D():B(), C()
{
    d = 0;
    cout << "D constructor" << endl;
}

//直接基类要单独初始化  因为B和C是虚继承 B和C不会初始化直接基类
D::D(int _a, int _b, int _c, int _d):A(_a), B(_a, _b), C(_a, _c),d(_d)
{
    cout << "D constructor" << endl;
}

D::~D()
{
    cout << "D destructor" << endl;
}
void D::show(void)
{
    B::show();
    C::show();
    cout << "d = " << d << endl;
}

//////////////////////////////
C::C():A(), c(0)
{
    cout << "C constructor" << endl;
}

C::C(int _a, int _c):A(_a), c(_c)
{
    cout << "C constructor" << endl;
}

C::~C()
{
    cout << "C destructor" << endl;
}

void C::show(void)
{
    A::show1();
    cout << "c = " << c << endl;
}



B::B():A(), b(0)
{
    cout << "B constructor" << endl;
}

B::B(int _a, int _b):A(_a), b(_b)
{
    cout << "B constructor" << endl;
}

B::~B()
{
    cout << "B destructor" << endl;
}

void B::show(void)
{
    A::show1();
    cout << "b = " << b << endl;
}

//A类的无参构造函数
A::A()
{
    a = 0;
    cout << "A constructor" << endl;
}
//A类的带参数的构造函数
A::A(int _a):a(_a)
{
    cout << "A constructor" << endl;
}

A::~A()
{
    cout << "A destructor" << endl;
}
//A类的成员函数
void A::show1(void)
{
    cout << "a = " << a << endl;
}


int main(void)
{
    D d(1, 2, 3, 4);
    d.show();
    //通过作用域访问符来消除二义性问题
    //A类有两份拷贝 出现浪费空间
    //在15代码中 会出现二义性问题  使用虚基类就不会出现二义性问题
    //d.B::show1();
    //d.C::show1();
    d.show1();

    return 0;
}

#include <iostream>
using namespace std;


/*
 *
 *    多重继承可以反映现实生活中的情况，能够有效地处理一些较复杂的问题，使编写程序具有灵活性，但是多重继承也引起了一些值得注意的问题，它增加了程序的复杂度，使程序的编写和维护变得相对困难，容易出错。其中最常见的问题就是继承的成员同名而产生的二义性(ambiguous)问题。
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

//派生类C 公有继承A
class C:public A
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
    void show(void);
private:
    int d;
};

D::D():B(), C()
{
    d = 0;
    cout << "D constructor" << endl;
}

D::D(int _a, int _b, int _c, int _d):B(_a, _b), C(_a, _c),d(_d)
{
    cout << "D constructor" << endl;
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
    d.B::show1();
    d.C::show1();

    return 0;
}

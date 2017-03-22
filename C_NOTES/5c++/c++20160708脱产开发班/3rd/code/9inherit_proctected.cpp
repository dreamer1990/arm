#include <iostream>
using namespace std;

#if 0

8. 保护成员和保护继承

	由protected声明的成员称为“受保护的成员”，或简称“保护成员”。从类的用户角度来看，保护成员等价于私有成员。但有一点与私有成员不同，保护成员可以被派生类的成员函数引用。

	如果基类声明了私有成员，那么任何派生类都是不能访问它们的，若希望在派生类中能访问它们，应当把它们声明为保护成员。如果在一个类中声明了保护成员，就意味着该类可能要用作基类，在它的派生类中会访问这些成员。

	在定义一个派生类时将基类的继承方式指定为protected的，称为保护继承，用保护继承方式建立的派生类称为保护派生类(protected derived class)，其基类称为受保护的基类(protected base class)，简称保护基类。

	保护继承的特点是: 保护基类的公用成员和保护成员在派生类中都成了保护成员，其私有成员仍为基类私有。也就是把基类原有的公用成员也保护起来，不让类外任意访问。

#endif


//基类  父类
class Base{
public:
    Base();
    Base(int);
    void show(void);

//受保护的成员
protected:
    int a;
};

//保护继承
class B: protected Base{
public:
    B();
    B(int, int);
    void show1(void);
private:
    int b;
};

B::B()
{
    //调用基类的构造函数
    //Base();
    //a是保护成员  通过保护继承 派生类可以访问保护数据成员
    a = 0;
    b = 0;
}
B::B(int _a, int _b):Base(_a)
{
    b = _b;
}

void B::show1(void)
{
    //show();  
    cout << "a = " << a;
    cout << "  b = " << b << endl;
}

//构造函数
Base::Base()
{
    a = 0;
}

Base::Base(int _a)
{
    a = _a;
}

//成员函数的定义
void Base::show(void)
{
    cout << "a = " << a << endl;
}

int main(void)
{
    Base b(3);
    B b1(1, 2);

    b.show();
    cout << "==================" << endl;

    b1.show1();
    //show是基类中的公有成员  但是派生类是通过保护继承  所以基类中公有成员成为派生类中的保护成员 保护成员不能在类外被访问
    //b1.show();

    return 0;
}

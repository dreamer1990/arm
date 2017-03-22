#include <iostream>
using namespace std;

#if 0

    私有继承

	在声明一个派生类时将基类的继承方式指定为private的，称为私有继承，用私有继承方式建立的派生类称为私有派生类(private derived class) ，其基类称为私有基类(private base class)。

	私有基类的公用成员和保护成员在派生类中的访问属性相当于派生类中的私有成员，即派生类的成员函数能访问它们，而在派生类外不能访问它们。私有基类的私有成员在派生类中成为不可访问的成员，只有基类的成员函数可以引用它们。一个基类成员在基类中的访问属性和在派生类中的访问属性可能是不同的。

	由于私有派生类限制太多，使用不方便，一般不常使用。

#endif


//基类  父类
class Base{
public:
    Base();
    Base(int);
    void show(void);

private:
    int a;
};

//私有继承
class B:private Base{
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
    Base();
    //a是私有的 不能访问
    //a = 0;
    b = 0;
}
B::B(int _a, int _b):Base(_a)
{
    b = _b;
}

void B::show1(void)
{
    //因为私有继承  基类中的公有成员在派生类中是私有  派生类中私有成员可以被派生类中其他成员访问
    show();  
    cout << "b = " << b << endl;
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

    //调用派生类中的show1成员函数
    b1.show1();
    //调用基类中的show成员函数 因为是私有继承  基类中的公有成员在类外不可访问
    //b1.show();

    return 0;
}

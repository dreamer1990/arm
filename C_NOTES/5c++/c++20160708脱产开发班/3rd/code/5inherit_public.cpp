#include <iostream>
using namespace std;

#if 0
6. 公用继承 

	在定义一个派生类时将基类的继承方式指定为public的，称为公用继承，用公用继承方式建立的派生类称为公用派生类(public derived class)，其基类称为公用基类(public base class)。

	采用公用继承方式时，基类的公用成员和保护成员在派生类中仍然保持其公用成员和保护成员的属性，而基类的私有成员在派生类中并没有成为派生类的私有成员，它仍然是基类的私有成员，只有基类的成员函数可以引用它，而不能被派生类的成员函数引用，因此就成为派生类中的不可访问的成员。

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

//公有继承
class B:public Base{
public:
    B();
    B(int, int);
    void show1(void);
private:
    int b;
};

B::B()
{
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
    //基类中的公有成员在派生类中可以访问
    show();  
    //公有继承不能访问基类中的私有成员  因为基类私有成员在派生类中不可见
    //cout << "a = " << a << endl;
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

    //a是基类私有 派生类共有继承基类之后  基类中的私有成员在类外不能访问
    //cout << "b1.a = " << b1.a << endl;

    //调用派生类中的show1成员函数
    b1.show1();
    //调用基类中的show成员函数
    b1.show();



    return 0;
}

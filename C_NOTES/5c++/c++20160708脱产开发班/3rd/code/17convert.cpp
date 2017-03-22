#include <iostream>
using namespace std;

#if 0

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
    void show(void);
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

void B::show(void)
{
    //基类中的公有成员在派生类中可以访问
    Base::show();  
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
    Base a;

    B b(11, 22);
    b.show();
    cout << "=======================" << endl;
    //将派生类对象赋值给基类 不能通过基类去访问派生类中的公有成员
    a = b;
    a.show();

    cout << "=======================" << endl;
    //将基类赋值给派生类是不支持
    //b = a;
    return 0;
}

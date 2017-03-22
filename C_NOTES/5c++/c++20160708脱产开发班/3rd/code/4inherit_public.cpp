#include <iostream>
using namespace std;

#if 0
	声明派生类的一般形式为
	class 派生类名: ［继承方式］ 基类名
	{
	派生类新增加的成员
	} ;

	继承方式包括: public(公用的),private(私有的)和protected(受保护的)，此项是可选的，如果不写此项，则默认为private(私有的)。
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

    //调用派生类中的show1成员函数
    b1.show1();
    //调用基类中的show成员函数
    b1.show();

    cout << "=========================" << endl;
    cout << "sizeof(Base): " << sizeof(Base) << "  sizeof(B): "  << sizeof(B) << endl;


    return 0;
}

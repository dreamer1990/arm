#include <iostream>
using namespace std;

#if 0

25. 虚析构函数


	析构函数的作用是在对象撤销之前做必要的“清理现场”的工作。当派生类的对象从内存中撤销时一般先调用派生类的析构函数，然后再调用基类的析构函数。但是，如果用new运算符建立了临时对象，若基类中有析构函数，并且定义了一个指向该基类的指针变量。在程序用带指针参数的delete运算符撤销对象时，会发生一个情况: 系统会只执行基类的析构函数，而不执行派生类的析构函数。

#endif


//基类  父类
class Base{
public:
    Base();
    Base(int);
    virtual ~Base();
    virtual void show(void);

private:
    int a;
};

//公有继承
class B:public Base{
public:
    B();
    B(int, int);
    ~B();
    void show(void);
    void say(void);
private:
    int b;
};


B::B()
{
    //a是私有的 不能访问
    //a = 0;
    b = 0;
    cout << "B constructor" << endl;
}
B::B(int _a, int _b):Base(_a)
{
    b = _b;
    cout << "B constructor" << endl;
}

B::~B()
{
    cout << "B destructor" << endl;
}

void B::show(void)
{
    //基类中的公有成员在派生类中可以访问
    Base::show();  
    //公有继承不能访问基类中的私有成员  因为基类私有成员在派生类中不可见
    //cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

void B::say(void)
{
    cout << "hello world   boy" << endl;
}

//构造函数
Base::Base()
{
    a = 0;
    cout << "Base constructor" << endl;
}

Base::Base(int _a)
{
    a = _a;
    cout << "Base constructor" << endl;
}

Base::~Base()
{
    cout << "Base destructor" << endl;
}

//成员函数的定义
void Base::show(void)
{
    cout << "a = " << a << endl;
}

int main(void)
{
    Base *p = NULL;

    p = new B(11, 22);

    p->show();

    //调用析构函数
    delete p;
       
   return 0;
}

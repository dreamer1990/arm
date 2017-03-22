#include <iostream>
using namespace std;

#if 0

	(4) 派生类对象的地址可以赋给指向基类对象的指针变量，也就是说，指向基类对象的指针变量也可以指向派生类对象。

	通过本例可以看到: 用指向基类对象的指针变量指向子类对象是合法的、安全的，不会出现编译上的错误。但在应用上却不能完全满足人们的希望，人们有时希望通过使用基类指针能够调用基类和子类对象的成员。在下一章就要解决这个问题。办法是使用虚函数和多态性。

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
    void say(void);
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

void B::say(void)
{
    cout << "hello world   boy" << endl;
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
    Base a(88);
    B b(11, 11);

    Base *p1 = NULL;
    B *p2 = NULL;

    p1 = &a;
    p1->show();
    cout << "========================" << endl;
    //可以用基类指针指向派生类 但是不能访问派生类中新增加的公有成员
    p1 = &b;
    p1->show();
    // 错误：‘class Base’ 没有名为 ‘say’ 的成
    //p1->say();

    cout << "===================="  << endl;
    p2 = &b;
    p2->show();
    //错误：从类型 ‘Base*’ 到类型 ‘B*’ 的转换无效
    //p2 = &a;
        
   return 0;
}

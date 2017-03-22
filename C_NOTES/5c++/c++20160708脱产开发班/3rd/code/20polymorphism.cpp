#include <iostream>
using namespace std;

#if 0
	由虚函数实现的动态多态性就是: 同一类族中不同类的对象，对同一函数调用作出不同的响应。虚函数的使用方法是: 
	(1) 在基类用virtual声明成员函数为虚函数。这样就可以在派生类中重新定义此函数，为它赋予新的功能，并能方便地被调用。
	在类外定义虚函数时，不必再加virtual。

	(2) 在派生类中重新定义此函数，要求函数名、函数类型、函数参数个数和类型全部与基类的虚函数相同，并根据派生类的需要重新定义函数体。

	C++规定，当一个成员函数被声明为虚函数后，其派生类中的同名函数都自动成为虚函数。因此在派生类重新声明该虚函数时，可以加virtual，也可以不加，但习惯上一般在每一层声明该函数时都加virtual，使程序更加清晰。
	如果在派生类中没有对基类的虚函数重新定义，则派生类简单地继承其直接基类的虚函数。
	(3) 定义一个指向基类对象的指针变量，并使它指向同一类族中需要调用该函数的对象。
	(4) 通过该指针变量调用此虚函数，此时调用的就是指针变量指向的对象的同名函数。

#endif


//基类  父类
class Base{
public:
    Base();
    Base(int);
    ~Base();
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

//公有继承
class C:public Base{
public:
    C();
    C(int, int);
    ~C();
    void show(void);
    void say(void);
private:
    int b;
};

C::C()
{
    //a是私有的 不能访问
    //a = 0;
    b = 0;
    cout << "C constructor" << endl;
}
C::C(int _a, int _b):Base(_a)
{
    b = _b;
    cout << "C constructor" << endl;
}

C::~C()
{
    cout << "C destructor" << endl;
}

void C::show(void)
{
    //基类中的公有成员在派生类中可以访问
    Base::show();  
    //公有继承不能访问基类中的私有成员  因为基类私有成员在派生类中不可见
    //cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "hello uplooking" << endl;
}


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

    B b(11, 22);
    C c(88, 88);
    b.show();
    cout << "========================" << endl;

    p = &b;
    p->show();
    cout << "========================" << endl;

    p = &c;
    p->show();

       
   return 0;
}

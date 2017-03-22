#include <iostream>
using namespace std;


#if 0
	纯虚函数是在声明虚函数时被“初始化”为0的函数。声明纯虚函数的一般形式是
	virtual 函数类型 函数名 (参数表列) =0;

	注意: 
        ① 纯虚函数没有函数体；
        ② 最后面的“=0”并不表示函数返回值为0，它只起形式上的作用，告诉编译系统“这是纯虚函数”; 
        ③ 这是一个声明语句，最后应有分号。


 26.2 抽象类

	如果声明了一个类，一般可以用它定义对象。但是在面向对象程序设计中，往往有一些类，它们不用来生成对象。定义这些类的惟一目的是用它作为基类去建立派生类。它们作为一种基本类型提供给用户，用户在这个基础上根据自己的需要定义出功能各异的派生类。用这些派生类去建立对象。

	一个优秀的软件工作者在开发一个大的软件时，决不会从头到尾都由自己编写程序代码，他会充分利用已有资源(例如类库)作为自己工作的基础。
	这种不用来定义对象而只作为一种基本类型用作继承的类，称为抽象类(abstract class)，由于它常用作基类，通常称为抽象基类(abstract base class)。

	凡是包含纯虚函数的类都是抽象类。因为纯虚函数是不能被调用的，包含纯虚函数的类是无法建立对象的。抽象类的作用是作为一个类族的共同基类，或者说，为一个类族提供一个公共接口。

#endif

//抽象类  抽象类一般作为基类
class A{
public:
    A(){a = 0; cout << "A constructor" << endl;}
    A(int _a):a(_a) {cout << "A constructor" << endl;} 
    ~A() {cout << "A destructor" << endl;}
    //纯虚函数
    virtual void show(void) = 0;  
protected:
    int a;
};


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

B::B():A()
{
    b = 0;
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
    cout << "a = "  << a << " b = " << b << endl;
}

int main(void)
{
    //错误：不能将变量 ‘a’ 声明为具有抽象类型 ‘A’
    //抽象类不能定义对象
    //A a; 

    B b(1, 2);
    b.show();
    return 0;
}

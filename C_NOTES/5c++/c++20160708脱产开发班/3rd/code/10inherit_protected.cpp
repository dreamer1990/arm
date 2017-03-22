#include <iostream>
using namespace std;

//类A
class A{
public:
    A(int);
    void show(void);
protected:
    int a;
};

//B类共有继承A类
class B:protected A
{
public:
    B(int, int);
    void show(void);
protected:
    int a;
};

B::B(int _a, int _b):A(_a)
{
    //构造函数必须调用构造函数初始化
    //A::a = _a;
    a = _b; 
}

//如果派生类中的共有成员函数与基类中的共有成员函数同名 那么基类中的会被隐藏
void B::show(void)
{
    //如果要调用基类中的同名成员函数 必须要使用作用域限定符
    //A::show();
    cout << "a = " << A::a << "  ";
    cout << "a = " << a << endl;
}

A::A(int a)
{
    //这种情况没有给成员变量赋值
   //a = a; 
   this->a = a;
}

void A::show(void)
{
    cout << "a = " << a << endl;
}



int main(void)
{
    A a(10);
    a.show();
    cout << "========================" << endl;

    B b(1, 2);
    b.show();

    return 0;
}

#include <iostream>
using namespace std;

#if 0
	(2) 派生类对象可以替代基类对象向基类对象的引用进行赋值或初始化。
	如已定义了基类A对象a1，可以定义a1的引用变量:
	A a1;           //定义基类A对象a1
	B b1;                //定义公用派生类B对象b1
	A& r=a1;             //定义基类A对象的引用变量r，并用a1对其初始化
	这时，引用变量r是a1的别名，r和a1共享同一段存储单元。也可以用子类对象初始化引用变量r，将上面最后一行改为
	A& r=b1;//定义基类A对象的引用变量r，并用派生类B对象b1
	//对其初始化
	或者保留上面第3行“A& r=a1;”，而对r重新赋值：
	r=b1;//用派生类B对象b1对a1的引用变量r赋值

	注意: 此时r并不是b1的别名，也不与b1共享同一段存储单元。它只是b1中基类部分的别名，r与b1中基类部分共享同一段存储单元，r与b1具有相同的起始地址

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

    Base &a2 = b;

    // 错误：将类型为 ‘B&’ 的引用初始化为类型为 ‘Base’ 的表达式无效
    //B &b2 = a;

    //引用  a1和a是指向同一个存储空间
    Base &a1 = a;
    cout << "&a = " << &a << "  &a1 = " << &a1 << endl;
    a1.show();
    a.show();
    cout << "======================" << endl;

    //基类的引用指向派生类  但是不能通过基类的引用去访问派生类的公有成员
    cout << "&a2 = " << &a2 << "  &b = " << &b << endl;
    //不能通过基类引用访问派生类的共有成员  a2只指向派生类的基类部分
    //a2.say();
    a2.show(); 

        
   return 0;
}

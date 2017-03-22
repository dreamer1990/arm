#include <iostream>
//栈相关的头文件
#include <stack>

using namespace std;


#if 0
标准模板库  模板类

    C++ Stacks（堆栈）
    C++ Stack（堆栈） 是一个容器类的改编，为程序员提供了堆栈的全部功能，——也就是说实现了一个先进后出（FILO）的数据结构。
    
    操作 比较和分配堆栈 
    empty() 堆栈为空则返回真 
    pop() 移除栈顶元素 
    push() 在栈顶增加元素 
    size() 返回栈中元素数目 
    top() 返回栈顶元素 
#endif

//学生类
class A
{
public:
    A();
    A(int _a, int _b);
    A(const A&);
    ~A();
    void show(void);
    void setAb(int _a, int _b);

private:
    int a;
    int b;
};

A::A()
{
    a = 0;
    b = 0;
    cout << "A constructor" << endl;
}

A::A(int _a, int _b):a(_a), b(_b)
{
    cout << "A constructor" << endl;
}

//拷贝构造函数
A::A(const A& a1)
{
    a  = a1.a;
    b = a1.b;
    cout << "copy constructor" << endl;
}

A::~A()
{
    cout << "A destructor" << endl;
}

void A::show(void)
{
    cout << "a = " << a << "  b = " << b << endl;
}

void A::setAb(int _a, int _b)
{
    a = _a;
    b = _b;
}

    

int main(void)
{
    
    A a;
    //stack是类模板
    stack<A> s;
    int i = 0;

    cout << "size: " << s.size() << endl;
    cout << "栈是否为空: " << s.empty() << endl;

    for (i = 0; i < 10; i++)
    {
        a.setAb(i + 1, i + 1);
        s.push(a);
    }
    cout << "压栈之后 size: " << s.size() << endl;
    cout << "栈是否为空: " << s.empty() << endl;

    a = s.top();
    a.show();
    cout << "压栈之后 size: " << s.size() << endl;
    cout << "======================" << endl;

    //弹栈
    while(!s.empty())
    {
        a = s.top();
        a.show();
        s.pop();
    }
    cout << endl;
    return 0;
}

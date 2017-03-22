#include <iostream>
//队列相关的头文件
#include <queue>

using namespace std;

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
    //queue是类模板
    queue<A> s;
    int i = 0;

    cout << "size: " << s.size() << endl;
    cout << "队列是否为空: " << s.empty() << endl;

    for (i = 0; i < 10; i++)
    {
        a.setAb(i + 1, i + 1);
        s.push(a);
    }
    cout << "入队列之后 size: " << s.size() << endl;
    cout << "队列是否为空: " << s.empty() << endl;

    a = s.front();
    a.show();
    cout << "返回队头元素之后 size: " << s.size() << endl;
    cout << "======================" << endl;

    //弹栈
    while(!s.empty())
    {
        a = s.front();
        a.show();
        s.pop();
    }
    cout << endl;
    return 0;
}

#include <iostream>
#include <list>
using namespace std;

class A{
public:
    A();
    A(int);
    ~A();
    void setA(int);
    void show(void);

private:
    int a;
};

A::A()
{
    a = 0;
    cout << "constructor" << endl;
}

A::A(int _a)
{
    a = _a;
    cout << "constructor" << endl;
}

A::~A()
{
    cout << "destructor" << endl;
}

void A::setA(int x)
{
    a = x;
}
void A::show(void)
{
    cout << a << endl;
}

void show(list<A> v)
{
    list<A>::iterator it;

    for (it = v.begin(); it != v.end(); it++)
    {
        it->show();  
    }
}

int main(void)
{
    int i = 0;
    A a(0);
    list<A> v; 

    for (i = 0; i < 10; i++)
    {
        a.setA(i + 1);
        v.push_back(a); 
    }

    show(v);

    return 0;
}

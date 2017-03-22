#include <iostream>
using namespace std;

class A{
private:
    int n;
public:
    A(int n = 0):n(n){cout << "constructor called " << n  << endl;};
    ~A(){cout << "destructor called " << n << endl;};
    void show(void) { cout << "n = " << n << endl;};
};

int main(void)
{
    //调用构造函数一次
    A *p = NULL;
    A a(1);

    //对象指针指向一个对象
    p = &a;

    a.show();
    p->show();
    (*p).show();
    

    return 0;
}

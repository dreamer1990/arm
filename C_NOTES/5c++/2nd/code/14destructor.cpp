#include <iostream>
using namespace std;

class A{
private:
    int n;
public:
    A(int n = 0):n(n){cout << "constructor called " << n  << endl;};
    ~A(){cout << "destructor called " << n << endl;};
};

int main(void)
{
    
    //先构造的  后析构

    //隐式的调用构造函数 所以构造函数不能是私有的
    A a(1);
    A b(2);
    A c(3);

    return 0;
}

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
    int i = 0;
    
    //先构造的  后析构

    //隐式的调用构造函数 所以构造函数不能是私有的
    //对象数组
    A arr[3] = {
        A(1),
        A(2),
        A(3),
    };

    for (i = 0; i < 3; i++)
    {
        arr[i].show(); 
    }

    return 0;
}

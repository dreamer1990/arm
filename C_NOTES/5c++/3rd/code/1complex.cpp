#include <iostream>
using namespace std;

//复数类
class Complex
{
public:
    Complex();
    Complex(int, int);
    void show(void);
    //实现两个复数相加
    Complex add(Complex &c);
private:
    int real;
    int image;
};

//构造函数
Complex::Complex()
{
    cout << "constructor...." << endl;
}

//带有参数的构造函数
Complex::Complex(int r, int i)
{
    real = r;
    image = i;
    cout << "constructor .." << endl;
}

//实现两个复数相加
Complex Complex::add(Complex &c)
{
    Complex t;

    t.real = real + c.real;
    t.image = image + c.image;

    return t;
}

//成员函数
void Complex::show(void)
{
    cout << real << " + " << image << "i" << endl;
}


int main(void)
{
    Complex c(1, 3);
    Complex d(2, 3);
    Complex e;
    c.show();
    d.show();
    //会调用拷贝构造函数
    e = c.add(d);
    e.show();


    return 0;
}

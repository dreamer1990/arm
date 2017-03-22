#include <iostream>
using namespace std;

//复数类
class Complex{
public:
    Complex();
    Complex(int, int);
    Complex(const Complex&);
    ~Complex();
    void show(void);
    Complex complexAdd(const Complex&);

private:
    int real;
    int image;
};

//类外定义成员函数
Complex::Complex()
{
    real = 0;
    image = 0;
    cout << "empty constructor" << endl;
}

Complex::Complex(int r, int i)
{
    real = r;
    image = i;
    cout << "arg constructor" << endl;
}

Complex::Complex(const Complex& c)
{
    real = c.real;
    image = c.image;
    cout << "copy constructor" << endl;
}

Complex::~Complex()
{
    cout << "destructor" << endl;
}

void Complex::show(void)
{
    cout << "(" << real << ", " << image << "i)" << endl;
}

//实现两个复数相加
Complex Complex::complexAdd(const Complex &c)
{
    Complex c1;    

    c1.real = real + c.real;
    c1.image = image + c.image;

    return c1;
}


int main(void)
{

    Complex c1(1, 1), c2(2, 2), c3;
    c1.show();
    c2.show();

    //实现两个复数相加
    c3 = c1.complexAdd(c2);
    c3.show();


    return 0;
}




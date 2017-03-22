#include <iostream>
using namespace std;


/*
 *    运算符重载的方法是定义一个重载运算符的函数，在需要执行被重载的运算符时，系统就自动调用该函数，以实现相应的运算。也就是说，运算符重载是通过定义函数实现的。运算符重载实质上是函数的重载。
 *    
 *    重载运算符的函数一般格式如下： 
 *    函数类型 operator 运算符名称 (形参表列)
 *    { 对运算符的重载处理 }
 *
 */

//复数类
class Complex{
public:
    Complex();
    Complex(int, int);
    Complex(const Complex&);
    ~Complex();
    void show(void);
    //重载运算符+
    friend Complex operator+(const Complex&, const Complex&);
    //重载运算符-
    friend Complex operator-(const Complex&, const Complex&);

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
Complex operator+(const Complex &c, const Complex &c2)
{
    Complex c1;    
    c1.real = c2.real + c.real;
    c1.image = c2.image + c.image;
    return c1;
}

//实现两个复数相减
Complex operator-(const Complex &c, const Complex &c2)
{
    Complex c1;    
    c1.real = c2.real - c.real;
    c1.image = c2.image - c.image;
    return c1;
}



int main(void)
{

    Complex c1(1, 1), c2(2, 2), c3;
    c1.show();
    c2.show();

    //实现两个复数相加
    c3 = c1 + c2;
    c3.show();

    //实现两个复数相减
    c3 = c2 - c1;
    c3.show();


    return 0;
}




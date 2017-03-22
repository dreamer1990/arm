#include <iostream>
using namespace std;


/*
 *    (1) C++不允许用户自己定义新的运算符，只能对已有的C++运算符进行重载。
 *
 *    (2） C++允许重载的运算符
 *    C++中绝大部分的运算符允许重载。
 *    不能重载的运算符只有5个： 
 *    .        (成员访问运算符)
 *    .*       (成员指针访问运算符)
 *    ∷       (域运算符)
 *    sizeof   (长度运算符)
 *    ?:       (条件运算符)
 *
 */

/*
 *
 *    重载运算符的函数一般格式如下： 
 *    函数类型 operator 运算符名称 (形参表列)
 *    { 对运算符的重载处理 }
 *
 */



//友元函数的方式重载

//复数类
class Complex
{
public:
    Complex();
    Complex(int, int);
    void show(void);
    //运算符重载 使用友元的方式
    friend Complex operator+(Complex c1, Complex c2);
    friend Complex operator-(Complex c1, Complex c2);
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

//返回一个对象
Complex operator+(Complex c1, Complex c2)
{
    Complex t;

    t.real = c1.real + c2.real;
    t.image = c1.image + c2.image;

    return t;
}

//返回一个对象
Complex operator-(Complex c1, Complex c2)
{
    Complex t;

    t.real = c1.real - c2.real;
    t.image = c1.image - c2.image;

    return t;
}

//成员函数
void Complex::show(void)
{
    cout << real << " + " << image << "i" << endl;
}


//	需要说明的是： 运算符被重载后，其原有的功能仍然保留，没有丧失或改变。
int main(void)
{
    Complex c(1, 3);
    Complex d(2, 3);
    Complex e;
    c.show();
    d.show();
    //重载运算符之后  增加了运算符的功能
    e = c + d;
    e.show();
    e = c - d;
    e.show();

    return 0;
}

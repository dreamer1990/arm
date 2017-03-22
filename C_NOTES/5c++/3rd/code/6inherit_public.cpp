#include <iostream>
using namespace std;

//点类
class Point
{
public:
    Point();
    Point(int , int);
    void show(void);

private:
    int x;
    int y;
};

//圆类
class Circle:public Point
{
public:
    Circle();
    Circle(int, int, int);
    void show(void);
    
private:
    int radis;
};


//构造函数
Point::Point()
{
    x = 0;
    y = 0;
    cout << "Point  constructor..." << endl;
}
//构造函数
Point::Point(int _x, int _y)
{
    x = _x;
    y = _y;

    cout << "Point constructor.." << endl;
}

//成员函数
void Point::show(void)
{
    cout << "(" << x << ", " << y << ")" << endl;
}

//圆的构造函数
Circle::Circle():Point()
{
    radis = 0;
    cout << "Circle construtor..." << endl;
}

Circle::Circle(int _x, int _y, int _r):Point(_x, _y)
{
    radis = _r;
    cout << "Circle construtor..." << endl;
}

//成员函数
void Circle::show(void)
{
    Point::show();
    cout << "r = " << radis << endl;
}


int main(void)
{

    Circle c(1, 2, 3);
    c.show();



    return 0;
}

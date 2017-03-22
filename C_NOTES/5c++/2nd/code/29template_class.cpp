#include <iostream>
using namespace std;


//类模板
//template <class T1>
template <typename T1>
class Compare
{
public:
    Compare();
    Compare(T1 _x, T1 _y);
    T1 max(void);
    T1 min(void);
private:
    T1 x;
    T1 y;
};

/*
 *
 *    (5) 如果在类模板外定义成员函数，应写成类模板形式： 
 *    template<class 虚拟类型参数>
 *    函数类型 类模板名<虚拟类型参数>::成员函数名(函数形参表列) {…}
 */

template <typename T1>
Compare<T1>::Compare()
{
    cout << "constructor ...." << endl;
}

template <typename T1>
Compare<T1>::Compare(T1 _x, T1 _y)
{
    x = _x;
    y = _y;
    cout << "constructor ...." << endl;
}

template <typename T1>
T1 Compare<T1>::max(void)
{
    return x > y ? x : y; 
}

template <typename T1>
T1 Compare<T1>::min(void)
{
    return x < y ? x : y; 
}

int main(void)
{
    Compare<int> c(3, 7);
    cout << "max(3, 7): " << c.max() << endl;
    cout << "min(3, 7): " << c.min() << endl;

    Compare<float> c1(3.3, 7.7);
    cout << "max(3.3, 7.7): " << c1.max() << endl;
    cout << "min(3.3, 7.7): " << c1.min() << endl;




    return 0;
}

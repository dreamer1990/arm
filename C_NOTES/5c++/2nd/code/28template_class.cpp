#include <iostream>
using namespace std;


//类模板
//template <class T1>
template <typename T1>
class Compare
{
public:
    Compare() {}
    Compare(T1 _x, T1 _y):x(_x), y(_y) {}
    T1 max(void)
    {
        return x > y ? x : y; 
    }
    T1 min(void)
    {
        return x > y ? y : x; 
    }
private:
    T1 x;
    T1 y;
};

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

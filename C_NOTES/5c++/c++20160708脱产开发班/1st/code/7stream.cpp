#include <iostream>
using namespace std;

/*
 *
 *    在用cout输出时，用户不必通知计算机按何种类型输出，系统会自动判别输出数据的类型，使输出的数据按相应的类型输出。如已定义a为int型，b为float型，c为char型，则
 *    cout << a << ′ ′ << b << ′ ′ << c << endl;
 *    会以下面的形式输出：
 *    4 345.789 a
 *
 */

int main(void)
{
    int a;
    char b;
    float c;


    //会自动识别
    cin >> a >> b >> c;

    cout << a << "  " << b << "  " << c << endl;



    return 0;
}

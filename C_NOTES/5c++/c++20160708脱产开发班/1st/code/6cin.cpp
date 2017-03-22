#include <iostream>
using namespace std;


#if 0
	cin语句的一般格式为
    	cin >> 变量1 >> 变量2 >> …… >> 变量n;

#endif

int main(void)
{
    int a, b, c;

    //第一种方式
    cin >> a >> b >> c;
    cout << a << " " << b << " " << c << endl;

    //第二种方式
    cin >> a
        >> b
        >> c;
    cout << a << " " << b << " " << c << endl;

    //第三种方式
    cin >> a;
    cin >> b;
    cin >> c;
    cout << a << " " << b << " " << c << endl;

    return 0;
}

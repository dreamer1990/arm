#include <iostream>
using namespace std;


int main(void)
{

    //true 1  false 0
    bool a = true;
    bool b = false;

    cout << "a = " << a << " b = " << b << endl;


    a = 3 > 10;
    b = 11 == 33;
    cout << "a = " << a << " b = " << b << endl;

    //非零为真   零为假
    a = 100;
    b = 0;
    cout << "a = " << a << " b = " << b << endl;

    return 0;
}

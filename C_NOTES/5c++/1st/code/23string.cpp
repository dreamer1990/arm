#include <iostream>
#include <string>

using namespace std;


int main(void)
{
    string str[3];
    string tmp;

    cin >> str[0] >> str[1] >> str[2];
    cout << str[0] << " " << str[1] << " " << str[2] << endl;

    //从小到大排序
    if (str[0] > str[1])
    {
        tmp = str[0]; 
        str[0] = str[1];
        str[1] = tmp;
    }

    if (str[0] > str[2])
    {
        tmp = str[0];
        str[0] = str[2];
        str[2] = tmp;
    }

    if (str[1] > str[2])
    {
        tmp = str[1]; 
        str[1] = str[2];
        str[2] = tmp;
    }

    cout  << "排序之后...\n";
    cout << str[0] << " " << str[1] << " " << str[2] << endl;

    return 0;
}

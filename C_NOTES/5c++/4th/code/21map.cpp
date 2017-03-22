#include <iostream>
#include <string>
#include <map>

using namespace std;


//遍历关联容器
void show(map<int, string> m)
{
    map<int, string>::iterator it;

    for (it = m.begin(); it != m.end(); it++)
    {
        cout << "( " << it->first << ", " << it->second << ")" << " ";
    }
    cout << endl;

}

//遍历关联容器
void show(map<int, string> m, int i)
{
    map<int, string>::reverse_iterator it;

    for (it = m.rbegin(); it != m.rend(); it++)
    {
        cout << "( " << it->first << ", " << it->second << ")" << " ";
    }
    cout << endl;

}
int main(void)
{

    pair<int, string> a[5] = {pair<int, string>(1, "aaaa"), pair<int, string>(2, "bbbb"), pair<int, string>(3, "ccccc"), pair<int, string>(4, "dddd"), pair<int, string>(5, "eeeee")};

    map<int, string> m1(&a[0], &a[5]);

    map<int, string> m;

    map<int, string> m2(m1);

    //键一定唯一 
    m[0] = "hello";
    m[1] = "hello1";
    m[2] = "hello2";
    m[3] = "hello3";
    m[4] = "hello4";
    m[5] = "hello5";
    //会覆盖以前  重复的键值
    m[5] = "hello0";
    m[6] = "hello5";


    show(m);
    show(m, 1);

    show(m1);
    cout << "=========================" << endl;
    show(m2);
    

    return 0;
}

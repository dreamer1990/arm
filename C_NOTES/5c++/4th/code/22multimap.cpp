#include <iostream>
#include <string>
#include <map>

using namespace std;


//遍历关联容器
void show(multimap<int, string> m)
{
    multimap<int, string>::iterator it;

    for (it = m.begin(); it != m.end(); it++)
    {
        cout << "( " << it->first << ", " << it->second << ")" << " ";
    }
    cout << endl;

}

//遍历关联容器
void show(multimap<int, string> m, int i)
{
    multimap<int, string>::reverse_iterator it;

    for (it = m.rbegin(); it != m.rend(); it++)
    {
        cout << "( " << it->first << ", " << it->second << ")" << " ";
    }
    cout << endl;

}
int main(void)
{

    //multimap允许重复的键值
    pair<int, string> a[6] = {pair<int, string>(1, "aaaa"), pair<int, string>(1, "aaaa"), pair<int, string>(2, "bbbb"), pair<int, string>(3, "ccccc"), pair<int, string>(4, "dddd"), pair<int, string>(5, "eeeee")};

    multimap<int, string> m1(&a[0], &a[6]);


    multimap<int, string> m2(m1);

    show(m1);
    cout << "=========================" << endl;
    show(m2);
    

    return 0;
}

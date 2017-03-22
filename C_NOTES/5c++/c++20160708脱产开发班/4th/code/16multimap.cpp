#include <iostream>
#include <string>
#include <map>
using namespace std;

void show(multimap<char, int> m)
{
    multimap<char, int>::iterator it; 

    for (it = m.begin(); it != m.end(); it++)
    {
        cout << "(" << it->first << " , " << it->second << " )" << endl;
    }
}

void show2(multimap<int , string> m)
{
    multimap<int, string>::iterator it; 

    for (it = m.begin(); it != m.end(); it++)
    {
        cout << "(" << it->first << " , " << it->second << " )" << endl;
    }
}


int main(void)
{
    
    //键值对
    multimap<char, int> m;
    multimap<int, string> m1;
#if 0
    //如果遇到重复的　　那么就会覆盖
    //键值必须唯一　并且键值排序
    m['a'] = 1;
    m['e'] = 5;
    m['c'] = 3;
    m['a'] = 2;
    m['d'] = 4;
    m['b'] = 2;
    show(m);
#endif

    m1.insert(m1.end(), pair<int, string>(1, "hello world1"));
    m1.insert(m1.end(), pair<int, string>(2, "hello world2"));
    m1.insert(m1.end(), pair<int, string>(3, "hello world3"));
    m1.insert(m1.end(), pair<int, string>(4, "hello world4"));

    show2(m1);

    //通过键删除
    m.erase('a');
    show(m);

    m1.erase(1);
    show2(m1);

    return 0;
}

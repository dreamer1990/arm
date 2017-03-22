#include <iostream>
#include <vector>
using namespace std;

//使用迭代器遍历容器
void show_v1(vector<int> v)
{
    //迭代器类型
    vector<int>::iterator it;
    //begin: 返回当前容器起始位置的迭代器
    //end: 返回当前容器的最后一个元素的下一个位置的迭代器
    for (it = v.begin(); it != v.end(); it++)
    {
        //vector中的迭代器可以直接解引用
        cout << *it << " ";
    }
    cout << endl;
}

int main(void)
{
    int i = 0;
    int size = 0;
    vector<char> ch;
    vector<char>::iterator it;

    vector<int> v(5, 100);
    vector<int> v1(10, 88);

    for (i = 0; i < 10; i++)
    {
        ch.push_back(65 + i); 
    }

    size = ch.size();

    for (i = 0; i < size; i++)
    {
        for (it = ch.begin(); it != ch.end(); it++) 
        {
            cout << *it; 
        }
        cout << endl;
    
        //移除最后一个元素 
        ch.pop_back(); 
    
    }
    
    cout << "======================" << endl;
    show_v1(v);
    show_v1(v1);

    cout << "======================" << endl;
    v.swap(v1);
    show_v1(v);
    show_v1(v1);
    
   return 0;
}

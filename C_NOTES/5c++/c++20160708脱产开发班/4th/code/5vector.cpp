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

//使用数组的方式 或者at函数遍历容器
void show(vector<int> v)
{
    int i = 0;
    for (i = 0; i < v.size(); i++)
    {
        //v[i]是不安全的方法 不做越界检查
        //cout << v[i] << " ";
        //v.at(i)返回指定位置的元素
        cout << v.at(i) << " ";
    }

    cout << endl;
}

int main(void)
{
    int i = 0;    
    vector<int> v;

    //向容器中追加元素
    for (i = 0; i < 20; i++)
    {
        v.push_back(i + 1); 
    }

    //show(v);
    show_v1(v);
    cout << "size: " << v.size() << endl;
    
    //back: 返回最后一个元素
    cout << "最后一个元素为: " << v.back() << endl;
    //front是返回第一个元素
    cout << "第一个元素为: " << v.front() << endl;
    //empty判断容器是否为空
    cout << "empty:  " << v.empty() << endl;

    cout << "=======================" << endl;
    //clear 清空所有的元素
    v.clear();
    cout << "是否为空: " << v.empty() << " 当前元素的个数: " << v.size() << endl;;

    return 0;
}

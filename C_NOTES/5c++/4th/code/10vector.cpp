#include <iostream>
#include <vector>
using namespace std;

//第一种遍历方法
void show(vector<int> v)
{
    int i = 0;
    
    for (i = 0; i < v.size(); i++)
    {
        //v[i]和v.at(i)是等价
        //cout << v[i] << " ";
        cout << v.at(i) << " ";
    }
    cout << endl;
}

//通过迭代器访问容器
void show(vector<int> v, int i)
{
    //定义迭代器类型的变量
    vector<int>::iterator it; 
    
    //begin: 是容器中的第一个位置
    //end: 是容器中的最后一个位置的下一个位置
    
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " "; 
    }
    cout << endl;
}

//通过迭代器访问容器
void show(vector<int> v, int i, int j)
{
    //定义迭代器类型的变量
    vector<int>::reverse_iterator it; 
    
    //begin: 是容器中的第一个位置
    //end: 是容器中的最后一个位置的下一个位置
    
    for (it = v.rbegin(); it != v.rend(); it++)
    {
        cout << *it << " "; 
    }
    cout << endl;
}

//通过迭代器访问容器
void const_show(vector<int> v, int i)
{
    //定义迭代器类型的变量
    vector<int>::const_iterator it; 
    
    //begin: 是容器中的第一个位置
    //end: 是容器中的最后一个位置的下一个位置
    
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " "; 
        //常量迭代器  不能改变指向的数据的值
        //*it = 88;
    }
    cout << endl;
}

int main(void)
{

    int i = 0;

    //vector是顺序容器 与以前的动态数组类似
    //调用默认的构造函数
    vector<int> v;

    for (i = 1; i < 11; i++)
    {
        //在尾部添加数据
        v.push_back(i); 
    }

    //size是计算容器的元素的个数
    cout << "size: " << v.size() << endl;
    //empty: 是判断容器是否为空
    cout << "empty: " << v.empty() << endl;

    show(v);
    show(v, 1);
    show(v, 1, 2);


    return 0;
}

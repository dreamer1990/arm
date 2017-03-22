#include <iostream>
#include <list>
using namespace std;

//通过迭代器访问容器
void show(list<int> v)
{
    //定义迭代器类型的变量
    list<int>::iterator it; 
    
    //begin: 是容器中的第一个位置
    //end: 是容器中的最后一个位置的下一个位置
    
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " "; 
    }
    cout << endl;
}

//通过迭代器访问容器
void show(list<int> v, int i, int j)
{
    //定义迭代器类型的变量
    list<int>::reverse_iterator it; 
    
    //begin: 是容器中的第一个位置
    //end: 是容器中的最后一个位置的下一个位置
    
    for (it = v.rbegin(); it != v.rend(); it++)
    {
        cout << *it << " "; 
    }
    cout << endl;
}

//通过迭代器访问容器
void const_show(list<int> v, int i)
{
    //定义迭代器类型的变量
    list<int>::const_iterator it; 
    
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

    //list是顺序容器 与以前的动态数组类似
    //调用默认的构造函数
    list<int> v;

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
    const_show(v, 1);
    show(v, 1, 2);


    return 0;
}

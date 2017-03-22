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

    int a[10] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 100};

    vector<int> v;

    //给容器赋值
    v.assign(&a[0], &a[10]);
    show(v);

    //erase 清除指定区间元素
    v.erase(v.begin());
    v.erase(v.end() - 1);
    show(v);

    //insert在指定位置插入一个数据
    v.insert(v.begin(), 222);
    v.insert(v.end(), 8888);
    show(v);

    v.insert(v.end(), &a[0], &a[6]);
    show(v);

    //clear: 清除所有的元素
    v.clear();
    cout << "size: " << v.size() << endl;
    cout << "empty: " << v.empty() << endl;

    return 0;
}






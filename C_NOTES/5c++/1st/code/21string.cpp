#include <iostream>
#include <string>

using namespace std;

/*
 *
 *    20.4 字符串变量的运算
 *    在以字符数组存放字符串时，字符串的运算要用字符串函数，如strcat(连接)、strcmp(比较)、strcpy(复制)，而对string类对象，可以不用这些函数，而直接用简单的运算符。
 *    (1) 字符串复制用赋值号
 *    string1=string2;
 *    其作用与“strcpy(string1,string2);”相同。
 *    (2) 字符串连接用加号
 *    string string1=″C++″;                   //定义string1并赋初值
 *    string string2=″Language″;               //定义string2并赋初值
 *    string1=string1 + string2;               //连接string1和string2
 *    连接后string1为″C++ Language″。
 *    (3) 字符串比较直接用关系运算符
 *    可以直接用 ==(等于)、>(大于)、<(小于)、!=(不等于)、>=(大于或等于)、<=(小于或等于)等关系运算符来进行字符串的比较。
 *    使用这些运算符比使用5.5.5节中介绍的字符串函数直观而方便。
 *    
 */

int main(void)
{
    string s1 = "hello world";
    string s2;

    //字符串赋值运算
    //将s1的值赋值给s2
    //调用一次new  退出的时候 调用依次delete
    s2 = s1;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;

    //字符串类不能使用字符串相关的函数
    //strcat(s1, "UPLOOKING");
    s1 = s1 + " Uplooking";
    cout << "s1 = " << s1 << endl;;
    //字符串变量可以直接用关系运算符比较两个字符串 
    if (s1 > s2)
        cout << "s1 > s2" << endl;
    else
        cout << "s1 <= s2" << endl;

    return 0;
}




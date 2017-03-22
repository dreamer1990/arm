#include <iostream>

using namespace std;



#if 0
    20.3 字符串变量的输入输出
    可以在输入输出语句中用字符串变量名，输入输出字符串，如
    cin >> string1;                 //从键盘输入一个字符串给字符串变量string1
    cout << string2;                //将字符串string2输出
    
    20.4 字符串变量的运算
    在以字符数组存放字符串时，字符串的运算要用字符串函数，如strcat(连接)、strcmp(比较)、strcpy(复制)，而对string类对象，可以不用这些函数，而直接用简单的运算符。
    (1) 字符串复制用赋值号
    string1=string2;
    其作用与“strcpy(string1,string2);”相同。
    (2) 字符串连接用加号
    string string1=″C++″;                   //定义string1并赋初值
    string string2=″Language″;               //定义string2并赋初值
    string1=string1 + string2;               //连接string1和string2
    连接后string1为″C++ Language″。
    
    (3) 字符串比较直接用关系运算符
    可以直接用 ==(等于)、>(大于)、<(小于)、!=(不等于)、>=(大于或等于)、<=(小于或等于)等关系运算符来进行字符串的比较。
#endif
    

int main(void)
{
    string s1;
    string s2;

    //遇到空格 制表符 换行符  就认为输入结束
    cin >> s1;
    cout << "s1 = " << s1 << endl;
    cout << "============================"  << endl;
    //+被重载了 相当于strcat
    s1 += " uplooking";
    cout << "s1 = " << s1 << endl;
    //不支持-
    //s1 -= "uplooking";
    s2 = s1;
    cout << "s2 = " << s2 << endl;


    //关系运算符
    cout << "s1 == s2: " << (s1 == s2) << endl;
    cout << "s1 != s2: " << (s1 != s2) << endl;
    cout << "s1 > s2: " << (s1 > s2) << endl;
    cout << "AAA < AAAB: " << ("AAA" < "AAAB") << endl;

    return 0;
}







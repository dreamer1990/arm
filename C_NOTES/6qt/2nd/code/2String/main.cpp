#include <iostream>
#include <QString>
#include <QDebug>

using namespace std;


int main(void)
{
    int i = 0;
    cout << "hello world" << endl;
    QString str("Hello Uplooking");

    //size： 返回字符串中字符的个数
    for (i = 0; i < str.size(); i++)
    {
//        cout << str.at(i).toAscii();
        cout << str[i].toAscii();
    }
    cout << endl;

//    //迭代器
//    QString::iterator it;
//    for (it = str.begin(); it != str.end(); it++)
//    {
//           qDebug() << *it;

//    }

    QChar *s = str.data();
    //输出第一个字符
//    cout << s->toAscii()<< endl;
    while(!s->isNull())
    {
        cout << s->toAscii();
        s++;
    }
    cout << endl;

//    qDebug() << QString::fromAscii("hello uplooking");

    str = "3415678";
    cout << "int = " << str.toInt() << endl;
    str = "3.1415926";
    cout << "double = " << str.toDouble() + 1 << endl;

    return 0;
}

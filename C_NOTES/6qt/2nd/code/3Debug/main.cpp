#include <iostream>
#include <QDebug>
#include <QDate>
#include <QTime>

using namespace std;


int main(void)
{
//    QDebug dbg(QString("x = %d y = %d"));
    //调试函数  输出调试信息
    qDebug() << QDate::currentDate();
    qDebug() << QTime::currentTime();

    //默认换行 因此不用添加换行  类似于printf
    qDebug("hello world");
    qDebug("x = %d y = %d", 3, 4);

//    dbg << 3 << 4 << endl;


}

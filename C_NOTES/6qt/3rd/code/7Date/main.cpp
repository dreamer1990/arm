#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QDate>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "===========================";
    cout << "hello world" << endl;


    //空的对象
    QDate date;
    qDebug() << date;

    //获取当前的日期
    QDate date2 = QDate::currentDate();
    qDebug() << date2;

    //相关的方法
    qDebug() << date2.addYears(1);
    qDebug() << date2.addMonths(1);
    qDebug() << date2.addDays(1);

    //返回值
    qDebug() << "Year: " << date2.year();
    qDebug() << "Month: " << date2.month();
    qDebug() << "Day: " << date2.day();

    qDebug() << "DayofYear: " << date2.dayOfYear();

    //判断是否为润年
    qDebug() << "IsLeapYear: " << QDate::isLeapYear(date2.year());

    //longDayName
//    qDebug() << "longDayName: " << QDate::longDayName(2, QDate::DateFormat);
    qDebug() << "longDayName: " << QDate::longDayName(2, QDate::StandaloneFormat);

//    longMonthName
    qDebug() << "longMonthName: " << QDate::longMonthName(8);

    return a.exec();
}

#include <QtCore/QCoreApplication>
#include <QDateTime>
#include <QDate>
#include <QTime>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QDateTime dt = QDateTime::currentDateTime();

    qDebug() << dt;


    QDateTime *dt2 = new QDateTime(QDate::currentDate(), QTime::currentTime());
    qDebug() << dt2->toString();


    //返回日期
    qDebug() << dt2->date();

    //返回时间
    qDebug() << dt2->time();

//    return a.exec();
    return 0;
}

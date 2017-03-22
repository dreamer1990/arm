
#include <QtGui>

#include "digitalclock.h"

//! [0]
DigitalClock::DigitalClock(QWidget *parent)
    : QLCDNumber(parent)
{
    setSegmentStyle(Filled);

    //创建一个定时器
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    //启动定时器  每隔1秒触发超时信号
    timer->start(1000);

    //显示时间
    showTime();

    setWindowTitle(tr("Digital Clock"));
    resize(150, 60);
}
//! [0]

//! [1]
void DigitalClock::showTime()
//! [1] //! [2]
{
    QTime time = QTime::currentTime();
    //将时间转为字符串
    QString text = time.toString("hh:mm");
    if ((time.second() % 2) == 0)
        text[2] = ' ';
    display(text);
}
//! [2]

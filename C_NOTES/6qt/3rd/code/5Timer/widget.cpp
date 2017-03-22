#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lcdNumber->setDigitCount(8);

    timer = new QTimer(this);

    timer2 = new QTimer(this);
    //设置超时间隔
    timer2->setInterval(1000);

    connect(timer2, SIGNAL(timeout()), this, SLOT(timer2TimeOut()));
    //如果设置为真  则定时器只会启动一次
//    timer2->setSingleShot(true);
    timer2->start();

    //手动连接信号与槽
    connect(timer, SIGNAL(timeout()), this, SLOT(updateLCDNumber()));

    //启动定时器
//    timer->start(1000);

}

Widget::~Widget()
{
    delete timer;
    delete ui;
}

//自定义槽
void Widget::updateLCDNumber()
{
    ui->lcdNumber->display(QTime::currentTime().toString());
}

//开始
void Widget::on_pushButton_clicked()
{
    timer->start(1000);
    qDebug() << "IsActive: " << timer->isActive();
}

//停止
void Widget::on_pushButton_2_clicked()
{
    timer->stop();
    qDebug() << "IsActive: " << timer->isActive();
}

void Widget::timer2TimeOut()
{
    qDebug() << "Time out " << QTime::currentTime();
}

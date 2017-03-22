#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setScaledContents(true);

//    movie = new QMovie(":/image/cat.gif");
    movie = new QMovie(":/image/a.mng");
    ui->label->setMovie(movie);

    //设置动画的缓冲的模式
    movie->setCacheMode(QMovie::CacheAll);

    //返回当前动画的状态
    qDebug() << movie->state();

    //设置背景颜色
//    movie->setBackgroundColor(Qt::red);

    //多少帧
    qDebug() << "Frame Count: " << movie->frameCount();


    if (!movie->isValid())
    {
        qDebug() << "The movie is invalid";
    }
    else
        {
        qDebug() << "The movie is valid";
    }

    //播放动画
//    movie->start();

}

Widget::~Widget()
{
    delete ui;
}

//播放
void Widget::on_pushButton_clicked()
{
    movie->start();
}

//暂停
void Widget::on_pushButton_2_clicked()
{
    movie->setPaused(true);
}

//停止
void Widget::on_pushButton_3_clicked()
{
    movie->stop();
}

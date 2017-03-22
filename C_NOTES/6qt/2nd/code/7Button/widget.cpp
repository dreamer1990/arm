#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

//上
void Widget::on_pushButton_clicked()
{
    int x= ui->pushButton_5->x();
    int y = ui->pushButton_5->y();


    ui->pushButton_5->move(x, y - 5);
}

//下
void Widget::on_pushButton_2_clicked()
{
    int x= ui->pushButton_5->x();
    int y = ui->pushButton_5->y();


    ui->pushButton_5->move(x, y + 5);
}
//左
void Widget::on_pushButton_3_clicked()
{
    int x= ui->pushButton_5->x();
    int y = ui->pushButton_5->y();


    ui->pushButton_5->move(x - 5, y);
}

//右
void Widget::on_pushButton_4_clicked()
{
    int x= ui->pushButton_5->x();
    int y = ui->pushButton_5->y();


    ui->pushButton_5->move(x + 5, y);
}

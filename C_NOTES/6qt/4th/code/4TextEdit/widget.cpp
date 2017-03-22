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

//发送事件
void Widget::on_pushButton_clicked()
{
    QString str = ui->lineEdit->text();

    //清空
    ui->lineEdit->clear();
    //追加
    ui->textEdit->append(str);
}

void Widget::on_pushButton_2_clicked()
{
    ui->textEdit->paste();
}

void Widget::on_pushButton_3_clicked()
{
    ui->textEdit->copy();
}

#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置模式
    ui->lineEdit_2->setEchoMode(QLineEdit::PasswordEchoOnEdit);
}

Widget::~Widget()
{
    delete ui;
}

//提交动作
void Widget::on_pushButton_clicked()
{
    qDebug() << ui->lineEdit->text();
//    ui->lineEdit->clear();
}

//撤消
void Widget::on_pushButton_2_clicked()
{
    //清空
    ui->lineEdit->clear();
}

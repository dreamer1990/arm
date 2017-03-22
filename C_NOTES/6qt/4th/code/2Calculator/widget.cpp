#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置LineEdit
    ui->lineEdit->setInputMask("9999999999");
    ui->lineEdit_2->setInputMask("9999999999");



}

Widget::~Widget()
{
    delete ui;
}

//计算结果
void Widget::on_pushButton_clicked()
{
    int x = ui->lineEdit->text().toInt();
    int y = ui->lineEdit_2->text().toInt();
    QString str = "";

//    qDebug() << x << "  " << y << "  " << ui->comboBox->currentIndex();

    switch(ui->comboBox->currentIndex())
    {
        case 0: //+
            str += QString::number(x);
            str += "+";
            str += QString::number(y);
            str += "=";
            str += QString::number(x + y);
            qDebug() << str;

            ui->lineEdit_3->setText(str);
            break;
        case 1: // -
            str += QString::number(x);
            str += "-";
            str += QString::number(y);
            str += "=";
            str += QString::number(x - y);
            qDebug() << str;

            ui->lineEdit_3->setText(str);

            break;
        case 2: //*
            str += QString::number(x);
            str += "*";
            str += QString::number(y);
            str += "=";
            str += QString::number(x * y);
            qDebug() << str;

            ui->lineEdit_3->setText(str);

            break;
        case 3: // /
            str += QString::number(x);
            str += "/";
            str += QString::number(y);
            str += "=";
            str += QString::number(x / y);
            qDebug() << str;

            ui->lineEdit_3->setText(str);
            break;
        case 4: // %
            str += QString::number(x);
            str += "%";
            str += QString::number(y);
            str += "=";
            str += QString::number(x % y);
            qDebug() << str;

            ui->lineEdit_3->setText(str);
            break;
    }


}






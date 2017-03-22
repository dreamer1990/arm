#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

//    setSizePolicy(
//    ui->webView->load(QUrl("http://www.qq.com"));
//    ui->webView->show();

}

Widget::~Widget()
{
    delete ui;
}

//链接的操作
void Widget::on_pushButton_clicked()
{
    if (ui->lineEdit->text().isEmpty())
    {
        qDebug() << "The Url is invalid" ;
    }

    ui->webView->load(QUrl(ui->lineEdit->text()));
    ui->webView->show();
}

#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //使用本地的编码
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    ui->lineEdit_2->setFocus();
    //用户名是10个字符以内
    ui->lineEdit->setMaxLength(10);
    //设置提示
//    ui->lineEdit->setText(tr("请输入用户名"));

    ui->lineEdit_2->setMaxLength(10);
//    ui->lineEdit_2->setText(tr("请输入密码"));
    //设置回显模式
    ui->lineEdit_2->setEchoMode(QLineEdit::PasswordEchoOnEdit);

}

Widget::~Widget()
{
    delete ui;
}

//登录
void Widget::on_pushButton_clicked()
{
    QString user = ui->lineEdit->text();
    QString passwd = ui->lineEdit_2->text();

    if (user.isEmpty() || passwd.isEmpty())
    {
        qDebug() << tr("密码或者用户名为空");
        return;
    }

    if (user.compare("root") != 0)
    {
        qDebug() << tr("用户名错误");
        ui->lineEdit->clear();
        return;
    }

    if (passwd.compare("123456") != 0)
    {
        qDebug() << tr("密码错误");
        ui->lineEdit_2->clear();
        return;
    }

    //登录成功
    qDebug() << tr("登录成功");
    QMessageBox::information(this, "Information", tr("登录成功"));


}

//取消
void Widget::on_pushButton_2_clicked()
{
    //关闭登录窗口
    close();
}

#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

//关于对话框
void Dialog::on_pushButton_clicked()
{
    QMessageBox::about(this, "About ShenZhen", "This is ShenZhen");
}

//关于Qt对话框
void Dialog::on_pushButton_2_clicked()
{
    QMessageBox::aboutQt(this, "QT");
}
//critical
void Dialog::on_pushButton_3_clicked()
{
    QMessageBox::critical(this, "Error", "This is a critical error");
}

//information
void Dialog::on_pushButton_4_clicked()
{
    QMessageBox::information(this, "Info", "This is an information message");
}

//question
void Dialog::on_pushButton_5_clicked()
{
    QMessageBox::question(this, "Question", "This is in ShenZhen");
}

//Warning
void Dialog::on_pushButton_6_clicked()
{
    QMessageBox::warning(this, "Warn", "This is a dangerouse question");
}

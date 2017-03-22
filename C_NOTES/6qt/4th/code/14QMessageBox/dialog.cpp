#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    int ret = 0;

    ui->setupUi(this);

//    //消息对话框
//    mbox = new QMessageBox;
//    mbox->setText("This is a QMessageBox");
//    mbox->exec();


    mbox = new QMessageBox;
    mbox->setText("This is a MessageBox");
    mbox->setInformativeText("Do you want to save the change");
    mbox->setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    //设置默认的按钮
    mbox->setDefaultButton(QMessageBox::Save);
    ret = mbox->exec();

    switch(ret)
    {
        case QMessageBox::Save:
            qDebug() << "Save";
            break;
        case QMessageBox::Discard:
            qDebug() << "Discard";
            break;
        case QMessageBox::Cancel:
            qDebug() << "Cancel";
            break;
          default:
            qDebug() << "no choice";

    }

}

Dialog::~Dialog()
{
    delete ui;
}

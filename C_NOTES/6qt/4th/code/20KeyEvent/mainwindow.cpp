#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//按键按下事件
void MainWindow::keyPressEvent(QKeyEvent *e)
{
    qDebug() << "Press";

    switch(e->key())
    {
       case Qt::Key_A:
       case Qt::Key_Left:
            qDebug() << "Left";
            break;

       case Qt::Key_D:
       case Qt::Key_Right:
            qDebug() << "Right";
            break;

       case Qt::Key_W:
       case Qt::Key_Up:
            qDebug() << "Up";
            break;

       case Qt::Key_S:
       case Qt::Key_Down:
            qDebug() << "Down";
            break;
        case Qt::Key_Escape:
            close();
            break;
//        case Qt::Key_Up:
//            qDebug() << "  aaaa  Up";
//            break;
       default:
            qDebug() << "other";

    }

}

//按键释放事件
void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
    qDebug() << "Release";

    qDebug() << e->text();
}

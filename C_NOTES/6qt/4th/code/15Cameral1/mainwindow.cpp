#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Cam.Init_Cameral(W , H);
    Timer.setInterval(20);

    Cam.set_bmp_header((struct bmp_header_t *)RGB,W,H);
    connect(&Timer,SIGNAL(timeout()),this,SLOT(Timer_Slot()));
}

void MainWindow::Timer_Slot()
{

   Cam.Get_Picture_YUYV(YUV);
   Cam.yuyv2rgb24(YUV , RGB+54 , W , H);

    QPixmap Pixmap ;
    Pixmap.loadFromData(RGB,W*H*3+54);
    ui->label->setPixmap(Pixmap);
}

MainWindow::~MainWindow()
{
    Cam.Stop_Cameral();
    Cam.Exit_Cameral();
    delete ui;
}

void MainWindow::on_pushButtonStart_clicked()
{
    Cam.Start_Cameral();
    Timer.start();
}

void MainWindow::on_pushButtonPause_clicked()
{
    Timer.stop();
}

void MainWindow::on_pushButtonCapture_clicked()
{
    static int i = 0 ;
   Cam.Get_Picture_YUYV(YUV);
   Cam.yuyv2rgb24(YUV , RGB+54 , W , H);

    QString Str("Pic");
    Str.append(QString().number(i));
    QFile file(Str);
    file.open(QIODevice::ReadWrite);
    file.write((const char *)RGB,W*H*3+54);
    file.close();
    i++;
}

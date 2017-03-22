#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    sound = new QSound("/var/ftp/pub/weekend/6qt/4th/code/10Sound-build-desktop/Side_Right.wav");
    sound->play();

    qDebug() << sound->fileName();

    //检查设备是否存在  false
    qDebug() << "isAvailable:  " << sound->isAvailable();

    qDebug() << "Loops: " << sound->loops();

//    QSound::play("./Explosion.wav");



}

Widget::~Widget()
{
    delete ui;
}

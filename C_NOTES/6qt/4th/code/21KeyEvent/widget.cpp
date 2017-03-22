#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setScaledContents(true);

//    movie = new QMovie(":/image/cat.gif");
    movie = new QMovie(":/image/dog.gif");
    ui->label->setMovie(movie);

    movie->start();



}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *e)
{
    int x = ui->label->x();
    int y = ui->label->y();


    switch(e->key())
    {
        case Qt::Key_W:
        case Qt::Key_Up:
            y = y - 5;
            break;

        case Qt::Key_S:
        case Qt::Key_Down:
            y = y + 5;
            break;

        case Qt::Key_A:
        case Qt::Key_Left:
            x = x - 5;
            break;

        case Qt::Key_D:
        case Qt::Key_Right:
            x = x + 5;
            break;


        default:
            ;


    }

    ui->label->move(x, y);
}




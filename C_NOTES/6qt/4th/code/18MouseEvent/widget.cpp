#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}



//重写鼠标按下的事件
void Widget::mousePressEvent(QMouseEvent *e)
{
    //相对位置
    int x = e->x();
    int y = e->y();
    QString str = "";

    qDebug() << x << " " << y;

    str += "(";
    str += QString::number(x);
    str += " ,";
    str += QString::number(y);
    str += ")";

    ui->textEdit->append(str);

    //绝对位置
    qDebug() << e->globalPos();
    qDebug() << e->globalX();
    qDebug() << e->globalY();

}

//鼠标释放事件
void Widget::mouseReleaseEvent(QMouseEvent *e)
{

    qDebug() << e->button() << " Release";
}

//鼠标双击事件
void Widget::mouseDoubleClickEvent(QMouseEvent *e)
{
    qDebug() << e->buttons() << "Double clicked";
}

//鼠标移动事件
void Widget::mouseMoveEvent(QMouseEvent *e)
{
    qDebug() << e->buttons() << "Move";
}

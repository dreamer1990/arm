#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QDebug>

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QTimer *timer;
    QTimer *timer2;

private slots:
  void on_pushButton_2_clicked();
  void on_pushButton_clicked();
  void updateLCDNumber();
  void timer2TimeOut();

};

#endif // WIDGET_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDate>
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

private slots:
    void calendarShow( const QDate & date);
};

#endif // WIDGET_H

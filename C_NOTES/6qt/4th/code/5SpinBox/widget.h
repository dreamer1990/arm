#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
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
    void on_doubleSpinBox_valueChanged(double );
    void on_doubleSpinBox_editingFinished();
    void on_spinBox_valueChanged(int );
};

#endif // WIDGET_H

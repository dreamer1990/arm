#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

//公有槽
public slots:
    void setLabel(void);
    void setLabel1(void);
private:
    Ui::Widget *ui;

private slots:
    void on_pushButton_2_clicked();
};

#endif // WIDGET_H

#include "widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{


//    if (Widget->objectName().isEmpty())
//        Widget->setObjectName(QString::fromUtf8("Widget"));
//    Widget->resize(573, 407);
    widget = new QWidget(this);
    widget->setObjectName(QString::fromUtf8("widget"));
    widget->setGeometry(QRect(110, 50, 351, 231));
    verticalLayout = new QVBoxLayout(widget);
    verticalLayout->setSpacing(6);
    verticalLayout->setContentsMargins(11, 11, 11, 11);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalLayout->setContentsMargins(0, 0, 0, 0);
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setSpacing(6);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    label = new QLabel(widget);
    label->setObjectName(QString::fromUtf8("label"));
    QFont font;
    font.setPointSize(12);
    label->setFont(font);
    label->setText("Login");
    label->setScaledContents(false);
    label->setWordWrap(false);

    horizontalLayout->addWidget(label);

    lineEdit = new QLineEdit(widget);
    lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

    horizontalLayout->addWidget(lineEdit);


    verticalLayout->addLayout(horizontalLayout);

    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setSpacing(6);
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    label_2 = new QLabel(widget);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setFont(font);
    label_2->setText("PassWd");

    horizontalLayout_2->addWidget(label_2);

    lineEdit_2 = new QLineEdit(widget);
    lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

    horizontalLayout_2->addWidget(lineEdit_2);


    verticalLayout->addLayout(horizontalLayout_2);

    horizontalLayout_3 = new QHBoxLayout();
    horizontalLayout_3->setSpacing(6);
    horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
    horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout_3->addItem(horizontalSpacer_2);

    pushButton_2 = new QPushButton(widget);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
    pushButton_2->setFont(font);
    pushButton_2->setText("Login");

    horizontalLayout_3->addWidget(pushButton_2);

    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout_3->addItem(horizontalSpacer);

    pushButton = new QPushButton(widget);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setFont(font);
    pushButton->setText("Cancel");

    horizontalLayout_3->addWidget(pushButton);

    horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout_3->addItem(horizontalSpacer_3);


    verticalLayout->addLayout(horizontalLayout_3);
}

Widget::~Widget()
{

}

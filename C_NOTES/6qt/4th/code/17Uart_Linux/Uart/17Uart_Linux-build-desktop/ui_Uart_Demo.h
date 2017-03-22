/********************************************************************************
** Form generated from reading UI file 'Uart_Demo.ui'
**
** Created: Sun Oct 16 16:16:41 2016
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UART_DEMO_H
#define UI_UART_DEMO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Uart_Demo
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox_SlectCom;
    QComboBox *comboBox_BoartRate;
    QPushButton *pushButton_Connect;
    QPushButton *pushButton_Disconnect;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_SendContent;
    QPushButton *pushButton_Send;
    QTextBrowser *textBrowser_Log;
    QPushButton *pushButton_Clear;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Uart_Demo)
    {
        if (Uart_Demo->objectName().isEmpty())
            Uart_Demo->setObjectName(QString::fromUtf8("Uart_Demo"));
        Uart_Demo->resize(403, 414);
        centralWidget = new QWidget(Uart_Demo);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboBox_SlectCom = new QComboBox(centralWidget);
        comboBox_SlectCom->setObjectName(QString::fromUtf8("comboBox_SlectCom"));

        horizontalLayout->addWidget(comboBox_SlectCom);

        comboBox_BoartRate = new QComboBox(centralWidget);
        comboBox_BoartRate->setObjectName(QString::fromUtf8("comboBox_BoartRate"));

        horizontalLayout->addWidget(comboBox_BoartRate);

        pushButton_Connect = new QPushButton(centralWidget);
        pushButton_Connect->setObjectName(QString::fromUtf8("pushButton_Connect"));

        horizontalLayout->addWidget(pushButton_Connect);

        pushButton_Disconnect = new QPushButton(centralWidget);
        pushButton_Disconnect->setObjectName(QString::fromUtf8("pushButton_Disconnect"));
        pushButton_Disconnect->setEnabled(false);

        horizontalLayout->addWidget(pushButton_Disconnect);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit_SendContent = new QLineEdit(centralWidget);
        lineEdit_SendContent->setObjectName(QString::fromUtf8("lineEdit_SendContent"));
        lineEdit_SendContent->setEnabled(false);

        horizontalLayout_2->addWidget(lineEdit_SendContent);

        pushButton_Send = new QPushButton(centralWidget);
        pushButton_Send->setObjectName(QString::fromUtf8("pushButton_Send"));
        pushButton_Send->setEnabled(false);

        horizontalLayout_2->addWidget(pushButton_Send);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        textBrowser_Log = new QTextBrowser(centralWidget);
        textBrowser_Log->setObjectName(QString::fromUtf8("textBrowser_Log"));

        gridLayout->addWidget(textBrowser_Log, 2, 0, 1, 1);

        pushButton_Clear = new QPushButton(centralWidget);
        pushButton_Clear->setObjectName(QString::fromUtf8("pushButton_Clear"));

        gridLayout->addWidget(pushButton_Clear, 3, 0, 1, 1);

        Uart_Demo->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Uart_Demo);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 403, 17));
        Uart_Demo->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Uart_Demo);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Uart_Demo->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Uart_Demo);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Uart_Demo->setStatusBar(statusBar);

        retranslateUi(Uart_Demo);

        QMetaObject::connectSlotsByName(Uart_Demo);
    } // setupUi

    void retranslateUi(QMainWindow *Uart_Demo)
    {
        Uart_Demo->setWindowTitle(QApplication::translate("Uart_Demo", "Uart_Demo", 0, QApplication::UnicodeUTF8));
        comboBox_SlectCom->clear();
        comboBox_SlectCom->insertItems(0, QStringList()
         << QApplication::translate("Uart_Demo", "COM0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "COM1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "COM2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "COM3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "COM4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "COM5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "COM6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "COM7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "COM8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "COM9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "COM10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "COM11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "COM12", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "COM13", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "COM14", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "COM15", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "COM16", 0, QApplication::UnicodeUTF8)
        );
        comboBox_BoartRate->clear();
        comboBox_BoartRate->insertItems(0, QStringList()
         << QApplication::translate("Uart_Demo", "50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "75", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "110", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "134", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "150", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "300", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "1200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "1800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "2400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "4800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "9600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "14400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "19200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "38400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "56000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "57600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "76800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "115200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "128000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Uart_Demo", "256000", 0, QApplication::UnicodeUTF8)
        );
        pushButton_Connect->setText(QApplication::translate("Uart_Demo", "\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        pushButton_Disconnect->setText(QApplication::translate("Uart_Demo", "\346\226\255\345\274\200", 0, QApplication::UnicodeUTF8));
        pushButton_Send->setText(QApplication::translate("Uart_Demo", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        pushButton_Clear->setText(QApplication::translate("Uart_Demo", "\346\270\205\347\251\272\346\227\245\345\277\227", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Uart_Demo: public Ui_Uart_Demo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UART_DEMO_H

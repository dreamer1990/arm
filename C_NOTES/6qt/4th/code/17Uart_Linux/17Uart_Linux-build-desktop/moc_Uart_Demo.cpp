/****************************************************************************
** Meta object code from reading C++ file 'Uart_Demo.h'
**
** Created: Sun Oct 16 16:16:43 2016
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Uart/Uart_Demo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Uart_Demo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Uart_Demo[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      41,   10,   10,   10, 0x08,
      73,   10,   10,   10, 0x08,
     108,   10,   10,   10, 0x08,
     137,   10,   10,   10, 0x08,
     154,   10,   10,   10, 0x08,
     178,  174,   10,   10, 0x08,
     205,  200,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Uart_Demo[] = {
    "Uart_Demo\0\0on_pushButton_Clear_clicked()\0"
    "on_pushButton_Connect_clicked()\0"
    "on_pushButton_Disconnect_clicked()\0"
    "on_pushButton_Send_clicked()\0"
    "Slot_Connected()\0Slot_DisConnected()\0"
    "msg\0Slot_PushMsg(QString)\0data\0"
    "Slot_ReciveData(QByteArray)\0"
};

const QMetaObject Uart_Demo::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Uart_Demo,
      qt_meta_data_Uart_Demo, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Uart_Demo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Uart_Demo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Uart_Demo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Uart_Demo))
        return static_cast<void*>(const_cast< Uart_Demo*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Uart_Demo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushButton_Clear_clicked(); break;
        case 1: on_pushButton_Connect_clicked(); break;
        case 2: on_pushButton_Disconnect_clicked(); break;
        case 3: on_pushButton_Send_clicked(); break;
        case 4: Slot_Connected(); break;
        case 5: Slot_DisConnected(); break;
        case 6: Slot_PushMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: Slot_ReciveData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

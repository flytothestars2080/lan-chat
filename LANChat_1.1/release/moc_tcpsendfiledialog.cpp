/****************************************************************************
** Meta object code from reading C++ file 'tcpsendfiledialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tcpsendfiledialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpsendfiledialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TcpSendFileDialog_t {
    QByteArrayData data[11];
    char stringdata0[172];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpSendFileDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpSendFileDialog_t qt_meta_stringdata_TcpSendFileDialog = {
    {
QT_MOC_LITERAL(0, 0, 17), // "TcpSendFileDialog"
QT_MOC_LITERAL(1, 18, 12), // "sendFileName"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 8), // "FileName"
QT_MOC_LITERAL(4, 41, 11), // "SendMessage"
QT_MOC_LITERAL(5, 53, 17), // "updateSendProgess"
QT_MOC_LITERAL(6, 71, 7), // "ByteNum"
QT_MOC_LITERAL(7, 79, 23), // "on_btn_FileOpen_clicked"
QT_MOC_LITERAL(8, 103, 19), // "on_btn_send_clicked"
QT_MOC_LITERAL(9, 123, 20), // "on_btn_close_clicked"
QT_MOC_LITERAL(10, 144, 27) // "on_pushButton_canel_clicked"

    },
    "TcpSendFileDialog\0sendFileName\0\0"
    "FileName\0SendMessage\0updateSendProgess\0"
    "ByteNum\0on_btn_FileOpen_clicked\0"
    "on_btn_send_clicked\0on_btn_close_clicked\0"
    "on_pushButton_canel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpSendFileDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   52,    2, 0x08 /* Private */,
       5,    1,   53,    2, 0x08 /* Private */,
       7,    0,   56,    2, 0x08 /* Private */,
       8,    0,   57,    2, 0x08 /* Private */,
       9,    0,   58,    2, 0x08 /* Private */,
      10,    0,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TcpSendFileDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TcpSendFileDialog *_t = static_cast<TcpSendFileDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendFileName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->SendMessage(); break;
        case 2: _t->updateSendProgess((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 3: _t->on_btn_FileOpen_clicked(); break;
        case 4: _t->on_btn_send_clicked(); break;
        case 5: _t->on_btn_close_clicked(); break;
        case 6: _t->on_pushButton_canel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TcpSendFileDialog::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSendFileDialog::sendFileName)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject TcpSendFileDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TcpSendFileDialog.data,
      qt_meta_data_TcpSendFileDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TcpSendFileDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpSendFileDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpSendFileDialog.stringdata0))
        return static_cast<void*>(const_cast< TcpSendFileDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int TcpSendFileDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void TcpSendFileDialog::sendFileName(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

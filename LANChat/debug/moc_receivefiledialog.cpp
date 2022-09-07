/****************************************************************************
** Meta object code from reading C++ file 'receivefiledialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../receivefiledialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'receivefiledialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_receiveFileDialog_t {
    QByteArrayData data[9];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_receiveFileDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_receiveFileDialog_t qt_meta_stringdata_receiveFileDialog = {
    {
QT_MOC_LITERAL(0, 0, 17), // "receiveFileDialog"
QT_MOC_LITERAL(1, 18, 11), // "readMessage"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 8), // "on_error"
QT_MOC_LITERAL(4, 40, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(5, 69, 11), // "socketError"
QT_MOC_LITERAL(6, 81, 4), // "Init"
QT_MOC_LITERAL(7, 86, 20), // "on_btn_canel_clicked"
QT_MOC_LITERAL(8, 107, 20) // "on_btn_close_clicked"

    },
    "receiveFileDialog\0readMessage\0\0on_error\0"
    "QAbstractSocket::SocketError\0socketError\0"
    "Init\0on_btn_canel_clicked\0"
    "on_btn_close_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_receiveFileDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    1,   40,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,
       7,    0,   44,    2, 0x08 /* Private */,
       8,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void receiveFileDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        receiveFileDialog *_t = static_cast<receiveFileDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readMessage(); break;
        case 1: _t->on_error((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 2: _t->Init(); break;
        case 3: _t->on_btn_canel_clicked(); break;
        case 4: _t->on_btn_close_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject receiveFileDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_receiveFileDialog.data,
      qt_meta_data_receiveFileDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *receiveFileDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *receiveFileDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_receiveFileDialog.stringdata0))
        return static_cast<void*>(const_cast< receiveFileDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int receiveFileDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

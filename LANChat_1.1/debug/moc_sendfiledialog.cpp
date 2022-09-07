/****************************************************************************
** Meta object code from reading C++ file 'sendfiledialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sendfiledialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sendfiledialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SendFileDialog_t {
    QByteArrayData data[18];
    char stringdata0[239];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SendFileDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SendFileDialog_t qt_meta_stringdata_SendFileDialog = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SendFileDialog"
QT_MOC_LITERAL(1, 15, 12), // "sendFileName"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "FileName"
QT_MOC_LITERAL(4, 38, 12), // "DlgSendCanel"
QT_MOC_LITERAL(5, 51, 5), // "dlgid"
QT_MOC_LITERAL(6, 57, 8), // "DlgClose"
QT_MOC_LITERAL(7, 66, 23), // "on_btn_FileOpen_clicked"
QT_MOC_LITERAL(8, 90, 19), // "on_btn_send_clicked"
QT_MOC_LITERAL(9, 110, 20), // "on_btn_close_clicked"
QT_MOC_LITERAL(10, 131, 27), // "on_pushButton_canel_clicked"
QT_MOC_LITERAL(11, 159, 15), // "updateDateBytes"
QT_MOC_LITERAL(12, 175, 10), // "TotalBytes"
QT_MOC_LITERAL(13, 186, 12), // "bytesWritten"
QT_MOC_LITERAL(14, 199, 12), // "bytesToWrite"
QT_MOC_LITERAL(15, 212, 11), // "payloadSize"
QT_MOC_LITERAL(16, 224, 5), // "speed"
QT_MOC_LITERAL(17, 230, 8) // "usedtime"

    },
    "SendFileDialog\0sendFileName\0\0FileName\0"
    "DlgSendCanel\0dlgid\0DlgClose\0"
    "on_btn_FileOpen_clicked\0on_btn_send_clicked\0"
    "on_btn_close_clicked\0on_pushButton_canel_clicked\0"
    "updateDateBytes\0TotalBytes\0bytesWritten\0"
    "bytesToWrite\0payloadSize\0speed\0usedtime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SendFileDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       6,    1,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   63,    2, 0x08 /* Private */,
       8,    0,   64,    2, 0x08 /* Private */,
       9,    0,   65,    2, 0x08 /* Private */,
      10,    0,   66,    2, 0x08 /* Private */,
      11,    6,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong, QMetaType::LongLong, QMetaType::LongLong, QMetaType::Double, QMetaType::Double,   12,   13,   14,   15,   16,   17,

       0        // eod
};

void SendFileDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SendFileDialog *_t = static_cast<SendFileDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendFileName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->DlgSendCanel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->DlgClose((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_btn_FileOpen_clicked(); break;
        case 4: _t->on_btn_send_clicked(); break;
        case 5: _t->on_btn_close_clicked(); break;
        case 6: _t->on_pushButton_canel_clicked(); break;
        case 7: _t->updateDateBytes((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3])),(*reinterpret_cast< qint64(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SendFileDialog::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SendFileDialog::sendFileName)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SendFileDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SendFileDialog::DlgSendCanel)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SendFileDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SendFileDialog::DlgClose)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject SendFileDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SendFileDialog.data,
      qt_meta_data_SendFileDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SendFileDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SendFileDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SendFileDialog.stringdata0))
        return static_cast<void*>(const_cast< SendFileDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int SendFileDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void SendFileDialog::sendFileName(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SendFileDialog::DlgSendCanel(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SendFileDialog::DlgClose(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

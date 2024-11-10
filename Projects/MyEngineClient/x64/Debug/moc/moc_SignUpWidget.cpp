/****************************************************************************
** Meta object code from reading C++ file 'SignUpWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/OtherProjects/MyEngineClient/SignUpWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SignUpWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SignUpWidget_t {
    QByteArrayData data[9];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SignUpWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SignUpWidget_t qt_meta_stringdata_SignUpWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SignUpWidget"
QT_MOC_LITERAL(1, 13, 10), // "sig_closed"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 18), // "on_SureBtn_clicked"
QT_MOC_LITERAL(4, 44, 14), // "slot_CheckName"
QT_MOC_LITERAL(5, 59, 3), // "str"
QT_MOC_LITERAL(6, 63, 16), // "slot_CheckNumber"
QT_MOC_LITERAL(7, 80, 15), // "slot_CheckEmail"
QT_MOC_LITERAL(8, 96, 18) // "slot_CheckPassword"

    },
    "SignUpWidget\0sig_closed\0\0on_SureBtn_clicked\0"
    "slot_CheckName\0str\0slot_CheckNumber\0"
    "slot_CheckEmail\0slot_CheckPassword"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SignUpWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   45,    2, 0x0a /* Public */,
       4,    1,   46,    2, 0x0a /* Public */,
       6,    1,   49,    2, 0x0a /* Public */,
       7,    1,   52,    2, 0x0a /* Public */,
       8,    1,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,

       0        // eod
};

void SignUpWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SignUpWidget *_t = static_cast<SignUpWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_closed(); break;
        case 1: _t->on_SureBtn_clicked(); break;
        case 2: _t->slot_CheckName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->slot_CheckNumber((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->slot_CheckEmail((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->slot_CheckPassword((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SignUpWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SignUpWidget::sig_closed)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SignUpWidget::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SignUpWidget.data,
      qt_meta_data_SignUpWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SignUpWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SignUpWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SignUpWidget.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SignUpWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void SignUpWidget::sig_closed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'MoveMissionWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../MoveMissionWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MoveMissionWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MoveMissionWidget_t {
    QByteArrayData data[7];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MoveMissionWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MoveMissionWidget_t qt_meta_stringdata_MoveMissionWidget = {
    {
QT_MOC_LITERAL(0, 0, 17), // "MoveMissionWidget"
QT_MOC_LITERAL(1, 18, 18), // "on_SendBtn_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 19), // "onHumanComboxSelect"
QT_MOC_LITERAL(4, 58, 5), // "index"
QT_MOC_LITERAL(5, 64, 17), // "onUavComboxSelect"
QT_MOC_LITERAL(6, 82, 7) // "timeout"

    },
    "MoveMissionWidget\0on_SendBtn_clicked\0"
    "\0onHumanComboxSelect\0index\0onUavComboxSelect\0"
    "timeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MoveMissionWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    1,   35,    2, 0x0a /* Public */,
       5,    1,   38,    2, 0x0a /* Public */,
       6,    0,   41,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,

       0        // eod
};

void MoveMissionWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MoveMissionWidget *_t = static_cast<MoveMissionWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_SendBtn_clicked(); break;
        case 1: _t->onHumanComboxSelect((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onUavComboxSelect((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->timeout(); break;
        default: ;
        }
    }
}

const QMetaObject MoveMissionWidget::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MoveMissionWidget.data,
      qt_meta_data_MoveMissionWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MoveMissionWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MoveMissionWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MoveMissionWidget.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MoveMissionWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'AttackMissionWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../AttackMissionWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AttackMissionWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AttackMissionWidget_t {
    QByteArrayData data[8];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AttackMissionWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AttackMissionWidget_t qt_meta_stringdata_AttackMissionWidget = {
    {
QT_MOC_LITERAL(0, 0, 19), // "AttackMissionWidget"
QT_MOC_LITERAL(1, 20, 18), // "on_SendBtn_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 20), // "on_SendBtn_2_clicked"
QT_MOC_LITERAL(4, 61, 19), // "onHumanComboxSelect"
QT_MOC_LITERAL(5, 81, 5), // "index"
QT_MOC_LITERAL(6, 87, 17), // "onUavComboxSelect"
QT_MOC_LITERAL(7, 105, 11) // "slot_update"

    },
    "AttackMissionWidget\0on_SendBtn_clicked\0"
    "\0on_SendBtn_2_clicked\0onHumanComboxSelect\0"
    "index\0onUavComboxSelect\0slot_update"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AttackMissionWidget[] = {

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
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    1,   41,    2, 0x0a /* Public */,
       6,    1,   44,    2, 0x0a /* Public */,
       7,    0,   47,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,

       0        // eod
};

void AttackMissionWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AttackMissionWidget *_t = static_cast<AttackMissionWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_SendBtn_clicked(); break;
        case 1: _t->on_SendBtn_2_clicked(); break;
        case 2: _t->onHumanComboxSelect((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onUavComboxSelect((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->slot_update(); break;
        default: ;
        }
    }
}

const QMetaObject AttackMissionWidget::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AttackMissionWidget.data,
      qt_meta_data_AttackMissionWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AttackMissionWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AttackMissionWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AttackMissionWidget.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int AttackMissionWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

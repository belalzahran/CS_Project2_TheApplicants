/****************************************************************************
** Meta object code from reading C++ file 'college_list.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../college_list.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'college_list.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CollegeList_t {
    const uint offsetsAndSize[14];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_CollegeList_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_CollegeList_t qt_meta_stringdata_CollegeList = {
    {
QT_MOC_LITERAL(0, 11), // "CollegeList"
QT_MOC_LITERAL(12, 35), // "on_sortAlphabeticallyButton_c..."
QT_MOC_LITERAL(48, 0), // ""
QT_MOC_LITERAL(49, 28), // "on_sortByStateButton_clicked"
QT_MOC_LITERAL(78, 36), // "on_comboBoxState_currentIndex..."
QT_MOC_LITERAL(115, 5), // "index"
QT_MOC_LITERAL(121, 21) // "on_pushButton_clicked"

    },
    "CollegeList\0on_sortAlphabeticallyButton_clicked\0"
    "\0on_sortByStateButton_clicked\0"
    "on_comboBoxState_currentIndexChanged\0"
    "index\0on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CollegeList[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x08,    1 /* Private */,
       3,    0,   39,    2, 0x08,    2 /* Private */,
       4,    1,   40,    2, 0x08,    3 /* Private */,
       6,    0,   43,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,

       0        // eod
};

void CollegeList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CollegeList *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_sortAlphabeticallyButton_clicked(); break;
        case 1: _t->on_sortByStateButton_clicked(); break;
        case 2: _t->on_comboBoxState_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject CollegeList::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CollegeList.offsetsAndSize,
    qt_meta_data_CollegeList,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CollegeList_t
, QtPrivate::TypeAndForceComplete<CollegeList, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *CollegeList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CollegeList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CollegeList.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CollegeList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'admin.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../admin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'admin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_admin_t {
    const uint offsetsAndSize[32];
    char stringdata0[320];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_admin_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_admin_t qt_meta_stringdata_admin = {
    {
QT_MOC_LITERAL(0, 5), // "admin"
QT_MOC_LITERAL(6, 21), // "updateCollegesClicked"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 22), // "updateSouvenirsClicked"
QT_MOC_LITERAL(52, 24), // "fillCollegeSouvenirCombo"
QT_MOC_LITERAL(77, 7), // "College"
QT_MOC_LITERAL(85, 15), // "selectedCollege"
QT_MOC_LITERAL(101, 30), // "on_comboBox_currentTextChanged"
QT_MOC_LITERAL(132, 4), // "arg1"
QT_MOC_LITERAL(137, 18), // "sendUpdateColleges"
QT_MOC_LITERAL(156, 19), // "sendUpdateSouvenirs"
QT_MOC_LITERAL(176, 27), // "on_pushButton_edit3_clicked"
QT_MOC_LITERAL(204, 27), // "on_pushButton_3done_clicked"
QT_MOC_LITERAL(232, 33), // "on_pushButton_addSouvenir_cli..."
QT_MOC_LITERAL(266, 36), // "on_pushButton_deleteSouvenir_..."
QT_MOC_LITERAL(303, 16) // "fillCollegeCombo"

    },
    "admin\0updateCollegesClicked\0\0"
    "updateSouvenirsClicked\0fillCollegeSouvenirCombo\0"
    "College\0selectedCollege\0"
    "on_comboBox_currentTextChanged\0arg1\0"
    "sendUpdateColleges\0sendUpdateSouvenirs\0"
    "on_pushButton_edit3_clicked\0"
    "on_pushButton_3done_clicked\0"
    "on_pushButton_addSouvenir_clicked\0"
    "on_pushButton_deleteSouvenir_clicked\0"
    "fillCollegeCombo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_admin[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x06,    1 /* Public */,
       3,    0,   81,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   82,    2, 0x08,    3 /* Private */,
       7,    1,   85,    2, 0x08,    5 /* Private */,
       9,    0,   88,    2, 0x08,    7 /* Private */,
      10,    0,   89,    2, 0x08,    8 /* Private */,
      11,    0,   90,    2, 0x08,    9 /* Private */,
      12,    0,   91,    2, 0x08,   10 /* Private */,
      13,    0,   92,    2, 0x08,   11 /* Private */,
      14,    0,   93,    2, 0x08,   12 /* Private */,
      15,    0,   94,    2, 0x0a,   13 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void admin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<admin *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateCollegesClicked(); break;
        case 1: _t->updateSouvenirsClicked(); break;
        case 2: _t->fillCollegeSouvenirCombo((*reinterpret_cast< College(*)>(_a[1]))); break;
        case 3: _t->on_comboBox_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->sendUpdateColleges(); break;
        case 5: _t->sendUpdateSouvenirs(); break;
        case 6: _t->on_pushButton_edit3_clicked(); break;
        case 7: _t->on_pushButton_3done_clicked(); break;
        case 8: _t->on_pushButton_addSouvenir_clicked(); break;
        case 9: _t->on_pushButton_deleteSouvenir_clicked(); break;
        case 10: _t->fillCollegeCombo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (admin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&admin::updateCollegesClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (admin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&admin::updateSouvenirsClicked)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject admin::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_admin.offsetsAndSize,
    qt_meta_data_admin,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_admin_t
, QtPrivate::TypeAndForceComplete<admin, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<College, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *admin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *admin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_admin.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int admin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void admin::updateCollegesClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void admin::updateSouvenirsClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

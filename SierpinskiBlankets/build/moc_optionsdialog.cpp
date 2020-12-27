/****************************************************************************
** Meta object code from reading C++ file 'optionsdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../optionsdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'optionsdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OptionsDialog_t {
    QByteArrayData data[14];
    char stringdata0[280];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OptionsDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OptionsDialog_t qt_meta_stringdata_OptionsDialog = {
    {
QT_MOC_LITERAL(0, 0, 13), // "OptionsDialog"
QT_MOC_LITERAL(1, 14, 13), // "dialogPressed"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 12), // "dialogClosed"
QT_MOC_LITERAL(4, 42, 19), // "on_butnStar_clicked"
QT_MOC_LITERAL(5, 62, 26), // "on_butnReverseStar_clicked"
QT_MOC_LITERAL(6, 89, 21), // "on_butnCircle_clicked"
QT_MOC_LITERAL(7, 111, 28), // "on_butnReverseCircle_clicked"
QT_MOC_LITERAL(8, 140, 21), // "on_butnGasket_clicked"
QT_MOC_LITERAL(9, 162, 28), // "on_butnReverseGasket_clicked"
QT_MOC_LITERAL(10, 191, 20), // "on_btnCarpet_clicked"
QT_MOC_LITERAL(11, 212, 28), // "on_butnReverseCarpet_clicked"
QT_MOC_LITERAL(12, 241, 18), // "on_btnDraw_clicked"
QT_MOC_LITERAL(13, 260, 19) // "on_btnClear_clicked"

    },
    "OptionsDialog\0dialogPressed\0\0dialogClosed\0"
    "on_butnStar_clicked\0on_butnReverseStar_clicked\0"
    "on_butnCircle_clicked\0"
    "on_butnReverseCircle_clicked\0"
    "on_butnGasket_clicked\0"
    "on_butnReverseGasket_clicked\0"
    "on_btnCarpet_clicked\0on_butnReverseCarpet_clicked\0"
    "on_btnDraw_clicked\0on_btnClear_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OptionsDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       3,    0,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   78,    2, 0x08 /* Private */,
       5,    0,   79,    2, 0x08 /* Private */,
       6,    0,   80,    2, 0x08 /* Private */,
       7,    0,   81,    2, 0x08 /* Private */,
       8,    0,   82,    2, 0x08 /* Private */,
       9,    0,   83,    2, 0x08 /* Private */,
      10,    0,   84,    2, 0x08 /* Private */,
      11,    0,   85,    2, 0x08 /* Private */,
      12,    0,   86,    2, 0x08 /* Private */,
      13,    0,   87,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void OptionsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OptionsDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dialogPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->dialogClosed(); break;
        case 2: _t->on_butnStar_clicked(); break;
        case 3: _t->on_butnReverseStar_clicked(); break;
        case 4: _t->on_butnCircle_clicked(); break;
        case 5: _t->on_butnReverseCircle_clicked(); break;
        case 6: _t->on_butnGasket_clicked(); break;
        case 7: _t->on_butnReverseGasket_clicked(); break;
        case 8: _t->on_btnCarpet_clicked(); break;
        case 9: _t->on_butnReverseCarpet_clicked(); break;
        case 10: _t->on_btnDraw_clicked(); break;
        case 11: _t->on_btnClear_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (OptionsDialog::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OptionsDialog::dialogPressed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (OptionsDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OptionsDialog::dialogClosed)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject OptionsDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_OptionsDialog.data,
    qt_meta_data_OptionsDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *OptionsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OptionsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OptionsDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int OptionsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void OptionsDialog::dialogPressed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void OptionsDialog::dialogClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

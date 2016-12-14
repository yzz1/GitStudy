/****************************************************************************
** Meta object code from reading C++ file 'individualselectview.h'
**
** Created: Wed May 4 11:52:07 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../views/call/individualselectview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'individualselectview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_IndividualSelectView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      46,   22,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
     101,   21,   21,   21, 0x0a,
     119,   21,   21,   21, 0x0a,
     141,   21,   21,   21, 0x0a,
     167,   21,   21,   21, 0x0a,
     194,   21,   21,   21, 0x0a,
     224,  218,   21,   21, 0x0a,
     251,   22,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_IndividualSelectView[] = {
    "IndividualSelectView\0\0thisID,fowordID,paraMap\0"
    "afterPageSignal(QString,QString,QMap<QString,QString>)\0"
    "homeClickedSlot()\0okButtonClickedSlot()\0"
    "cancelButtonClickedSlot()\0"
    "receiveButtonClickedSlot()\0"
    "callButtonClickedSlot()\0index\0"
    "activatedSlot(QModelIndex)\0"
    "frontPageSlot(QString,QString,QMap<QString,QString>)\0"
};

void IndividualSelectView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        IndividualSelectView *_t = static_cast<IndividualSelectView *>(_o);
        switch (_id) {
        case 0: _t->afterPageSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QMap<QString,QString>(*)>(_a[3]))); break;
        case 1: _t->homeClickedSlot(); break;
        case 2: _t->okButtonClickedSlot(); break;
        case 3: _t->cancelButtonClickedSlot(); break;
        case 4: _t->receiveButtonClickedSlot(); break;
        case 5: _t->callButtonClickedSlot(); break;
        case 6: _t->activatedSlot((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 7: _t->frontPageSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QMap<QString,QString>(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData IndividualSelectView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject IndividualSelectView::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_IndividualSelectView,
      qt_meta_data_IndividualSelectView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &IndividualSelectView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *IndividualSelectView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *IndividualSelectView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IndividualSelectView))
        return static_cast<void*>(const_cast< IndividualSelectView*>(this));
    return QDialog::qt_metacast(_clname);
}

int IndividualSelectView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void IndividualSelectView::afterPageSignal(QString _t1, QString _t2, QMap<QString,QString> _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'callcommunicationwidget.h'
**
** Created: Wed May 4 11:52:16 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../views/call/callcommunicationwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'callcommunicationwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CallCommunicationwidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      49,   25,   24,   24, 0x05,
     104,   24,   24,   24, 0x05,

 // slots: signature, parameters, type, tag, flags
     128,   24,   24,   24, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CallCommunicationwidget[] = {
    "CallCommunicationwidget\0\0"
    "thisID,fowordID,paraMap\0"
    "afterPageSignal(QString,QString,QMap<QString,QString>)\0"
    "okButtonClickedSignal()\0okButtonClickedSlot()\0"
};

void CallCommunicationwidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CallCommunicationwidget *_t = static_cast<CallCommunicationwidget *>(_o);
        switch (_id) {
        case 0: _t->afterPageSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QMap<QString,QString>(*)>(_a[3]))); break;
        case 1: _t->okButtonClickedSignal(); break;
        case 2: _t->okButtonClickedSlot(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CallCommunicationwidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CallCommunicationwidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CallCommunicationwidget,
      qt_meta_data_CallCommunicationwidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CallCommunicationwidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CallCommunicationwidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CallCommunicationwidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CallCommunicationwidget))
        return static_cast<void*>(const_cast< CallCommunicationwidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CallCommunicationwidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CallCommunicationwidget::afterPageSignal(QString _t1, QString _t2, QMap<QString,QString> _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CallCommunicationwidget::okButtonClickedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE

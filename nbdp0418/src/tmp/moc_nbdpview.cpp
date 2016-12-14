/****************************************************************************
** Meta object code from reading C++ file 'nbdpview.h'
**
** Created: Wed May 4 11:51:49 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../views/nbdpview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nbdpview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NbdpView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       1,   79, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      34,   10,    9,    9, 0x05,
      89,    9,    9,    9, 0x05,
     116,   99,    9,    9, 0x05,
     147,  142,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     170,  164,    9,    9, 0x08,
     183,    9,    9,    9, 0x28,
     193,   10,    9,    9, 0x08,
     246,    9,    9,    9, 0x08,
     264,  260,    9,    9, 0x08,
     297,  293,    9,    9, 0x08,
     328,    9,    9,    9, 0x08,
     347,  343,    9,    9, 0x08,

 // methods: signature, parameters, type, tag, flags
     389,  381,    9,    9, 0x02,

 // properties: name, type, flags
     381,  409, 0x0a095103,

       0        // eod
};

static const char qt_meta_stringdata_NbdpView[] = {
    "NbdpView\0\0thisID,fowordID,paraMap\0"
    "afterPageSignal(QString,QString,QMap<QString,QString>)\0"
    "signal1()\0realTimePrinting\0"
    "realTimePrinting(QString)\0mmsi\0"
    "setMMSI(QString)\0index\0forward(int)\0"
    "forward()\0"
    "afterPageslot(QString,QString,QMap<QString,QString>)\0"
    "SlotTimeout()\0ret\0SlotRadioConnectAnswer(bool)\0"
    "cdc\0SlotCheckData(CheckDataClass*)\0"
    "SlotShutDown()\0cic\0SlotDSCfollowComm(CallInfoClass*)\0"
    "backPix\0setBackPix(QString)\0QString\0"
};

void NbdpView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NbdpView *_t = static_cast<NbdpView *>(_o);
        switch (_id) {
        case 0: _t->afterPageSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QMap<QString,QString>(*)>(_a[3]))); break;
        case 1: _t->signal1(); break;
        case 2: _t->realTimePrinting((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->setMMSI((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->forward((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->forward(); break;
        case 6: _t->afterPageslot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QMap<QString,QString>(*)>(_a[3]))); break;
        case 7: _t->SlotTimeout(); break;
        case 8: _t->SlotRadioConnectAnswer((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->SlotCheckData((*reinterpret_cast< CheckDataClass*(*)>(_a[1]))); break;
        case 10: _t->SlotShutDown(); break;
        case 11: _t->SlotDSCfollowComm((*reinterpret_cast< CallInfoClass*(*)>(_a[1]))); break;
        case 12: _t->setBackPix((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData NbdpView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NbdpView::staticMetaObject = {
    { &BaseView::staticMetaObject, qt_meta_stringdata_NbdpView,
      qt_meta_data_NbdpView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NbdpView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NbdpView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NbdpView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NbdpView))
        return static_cast<void*>(const_cast< NbdpView*>(this));
    return BaseView::qt_metacast(_clname);
}

int NbdpView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = backPix(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setBackPix(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void NbdpView::afterPageSignal(QString _t1, QString _t2, QMap<QString,QString> _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NbdpView::signal1()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void NbdpView::realTimePrinting(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void NbdpView::setMMSI(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE

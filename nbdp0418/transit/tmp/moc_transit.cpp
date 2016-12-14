/****************************************************************************
** Meta object code from reading C++ file 'transit.h'
**
** Created: Wed May 4 11:49:18 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../transit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'transit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Transit[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      32,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      40,   36,    8,    8, 0x05,
      64,   61,    8,    8, 0x05,
      94,   92,    8,    8, 0x05,
     115,   92,    8,    8, 0x05,
     141,   92,    8,    8, 0x05,
     168,   92,    8,    8, 0x05,
     197,    8,    8,    8, 0x05,
     235,  222,    8,    8, 0x05,
     275,  267,    8,    8, 0x05,
     311,   36,    8,    8, 0x05,
     338,    8,    8,    8, 0x05,
     355,   92,    8,    8, 0x05,
     383,    8,    8,    8, 0x05,
     403,    8,    8,    8, 0x05,
     427,  424,    8,    8, 0x05,
     454,  450,    8,    8, 0x05,
     485,    8,    8,    8, 0x05,
     503,  499,    8,    8, 0x05,
     536,    8,    8,    8, 0x05,
     554,    8,    8,    8, 0x05,
     573,    8,    8,    8, 0x05,
     592,  590,    8,    8, 0x05,
     614,    8,    8,    8, 0x05,
     631,  590,    8,    8, 0x05,
     657,    8,    8,    8, 0x05,
     676,    8,    8,    8, 0x05,
     700,    8,    8,    8, 0x05,
     735,  731,    8,    8, 0x05,
     771,    8,    8,    8, 0x05,
     801,   92,    8,    8, 0x05,
     838,  827,    8,    8, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_Transit[] = {
    "Transit\0\0SignalJianLianEnterReady()\0"
    "str\0SignalState(QString)\0cc\0"
    "SignalCallSetup(CallClass*)\0b\0"
    "SignalCallWait(bool)\0SignalTurningResult(bool)\0"
    "SignalConnectingWait(bool)\0"
    "SignalConnectingResult(bool)\0"
    "SignalConnectingCancel()\0strNo,strMsg\0"
    "SignalTalkSend(QString,QString)\0strNo,b\0"
    "SignalTalkSendConfirm(QString,bool)\0"
    "SignalTalkReceive(QString)\0SignalInterupt()\0"
    "SignalInteruptConfirm(bool)\0"
    "SignalInteruptDSC()\0SignalInteruptComu()\0"
    "sc\0SignalScan(ScanClass*)\0sdc\0"
    "SignalScanData(CallInfoClass*)\0"
    "SignalCheck()\0cdc\0SignalCheckData(CheckDataClass*)\0"
    "SignalMarkTrans()\0SignalSpaceTrans()\0"
    "SignalDotTrans()\0i\0SignalSlaveDelay(int)\0"
    "SignalShutDown()\0SignalKeyDownForTest(int)\0"
    "SignalMessageEnd()\0SignalRadioConnectAsk()\0"
    "SignalRadioConnectAnswer(bool)\0ddc\0"
    "SignalDSCfollowComm(CallInfoClass*)\0"
    "SignalKillSendScanFreqTimer()\0"
    "SignalLineEditState(bool)\0calledType\0"
    "SignalCalledReceive(int)\0"
};

void Transit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Transit *_t = static_cast<Transit *>(_o);
        switch (_id) {
        case 0: _t->SignalJianLianEnterReady(); break;
        case 1: _t->SignalState((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->SignalCallSetup((*reinterpret_cast< CallClass*(*)>(_a[1]))); break;
        case 3: _t->SignalCallWait((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->SignalTurningResult((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->SignalConnectingWait((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->SignalConnectingResult((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->SignalConnectingCancel(); break;
        case 8: _t->SignalTalkSend((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->SignalTalkSendConfirm((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 10: _t->SignalTalkReceive((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->SignalInterupt(); break;
        case 12: _t->SignalInteruptConfirm((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->SignalInteruptDSC(); break;
        case 14: _t->SignalInteruptComu(); break;
        case 15: _t->SignalScan((*reinterpret_cast< ScanClass*(*)>(_a[1]))); break;
        case 16: _t->SignalScanData((*reinterpret_cast< CallInfoClass*(*)>(_a[1]))); break;
        case 17: _t->SignalCheck(); break;
        case 18: _t->SignalCheckData((*reinterpret_cast< CheckDataClass*(*)>(_a[1]))); break;
        case 19: _t->SignalMarkTrans(); break;
        case 20: _t->SignalSpaceTrans(); break;
        case 21: _t->SignalDotTrans(); break;
        case 22: _t->SignalSlaveDelay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->SignalShutDown(); break;
        case 24: _t->SignalKeyDownForTest((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->SignalMessageEnd(); break;
        case 26: _t->SignalRadioConnectAsk(); break;
        case 27: _t->SignalRadioConnectAnswer((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: _t->SignalDSCfollowComm((*reinterpret_cast< CallInfoClass*(*)>(_a[1]))); break;
        case 29: _t->SignalKillSendScanFreqTimer(); break;
        case 30: _t->SignalLineEditState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 31: _t->SignalCalledReceive((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Transit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Transit::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Transit,
      qt_meta_data_Transit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Transit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Transit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Transit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Transit))
        return static_cast<void*>(const_cast< Transit*>(this));
    return QObject::qt_metacast(_clname);
}

int Transit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    }
    return _id;
}

// SIGNAL 0
void Transit::SignalJianLianEnterReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Transit::SignalState(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Transit::SignalCallSetup(CallClass * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Transit::SignalCallWait(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Transit::SignalTurningResult(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Transit::SignalConnectingWait(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Transit::SignalConnectingResult(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Transit::SignalConnectingCancel()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void Transit::SignalTalkSend(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Transit::SignalTalkSendConfirm(QString _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Transit::SignalTalkReceive(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Transit::SignalInterupt()
{
    QMetaObject::activate(this, &staticMetaObject, 11, 0);
}

// SIGNAL 12
void Transit::SignalInteruptConfirm(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Transit::SignalInteruptDSC()
{
    QMetaObject::activate(this, &staticMetaObject, 13, 0);
}

// SIGNAL 14
void Transit::SignalInteruptComu()
{
    QMetaObject::activate(this, &staticMetaObject, 14, 0);
}

// SIGNAL 15
void Transit::SignalScan(ScanClass * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void Transit::SignalScanData(CallInfoClass * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void Transit::SignalCheck()
{
    QMetaObject::activate(this, &staticMetaObject, 17, 0);
}

// SIGNAL 18
void Transit::SignalCheckData(CheckDataClass * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void Transit::SignalMarkTrans()
{
    QMetaObject::activate(this, &staticMetaObject, 19, 0);
}

// SIGNAL 20
void Transit::SignalSpaceTrans()
{
    QMetaObject::activate(this, &staticMetaObject, 20, 0);
}

// SIGNAL 21
void Transit::SignalDotTrans()
{
    QMetaObject::activate(this, &staticMetaObject, 21, 0);
}

// SIGNAL 22
void Transit::SignalSlaveDelay(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void Transit::SignalShutDown()
{
    QMetaObject::activate(this, &staticMetaObject, 23, 0);
}

// SIGNAL 24
void Transit::SignalKeyDownForTest(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void Transit::SignalMessageEnd()
{
    QMetaObject::activate(this, &staticMetaObject, 25, 0);
}

// SIGNAL 26
void Transit::SignalRadioConnectAsk()
{
    QMetaObject::activate(this, &staticMetaObject, 26, 0);
}

// SIGNAL 27
void Transit::SignalRadioConnectAnswer(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}

// SIGNAL 28
void Transit::SignalDSCfollowComm(CallInfoClass * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void Transit::SignalKillSendScanFreqTimer()
{
    QMetaObject::activate(this, &staticMetaObject, 29, 0);
}

// SIGNAL 30
void Transit::SignalLineEditState(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 30, _a);
}

// SIGNAL 31
void Transit::SignalCalledReceive(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 31, _a);
}
QT_END_MOC_NAMESPACE

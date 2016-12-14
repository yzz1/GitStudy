/****************************************************************************
** Meta object code from reading C++ file 'control.h'
**
** Created: Wed May 4 11:49:55 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../control.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'control.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Control[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,    9,    8,    8, 0x0a,
      60,   57,    8,    8, 0x08,
      86,    8,    8,    8, 0x08,
     109,    9,    8,    8, 0x08,
     139,    8,    8,    8, 0x08,
     157,  154,    8,    8, 0x08,
     178,    8,    8,    8, 0x08,
     190,    8,    8,    8, 0x08,
     206,    8,    8,    8, 0x08,
     223,    8,    8,    8, 0x08,
     240,  238,    8,    8, 0x08,
     260,    8,    8,    8, 0x08,
     282,    8,    8,    8, 0x08,
     301,    8,    8,    8, 0x08,
     323,    8,    8,    8, 0x08,
     351,    8,    8,    8, 0x08,
     382,  380,    8,    8, 0x08,
     419,  408,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Control[] = {
    "Control\0\0strNo,strMsg\0"
    "SlotTalkAndCSSend(QString,QString)\0"
    "cc\0SlotCallSetup(CallClass*)\0"
    "SlotConnectingCancel()\0"
    "SlotTalkSend(QString,QString)\0"
    "SlotInterupt()\0sc\0SlotScan(ScanClass*)\0"
    "SlotCheck()\0SlotMarkTrans()\0"
    "SlotSpaceTrans()\0SlotDotTrans()\0i\0"
    "SlotSlaveDelay(int)\0SlotRadioConnectAsk()\0"
    "SlotSendScanFreq()\0SlotSendStrMsgTimer()\0"
    "SlotKillSendScanFreqTimer()\0"
    "SLot_workFlow_readyAndIdle()\0b\0"
    "SlotBS_FECStartLink(bool)\0calledType\0"
    "SlotCalledReceive(int)\0"
};

void Control::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Control *_t = static_cast<Control *>(_o);
        switch (_id) {
        case 0: _t->SlotTalkAndCSSend((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->SlotCallSetup((*reinterpret_cast< CallClass*(*)>(_a[1]))); break;
        case 2: _t->SlotConnectingCancel(); break;
        case 3: _t->SlotTalkSend((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->SlotInterupt(); break;
        case 5: _t->SlotScan((*reinterpret_cast< ScanClass*(*)>(_a[1]))); break;
        case 6: _t->SlotCheck(); break;
        case 7: _t->SlotMarkTrans(); break;
        case 8: _t->SlotSpaceTrans(); break;
        case 9: _t->SlotDotTrans(); break;
        case 10: _t->SlotSlaveDelay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->SlotRadioConnectAsk(); break;
        case 12: _t->SlotSendScanFreq(); break;
        case 13: _t->SlotSendStrMsgTimer(); break;
        case 14: _t->SlotKillSendScanFreqTimer(); break;
        case 15: _t->SLot_workFlow_readyAndIdle(); break;
        case 16: _t->SlotBS_FECStartLink((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->SlotCalledReceive((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Control::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Control::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Control,
      qt_meta_data_Control, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Control::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Control::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Control::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Control))
        return static_cast<void*>(const_cast< Control*>(this));
    return QObject::qt_metacast(_clname);
}

int Control::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

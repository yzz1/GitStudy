/****************************************************************************
** Meta object code from reading C++ file 'callcommunication.h'
**
** Created: Wed May 4 11:52:13 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../views/call/callcommunication.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'callcommunication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CallCommunication[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      43,   19,   18,   18, 0x05,
     108,   98,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
     131,   19,   18,   18, 0x0a,
     184,   18,   18,   18, 0x0a,
     201,   18,   18,   18, 0x0a,
     218,   18,   18,   18, 0x0a,
     254,  236,   18,   18, 0x0a,
     275,   18,   18,   18, 0x2a,
     289,   18,   18,   18, 0x0a,
     301,   18,   18,   18, 0x0a,
     321,   18,   18,   18, 0x0a,
     340,   18,   18,   18, 0x0a,
     361,   18,   18,   18, 0x0a,
     375,   18,   18,   18, 0x0a,
     385,   18,   18,   18, 0x0a,
     394,   18,   18,   18, 0x0a,
     405,   18,   18,   18, 0x0a,
     427,  417,   18,   18, 0x0a,
     457,   18,   18,   18, 0x0a,
     475,   18,   18,   18, 0x0a,
     499,   18,   18,   18, 0x0a,
     526,  524,   18,   18, 0x0a,
     545,  524,   18,   18, 0x0a,
     569,  524,   18,   18, 0x0a,
     594,  524,   18,   18, 0x0a,
     629,  621,   18,   18, 0x0a,
     667,  663,   18,   18, 0x0a,
     692,  524,   18,   18, 0x0a,
     718,   18,   18,   18, 0x0a,
     736,   18,   18,   18, 0x0a,
     755,   18,   18,   18, 0x0a,
     772,  524,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CallCommunication[] = {
    "CallCommunication\0\0thisID,fowordID,paraMap\0"
    "afterPageSignal(QString,QString,QMap<QString,QString>)\0"
    "hasUnread\0hasUnreadMessage(bool)\0"
    "frontPageSlot(QString,QString,QMap<QString,QString>)\0"
    "showOptionMenu()\0showInsertMenu()\0"
    "homeClickedSlot()\0strReceiveMessage\0"
    "sendMessage(QString)\0sendMessage()\0"
    "macroMenu()\0phrasebookMessage()\0"
    "printClickedSlot()\0widgetDataBackSlot()\0"
    "loadMessage()\0sendWRU()\0sendHR()\0"
    "sendOver()\0sendBreak()\0printMode\0"
    "SlotRealTimePrinting(QString)\0"
    "SlotTimerUpdate()\0SlotSignalWaitTimeOut()\0"
    "SlotDialogCloseTimeout()\0b\0"
    "SlotCallWait(bool)\0SlotTurningResult(bool)\0"
    "SlotConnectingWait(bool)\0"
    "SlotConnectingResult(bool)\0strNo,b\0"
    "SlotTalkSendConfirm(QString,bool)\0str\0"
    "SlotTalkReceive(QString)\0"
    "SlotInteruptConfirm(bool)\0SlotInteruptDSC()\0"
    "SlotInteruptComu()\0SlotMessageEnd()\0"
    "SlotSetLineEditState(bool)\0"
};

void CallCommunication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CallCommunication *_t = static_cast<CallCommunication *>(_o);
        switch (_id) {
        case 0: _t->afterPageSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QMap<QString,QString>(*)>(_a[3]))); break;
        case 1: _t->hasUnreadMessage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->frontPageSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QMap<QString,QString>(*)>(_a[3]))); break;
        case 3: _t->showOptionMenu(); break;
        case 4: _t->showInsertMenu(); break;
        case 5: _t->homeClickedSlot(); break;
        case 6: _t->sendMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->sendMessage(); break;
        case 8: _t->macroMenu(); break;
        case 9: _t->phrasebookMessage(); break;
        case 10: _t->printClickedSlot(); break;
        case 11: _t->widgetDataBackSlot(); break;
        case 12: _t->loadMessage(); break;
        case 13: _t->sendWRU(); break;
        case 14: _t->sendHR(); break;
        case 15: _t->sendOver(); break;
        case 16: _t->sendBreak(); break;
        case 17: _t->SlotRealTimePrinting((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->SlotTimerUpdate(); break;
        case 19: _t->SlotSignalWaitTimeOut(); break;
        case 20: _t->SlotDialogCloseTimeout(); break;
        case 21: _t->SlotCallWait((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->SlotTurningResult((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->SlotConnectingWait((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->SlotConnectingResult((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->SlotTalkSendConfirm((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 26: _t->SlotTalkReceive((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 27: _t->SlotInteruptConfirm((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: _t->SlotInteruptDSC(); break;
        case 29: _t->SlotInteruptComu(); break;
        case 30: _t->SlotMessageEnd(); break;
        case 31: _t->SlotSetLineEditState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CallCommunication::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CallCommunication::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CallCommunication,
      qt_meta_data_CallCommunication, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CallCommunication::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CallCommunication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CallCommunication::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CallCommunication))
        return static_cast<void*>(const_cast< CallCommunication*>(this));
    return QWidget::qt_metacast(_clname);
}

int CallCommunication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void CallCommunication::afterPageSignal(QString _t1, QString _t2, QMap<QString,QString> _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CallCommunication::hasUnreadMessage(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE

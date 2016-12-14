/****************************************************************************
** Meta object code from reading C++ file 'messagesstyle.h'
**
** Created: Wed May 4 11:52:00 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../views/messages/messagesstyle.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'messagesstyle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MessagesStyle[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
      11,  114, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: signature, parameters, type, tag, flags
      19,   14,   15,   14, 0x02,
      51,   14,   43,   14, 0x02,
      67,   14,   43,   14, 0x02,
      86,   14,   43,   14, 0x02,
     106,   14,   43,   14, 0x02,
     129,   14,   43,   14, 0x02,
     158,   14,  151,   14, 0x02,
     180,   14,  151,   14, 0x02,
     203,   14,   43,   14, 0x02,
     227,   14,   43,   14, 0x02,
     269,  250,   14,   14, 0x02,
     307,  296,   14,   14, 0x02,
     344,  330,   14,   14, 0x02,
     385,  370,   14,   14, 0x02,
     430,  412,   14,   14, 0x02,
     477,  460,   14,   14, 0x02,
     523,  506,   14,   14, 0x02,
     569,  551,   14,   14, 0x02,
     617,  598,   14,   14, 0x02,
     666,  648,   14,   14, 0x02,

 // properties: name, type, flags
     250,   15, 0x02095103,
     296,   43, 0x0a095103,
     696,   43, 0x0a095103,
     330,   43, 0x0a095103,
     370,   43, 0x0a095103,
     412,   43, 0x0a095103,
     460,   43, 0x0a095103,
     506,  151, 0x43095103,
     551,  151, 0x43095103,
     598,   43, 0x0a095103,
     648,   43, 0x0a095103,

       0        // eod
};

static const char qt_meta_stringdata_MessagesStyle[] = {
    "MessagesStyle\0\0int\0getDateFormatColIndex()\0"
    "QString\0getDateFormat()\0getCheckNoPixmap()\0"
    "getCheckYesPixmap()\0getCheckSelYesPixmap()\0"
    "getCheckSelNoPixmap()\0QColor\0"
    "getMsContentBgColor()\0getMsSelectedBgColor()\0"
    "getReadedSelYesPixmap()\0getReadedSelNoPixmap()\0"
    "dateFormatColIndex\0setDateFormatColIndex(int)\0"
    "dateFormat\0setDateFormat(QString)\0"
    "checkNoPixmap\0setCheckNoPixmap(QString)\0"
    "checkYesPixmap\0setCheckYesPixmap(QString)\0"
    "checkSelYesPixmap\0setCheckSelYesPixmap(QString)\0"
    "checkSelNoPixmap\0setCheckSelNoPixmap(QString)\0"
    "msContentBgColor\0setMsContentBgColor(QColor)\0"
    "msSelectedBgColor\0setMsSelectedBgColor(QColor)\0"
    "readedSelYesPixmap\0setReadedSelYesPixmap(QString)\0"
    "readedSelNoPixmap\0setReadedSelNoPixmap(QString)\0"
    "selectedPixmap\0"
};

void MessagesStyle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MessagesStyle *_t = static_cast<MessagesStyle *>(_o);
        switch (_id) {
        case 0: { int _r = _t->getDateFormatColIndex();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: { QString _r = _t->getDateFormat();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 2: { QString _r = _t->getCheckNoPixmap();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 3: { QString _r = _t->getCheckYesPixmap();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 4: { QString _r = _t->getCheckSelYesPixmap();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 5: { QString _r = _t->getCheckSelNoPixmap();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 6: { QColor _r = _t->getMsContentBgColor();
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 7: { QColor _r = _t->getMsSelectedBgColor();
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 8: { QString _r = _t->getReadedSelYesPixmap();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 9: { QString _r = _t->getReadedSelNoPixmap();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 10: _t->setDateFormatColIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->setDateFormat((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->setCheckNoPixmap((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->setCheckYesPixmap((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->setCheckSelYesPixmap((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->setCheckSelNoPixmap((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->setMsContentBgColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 17: _t->setMsSelectedBgColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 18: _t->setReadedSelYesPixmap((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->setReadedSelNoPixmap((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MessagesStyle::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MessagesStyle::staticMetaObject = {
    { &ContactsStyle::staticMetaObject, qt_meta_stringdata_MessagesStyle,
      qt_meta_data_MessagesStyle, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MessagesStyle::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MessagesStyle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MessagesStyle::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MessagesStyle))
        return static_cast<void*>(const_cast< MessagesStyle*>(this));
    return ContactsStyle::qt_metacast(_clname);
}

int MessagesStyle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ContactsStyle::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = getDateFormatColIndex(); break;
        case 1: *reinterpret_cast< QString*>(_v) = getDateFormat(); break;
        case 2: *reinterpret_cast< QString*>(_v) = getSelectedPixmap(); break;
        case 3: *reinterpret_cast< QString*>(_v) = getCheckNoPixmap(); break;
        case 4: *reinterpret_cast< QString*>(_v) = getCheckYesPixmap(); break;
        case 5: *reinterpret_cast< QString*>(_v) = getCheckSelYesPixmap(); break;
        case 6: *reinterpret_cast< QString*>(_v) = getCheckSelNoPixmap(); break;
        case 7: *reinterpret_cast< QColor*>(_v) = getMsContentBgColor(); break;
        case 8: *reinterpret_cast< QColor*>(_v) = getMsSelectedBgColor(); break;
        case 9: *reinterpret_cast< QString*>(_v) = getReadedSelYesPixmap(); break;
        case 10: *reinterpret_cast< QString*>(_v) = getReadedSelNoPixmap(); break;
        }
        _id -= 11;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setDateFormatColIndex(*reinterpret_cast< int*>(_v)); break;
        case 1: setDateFormat(*reinterpret_cast< QString*>(_v)); break;
        case 2: setSelectedPixmap(*reinterpret_cast< QString*>(_v)); break;
        case 3: setCheckNoPixmap(*reinterpret_cast< QString*>(_v)); break;
        case 4: setCheckYesPixmap(*reinterpret_cast< QString*>(_v)); break;
        case 5: setCheckSelYesPixmap(*reinterpret_cast< QString*>(_v)); break;
        case 6: setCheckSelNoPixmap(*reinterpret_cast< QString*>(_v)); break;
        case 7: setMsContentBgColor(*reinterpret_cast< QColor*>(_v)); break;
        case 8: setMsSelectedBgColor(*reinterpret_cast< QColor*>(_v)); break;
        case 9: setReadedSelYesPixmap(*reinterpret_cast< QString*>(_v)); break;
        case 10: setReadedSelNoPixmap(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 11;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 11;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE

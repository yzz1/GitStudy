/****************************************************************************
** Meta object code from reading C++ file 'managerfilestyle.h'
**
** Created: Wed May 4 11:52:04 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../views/manager/managerfilestyle.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'managerfilestyle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ManagerFileStyle[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       8,   84, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: signature, parameters, type, tag, flags
      22,   17,   18,   17, 0x02,
      54,   17,   46,   17, 0x02,
      70,   17,   46,   17, 0x02,
      89,   17,   46,   17, 0x02,
     109,   17,   46,   17, 0x02,
     132,   17,   46,   17, 0x02,
     161,   17,  154,   17, 0x02,
     202,  183,   17,   17, 0x02,
     240,  229,   17,   17, 0x02,
     277,  263,   17,   17, 0x02,
     318,  303,   17,   17, 0x02,
     363,  345,   17,   17, 0x02,
     410,  393,   17,   17, 0x02,
     456,  439,   17,   17, 0x02,

 // properties: name, type, flags
     183,   18, 0x02095103,
     229,   46, 0x0a095103,
     484,   46, 0x0a095103,
     263,   46, 0x0a095103,
     303,   46, 0x0a095103,
     345,   46, 0x0a095103,
     393,   46, 0x0a095103,
     439,  154, 0x43095103,

       0        // eod
};

static const char qt_meta_stringdata_ManagerFileStyle[] = {
    "ManagerFileStyle\0\0int\0getDateFormatColIndex()\0"
    "QString\0getDateFormat()\0getCheckNoPixmap()\0"
    "getCheckYesPixmap()\0getCheckSelYesPixmap()\0"
    "getCheckSelNoPixmap()\0QColor\0"
    "getMsContentBgColor()\0dateFormatColIndex\0"
    "setDateFormatColIndex(int)\0dateFormat\0"
    "setDateFormat(QString)\0checkNoPixmap\0"
    "setCheckNoPixmap(QString)\0checkYesPixmap\0"
    "setCheckYesPixmap(QString)\0checkSelYesPixmap\0"
    "setCheckSelYesPixmap(QString)\0"
    "checkSelNoPixmap\0setCheckSelNoPixmap(QString)\0"
    "msContentBgColor\0setMsContentBgColor(QColor)\0"
    "selectedPixmap\0"
};

void ManagerFileStyle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ManagerFileStyle *_t = static_cast<ManagerFileStyle *>(_o);
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
        case 7: _t->setDateFormatColIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setDateFormat((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->setCheckNoPixmap((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->setCheckYesPixmap((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->setCheckSelYesPixmap((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->setCheckSelNoPixmap((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->setMsContentBgColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ManagerFileStyle::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ManagerFileStyle::staticMetaObject = {
    { &ContactsStyle::staticMetaObject, qt_meta_stringdata_ManagerFileStyle,
      qt_meta_data_ManagerFileStyle, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ManagerFileStyle::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ManagerFileStyle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ManagerFileStyle::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ManagerFileStyle))
        return static_cast<void*>(const_cast< ManagerFileStyle*>(this));
    return ContactsStyle::qt_metacast(_clname);
}

int ManagerFileStyle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ContactsStyle::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
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
        }
        _id -= 8;
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
        }
        _id -= 8;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE

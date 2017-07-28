/****************************************************************************
** Meta object code from reading C++ file 'dbconnect.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dbconnect.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dbconnect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_JsonParsingForApp_t {
    QByteArrayData data[1];
    char stringdata0[18];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_JsonParsingForApp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_JsonParsingForApp_t qt_meta_stringdata_JsonParsingForApp = {
    {
QT_MOC_LITERAL(0, 0, 17) // "JsonParsingForApp"

    },
    "JsonParsingForApp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_JsonParsingForApp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void JsonParsingForApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject JsonParsingForApp::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_JsonParsingForApp.data,
      qt_meta_data_JsonParsingForApp,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *JsonParsingForApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JsonParsingForApp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_JsonParsingForApp.stringdata0))
        return static_cast<void*>(const_cast< JsonParsingForApp*>(this));
    return QObject::qt_metacast(_clname);
}

int JsonParsingForApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_DBConnect_t {
    QByteArrayData data[28];
    char stringdata0[325];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DBConnect_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DBConnect_t qt_meta_stringdata_DBConnect = {
    {
QT_MOC_LITERAL(0, 0, 9), // "DBConnect"
QT_MOC_LITERAL(1, 10, 9), // "connected"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 6), // "result"
QT_MOC_LITERAL(4, 28, 7), // "failure"
QT_MOC_LITERAL(5, 36, 11), // "studiesList"
QT_MOC_LITERAL(6, 48, 13), // "sitesInfoList"
QT_MOC_LITERAL(7, 62, 16), // "subjectsInfoList"
QT_MOC_LITERAL(8, 79, 9), // "visitsMap"
QT_MOC_LITERAL(9, 89, 10), // "logoutInfo"
QT_MOC_LITERAL(10, 100, 5), // "login"
QT_MOC_LITERAL(11, 106, 8), // "dfserver"
QT_MOC_LITERAL(12, 115, 6), // "dfuser"
QT_MOC_LITERAL(13, 122, 6), // "dfpass"
QT_MOC_LITERAL(14, 129, 6), // "logout"
QT_MOC_LITERAL(15, 136, 10), // "getStudies"
QT_MOC_LITERAL(16, 147, 14), // "setStudyNumber"
QT_MOC_LITERAL(17, 162, 16), // "getSitesInfoList"
QT_MOC_LITERAL(18, 179, 19), // "getSubjectsInfoList"
QT_MOC_LITERAL(19, 199, 12), // "getVisitsMap"
QT_MOC_LITERAL(20, 212, 7), // "getKeys"
QT_MOC_LITERAL(21, 220, 8), // "getSetup"
QT_MOC_LITERAL(22, 229, 18), // "mergeKeyVisitsData"
QT_MOC_LITERAL(23, 248, 4), // "site"
QT_MOC_LITERAL(24, 253, 26), // "getModuleListsFromOnePlate"
QT_MOC_LITERAL(25, 280, 7), // "platNum"
QT_MOC_LITERAL(26, 288, 26), // "getFieldsListFromOneModule"
QT_MOC_LITERAL(27, 315, 9) // "moduleNum"

    },
    "DBConnect\0connected\0\0result\0failure\0"
    "studiesList\0sitesInfoList\0subjectsInfoList\0"
    "visitsMap\0logoutInfo\0login\0dfserver\0"
    "dfuser\0dfpass\0logout\0getStudies\0"
    "setStudyNumber\0getSitesInfoList\0"
    "getSubjectsInfoList\0getVisitsMap\0"
    "getKeys\0getSetup\0mergeKeyVisitsData\0"
    "site\0getModuleListsFromOnePlate\0platNum\0"
    "getFieldsListFromOneModule\0moduleNum"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DBConnect[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x06 /* Public */,
       4,    1,  112,    2, 0x06 /* Public */,
       5,    1,  115,    2, 0x06 /* Public */,
       6,    1,  118,    2, 0x06 /* Public */,
       7,    1,  121,    2, 0x06 /* Public */,
       8,    1,  124,    2, 0x06 /* Public */,
       9,    1,  127,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    3,  130,    2, 0x0a /* Public */,
      14,    0,  137,    2, 0x0a /* Public */,
      15,    0,  138,    2, 0x0a /* Public */,
      16,    1,  139,    2, 0x0a /* Public */,
      17,    0,  142,    2, 0x0a /* Public */,
      18,    1,  143,    2, 0x0a /* Public */,
      19,    0,  146,    2, 0x0a /* Public */,
      20,    1,  147,    2, 0x0a /* Public */,
      21,    0,  150,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      22,    2,  151,    2, 0x02 /* Public */,
      24,    1,  156,    2, 0x02 /* Public */,
      26,    2,  159,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString,   11,   12,   13,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::UInt,    2,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::Int,    2,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::Int,    2,
    QMetaType::Bool,

 // methods: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   23,    2,
    QMetaType::QStringList, QMetaType::QString,   25,
    QMetaType::QString, QMetaType::QString, QMetaType::QString,   25,   27,

       0        // eod
};

void DBConnect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DBConnect *_t = static_cast<DBConnect *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->failure((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->studiesList((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->sitesInfoList((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->subjectsInfoList((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->visitsMap((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->logoutInfo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: { bool _r = _t->login((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: { bool _r = _t->logout();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->getStudies();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->setStudyNumber((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { bool _r = _t->getSitesInfoList();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->getSubjectsInfoList((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: { bool _r = _t->getVisitsMap();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 14: { bool _r = _t->getKeys((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: { bool _r = _t->getSetup();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 16: _t->mergeKeyVisitsData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 17: { QStringList _r = _t->getModuleListsFromOnePlate((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 18: { QString _r = _t->getFieldsListFromOneModule((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DBConnect::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DBConnect::connected)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DBConnect::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DBConnect::failure)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (DBConnect::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DBConnect::studiesList)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (DBConnect::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DBConnect::sitesInfoList)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (DBConnect::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DBConnect::subjectsInfoList)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (DBConnect::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DBConnect::visitsMap)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (DBConnect::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DBConnect::logoutInfo)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject DBConnect::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DBConnect.data,
      qt_meta_data_DBConnect,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DBConnect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DBConnect::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DBConnect.stringdata0))
        return static_cast<void*>(const_cast< DBConnect*>(this));
    return QObject::qt_metacast(_clname);
}

int DBConnect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void DBConnect::connected(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DBConnect::failure(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DBConnect::studiesList(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DBConnect::sitesInfoList(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DBConnect::subjectsInfoList(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DBConnect::visitsMap(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void DBConnect::logoutInfo(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

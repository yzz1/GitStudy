/****************************************************************************
**
** 文件名称： sqlitehelper.h
** 功能概述:  数据库操作中继类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef SQLITEHELPER_H
#define SQLITEHELPER_H

#include <QObject>
#include <QMap>
#include <QtSql/QSqlDatabase>
#include <QVariantMap>
#include <QtSql/QSqlTableModel>

class QXmlStreamReader;
class Database;

class SQLiteHelper : public QObject
{
        Q_OBJECT
    public:
    
        static QSqlDatabase openConnection();
        
        static void closeConnection();
        
        static bool exportData(const QString& tableName, const QString& fileName  = NULL,
                               const QString& messageInOutFlag = "I");
                               
        static bool importData(const QString& filePath, QSqlTableModel* model);
        
        static bool printData(const QString& tableName, QString& printStr, const QString& messageInOutFlag = "I",
                              const QString& strUUID = "I");
                              
        static bool printStr(const QString& str);
        
        static void beginTransaction();
        
        static void endTransaction();
        
        static bool parseXmlToTable(QSqlTableModel* model, QXmlStreamReader& reader);
        
        static bool parseNormalToTable(QSqlTableModel* model, QXmlStreamReader& reader);
        
        static bool parseManagerFileToTable(const QString& filePath, QSqlTableModel* model, QString& fileName);
        
        static bool parseFkeyTable(QXmlStreamReader& reader, QString& fkey, Database* database);
        //static void insert(QString table, QMap<QString, QVariant> params);
        
        //static void update(QString table, QMap<QString, QVariant> params);
        
        //static void select(QString table, QMap<QString, QVariant> params);
        
        static void exec(const QString& sql, const QVariantMap& params);
        
        static QList<QVariantMap> select(const QString& sql, const QVariantMap& params);
        
    private:
        //void SQLiteHelper::queryTableInfo(QStringList & fields, QStringList & values);
        
};

#endif // SQLITEHELPER_H

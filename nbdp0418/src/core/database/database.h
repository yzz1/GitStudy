/****************************************************************************
**
** 文件名称： database.h
** 功能概述:  数据库类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QVariantMap>
#include <QSqlQuery>

class DatabasePrivate;

class Database : public QObject
{
        Q_OBJECT
    public:
        explicit Database(QObject* parent = 0);
        
        void openConnection();
        
        void closeConnection();
        
        QSqlQuery getQuery();
        
        bool executeSql(const QString& sql, const QVariantMap& params);
        
        bool transaction();
        
        bool commit();
        
        bool rollback();
        
        void sync();
        
    signals:
    
    public slots:
    
    private:
        DatabasePrivate* d;
};

#endif // DATABASE_H

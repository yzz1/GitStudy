#include <QSqlDatabase>
#include <QSqlQuery>
#include "database.h"
#include <QSettings>
#include <QDir>
#include <QApplication>
#include <QDebug>
#include <QSqlError>
#include <QSqlDriver>
#include <QLatin1String>
#include "connectionpool.h"
#include "core/utils/pathresolve.h"

class DatabasePrivate
{
    public:
        QSqlDatabase db;
        QSqlQuery query;
        
        void bindValues(const QVariantMap& params) ;
};
/****************************************************************************
**
** 函数名称：Database::Database
** 功能概述: 初始化
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
Database::Database(QObject* parent) : QObject(parent)
{
    d = new DatabasePrivate();
}
/****************************************************************************
**
** 函数名称：Database::openConnection
** 功能概述: 打开数据库
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Database::openConnection()
{
    if (QSqlDatabase::contains("nbdp"))
    {
        d->db =  QSqlDatabase::database("nbdp");
    }
    else
    {
        d->db = QSqlDatabase::addDatabase("QSQLITE", "nbdp");
        d->db.setDatabaseName(PathResolve::databaseFile());
        d->db.setPort(3306);
    }
    
    if (!d->db.isOpen())
    {
        d->db.open();
    }
    
    d->query = QSqlQuery(d->db);
}
/****************************************************************************
**
** 函数名称：Database::closeConnection
** 功能概述: 关闭数据库
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Database::closeConnection()
{
    ConnectionPool::closeConnection(d->db);
}
/****************************************************************************
**
** 函数名称：Database::closeConnection
** 功能概述: 调用SQL语句
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool Database::executeSql(const QString& sql, const QVariantMap& params)
{
    d->query.prepare(sql);
    d->bindValues(params);
    
    if (d->query.exec())
    {
    }
    
    if (d->query.lastError().type() != QSqlError::NoError)
    {
        // log->debug("SQL Error :" + d->query.lastError().text().trimmed());
        return false;
    }
    
    // log->debug("SQL Query :" + d->query.lastQuery());
    
    if (params.size() > 0)
    {
        QString paramStr = "";
        
        for (QVariantMap::const_iterator i = params.constBegin(); i != params.constEnd(); ++i)
        {
            paramStr.append(i.key())
            .append(QLatin1String("="))
            .append(i.value().toString())
            .append(QLatin1String(" "));
        }
        
        // log->debug("SQL Params :" + params.size());
    }
    
    return true;
}
/****************************************************************************
**
** 函数名称：Database::closeConnection
** 功能概述: SQL参数组合
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void DatabasePrivate::bindValues(const QVariantMap& params)
{
    for (QVariantMap::const_iterator i = params.constBegin(); i != params.constEnd(); ++i)
    {
        query.bindValue(":" + i.key(), i.value());
    }
}
/****************************************************************************
**
** 函数名称：Database::closeConnection
** 功能概述: 打开事务
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool Database::transaction()
{
    if (!d->db.isOpen())
        return false;
        
    if (d->db.driver()->hasFeature(QSqlDriver::Transactions))
    {
        return d->db.transaction();
    }
    
    return false;
}
/****************************************************************************
**
** 函数名称：Database::closeConnection
** 功能概述: 提交数据
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool Database::commit()
{
    if (!d->db.isOpen())
        return false;
        
    return d->db.commit();
}
/****************************************************************************
**
** 函数名称：Database::rollback
** 功能概述: 回滚数据
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool Database::rollback()
{
    if (!d->db.isOpen())
        return false;
        
    return d->db.rollback();
}
/****************************************************************************
**
** 函数名称：Database::sync
** 功能概述:
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Database::sync()
{
}
/****************************************************************************
**
** 函数名称：Database::getQuery
** 功能概述: 获取数据库句柄
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QSqlQuery Database::getQuery()
{
    return d->query;
}

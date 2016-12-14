/****************************************************************************
**
** 文件名称： connectionpool.h
** 功能概述:  数据库连接基础类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef CONNECTIONPOOL_H
#define CONNECTIONPOOL_H

class QSqlDatabase;
class ConnectionPoolPrivate;

class ConnectionPool
{
    public:
        static void release();
        static QSqlDatabase openConnection();
        static void closeConnection(const QSqlDatabase& connection);
        
        ~ConnectionPool();
        
    private:
        static ConnectionPool& getInstance();
        
        ConnectionPool();
        ConnectionPool(const ConnectionPool& other);
        ConnectionPool& operator=(const ConnectionPool& other);
        
        ConnectionPoolPrivate* data;
        static ConnectionPool* instance;
};

#endif // CONNECTIONPOOL_H

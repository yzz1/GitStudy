#include "connectionpool.h"
#include "core/utils/configutils.cpp"
#include <QDebug>
#include <QtSql>
#include <QStack>
#include <QString>
#include <QMutex>
#include <QSemaphore>
#include "core/utils/pathresolve.h"

class ConnectionPoolPrivate
{
    public:
        ConnectionPoolPrivate();
        ~ConnectionPoolPrivate();
        
        QSqlDatabase createConnection(const QString& connectionName); // 创建数据库连接
        
        QStack<QString> usedConnectionNames;   // 已使用的数据库连接名
        QStack<QString> unusedConnectionNames; // 未使用的数据库连接名
        
        // 数据库信息
        QString hostName;
        QString databaseName;
        QString username;
        QString password;
        QString databaseType;
        int port;
        
        bool    testOnBorrow;    // 取得连接的时候验证连接有效
        QString testOnBorrowSql; // 测试访问数据库的 SQL
        int maxWaitTime;         // 获取连接最大等待时间
        int maxConnectionCount;  // 最大连接数
        
        QSemaphore* semaphore;
        
        static QMutex mutex;
        static int lastKey; // 用来创建连接的名字，保证连接名字不会重复
};

QMutex ConnectionPoolPrivate::mutex;
int ConnectionPoolPrivate::lastKey = 0;
/****************************************************************************
**
** 函数名称：ConnectionPoolPrivate::ConnectionPoolPrivate
** 功能概述: 初始化
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ConnectionPoolPrivate::ConnectionPoolPrivate()
{
    // 从配置文件里读取
    QSettings  settings(PathResolve::resourcesPath() + "config/db.properties", QSettings::IniFormat);
    hostName     = settings.value(QLatin1String("hostName")).toString();;
    databaseName = settings.value(QLatin1String("databaseName")).toString();;
    databaseType = settings.value(QLatin1String("type")).toString();;
    port         = settings.value(QLatin1String("port"), 0).toInt();
    testOnBorrow = settings.value(QLatin1String("testOnBorrow"), false).toBool();;
    testOnBorrowSql = settings.value(QLatin1String("testOnBorrowSql"), "select 1").toString();;
    maxWaitTime     = settings.value(QLatin1String("maxWaitTime"), 5000).toInt();;
    maxConnectionCount = settings.value(QLatin1String("maxConnectionCount"), 5).toInt();;
    semaphore = new QSemaphore(maxConnectionCount);
}
/****************************************************************************
**
** 函数名称：ConnectionPoolPrivate::~ConnectionPoolPrivate
** 功能概述: 析构函数
** 参数说明： 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ConnectionPoolPrivate::~ConnectionPoolPrivate()
{
    // 销毁连接池的时候删除所有的连接
    foreach(QString connectionName, usedConnectionNames)
    {
        createConnection(connectionName).close();
        QSqlDatabase::removeDatabase(connectionName);
    }
    foreach(QString connectionName, unusedConnectionNames)
    {
        QSqlDatabase::removeDatabase(connectionName);
    }
    delete semaphore;
}
/****************************************************************************
**
** 函数名称：ConnectionPoolPrivate::createConnection
** 功能概述: 建立连接
** 参数说明： 数据库名称
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QSqlDatabase ConnectionPoolPrivate::createConnection(const QString& connectionName)
{
    // 连接已经创建过了，复用它，而不是重新创建
    if (QSqlDatabase::contains(connectionName))
    {
        QSqlDatabase db1 = QSqlDatabase::database(connectionName);
        
        if (testOnBorrow)
        {
            // 返回连接前访问数据库，如果连接断开，重新建立连接
            qDebug() << QString("Test connection on borrow, execute: %1, for connection %2")
                     .arg(testOnBorrowSql).arg(connectionName);
            QSqlQuery query(testOnBorrowSql, db1);
            
            if (query.lastError().type() != QSqlError::NoError && !db1.open())
            {
                qDebug() << "Open datatabase error:" << db1.lastError().text();
                return QSqlDatabase();
            }
        }
        
        return db1;
    }
    
    // 创建一个新的连接
    QSqlDatabase db = QSqlDatabase::addDatabase(databaseType, connectionName);
    //db.setHostName(hostName);
    QString dbPath = PathResolve::resourcesPath().append(QLatin1String("db/")).append(databaseName);
    qDebug() << dbPath;
    db.setDatabaseName(dbPath);
    //db.setUserName(username);
    //db.setPassword(password);
    
    if (port != 0)
    {
        db.setPort(port);
    }
    
    if (!db.open())
    {
        qDebug() << "Open datatabase error:" << db.lastError().text();
        return QSqlDatabase();
    }
    
    return db;
}

ConnectionPool* ConnectionPool::instance = NULL;
/****************************************************************************
**
** 函数名称：ConnectionPool::ConnectionPool
** 功能概述: 初始化
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ConnectionPool::ConnectionPool()
{
    data = new ConnectionPoolPrivate();
}
/****************************************************************************
**
** 函数名称：ConnectionPool::ConnectionPool
** 功能概述: 析构函数
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ConnectionPool::~ConnectionPool()
{
    delete data;
}
/****************************************************************************
**
** 函数名称：ConnectionPool::getInstance
** 功能概述: 获取连接实例
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ConnectionPool& ConnectionPool::getInstance()
{
    if (NULL == instance)
    {
        QMutexLocker locker(&ConnectionPoolPrivate::mutex);
        
        if (NULL == instance)
        {
            instance = new ConnectionPool();
        }
    }
    
    return *instance;
}
/****************************************************************************
**
** 函数名称：ConnectionPool::release
** 功能概述: 解除连接
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ConnectionPool::release()
{
    QMutexLocker locker(&ConnectionPoolPrivate::mutex);
    delete instance;
    instance = NULL;
}
/****************************************************************************
**
** 函数名称：ConnectionPool::openConnection
** 功能概述: 创建连接
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QSqlDatabase ConnectionPool::openConnection()
{
    ConnectionPool& pool = ConnectionPool::getInstance();
    
    if (pool.data->semaphore->tryAcquire(1, pool.data->maxWaitTime))
    {
        // 有已经回收的连接，复用它们
        // 没有已经回收的连接，则创建新的连接
        ConnectionPoolPrivate::mutex.lock();
        QString connectionName = pool.data->unusedConnectionNames.size() > 0 ?
                                 pool.data->unusedConnectionNames.pop() :
                                 QString("C%1").arg(++ConnectionPoolPrivate::lastKey);
        pool.data->usedConnectionNames.push(connectionName);
        ConnectionPoolPrivate::mutex.unlock();
        // 创建连接。因为创建连接很耗时，所以不放在 lock 的范围内，提高并发效率
        QSqlDatabase db = pool.data->createConnection(connectionName);
        
        if (!db.isOpen())
        {
            ConnectionPoolPrivate::mutex.lock();
            int index = pool.data->usedConnectionNames.indexOf(connectionName);
            pool.data->usedConnectionNames.remove(index); // 无效连接删除
            ConnectionPoolPrivate::mutex.unlock();
            pool.data->semaphore->release(); // 没有消耗连接
        }
        
        return db;
    }
    else
    {
        // 创建连接超时，返回一个无效连接
        qDebug() << "Time out to create connection.";
        return QSqlDatabase();
    }
}
/****************************************************************************
**
** 函数名称：ConnectionPool::closeConnection
** 功能概述: 关闭连接
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ConnectionPool::closeConnection(const QSqlDatabase& connection)
{
    ConnectionPool& pool = ConnectionPool::getInstance();
    QString connectionName = connection.connectionName();
    
    // 如果是我们创建的连接，并且已经被使用，则从 used 里删除，放入 unused 里
    if (pool.data->usedConnectionNames.contains(connectionName))
    {
        QMutexLocker locker(&ConnectionPoolPrivate::mutex);
        int index = pool.data->usedConnectionNames.indexOf(connectionName);
        pool.data->usedConnectionNames.remove(index);
        pool.data->unusedConnectionNames.push(connectionName);
        pool.data->semaphore->release();
    }
}

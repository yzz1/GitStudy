#include "sqls.h"
#include "core/utils/configutils.h"

#include <QFile>
#include <QDebug>
#include <QXmlInputSource>
#include <QXmlAttributes>
#include <QXmlParseException>
#include <QXmlDefaultHandler>

static const char* const SQL_ID              = "id";
static const char* const SQL_REF_ID          = "refId";
static const char* const SQL_TAGNAME_SQL     = "sql";
static const char* const SQL_TAGNAME_SQLS    = "sqls";
static const char* const SQL_TAGNAME_DEFINE  = "define";
static const char* const SQL_TAGNAME_INCLUDE = "include";
static const char* const SQL_NAMESPACE       = "namespace";

class SqlsPrivate : public QXmlDefaultHandler
{
    public:
        SqlsPrivate(Sqls* cxt);
        static QString buildKey(const QString& sqlNamespace, const QString& id);
        
    protected:
        bool startElement(const QString& namespaceURI,
                          const QString& localName,
                          const QString& qName,
                          const QXmlAttributes& attributes);
        bool endElement(const QString& namespaceURI, const QString& localName, const QString& qName);
        bool characters(const QString& str);
        bool fatalError(const QXmlParseException& exception);
        
    private:
        QHash<QString, QString> defines;
        QString sqlNamespace;
        QString currentText;
        QString currentSqlId;
        QString currentDefineId;
        QString currentRefId;
        
        Sqls* cxt;
};
/****************************************************************************
**
** 函数名称：SqlsPrivate::SqlsPrivate
** 功能概述: 初始化
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
SqlsPrivate::SqlsPrivate(Sqls* cxt)
{
    this->cxt = cxt;
    QStringList sqlFiles /*= ConfigUtils::getInstance().getDatabaseSqlFiles()*/;
    foreach(QString fileName, sqlFiles)
    {
        qDebug() << QString("Loading SQL file: %1").arg(fileName);
        QFile file(fileName);
        QXmlInputSource inputSource(&file);
        QXmlSimpleReader reader;
        reader.setContentHandler(this);
        reader.setErrorHandler(this);
        reader.parse(inputSource);
        defines.clear();
    }
}
/****************************************************************************
**
** 函数名称：SqlsPrivate::buildKey
** 功能概述: SQL语句组合
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QString SqlsPrivate::buildKey(const QString& sqlNamespace, const QString& id)
{
    return sqlNamespace + "::" + id;
}
/****************************************************************************
**
** 函数名称：SqlsPrivate::startElement
** 功能概述: XML标签开始
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool SqlsPrivate::startElement(const QString& namespaceURI,
                               const QString& localName,
                               const QString& qName,
                               const QXmlAttributes& attributes)
{
    Q_UNUSED(namespaceURI)
    Q_UNUSED(localName)
    
    // 1. 取得 SQL 得 xml 文档中得 namespace, sql id, refid, include id
    // 2. 如果是 <sql> 标签，清空 currentText
    // 3. 如果是 <define> 标签，清空 currentText
    if (SQL_TAGNAME_SQL == qName)
    {
        currentSqlId = attributes.value(SQL_ID);
        currentText = "";
    }
    else if (SQL_TAGNAME_INCLUDE == qName)
    {
        currentRefId = attributes.value(SQL_REF_ID);
    }
    else if (SQL_TAGNAME_DEFINE == qName)
    {
        currentDefineId = attributes.value(SQL_ID);
        currentText = "";
    }
    else if (SQL_TAGNAME_SQLS == qName)
    {
        sqlNamespace = attributes.value(SQL_NAMESPACE);
    }
    
    return true;
}
/****************************************************************************
**
** 函数名称：SqlsPrivate::endElement
** 功能概述: XML标签结束
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool SqlsPrivate::endElement(const QString& namespaceURI, const QString& localName, const QString& qName)
{
    Q_UNUSED(namespaceURI)
    Q_UNUSED(localName)
    
    // 1. 如果是 <sql> 标签，则插入 sqls
    // 2. 如果是 <include> 标签，则从 defines 里取其内容加入 sql
    // 3. 如果是 <define> 标签，则存入 defines
    if (SQL_TAGNAME_SQL == qName)
    {
        // 取到一个完整的 SQL 语句
        cxt->sqls.insert(buildKey(sqlNamespace, currentSqlId), currentText.simplified());
        currentText = "";
    }
    else if (SQL_TAGNAME_INCLUDE == qName)
    {
        QString def = defines.value(buildKey(sqlNamespace, currentRefId));
        QString defineKey = buildKey(sqlNamespace, currentRefId);
        
        if (!def.isEmpty())
        {
            currentText += defines.value(defineKey);
        }
        else
        {
            qDebug() << "Cannot find define: " << defineKey;
        }
    }
    else if (SQL_TAGNAME_DEFINE == qName)
    {
        defines.insert(buildKey(sqlNamespace, currentDefineId), currentText.simplified());
    }
    
    return true;
}
/****************************************************************************
**
** 函数名称：SqlsPrivate::characters
** 功能概述: 插入标签内的值
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool SqlsPrivate::characters(const QString& str)
{
    currentText += str;
    return true;
}
/****************************************************************************
**
** 函数名称：SqlsPrivate::fatalError
** 功能概述: 报错
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool SqlsPrivate::fatalError(const QXmlParseException& exception)
{
    qDebug() << QString("Parse error at line %1, column %2, message: %3")
             .arg(exception.lineNumber())
             .arg(exception.columnNumber())
             .arg(exception.message());
    return false;
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                 Sqls 的定义                               ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////
SINGLETON_INITIALIZE(Sqls)
SINGLETON_DESTRUCTOR(Sqls)
/****************************************************************************
**
** 函数名称：Sqls::Sqls
** 功能概述: 初始化
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
Sqls::Sqls()
{
    SqlsPrivate* data = new SqlsPrivate(this); // 读取 SQL 文件，内容放到 QHash sqls 里
    delete data; // 不需要 data 了，所以删除掉它
}
/****************************************************************************
**
** 函数名称：Sqls::getSql
** 功能概述: 获取SQL语句
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QString Sqls::getSql(const QString& sqlNamespace, const QString& sqlId)
{
    QString sql = Sqls::getInstance().sqls.value(SqlsPrivate::buildKey(sqlNamespace, sqlId));
    
    if (sql.isEmpty())
    {
        qDebug() << QString("Cannot find SQL for %1::%2").arg(sqlNamespace).arg(sqlId);
    }
    
    return sql;
}

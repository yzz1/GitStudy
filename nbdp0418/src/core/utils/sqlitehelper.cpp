#include "sqlitehelper.h"
#include "pathresolve.h"
#include "constants.h"
#include "views/common/constants.h"
#include "intputcheck.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QStringList>
#include <QXmlStreamWriter>
#include <QDomElement>
#include <QFile>
#include <QDateTime>
#include <QDebug>
#include <QSqlRecord>
#include <QVariantMap>
#include <QSqlError>
#include "QUuid"
#include "QDateTime"
#include "core/database/database.h"
#include <QDebug>
#include "core/serialport/serialportcommunication.h"

using namespace Constants;
/****************************************************************************
**
** 函数名称：SQLiteHelper::openConnection
** 功能概述: 连接数据库
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QSqlDatabase SQLiteHelper::openConnection()
{
    if (QSqlDatabase::contains(Core::Constants::CONNECTION_NAME))
    {
        return QSqlDatabase::database(Core::Constants::CONNECTION_NAME);
    }
    
    QSqlDatabase database = QSqlDatabase::addDatabase(Core::Constants::DB_TYPE_SQLITE, Core::Constants::CONNECTION_NAME);
   // qDebug()<<"database path"<<PathResolve::databaseFile();

    database.setDatabaseName(PathResolve::databaseFile());
    database.setPort(Core::Constants::SQLITE_PORT);
    
    if (!database.isOpen())
    {
        database.open();
    }
    
    return database;
}
/****************************************************************************
**
** 函数名称：SQLiteHelper::closeConnection
** 功能概述: 关闭数据库
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SQLiteHelper::closeConnection()
{
    if (QSqlDatabase::contains(Core::Constants::CONNECTION_NAME))
    {
        QSqlDatabase database =  QSqlDatabase::database(Core::Constants::CONNECTION_NAME);
        database.close();
    }
}
/****************************************************************************
**
** 函数名称：SQLiteHelper::beginTransaction
** 功能概述: 打开数据库事务
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SQLiteHelper::beginTransaction()
{
    if (QSqlDatabase::contains(Core::Constants::CONNECTION_NAME))
    {
        QSqlDatabase database =  QSqlDatabase::database(Core::Constants::CONNECTION_NAME);
        database.transaction();
    }
}
/****************************************************************************
**
** 函数名称：SQLiteHelper::endTransaction
** 功能概述: 关闭数据库事务
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SQLiteHelper::endTransaction()
{
    if (QSqlDatabase::contains(Core::Constants::CONNECTION_NAME))
    {
        QSqlDatabase database =  QSqlDatabase::database(Core::Constants::CONNECTION_NAME);
        database.commit();
    }
}
/****************************************************************************
**
** 函数名称：SQLiteHelper::exec
** 功能概述: 提交SQL语句
** 参数说明：sql:SQL语句   params：语句参数
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SQLiteHelper::exec(const QString& sql, const QVariantMap& params)
{
    if (QSqlDatabase::contains(Core::Constants::CONNECTION_NAME))
    {
        QSqlDatabase database =  QSqlDatabase::database(Core::Constants::CONNECTION_NAME);
        QSqlQuery query(database);
        query.prepare(sql);
        
        for (QVariantMap::const_iterator i = params.constBegin(); i != params.constEnd(); ++i)
        {
            query.bindValue(":" + i.key(), i.value());
        }
        
        query.exec();
        bool result = query.lastError().type() == QSqlError::NoError;
        int i = 1;
    }
}
/****************************************************************************
**
** 函数名称：SQLiteHelper::select
** 功能概述: 查询数据库
** 参数说明：sql:SQL语句   params：语句参数
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QList<QVariantMap> SQLiteHelper::select(const QString& sql, const QVariantMap& params)
{
    if (QSqlDatabase::contains(Core::Constants::CONNECTION_NAME))
    {
        QSqlDatabase database =  QSqlDatabase::database(Core::Constants::CONNECTION_NAME);
        QSqlQuery query(database);
        query.prepare(sql);
        
        for (QVariantMap::const_iterator i = params.constBegin(); i != params.constEnd(); ++i)
        {
            query.bindValue(":" + i.key(), i.value());
        }
        
        query.exec();
        QList<QVariantMap> rowMaps;
        QSqlRecord record = query.record();
        int count = record.count();
        
        while (query.next())
        {
            QVariantMap rowMap;
            
            for (int i = 0; i < count; i++)
            {
                rowMap.insert(record.fieldName(i), query.value(i));
            }
            
            rowMaps.append(rowMap);
        }
        
        return rowMaps;
    }
}
/****************************************************************************
**
** 函数名称：SQLiteHelper::select
** 功能概述: 打印数据
** 参数说明：tableName：表名称, printStr：打印字符串,messageInOutFlag：message标记 或文件名,strUUID：数据的UUID
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool SQLiteHelper::printData(const QString& tableName, QString& printStr, const QString& messageInOutFlag,
                             const QString& strUUID)
{
    printStr += "\n";
    QSqlDatabase database =  openConnection();
    QSqlQuery query(database);
    QString fileRealName = messageInOutFlag;
    
    if (tableName.toLower() == "message")
    {
        QString tablesqlselect =
            QString(" select count(*)  from message where checkFlag = 1 and InputOutput = '%1' and uuid = '%2'")
            .arg(messageInOutFlag).arg(strUUID);
        qDebug() << tablesqlselect;
        query.prepare(tablesqlselect);
        query.exec();
        query.next();
        
        if (!query.value(0).toBool())
        {
            return false;
        }
    }
    
    QStringList fields;
    QStringList values;
    query.exec(QString("pragma table_info(%1)").arg(tableName));
    
    while (query.next())
    {
        fields << query.value(1).toString();
    }
    
    QString fieldNames = fields.join(",");
    
    if (tableName.toLower() == "message")
    {
        QString checkFlagName  = "checkFlag";
        QString inputOutputName  = "InputOutput";
        //QString temp = "I";
        QString sql = QString(" select %1 from %2 where %3 = 1 and %4 = '%5'and uuid = '%6'")
                      .arg(fieldNames).arg(tableName)
                      .arg(checkFlagName).arg(inputOutputName).arg(messageInOutFlag).arg(strUUID);
        query.prepare(sql);
    }
    else
    {
        QString sql = QString(" select %1 from %2").arg(fieldNames).arg(tableName);
        query.prepare(sql);
    }
    
    query.exec();
    
    while (query.next())
    {
        for (int i = 0; i < fields.size(); i++)
        {
            values << query.value(i).toString();
        }
    }
    
    if (tableName.toLower() == "message")
    {
        QTextStream out(&printStr);
        int rowNum = 0;
        int count = 1;
        
        for (int i = 0; i < values.size(); i++)
        {
            if (i % fields.size() == 0)
            {
                out << "/************/" << endl;
                
                if (count < 10)
                    out << "message_0" << count++ << endl;
                else
                    out << "message_" << count++ << endl;
                    
                out << "/************/" << endl;
            }
            
            if (fields.at(i % fields.size()) == "UUID" || fields.at(i % fields.size()) == "checkFlag" ||
                fields.at(i % fields.size()) == "showPix" || fields.at(i % fields.size()) == "Tx" ||
                fields.at(i % fields.size()) == "Rx")
                continue;
                
            out << fields.at(i % fields.size()) << ":" << values.at(i) << endl;
            
            if ((i + 1) % fields.size() == 0)
            {
                QString relationTable  = "MessageDetail";
                QStringList relationFields;
                QStringList relationValues;
                int indexColumn = 0;
                QString fKeyName  = "fkey";
                QString sql2 = QString(" select InputOutput,Content,CommunicationDateTime from %2 where %3 = '%4' ")
                               .arg(relationTable).arg(fKeyName).arg(values.at(rowNum * fields.size() + indexColumn));
                query.prepare(sql2);
                query.exec();
                int selectColumn = 3;
                
                while (query.next())
                {
                    for (int i = 0; i < selectColumn; i++)
                    {
                        relationValues << query.value(i).toString();
                    }
                }
                
                if (relationValues.size()  > 0)
                {
                    out << "/************/" << endl;
                    out << "Detail" << endl;
                    out << "/************/" << endl;
                    
                    for (int i = 0; i < relationValues.size(); i++)
                    {
                        if (relationValues.at(i) == "I")
                        {
                            out << "InPut:" << relationValues.at(i + 1) << endl;
                            out << "I_Datatime:" << relationValues.at(i + 2) << endl;
                            i = i + 2;
                        }
                        else if (relationValues.at(i) == "O")
                        {
                            out << "OutPut:" << relationValues.at(i + 1) << endl;
                            out << "O_Datatime:" << relationValues.at(i + 2) << endl;
                            i = i + 2;
                        }
                    }
                }
                
                out << endl;
                rowNum++;
            }
        }
    }
    else if (tableName.toLower() == "file")
    {
        for (int i = 0; i < values.size(); i++)
        {
            if (fields.at(i % fields.size()).toLower() == "name")
            {
                if (values.at(i) == fileRealName)
                {
                    QTextStream out(&printStr);
                    out << values.at(i + 1);
                    break;
                }
            }
        }
    }
    else
    {
        QXmlStreamWriter xmlWriter(&printStr);
        xmlWriter.setAutoFormatting(true);
        xmlWriter.writeStartDocument();
        xmlWriter.writeStartElement(tableName + "s");
        int rowNum = 0;
        
        for (int i = 0; i < values.size(); i++)
        {
            if (i % fields.size() == 0)
            {
                xmlWriter.writeStartElement(tableName);
            }
            
            xmlWriter.writeTextElement(fields.at(i % fields.size()), values.at(i));
            
            if ((i + 1) % fields.size() == 0)
            {
                if (tableName.toLower() == "station" || tableName.toLower() == "individual")
                {
                    QString relationTable  = "frequency";
                    QStringList relationFields;
                    QStringList relationValues;
                    int indexColumn = 0;
                    QString fKeyName  = "fkey";
                    query.exec(QString("pragma table_info(%1)").arg(relationTable));
                    
                    while (query.next())
                    {
                        relationFields << query.value(1).toString();
                    }
                    
                    QString relationFieldNames = relationFields.join(",");
                    QString sql2 = QString(" select %1 from %2 where %3 = '%4' ")
                                   .arg(relationFieldNames).arg(relationTable)
                                   .arg(fKeyName).arg(values.at(rowNum * fields.size() + indexColumn));
                    query.prepare(sql2);
                    query.exec();
                    
                    while (query.next())
                    {
                        for (int i = 0; i < relationFields.size(); i++)
                        {
                            relationValues << query.value(i).toString();
                        }
                    }
                    
                    if (relationValues.size()  > 0)
                    {
                        xmlWriter.writeStartElement(relationTable + "s");
                        
                        for (int i = 0; i < relationValues.size(); i++)
                        {
                            if (i % relationFields.size() == 0)
                            {
                                xmlWriter.writeStartElement(relationTable);
                            }
                            
                            xmlWriter.writeTextElement(relationFields.at(i % relationFields.size()), relationValues.at(i));
                            
                            if ((i + 1) % relationFields.size() == 0)
                            {
                                xmlWriter.writeEndElement();
                            }
                        }
                        
                        xmlWriter.writeEndElement();
                    }
                }
                else if (tableName.toLower()  == "message")
                {
                    QString relationTable  = "MessageDetail";
                    QStringList relationFields;
                    QStringList relationValues;
                    int indexColumn = 0;
                    QString fKeyName  = "fkey";
                    query.exec(QString("pragma table_info(%1)").arg(relationTable));
                    
                    while (query.next())
                    {
                        relationFields << query.value(1).toString();
                    }
                    
                    QString relationFieldNames = relationFields.join(",");
                    QString sql2 = QString(" select %1 from %2 where %3 = '%4' ")
                                   .arg(relationFieldNames).arg(relationTable)
                                   .arg(fKeyName).arg(values.at(rowNum * fields.size() + indexColumn));
                    query.prepare(sql2);
                    query.exec();
                    
                    while (query.next())
                    {
                        for (int i = 0; i < relationFields.size(); i++)
                        {
                            relationValues << query.value(i).toString();
                        }
                    }
                    
                    if (relationValues.size()  > 0)
                    {
                        xmlWriter.writeStartElement(relationTable + "s");
                        
                        for (int i = 0; i < relationValues.size(); i++)
                        {
                            if (i % relationFields.size() == 0)
                            {
                                xmlWriter.writeStartElement(relationTable);
                            }
                            
                            xmlWriter.writeTextElement(relationFields.at(i % relationFields.size()), relationValues.at(i));
                            
                            if ((i + 1) % relationFields.size() == 0)
                            {
                                xmlWriter.writeEndElement();
                            }
                        }
                        
                        xmlWriter.writeEndElement();
                    }
                }
                
                xmlWriter.writeEndElement();
                rowNum++;
            }
        }
        
        xmlWriter.writeEndElement();
        xmlWriter.writeEndDocument();
    }
    
    SerialPortCommunication* printer = SerialPortCommunication::get();
    printStr += "\n";
    printStr += "\n";
    printStr += "\n";
    printStr += "\n";
    printStr += "\n";
    printStr += "\n";
    printStr += "\n";
    printStr += "\n";
    printStr += "\n";
    printStr += "\n";
    std::string str = printStr.toStdString();
    const char* ch = str.c_str();
    printer->writeData(ch, printStr.length());
    return true;
}
/****************************************************************************
**
** 函数名称：SQLiteHelper::select
** 功能概述: 打印数据
** 参数说明：打印字符串
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool SQLiteHelper::printStr(const QString& str)
{
    QString str1;
    str1 += "\n";
    str1 += str;
    SerialPortCommunication* printer = SerialPortCommunication::get();
    std::string str2 = str1.toStdString();
    const char* ch = str2.c_str();
    printer->writeData(ch, str1.length());
    return true;
}
/****************************************************************************
**
** 函数名称：SQLiteHelper::select
** 功能概述: 打印数据
** 参数说明：tableName：表名称, fileName:文件名,messageInOutFlag：message标记
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool SQLiteHelper::exportData(const QString& tableName, const QString& fileName, const QString& messageInOutFlag)
{
    QSqlDatabase database =  openConnection();
    QSqlQuery query(database);
    int msgcount;
    QString fileRealName;
    
    if (tableName.toLower() == "message")
    {
        QString tablesqlselect = QString(" select count(*)  from message where checkFlag = 1 and InputOutput = '%5'")
                                 .arg(messageInOutFlag);
        query.prepare(tablesqlselect);
        query.exec();
        query.next();
        
        if (query.value(0).toBool())
        {
            msgcount = query.value(0).toInt();
        }
        else
        {
            return false;
        }
    }
    
    QStringList fields;
    QStringList values;
    query.exec(QString("pragma table_info(%1)").arg(tableName));
    
    while (query.next())
    {
        fields << query.value(1).toString();
    }
    
    QString fieldNames = fields.join(",");
    
    if (tableName.toLower() == "message")
    {
        QString checkFlagName  = "checkFlag";
        QString inputOutputName  = "InputOutput";
        //QString temp = "I";
        QString sql = QString(" select %1 from %2 where %3 = 1 and %4 = '%5'")
                      .arg(fieldNames).arg(tableName)
                      .arg(checkFlagName).arg(inputOutputName).arg(messageInOutFlag);
        query.prepare(sql);
    }
    else  if (tableName.toLower() == "file")
    {
        QString name  = "Name";
        fileRealName = messageInOutFlag;
        QString sql = QString(" select %1 from %2 where %3 = '%4'")
                      .arg(fieldNames).arg(tableName)
                      .arg(name).arg(fileRealName);
        query.prepare(sql);
    }
    else
    {
        QString sql = QString(" select %1 from %2").arg(fieldNames).arg(tableName);
        query.prepare(sql);
    }
    
    query.exec();
    
    while (query.next())
    {
        for (int i = 0; i < fields.size(); i++)
        {
            values << query.value(i).toString();
        }
    }
    
    QFile file;
    
    if (fileName == NULL)
    {
        QDateTime now = QDateTime::currentDateTime();
        QString strNow = now.toString("yyyyMMddhhmmss");
        
        //file = QFile file(QString("%1%2_%3.xml").arg(PathResolve::resourcesPath()).arg(tableName).arg(strNow));
        if (tableName.toLower() == "message" || "file" == tableName.toLower())
            file.setFileName(QString("%1%2_%3.txt").arg(PathResolve::resourcesPath()).arg(tableName).arg(strNow));
        else
            file.setFileName(QString("%1%2_%3.xml").arg(PathResolve::resourcesPath()).arg(tableName).arg(strNow));
    }
    else
    {
        file.setFileName(fileName);
    }
    
    if (!file.open(QIODevice::WriteOnly))
        return false;
        
    if (tableName.toLower() == "message")
    {
        QTextStream out(&file);
        int rowNum = 0;
        int count = 1;
        
        for (int i = 0; i < values.size(); i++)
        {
            if (i % fields.size() == 0)
            {
                out << "/************/" << endl;
                
                if (count < 10)
                    out << "message_0" << count++ << endl;
                else
                    out << "message_" << count++ << endl;
                    
                out << "/************/" << endl;
            }
            
            if (fields.at(i % fields.size()) == "UUID" || fields.at(i % fields.size()) == "checkFlag" ||
                fields.at(i % fields.size()) == "showPix" || fields.at(i % fields.size()) == "Tx" ||
                fields.at(i % fields.size()) == "Rx")
                continue;
                
            out << fields.at(i % fields.size()) << ":" << values.at(i) << endl;
            
            if ((i + 1) % fields.size() == 0)
            {
                QString relationTable  = "MessageDetail";
                QStringList relationFields;
                QStringList relationValues;
                int indexColumn = 0;
                QString fKeyName  = "fkey";
                QString sql2 = QString(" select InputOutput,Content,CommunicationDateTime from %2 where %3 = '%4' ")
                               .arg(relationTable).arg(fKeyName).arg(values.at(rowNum * fields.size() + indexColumn));
                query.prepare(sql2);
                query.exec();
                int selectColumn = 3;
                
                while (query.next())
                {
                    for (int i = 0; i < selectColumn; i++)
                    {
                        relationValues << query.value(i).toString();
                    }
                }
                
                if (relationValues.size()  > 0)
                {
                    out << "/************/" << endl;
                    out << "messageDetail" << endl;
                    out << "/************/" << endl;
                    
                    for (int i = 0; i < relationValues.size(); i++)
                    {
                        if (relationValues.at(i) == "I")
                        {
                            out << "InPut:" << relationValues.at(i + 1) << endl;
                            out << "I_Datatime:" << relationValues.at(i + 2) << endl;
                            i = i + 2;
                        }
                        else if (relationValues.at(i) == "O")
                        {
                            out << "OutPut:" << relationValues.at(i + 1) << endl;
                            out << "O_Datatime:" << relationValues.at(i + 2) << endl;
                            i = i + 2;
                        }
                    }
                }
                
                out << endl;
                rowNum++;
            }
        }
    }
    else if (tableName.toLower() == "file")
    {
        for (int i = 0; i < values.size(); i++)
        {
            if (fields.at(i % fields.size()).toLower() == "content")
            {
                QTextStream out(&file);
                out << values.at(i);
                break;
            }
        }
    }
    else
    {
        QXmlStreamWriter xmlWriter(&file);
        xmlWriter.setAutoFormatting(true);
        xmlWriter.writeStartDocument();
        xmlWriter.writeStartElement(tableName + "s");
        int rowNum = 0;
        
        for (int i = 0; i < values.size(); i++)
        {
            if (i % fields.size() == 0)
            {
                xmlWriter.writeStartElement(tableName);
            }
            
            xmlWriter.writeTextElement(fields.at(i % fields.size()), values.at(i));
            
            if ((i + 1) % fields.size() == 0)
            {
                if (tableName.toLower() == "station" || tableName.toLower() == "individual")
                {
                    QString relationTable  = "frequency";
                    QStringList relationFields;
                    QStringList relationValues;
                    int indexColumn = 0;
                    QString fKeyName  = "fkey";
                    query.exec(QString("pragma table_info(%1)").arg(relationTable));
                    
                    while (query.next())
                    {
                        if ("ScanFlag" == query.value(1).toString())
                            continue;
                            
                        relationFields << query.value(1).toString();
                    }
                    
                    QString relationFieldNames = relationFields.join(",");
                    QString sql2 = QString(" select %1 from %2 where %3 = '%4' ")
                                   .arg(relationFieldNames).arg(relationTable)
                                   .arg(fKeyName).arg(values.at(rowNum * fields.size() + indexColumn));
                    query.prepare(sql2);
                    query.exec();
                    
                    while (query.next())
                    {
                        for (int i = 0; i < relationFields.size(); i++)
                        {
                            relationValues << query.value(i).toString();
                        }
                    }
                    
                    if (relationValues.size()  > 0)
                    {
                        xmlWriter.writeStartElement(relationTable + "s");
                        
                        for (int i = 0; i < relationValues.size(); i++)
                        {
                            if (i % relationFields.size() == 0)
                            {
                                xmlWriter.writeStartElement(relationTable);
                            }
                            
                            xmlWriter.writeTextElement(relationFields.at(i % relationFields.size()), relationValues.at(i));
                            
                            if ((i + 1) % relationFields.size() == 0)
                            {
                                xmlWriter.writeEndElement();
                            }
                        }
                        
                        xmlWriter.writeEndElement();
                    }
                }
                else if (tableName.toLower()  == "message")
                {
                    QString relationTable  = "MessageDetail";
                    QStringList relationFields;
                    QStringList relationValues;
                    int indexColumn = 0;
                    QString fKeyName  = "fkey";
                    query.exec(QString("pragma table_info(%1)").arg(relationTable));
                    
                    while (query.next())
                    {
                        relationFields << query.value(1).toString();
                    }
                    
                    QString relationFieldNames = relationFields.join(",");
                    QString sql2 = QString(" select %1 from %2 where %3 = '%4' ")
                                   .arg(relationFieldNames).arg(relationTable)
                                   .arg(fKeyName).arg(values.at(rowNum * fields.size() + indexColumn));
                    query.prepare(sql2);
                    query.exec();
                    
                    while (query.next())
                    {
                        for (int i = 0; i < relationFields.size(); i++)
                        {
                            relationValues << query.value(i).toString();
                        }
                    }
                    
                    if (relationValues.size()  > 0)
                    {
                        xmlWriter.writeStartElement(relationTable + "s");
                        
                        for (int i = 0; i < relationValues.size(); i++)
                        {
                            if (i % relationFields.size() == 0)
                            {
                                xmlWriter.writeStartElement(relationTable);
                            }
                            
                            xmlWriter.writeTextElement(relationFields.at(i % relationFields.size()), relationValues.at(i));
                            
                            if ((i + 1) % relationFields.size() == 0)
                            {
                                xmlWriter.writeEndElement();
                            }
                        }
                        
                        xmlWriter.writeEndElement();
                    }
                }
                
                xmlWriter.writeEndElement();
                rowNum++;
            }
        }
        
        xmlWriter.writeEndElement();
        xmlWriter.writeEndDocument();
    }
    
    file.close();
    return true;
}
/****************************************************************************
**
** 函数名称：SQLiteHelper::select
** 功能概述: 解析文件到数据库
** 参数说明：filePath：路径, model:数据库模型,fileName：文件名
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool SQLiteHelper::parseManagerFileToTable(const QString& filePath, QSqlTableModel* model, QString& fileName)
{
//  QString fileName = inputDialog.getTextContent();
    Database* database = new Database();
    database->openConnection();
    bool hasTransaction = database->transaction();
    QUuid idFile = QUuid::createUuid();
    QString strFileId = idFile.toString();
    QDateTime dateTime = QDateTime::currentDateTime();
    int y = dateTime.date().year();
    int m = dateTime.date().month();
    QString mStr = "0";
    
    if (m < 10)
        mStr += QString::number(m);
    else
        mStr = QString::number(m);
        
    int d = dateTime.date().day();
    QString dStr = "0";
    
    if (d < 10)
        dStr += QString::number(d);
    else
        dStr = QString::number(d);
        
    QString strTime = dateTime.time().toString();
    QString strDateTime = (QString::number(y) + "-" + mStr + "-" + dStr + "  " + strTime);
    QString sqlInsert =
        "insert into file(UUID, Name,Content,CreateDateTime,UpdateDateTime) values(:UUID,:Name,:Content,:CreateDateTime,:UpdateDateTime)";
    QVariantMap mapInsert;
    bool bInsertResult = false;
    mapInsert.insert(Constants::MANAGER_FILE_UUID, strFileId);
    mapInsert.insert(Constants::FILe_LIST_COL_NAME, fileName);
    QFile file;
    
    if (filePath == NULL)
    {
        return false;
    }
    else
    {
        file.setFileName(filePath);
    }
    
    if (!file.open(QIODevice::ReadOnly))
    {
        qErrnoWarning(filePath.toStdString().c_str());
        return false;
    }
    
    QTextStream in(&file);
    QString content;
    content = in.readAll();
    IntputCheck check;
    
    if (!check.checkStr(content))
        return false;
        
    mapInsert.insert(Constants::FILe_LIST_COL_CONTENT, content);
    mapInsert.insert(Constants::FILe_LIST__COL_CDATETIME, strDateTime);
    mapInsert.insert(Constants::FILe_LIST__COL_UDATETIME, strDateTime);
    bInsertResult = database->executeSql(sqlInsert, mapInsert);
    
    if (hasTransaction && bInsertResult)
    {
        database->commit();
    }
    else
    {
        database->rollback();
    }
    
    return true;
}
/****************************************************************************
**
** 函数名称：SQLiteHelper::select
** 功能概述: 解析XML文件到数据库
** 参数说明：model:数据库模型,reader：解析类
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool SQLiteHelper::parseNormalToTable(QSqlTableModel* model, QXmlStreamReader& reader)
{
    bool ret = true;
    Database* database = new Database();
    database->openConnection();
    QSqlQuery query = database->getQuery();
    bool hasTransaction = database->transaction();
    bool updateFlag = false;
    reader.readNext();
    reader.readNext();
    QString uuid;
    QString name;
    QString CallCode;
    QString CreateDateTime;
    QString UpdateDateTime;
    QString CallSign;
    QString Country;
    QString no;
    QString content;
    
    while (!reader.atEnd())
    {
        if (reader.isStartElement())
        {
            if (reader.name() == CONTACTS_STATION_UUID)
            {
                QString tablesqlselect;
                
                if (model->tableName().toLower() == "station")
                {
                    tablesqlselect.append("select count(*)  from station where UUID=") ;
                }
                else if (model->tableName().toLower() == "individual")
                {
                    tablesqlselect.append("select count(*)  from Individual where UUID=") ;
                }
                else if (model->tableName().toLower() == "phrasebook")
                {
                    tablesqlselect.append("select count(*)  from phrasebook where UUID=") ;
                }
                else if (model->tableName().toLower() == "macro")
                {
                    tablesqlselect.append("select count(*)  from macro where UUID=") ;
                }
                
                uuid.append(reader.readElementText());
                tablesqlselect.append("'") ;
                tablesqlselect.append(uuid) ;
                tablesqlselect.append("';  ") ;
                query.prepare(tablesqlselect);
                query.exec();
                query.next();
                
                if (query.value(0).toBool())
                {
                    updateFlag = true;
                }
                else
                {
                    updateFlag = false;
                }
                
                //uuid +=reader.readElementText();
                reader.readNext();
            }
            else if (reader.name() == CONTACTS_STATION_NAME)
            {
                name += reader.readElementText();
                reader.readNext();
            }
            else if (reader.name() == CONTACTS_STATION_CALLCODE)
            {
                CallCode += reader.readElementText();
                reader.readNext();
            }
            else if (reader.name() == CONTACTS_STATION_CREATEDATETIME)
            {
                if (!updateFlag)
                    CreateDateTime += reader.readElementText();
                else
                    reader.readNext();
                    
                reader.readNext();
            }
            else if (reader.name() == CONTACTS_STATION_UPDATEDATETIME)
            {
                if (!updateFlag)
                    UpdateDateTime += reader.readElementText();
                else
                {
                    QDateTime dateTime = QDateTime::currentDateTime();
                    int y = dateTime.date().year();
                    int m = dateTime.date().month();
                    QString mStr = "0";
                    
                    if (m < 10)
                        mStr += QString::number(m);
                    else
                        mStr = QString::number(m);
                        
                    int d = dateTime.date().day();
                    QString dStr = "0";
                    
                    if (d < 10)
                        dStr += QString::number(d);
                    else
                        dStr = QString::number(d);
                        
                    QString strTime = dateTime.time().toString();
                    QString sTime = (QString::number(y) + "-" + mStr + "-" + dStr + "  " + strTime);
                    UpdateDateTime += sTime;
                    reader.readNext();
                }
            }
            else if (reader.name() == CONTACTS_STATION_CALLSIGN)
            {
                CallSign += reader.readElementText();
                reader.readNext();
            }
            else if (reader.name() == CONTACTS_STATION_COUNTRY)
            {
                Country += reader.readElementText();
                reader.readNext();
            }
            else if (reader.name() == CONTACTS_STATION_FREQUENCYS)
            {
                ret = parseFkeyTable(reader, uuid, database);
                
                if (!ret)
                {
                    database->rollback();
                    return false;
                }
            }
            else if (reader.name() == MANAGER_PHRASEBOOK_CONTENT)
            {
                content += reader.readElementText();
                reader.readNext();
            }
            else if (reader.name() == MANAGER_PHRASEBOOK_NO)
            {
                no += reader.readElementText();
                reader.readNext();
            }
            
            reader.readNext();
        }
        else if (reader.isEndElement() && reader.name() == model->tableName().toLower())
        {
            if (updateFlag)
            {
                QVariantMap updateMap;
                QString sql = "update ";
                
                if (model->tableName().toLower() == "station")
                {
                    updateMap.insert(CONTACTS_STATION_UUID, uuid);
                    updateMap.insert(CONTACTS_STATION_NAME, name);
                    updateMap.insert(CONTACTS_STATION_CALLCODE, CallCode);
                    updateMap.insert(CONTACTS_STATION_UPDATEDATETIME, UpdateDateTime);
                    updateMap.insert(CONTACTS_STATION_CALLSIGN, CallSign);
                    updateMap.insert(CONTACTS_STATION_COUNTRY, Country);
                    sql += " station set Name=:Name, CallCode=:CallCode, UpdateDateTime=:UpdateDateTime, CallSign=:CallSign, Country=:Country where UUID=:UUID";
                }
                else if (model->tableName().toLower() == "individual")
                {
                    updateMap.insert(CONTACTS_STATION_UUID, uuid);
                    updateMap.insert(CONTACTS_STATION_NAME, name);
                    updateMap.insert(CONTACTS_STATION_CALLCODE, CallCode);
                    updateMap.insert(CONTACTS_STATION_UPDATEDATETIME, UpdateDateTime);
                    sql += " individual set Name=:Name, CallCode=:CallCode, UpdateDateTime=:UpdateDateTime where UUID=:UUID";
                }
                else if (model->tableName().toLower() == "phrasebook")
                {
                    updateMap.insert(CONTACTS_STATION_UUID, uuid);
                    updateMap.insert(MANAGER_PHRASEBOOK_CONTENT, content);
                    updateMap.insert(MANAGER_PHRASEBOOK_NO, no);
                    updateMap.insert(CONTACTS_STATION_UPDATEDATETIME, UpdateDateTime);
                    sql += " phrasebook set Content=:Content, no=:no, UpdateDateTime=:UpdateDateTime where UUID=:UUID";
                }
                else if (model->tableName().toLower() == "macro")
                {
                    updateMap.insert(MANAGER_MACRO_UUID, uuid);
                    updateMap.insert(MANAGER_MACRO_NAME, name);
                    updateMap.insert(MANAGER_MACRO_NO, no);
                    updateMap.insert(MANAGER_MACRO_UPDATEDATETIME, UpdateDateTime);
                    sql += " macro set Name=:Name, No=:No, UpdateDateTime=:UpdateDateTime where UUID=:UUID";
                }
                
                ret = database->executeSql(sql, updateMap);
            }
            else
            {
                QVariantMap insertMap;
                QString sql = "insert into ";
                
                if (model->tableName().toLower() == "station")
                {
                    insertMap.insert(CONTACTS_STATION_UUID, uuid);
                    insertMap.insert(CONTACTS_STATION_NAME, name);
                    insertMap.insert(CONTACTS_STATION_CALLCODE, CallCode);
                    insertMap.insert(CONTACTS_STATION_CREATEDATETIME, CreateDateTime);
                    insertMap.insert(CONTACTS_STATION_CALLSIGN, CallSign);
                    insertMap.insert(CONTACTS_STATION_COUNTRY, Country);
                    sql += " station(uuid, name,CallSign,Country,CallCode,CreateDateTime) values(:UUID,:Name,:CallSign,:Country,:CallCode,:CreateDateTime)";
                }
                else if (model->tableName().toLower() == "individual")
                {
                    insertMap.insert(CONTACTS_STATION_UUID, uuid);
                    insertMap.insert(CONTACTS_STATION_NAME, name);
                    insertMap.insert(CONTACTS_STATION_CALLCODE, CallCode);
                    insertMap.insert(CONTACTS_STATION_CREATEDATETIME, CreateDateTime);
                    sql +=  " individual(uuid,name,callcode,CreateDateTime) values(:UUID,:Name,:CallCode,:CreateDateTime)";
                }
                else if (model->tableName().toLower() == "phrasebook")
                {
                    insertMap.insert(MANAGER_PHRASEBOOK_UUID, uuid);
                    insertMap.insert(MANAGER_PHRASEBOOK_CONTENT, content);
                    insertMap.insert(MANAGER_PHRASEBOOK_NO, no);
                    insertMap.insert(MANAGER_PHRASEBOOK_CREATEDATETIME, CreateDateTime);
                    insertMap.insert(MANAGER_PHRASEBOOK_UPDATEDATETIME, CreateDateTime);
                    sql +=  " phrasebook(UUID,Content,No,CreateDateTime,UpdateDateTime) values(:UUID,:Content,:No,:CreateDateTime,:UpdateDateTime)";
                }
                else if (model->tableName().toLower() == "macro")
                {
                    insertMap.insert(MANAGER_MACRO_UUID, uuid);
                    insertMap.insert(MANAGER_MACRO_NAME, name);
                    insertMap.insert(MANAGER_MACRO_NO, no);
                    insertMap.insert(MANAGER_MACRO_CREATEDATETIME, CreateDateTime);
                    insertMap.insert(MANAGER_MACRO_UPDATEDATETIME, CreateDateTime);
                    sql +=  " macro(UUID,Name,No,CreateDateTime,UpdateDateTime) values(:UUID,:Name,:No,:CreateDateTime,:UpdateDateTime)";
                }
                
                ret = database->executeSql(sql, insertMap);
            }
            
            uuid.clear();
            name.clear();
            CallCode.clear();
            CreateDateTime.clear();
            CallSign.clear();
            Country.clear();
            UpdateDateTime.clear();
            no.clear();
            content.clear();
            
            if (!ret)
            {
                database->rollback();
                return false;
            }
            
            reader.readNext();
        }
        else
        {
            reader.readNext();
        }
    }
    
    if (hasTransaction)
    {
        bool ret = database->commit();
        return true;
    }
    else
    {
        database->rollback();
        return false;
    }
}
/****************************************************************************
**
** 函数名称：SQLiteHelper::select
** 功能概述: 解析频率XML文件到数据库
** 参数说明：reader：解析类，fkey：复键，database：数据库句柄
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool SQLiteHelper::parseFkeyTable(QXmlStreamReader& reader, QString& fkey, Database* database)
{
    QVariantMap map;
    QSqlQuery query = database->getQuery();
    bool bResultExe = true;
    bool updateFlag;
    reader.readNext();
    reader.readNext();
    
    if (reader.isStartElement() && reader.name() == "frequency")
    {
        reader.readNext();
        reader.readNext();
    }
    else
        return false;
        
    while (!reader.atEnd() && !(reader.isEndElement() && reader.name() == "frequencys"))
    {
        if (reader.isStartElement() && reader.name() == "frequency")
        {
            reader.readNext();
            reader.readNext();
            continue;
        }
        
        if (reader.isStartElement())
        {
            if (reader.name() == "UUID")
            {
                QString sqlFrequencyselect = "select count(*)  from Frequency  where FKey = ";
                sqlFrequencyselect.append("'");
                sqlFrequencyselect.append(fkey);
                sqlFrequencyselect.append("'");
                sqlFrequencyselect.append(" and UUID =");
                QString uuid = reader.readElementText();
                sqlFrequencyselect.append("'") ;
                sqlFrequencyselect.append(uuid) ;
                sqlFrequencyselect.append("';  ") ;
                query.prepare(sqlFrequencyselect);
                //sqlFrequency.clear();
                query.exec();
                query.next();
                
                if (query.value(0).toBool())
                {
                    updateFlag = true;
                }
                else
                {
                    updateFlag = false;
                }
                
                map.insert("UUID", uuid);
                reader.readNext();
            }
            else if (reader.name() == "FKey")
            {
                if (!updateFlag)
                    map.insert("FKey", reader.readElementText());
                else
                    reader.readNext();
                    
                reader.readNext();
            }
            else if (reader.name() == "Ower")
            {
                map.insert("Ower", reader.readElementText());
                reader.readNext();
            }
            else if (reader.name() == "No")
            {
                map.insert("No", reader.readElementText());
                reader.readNext();
            }
            else if (reader.name() == "Channel")
            {
                map.insert("Channel", reader.readElementText());
                reader.readNext();
            }
            else if (reader.name() == "Tx")
            {
                map.insert("Tx", reader.readElementText());
                reader.readNext();
            }
            else if (reader.name() == "Rx")
            {
                map.insert("Rx", reader.readElementText());
                reader.readNext();
            }
            else
                reader.readNext();
                
            reader.readNext();
        }
        else if (reader.isEndElement() && reader.name() == "frequency")
        {
            QString sqlFrequency;
            
            if (updateFlag)
            {
                sqlFrequency += "update frequency set Ower=:Ower,No=:No,Channel=:Channel,Tx=:Tx, Rx=:Rx where UUID=:UUID";
            }
            else
            {
                sqlFrequency += "insert into frequency (UUID,FKey,Ower,No,Channel,Tx,Rx)values(:UUID,:FKey,:Ower,:No,:Channel,:Tx,:Rx)";
            }
            
            bResultExe = database->executeSql(sqlFrequency, map);
            map.clear();
            reader.readNext();
            
            if (!bResultExe)
                return false;
        }
        else
            reader.readNext();
    }
    
    return bResultExe;
}
/****************************************************************************
**
** 函数名称：SQLiteHelper::parseXmlToTable
** 功能概述: 解析XML文件到数据库
** 参数说明：reader：解析类，model：数据库模型
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool SQLiteHelper::parseXmlToTable(QSqlTableModel* model, QXmlStreamReader& reader)
{
    reader.readNext();
    
    if (reader.isStartDocument())
        reader.readNext();
    else
        return false;
        
    if (reader.isStartElement())
    {
        if (reader.name() != "stations" && reader.name() != "individuals" && reader.name() != "phrasebooks"
            && reader.name() != "macros")
        {
            return false;
        }
        else
        {
            reader.readNext();
            reader.readNext();
            
            if (reader.isStartElement())
            {
                if (model->tableName().toLower() != reader.name().toString())
                    return false;
            }
            else
                return false;
        }
    }
    else
        return false;
        
    bool ret = false;
    
    if (reader.name().toString() == "station" || reader.name().toString() == "individual"
        || reader.name().toString() == "phrasebook" || reader.name().toString() == "macro")
    {
        ret = parseNormalToTable(model, reader);
    }
    
    return ret;
}
/****************************************************************************
**
** 函数名称：SQLiteHelper::parseXmlToTable
** 功能概述: 导入文件到数据库
** 参数说明：filePath：文件路径，model：数据库模型
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool SQLiteHelper::importData(const QString& filePath, QSqlTableModel* model)
{
    QFile file(filePath);
    
    if (!file.open((QFile::ReadOnly | QFile::Text)))
    {
        qDebug() << "importData::Error open " << filePath;
        return false;
    }
    
    if (model->tableName().toLower() == Constants::FILe_LIST_TABLE_NAME)
    {
        QString name = filePath.section('/', -1);
        name = name.left(name.length() - 4);
        return parseManagerFileToTable(filePath, model, name);
    }
    
    QXmlStreamReader reader;
    reader.setDevice(&file);
    return parseXmlToTable(model, reader);
}


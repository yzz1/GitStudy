#include "configreader.h"

#include <QFile>
#include <QDebug>
/****************************************************************************
**
** 函数名称：ConfigReader::ConfigReader
** 功能概述: 初始化
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ConfigReader::ConfigReader()
{
}
/****************************************************************************
**
** 函数名称：ConfigReader::readConfig
** 功能概述: 读取配置
** 参数说明  fileName：配置名
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QList<QString> ConfigReader::readConfig(const QString& fileName)
{
    QFile file(fileName);
    
    file.open(QFile::ReadOnly);
    setDevice(&file);
    
    if (readNextStartElement())
    {
        if (name() == QLatin1String("pages"))
        {
            qDebug() << "  Processing property";
        }
    }
    
    QList<QString> a;
    return a;
}

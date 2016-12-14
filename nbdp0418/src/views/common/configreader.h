/****************************************************************************
**
** 文件名称： configreader.h
** 功能概述:  读取配置类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef CONFIGREADER_H
#define CONFIGREADER_H

#include <QXmlStreamReader>
#include <QList>

class ConfigReader : public QXmlStreamReader
{
    public:
        ConfigReader();
        QList<QString> readConfig(const QString& fileName);
};

#endif // CONFIGREADER_H

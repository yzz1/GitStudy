#include "pathresolve.h"

#include <QtGlobal>
#include <QApplication>
#include <QDir>
#include <QDebug>
/****************************************************************************
**
** 函数名称：PathResolve::appPath
** 功能概述: app路径
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QString PathResolve::appPath()
{
    QString strPath = QApplication::applicationDirPath();
    addBackslash(strPath);
    return strPath;
}
/****************************************************************************
**
** 函数名称：PathResolve::resourcesPath
** 功能概述: 资源路径
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QString PathResolve::resourcesPath()
{
    QDir dir(appPath());
    QString strPath = dir.path();
    addBackslash(strPath);
    return strPath;
}
/****************************************************************************
**
** 函数名称：PathResolve::dataStorePath
** 功能概述: 数据库路径
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QString PathResolve::databaseFile()
{
    return resourcesPath() + "db/nbdp.db";
}

/****************************************************************************
**
** 函数名称：PathResolve::tempPath
** 功能概述: 临时文件路径
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QString PathResolve::tempPath()
{
    QString path = QDir::tempPath() + "/nbdp/";
    ensurePathExists(path);
    return path;
}
/****************************************************************************
**
** 函数名称：PathResolve::qtTranslationFileName
** 功能概述: 读取语言配置路径
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QString PathResolve::qtTranslationFileName(const QString& lang)
{
    return resourcesPath() + "translations/nbdp_" + lang + ".qm";
}
/****************************************************************************
**
** 函数名称：PathResolve::addBackslash
** 功能概述: 添加反斜杠
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void PathResolve::addBackslash(QString& strPath)
{
    strPath.replace('\\', '/');
    
    if (strPath.endsWith('/'))
        return;
        
    strPath += '/';
}
/****************************************************************************
**
** 函数名称：PathResolve::ensurePathExists
** 功能概述: 添加目录
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void PathResolve::ensurePathExists(const QString& path)
{
    QDir dir;
    dir.mkpath(path);
}

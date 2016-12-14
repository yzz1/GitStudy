/****************************************************************************
**
** 文件名称： pathresolve.h
** 功能概述:  路径管理类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef UTILS_PATHRESOLVE_H
#define UTILS_PATHRESOLVE_H

class QString;

class PathResolve
{
    public:
        static QString appPath();
        static QString resourcesPath();
        static QString pluginsPath();
        static QString dataStorePath();
        static QString databaseFile();
        static QString cachePath();
        static QString tempPath();
        static QString logFile();
        static QString globalSettingsFile();
        static QString userSettingsFile(const QString strUserId);
        static QString qtTranslationFileName(const QString& strLocale);
        static QString localeFileName(const QString& strLocale);
        
        // helpers
        static void addBackslash(QString& strPath);
        static void ensurePathExists(const QString& path);
        
    private:
        static QString logFilePath();
};

#endif // UTILS_PATHRESOLVE_H

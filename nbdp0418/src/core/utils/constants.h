/****************************************************************************
**
** 文件名称： constants.h
** 功能概述:  数据库名称信息等
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef UTILS_CONSTANTS_H
#define UTILS_CONSTANTS_H

namespace Core
{
    namespace Constants
    {
    
        const char* APP_NAME = "nbdp";
        
        const char* DB_TYPE_SQLITE = "QSQLITE";
        
        const int SQLITE_PORT = 3306;
        
        const char* CONNECTION_NAME = "nbdp";
    }
}

#endif // UTILS_CONSTANTS_H

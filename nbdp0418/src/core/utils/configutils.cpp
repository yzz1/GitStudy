#include "configutils.h"
#include "singleton.h"

#include <QString>
#include <QStringList>
#include "core/utils/pathresolve.h"

static const char* const SETTINGS_FILE_NAME    = "config.ini";
static const char* const DATABASE_GROUP        = "Database";
static const char* const DATABASE_TYPE         = "type";
static const char* const DataBASE_PORT         = "port";
static const char* const DATABASE_NAME         = "databaseName";
static const char* const DATABASE_HOST         = "host";
static const char* const DATABASE_USERNAME     = "username";
static const char* const DATABASE_PASSWORD     = "password";
bool ConfigUtils::m_connectStateFlag = true;
/****************************************************************************
**
** 函数名称：ConfigUtils::getScreenHeight
** 功能概述: 获取屏幕高度
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
int ConfigUtils::getScreenHeight()
{
    QSettings* settings = new QSettings(PathResolve::resourcesPath() + "config/application.properties",
                                        QSettings::IniFormat);
    return settings->value(QLatin1String("ScreenHeight")).toInt();
}
/****************************************************************************
**
** 函数名称：ConfigUtils::getScreenWidth
** 功能概述: 获取屏幕宽度
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
int ConfigUtils::getScreenWidth()
{
    QSettings* settings = new QSettings(PathResolve::resourcesPath() + "config/application.properties",
                                        QSettings::IniFormat);
    return settings->value(QLatin1String("ScreenWidth")).toInt();
}
/****************************************************************************
**
** 函数名称：ConfigUtils::getLanguage
** 功能概述: 获取语言配置
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QString ConfigUtils::getLanguage()
{
    QSettings* settings = new QSettings(PathResolve::resourcesPath() + "config/application.properties",
                                        QSettings::IniFormat);
    return settings->value(QLatin1String("Lang")).toString();
}
/****************************************************************************
**
** 函数名称：ConfigUtils::getSerialPort
** 功能概述: 获取打印机串口号
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QString ConfigUtils::getSerialPort()
{
    QSettings* settings = new QSettings(PathResolve::resourcesPath() + "config/application.properties",
                                        QSettings::IniFormat);
    return settings->value(QLatin1String("SerialPort")).toString();
}
/****************************************************************************
**
** 函数名称：ConfigUtils::getBaudRate
** 功能概述: 获取波特率
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QString ConfigUtils::getBaudRate()
{
    QSettings* settings = new QSettings(PathResolve::resourcesPath() + "config/application.properties",
                                        QSettings::IniFormat);
    return settings->value(QLatin1String("BaudRate")).toString();
}
/****************************************************************************
**
** 函数名称：ConfigUtils::getCursorVisible
** 功能概述: 获取鼠标隐藏配置
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool ConfigUtils::getCursorVisible()
{
    QSettings* settings = new QSettings(PathResolve::resourcesPath() + "config/application.properties",
                                        QSettings::IniFormat);
    QString showCursorStr = settings->value(QLatin1String("CursorVisible")).toString();
    return showCursorStr.toLower() == "true";
}
/****************************************************************************
**
** 函数名称：ConfigUtils::getCallInterval
** 功能概述: 获取CALL弹窗自动关闭时间
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
int ConfigUtils::getCallInterval()
{
    QSettings* settings = new QSettings(PathResolve::resourcesPath() + "config/application.properties",
                                        QSettings::IniFormat);
    return settings->value(QLatin1String("CallInterval")).toInt();
}
/****************************************************************************
**
** 函数名称：ConfigUtils::getConnectStateResultWaitTime
** 功能概述: 获取连接超时时间设置
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
int ConfigUtils::getConnectStateResultWaitTime()
{
    QSettings* settings = new QSettings(PathResolve::resourcesPath() + "config/application.properties",
                                        QSettings::IniFormat);
    return settings->value(QLatin1String("ConnectStateResultWaitTime")).toInt();
}
/****************************************************************************
**
** 函数名称：ConfigUtils::getTuneResultWaitTime
** 功能概述: 获取通话超时时间设置
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
int ConfigUtils::getTuneResultWaitTime()
{
    QSettings* settings = new QSettings(PathResolve::resourcesPath() + "config/application.properties",
                                        QSettings::IniFormat);
    return settings->value(QLatin1String("TuneResultWaitTime")).toInt();
}
/****************************************************************************
**
** 函数名称：ConfigUtils::getConnectingWaitTime
** 功能概述: 获取连接等待时间设置
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
int ConfigUtils::getConnectingWaitTime()
{
    QSettings* settings = new QSettings(PathResolve::resourcesPath() + "config/application.properties",
                                        QSettings::IniFormat);
    return settings->value(QLatin1String("ConnectingWaitTime")).toInt();
}
/****************************************************************************
**
** 函数名称：ConfigUtils::getConnectResultWaitTime
** 功能概述: 获取连接等待回折时间设置
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
int ConfigUtils::getConnectResultWaitTime()
{
    QSettings* settings = new QSettings(PathResolve::resourcesPath() + "config/application.properties",
                                        QSettings::IniFormat);
    return settings->value(QLatin1String("ConnectResultWaitTime")).toInt();
}
/****************************************************************************
**
** 函数名称：ConfigUtils::getDialogCloseWaitTime
** 功能概述: 获取连接状态对话框自动关闭时间设置
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
int ConfigUtils::getDialogCloseWaitTime()
{
    QSettings* settings = new QSettings(PathResolve::resourcesPath() + "config/application.properties",
                                        QSettings::IniFormat);
    return settings->value(QLatin1String("DialogCloseWaitTime")).toInt();
}
/****************************************************************************
**
** 函数名称：ConfigUtils::setConnectStateFlag
** 功能概述: 设置连接状态标识
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ConfigUtils::setConnectStateFlag(bool connectStateFlag)
{
    m_connectStateFlag = connectStateFlag;
}
/****************************************************************************
**
** 函数名称：ConfigUtils::isConnected
** 功能概述: 返回是否连接成功
** 参数说明： 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool ConfigUtils::isConnected()
{
    return m_connectStateFlag;
}

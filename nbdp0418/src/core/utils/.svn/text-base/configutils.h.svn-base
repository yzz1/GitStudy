/****************************************************************************
**
** 文件名称： configutils.h
** 功能概述:  配置读取
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef CONFIGUTILs_H
#define CONFIGUTILs_H

#include <QSettings>

class ConfigUtils
{

    public:
        static int getScreenWidth();
        
        static int getScreenHeight();
        
        static QString getLanguage();
        
        static QString getSerialPort();
        
        static QString getBaudRate();
        
        static bool getCursorVisible();
        
        static int getCallInterval();
        
        static int getConnectStateResultWaitTime();
        
        static int getTuneResultWaitTime();
        
        static int getConnectingWaitTime();
        
        static int getConnectResultWaitTime();
        
        static int getDialogCloseWaitTime();
        
        static void setConnectStateFlag(bool connectStateFlag);
        
        static bool isConnected();
        
    private:
        static QSettings* m_settings;
        static bool m_connectStateFlag;
};

#endif // CONFIGUTILs_H

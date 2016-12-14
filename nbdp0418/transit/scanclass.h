/****************************************************************************
**
** 文件名称： scanclass.h
** 功能概述: 扫描信息类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef SCANCLASS_H
#define SCANCLASS_H

#include <QList>
#include "channelinfoclass.h"

class ScanClass
{
    public:
        static ScanClass*  get();
        ~ScanClass();
        void setIsScan(bool b);
        bool getIsScan();
        void setScanGroup(int i);
        int getScanGroup();
        void setDwellTime(QString str);
        QString getDwellTime();
        void setScanMode(QString str);
        QString getScanMode();
        void addChannelInfoClass(ChannelInfoClass cnlic);
        QList<ChannelInfoClass>* getChannelInfoList();
    private:
        ScanClass();
        static ScanClass* m_pInstance;
        QString dwellTime;          // DwellTime
        QString scanMode;           // 扫描模式
        bool IsScan;                // 是否开始
        int iScanGroup;             // 是否扫描频组
        QList<ChannelInfoClass> cnlicl;
};

#endif // SCANCLASS_H

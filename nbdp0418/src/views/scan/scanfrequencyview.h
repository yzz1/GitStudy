/****************************************************************************
**
** 文件名称： scanfrequencyview.h
** 功能概述:  频率扫描类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef SCANFREQUENCYVIEW_H
#define SCANFREQUENCYVIEW_H

#include <QWidget>
#include <QMap>
#include "../transit/transit.h"
#include "callinfoclass.h"

namespace Ui
{
    class ScanFrequencyView;
}

class ScanFrequencyView : public QWidget
{
        Q_OBJECT
        
    public:
        explicit ScanFrequencyView(QWidget* parent = 0);
        ~ScanFrequencyView();
        
        
    signals:
        void afterPageSignal(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        
    public  slots:
        void frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        void  stopClickedSolt();
        void SlotScanData(CallInfoClass* cic);
        
    private:
        Ui::ScanFrequencyView* ui;
        bool eventFilter(QObject* watched, QEvent* event);
        int m_nTimerId;			//定时器ID
        int m_TimeCount;			//定时器保存的循环数
        int m_recordCount;			//频率数
        
    protected:
        void timerEvent(QTimerEvent* event);
        
};

#endif // SCANFREQUENCYVIEW_H

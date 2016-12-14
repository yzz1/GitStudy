/****************************************************************************
**
** 文件名称： stationeditview.h
** 功能概述:  站台联系表编辑界面类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef STATIONEDITVIEW_H
#define STATIONEDITVIEW_H

#include <QWidget>
#include <QMap>
#include <QList>
#include <widgets/titlewidget.h>

namespace Ui
{
    class StationEditView;
}

class FrequencyStationData
{

    public :
//   FrequencyData();
        QString strNO;
        QString strChannel;
        QString strTx;
        QString strRx;
        bool display;
        void clear();
};

class StationEditView : public QWidget
{
        Q_OBJECT
        
    public:
        explicit StationEditView(QWidget* parent = 0);
        ~StationEditView();
        
    private:
        Ui::StationEditView* ui;
        QString m_strModle;		//打开模式  编辑or新建
        QMap <QString, QString> m_stationMap;	//站台联系人数据
        QList<FrequencyStationData> m_list;		//频率表缓存
        bool eventFilter(QObject* watched, QEvent* event);
        bool m_editmode;				//编辑频率标记
    signals:
    
        void afterPageSignal(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        
    public  slots:
        bool saveData();
        void frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        void cancelButtonClicked();
        void arrowUpButtonClicked();
        void arrowDownButtonClicked();
        void homeClickedSlot();
        void individualClickedSlot();
        void stationClickedSlot();
        
        
};

#endif // STATIONEDITVIEW_H

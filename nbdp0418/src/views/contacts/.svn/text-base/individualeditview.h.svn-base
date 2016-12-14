/****************************************************************************
**
** 文件名称： individualeditview.h
** 功能概述:  个人联系表编辑界面类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef INDIVIDUALEDITVIEW_H
#define INDIVIDUALEDITVIEW_H

#include <QWidget>
#include <QMap>
#include <widgets/titlewidget.h>

namespace Ui
{
    class IndividualEditView;
}

class FrequencyIndividualData
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

class IndividualEditView : public QWidget
{
        Q_OBJECT
        
    public:
        explicit IndividualEditView(QWidget* parent = 0);
        ~IndividualEditView();
        
    private:
        Ui::IndividualEditView* ui;
        QString m_strModle;			//打开模式 编辑or新建
        QList<FrequencyIndividualData> m_list; //频率数据缓存
        QMap <QString, QString> m_stationMap;  //联系人数据
        bool eventFilter(QObject* watched, QEvent* event);
        bool  m_editmode;				//编辑频率标记
    signals:
    
        void afterPageSignal(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        
    public  slots:
        bool saveData();
        void frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        void cancelButtonClicked();
        void homeClickedSlot();
        void individualClickedSlot();
        void stationClickedSlot();
        void arrowUpButtonClicked();
        void arrowDownButtonClicked();
        
        
};

#endif // INDIVIDUALEDITVIEW_H

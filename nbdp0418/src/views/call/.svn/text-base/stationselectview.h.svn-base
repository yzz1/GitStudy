/****************************************************************************
**
** 文件名称： stationselectview.h
** 功能概述:  call选择站台界面类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef STATIONSELECTVIEW_H
#define STATIONSELECTVIEW_H

#include <QWidget>
#include <QMap>
#include "models/contactsmodel.h"

namespace Ui
{
    class StationSelectView;
}

class StationSelectView : public QWidget
{
        Q_OBJECT
        
    public:
        explicit StationSelectView(QWidget* parent = 0);
        ~StationSelectView();
        
    private:
        Ui::StationSelectView* ui;
        ContactsModel* m_model;   //联系站台的数据模型
        bool eventFilter(QObject* watched, QEvent* event);
        bool m_callOrReceive;	//主叫被叫模式
        
    signals :
        void afterPageSignal(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        
    public slots:
        void  homeClickedSlot();
        void okButtonClickedSlot();
        void cancelButtonClickedSlot();
        void receiveButtonClickedSlot();
        void callButtonClickedSlot();
        
        void activatedSlot(QModelIndex index);
        void  frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        
};

#endif // STATIONSELECTVIEW_H

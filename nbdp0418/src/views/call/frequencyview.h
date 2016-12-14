/****************************************************************************
**
** 文件名称： frequencyview.h
** 功能概述:  Frequency数据库中选择频率
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef FREQUENCYVIEW_H
#define FREQUENCYVIEW_H

#include <QWidget>
#include <QMap>
#include "models/contactsmodel.h"

namespace Ui
{
    class FrequencyView;
}

class FrequencyView : public QWidget
{
        Q_OBJECT
        
    public:
        explicit FrequencyView(QWidget* parent = 0);
        ~FrequencyView();
        void initTableView();
        
    private:
        Ui::FrequencyView* ui;
        ContactsModel* m_model;
        QString m_name;
        QString m_owner;
        QString m_fkey;
        QString m_callCode;
        bool m_callOrReceive;	//主叫被叫模式
        bool eventFilter(QObject* watched, QEvent* event);
    signals :
        void afterPageSignal(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        
    public slots:
        void frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        void  homeClickedSlot();
        void  okButtonClickedSlot();
        void  cancelButtonClickedSlot();
        void receiveButtonClickedSlot();
        void callButtonClickedSlot();
        void activatedSlot(QModelIndex index);
};

#endif // FREQUENCYVIEW_H

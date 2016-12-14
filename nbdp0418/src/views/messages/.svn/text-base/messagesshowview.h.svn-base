/****************************************************************************
**
** 文件名称： messagesshowview.h
** 功能概述:  message明细界面类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef MESSAGESSHOWVIEW_H
#define MESSAGESSHOWVIEW_H

#include <QWidget>
#include "models/messagesmodel.h"
#include "views/common/constants.h"

namespace Ui
{
    class MessagesShowView;
}

class MessagesShowView : public QWidget
{
        Q_OBJECT
        
    public:
        explicit MessagesShowView(QWidget* parent = 0);
        ~MessagesShowView();
        void setTableViewRowHeight();
        
    signals:
        void afterPageSignal(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        
    public  slots:
        void frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        void homeClickedSlot();
        void inBoxClickedSlot();
        void OutBoxClickedSlot();
        void CloseClickedSlot();
        void setClipboardContent();
        void printClickedSlot();
        
    private:
        Ui::MessagesShowView* ui;
        bool m_optionMenuStatus;  //option 菜单的开关
        MessagesModel* m_model;   //数据模型
        QString m_strModle;		//保存message in or out标记
        QString m_uuid;		//保存message的uuid
        QMap <QString, QString> m_messageMap;
        bool eventFilter(QObject* watched, QEvent* event);
        QStringList nameList;	//保存光标循环列表
};

#endif // MESSAGESSHOWVIEW_H

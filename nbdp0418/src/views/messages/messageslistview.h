/****************************************************************************
**
** 文件名称： messageslistview.h
** 功能概述:  Phrasebook界面类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef MessagesListView_H
#define MessagesListView_H
#include "models/contactsmodel.h"
#include <QWidget>

namespace Ui
{
    class MessagesListView;
}

class MessagesListView : public QWidget
{
        Q_OBJECT
        
    public:
        explicit MessagesListView(QWidget* parent = 0);
        ~MessagesListView();
    signals :
        void afterPageSignal(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        void hasUnreadMessage(bool hasUnread);
    private:
        Ui::MessagesListView* ui;
        QSqlTableModel* m_model;   //数据模型
        bool  m_selectAllFlag;	//全部选中标记
        bool  m_bOutBoxFlag;		//in or out界面标记
        QString m_strInboxFiter;	//保存SQL语句
        QString m_strOutboxFiter;	//保存SQL语句
        int  m_currow;		//保存当前行
        QStringList nameList;	//保存界面光标循环列表
        
        bool eventFilter(QObject* watched, QEvent* event);
        
    public slots:
        void frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        void  homeClickedSlot();
        void  selectClickedSlot();
        void selectAllClickedSlot();
        void deleteSelectedRow();
        void inBoxClickedSlot();
        void outBoxClickedSlot();
        void openClickedSlot();
        void exportClickedSlot();
        
};

#endif // MessagesListView_H

/****************************************************************************
**
** 文件名称： messagedetaildelegate.h
** 功能概述: 消息详细内容Delegate类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef MESSAGEDETAILDELEGATE_H
#define MESSAGEDETAILDELEGATE_H

#include <QItemDelegate>
#include <QPixmap>
#include "views/messages/messagesstyle.h"

class MessageDetailDelegate: public QItemDelegate
{
    public:
        MessageDetailDelegate(QObject* parent = 0, MessagesStyle* contactsStyle = 0);
        void paint(QPainter* painter,
                   const QStyleOptionViewItem& option,
                   const QModelIndex& index) const;
        void setCommuMessageFlag(bool commuMessageFlag) {m_commuMessageFlag = commuMessageFlag; }
        bool getCommuMessageFlag() {return m_commuMessageFlag ; }
        void setTableWidget(QWidget* tableWidget){m_tableWidget = tableWidget;}
        
    private:
        MessagesStyle* m_style;//一览画面属性
        bool m_commuMessageFlag;//通信画面标识
        QWidget* m_tableWidget;//table Widget
};

#endif // MESSAGEDETAILDELEGATE_H

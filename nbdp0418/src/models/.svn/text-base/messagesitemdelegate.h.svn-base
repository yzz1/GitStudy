/****************************************************************************
**
** 文件名称： messagesitemdelegate.h
** 功能概述: 消息列表Delegate类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef MESSAGESITEMDELEGATE_H
#define MESSAGESITEMDELEGATE_H
#include <QItemDelegate>
#include <QPixmap>
#include "views/messages/messagesstyle.h"

class MessagesItemDelegate: public QItemDelegate
{

    public:
        MessagesItemDelegate(QObject* parent = 0, MessagesStyle* contactsStyle = 0);
        void paint(QPainter* painter,
                   const QStyleOptionViewItem& option,
                   const QModelIndex& index) const;
                   
    protected:
        virtual void drawFocus(QPainter* painter, const QStyleOptionViewItem& option,
                               const QRect& rect) const;
    private:
        MessagesStyle* m_style;//一览画面属性
        
};

#endif // MESSAGESITEMDELEGATE_H

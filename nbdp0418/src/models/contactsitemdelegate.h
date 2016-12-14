/****************************************************************************
**
** 文件名称： contactsitemdelegate.h
** 功能概述: 联系人列表Delegate类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef CONTACTSITEMDELEGATE_H
#define CONTACTSITEMDELEGATE_H
#include <QItemDelegate>
#include <QPixmap>
#include "views/contacts/contactsstyle.h"

class ContactsItemDelegate: public QItemDelegate
{

    public:
        ContactsItemDelegate(QObject* parent = 0, ContactsStyle* contactsStyle = 0);
        void paint(QPainter* painter,
                   const QStyleOptionViewItem& option,
                   const QModelIndex& index) const;
        void setIndividualFlag(bool individualFlag) {  m_individualFlag = individualFlag; }
        
    protected:
        virtual void drawFocus(QPainter* painter, const QStyleOptionViewItem& option,
                               const QRect& rect) const;
    private:
        ContactsStyle* m_contactsStyle;//联系人一览属性类指针
        bool     m_individualFlag;//个人联系人标识
        
};

#endif // CONTACTSITEMDELEGATE_H

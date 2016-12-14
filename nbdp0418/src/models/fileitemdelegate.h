/****************************************************************************
**
** 文件名称： fileitemdelegate.h
** 功能概述: 文件列表Delegate类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef FILEITEMDELEGATE_H
#define FILEITEMDELEGATE_H
#include <QItemDelegate>
#include <QPixmap>
#include "views/manager/managerfilestyle.h"

class FileItemDelegate: public QItemDelegate
{

    public:
        FileItemDelegate(QObject* parent = 0, ManagerFileStyle* contactsStyle = 0);
        void paint(QPainter* painter,
                   const QStyleOptionViewItem& option,
                   const QModelIndex& index) const;
        void setIntEditRow(int intEditRow) {m_intEditRow = intEditRow ;}
        int    getIntEditRow() {return m_intEditRow ;}
        
    protected:
        virtual void drawFocus(QPainter* painter, const QStyleOptionViewItem& option,
                               const QRect& rect) const;
                               
    private:
        ManagerFileStyle* m_style;
        int  m_intEditRow;
        int  m_intEditCol;
};

#endif // FILEITEMDELEGATE_H

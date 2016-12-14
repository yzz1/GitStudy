/****************************************************************************
**
** 文件名称： managerdelegate.h
** 功能概述: 文件管理列表Delegate类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef MANAGERDELEGATE_H
#define MANAGERDELEGATE_H

#include <QItemDelegate>
#include <QPixmap>
#include "views/manager/managerstyle.h"
#include "views/scan/scangroupstyle.h"
#include <QWidget>
#include "views/call/callcommunicationstyle.h"
#include "views/call/callfilestyle.h"
#include "views/call/callphrasebookstyle.h"

class ManagerDelegate: public QItemDelegate
{

    public:
        ManagerDelegate(QObject* parent = 0, ManagerStyle* contactsStyle = 0);
        ManagerDelegate(QObject* parent = 0, ScanGroupStyle* contactsStyle = 0);
        ManagerDelegate(QObject* parent = 0, CallCommunicationStyle* contactsStyle = 0);
        ManagerDelegate(QObject* parent = 0, CallPhraseBookStyle* contactsStyle = 0);
        ManagerDelegate(QObject* parent = 0, CallFileStyle* contactsStyle = 0);
        void paint(QPainter* painter,
                   const QStyleOptionViewItem& option,
                   const QModelIndex& index) const;
        void setSelectedHidden(bool hidden);
        void setCallFileFlag(bool callFileFlag) {m_callFileFlag = callFileFlag;}
        // QString setTexTWrap(QString strInputText);
        
    protected:
        virtual void drawFocus(QPainter* painter, const QStyleOptionViewItem& option,
                               const QRect& rect) const;
                               
    private:
        ContactsStyle* m_style;//一览画面属性
        bool m_selectedHidden;//// call insert 画面 光标丢失后不高亮显示
        bool m_callFileFlag;// Call load 文件一览画面标识
};

#endif // MANAGERDELEGATE_H

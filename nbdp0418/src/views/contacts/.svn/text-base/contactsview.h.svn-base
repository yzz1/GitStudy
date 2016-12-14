/****************************************************************************
**
** 文件名称： contactsview.h
** 功能概述:  站台联系表界面类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef CONTACTSVIEW_H
#define CONTACTSVIEW_H

#include <QWidget>
#include <QMap>
#include "models/contactsmodel.h"

namespace Ui
{
    class ContactsView;
}

class ContactsView : public QWidget
{
        Q_OBJECT
        
    public:
        explicit ContactsView(QWidget* parent = 0);
        ~ContactsView();
        
    signals :
        void afterPageSignal(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        
    private:
        Ui::ContactsView* ui;           //联系站台的
        bool m_optionMenuStatus;  //option 菜单的开关
        ContactsModel* m_model;   //联系站台的数据模型
        bool eventFilter(QObject* watched, QEvent* event);
        
    public slots:
        void showOptionMenu();
        void deleteSelectedRow();
        void editClickedSolt();
        void  newClickedSolt();
        void  cancelClickedSolt();
        void  homeClickedSlot();
        void individualClickedSlot();
        void printClickedSlot();
        void  importClickedSlot();
        void  exportClickedSlot();
        void frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
};



#endif // CONTACTSVIEW_H

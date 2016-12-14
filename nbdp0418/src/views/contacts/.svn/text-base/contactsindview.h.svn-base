/****************************************************************************
**
** 文件名称： contactsindview.h
** 功能概述:  个人联系表界面类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef CONTACTSINDVIEW_H
#define CONTACTSINDVIEW_H

#include <QWidget>
#include <QMap>
#include "models/contactsmodel.h"

namespace Ui
{
    class ContactsIndView;
}

class ContactsIndView : public QWidget
{
        Q_OBJECT
        
    public:
        explicit ContactsIndView(QWidget* parent = 0);
        ~ContactsIndView();
        void show();
    signals :
        void afterPageSignal(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        
    private:
        Ui::ContactsIndView* ui;
        bool m_optionMenuStatus;  //option 菜单的开关
        ContactsModel* m_model;   //数据模型
        bool eventFilter(QObject* watched, QEvent* event);
    public slots:
        void showOptionMenu();
        void deleteSelectedRow();
        void editClickedSolt();
        void  newClickedSolt();
        void  cancelClickedSolt();
        void  homeClickedSlot();
        void stationClickedSlot();
        void  importClickedSlot();
        void  exportClickedSlot();
        void  printClickedSlot();
        void frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        
        
        
};

#endif // CONTACTSINDVIEW_H


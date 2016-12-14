/****************************************************************************
**
** 文件名称： individualselectview.h
** 功能概述:  call联系人选择界面类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef INDIVIDUALSELECTVIEW_H
#define INDIVIDUALSELECTVIEW_H

#include <QDialog>
#include <QMap>
#include "models/contactsmodel.h"
class QListWidgetItem;

namespace Ui
{
    class IndividualSelectView;
}

class IndividualSelectView : public QDialog
{
        Q_OBJECT
        
    public:
        explicit IndividualSelectView(QWidget* parent = 0);
        ~IndividualSelectView();
        
    private:
        Ui::IndividualSelectView* ui;
        ContactsModel* m_model;   //数据模型
        bool eventFilter(QObject* watched, QEvent* event);
        bool m_callOrReceive;	//主叫被叫模式
        
    signals :
        void afterPageSignal(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        
    public slots:
        void homeClickedSlot();
        void okButtonClickedSlot();
        void cancelButtonClickedSlot();
        void receiveButtonClickedSlot();
        void callButtonClickedSlot();
        
        void activatedSlot(QModelIndex index);
        void  frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        
};

#endif // INDIVIDUALSELECTVIEW_H

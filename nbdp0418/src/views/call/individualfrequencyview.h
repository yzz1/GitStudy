/****************************************************************************
**
** 文件名称： individualfrequencyview.h
** 功能概述:  call选择联系人界面类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef INDIVIDUALFREQUENCYVIEW_H
#define INDIVIDUALFREQUENCYVIEW_H

#include <QWidget>
#include <QMap>
#include "models/contactsmodel.h"

namespace Ui
{
    class IndividualFrequencyView;
}

class IndividualFrequencyView : public QWidget
{
        Q_OBJECT
        
    public:
        explicit IndividualFrequencyView(QWidget* parent = 0);
        ~IndividualFrequencyView();
        void initTableView();
        
    private:
        Ui::IndividualFrequencyView* ui;
        ContactsModel* m_model;
        QString m_name;
        QString m_owner;
        QString m_fkey;
        QString m_callCode;
        
    signals :
        void afterPageSignal(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        
    public slots:
        void frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        void  homeClickedSlot();
        void  okButtonClickedSlot();
        void  cancelButtonClickedSlot();
};

#endif // INDIVIDUALFREQUENCYVIEW_H

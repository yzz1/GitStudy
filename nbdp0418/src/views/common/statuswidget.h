/****************************************************************************
**
** 文件名称： statuswidget.h
** 功能概述:  状态栏界面类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef StatusWidget_H
#define StatusWidget_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QSignalMapper>
#include "models/contactsmodel.h"
#include "messageclass.h"

class StatusWidget: public QWidget
{
        Q_OBJECT
        
    public:
        explicit StatusWidget(QWidget* parent = NULL);        
        ~StatusWidget() {}
    private:
        StatusWidget& operator=(const StatusWidget& obj);
        StatusWidget(const StatusWidget& obj);
        
    private slots:
        void timer_deal_slot_function();
        void SlotSetMMSI(QString mmsi);
        void SlotState(QString state);
        void updateMailIcon(bool bResult);
        
    private:
        static StatusWidget* m_pInstance;
        QLabel* m_signal;
        QLabel* m_status;
        QLabel* m_mail;
        QLabel* m_time;
        QLabel* m_mmsi;
        QLabel* m_mmsiNo;
        QSqlTableModel* m_model;
        QSqlTableModel* m_messageModel;
        QHBoxLayout* m_layout;

public :
        QString get_strSelfMMSI();
};
extern QString g_selfMMSI;

#endif // StatusWidget_H

/****************************************************************************
**
** 文件名称： callcommunication.h
** 功能概述:  call主界面类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef CALLVIEW_H
#define CALLVIEW_H

#include <QWidget>
#include <QMap>
#include <QListWidgetItem>
#include <QTimer>
#include "../myCom/mainwindow.h"
#include "widgets/iocmessage.h"

namespace Ui
{
    class CallView;
}

class CallContactsData
{
    public :
        QString name;
        QString callCode;
        QString strChannel;
        QString strTx;
        QString strRx;
        void clear();
};

class CallView : public QWidget
{
        Q_OBJECT
        
    public:
        explicit CallView(QWidget* parent = 0);
        ~CallView();
        bool eventFilter(QObject* watched, QEvent* event);
        
    private:
        Ui::CallView* ui;
        bool m_upFlag;
        bool m_rightFlag;
        bool m_leftFlag;
        CallContactsData m_callModeStaionDate;
        CallContactsData m_callModeIndividualDate;
        CallContactsData m_callModeManualDate;
        CallContactsData m_recvModeStaionDate;
        CallContactsData m_recvModeIndividualDate;
        CallContactsData m_recvModeManualDate;
        CallContactsData* m_stationData;
        CallContactsData* m_individualDate;
        CallContactsData* m_manualDate;
        bool m_callOrReceive;	//主叫被叫模式
        QMap <QString, QString> m_CallParaMap;
        int m_countTimeS;
        int m_nTimerId;
        int m_callMode;
        QTimer* m_timer;
        bool timeoutFlag;
        IocMessage m_iocMessage;
        bool m_keyupDown;
        
    signals :
        void afterPageSignal(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        
    public slots:
        void frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        void homeClickedSlot();
        void okButtonClickedSlot();
        void cancelButtonClickedSlot();
        void callButtonClickedSlot();
        void receiveButtonClickedSlot();
        void updateTimeoutFlagSlot();
        void buttonPressedSlot(int id);
};
extern MainWindow* g_mainWorkFlow;
#endif // CALLVIEW_H

/****************************************************************************
**
** 文件名称： callcommunication.h
** 功能概述:  call通讯界面类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef CALLCOMMUNICATION_H
#define CALLCOMMUNICATION_H

#include <QWidget>
#include <QMap>
#include <QTimer>
#include "models/messagesmodel.h"
#include "views/common/constants.h"
#include "widgets/iocmessage.h"
#include "callcommunicationwidget.h"
#include "transit.h"

class MainWindow;
class nbdpWorkflow;
namespace Ui
{
    class CallCommunication;
}

class CallCommunication : public QWidget
{
        Q_OBJECT
        enum State {TUNING, WATINGCONNECT, CONNECTING, CONNECTED};
    public:
        explicit CallCommunication(QWidget* parent = 0);
        ~CallCommunication();
        void communicationExit(bool showQuitDialog = true, bool isUnread = false);
        bool eventFilter(QObject* watched, QEvent* event);
        void setTableViewRowHeight();
        QString  setTexTWrap(QString strInputText);
        
        void startWaitConnect();
        void startConnect();
        void startCommunication();
        QString  reMoveHuanHang(QString str );
        
    signals :
        void afterPageSignal(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        void hasUnreadMessage(bool hasUnread);
        
    public slots:
        void frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        void CheckInputText();
        void showOptionMenu();
        void showInsertMenu();
        void homeClickedSlot();
        void sendMessage(QString  strReceiveMessage = "");
        void macroMenu();
        void phrasebookMessage();
        void printClickedSlot();
        void widgetDataBackSlot();
        void loadMessage();
        void sendWRU();
        void sendHR();
        void sendOver();
        void sendBreak();
        void SlotRealTimePrinting(QString printMode);
        void SlotTimerUpdate();
        void SlotSignalWaitTimeOut();
        void SlotDialogCloseTimeout();
        
        void SlotCallWait(bool b);
        void SlotTurningResult(bool b);
        void SlotConnectingWait(bool b);
        void SlotConnectingResult(bool b);
        void SlotTalkSendConfirm(QString strNo, bool b);
        void SlotTalkReceive(QString str);
        void SlotInteruptConfirm(bool b);
        void SlotInteruptDSC();
        void SlotInteruptComu();
        void SlotMessageEnd();

        void SlotSetLineEditState(bool b);
        void SlotReflashMMSI(QString strMMSI);
        void SlotReflashCallMode(QString strCallMode);
        
    private:
        Ui::CallCommunication* ui;
        bool m_optionMenuStatus;   //option菜单打开状态
        bool m_insertMenuStatus;   //insert菜单打开状态
        QMap<QString, QString>  m_paraMap;
        MessagesModel* m_model;   //数据模型
        bool m_connectFlag;
        IocMessage m_commStatusMessage;	//提示对话框
        QString m_strMessageListUUID; //通讯记录的UUID
        CallCommunicationwidget* m_widget; //数据库查询显示窗口
        QString m_realTimePrinting; //打印机模式
        QString m_strCallOrReceive; //主叫被叫模式
        //QString m_strStyleSheetWhite; // Transmit or receive的高亮显示样式
        QIcon    m_whiteQIconTransmit;// Transmit的高亮显示图标
        QIcon    m_grayQIconTransmit;// Transmit的灰色显示图标
        QIcon    m_whiteQIconReceive;// receive的高亮显示图标
        QIcon    m_grayQIconReceive;// receive的灰色显示图标
        QString m_strStyleSheetGray;// Transmit or receive的灰色显示样式
        QTimer* m_commuTimer;
        QTimer* m_waitSignalTimer;
        QTimer* m_dialogCloseWaitTime;
        int m_secs;
        
        State m_state;
        QString m_startTime;
        int m_row;
};
extern MainWindow* g_mainWorkFlow;
extern nbdpWorkflow* g_nbdpWorkFlow;
#endif // CALLCOMMUNICATION_H

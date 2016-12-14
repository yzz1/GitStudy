/****************************************************************************
**
** 文件名称： control.h
** 功能概述: 协议控制类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef Control_H
#define Control_H

#include <QObject>
#include "control_global.h"
#include "transit.h"
#include "../myCom/mainwindow.h"
#include "../myCom/UIDefineInsStruct.h"
#include "../myCom/UISerial.h"
#include "../myCom/nbdpWorkFlow.h"



class CONTROLSHARED_EXPORT Control : public QObject
{
        Q_OBJECT
    public:
        static Control*  get();
        ~Control();
        void KeyDownForTest(QString strMdf, int intKc);        
        void sendCSOneChar(QString strMsg);         //yzz
        void sendCSThreeChar(QString strMsg);       //yzz
        void sendInfoMessage(QByteArray strMsg);
        void sendNBDP_StateFlag(unsigned char SwitchFlag);
    public slots:
        void SlotTalkAndCSSend(QString strNo, QString strMsg);
        void SlotReflashDeviceInfo(QString four,QString nine,QString answerCode);

    private slots:
        void SlotCallSetup(CallClass* cc);
        void SlotConnectingCancel();
        void SlotTalkSend(QString strNo, QString strMsg);

        void SlotInterupt();
        void SlotScan(ScanClass* sc);
        void SlotCheck();
        void SlotMarkTrans();
        void SlotSpaceTrans();
        void SlotDotTrans();
        void SlotSlaveDelay(int i);
        void SlotRadioConnectAsk();
        void SlotSendScanFreq();
        void SlotSendStrMsgTimer();

        void SlotKillSendScanFreqTimer();
        void SLot_workFlow_readyAndIdle();
        void SlotBS_FECStartLink(bool b);
        void SlotCalledReceive(int calledType);

    private:
        Control();
        static Control* m_pInstance;
        QString m_strNo;
        QTimer *sendScanFreqTimer;
        QString m_strMsg;             //FEC
        QByteArray m_charMsg;         //ARQ
        QByteArray m_repeate_charMsg;
        QTimer *sendStrMsgTimer;

        ScanClass* m_sc;
        int sendScanFreqTimer_count;
        int sendStrMsg_count;
};
extern MainWindow* g_mainWorkFlow;
extern UISerial*  g_mSerial;
extern nbdpWorkflow *g_nbdpWorkFlow;
extern QString g_selfMMSI;
#endif // Control_H

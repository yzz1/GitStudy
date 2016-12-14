/****************************************************************************
**
** 文件名称： transit.h
** 功能概述: 信息中继类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef TRANSIT_H
#define TRANSIT_H

#include "transit_global.h"
#include <QObject>
#include <QString>
#include <QList>

#include "messageclass.h"
#include "callclass.h"
#include "scanclass.h"
#include "callinfoclass.h"
#include "checkdataclass.h"

class TRANSITSHARED_EXPORT Transit : public QObject
{
        Q_OBJECT
    public:
        static Transit*  get();
        ~Transit();
        void EmitSignalState(QString str);       // r1
        void EmitSignalCallSetup(CallClass* cc); //发起调谐
        void EmitSignalTurningResult(bool b);    // r1  tiaoXie result
        void EmitSignalConnectingWait(bool b);    // r1 zhegn zai jian lian
        void EmitSignalConnectingResult(bool b);   // r1 jian lian success

        void EmitSignalConnectingCancel();      //断开连接指令
        void EmitSignalTalkSend(QString strNo, QString strMsg);
        void EmitSignalTalkSendConfirm(QString strNo, bool b);     // r1
        void EmitSignalTalkReceive(QString str);                    // r1
        void EmitSignalInterupt();
        void EmitSignalInteruptConfirm(bool b);                     // r1,通信结束，进入home
        void EmitSignalInteruptDSC();
        void EmitSignalInteruptComu();

        void EmitSignalScan(ScanClass* sc);
        void EmitSignalScanData(CallInfoClass* cic);            //r1
        void EmitSignalCheck();
        void EmitSignalCheckData(CheckDataClass* cdc);
        void EmitSignalMarkTrans();
        void EmitSignalSpaceTrans();
        void EmitSignalDotTrans();
        void EmitSignalSlaveDelay(int i);
        void EmitSignalShutDown();
        void EmitSignalRadioConnectAsk();
        void EmitSignalRadioConnectAnswer(bool ret);                // r1
        void EmitSignalMessageEnd();

        void EmitSignalDSCfollowComm(CallInfoClass* ddc);
        void EmitSignalKillSendScanFreqTimer();
        void EmitSignalLineEditState(bool b);
        void EmitSignalCalledReceive(int calledType); //(1,ARQ) (2,FEC)
        void EmitSignalJianLianEnterReady();
        void EmitSignalReflashMMSISignal(QString strMMSI);
        void EmitSignalReflashCallModeSignal(QString strCallMode);
        void EmitSignalReflashDeviceInfo(QString four,QString nine,QString answerCode);
    private:
        Transit();
        static Transit* m_pInstance;
        
    signals:
        void reflashDeviceInfo(QString four,QString nine,QString answerCode);
        void reflashCallModeSignal(QString strCallMode);
        void reflashSignal(QString strMMSI);
        void SignalJianLianEnterReady();
        void SignalState(QString str);
        void SignalCallSetup(CallClass* cc);
        void SignalCallWait(bool b);
        void SignalTurningResult(bool b);
        void SignalConnectingWait(bool b);
        void SignalConnectingResult(bool b);
        void SignalConnectingCancel();
        void SignalTalkSend(QString strNo, QString strMsg);
        void SignalTalkSendConfirm(QString strNo, bool b);
        void SignalTalkReceive(QString str);
        void SignalInterupt();
        void SignalInteruptConfirm(bool b);
        void SignalInteruptDSC();
        void SignalInteruptComu();
        void SignalScan(ScanClass* sc);
        void SignalScanData(CallInfoClass* sdc);
        void SignalCheck();
        void SignalCheckData(CheckDataClass* cdc);
        void SignalMarkTrans();
        void SignalSpaceTrans();
        void SignalDotTrans();
        void SignalSlaveDelay(int i);
        void SignalShutDown();
        void SignalKeyDownForTest(int i);
        void SignalMessageEnd();
        void SignalRadioConnectAsk();
        void SignalRadioConnectAnswer(bool);
        void SignalDSCfollowComm(CallInfoClass* ddc);
        void SignalKillSendScanFreqTimer();
        void SignalLineEditState(bool b);
        void SignalCalledReceive(int calledType); //(1,ARQ) (2,FEC)
};

#endif // TRANSIT_H

#ifndef NBDPWORKFLOW_H
#define NBDPWORKFLOW_H

#include "UISerialFilter.h"
#include "transit.h"
#include "callinfoclass.h"

#include <QTimer>



class MainWindow;
class nbdpWorkflow:QObject
{
    Q_OBJECT
protected:
    UISerialFilter* m_SerialFilter;
public:
     nbdpWorkflow(UISerialFilter* serialFilter);
     QString Q4B3Y_zhuan_QString(QByteArray msgInfo);
signals:

public slots:
       void On_SerialFilter_ConnRadioACKReceived();
       void On_SerialFilter_TurnInsACKReceived(type_NBDP_ConnectInstruction* instruction);
       void On_SerialFilter_DisconnectInsACKReceived(type_NBDP_DisconnectInstruction* ins);
       void On_SerialFilter_ScanInsACKReceived(type_NBDP_ScanInstruction* ins);
       void On_SerialFilter_ScanInsResultReceived(type_NBDP_ScanResultInstruction* ins);
       void On_SerialFilter_SelfCheckInsACKReceived(type_NBDP_SelfCheckInstruction* ins);
       void On_SerialFilter_TransmitTestInsACKReceived(type_NBDP_TransmitTestInstruction* ins);
       void On_SerialFilter_FollowCommunicateInsACKReceived(type_NBDP_FollowCommunicateInstruction* ins);
       void On_SerialFilter_StateFlag(type_NBDP_StateFlag* ins);
       void On_SerialFilter_MessageIns(QByteArray data);
       void On_slotStartScanToTurn();
private:
       QTimer *callRadioScanToTurnTimer;
       CallInfoClass m_callInfo;
public:
       QString msgInfoStr;
       int isHuanHang;              //默认是初始换行状态，前一个是换行则当前换行副忽略不发送，当前 非换行副 当前发送(全局记忆，isZhuanyi是局部记忆)

};
extern MainWindow* g_mainWorkFlow;


#endif // NBDPWORKFLOW_H

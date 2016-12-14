#ifndef UISERIALFILTER_H
#define UISERIALFILTER_H

#include <QObject>
#include "UIDefineInsStruct.h"

class MainWindow;
class Transit;
class UISerial;

class UISerialFilter : public QObject
{
    Q_OBJECT
public:
    explicit UISerialFilter(QObject *parent = 0);
    void FilterInstruction(QByteArray bytes);
signals:
    void INS_NBDP_ERROR_INSTRUCTION_Received();
    void INS_NBDP_ConnRadioACKReceived();
    void INS_NBDP_TurnInsACKReceived(type_NBDP_ConnectInstruction* instruction);
    void INS_NBDP_DisconnectInsACKReceived(type_NBDP_DisconnectInstruction* instruction);
    void INS_NBDP_ScanInsACKReceived(type_NBDP_ScanInstruction* instruction);
    void INS_NBDP_ScanInsResultReceived(type_NBDP_ScanResultInstruction* instruction);
    void INS_NBDP_SelfCheckInsACKReceived(type_NBDP_SelfCheckInstruction* instruction);
    void INS_NBDP_TransmitTestInsACKReceived(type_NBDP_TransmitTestInstruction* instruction);
    void INS_NBDP_FollowCommunicateInsACKReceived(type_NBDP_FollowCommunicateInstruction* instruction);
    //void INS_NBDP_MessageInsReceived(type_NBDP_MessageInstruction* instruction);
    void INS_NBDP_MessageInsReceived(QByteArray data);
    void INS_NBDP_StateFlag(type_NBDP_StateFlag* nbdp_StateFlagIns);

public slots:

};
extern MainWindow* g_mainWorkFlow;
extern UISerial*  g_mSerial;
#endif // UISERIALFILTER1_H

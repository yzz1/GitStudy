#ifndef UISERIAL_H
#define UISERIAL_H

#include <QDebug>
#include <QTimer>
#include <QFile>
#include <QDateTime>
#include "posix_qextserialport.h"
#include "UIDefineInsStruct.h"
#include "UISerialFilter.h"
//#include "nbdpWorkFlow.h"

class UISerial:public Posix_QextSerialPort
{
    Q_OBJECT
public:
    UISerial();
    ~UISerial();
public :
    void init_buffer();
    void on_Serial1_ReadDataFinished(QByteArray data);
    short int GetVerifyValue(QByteArray bytes);

    QByteArray* m_Buffer;
    UISerialFilter m_Filter1;
    Posix_QextSerialPort* m_serial1;
   // nbdpWorkflow* m_nbdpWorkFlow;

    void Send_NBDP_ConnRadioAskIns(type_connectRadioInstruction* ins);
    void Send_NBDP_ConnectIns(type_NBDP_ConnectInstruction* ins);
    void Send_NBDP_DisconnectIns(type_NBDP_DisconnectInstruction* ins);
    void Send_NBDP_ScanIns(type_NBDP_ScanInstruction* ins);
    void Send_NBDP_SelfCheckIns(type_NBDP_SelfCheckInstruction* ins);
    void Send_NBDP_TransmitTestIns(type_NBDP_TransmitTestInstruction* ins);
    void Send_NBDP_FollowCommunicateIns(type_NBDP_FollowCommunicateInstruction* ins);
    void Send_NBDP_MessageIns(type_NBDP_MessageInstruction* ins);
    void Send_NBDP_StartFecLinkIns(type_NBDP_FECStartLinkInstruction* ins);
    void Send_NBDP_CalledReceiveIns(type_NBDP_CalledReceiveInstruction* ins);
    void Send_NBDP_DeviceInfoIns( type_NBDP_ReflashDeviceInfo* ins );
    void Send_NBDP_HuiChe();
private:
    QDateTime m_mSec;

};


#endif // UISERIAL_H

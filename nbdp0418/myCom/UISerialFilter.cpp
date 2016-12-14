#include "QDebug"
#include "UISerialFilter.h"
#include "mainwindow.h"
#include "transit.h"
#include "UISerial.h" //yzz

UISerialFilter::UISerialFilter(QObject *parent) :
    QObject(parent)
{
}

/*****************************符合帧头和校验码**********************************/

void UISerialFilter::FilterInstruction(QByteArray bytes)
{
    unsigned char uchar=(unsigned char)bytes.at(6);
    int nInsCode=(int)uchar;

   qDebug()<<"receive is:"<<bytes.toHex();

    switch(nInsCode)
    {
    case INS_CODE_NBDP_ReceiveIdle:
    {
        Transit::get()->EmitSignalState("Idle");  //idle,auto
    }
        break;
    case INS_CODE_NBDP_FECStartLink:

        if(g_mainWorkFlow->workFlowState==2)
        {
        qDebug()<<"enter FEC Jian result";
        type_NBDP_FECStartLinkInstruction*  FecStartLinkIns=(type_NBDP_FECStartLinkInstruction*)bytes.data();
        QString strCallType=CallClass::get()->getCallInfo()->getCallType();

        if( FecStartLinkIns->linkState==0x01 && strCallType.compare("ARQ") != 0 ) // communication ui
           {
            Transit::get()->EmitSignalConnectingResult(true);         //从建连 到 通信界面
            bool strisCall=CallClass::get()->getIsCall();

            if(strCallType.compare("BFEC")==0 && strisCall==1 )
               {  Transit::get()->EmitSignalState("Outgoing BFEC"); g_mSerial->Send_NBDP_HuiChe(); } //BFEC 发射
            else if(strCallType.compare("SFEC")==0 && strisCall==1 )
               {  Transit::get()->EmitSignalState("Outgoing SFEC"); g_mSerial->Send_NBDP_HuiChe(); } //SFEC 发射
                                                                                                     //     接受是单独的建连过程
           }
        else
            Transit::get()->EmitSignalConnectingResult(false);   // back to call setUp
        }
        break;
    case INS_CODE_NBDP_Message:
    {
        if( g_mainWorkFlow->workFlowState == 3 )   //break,则状态改为0
        {
            emit INS_NBDP_MessageInsReceived(bytes);
        }
    }
        break;
    case INS_CODE_NBDP_connRadio:
       // if(g_mainWorkFlow->workFlowState==0)
        {
            emit INS_NBDP_ConnRadioACKReceived();  qDebug()<<"01:emit connRadioCK,tel ui";
            g_mainWorkFlow->workFlowState=1;
        }
        break;
    case INS_CODE_NBDP_Turn:     //tell ui turn change to jianLian
     {
        qDebug()<<"workFlowState need 1 current is:"<<g_mainWorkFlow->workFlowState;
        if(g_mainWorkFlow->workFlowState==1)  //调谐成功后，改变为接受建连状态，否则不变化
        {
             qDebug()<<"enter turn result";
             type_NBDP_ConnectInstruction* nbdp_ConnectIns=(type_NBDP_ConnectInstruction*)bytes.data();
             emit INS_NBDP_TurnInsACKReceived(nbdp_ConnectIns);
        }
    }
        break;
    case INS_CODE_NBDP_Disconnect:  //do nothing, ui tell xieYi,and back no use
    {
        type_NBDP_DisconnectInstruction* nbdp_DisconnectIns=(type_NBDP_DisconnectInstruction*)bytes.data();
        emit INS_NBDP_DisconnectInsACKReceived(nbdp_DisconnectIns); qDebug()<<"03:start unlink,tel ui";
    }
        break;
    case INS_CODE_NBDP_Scan:
    {
          if(g_mainWorkFlow->workFlowState==1)  //状态为1，可以接受控制指令
          {
            g_mainWorkFlow->workFlowState=2;
            type_NBDP_ScanInstruction* nbdp_ScanIns=(type_NBDP_ScanInstruction*)bytes.data();
            emit INS_NBDP_ScanInsACKReceived(nbdp_ScanIns); qDebug()<<"04:start scan,tel ui";
          }
    }
        break;
    case INS_CODE_NBDP_ScanResult:
    {
       qDebug()<<"receive scan result";
        if(g_mainWorkFlow->workFlowState==2 || CallClass::get()->getIsScan() == true)  // ，验证正确后， 被呼叫转入通信界面
        {
            qDebug()<<"enter scan result";
            type_NBDP_ScanResultInstruction* nbdp_ScanResultIns=(type_NBDP_ScanResultInstruction*)bytes.data();
            emit INS_NBDP_ScanInsResultReceived(nbdp_ScanResultIns);qDebug()<<"041:have get scan tx rx,tel ui";
        }
    }
        break;
    case INS_CODE_NBDP_CalledReceive:
    {
        qDebug()<<"receive Called Receive reback";
         if(g_mainWorkFlow->workFlowState==2)  // 收到开始接受的回复，被呼叫台开始接受数据
         {

         }
    }
        break;
    case INS_CODE_NBDP_SelfCheck:
    {
        if(g_mainWorkFlow->workFlowState==1)
        {
        type_NBDP_SelfCheckInstruction* nbdp_SelfCheckIns=(type_NBDP_SelfCheckInstruction*)bytes.data();
        emit INS_NBDP_SelfCheckInsACKReceived(nbdp_SelfCheckIns);qDebug()<<"05:start selfcheck,tel ui";
        }
    }
        break;
    case INS_CODE_NBDP_TransmitTest:
    {
        if(g_mainWorkFlow->workFlowState==1)
        {
        type_NBDP_TransmitTestInstruction* nbdp_TransmitTestIns=(type_NBDP_TransmitTestInstruction*)bytes.data();
        emit INS_NBDP_TransmitTestInsACKReceived(nbdp_TransmitTestIns);qDebug()<<"06:start tansmitr,tel ui";
        }
    }
        break;
    case INS_CODE_NBDP_FollowCommunicate:
    {
        if(g_mainWorkFlow->workFlowState==1)
        {
         type_NBDP_FollowCommunicateInstruction* nbdp_FollowCommunicateIns=(type_NBDP_FollowCommunicateInstruction*)bytes.data();
         emit INS_NBDP_FollowCommunicateInsACKReceived(nbdp_FollowCommunicateIns);qDebug()<<"07:start followComm,tel ui";
        }
    }
        break;
    case INS_CODE_NBDP_StateFlag:
       {
        type_NBDP_StateFlag* nbdp_StateFlagIns = ( type_NBDP_StateFlag* )bytes.data();
        emit INS_NBDP_StateFlag(nbdp_StateFlagIns); qDebug()<<"08:receive stateFlag over";
       }
        break;
    default:
        qDebug()<<"received remote_Error_Ins:";     
        break;
    }

}


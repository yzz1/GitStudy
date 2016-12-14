
#include <QObject>
#include <QtCore/qmath.h>
#include <math.h>
#include "nbdpWorkFlow.h"
#include "mainwindow.h"

nbdpWorkflow::nbdpWorkflow(
        UISerialFilter* serialFilter
    )
{

    connect(serialFilter,  SIGNAL(INS_NBDP_ConnRadioACKReceived()), this, SLOT(On_SerialFilter_ConnRadioACKReceived()));
    connect(serialFilter,  SIGNAL(INS_NBDP_TurnInsACKReceived(type_NBDP_ConnectInstruction*)), this, SLOT(On_SerialFilter_TurnInsACKReceived(type_NBDP_ConnectInstruction*)));
    connect(serialFilter,  SIGNAL(INS_NBDP_DisconnectInsACKReceived(type_NBDP_DisconnectInstruction* )), this, SLOT(On_SerialFilter_DisconnectInsACKReceived(type_NBDP_DisconnectInstruction*)));
    connect(serialFilter,  SIGNAL(INS_NBDP_ScanInsACKReceived(type_NBDP_ScanInstruction* )), this, SLOT(On_SerialFilter_ScanInsACKReceived(type_NBDP_ScanInstruction*)));
    connect(serialFilter,  SIGNAL(INS_NBDP_ScanInsResultReceived(type_NBDP_ScanResultInstruction* )), this, SLOT(On_SerialFilter_ScanInsResultReceived(type_NBDP_ScanResultInstruction*)));
    connect(serialFilter,  SIGNAL(INS_NBDP_SelfCheckInsACKReceived(type_NBDP_SelfCheckInstruction* )), this, SLOT(On_SerialFilter_SelfCheckInsACKReceived(type_NBDP_SelfCheckInstruction*)));
    connect(serialFilter,  SIGNAL(INS_NBDP_TransmitTestInsACKReceived(type_NBDP_TransmitTestInstruction* )), this, SLOT(On_SerialFilter_TransmitTestInsACKReceived(type_NBDP_TransmitTestInstruction*)));
    connect(serialFilter,  SIGNAL(INS_NBDP_FollowCommunicateInsACKReceived(type_NBDP_FollowCommunicateInstruction* )), this, SLOT(On_SerialFilter_FollowCommunicateInsACKReceived(type_NBDP_FollowCommunicateInstruction*)));
    //connect(serialFilter,  SIGNAL(INS_NBDP_MessageInsReceived(type_NBDP_MessageInstruction* instruction)), this, SLOT(On_SerialFilter_MessageIns(type_NBDP_MessageInstruction*)));
    connect(serialFilter,  SIGNAL(INS_NBDP_MessageInsReceived(QByteArray )), this, SLOT(On_SerialFilter_MessageIns(QByteArray)));
    connect(serialFilter, SIGNAL(INS_NBDP_StateFlag(type_NBDP_StateFlag*)),this,SLOT(On_SerialFilter_StateFlag(type_NBDP_StateFlag*)));
    callRadioScanToTurnTimer= new QTimer();
    connect(callRadioScanToTurnTimer,SIGNAL(timeout()),this,SLOT(On_slotStartScanToTurn()));
    isHuanHang=1;
}

/**************************调谐成功以后的指令******************************************/

void nbdpWorkflow::On_SerialFilter_StateFlag(type_NBDP_StateFlag* ins)
{
    unsigned char whichFlag = ins->StateFlag;

    switch ( whichFlag )
    {
        case 0:
            if( g_mainWorkFlow->workFlowState == 2 )
                 Transit::get()->EmitSignalConnectingResult(false);     //建连失败 (状态为1重新调谐)
                 g_mainWorkFlow->workFlowState = 1;
                 //Transit::get()->EmitSignalJianLianEnterReady() ;
            break;
        case 1:
            qDebug()<<"need workFlowState == 2 current is"<< g_mainWorkFlow->workFlowState;
             if( g_mainWorkFlow->workFlowState == 2 )                  //建连成功，计入通信(状态为3)
                {
                 Transit::get()->EmitSignalConnectingResult(true);
                 //Transit::get()->EmitSignalLineEditState(true);          //光标打开与否看收发状态
                 Transit::get()->EmitSignalState("ARQ Connected");       //左上角
                 g_mainWorkFlow->workFlowState = 3;
                }
            break;
        case 2:
            if( g_mainWorkFlow->workFlowState == 3 )                   //锁定
           {
             Transit::get()->EmitSignalLineEditState(false);
           }
            break;
        case 3:
       // if( g_mainWorkFlow->workFlowState == 3 )                       //解锁
           {
            Transit::get()->EmitSignalLineEditState(true);
            qDebug()<<"unLock cursor";
           }
            break;
        case 4:
        if( g_mainWorkFlow->workFlowState == 3 || g_mainWorkFlow->workFlowState == 2)     //通信结束，进入Home
           {
            if( g_mainWorkFlow->workFlowState == 3  )
            {
            Transit::get()->EmitSignalInteruptConfirm(true);
            Transit::get()->EmitSignalState("Idle");       //左上角
            g_mainWorkFlow->workFlowState = 1;
            }
            else if(  g_mainWorkFlow->workFlowState == 2 )
            {
                Transit::get()->EmitSignalJianLianEnterReady() ;
            }
           }
            break;
        default:
           break;
    }
}
void nbdpWorkflow::On_slotStartScanToTurn()
{
     callRadioScanToTurnTimer->stop();             //执行一次，只为启动调谐过程
     Transit::get()->EmitSignalScanData(&m_callInfo);
}
void nbdpWorkflow::On_SerialFilter_ConnRadioACKReceived()
{
     Transit::get()->EmitSignalRadioConnectAnswer(true);
}

void nbdpWorkflow::On_SerialFilter_TurnInsACKReceived(type_NBDP_ConnectInstruction* instruction)
{       
            switch(instruction->s_TunePara.s_TuneResult)
            {
            case 0x00:
                 Transit::get()->EmitSignalTurningResult(false);
                 qDebug()<<"turn false";
                break;
            case 0x01:
                 Transit::get()->EmitSignalTurningResult(true);
                 g_mainWorkFlow->workFlowState=2;
                 qDebug()<<"turn success";
                break;
            default:
                qDebug()<<"no turn result,turn result is:"<<instruction->s_TunePara.s_TuneResult;
                break;
            }

}

void nbdpWorkflow::On_SerialFilter_DisconnectInsACKReceived(type_NBDP_DisconnectInstruction* ins)
{
  // Transit::get()->EmitSignalInteruptComu();
}
void nbdpWorkflow::On_SerialFilter_ScanInsACKReceived(type_NBDP_ScanInstruction* ins)
{
    // 默认点击按钮就已经开始扫描了 ScanGroupView->startClickedSolt

}
void nbdpWorkflow::On_SerialFilter_ScanInsResultReceived(type_NBDP_ScanResultInstruction* ins)
{
  CallInfoClass callInfo;

  QString str_Mode;
  if(ins->s_MODE==0x01)
      str_Mode="ARQ";
  else if(ins->s_MODE==0x02)
      str_Mode="FEC";


  bool isCall=CallClass::get()->getIsCall();
  bool isScan=CallClass::get()->getIsScan();

  if(isCall==0 && isScan== false)    // 被呼叫 ( 非扫描)
  {
       int mode=(int)ins->s_MODE;
       Transit::get()->EmitSignalCalledReceive(mode);
       if( str_Mode.compare("FEC")==0 )
       {
            CallClass::get()->getCallInfo()->setCallType("FEC");
            Transit::get()->EmitSignalConnectingResult(true);     //转入通信界面，收到数据前一直为Idle
            Transit::get()->EmitSignalState("Incoming FEC");
       }
       else if( str_Mode.compare("ARQ")==0 )
       {
           CallClass::get()->getCallInfo()->setCallType("ARQ");
           g_mainWorkFlow->on_sendCallCode_callRadio(true);
          // Transit::get()->EmitSignalState("ARQ connected");
       }

  }
  else if(isScan== true)            //扫描结果  (扫描）
  {
      callInfo.setCallType(str_Mode);
      if( CallClass::get()->getCallInfo()->getCallType().compare("ARQ") == 0 && str_Mode.compare("ARQ")!=0 )
          return ;



    callInfo.setCallCode("00000000");   //callInfo tell ui
    CallClass::get()->setCallInfo(&callInfo);

  switch(ins->s_ScanResult)
  {
  case 0x01:
      Transit::get()->EmitSignalKillSendScanFreqTimer();
      Transit::get()->EmitSignalCallSetup(CallClass::get());  //收到扫描结果，发送调谐指令

      m_callInfo=callInfo;
      callRadioScanToTurnTimer->start(5);
      g_mainWorkFlow->workFlowState=1;               //扫描结果，可以接受调谐指令
      qDebug()<<"get scan result";
      break;
  default:
     qDebug()<<"no get scan result"<<ins->s_ScanResult;
      break;
  }

  }
}

//自检-yzz
void nbdpWorkflow::On_SerialFilter_SelfCheckInsACKReceived(type_NBDP_SelfCheckInstruction* ins)
{
    CheckDataClass checkData;

    if(ins->Transmit == 0x01)
        checkData.setTransmissionCheck(true);
    else
        checkData.setTransmissionCheck(false);
    if(ins->Receive == 0x01)
        checkData.setReceiveCheck(true);
    else
        checkData.setReceiveCheck(false);


    Transit::get()->EmitSignalCheckData(&checkData);

}
void nbdpWorkflow::On_SerialFilter_TransmitTestInsACKReceived(type_NBDP_TransmitTestInstruction* ins)
{

}
//DSC后续通信-yzz
void nbdpWorkflow::On_SerialFilter_FollowCommunicateInsACKReceived(type_NBDP_FollowCommunicateInstruction* ins)
{
    CallInfoClass* ddc;
    QString callMMSI;
    QString callMMSI_real;
    switch(ins->s_MODE)
    {
    case 0x01:
            ddc->getCallType()="ARQ";
        break;
    case 0x02:
            ddc->getCallType()="BFEC";
        break;
    case 0x03:
            ddc->getCallType()="SFEC";
        break;
    default:
        break;
    }

    ddc->setCallTx(QString("%s").arg(ins->s_TX));
    ddc->setCallRx(QString("%s").arg(ins->s_RX));
    //ddc->getCallCode()=ins->s_CalledMMSI;
    if(ins->s_MODE == 0x02)
        ddc->setCallCode("0000000003");
    else
    {
        callMMSI=QString("%s").arg(ins->s_CalledMMSI.s_MMSI1)+QString("%s").arg(ins->s_CalledMMSI.s_MMSI2)+
                QString("%s").arg(ins->s_CalledMMSI.s_MMSI3)+QString("%s").arg(ins->s_CalledMMSI.s_MMSI4)+QString("%s").arg(ins->s_CalledMMSI.s_MMSI5);
        if( callMMSI.mid(callMMSI.size()-1,1)=="0") // 9wei
            callMMSI_real=callMMSI.mid(0,9);
        else if(callMMSI.mid(callMMSI.size()-1,1)=="1") //5 wei
            callMMSI_real=callMMSI.mid(0,5);
        else if(callMMSI.mid(callMMSI.size()-1,1)=="2") //4 wei
            callMMSI_real=callMMSI.mid(0,4);
        ddc->setCallCode(callMMSI_real);
    }

    ddc->setCallOrReceive(QString("%s").arg(ins->s_RTStyle));

    Transit::get()->EmitSignalDSCfollowComm(ddc);
}
QString nbdpWorkflow::Q4B3Y_zhuan_QString(QByteArray msgInfo)
{
//    QString receivedInfo;
//    for(int i=0;i<msgInfo.count();++i)
//                {
//                     if( msgInfo.at(i)==0x00 || msgInfo.at(i)==Intbeta )
//                         continue;

//                     if(msgInfo.at(i)==g_mainWorkFlow->globalArray.mapSwitchLetterAndNum["toLetter"])
//                      { g_mainWorkFlow->isLetterState_receive=true;isZhuanYi=1; count+=1; continue;}
//                     else if(msgInfo.at(i)==g_mainWorkFlow->globalArray.mapSwitchLetterAndNum["toNum"])
//                     {  g_mainWorkFlow->isLetterState_receive=false; isZhuanYi=1;count+=1;continue;}
//                     else if(   msgInfo.at(i)==g_mainWorkFlow->globalArray.mapSwitchLetterAndNum["huiChe"]   )
//                     {
//                         receivedInfo ="\n";continue;
//                     }


//                     count=0;
//                     for(it=g_mainWorkFlow->globalArray.mapLetterToNum.begin();it!=g_mainWorkFlow->globalArray.mapLetterToNum.end();++it)
//                     {
//                         if( it.value()==msgInfo.at(i) )  count++;

//                         if(  g_mainWorkFlow->isLetterState_receive ==true && count==2 )
//                             { temp_msgInfoStr.append( it.key() ); isHuanHang=0; break;}
//                         else if( g_mainWorkFlow->isLetterState_receive ==false && count==1 )
//                              { temp_msgInfoStr.append( it.key() ); isHuanHang=0; break;}
//                     }


//                     if(count==0)   // if map haven't,then use -1 instead.
//                      { temp_msgInfoStr.clear(); /*msgInfoStr.append( "*" );*/ qDebug()<< (int)data.at(8); break;}

//                     qDebug()<<"temp_msgInfoStr"<<temp_msgInfoStr;
//                 }



//                 if(count==0)                                                  //if one ont adjust 4b3y
//                     receivedInfo.clear();
//                 else
//                     receivedInfo=(QString("ID:")+msgInfoStr+(QString(";")));  // add ID easy to recongnize


}
void nbdpWorkflow::On_SerialFilter_MessageIns(QByteArray data)
{
    QByteArray tempData = data.mid(8,data.count()-10);

    if( data.mid(7,1).at(0) == 0x06 )  //MMSI 请获取
    {
        QByteArray temp_MMSI= data.mid(8,4);
        int long_MMSI = 0;
        for( int i =0 ;i<temp_MMSI.size();++i )
            { long_MMSI+=((unsigned char)temp_MMSI.at(i))*( pow(16,6-2*i) );  qDebug()<<long_MMSI;}

        QString strMMSI= QString::number(long_MMSI,10);  //10 jinzhi

        Transit::get()->EmitSignalReflashMMSISignal(strMMSI);
        Transit::get()->EmitSignalLineEditState(false);       //被呼叫台 开始锁定
        g_mainWorkFlow->strOtherMMSI=strMMSI;

        return;

    }
    if( g_mainWorkFlow->isCallRadio==0 && ( data.mid(7,1).at(0) >= 0x01 &&  data.mid(7,1).at(0) <= 0x03) ) //被呼叫 改变通信界面标志
    {
         unsigned char callType = (unsigned char )data.mid(7,1).at(0);
         switch(callType)
         {
          case 0x01:

             Transit::get()->EmitSignalState("ARQ Connected");       //左上角
             Transit::get()->EmitSignalReflashCallModeSignal("ARQ");
             CallClass::get()->getCallInfo()->setCallType("ARQ");
             break;
         case 0x02:

             Transit::get()->EmitSignalState("Incoming FEC");
             Transit::get()->EmitSignalReflashCallModeSignal("BFEC");
             CallClass::get()->getCallInfo()->setCallType("BFEC");
             break;
         case 0x03:

             Transit::get()->EmitSignalState("Incoming FEC");
             Transit::get()->EmitSignalReflashCallModeSignal("SFEC");
             CallClass::get()->getCallInfo()->setCallType("SFEC");
             break;
         default:
             break;
         }

    }


    if( tempData.isEmpty() == false ) //ARQ 接收
    {
        msgInfoStr.append( tempData );
        qDebug()<<"info:"<<msgInfoStr<<tempData.toHex();
        for(int i =0;i<tempData.size();++i)
          {
            if(tempData.at(i) == 0x00 ||tempData.at(i) == 0xaa || tempData.at(i) == 0xab || tempData.at(i) == 0xac || tempData.at(i) == 0xad) continue;
            else if(tempData.at(i) == 0x0D || tempData.at(i) == 0x0A)
            {   if( (i > 0) && (tempData.at(i-1) == 0x0D || tempData.at(i-1) == 0x0A) )   continue;
                else   Transit::get()->EmitSignalTalkReceive(QString("\n"));
            }
            else Transit::get()->EmitSignalTalkReceive(QString(tempData.at(i)));
          }
        msgInfoStr.clear();
    }


}



//void nbdpWorkflow::On_SerialFilter_MessageIns(QByteArray data)
//{
//            QByteArray *bytes=&data;
//            QByteArray msgInfo;  int whichcallType;
//            QMap<QString,int>::iterator it; int count=0;
//            QString temp_msgInfoStr;

//            /****************提取到data中*********************/
//            /************************************************/
//            int CS_CMD;  //提取CS信号

//            if( g_mainWorkFlow->get_state_recvinfo()==true )  // receive info state g_mainWorkFlow->get_state_recvinfo()==true
//               {

//                if( ( bytes->at(data.count()-3)==Intalpha && bytes->at(data.count()-4)==Intalpha && bytes->at(data.count()-5)==Intalpha ) ||
//                        ( bytes->at(data.count()-3) == IntRQ && bytes->at(data.count()-4) == IntRQ && bytes->at(data.count()-5) == IntRQ ))      //结束信号3Alpha  或 重复信号3RQ
//                      { CS_CMD=bytes->at(data.count()-3); }
//                else if( bytes->at(data.count()-3)==Intbeta && bytes->at(data.count()-4)==Intbeta && bytes->at(data.count()-5)==Intbeta  )      //3beta
//                { CS_CMD=bytes->at(data.count()-3);  }                                                                                        //0x52+2beta
//                else if( bytes->at(data.count()-3)==Intbeta && bytes->at(data.count()-4)==Intbeta && bytes->at(data.count()-5)==g_mainWorkFlow->globalArray.mapSwitchLetterAndNum["toLetter"] )
//                   {  CS_CMD=bytes->at(data.count()-3); }
//                else
//                    {CS_CMD=300;  }
//               }
//            else
//                CS_CMD=bytes->at(data.count()-3);           // 建连 state

//            QString receivedInfo;
//            qDebug()<<"CS_CMD:"<<CS_CMD;

//            switch(CS_CMD)
//            {
//            case IntCS1:
//                    receivedInfo=CS1;
//                break;
//            case IntCS2:
//                    receivedInfo=CS2;
//                break;
//            case IntCS3:
//                    receivedInfo=CS3;
//                break;
//            case IntCS4:
//                    {  receivedInfo=CS4; qDebug()<<"Receive CS4 !!!!!!!";}
//                break;
//            case IntCS5:
//                    receivedInfo=CS5;
//                break;
//            case Intbeta:
//                    receivedInfo=beta;
//                    if(data.count()>=5)
//                    {
//                    if(bytes->at(data.count()-3)==Intbeta && bytes->at(data.count()-4)==Intalpha && bytes->at(data.count()-5)==Intbeta )   //lian xu betaAlphaBeta
//                        receivedInfo=betaAlphaBeta;
//                    else if(bytes->at(data.count()-3)==Intbeta && bytes->at(data.count()-4)==Intbeta && bytes->at(data.count()-5)==Intbeta )   //接受位置 收到3beta
//                        receivedInfo="ID:3beta;";
//                    else if(bytes->at(data.count()-3)==Intbeta && bytes->at(data.count()-4)==Intbeta && bytes->at(data.count()-5)==g_mainWorkFlow->globalArray.mapSwitchLetterAndNum["toLetter"] )   //接受0x52+2beta
//                        receivedInfo="ID:3beta;";
//                    }
//                break;
//            case Intalpha:
//                    receivedInfo=alpha;
//                    if(data.count()>=5)
//                    {
//                    if(bytes->at(data.count()-3)==Intalpha && bytes->at(data.count()-4)==Intalpha && bytes->at(data.count()-5)==Intalpha)   //lian xu 3 ge shi alpha
//                        receivedInfo=alphaAlphaAlpha;
//                    }
//                break;
//            case IntRQ:
//                    receivedInfo=RQ;
//                    if(data.count()>=5)
//                    {
//                    if(bytes->at(data.count()-3)==IntRQ && bytes->at(data.count()-4)==IntRQ  && bytes->at(data.count()-5)==IntRQ)  //lian xu 3 ge shi RQ
//                        receivedInfo=RQ_RQ_RQ;
//                    }
//                break;
//            case 300:  //信息提取，并通知UI层显示
//            {
//                msgInfo=data.mid(data.count()-5,data.count()-10);  //总共13个，其中3个是信息字节
//                whichcallType = 0;
//                whichcallType = data.mid(data.count()-6,1).at(0);                 //通信方式，1 ARQ ，2BFEC 3SFEC
//                int isZhuanYi=0; temp_msgInfoStr.clear();

//                qDebug()<<"info:"<<msgInfo.toHex();

//                for(int i=0;i<msgInfo.count();++i)
//               {
//                    if( msgInfo.at(i)==0x00 || msgInfo.at(i)==Intbeta )
//                        continue;

//                    if(msgInfo.at(i)==g_mainWorkFlow->globalArray.mapSwitchLetterAndNum["toLetter"])
//                     { g_mainWorkFlow->isLetterState_receive=true;isZhuanYi=1; count+=1; continue;}
//                    else if(msgInfo.at(i)==g_mainWorkFlow->globalArray.mapSwitchLetterAndNum["toNum"])
//                    {  g_mainWorkFlow->isLetterState_receive=false; isZhuanYi=1;count+=1;continue;}

//                    count=0;
//                    for(it=g_mainWorkFlow->globalArray.mapLetterToNum.begin();it!=g_mainWorkFlow->globalArray.mapLetterToNum.end();++it)
//                    {
//                        if( it.value()==msgInfo.at(i) )  count++;

//                        if(  g_mainWorkFlow->isLetterState_receive ==true && count==2 )
//                            { temp_msgInfoStr.append( it.key() ); isHuanHang=0; break;}
//                        else if( g_mainWorkFlow->isLetterState_receive ==false && count==1 )
//                             { temp_msgInfoStr.append( it.key() ); isHuanHang=0; break;}
//                    }
//                    if(data.at(data.count()-5)==g_mainWorkFlow->globalArray.mapSwitchLetterAndNum["huiChe"])
//                    {
//                        if(isHuanHang==0)
//                         { msgInfoStr.clear();   qDebug()<<"clear";} //msgInfoStr.append("\n");

//                            isZhuanYi=1;
//                        isHuanHang=1; count +=1;
//                    }else if(data.at(data.count()-5)==g_mainWorkFlow->globalArray.mapSwitchLetterAndNum["huanHang"])
//                    {
//                        if(isHuanHang==0)
//                         { msgInfoStr.clear();   qDebug()<<"clear";}    //msgInfoStr.append("\n");

//                            isZhuanYi=1;
//                         isHuanHang=1;  count +=1;
//                    }
//                     else if(count==0)   // if map haven't,then use -1 instead.
//                     { temp_msgInfoStr.clear(); /*msgInfoStr.append( "*" );*/ qDebug()<< (int)data.at(8); break;}

//                    qDebug()<<"temp_msgInfoStr"<<temp_msgInfoStr;
//                }
//                msgInfoStr.append(temp_msgInfoStr);
//                qDebug()<<"msgInfoStr"<<msgInfoStr;

//                if(count==0)                                                  //if one ont adjust 4b3y
//                    receivedInfo.clear();
//                else
//                    receivedInfo=(QString("ID:")+msgInfoStr+(QString(";")));  // add ID easy to recongnize

//            }
//                break;
//            default:  //   呼叫 和 识别流程
//                qDebug()<<"call or recongnise work flow";
//                if(g_mainWorkFlow->isCallRadio==1 && g_mainWorkFlow->get_call_or_recg_state()==2 && data.count()==13)//识别过程，len=13 提取对应1个字节,接受ck1，2，3
//                    {
//                   msgInfo=data.mid(8,data.count()-10);
//                   msgInfoStr.clear();
//                   for(int i=0;i<msgInfo.count();++i)
//                   {
//                       if( msgInfo.at(i) == 0x00 )
//                          continue;
//                       count=0;
//                       for(it=g_mainWorkFlow->globalArray.mapLetterToNum.begin();it!=g_mainWorkFlow->globalArray.mapLetterToNum.end();++it)
//                       {
//                           if( it.value()==msgInfo.at(i) )  count++;

//                           if(count==2 )
//                           {msgInfoStr.append( it.key() );break;}
//                       }

//                   }
//                   receivedInfo=msgInfoStr;   qDebug()<<"receive IS:"<<msgInfoStr;
//                 }else if(g_mainWorkFlow->isCallRadio==0 && g_mainWorkFlow->get_call_or_recg_state()==1 && data.count()==13)  //被呼叫台 ,接受呼1，2，3
//                 {
//                     msgInfo=data.mid(8,data.count()-10);
//                     msgInfoStr.clear();
//                     for(int i=0;i<msgInfo.count();++i)
//                     {
//                      if( msgInfo.at(i)==IntRQ   )
//                       { msgInfoStr.append("RQ");continue;}

//                      count=0;
//                      for(it=g_mainWorkFlow->globalArray.mapLetterToNum.begin();it!=g_mainWorkFlow->globalArray.mapLetterToNum.end();++it)
//                      {
//                          if( it.value()==msgInfo.at(i) )  count++;

//                          if(count==2 )
//                             { msgInfoStr.append( it.key() );break;}
//                      }

//                     }
//                      receivedInfo=msgInfoStr;  qDebug()<<"receive call code:"<<msgInfoStr;
//                 }
//                 else if(g_mainWorkFlow->isCallRadio==0 && g_mainWorkFlow->get_call_or_recg_state()==2 && data.count()==13)   //被呼叫过程 ,识别码
//                 {
//                     msgInfo=data.mid(8,data.count()-10);
//                     msgInfoStr.clear();
//                     for(int i=0;i<msgInfo.count();++i)
//                     {
//                      if( msgInfo.at(i)==Intalpha   )
//                      { msgInfoStr.append(alpha);continue;}

//                          count=0;
//                          for(it=g_mainWorkFlow->globalArray.mapLetterToNum.begin();it!=g_mainWorkFlow->globalArray.mapLetterToNum.end();++it)
//                          {
//                              if( it.value()==msgInfo.at(i) )  count++;
//                              if(count==2 )
//                                 { msgInfoStr.append( it.key() );break;}
//                          }
//                     }
//                      receivedInfo=msgInfoStr; qDebug()<<"receive recongnise code:"<<msgInfoStr;
//                 }
//                msgInfoStr.clear();  //使用完，进入通信前清零，进入通信后，不走此分支了 收到还行时候清零
//                break;
//            }

//            /*************************************通知状态变量****************************/

//            QString strCallType=CallClass::get()->getCallInfo()->getCallType();
//            if( CallClass::get()->getIsCall() == true && strCallType.compare("ARQ")==0)  // call Radio
//               {

//                if( g_mainWorkFlow->isFourMMSI==0)
//                    { qDebug()<<"00";g_mainWorkFlow->callRadio_flow(receivedInfo);   }           //主台呼叫的是9位码
//                else
//                    {  qDebug()<<"01";g_mainWorkFlow->callRadio_flow_fourMMSI(receivedInfo); }   //主台呼叫的是4位码
//               }
//            else if( CallClass::get()->getIsCall() == false && strCallType.compare("ARQ")==0)             // called Radio
//               {
//                qDebug()<<"02";
//                g_mainWorkFlow->calledRadio_flow(receivedInfo);                                   //副台接受流程
//               }

//            /*****************************通知完流程变量，再通知UI************************/

//            if( temp_msgInfoStr.size() > 0 && CS_CMD == 300 )                                     // 转义，回车换行都为空，误码为空
//               {
//                Transit::get()->EmitSignalTalkReceive(msgInfoStr); temp_msgInfoStr.clear();       //通知UI显示数据，同时左上角显示通信状态

//                if(whichcallType==1)
//                    Transit::get()->EmitSignalState("ARQ Connected");
//                else
//                    Transit::get()->EmitSignalState("Incoming FEC");
//                if( CallClass::get()->getCallInfo()->getCallType().compare("ARQ") ==0 )
//                    msgInfoStr.clear();
//               }



//}

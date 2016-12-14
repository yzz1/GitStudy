#include "control.h"
#include <QDebug>
#include <QChar>
#include "../src/models/contactsmodel.h"
#include "../src/views//common/constants.h"
#include "../src/core/utils/sqlitehelper.h"
#include <QtSql/QSqlRecord>
#include "logging.h"
#include "../myCom/UIDefineInsStruct.h"

Control* Control::m_pInstance = 0;

/****************************************************************************
**
** Control::~Control
** 功能概述: 析构函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
Control::~Control()
{
    m_pInstance = 0;
}

/****************************************************************************
**
** Control::~Control
** 功能概述: 取得单实例
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/

Control* Control::get()
{
    if (0 == m_pInstance)
    {
        m_pInstance = new Control();
    }

    return m_pInstance;
}

/****************************************************************************
**
** Control::~Control
** 功能概述: 构造函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
Control::Control()
{
    connect(Transit::get(), SIGNAL(SignalCallSetup(CallClass*)), this, SLOT(SlotCallSetup(CallClass*)));
    connect(Transit::get(), SIGNAL(SignalConnectingCancel()), this, SLOT(SlotConnectingCancel()));
    connect(Transit::get(), SIGNAL(SignalTalkSend(QString, QString)), this, SLOT(SlotTalkSend(QString, QString)),Qt::DirectConnection);
    connect(Transit::get(), SIGNAL(SignalInterupt()), this, SLOT(SlotInterupt()));
    connect(Transit::get(), SIGNAL(SignalScan(ScanClass*)), this, SLOT(SlotScan(ScanClass*)));
    connect(Transit::get(), SIGNAL(SignalCheck()), this, SLOT(SlotCheck()));
    connect(Transit::get(), SIGNAL(SignalMarkTrans()), this, SLOT(SlotMarkTrans()));
    connect(Transit::get(), SIGNAL(SignalSpaceTrans()), this, SLOT(SlotSpaceTrans()));
    connect(Transit::get(), SIGNAL(SignalDotTrans()), this, SLOT(SlotDotTrans()));
    connect(Transit::get(), SIGNAL(SignalSlaveDelay(int)), this, SLOT(SlotSlaveDelay(int)));
    connect(Transit::get(), SIGNAL(SignalRadioConnectAsk()), this, SLOT(SlotRadioConnectAsk()));


    sendScanFreqTimer=new QTimer();
    connect(sendScanFreqTimer,SIGNAL(timeout()),this,SLOT(SlotSendScanFreq()));  //yzz
    connect(Transit::get(),SIGNAL(SignalKillSendScanFreqTimer()),this,SLOT(SlotKillSendScanFreqTimer()));

    sendStrMsgTimer = new QTimer();
    connect(sendStrMsgTimer,SIGNAL(timeout()),this,SLOT(SlotSendStrMsgTimer()),Qt::DirectConnection);
    sendStrMsg_count=0;

    g_mSerial= new UISerial;
    g_nbdpWorkFlow=new nbdpWorkflow(&(g_mSerial->m_Filter1));
    g_mainWorkFlow= new MainWindow(g_mSerial);
    //  g_mainWorkFlow->show();


    connect(g_mainWorkFlow,SIGNAL(signal_sendNbdp_mesg(QString,QString)),this,SLOT(SlotTalkAndCSSend(QString, QString)),Qt::DirectConnection);
    connect(g_mainWorkFlow,SIGNAL(signal_workFlow_readyAndIdle()),this,SLOT(SLot_workFlow_readyAndIdle()));
    connect(Transit::get(),SIGNAL(SignalTurningResult(bool)),this,SLOT(SlotBS_FECStartLink(bool)));
    connect(Transit::get(),SIGNAL(SignalCalledReceive(int)),this,SLOT(SlotCalledReceive(int)));
    connect(Transit::get(),SIGNAL(reflashDeviceInfo(QString,QString,QString)),this,SLOT(SlotReflashDeviceInfo(QString,QString,QString)));
}
void Control::sendNBDP_StateFlag(unsigned char  SwitchFlag)
{
    type_NBDP_StateFlag ChangeIns;
     ChangeIns.s_FrameHeader=FRAME_HEADER;
    short int nLength=sizeof( ChangeIns)-4;

     ChangeIns.s_FrameLength=be16toh(nLength);
     ChangeIns.s_SourceDeviceID=INS_DEVICEID_NBDP;
     ChangeIns.s_TargetDeviceID=INS_DEVICEID_NBDP;

     ChangeIns.s_InsCode=INS_CODE_NBDP_StateFlag;
     ChangeIns.StateFlag = SwitchFlag;
     ChangeIns.s_VerifyValue = 0;


     QByteArray bytes;
     bytes.append((char*)(&ChangeIns),sizeof(type_NBDP_StateFlag));

     //计算校验值
     short int nVerifyValue= g_mSerial->GetVerifyValue(bytes.mid(2,bytes.count()-2));
     short int nVerifyValue1=be16toh(nVerifyValue);
     bytes.remove(bytes.count()-2,2);
     bytes.append((char*)&nVerifyValue1,sizeof(nVerifyValue1));


     //写入串口
     g_mSerial->m_serial1->write(bytes.data(),bytes.length());
     qDebug()<<"Send_NBDPState_Ins="+bytes.toHex();

}
void Control::SlotCalledReceive(int calledType)
{
    type_NBDP_CalledReceiveInstruction calledReceiveIns;
    calledReceiveIns.s_FrameHeader=FRAME_HEADER;
    short int nLength=sizeof(type_NBDP_CalledReceiveInstruction)-4;

    calledReceiveIns.s_FrameLength=be16toh(nLength);
    calledReceiveIns.s_SourceDeviceID=INS_DEVICEID_NBDP;
    calledReceiveIns.s_TargetDeviceID=INS_DEVICEID_DSP;

    calledReceiveIns.s_InsCode=INS_CODE_NBDP_CalledReceive;
    if(calledType==1)
        calledReceiveIns.s_MODE=0x01;
    else if(calledType==2)
        calledReceiveIns.s_MODE=0x02;

    unsigned int nTx=0;                //对方不判断
    calledReceiveIns.s_TX=be32toh(nTx);
    unsigned int nRx=0;
    calledReceiveIns.s_RX=be32toh(nRx);

    calledReceiveIns.s_VerifyValue=0x00;
    g_mSerial->Send_NBDP_CalledReceiveIns(&calledReceiveIns);

}
void Control::SLot_workFlow_readyAndIdle() //workFLow 状态变量控制串口接受，UI进入Idle
{
    g_mainWorkFlow->workFlowState=1;
    Transit::get()->EmitSignalLineEditState(true);  //发送结束，使能光标
    Transit::get()->EmitSignalState("Idle");
}

void Control::SlotTalkAndCSSend(QString strNo, QString strMsg)
{
    if(strNo.compare("1")==0)  // send cs signal one char,P E D
    {sendCSOneChar(strMsg);}
    else if(strNo.compare("3")==0) //send cs signal three char
    {sendCSThreeChar(strMsg);}
    else if( CallClass::get()->getCallInfo()->getCallType().compare("ARQ")!=0)           //FEC发送信息  （ "0",sendInfo ）,数据早已经保存在sendData中，由SlotSendStrMsgTimer()发送。
    {
        sendStrMsg_count=0;
        SlotSendStrMsgTimer();          //计时器开启，间隔不定长时间发送数据
    }
}
void Control::SlotSendStrMsgTimer()
{
    QByteArray strMsgTemp = g_mainWorkFlow->sendData;
    QByteArray  childMsg;

    int i=sendStrMsg_count;

    if( sendStrMsgTimer->isActive() == true )
        sendStrMsgTimer->stop();


    if( i < (strMsgTemp.size()-1)/50+1  )   //发送多少帧
    {
        if( strMsgTemp.size()-(i*50) >= 50 )
             childMsg=strMsgTemp.mid( (i*50),50 );
        else
             childMsg=strMsgTemp.mid( (i*50),strMsgTemp.size()-(i*50) );

        sendInfoMessage(childMsg);                          //只是发送
        sendStrMsg_count++;
        sendStrMsgTimer->start( 140*childMsg.size() );

        qDebug()<<"sendStrMsgCount:"<<sendStrMsg_count;

    }else                  //fec关闭
    {
        sendStrMsgTimer->stop();  g_mainWorkFlow->sendInfo.clear();
        Transit::get()->EmitSignalLineEditState(true);  //FEC 计时结束，打开光标
     }

}
/************************************************************
  yzz
  BS FEC Turn success ,and start link
  **************************************************************/
void Control::SlotBS_FECStartLink(bool b)
{
    QString strCallType=CallClass::get()->getCallInfo()->getCallType();
    bool isCallOrReceive=g_mainWorkFlow->isCallRadio ;

    // 调谐成功后，FEC模式主叫发起的建连（被叫处于等待建连）
    if(b == true && isCallOrReceive==1 && ( strCallType.compare("BFEC")==0 || strCallType.compare("SFEC")==0 ))
    {

               type_NBDP_FECStartLinkInstruction fecStartLinkIns;
                fecStartLinkIns.s_FrameHeader=FRAME_HEADER;
                short int nLength=sizeof(type_NBDP_FECStartLinkInstruction)-4;

                 fecStartLinkIns.s_FrameLength=be16toh(nLength);
                 fecStartLinkIns.s_SourceDeviceID=INS_DEVICEID_NBDP;
                 fecStartLinkIns.s_TargetDeviceID=INS_DEVICEID_ARM;
                 fecStartLinkIns.s_InsCode=INS_CODE_NBDP_FECStartLink;

                 fecStartLinkIns.linkState=0x00;

                  fecStartLinkIns.s_VerifyValue=0x00;
                  g_mSerial->Send_NBDP_StartFecLinkIns(&fecStartLinkIns);
    }

}
/****************************************************************************
**
** Control::SlotCallSetup
** 功能概述: UI层呼叫信号处理槽
** 参数说明: CallClass* cc 呼叫信息
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Control::SlotCallSetup(CallClass* cc)
{
    QString strTmp;
    Logging::get()->debug("S*****SlotCallSetup*****S");
    Logging::get()->debug("CallName:");
    Logging::get()->debug(cc->getCallInfo()->getCallName());
    Logging::get()->debug("CallCode:");
    Logging::get()->debug(cc->getCallInfo()->getCallCode());
    Logging::get()->debug("CallChannel:");
    Logging::get()->debug(cc->getCallInfo()->getCallChannel());
    Logging::get()->debug("CallTx:");
    Logging::get()->debug(cc->getCallInfo()->getCallTx());
    Logging::get()->debug("CallRx:");
    Logging::get()->debug(cc->getCallInfo()->getCallRx());
    Logging::get()->debug("CallType:");
    Logging::get()->debug(cc->getCallInfo()->getCallType());
    Logging::get()->debug("IsCall:");
    strTmp = cc->getIsCall();
    Logging::get()->debug(strTmp);
    Logging::get()->debug("E*****SlotCallSetup*****E");



    g_mainWorkFlow->MainTimerCount=0; g_mainWorkFlow->ReceTimerCount = 0;
    g_mainWorkFlow->strSelfMMSI=g_selfMMSI;  qDebug()<<g_selfMMSI;
    g_mainWorkFlow->strOtherMMSI=cc->getCallInfo()->getCallCode();


    g_mainWorkFlow->calc_IS_IK(g_mainWorkFlow->strSelfMMSI,g_mainWorkFlow->strOtherMMSI);
    g_mainWorkFlow->Var_init();                 //初始化所有重复使用的变量

    type_NBDP_ConnectInstruction connectIns;

    //内容固定为0X7E7E 2 字节
    connectIns.s_FrameHeader=FRAME_HEADER;
    short int nLength=sizeof(type_NBDP_ConnectInstruction)-4;
    connectIns.s_FrameLength=be16toh(nLength);
    connectIns.s_SourceDeviceID=INS_DEVICEID_NBDP;
    connectIns.s_TargetDeviceID=INS_DEVICEID_ARM;
    // 指令代码
    connectIns.s_InsCode=INS_CODE_NBDP_Turn;



    if( CallClass::get()->getIsCall() == false )            //01,02,03,04; (ARQ,BFEC,SFEC),RECEIVE
         { connectIns.s_MODE= INS_NBDP_MODE_SCAN;  g_mainWorkFlow->isCallRadio = 0; }
    else if(QString(cc->getCallInfo()->getCallType()).compare("ARQ")==0)
        connectIns.s_MODE= INS_NBDP_MODE_ARQ;
    else if(QString(cc->getCallInfo()->getCallType()).compare("BFEC")==0)
        connectIns.s_MODE= INS_NBDP_MODE_BFEC;
    else
        connectIns.s_MODE= INS_NBDP_MODE_SFEC;

    //精确到1Hz高字节在前低字节在后
    //unsigned int nTx=(unsigned int)(m_GlobalParas->s_ActiveChannel.s_TX*1000);
    bool ok;

    unsigned int nTx=(unsigned int)((cc->getCallInfo()->getCallTx()).toDouble(&ok)*1000);
    connectIns.s_TX=be32toh(nTx);
    unsigned int nRx=(unsigned int)((cc->getCallInfo()->getCallRx()).toDouble(&ok)*1000);
    connectIns.s_RX=be32toh(nRx);


    //填充
     long numCalledMMSI= g_mainWorkFlow->strOtherMMSI.toLong(); QByteArray calledMMSIAry;
     while(numCalledMMSI > 0)
    {
        calledMMSIAry.prepend( numCalledMMSI % (256) );
        numCalledMMSI = numCalledMMSI /(256);
    }

    if(g_mainWorkFlow->isCallRadio==1 && g_mainWorkFlow->list_IS.size()==4)
    {
        connectIns.s_CallCode[0]=(g_mainWorkFlow->strOtherMMSI).size();        //4位呼叫码

        for(int i=0;i<7;++i)
         {
            if( i <=4 )   connectIns.s_CallCode[i+1]=0x00;
            else  connectIns.s_CallCode[i+1] = calledMMSIAry.at(i-5);
        }
    }
    else if(g_mainWorkFlow->isCallRadio==1 && g_mainWorkFlow->list_IS.size()==7)
         {
        connectIns.s_CallCode[0]=0x07;         //7位呼叫码

        for(int i=0;i<7;++i)
           {
            if( i<=2 ) connectIns.s_CallCode[i+1]= 0x00;
            else   connectIns.s_CallCode[i+1] = calledMMSIAry.at(i-3);
           }
         }
    else
         {         
          for(int i=0;i<8;++i)
              connectIns.s_CallCode[i]=0x00;
           connectIns.s_CallCode[0]=(g_mainWorkFlow->strOtherMMSI).size();      //BFEC 无呼叫码
         }

    connectIns.s_TunePara.s_TuneProcess=INS_NBDP_TUNEPROCESS_Start;
    connectIns.s_TunePara.s_TuneResult=INS_NBDP_TUNERESULT_Failure;
    connectIns.s_TunePara.s_TuneStyle=0x01;  // 0,1; auto,manual


    //调谐参数预留位为0
    connectIns.s_TunePara.s_Reserve=0x00;
    connectIns.s_TunePara.s_Reserve1=0x00;

    //tuneIns.s_Paras.s_Reserve2=0x08;

    connectIns.s_VerifyValue=0x00;
    g_mSerial->Send_NBDP_ConnectIns(&connectIns);

}

/****************************************************************************
**
** Control::SlotConnectingCancel
** 功能概述: UI层连接取消信号处理槽
** 参数说明: 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Control::SlotConnectingCancel()
{
    Logging::get()->debug("*****SlotConnectingCancel*****");

    type_NBDP_DisconnectInstruction disConnectIns;
    disConnectIns.s_FrameHeader=FRAME_HEADER;
    short int nLength=sizeof(type_NBDP_DisconnectInstruction)-4;

    disConnectIns.s_FrameLength=be16toh(nLength);
    disConnectIns.s_SourceDeviceID=INS_DEVICEID_NBDP;
    disConnectIns.s_TargetDeviceID=INS_DEVICEID_ARM;

    disConnectIns.s_InsCode=INS_CODE_NBDP_Disconnect;
    disConnectIns.s_VerifyValue=0x00;
    g_mSerial->Send_NBDP_DisconnectIns(&disConnectIns);
    g_mainWorkFlow->callRadio_changetoReady();
}

/****************************************************************************
**
** Control::SlotTalkSend
** 功能概述: UI层通话下发信号处理槽
** 参数说明: QString strNo 消息ID
             QString strMsg 消息内容
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Control::SlotTalkSend(QString strNo, QString strMsg)
{
    Logging::get()->debug("S*****SlotTalkSend*****S");
    m_strNo = strNo;
    Logging::get()->debug("strNo:");
    Logging::get()->debug(strNo);
    Logging::get()->debug("strMsg:");
    Logging::get()->debug(strMsg);
    Logging::get()->debug("E*****SlotTalkSend*****E");


    g_mainWorkFlow->on_buttonSendToSerial_clicked(strNo,strMsg);

}

/****************************************************************************
**
** Control::SlotInterupt
** 功能概述: UI层ESC中断信号处理槽
** 参数说明: 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Control::SlotInterupt()
{
    Logging::get()->debug("*****SlotInterupt*****");


    //yzz ,ui 强制中断
    type_NBDP_DisconnectInstruction disConnectIns;
    disConnectIns.s_FrameHeader=FRAME_HEADER;
    short int nLength=sizeof(type_NBDP_DisconnectInstruction)-4;

     disConnectIns.s_FrameLength=be16toh(nLength);
     disConnectIns.s_SourceDeviceID=INS_DEVICEID_NBDP;
     disConnectIns.s_TargetDeviceID=INS_DEVICEID_ARM;

     disConnectIns.s_InsCode=INS_CODE_NBDP_Disconnect;
     disConnectIns.s_VerifyValue=0x00;

     sendNBDP_StateFlag( STATUS_CODE_NBDP_COMMEND );        //告诉 nbdp 断开状态
     g_mSerial->Send_NBDP_DisconnectIns(&disConnectIns);    //告诉 电台 断开通信
     g_mainWorkFlow->callRadio_changetoReady();


     Transit::get()->EmitSignalState("Idle");
     g_mainWorkFlow->workFlowState=1;
     g_nbdpWorkFlow->isHuanHang=1;
     g_nbdpWorkFlow->msgInfoStr.clear();

     qDebug()<<"interupt";
}

/****************************************************************************
**
** Control::SlotScan
** 功能概述: UI层扫描信号处理槽
** 参数说明: ScanClass* sc 扫描信息
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Control::SlotScan(ScanClass* sc)
{
    g_mainWorkFlow->isCallRadio=0;      //发起扫描是副台，因此调谐成功后不需要发送呼叫码，直接进入接受状态
   // g_mainWorkFlow->workFlowState=4;
    CallClass::get()->setIsScan(true); //设置为扫描状态
    Transit::get()->EmitSignalState("Scanning");

    QString strTmp;
    Logging::get()->debug("ScanGroup:");
    strTmp = sc->getScanGroup();
    Logging::get()->debug(strTmp);
    Logging::get()->debug("IsScan:");
    strTmp = sc->getIsScan();
    Logging::get()->debug(strTmp);
    Logging::get()->debug("DwellTime:");
    strTmp = sc->getDwellTime();
    Logging::get()->debug(strTmp);
    Logging::get()->debug("ScanMode:");
    strTmp = sc->getScanMode();
    Logging::get()->debug(strTmp);
    QList<ChannelInfoClass>* lstTmp = sc->getChannelInfoList();
    ChannelInfoClass cic;

    for (int i = 0; i < lstTmp->count(); i++)
    {
        strTmp = "ChannelInfo ";
        strTmp.append(i + 1);
        strTmp.append(":");
        Logging::get()->debug(strTmp);
        Logging::get()->debug("Tx:");
        cic = lstTmp->at(i);
        Logging::get()->debug(cic.getTx());
        Logging::get()->debug("Rx:");
        Logging::get()->debug(cic.getRx());
    }

    Logging::get()->debug("E*****SlotScan*****E");


    sendScanFreqTimer->start(3000);
    m_sc=sc;
    sendScanFreqTimer_count=0;

}
void Control::SlotKillSendScanFreqTimer()
{
    sendScanFreqTimer->stop();     
    g_mainWorkFlow->workFlowState=1;    //由扫描状态4，改为状态1


}
void Control::SlotSendScanFreq()
{
    sendScanFreqTimer_count+=1;
    QList<ChannelInfoClass>* lstTmp = m_sc->getChannelInfoList();
    if( sendScanFreqTimer_count > lstTmp->count() )
       {
        //sendScanFreqTimer->stop();
         sendScanFreqTimer_count=1;
        }

    ChannelInfoClass cic;
    QString strTmp;
    cic = lstTmp->at(sendScanFreqTimer_count-1);
    QString RX=cic.getRx() ;
    QString TX=cic.getTx() ;

/**************************5********************/

//    type_NBDP_ScanInstruction scanIns;
//    scanIns.s_FrameHeader=FRAME_HEADER;
//    short int nLength=sizeof(type_NBDP_ScanInstruction)-4;

//    scanIns.s_FrameLength=be16toh(nLength);
//    scanIns.s_SourceDeviceID=INS_DEVICEID_NBDP;
//    scanIns.s_TargetDeviceID=INS_DEVICEID_ARM;

//    scanIns.s_InsCode=INS_CODE_NBDP_Scan;

//    strTmp=m_sc->getScanMode();
//    if(strTmp.compare("ARQ")==0)
//         scanIns.s_MODE= INS_NBDP_MODE_ARQ;   //01,02,03; ARQ,FEC,AUTO
//    else if(strTmp.compare("FEC")==0)
//         scanIns.s_MODE=0x02;
//    else if(strTmp.compare("AUTO")==0)
//         scanIns.s_MODE=0x03;


//    //精确到1Hz高字节在前低字节在后

//      unsigned int nTx=(unsigned int)(TX.toDouble()*1000);
//      scanIns.s_TX=be32toh(nTx);
//      unsigned int nRx=(unsigned int)(RX.toDouble()*1000);
//      scanIns.s_RX=be32toh(nRx);
//      scanIns.s_ScanStatus=INS_NBDP_SCANPROCESS_Start;  //0x01 start 0x02 stop

//      scanIns.s_VerifyValue=0x00;
//      g_mSerial->Send_NBDP_ScanIns(&scanIns);

    /*******************************scan please*******************/

    type_NBDP_ConnectInstruction connectIns;

    //内容固定为0X7E7E 2 字节
    connectIns.s_FrameHeader=FRAME_HEADER;
    short int nLength=sizeof(type_NBDP_ConnectInstruction)-4;
    connectIns.s_FrameLength=be16toh(nLength);
    connectIns.s_SourceDeviceID=INS_DEVICEID_NBDP;
    connectIns.s_TargetDeviceID=INS_DEVICEID_ARM;
    // 指令代码
    connectIns.s_InsCode=INS_CODE_NBDP_Turn;

   CallInfoClass callInfo;


    //01,02,03,04; (ARQ,BFEC,SFEC),RECEIVE
    if( m_sc->getScanMode().compare("ARQ") == 0)
       { connectIns.s_MODE= INS_NBDP_MODE_ARQ; callInfo.setCallType("ARQ");}
    else
       { connectIns.s_MODE= INS_NBDP_MODE_SCAN;  callInfo.setCallType("AUTO");}
   /***************XIA FA QIAN JI ZHU,YI BIAN JIESHOU SCAN RESULT YONG**********/

    CallClass::get()->setCallInfo(&callInfo);
   CallClass::get()->getCallInfo()->setCallTx(TX);
    CallClass::get()->getCallInfo()->setCallRx(RX);
     g_mainWorkFlow->isCallRadio = 0;


    //精确到1Hz高字节在前低字节在后

    bool ok;

    unsigned int nTx=(unsigned int)(TX.toDouble(&ok)*1000);
    connectIns.s_TX=be32toh(nTx);
    unsigned int nRx=(unsigned int)(RX.toDouble(&ok)*1000);
    connectIns.s_RX=be32toh(nRx);


    //填充 无呼叫码

         {
          for(int i=0;i<8;++i)
              connectIns.s_CallCode[i]=0x00;
           connectIns.s_CallCode[0]=0x00;
         }

    connectIns.s_TunePara.s_TuneProcess=INS_NBDP_TUNEPROCESS_Stop;   //stop turn
    connectIns.s_TunePara.s_TuneResult=INS_NBDP_TUNERESULT_Failure;
    connectIns.s_TunePara.s_TuneStyle=0x01;  // 0,1; auto,manual


    //调谐参数预留位为0
    connectIns.s_TunePara.s_Reserve=0x00;
    connectIns.s_TunePara.s_Reserve1=0x00;

    //tuneIns.s_Paras.s_Reserve2=0x08;

    connectIns.s_VerifyValue=0x00;
    g_mSerial->Send_NBDP_ConnectIns(&connectIns);
}
/****************************************************************************
**
** Control::SlotCheck
** 功能概述: UI层系统自检信号处理槽
** 参数说明:
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Control::SlotCheck()
{
    Logging::get()->debug("*****SlotCheck*****");

    type_NBDP_SelfCheckInstruction selfCheckIns;
    selfCheckIns.s_FrameHeader=FRAME_HEADER;
    short int nLength=sizeof(type_NBDP_SelfCheckInstruction)-4;

     selfCheckIns.s_FrameLength=be16toh(nLength);
     selfCheckIns.s_SourceDeviceID=INS_DEVICEID_NBDP;
     selfCheckIns.s_TargetDeviceID=INS_DEVICEID_ARM;
     selfCheckIns.s_InsCode=INS_CODE_NBDP_SelfCheck;

     selfCheckIns.Transmit=0x00;  //0x00,false,0x01,right
     selfCheckIns.Receive=0X00;   //0x00,false,0x01,right

      selfCheckIns.s_VerifyValue=0x00;
      g_mSerial->Send_NBDP_SelfCheckIns(&selfCheckIns);
}

/****************************************************************************
**
** Control::SlotMarkTrans
** 功能概述: UI层Mark传递信号处理槽
** 参数说明:
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Control::SlotMarkTrans()
{
    Logging::get()->debug("*****SlotMarkTrans*****");

            type_NBDP_TransmitTestInstruction markTransIns;
            markTransIns.s_FrameHeader=FRAME_HEADER;
            short int nLength=sizeof(type_NBDP_TransmitTestInstruction)-4;

             markTransIns.s_FrameLength=be16toh(nLength);
             markTransIns.s_SourceDeviceID=INS_DEVICEID_NBDP;
             markTransIns.s_TargetDeviceID=INS_DEVICEID_ARM;
             markTransIns.s_InsCode=INS_CODE_NBDP_TransmitTest;
             /*************5 ******************/

             markTransIns.s_SendDataType.s_Reserve=0x00;
             markTransIns.s_SendDataType.s_DataType=0x20;    //0x00,space; 0x20,mark;0x40,dot;0x60,serial


              /*************+1******************/
              markTransIns.s_VerifyValue=0x00;
              g_mSerial->Send_NBDP_TransmitTestIns(&markTransIns);
}

/****************************************************************************
**
** Control::SlotSpaceTrans
** 功能概述: UI层Space传递信号处理槽
** 参数说明:
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Control::SlotSpaceTrans()
{
    Logging::get()->debug("*****SlotSpaceTrans*****");

    type_NBDP_TransmitTestInstruction SpaceTransIns;
    SpaceTransIns.s_FrameHeader=FRAME_HEADER;
    short int nLength=sizeof(type_NBDP_TransmitTestInstruction)-4;

     SpaceTransIns.s_FrameLength=be16toh(nLength);
     SpaceTransIns.s_SourceDeviceID=INS_DEVICEID_NBDP;
     SpaceTransIns.s_TargetDeviceID=INS_DEVICEID_ARM;
     SpaceTransIns.s_InsCode=INS_CODE_NBDP_TransmitTest;
     /*************5 ******************/

     SpaceTransIns.s_SendDataType.s_Reserve=0x00;
     SpaceTransIns.s_SendDataType.s_DataType=0x00;   //0x00,space; 0x20,mark;0x40,dot;0x60,serial


      /*************+1******************/
      SpaceTransIns.s_VerifyValue=0x00;
      g_mSerial->Send_NBDP_TransmitTestIns(&SpaceTransIns);
}

/****************************************************************************
**
** Control::SlotDotTrans
** 功能概述: UI层Dot传递信号处理槽
** 参数说明:
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Control::SlotDotTrans()
{
    Logging::get()->debug("*****SlotDotTrans*****");


    type_NBDP_TransmitTestInstruction dotTransIns;
    dotTransIns.s_FrameHeader=FRAME_HEADER;
    short int nLength=sizeof(type_NBDP_TransmitTestInstruction)-4;

     dotTransIns.s_FrameLength=be16toh(nLength);
     dotTransIns.s_SourceDeviceID=INS_DEVICEID_NBDP;
     dotTransIns.s_TargetDeviceID=INS_DEVICEID_ARM;
     dotTransIns.s_InsCode=INS_CODE_NBDP_TransmitTest;
     /*************5 ******************/

     dotTransIns.s_SendDataType.s_Reserve=0x00;
     dotTransIns.s_SendDataType.s_DataType=0x40;   //0x00,space; 0x20,mark;0x40,dot;0x60,serial


      /*************+1******************/
      dotTransIns.s_VerifyValue=0x00;
      g_mSerial->Send_NBDP_TransmitTestIns(&dotTransIns);
}

/****************************************************************************
**
** Control::SlotSlaveDelay
** 功能概述: UI层SlaveDelay信号处理槽
** 参数说明:
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Control::SlotSlaveDelay(int i)
{
    QString strTmp;
    Logging::get()->debug("S*****SlotSlaveDelay*****S");
    Logging::get()->debug("Delay:");
    strTmp = QString::number(i);
    Logging::get()->debug(strTmp);
    Logging::get()->debug("E*****SlotSlaveDelay*****E");
}

/****************************************************************************
**
** Control::SlotRadioConnectAsk
** 功能概述: UI层电台连接确认信号处理槽
** 参数说明:
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Control::SlotRadioConnectAsk()
{
    Logging::get()->debug("*****SlotRadioConnectAsk*****");

    type_connectRadioInstruction connRadioIns;
    connRadioIns.s_FrameHeader=FRAME_HEADER;
    short int nLength=sizeof(type_connectRadioInstruction)-4;

     connRadioIns.s_FrameLength=be16toh(nLength);
     connRadioIns.s_SourceDeviceID=INS_DEVICEID_NBDP;
     connRadioIns.s_TargetDeviceID=INS_DEVICEID_ARM;
     connRadioIns.s_InsCode=INS_CODE_NBDP_connRadio;
     /*************5 ******************/

      /*************+1******************/
      connRadioIns.s_VerifyValue=0x00;
      g_mSerial->Send_NBDP_ConnRadioAskIns(&connRadioIns);

}

/****************************************************************************
**
** Control::KeyDownForTest
** 功能概述: 快捷键回调函数
** 参数说明: QString strMdf 组合键
             int intKc 键值
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Control::KeyDownForTest(QString strMdf, int intKc)
{
    QString strTmp;
    CallInfoClass* cic = new CallInfoClass();
    cic->setCallName("1Peter");
    cic->setCallCode("020222111");
    cic->setCallChannel("30202");
    cic->setCallTx("1020.2");
    cic->setCallRx("2020.3");
    cic->setCallType("BFEC");
    cic->setCallOrReceive("0");
    CheckDataClass* cdc1 = new CheckDataClass();
    cdc1->setTerminalCheck(true);
    cdc1->setReceiveCheck(true);
    cdc1->setTransmissionCheck(true);

    if (strMdf == "Ctrl")
    {
        switch (intKc)
        {
        case Qt::Key_M:
            Transit::get()->EmitSignalTalkSendConfirm(m_strNo, true);
            break;

        case Qt::Key_R:
        {
            strTmp = "Hello!";
           // g_mainWorkFlow->strRemapIntger("T");
            //Transit::get()->EmitSignalTalkReceive(strTmp);
            static const char mydata[] = {
                0x7e, 0x7e, 0x00, 0x09, 0x02, 0x01, 0xd0,
                0x01, 0x61, 0x62, 0x62, 0x02, 0x02
            };    //aba

            QByteArray data = QByteArray::fromRawData(mydata, sizeof(mydata));
            g_nbdpWorkFlow->On_SerialFilter_MessageIns(data);
           // g_mainWorkFlow->readMyCom();

        }
            break;

        case Qt::Key_I:
            //Transit::get()->EmitSignalInteruptConfirm(true);
            {
            static const char mydata1[] = {
                0x7e, 0x7e, 0x00, 0x0b, 0x02, 0x01, 0xd6,
                0x03, 0x01, 0x90
            };

            QByteArray data1 = QByteArray::fromRawData(mydata1, sizeof(mydata1));
            g_nbdpWorkFlow->On_SerialFilter_StateFlag(( type_NBDP_StateFlag* )data1.data());

        }
            break;

        case Qt::Key_D:
           // Transit::get()->EmitSignalInteruptDSC();
           {
            static const char mydata2[] = {
                0x7e, 0x7e, 0x00, 0x0b, 0x02, 0x01, 0xd0,
                0x06, 0x06, 0xa7, 0xce, 0x41, 0x01, 0x90
            };

            QByteArray data2 = QByteArray::fromRawData(mydata2, sizeof(mydata2));
            g_nbdpWorkFlow->On_SerialFilter_MessageIns(data2);
        }
            break;

        case Qt::Key_O:
            Transit::get()->EmitSignalInteruptComu();
            break;

        case Qt::Key_S:
            cic->setCallType("FEC");
            Transit::get()->EmitSignalScanData(cic);
            break;

        case Qt::Key_C:
            Transit::get()->EmitSignalCheckData(cdc1);
            break;

        case Qt::Key_N:
            Transit::get()->EmitSignalShutDown();
            break;

        case Qt::Key_W:
            Transit::get()->EmitSignalRadioConnectAnswer(true);
            break;

        case Qt::Key_V:
            Transit::get()->EmitSignalDSCfollowComm(cic);
            break;

        case Qt::Key_K:
            Transit::get()->EmitSignalMessageEnd();
            break;

        default:
            break;
        }
    }
    else if (strMdf == "Alt")
    {
        switch (intKc)
        {
        case Qt::Key_1:
            Transit::get()->EmitSignalTurningResult(true);
            break;

        case Qt::Key_2:
            Transit::get()->EmitSignalConnectingWait(true);
            break;

        case Qt::Key_3:
            Transit::get()->EmitSignalConnectingResult(true);
            break;

        default:
            break;
        }
    }
    else if (strMdf == "Ctrl+Alt")
    {
        switch (intKc)
        {
        case Qt::Key_1:
            Transit::get()->EmitSignalTurningResult(false);
            break;

        case Qt::Key_2:
            Transit::get()->EmitSignalConnectingWait(false);
            break;

        case Qt::Key_3:
            Transit::get()->EmitSignalConnectingResult(false);
            break;

        case Qt::Key_4:
            Logging::get()->debug("Ctrl+Alt+4");
            Transit::get()->EmitSignalState("Idle");
            break;

        case Qt::Key_5:
            Logging::get()->debug("Ctrl+Alt+5");
            Transit::get()->EmitSignalState("Scanning");
            break;

        case Qt::Key_6:
            Logging::get()->debug("Ctrl+Alt+6");
            Transit::get()->EmitSignalState("ARQ Connected");
            break;

        case Qt::Key_7:
            Logging::get()->debug("Ctrl+Alt+7");
            Transit::get()->EmitSignalState("Outgoing SFEC");
            break;

        case Qt::Key_8:
            Logging::get()->debug("Ctrl+Alt+8");
            Transit::get()->EmitSignalState("Outgoing BFEC");
            break;

        case Qt::Key_9:
            Logging::get()->debug("Ctrl+Alt+9");
            Transit::get()->EmitSignalState("Incoming FEC");
            break;

        case Qt::Key_M:
            Transit::get()->EmitSignalTalkSendConfirm(m_strNo, false);
            break;

        case Qt::Key_I:
            Transit::get()->EmitSignalInteruptConfirm(false);
            break;

        case Qt::Key_W:
            Transit::get()->EmitSignalRadioConnectAnswer(false);
            break;

        default:
            break;
        }
    }
}

//#define  IntCS1 1
//#define  IntCS2  2
//#define  IntCS3  3
//#define  IntCS4  4
//#define  IntCS5 5
//#define   IntRQ  6
//#define   Intbeta  7
//#define   Intalpha  8


void  Control::sendCSOneChar(QString strMsg)        //yzz
{
    unsigned char controlSignal_oneChar;

    switch(g_mainWorkFlow->strRemapIntger(strMsg))
    {
    case IntCS1:
        controlSignal_oneChar=IntCS1;
        break;
    case IntCS2:
        controlSignal_oneChar=IntCS2;
        break;
    case IntCS3:
        controlSignal_oneChar=IntCS3;
        break;
    case IntCS4:
        controlSignal_oneChar=IntCS4;
        break;
    case IntCS5:
        controlSignal_oneChar=IntCS5;
        break;
    case IntRQ:
        controlSignal_oneChar=IntRQ;
        break;
    case Intbeta:
        controlSignal_oneChar=Intbeta;
        break;
    case Intalpha:
        controlSignal_oneChar=Intalpha;
        break;
    default:     // P E D
        controlSignal_oneChar=g_mainWorkFlow->globalArray.mapLetterToNum.value(strMsg.at(0));
        break;
    }

    type_NBDP_MessageInstruction mesgIns;
    mesgIns.s_FrameHeader=FRAME_HEADER;
    short int nLength=sizeof(type_NBDP_MessageInstruction)-4-59;

     mesgIns.s_FrameLength=be16toh(nLength);
     mesgIns.s_SourceDeviceID=INS_DEVICEID_NBDP;
     mesgIns.s_TargetDeviceID=INS_DEVICEID_DSP;
     mesgIns.s_InsCode=INS_CODE_NBDP_Message;
     /*************5 ******************/

//     mesgIns.s_TX= 0x00;
     mesgIns.s_DataType[0]=0x01; /*mesgIns.s_DataType[1]=0x01;  mesgIns.s_DataType[2]=0x00; mesgIns.s_DataType[3]=0x00;*/
     for(int i=0;i < 60 ; ++i )
         mesgIns.s_DataZhen[i]=0x00;
      mesgIns.s_DataZhen[0]=controlSignal_oneChar;

      /************修改帧长度**************/
      int nullCharNum=0;
      while(true)
      {
          if(mesgIns.s_DataZhen[119-nullCharNum]!=0x00)
              break;
          nullCharNum++;
      }
       nLength=sizeof(type_NBDP_MessageInstruction)-4-nullCharNum;
       mesgIns.s_FrameLength=be16toh(nLength);

      /*************+1******************/
      mesgIns.s_VerifyValue=0x00;
      g_mSerial->Send_NBDP_MessageIns(&mesgIns);
}

//#define   IntRQ_RQ_RQ  9
//#define   IntalphaAlphaAlpha  10
//#define   IntbetaAlphaBeta  11
void Control::sendCSThreeChar(QString strMsg)      //yzz
{
    unsigned char controlSignal_threeChar;
     bool isThreeCallCode  =false;

    switch(g_mainWorkFlow->strRemapIntger(strMsg))
    {
    case IntRQ_RQ_RQ:
        controlSignal_threeChar=IntRQ;isThreeCallCode  =false;
        break;
    case IntalphaAlphaAlpha:
         controlSignal_threeChar=Intalpha;isThreeCallCode  =false;
        break;
    case IntbetaAlphaBeta:
         controlSignal_threeChar=Intbeta;  isThreeCallCode  =false;  //0x32 0x0E 0x32
        break;
    default:
        isThreeCallCode  =true;
        break;
    }


    type_NBDP_MessageInstruction mesgIns;
    mesgIns.s_FrameHeader=FRAME_HEADER;
    short int nLength=sizeof(type_NBDP_MessageInstruction)-4-57;

     mesgIns.s_FrameLength=be16toh(nLength);
     mesgIns.s_SourceDeviceID=INS_DEVICEID_NBDP;
     mesgIns.s_TargetDeviceID=INS_DEVICEID_DSP;
     mesgIns.s_InsCode=INS_CODE_NBDP_Message;
     /*************5 ******************/

     //mesgIns.s_TX= 0x00;
     mesgIns.s_DataType[0]=0x01;/* mesgIns.s_DataType[1]=0x01;  mesgIns.s_DataType[2]=0x00; mesgIns.s_DataType[3]=0x00;*/
     for(int i=0;i < 60 ; ++i )
         mesgIns.s_DataZhen[i]=0x00;
     if(isThreeCallCode  ==false)
     {
      mesgIns.s_DataZhen[0]=controlSignal_threeChar;
      mesgIns.s_DataZhen[1]=controlSignal_threeChar; if(controlSignal_threeChar==Intbeta)  mesgIns.s_DataZhen[1]=Intalpha;
      mesgIns.s_DataZhen[2]=controlSignal_threeChar;
     }
     else if(isThreeCallCode  ==true && g_mainWorkFlow->get_call_or_recg_state()==1)//呼叫码
     {

         for(int j=0;j<strMsg.size();)
         {

             if(strMsg.indexOf("RQ")==0 )
             {
                 mesgIns.s_DataZhen[0]=IntRQ;
                 mesgIns.s_DataZhen[1]=g_mainWorkFlow->globalArray.mapLetterToNum.value(strMsg.at(2));
                 mesgIns.s_DataZhen[2]=g_mainWorkFlow->globalArray.mapLetterToNum.value(strMsg.at(3));
                 j=strMsg.size();
             }
             else  if( strMsg.indexOf("RQ")==1)
             {
                 mesgIns.s_DataZhen[0]=g_mainWorkFlow->globalArray.mapLetterToNum.value(strMsg.at(0));
                 mesgIns.s_DataZhen[1]=IntRQ;
                 mesgIns.s_DataZhen[2]=g_mainWorkFlow->globalArray.mapLetterToNum.value(strMsg.at(3));
                 j=strMsg.size();
             }
             else
                 {
                 mesgIns.s_DataZhen[j]=g_mainWorkFlow->globalArray.mapLetterToNum.value(strMsg.at(j));
                 j+=1;
                 }
         }

     }
     else if(isThreeCallCode  ==true && g_mainWorkFlow->get_call_or_recg_state()==2) // 识别码
     {

         for(int j=0;j<strMsg.size();)
         {
             if(strMsg.indexOf(alpha)==0 )
             {
                 mesgIns.s_DataZhen[0]=Intalpha;
                 mesgIns.s_DataZhen[1]=g_mainWorkFlow->globalArray.mapLetterToNum.value(strMsg.at(7));
                 mesgIns.s_DataZhen[2]=g_mainWorkFlow->globalArray.mapLetterToNum.value(strMsg.at(8));
                 j=strMsg.size();

                 qDebug()<<QString("send:%1%2%3").arg("α",strMsg.at(7),strMsg.at(8));
             }
             else  if( strMsg.indexOf(alpha)==1)
             {
                 mesgIns.s_DataZhen[0]=g_mainWorkFlow->globalArray.mapLetterToNum.value(strMsg.at(0));
                 mesgIns.s_DataZhen[1]=Intalpha;
                 mesgIns.s_DataZhen[2]=g_mainWorkFlow->globalArray.mapLetterToNum.value(strMsg.at(8));
                 j=strMsg.size();
                 qDebug()<<QString("send:%1%2%3").arg(strMsg.at(0),"α",strMsg.at(8));
             }
             else
                 {
                 mesgIns.s_DataZhen[j]=g_mainWorkFlow->globalArray.mapLetterToNum.value(strMsg.at(j));
                 j+=1;
                 }
         }

     }else if(isThreeCallCode  ==true && strMsg.compare("3beta")==0) // 信息填充码 betabetabeta
     {
         mesgIns.s_DataZhen[0]=Intbeta;
         mesgIns.s_DataZhen[1]=Intbeta;
         mesgIns.s_DataZhen[2]=Intbeta;
     }

     /************修改帧长度**************/
     int nullCharNum=0;
     while(true)
     {
         if(mesgIns.s_DataZhen[119-nullCharNum]!=0x00)
             break;
         nullCharNum++;
     }
      nLength=sizeof(type_NBDP_MessageInstruction)-4-nullCharNum;
      mesgIns.s_FrameLength=be16toh(nLength);

      /*************+1******************/
      mesgIns.s_VerifyValue=0x00;
      g_mSerial->Send_NBDP_MessageIns(&mesgIns);
}
bool isLetter(char charMsg)
{
    //( charMsg >='a' )
}
void Control::sendInfoMessage(QByteArray strMsg)         //yzz
{

    type_NBDP_MessageInstruction mesgIns;
    mesgIns.s_FrameHeader=FRAME_HEADER;
    short int nLength=sizeof(type_NBDP_MessageInstruction)-4;

     mesgIns.s_FrameLength=be16toh(nLength);
     mesgIns.s_SourceDeviceID=INS_DEVICEID_NBDP;
     mesgIns.s_TargetDeviceID=INS_DEVICEID_DSP;
     mesgIns.s_InsCode=INS_CODE_NBDP_Message;
     /*************5 ******************/


     mesgIns.s_DataType[0]=0x01;
     qDebug()<<"type:"<<CallClass::get()->getCallInfo()->getCallType();
     if( CallClass::get()->getCallInfo()->getCallType().compare("BFEC") == 0)
         mesgIns.s_DataType[0]=0x02;
     else if( CallClass::get()->getCallInfo()->getCallType().compare("SFEC") == 0)
         mesgIns.s_DataType[0]=0x03;


     int j=0;
     for(int i=0;i < 120 ; ++i )
     {
         if(j<strMsg.size())
         {
             mesgIns.s_DataZhen[i]=strMsg.at(j);
             j+=1;
         }
         else
             mesgIns.s_DataZhen[i]=0x00;
     }


      /*************+1******************/
      mesgIns.s_VerifyValue=0x00;

      /************修改帧长度**************/
      int nullCharNum=0;
      while(true)
      {
          if(mesgIns.s_DataZhen[119-nullCharNum]!=0x00)
              break;
          nullCharNum++;
      }
       nLength=sizeof(type_NBDP_MessageInstruction)-4-nullCharNum;
       mesgIns.s_FrameLength=be16toh(nLength);

      /***************************/
      g_mSerial->Send_NBDP_MessageIns(&mesgIns);

}
void Control::SlotReflashDeviceInfo(QString four, QString nine, QString answerCode)
{

    //yzz ,device info

    type_NBDP_ReflashDeviceInfo deviceInfoIns;
    deviceInfoIns.s_FrameHeader=FRAME_HEADER;
    short int nLength=sizeof(type_NBDP_ReflashDeviceInfo)-4;

     deviceInfoIns.s_FrameLength=be16toh(nLength);
     deviceInfoIns.s_SourceDeviceID=INS_DEVICEID_NBDP;
     deviceInfoIns.s_TargetDeviceID=INS_DEVICEID_NBDP;

     deviceInfoIns.s_InsCode = INS_CODE_NBDP_DeviceInfo;
     deviceInfoIns.s_VerifyValue=0x00;


     //填充4wei
     QByteArray zeroAry[0]=0x00;
      long numCalledMMSI= four.toLong(); QByteArray fourMMSIAry;
      while(numCalledMMSI > 0 || fourMMSIAry.size() < 3 )
     {
         fourMMSIAry.prepend( numCalledMMSI % (256) );
         numCalledMMSI = numCalledMMSI /(256);
     }
//      for(int i=0; i<3;++i)
//      {    if( i<fourMMSIAry.size() ) continue;
//          else fourMMSIAry.prepend(  numCalledMMSI /(256) ); }

      deviceInfoIns.s_DeviceInfo[0] = four.size();
      for(int i=1; i<4; ++i )
            deviceInfoIns.s_DeviceInfo[i] = fourMMSIAry.at(i-1);

      //填充7wei
     deviceInfoIns.s_DeviceInfo[4] = 0x07;
     numCalledMMSI= nine.toLong(); QByteArray nineMMSIAry;
     while(numCalledMMSI > 0 || nineMMSIAry.size() < 4)
    {
        nineMMSIAry.prepend( numCalledMMSI % (256) );
        numCalledMMSI = numCalledMMSI /(256);
    }
//     for(int i=0; i<4;++i)
//     {    if( i<nineMMSIAry.size() ) continue;
//         else nineMMSIAry.prepend(zeroAry); }

     for(int i=5; i<9; ++i )
           deviceInfoIns.s_DeviceInfo[i] =nineMMSIAry.at(i-5);

     //填充answer
     deviceInfoIns.s_DeviceInfo[9] = answerCode.size();
     for(int i=10; i<40; ++i )
     {
         if( (i-10)<answerCode.size() )
           deviceInfoIns.s_DeviceInfo[i] =answerCode.at(i-10).toAscii();
         else
           deviceInfoIns.s_DeviceInfo[i] = 0x00;
     }
     g_mSerial->Send_NBDP_DeviceInfoIns(&deviceInfoIns);

}

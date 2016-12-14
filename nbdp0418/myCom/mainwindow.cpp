#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGlobal>
#include <QDebug>
#include <QtDebug>
#include <QFileInfo>
#include <QThread>
#include <globalarray.h>
#include <QDateTime>
#include "../control/control.h"
#include "maintimer.h"
#include "recetimer.h"
#include "UIDefineInsStruct.h"


MainWindow::MainWindow(UISerial* m_SerialSend0)
{
    ui= new Ui::MainWindow;
    ui->setupUi(this);

     bHaveSendCommOver = false;
     m_SerialSend=m_SerialSend0;
     workFlowState=1;
     b_flag_cs4=false;
     sendCalledArrayAfter=0;
     sendIdentifyArrayAfter=0;
     sendIdentifyOverArrayAfter=0;
     send_flow_state=0;
     timer2_switch_timer3=0;
     isLetterState=true;
     isLetterState_receive=true;
     isCallRadio=1;
     calledRadioStart=1;   //calledRadio first called
     isMainTimerOpen  = true ;

     CS_commuOver = 0 ;
     ReceInfo = 0;
     ReceCS =-1;
     Rece3RQ = -1;
     ReceIdent =-1;
     ReceBetaAlphaBeta = 0;

     connect(this,SIGNAL(signal_received_CS4()),this,SLOT(slot_received_CS4()));
     connect(this,SIGNAL(signal_received_CS5()),this,SLOT(slot_received_CS5()));
               //tiao xie success ,send call code
     connect(Transit::get(),SIGNAL(SignalTurningResult(bool)),this,SLOT(on_sendCallCode_callRadio(bool)));

            Timer0 = new QTimer(this);
            Timer0Count= 0 ;
            connect(Timer0,SIGNAL(timeout()),this,SLOT(Timer0_count()),Qt::DirectConnection);

            Timer1 = new QTimer(this);
            Timer1Count=0;
           // Timer1->start(450);                  //450 ms timeout
            connect(Timer1,SIGNAL(timeout()),this,SLOT(Timer1_count()));

            Timer2 = new QTimer(this);
            Timer2Count=0;
            //Timer2->start(450);                  //450 ms timeout
            connect(Timer2,SIGNAL(timeout()),this,SLOT(Timer2_count()),Qt::DirectConnection);

            Timer3 =new QTimer(this);
            Timer3Count=0;  isSendingMsg=0;   b_haveData=false;
            connect(Timer3,SIGNAL(timeout()),this,SLOT(Timer3_count()),Qt::DirectConnection);


            Timer4 =new QTimer(this);
            Timer4Count=0;
            connect(Timer4,SIGNAL(timeout()),this,SLOT(Timer4_count()));

            Timer5 =new QTimer(this);
            Timer5Count=0;
            connect(Timer5,SIGNAL(timeout()),this,SLOT(Timer5_count()));

            Timer6 =new QTimer(this);
            Timer6Count=0;
            connect(Timer6,SIGNAL(timeout()),this,SLOT(Timer6_count()));


            MainTimerCount=0; ReceTimerCount =0;
            sendIndex=0; receiveIndex=0;receiveCount=0;

            readTimer = new QTimer(this);
            readTimer->start(5);                  // 5 ms search one time
            connect(readTimer,SIGNAL(timeout()),this,SLOT(readMyCom()));

          sendCalledArrayAfter_FourMMSI=0;
          afterSendInfo1CallRadio_FourMMSI=0;
          afterSendCommuEnd14_callRadio_FourMMSI=0;
          afterSendBetaAlphaBeta_FourMMSI=0;
          afterSendCommuEnd1617_callRadio_FourMMSI=0;
          afterSendInfo2CallRadio_FourMMSI=0;
          callRadio_waitForInfo1_FourMMSI=0;
          callRadio_changetoSend_FourMMSI=0;
          sendCS2_waitInfo2_callRadio_FourMMSI=0;

           afterSendInfo1CallRadio=0;
           afterSendInfo2CallRadio=0;
           sendSwitchInfo1=0;
           sendSwitchInfo2=0;
           afterSendBetaAlphaBeta=0;               //为了测试置1
            sendCS1_waitInfo1_callRadio=0;
            sendCS2_waitInfo2_callRadio=0;
            sendCS3_callRadio=0;
            sendRQ_callRadio =0;
            afterSendCommuEnd14_callRadio=0;
            afterSendCommuEnd1617_callRadio=0;

            calledRadioWaitForCalledCharAry2=0;
             calledRadioWaitForCalledCharAry3=0;

             calledRadioWaitForIdentify1=0;
             calledRadio_afterSendCK1=0;

             calledRadio_afterSendCK2=0;
             calledRadioWaitForIdentifyOverChar=0;
             calledRadioWaitForInfo1=0;
             calledRadioWaitForInfo1=0;
             calledRadio_afterSendCS3=0;
             calledRadio_receiveToSend=0;
             calledRadio_waitForInfo1Back=0;
             calledRadio_after14SendCommuOver=0;
              calledRadio_after16SendCommuOver=0;
               calledRadio_waitForSendChangeToReceiveBack=0;

              sendCalledArrayAfter_redirect=0;
              sendIdentifyArrayAfter_redirect=0;
              sendIdentifyOverAfter_redirect=0;
              waitForCall_redirect=0; waitForCall1_call1Lose_redirect=0;
              waitForIdentify_redirect=0;
              waitForIdentifyOver_redirect=0;
              FourMMSI_redirect_called_2and1Road=0;

              sendCalledArrayAfter_FourMMSI_reDirect=0;
              waitForCall_FourMMSI_reDirect=0;
              reDirect=0; redirect_waitInfo1=0;
              reversedOrder=0;


}
bool MainWindow::get_state_recvinfo()
{
    int receiveState=0;
    bool temp_receiveState=false;

    if((this->isFourMMSI ==1 && this->isCallRadio==1) &&
            (callRadio_waitForInfo1_FourMMSI ==1 ||sendCS2_waitInfo2_callRadio_FourMMSI ==1))   // 4 WEI CALL
       {temp_receiveState=true; receiveState=1; }

    else if((this->isFourMMSI == 0 && this->isCallRadio ==1) &&
        (sendCS1_waitInfo1_callRadio ==1 ||sendCS2_waitInfo2_callRadio ==1))                    // 9 WEI CALL
       {temp_receiveState=true; receiveState=2;  }

    else if((this->isCallRadio ==0) &&
            (calledRadioWaitForInfo1==1 || calledRadioWaitForInfo2==1))                         //  CALLED
       {temp_receiveState=true; receiveState=3; }

    else if(this->isCallRadio ==0)
    {
        QString strCallType=CallClass::get()->getCallInfo()->getCallType();
        if(strCallType.compare("BFEC")==0 || strCallType.compare("SFEC")==0)
           {temp_receiveState=true; receiveState=4; }
        else
            {temp_receiveState=false; receiveState=5; }
    }

    qDebug()<<"is receive info"<<temp_receiveState<<"receiveState"<<receiveState;
    if(temp_receiveState == true)
          {

            qDebug()<<"!!!!";
          }

    return temp_receiveState;
}
int  MainWindow::get_call_or_recg_state()
{
    if(send_flow_state==1)       //0,no; (1,call)(2,recongnise)（3，send）
        return 1;
    else if(send_flow_state==2)
        return 2;
    else if(send_flow_state==3)
        return 3;
    else
        return 0;
}
void MainWindow::receive_display(QString str0)
{

}
void MainWindow::send_display(QString str0)
{

}


void MainWindow::MainTimer_count()
 {
    MainTimerCount+=1;

    QString str;
    int calledCodeStrSize=list_IS.size();

//    qDebug()<<"isCall"<<isCallRadio<<"send_flow_state"<<get_call_or_recg_state();
//    qDebug()<<"iden1"<<calledRadioWaitForIdentify1<<"iden2"<<calledRadio_afterSendCK1<<"iden3"<<calledRadio_afterSendCK2;
//    qDebug()<<"idenOver"<<calledRadioWaitForIdentifyOverChar<<"ReceIdent"<<ReceIdent;

    /*********************主台***************************/
    //呼叫状态
    if( isCallRadio ==1 )
    {
    if(get_call_or_recg_state()==1 && calledCodeStrSize==7)  //9wei ma
    {
                   //0,no; (1,call)(2,recongnise)

        qDebug()<<"Timer0Count is:"<<Timer0Count;
           if( (Timer0Count%3)==0  )
           { str=list_IS.at(0)+"RQ"+list_IS.at(1);   sendTimerStr(str,3);        }

           else if( (Timer0Count%3)==1  )
           {   str="RQ"+list_IS.at(2)+list_IS.at(3);   sendTimerStr(str,3);        }

           else if( (Timer0Count%3)==2  )                                                                                     //开启
           {  str=list_IS.at(4)+list_IS.at(5)+list_IS.at(6);   sendTimerStr(str,3);
               if(reDirect==0) sendCalledArrayAfter=3;
               else sendCalledArrayAfter_redirect=3;
           }
    }
    //识别状态
     else if(get_call_or_recg_state()==2 && calledCodeStrSize==7)
     {
         if(sendIdentifyArrayAfter==1)  //发送识别1
         {
             QString s1=list_IS_SELF.at(0)+alpha+list_IS_SELF.at(1);
             sendTimerStr(s1,3);
         }
         else if(sendIdentifyArrayAfter==2)  //发送识别2
         {
             QString s2=alpha+list_IS_SELF.at(2)+list_IS_SELF.at(3);
             sendTimerStr(s2,3);
         }
         else if(sendIdentifyArrayAfter==3)  //发送识别3
         {
             QString s3=list_IS_SELF.at(4)+list_IS_SELF.at(5)+list_IS_SELF.at(6);
             sendTimerStr(s3,3);
         }else if(sendIdentifyOverArrayAfter==1)
         {
             sendTimerStr(RQ_RQ_RQ,3);
         }
     }
    //通信发送状态
     else if(get_call_or_recg_state()==3 && calledCodeStrSize==7)
    {
        //信息1 或 信息2
        if( afterSendInfo1CallRadio ==1 || afterSendInfo2CallRadio == 1)
        {
        qDebug()<<"ReceCS"<<ReceCS<<"afterSendInfo1"<<this->afterSendInfo1CallRadio<<"afterSendInfo2"<<this->afterSendInfo2CallRadio;
        if( ReceCS == 0  )  // || ( ( ReceCS ==1 && this->afterSendInfo1CallRadio==1) || ( ReceCS ==2 && this->afterSendInfo2CallRadio==1)  )
        {  sendTimerStr(RQ_RQ_RQ,3);  ReceCS = 0; }          //没有收到CS信号
        else if( b_haveData == false && isSendingMsg == 0)   // 没有发送数据
        {
            emit signal_sendNbdp_mesg("3","3beta");          // 传信号给 sendCSThreeChar("3beta");
            ReceCS = 0;
        }
        else if(b_haveData == true && isSendingMsg == 0)  // 有发送数据，而且处理完毕，而且不是（正在发送状态）
        {
              qDebug()<<"send man input info:"<<sendInfo ;

              //  关闭光标 ，改变标志
              isSendingMsg = 1;  MainTimerCount = 1;

              emit signal_sendNbdp_mesg("3","3beta");          // 多发一次3beta
              ReceCS = 0;
        }
        else if( isSendingMsg == 1 )                       //在发送状态时，重复发送info直到接受到最后一个字符的回复
        {
            callRadio_sendMsgARQ();
        }
        }
        //转向
        else if( afterSendBetaAlphaBeta == 1 )
        {
            if( Rece3RQ == 0 )
                sendTimerStr(RQ_RQ_RQ,3);
            else
               { sendTimerStr(betaAlphaBeta,3);  }

            Rece3RQ = 0;
        }
        //转向成功，开启第二个线程定时器  (此时接受到RQ，再过140ms发送CS1)
        else if( sendCS1_waitInfo1_callRadio == 1 && isMainTimerOpen == true )
        { g_receTimer.start();  isMainTimerOpen = false; }
         //通信结束
        else if( afterSendCommuEnd14_callRadio == 1 || afterSendCommuEnd1617_callRadio ==1 )
        {  sendTimerStr(alphaAlphaAlpha,3);   qDebug()<<"Timer4Count is:"<<Timer4Count; }
     }
     }
                     /*********************副台***************************/
    else if(isCallRadio ==0 )
    {
        if( MainTimerCount == 1)     //第一次什么都不做（接受全呼叫码 ，立马回复CS4）
            return ;
        //识别状态
        if( get_call_or_recg_state() == 2  )  // && calledCodeStrSize==7
        {
            if( calledRadioWaitForIdentify1 == 1  )                       //未收到识别1，发送CS4  (等待识1)
                sendTimerStr(CS4,1);
            else if( calledRadio_afterSendCK1 == 1 )                      //                      (等待识2)
               {
                if(ReceIdent == -1 || ReceIdent == 1)                     //紧收到识别1，发送CK1
                  { sendTimerStr(list_CK_SELF.at(0),1); ReceIdent = 0 ;}
                else if( ReceIdent == 0)                                  //收到异常，发送RQ
                    sendTimerStr(RQ,1);
               }
            else if( calledRadio_afterSendCK2 == 1 )                      //                      (等待识3)
               {
                if( ReceIdent == -1 || ReceIdent == 2 )
                  { sendTimerStr(list_CK_SELF.at(1),1);  ReceIdent = 0 ; }
                else if(ReceIdent == 0 )
                     sendTimerStr(RQ,1);
               }
            else if( calledRadioWaitForIdentifyOverChar==1 )              //                      (等待识结)
            {
                if(ReceIdent == -1 || ReceIdent == 3)
                { sendTimerStr(list_CK_SELF.at(2),1);  ReceIdent = 0 ; }
              else if(ReceIdent == 0 )
                   sendTimerStr(RQ,1);
            }

        }
        //通信状态
        if(get_call_or_recg_state() == 3 ) //&& calledCodeStrSize ==7
        {
            if( calledRadioWaitForInfo1 ==1 )
                 sendTimerStr(CS1,1);
            else if( calledRadioWaitForInfo2 ==1 )
                 sendTimerStr(CS2,1);
            else if( calledRadio_afterSendCS3 == 1)
                 sendTimerStr(CS3,1);
            else if( calledRadio_receiveToSend ==1 )
             {
                if(ReceIdent == -1)
                  { sendTimerStr(RQ_RQ_RQ,3); ReceIdent = 0; }
             }
            else if(calledRadio_waitForInfo1Back == 1 || calledRadio_waitForInfo2Back == 1)
            {
                if( ReceIdent  == 0   )                              //没有收到CS信号
                {
                    sendTimerStr(RQ_RQ_RQ,3);
                }
                else if( b_haveData == false && isSendingMsg == 0 )  //(ReceIdent == 1 || ReceIdent ==2)
                {
                    emit signal_sendNbdp_mesg("3","3beta");
                    ReceIdent = 0;
                }
                else if(b_haveData == true && isSendingMsg == 0)  // 有发送数据，而且处理完毕，而且不是（正在发送状态）
                {
                      qDebug()<<"send man input info:"<<sendInfo ;

                      //  关闭光标 ，改变标志
                      isSendingMsg = 1;  MainTimerCount = 1;

                      emit signal_sendNbdp_mesg("3","3beta");          // 多发一次3beta
                      ReceIdent = 0;
                }
                else if( isSendingMsg == 1 )                       //在发送状态时，重复发送info直到接受到最后一个字符的回复
                {
                    calledRadio_sendMsgARQ();
                }
            }

        }
    }
    // qDebug()<<"Main Time:"+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz");
    if( MainTimerCount >10000 )
        MainTimerCount = 10;

 }
void MainWindow::ReceTimer_count()
{
    ReceTimerCount +=1;
    if( ReceTimerCount ==1 ) //线程立马启动的第一次什么都不做
        return ;

    int calledCodeStrSize=list_IS.size();
    if( get_call_or_recg_state()==3 && calledCodeStrSize==7 )
    {
        //信息1 信息2
        if( (sendCS1_waitInfo1_callRadio == 1 ||  sendCS2_waitInfo2_callRadio == 1) && CS_commuOver ==0 )
        {
            // 收到 信息1,发送 请求CS2
            if( sendCS2_waitInfo2_callRadio == 1 && ReceInfo == 0)
                { sendTimerStr(CS2,1); ReceInfo =0; }
            else if( sendCS1_waitInfo1_callRadio == 1 &&  ReceInfo == 0 )
                { sendTimerStr(CS1,1);  ReceInfo =0;}
        }
        //转向
        else if( sendCS3_callRadio==1 && ReceBetaAlphaBeta ==0 )
        {
            sendTimerStr(CS3,1);
        }
        //持续发送，直到接受到转向成功，立马改变状态
        else if( sendRQ_callRadio ==1 )
        {
            sendTimerStr(RQ,1);
        }
        //通信结束
        else if ( CS_commuOver ==1 )
        {
            if(  sendCS1_waitInfo1_callRadio == 1 )
              {sendTimerStr(CS2,1);   sendCS1_waitInfo1_callRadio =0; Timer3->stop(); }
            else if(  sendCS2_waitInfo2_callRadio == 1)
              {sendTimerStr(CS1,1);   sendCS2_waitInfo2_callRadio = 0;Timer3->stop(); }
            if(Timer5Count==0)   callRadio_changetoReady();
            else                 callRadio_changetoRemap();
            CS_commuOver = 0;
        }
    }
}
void MainWindow::Timer0_count()
{
    Timer0Count+=1;
    if(Timer0Count==1)
          Timer0->start(NBDPTIMER450);


      if(isCallRadio==1 && Timer0Count>=TIMER_0_out128 )
      {
      if(sendCalledArrayAfter==3)
          sendCalledArrayAfter=0;
      else if( sendCalledArrayAfter==1 )
          sendCalledArrayAfter=0;
      else if(  sendCalledArrayAfter==2)
          sendCalledArrayAfter=0;
      else if(  sendCalledArrayAfter_FourMMSI==2 )
          sendCalledArrayAfter_FourMMSI=0;
      else if( sendCalledArrayAfter_FourMMSI==1)
          sendCalledArrayAfter_FourMMSI=0;

      callRadio_changetoReady();

      }

}
void MainWindow::calledRadio_sendMsgARQ()
{
    int i ;
    static int sendCountCalled=0;

    if( MainTimerCount == 2) //前一次没有成功发送却超时退出，引起下一次重复发送
        sendCountCalled = 0;
    i=sendCountCalled;
    QByteArray strMsgTemp =sendData;
    QByteArray childMsg;

    int j=0;
    if(i>=1)
        j=i-1;
    if( i!=0 && ( ( ReceIdent ==1 && this->calledRadioWaitForInfo1==1) || ( ReceIdent ==2 && this->calledRadioWaitForInfo2==1)  ) )        //重复发送上一帧
    {
         Control::get()->sendInfoMessage(m_repeate_charMsg);
         ReceIdent = 0;
    }
    else if(i < (strMsgTemp.size()-1)/3+1 )                                                                              //发送下一帧
    {

    if( strMsgTemp.size()-(i*3) >= 3 )
         childMsg=strMsgTemp.mid( (i*3),3 );
    else
         childMsg=strMsgTemp.mid( (i*3),strMsgTemp.size()-(i*3) );

    Control::get()->sendInfoMessage(childMsg);                    //截取发送
    ReceIdent = 0;
    m_repeate_charMsg=childMsg; //保存给下一次发送（如果不成功）
    sendCountCalled+=1;

    }else                                                                                                                                  //收到最后一帧的回复
    {
        this->sendInfo.clear();  this->sendData.clear();
        this->isSendingMsg=0;    this->b_haveData = false;
        sendCountCalled=0;
        emit signal_sendNbdp_mesg("3","3beta");          // 最后一次传输信号不能走一次空，要发送3beta
        Transit::get()->EmitSignalLineEditState(true);  //ARQ 计时结束，打开光标
    }
}
void MainWindow::callRadio_sendMsgARQ()
{
    int i ;
    static int sendCount=0;

    if( MainTimerCount == 2) //前一次没有成功发送却超时退出，引起下一次重复发送
        sendCount = 0;
    i=sendCount;
    QByteArray strMsgTemp =sendData;
    QByteArray childMsg;

    int j=0;
    if(i>=1)
        j=i-1;
    if( i!=0 && ( ( ReceCS ==1 && this->afterSendInfo1CallRadio==1) || ( ReceCS ==2 && this->afterSendInfo2CallRadio==1)  ) )        //重复发送上一帧
    {
         Control::get()->sendInfoMessage(m_repeate_charMsg);
         ReceCS = 0;
    }
    else if(i < (strMsgTemp.size()-1)/3+1 )                                                                              //发送下一帧
    {

    if( strMsgTemp.size()-(i*3) >= 3 )
         childMsg=strMsgTemp.mid( (i*3),3 );
    else
         childMsg=strMsgTemp.mid( (i*3),strMsgTemp.size()-(i*3) );

    Control::get()->sendInfoMessage(childMsg);                    //截取发送
    ReceCS = 0;
    m_repeate_charMsg=childMsg; //保存给下一次发送（如果不成功）
    sendCount+=1;

    }else                                                                                                                                  //收到最后一帧的回复
    {
        this->sendInfo.clear();  this->sendData.clear();
        this->isSendingMsg=0;    this->b_haveData = false;
        sendCount=0;
        emit signal_sendNbdp_mesg("3","3beta");          // 最后一次传输信号不能走一次空，要发送3beta
        Transit::get()->EmitSignalLineEditState(true);  //ARQ 计时结束，打开光标
    }
}
void MainWindow::Timer6_count()
{

}
void MainWindow::Timer1_count()
{
    //Timer1Count+=1;
}
void MainWindow::Timer2_count()
{

    Timer2Count+=1;
    if(Timer2Count==1)
        Timer2->start(NBDPTIMER450);

    if(isCallRadio==1 && Timer2Count >= TIMER_2_3_5_out32)
    {
    if(sendIdentifyArrayAfter==1)
          sendIdentifyArrayAfter=0;
    else if(sendIdentifyArrayAfter==2)
        sendIdentifyArrayAfter=0;
    else if(sendIdentifyArrayAfter==3)
        sendIdentifyArrayAfter=0;
    else if(sendIdentifyOverArrayAfter==1)
        sendIdentifyOverArrayAfter=0;
    else if(sendIdentifyArrayAfter_redirect==1)
        sendIdentifyArrayAfter_redirect=0;
    else if(sendIdentifyArrayAfter_redirect==2)
        sendIdentifyArrayAfter_redirect=0;
    else if(sendIdentifyArrayAfter_redirect ==3 )
        sendIdentifyArrayAfter_redirect=0;
    else if(sendIdentifyOverAfter_redirect ==1)
        sendIdentifyOverAfter_redirect=0;

     callRadio_changetoReady();

    }else if(isCallRadio==0 && Timer2Count >= TIMER_2_3_5_out32)
    {
        if(calledRadioWaitForIdentify1==1 )
            calledRadioWaitForIdentify1=0;
        else if(calledRadio_afterSendCK1==1)
            calledRadio_afterSendCK1=0;
        else if(calledRadio_afterSendCK2==1  )
            calledRadio_afterSendCK2=0;
        else if(calledRadioWaitForIdentifyOverChar==1  )
            calledRadioWaitForIdentifyOverChar=0;
        else if(waitForIdentify_redirect==1  )
            waitForIdentify_redirect=0;
        else if(waitForIdentify_redirect==2  )
            waitForIdentify_redirect=0;
        else if(waitForIdentify_redirect==3  )
            waitForIdentify_redirect=0;
        else if(waitForIdentifyOver_redirect==1 )
            waitForIdentifyOver_redirect=0;

        calledRadio_changetoReady();
    }


}
void MainWindow::Timer3_count()   //A4-7首次启动
{
    Timer3Count+=1;
    if(Timer3Count==1)
        Timer3->start(NBDPTIMER450);


    /************************************************/
    if(isFourMMSI==1 && Timer3Count >= TIMER_2_3_5_out32 && isCallRadio==1)  //4位主台
    {
        if(afterSendInfo1CallRadio_FourMMSI==1)
            afterSendInfo1CallRadio_FourMMSI=0;
        else if(afterSendInfo2CallRadio_FourMMSI==1)
           afterSendInfo2CallRadio_FourMMSI=0;
        else if(afterSendBetaAlphaBeta_FourMMSI==1)
           afterSendBetaAlphaBeta_FourMMSI=0;
        else if(callRadio_waitForInfo1_FourMMSI==1)
            callRadio_waitForInfo1_FourMMSI=0;
        else if(sendCS2_waitInfo2_callRadio_FourMMSI==1)
           sendCS2_waitInfo2_callRadio_FourMMSI=0;
        else if(callRadio_changetoSend_FourMMSI==1)
            callRadio_changetoSend_FourMMSI=0;

         callRadio_changetoRemap();

    }
    else if(isFourMMSI==0 && Timer3Count >=  TIMER_2_3_5_out32 && isCallRadio==1)  //9位主台
    {
        if(afterSendInfo1CallRadio==1)
            afterSendInfo1CallRadio=0;
        else if( afterSendInfo2CallRadio==1)
             afterSendInfo2CallRadio=0;
        else if(afterSendBetaAlphaBeta==1)
            afterSendBetaAlphaBeta=0;
        else if(sendCS1_waitInfo1_callRadio==1)
            sendCS1_waitInfo1_callRadio=0;
        else if(sendCS2_waitInfo2_callRadio==1)
            sendCS2_waitInfo2_callRadio=0;
        else if(sendCS3_callRadio==1)
            sendCS3_callRadio=0;

        callRadio_changetoReady();
        send_flow_state=1;
        // Timer5_count();  //开启重定向

    }else if(Timer3Count >=  TIMER_2_3_5_out32 && isCallRadio==0)  //副台
    {
        if(calledRadioWaitForInfo1==1)
            calledRadioWaitForInfo1=0;
        else if( calledRadioWaitForInfo2==1)
             calledRadioWaitForInfo2=0;
        else if(calledRadio_afterSendCS3==1)
            calledRadio_afterSendCS3=0;
        else if(calledRadio_receiveToSend==1)
            calledRadio_receiveToSend=0;
        else if(calledRadio_waitForInfo1Back==1)
            calledRadio_waitForInfo1Back=0;
        else if(calledRadio_waitForInfo2Back==1)
            calledRadio_waitForInfo2Back=0;
        else if(calledRadio_waitForSendChangeToReceiveBack==1)
            calledRadio_waitForSendChangeToReceiveBack=0;

        calledRadio_changetoRemap();
    }


}
void MainWindow::Timer4_count()
{
    Timer4Count+=1;
    if(Timer4Count==1)
        Timer4->start(NBDPTIMER450);

     /***************4位主台  end14 N4 超时**********************************/
    if(Timer4Count >= TIMER_4_out4 && afterSendCommuEnd14_callRadio_FourMMSI==1 && isFourMMSI==1 && isCallRadio==1)
    {
        afterSendCommuEnd14_callRadio_FourMMSI=0;
        if(Timer5Count==0) callRadio_changetoReady();
        else callRadio_changetoRemap();
    }
    else if(Timer4Count >= TIMER_4_out4 && afterSendCommuEnd1617_callRadio_FourMMSI==1 && isFourMMSI==1 && isCallRadio==1)
    {
        afterSendCommuEnd1617_callRadio_FourMMSI=0;
        if(Timer5Count==0) callRadio_changetoReady();
        else callRadio_changetoRemap();
    }

    /***************9位主台  end14 N4 超时**********************************/
    else if(Timer4Count > TIMER_4_out4 && afterSendCommuEnd14_callRadio==1 && isCallRadio==1)
    {
     afterSendCommuEnd14_callRadio=0;
     if(Timer5Count==0) callRadio_changetoReady();
     else callRadio_changetoRemap();
    }
    /***************9位主台  end1617 N4 超时**********************************/
    else if(Timer4Count > TIMER_4_out4 && afterSendCommuEnd1617_callRadio==1 && isCallRadio==1)
    {
        afterSendCommuEnd1617_callRadio=0;
        if(Timer5Count==0) callRadio_changetoReady();
        else callRadio_changetoRemap();
    }
    else if(Timer4Count >=TIMER_4_out4 && calledRadio_after14SendCommuOver==1 && isCallRadio==0 )
    {
        if(Timer5Count==0)
            calledRadio_changetoReady();
        else
            calledRadio_changetoRemap();
    }
    else if(Timer4Count >= TIMER_4_out4 && calledRadio_after16SendCommuOver==1 && isCallRadio==0)
     {
         if(Timer5Count==0)
             calledRadio_changetoReady();
         else
             calledRadio_changetoRemap();
     }
}
void MainWindow::Timer5_count()
{
//    Timer5Count+=1;
//    if( Timer5Count==1)
//           Timer5->start(NBDPTIMER450);

    /***************************以上copy timer0******************/
    if( isFourMMSI==0 && Timer5Count>= TIMER_2_3_5_out32 )
    {
    if(sendCalledArrayAfter_redirect ==3)
        sendCalledArrayAfter_redirect =0;
    else if(sendCalledArrayAfter_redirect==2)
        sendCalledArrayAfter_redirect=0;
    else if(sendCalledArrayAfter_redirect ==1)
        sendCalledArrayAfter_redirect =0;
    else if(sendCalledArrayAfter_FourMMSI_reDirect==2 )
        sendCalledArrayAfter_FourMMSI_reDirect=0;
    else if(sendCalledArrayAfter_FourMMSI_reDirect==1 )
        sendCalledArrayAfter_FourMMSI_reDirect=0;

     callRadio_changetoReady();
    }

}
void MainWindow::init_nine_MMSI(int flag)   //0 self MMSI ; 1  called MMSI
{

    QList<int> list_R;
    QList<int> list_N;
    QList<int> list_CN;
    QList<QString> list_IS_TEMP;
    QList<QString> list_CK_TEMP;
    QString S_MMSI;

    if(flag==0)
         S_MMSI=m_strSelf;
    else if(flag==1)
         S_MMSI=m_strCalled;
    else
        qDebug("init_self_MMSI(int flag) flag error");

    bool ok;
    qlonglong long_MMSI=S_MMSI.toLongLong(&ok,10);
    qlonglong temp_long_MMSI=long_MMSI;
    while(temp_long_MMSI!=0)
    {
        list_R.append(temp_long_MMSI%20);           //尾部添加
        temp_long_MMSI=temp_long_MMSI/20;
    }

    //从R 到 is
    for(int i=0;i<list_R.size();++i)
    {
        list_IS_TEMP.prepend(globalArray.mapRToIS.value(list_R.at(i)));  // 从头部添加

    }
    if(flag==0)
        list_IS_SELF=list_IS_TEMP;
    else
        list_IS=list_IS_TEMP;



    //识别信号 （is）到 等效信号（N）
    for(int i=0; i<list_IS_TEMP.size();++i)
    {
        list_N.append(globalArray.mapIsToN.value(list_IS_TEMP.at(i)));
    }
    for(int i=0;(i+2)<list_N.size();)
    {
        list_CN.append((list_N.at(i)+list_N.at(i+1)+list_N.at(i+2))%20);
        i=i+2;
    }
    //校验和号 到 校验和信号
    for(int i=0;i<list_CN.size();++i)
     {
        list_CK_TEMP.append(globalArray.mapCNToCK.value(list_CN.at(i)));
    }
    if(flag==0)
        list_CK_SELF=list_CK_TEMP;
    else
        list_CK=list_CK_TEMP;
    if(flag==0)
        qDebug()<<"self MMSI:"<<ui->labelStatic1->text()<<"IS:"<<list_IS_SELF<<"CK"<<list_CK_SELF;
    else
        qDebug()<<"called MMSI:"<<ui->labelStatic2->text()<<"IS:"<<list_IS<<"CK"<<list_CK;

}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::received_notExpected_CalledArrayAfter3()    //发送呼叫字组3之后
{
    //发射呼叫字组1，改变状态
    QString s1=list_IS.at(0)+"RQ"+list_IS.at(1);
    sendTimerStr(s1,3);    send_display(s1);

}
void MainWindow::received_notExpected_CalledArrayAfter1()      //发送呼叫字组1之后
{
     //发射呼叫字组2，改变状态
     QString s2="RQ"+list_IS.at(2)+list_IS.at(3);
    sendTimerStr(s2,3);    send_display(s2);
}
void MainWindow::received_notExpected_CalledArrayAfter2()            //发送呼叫字组2之后
{
     QString s3=list_IS.at(4)+list_IS.at(5)+list_IS.at(6);
     sendTimerStr(s3,3);      send_display(s3);
}

void MainWindow::sendIdentifTwo_receivedCK1()
{
       QString s2=alpha+list_IS_SELF.at(2)+list_IS_SELF.at(3);
       sendTimerStr(s2,3);
}
void MainWindow::sendIdentifThree_receivedCK2()
{
                               QString s3=list_IS_SELF.at(4)+list_IS_SELF.at(5)+list_IS_SELF.at(6);
                              sendTimerStr(s3,3);
}
void MainWindow::afterReceivedCK3_gotoIdentifyOver()
{

    sendTimerStr(RQ_RQ_RQ,3);    send_display(RQ_RQ_RQ);

}
//void MainWindow::afterReceivedCS1_gotoCommunication()
//{
//                            //   Timer3->start(450);

//                               QString contentsToSend=ui->lineEditContentsToSend->text();
//                               /***************根据没有结束字符，分支发送**********************/

//                                if(contentsToSend.compare(contentsToSend,"+?") ==0  )
//                       {
//                               Timer3->stop();       //转入通信结束14,待添加，记得发送完毕后不必改变 afterSendInfo1CallRadio=1;
//                               sendSwitchInfo1=1;
//                       }
//                                 else
//                        {
//                               sendSwitchInfo1=1;                // 记得发送完毕后需要改变 afterSendInfo1CallRadio=1;
//                               // myCom->write(contentsToSend);应该改变标志，在发送位置处判断要不要发送，而不是在这里发送

//                        }

//}
void MainWindow::afterReceivedInfo1() //11转入的地方
 {
        QString info2=ui->lineEditContentsToSend->text();
         if(info2.compare(info2,"+?")==0 ) //有内容，含有结束符
     {
         sendSwitchInfo2=1;
                               //转入通信结束程序 17，待添加
     }else
     {
         sendSwitchInfo2=1;    //发送信息字组2，自动打开开关，手动发送
     }
}

int MainWindow::afterReceivedInfo1_callRadio(QString str)
{
     if(str.contains("+?")==true)  //转入13 ，A11-A12
          return 0;
     else
     {     
     if(sendInfo.compare(sendInfo,CS3)==0)   //转入13 ，A11-A12
         return 0;
     else
     {
          return 1;
      }
     }
}


 void MainWindow::callRadio_changeTo_commuEnd14()
{
  Timer4->start(NBDPTIMER450);
  sendTimerStr(alphaAlphaAlpha,3);       send_display(alphaAlphaAlpha);
  //afterSendCommuEnd14_callRadio=1;
  calledRadioStart=1;
}
 void MainWindow::callRadio_changeTo_commuEnd16()
 {
                               Timer1->start(NBDPTIMER450);
                               callRadio_changeTo_commuEnd17();

}
                               void MainWindow::callRadio_changeTo_commuEnd17()
     {
                               Timer4->start(NBDPTIMER450);

                              sendTimerStr(alphaAlphaAlpha,3);        send_display(alphaAlphaAlpha);
                               afterSendCommuEnd1617_callRadio=1;calledRadioStart=1;
}

void MainWindow::readMyCom(  )
{
    com_receive_Array=m_SerialSend->m_serial1->readAll();

    if(com_receive_Array.isEmpty() == false)
       {
       qDebug()<<QDateTime::currentDateTime().toString("hh:mm:ss.zzz")<<beginTime.msecsTo( QDateTime::currentDateTime() ); beginTime =QDateTime::currentDateTime();
       qDebug()<<"receive:"<<com_receive_Array.toHex();

       m_SerialSend->on_Serial1_ReadDataFinished(com_receive_Array);
       }


}
                               void MainWindow::calledRadio_changeToReceiveAgain()  //this is  20(B9)
                               {
                                  sendTimerStr(betaAlphaBeta,3);   send_display(betaAlphaBeta);

                               }
                               int MainWindow::calledRadio_receivedInfo2Back()
                               {
                               Timer3->start(NBDPTIMER450);
                               QString str=sendInfo;
                               if(str.contains("+?")==true)
                                   return 0;
                               else
                                  return 1;
                               }
                               void MainWindow:: calledRadio_changetoCommuOver14()
                               {
                               Timer4->start(NBDPTIMER450);
                               sendTimerStr(alphaAlphaAlpha,3);    send_display(alphaAlphaAlpha);

                               }
                               void MainWindow:: calledRadio_changetoCommuOver16()
                               {
                               Timer4->start(NBDPTIMER450);
                               sendTimerStr(alphaAlphaAlpha,3);    send_display(alphaAlphaAlpha);

                               }
                               int MainWindow::calledRadio_receivedInfo1Back()
                                {
                                   QString str=sendInfo;
                                   if(str.contains(alphaAlphaAlpha)==true)
                                    {
                                         //go to 16
                                       return 0;
                                     }
                                    else
                                        return 1;
                                }
                               void MainWindow::calledRadio_sendPosition()  //26 (B6)
                              {
                               Timer3->start(NBDPTIMER450);
                               calledRadio_openSendInfo1Switch();
                              }
                               void MainWindow::calledRadio_openSendInfo1Switch()
                             {
//                               sendSwitchInfo1=1;
//                               calledRadio_waitForInfo1Back=1;
                             }
                               void MainWindow::calledRadio_receiveChangeToSend()
                               {
                                sendTimerStr(CS3,1);                send_display(CS3);

                               }
                               int MainWindow:: calledRadio_receivedInfo2()
                               {
                               if(receivedInfo.contains("+?")==true)
                               {
                                   calledRadio_receiveChangeToSend();  // goto 13
                                   return 0;
                               }
                               else   //loop goto 9-1
                                 {
                                   if(calledRadio_gotoCommu()==1)
                                     return 1;
                                   else
                                     return 0;
                                 }
                               }

                               int MainWindow:: calledRadio_receivedInfo1(QString str)
                               {
                               if( str.contains("+?") == true  )  // receive change to send position,
                                           return 0;
                               else
                                           return 1;
                               }
                               int MainWindow::calledRadio_gotoCommu()
                               {
                               //QString
                               Timer3->start(NBDPTIMER450);
                               if(sendInfo.compare(sendInfo,CS3)==0)  //change to send position
                                  {
                                   calledRadio_receiveChangeToSend();
                                   return 0;
                                  }
                               else
                                  {
                                     sendTimerStr(CS1,1);    // send_display(CS1);
                                    return 1;
                                  }

                               }
                             void MainWindow::calledRadio_afterReceivedIdentifyCharAry3()
                             {
                              QString CK3=list_CK_SELF.at(2);
                               sendTimerStr(CK3,1);     send_display(CK3);

                             }
                               void MainWindow::calledRadio_afterReceivedIdentifyCharAry2()
                               {
                               QString CK2=list_CK_SELF.at(1);
                               sendTimerStr(CK2,1);

                               }

                               void MainWindow::calledRadio_afterReceivedIdentifyCharAry1()
                               {
                               QString CK1=list_CK_SELF.at(0);
                               sendTimerStr(CK1,1);
                               }
                               void MainWindow::calledRadio_afterReceivedCalledCharAry1()
     {
                               calledRadioWaitForCalledCharAry2=1;
     }
    void MainWindow::calledRadio7_afterReceivedCalledCharAry2()
     {
                               calledRadioWaitForCalledCharAry3=1;
     }
     int MainWindow::calledRadio4_afterReceivedCalledCharAry2()
     {
         int flag=0;
         flag=calledRadio_gotoCommu();  //step to identify over,goto communication
          if(flag==1)
          {
              return 1;
          }
          else
              return 0;

     }
     void MainWindow::calledRadio_afterReceivedCalledCharAry3() // zhuan dao 1 (B2)
     {
                     Timer2->start(NBDPTIMER450);
                    sendTimerStr(CS4,1);

     }

   void MainWindow::callRadio_changeToRemap() //change to remap,JISHUQI n4==4 也转入此程序
     {
                               //panduan n5==0? shi ze ready,fou ze 25(A7)
                               qDebug("change to remap!");
     }
  void MainWindow::callRadio_sendAgain_afterReceiveWait()
{
                               sendTimerStr(RQ,1);    ;  send_display(RQ);// send CO2
                               Timer3->stop();
                               sendSwitchInfo1=1;
}
 void MainWindow::callRadio_sendAgain_beforeReceiveWait() //A12(13)
 {
                                sendTimerStr(CS3,1);      send_display(CS3);
                                //sendCS3_callRadio=1;

}
int MainWindow::callRadio_receive()     // A11中的18
{
                               //T12 待添加
                               if(receivedInfo ==CS3) // T13   判断是否是CS3
                                 {

                                return 0;
                                 }//转入 13（A12）
                               else
                                {
                                    sendTimerStr(CS1,1);    send_display(CS1);
                                   //sendCS1_waitInfo1_callRadio=1;  //A11
                                   return 1;
                                 }
}

void MainWindow::callRadio_changeToReceive()
{

    sendTimerStr(betaAlphaBeta,3);   send_display(betaAlphaBeta);

}

void MainWindow::on_buttonOpenSerial_clicked()
{

//    // myCom= new Posix_QextSerialPort("/dev/ttyS0",QextSerialBase::Polling);            //pc端默认使用com1作为数据口
//    if(myCom->open(QIODevice::ReadWrite)==true)
//    {
//        pe.setColor(QPalette::WindowText,Qt::red);
//        ui->label->setPalette(pe);  //set red
//        ui->label->setText("COM is Open!");
//    }

//    myCom->setBaudRate(BAUD9600);
//    myCom->setDataBits(DATA_8);
//    myCom->setParity(PAR_NONE);
//    myCom->setStopBits(STOP_1);
//    myCom->setFlowControl(FLOW_OFF);
//    myCom->setTimeout(10);

//    readTimer = new QTimer(this);
//    readTimer->start(10);                  //20 ms search one time
//    connect(readTimer,SIGNAL(timeout()),this,SLOT(readMyCom()));


//    ui->buttonOpenSerial->setEnabled(false);
//    ui->buttonCloseSerial->setEnabled(true);
//    ui->buttonSendToSerial->setEnabled(true);


     //sendTimerStr(RQ_RQ_RQ,1);
}


void MainWindow::on_buttonCloseSerial_clicked()
{
    myCom->close();
    pe.setColor(QPalette::WindowText,Qt::black);
    ui->label->setPalette(pe);
    ui->label->setText(tr("COM is disconnected!"));
    ui->buttonOpenSerial->setEnabled(true);
    ui->buttonCloseSerial->setEnabled(false);
    ui->buttonSendToSerial->setEnabled(false);

}
QByteArray MainWindow::Str_addZhuanYi(QString strMsg)    //加入转义字符
{
    QString temp_str=strMsg;
    QByteArray temp_array;
    QChar strMsgChar;

    g_mainWorkFlow->isLetterState=true;
    temp_array.append(g_mainWorkFlow->globalArray.mapSwitchLetterAndNum["toLetter"]);


    for(int i=0 ; i<temp_str.size() ; ++i)
    {

        strMsgChar=temp_str.at(i);
        if(i==1 && temp_str.size()==0)                         // 回车 换行
        {
            temp_array.append( g_mainWorkFlow->globalArray.mapSwitchLetterAndNum.value("huiChe") );
            temp_array.append( g_mainWorkFlow->globalArray.mapSwitchLetterAndNum.value("huanHang") );
            i=2;
        }
        if(i==1 && temp_str.size()==1 && temp_str.at(0)==' ')      // 单独空格
        {
            temp_array.append( this->globalArray.mapSwitchLetterAndNum.value(temp_str.at(0)) );
             i=2; break;
        }
        //如果当前是数字，状态为字母则添加
        if( (strMsgChar>='0' && strMsgChar<='9') ||
                (strMsgChar=='-') || (strMsgChar=='?')||(strMsgChar==':')||(strMsgChar=='$')||(strMsgChar=='&')||(strMsgChar=='(')||
                (strMsgChar==')')||(strMsgChar=='.')||(strMsgChar==',')||(strMsgChar=='\'')||(strMsgChar=='/')||(strMsgChar=='+')||(strMsgChar=='='))
        {
            if(g_mainWorkFlow->isLetterState==true)
            {temp_array.append( this->globalArray.mapSwitchLetterAndNum["toNum"] );this->isLetterState=false;}

           temp_array.append( this->globalArray.mapLetterToNum.value(strMsgChar) );  // zifuchuan zhong di n ge zifu
        }
        //如果当前是字母，状态为数字则添加
        else  if( ( strMsgChar>='a' && strMsgChar<='z') || ( strMsgChar>='A' && strMsgChar<='Z') )
        {
             if(this->isLetterState==false)
                { temp_array.append( this->globalArray.mapSwitchLetterAndNum["toLetter"] );this->isLetterState=true;}

             temp_array.append(this->globalArray.mapLetterToNum.value(strMsgChar) );     // zifuchuan zhong di n ge zifu
        } else if(strMsgChar==' ')
        {
            temp_array.append(this->globalArray.mapSwitchLetterAndNum.value(strMsgChar));  // 空格
        }

    }

    if(CallClass::get()->getCallInfo()->getCallType().compare("ARQ")==0)    //ARQ发送 最后用beta 补足3的倍数
   {
        int charNum=temp_array.size();
        int betaNum=charNum % 3; int j=0;
         while(betaNum!=0 && j<(3-betaNum))
         {
             temp_array.append(Intbeta);
             ++j;
         }
    }
    qDebug()<<"temp_array is:"<<temp_array.toHex();
    return temp_array;
}
void MainWindow::on_buttonSendToSerial_clicked(QString strNo,QString strMsg)
{
    QString contentsToSend=strMsg.toUpper();


    if( contentsToSend.compare("[BREAK]") ==0 )
      {

        QByteArray temp_BREAK; temp_BREAK[0]=0xAA ; temp_BREAK[1]=0xAA ;temp_BREAK[2]=0xAA ;Control::get()->sendInfoMessage(temp_BREAK);

        return;
      }
    else if(contentsToSend.compare("WRU") ==0)
     {
         QByteArray temp_WRU; temp_WRU[0]=0xAC ; Control::get()->sendInfoMessage(temp_WRU);
         return;
     }



    if( contentsToSend.isEmpty() == true)
        {QByteArray temp_huiCHe; temp_huiCHe[0]=0x0D ; temp_huiCHe[1]=0x0A; Control::get()->sendInfoMessage(temp_huiCHe); }
    else
        Control::get()->sendInfoMessage(contentsToSend.toAscii());


}
//void MainWindow::on_buttonSendToSerial_clicked(QString strNo,QString strMsg)    //储存发送内容，改变接受状态
//{
//      QString contentsToSend=strMsg;
//      if( sendSwitchInfo1 ==0 && sendSwitchInfo2 ==0 )           //在打开开关的时候才可以发送数据
//          return;

//    sendInfo=(QString("ID:")+contentsToSend+(QString(";")));  b_haveData = false ;
//    sendData=Str_addZhuanYi(strMsg);
//    bool b_isBreak =false ;
//    qDebug()<<"sendInfo"<<sendInfo;
//    if(sendInfo.contains("Break")==true || sendInfo.contains("BRK+")==true || sendInfo.contains("brk+")==true )
//        { b_isBreak = true ; qDebug()<<"enter break"<<"sendSwitch1 and switch2"<<sendSwitchInfo1<<sendSwitchInfo2; }
////    if( sendInfo.contains("+?")== true )
////       { send_flow_state=3 ; afterSendInfo1CallRadio =1 ;}

//    if( CallClass::get()->getCallInfo()->getCallType().compare("ARQ")==0 &&  b_haveData == false && b_isBreak == false )   //ARQ 发送数据（替代3beta）
//         b_haveData = true ;

//    else if(CallClass::get()->getCallInfo()->getCallType().compare("ARQ") !=0)                      //FEC 发送    （从sendData中获取，sendInfo没用）
//        emit signal_sendNbdp_mesg("0",sendInfo);

//    if(contentsToSend.isEmpty() ==false)
//      {
//      if(isCallRadio==1 && sendSwitchInfo1==1 &&  afterSendInfo1CallRadio == 1)        //非空下，可以发送时，发送完清除(info ary: start with"ID",end with ";")
//     {
//        sendSwitchInfo1=0 ;   //
//        if(sendInfo.contains("Break")==true || sendInfo.contains("BRK+")==true || sendInfo.contains("brk+")==true )
//           {
//            if(isFourMMSI==0)
//            {
//            afterSendInfo1CallRadio = 0;   afterSendCommuEnd14_callRadio = 1;
//            Timer3->stop();Timer3Count=0;  Timer4_count(); //commOver back
//            qDebug()<<"enter break2 change state";
//            }
//            else  // 4 wei ma commOver back
//            {
//             afterSendCommuEnd14_callRadio_FourMMSI=1;  Timer3->stop();Timer3Count=0; Timer4->start(NBDPTIMER450); //commOver back
//             sendTimerStr(alphaAlphaAlpha,3);
//            }
//           }
//        else if(isFourMMSI==0)  //9 wei ma
//           {
//            sendIndex=0;
//           }
//        else                  //4wei ma
//        {
//            sendIndex=0;
//        }

//      }else if(isCallRadio==1 && sendSwitchInfo2==1 &&  afterSendInfo2CallRadio == 1)        //非空下，可以发送时，发送完清除
//     {

//        sendSwitchInfo2=0 ;   //
//           if(sendInfo.contains("Break")==true || sendInfo.contains("BRK+")==true || sendInfo.contains("brk+")==true)  //跟info2并列的结束符
//        {
//               if(isFourMMSI==0)  //9wei ma
//               {
//                    afterSendInfo2CallRadio = 0 ; afterSendCommuEnd1617_callRadio =1;
//                    Timer3->stop();Timer3Count=0; Timer4_count();
//               }
//               else     // 4 wei ma
//               {
//                   afterSendCommuEnd1617_callRadio_FourMMSI =1;
//                   Timer3->stop();Timer3Count=0; Timer4->start(NBDPTIMER450);
//                   sendTimerStr(alphaAlphaAlpha,3);
//               }
//        }
//        else
//        {
//               if(isFourMMSI==0)
//               {
//                    sendIndex=0;
//               }
//               else
//               {
//                   afterSendInfo2CallRadio_FourMMSI=1;
//                   sendIndex=0;
//               }
//        }

//      }else if(isCallRadio==0 && sendSwitchInfo1==1)
//    {
//            sendSwitchInfo1=0 ;
//        if(sendInfo.contains("Break")==true || sendInfo.contains("BRK+")==true || sendInfo.contains("brk+")==true)  //跟info1并列
//        {
//            calledRadio_after14SendCommuOver=1;
//             Timer3->stop();Timer3Count=0; Timer4->start(NBDPTIMER450);Timer4Count=0;
//            sendTimerStr(alphaAlphaAlpha,3); send_display("alphaAlphaAlpha");
//        }
//        else
//        {
//            calledRadio_waitForInfo1Back=1;
//            sendIndex=0;
//        }
//      } else if(isCallRadio==0 && sendSwitchInfo2==1)        //非空下，可以发送时，发送完清除
//      {

//         sendSwitchInfo2=0 ;
//         if(sendInfo.contains("Break")==true|| sendInfo.contains("BRK+")==true || sendInfo.contains("brk+")==true)  //跟info2并列
//            {
//             calledRadio_after16SendCommuOver=1;
//              Timer3->stop();Timer3Count=0; Timer4->start(NBDPTIMER450);Timer4Count=0;
//             sendTimerStr(alphaAlphaAlpha,3); send_display("alphaAlphaAlpha");
//            }
//         else
//         {
//             calledRadio_waitForInfo2Back=1;   //可以接受
//             sendIndex=0;
//         }
//       }
//      else if(CallClass::get()->getCallInfo()->getCallType()=="SFEC" || CallClass::get()->getCallInfo()->getCallType()=="BFEC")
//         {
//          if(sendInfo.compare("ID:[Break];")!=0)
//             { sendTimerStr(sendInfo,0); send_display(sendInfo);qDebug()<<"sendInfo is:"<<sendInfo; }
//         }
// } else
//         { sendTimerStr(sendInfo,0); qDebug("can send ,but lineEdit is enter :huiChe Huan Hang");}
//}

//void MainWindow::send_call_byteArray()
//{
//    QString s1=list_IS.at(0)+"RQ"+list_IS.at(1);
//    testWidget->insertDebugInfo(tr("sending 呼叫字组1: ...")); testWidget->insertDebugInfo(s1);
//    //myCom->write(s1.toAscii());
//    QString s2="RQ"+list_IS.at(2)+list_IS.at(3);
//      testWidget->insertDebugInfo(tr("sending 呼叫字组2: ...")); testWidget->insertDebugInfo(s2);
//   // myCom->write(s2.toAscii());
//    QString s3=list_IS.at(4)+list_IS.at(5)+list_IS.at(6);
//       testWidget->insertDebugInfo(tr("sending 呼叫字组3: ...")); testWidget->insertDebugInfo(s3);
//   // myCom->write(s3.toAscii());
//}
//void MainWindow::send_recongnise_byteArray()
//{
//    QString str;
//    //发送识别字组1，并接受ck1
//    QString s1=list_IS_SELF.at(0)+tr("α")+list_IS_SELF.at(1);

//   testWidget->insertDebugInfo(tr("sending 识别字组1: ...")); testWidget->insertDebugInfo(s1);
//    // myCom->write(s1.toAscii());
//      testWidget->insertDebugInfo(tr("waiting ck1:%1").arg(list_CK.at(0)));
//        while(1)
//        {
//             ui->lineEdit_3->setText(list_CK.at(0));
//             str=ui->lineEdit_3->text();
//             if(str.compare(str,list_CK.at(0),Qt::CaseSensitive)==0)          //
//               break;
//        }


//  testWidget->insertDebugInfo(tr("receive ck1 ok"));
//    //发送识别字组2，并接受ck2
//    QString s2="α"+list_IS_SELF.at(2)+list_IS_SELF.at(3);
//   // myCom->write(s2.toAscii());

//    testWidget->insertDebugInfo(tr("sending 识别字组2:%1 ").arg(s2));
//   // readTimer->stop();
//        while(1)
//        {
//             ui->lineEdit_3->setText(list_CK.at(1));
//             str=ui->lineEdit_3->text();
//             if(str.compare(str,list_CK.at(1),Qt::CaseSensitive)==0)
//               break;
//        }
//  testWidget->insertDebugInfo(tr("receive ck2 %1 ok").arg(list_CK.at(1)));

//    //发送识别字组3，并接受ck3
//    QString s3=list_IS_SELF.at(4)+list_IS_SELF.at(5)+list_IS_SELF.at(6);
//     // myCom->write(s2.toAscii());
//     testWidget->insertDebugInfo(tr("sending 识别字组3:%1 ").arg(s3));

//       //ui->textBrowser->append(tr("sending 识别字组3: ..."));ui->textBrowser->append(s3);
//        while(1)
//        {
//            ui->lineEdit_3->setText(list_CK.at(2));
//              str=ui->lineEdit_3->text();
//             if(str.compare(str,list_CK.at(2),Qt::CaseSensitive)==0)
//               break;
//        }
//       testWidget->insertDebugInfo(tr("ck3 %1 ok").arg(list_CK.at(2)));

//}
//void MainWindow::send_info_byteArray()
//{

//     //等待接受cs1
//            //发送字组1ABC
//    QString str;
//  testWidget->insertDebugInfo(tr("waiting BYBYYBB"));
//    while(1)
//    {
//        ui->lineEdit_3->setText("BYBYYBB");
//        str=ui->lineEdit_3->text();
//        if(str.compare(str,"BYBYYBB",Qt::CaseSensitive)==0)
//          break;
//    }

//     testWidget->insertDebugInfo(tr("receive cs1:BYBYYBB OK"));

//    QString info1("ABC");
//    testWidget->insertDebugInfo(tr("sending info1 ABC"));
//   // myCom->write(info1.toAscii());
//     //等待接受cs2
//           //发送字组2def

// testWidget->insertDebugInfo(tr("waiting cs2"));

//    while(1)
//    {
//        ui->lineEdit_3->setText("YBYBYBB");
//        str=ui->lineEdit_3->text();
//        if(str.compare(str,"YBYBYBB",Qt::CaseSensitive)==0)
//          break;
//    }
//     testWidget->insertDebugInfo(tr("cs2 YBYBYBB OK!"));
//    QString info2("def");
//    //myCom->write(info2.toAscii());
//     testWidget->insertDebugInfo(tr("sending info2 def"));

//}

//void MainWindow::on_pushButton_4_clicked()
//{

//        init_self_MMSI(1); //flag ==1 分析呼叫台mmsi
//        //发送呼叫字组1,2,3
//         send_call_byteArray();

//        //等待接受CS4    ARQ "BYBYBBY"
//         //ui->textBrowser->append("waiting CS4: BYBYBBY...");
//         testWidget->insertDebugInfo("waiting CS4: BYBYBBY...");
//         //readTimer->stop();
//          QString str;
//          while(1)
//          {
//               ui->lineEdit_3->setText("BYBYBBY");
//                str=ui->lineEdit_3->text();
//               if(str.compare(str,"BYBYBBY",Qt::CaseSensitive)==0)
//                 break;
//          }
//          // ui->textBrowser->append("BYBYBBY ok...");
//            testWidget->insertDebugInfo("BYBYBBY ok...");
//        // readTimer->start(1000);
//        //接受到cs4后发送识别字组1,2,3
//            //并对应接受ck1，2，3（验证正确后进行下一个发送）

//         send_recongnise_byteArray();
//        //发送结束识别RQRQRQ
//           QString s3("RQRQRQ");
//          // myCom->write(s3.toAscii());
//          //ui->textBrowser->append(s3);
//        testWidget->insertDebugInfo(s3);
//            //等待接受cs1,2 jiaoti
//        //发送字组1abc,2def,...

//           send_info_byteArray();
//}

void MainWindow::calc_IS_IK(QString strSelfMMSI,QString strOtherMMSI)
{
     m_strSelf=strSelfMMSI;
     m_strCalled=strOtherMMSI;

    if(strOtherMMSI.size() >5)
         isFourMMSI=0;   //9 wei ma
    else
         isFourMMSI=1;   //4 or 5 wei ma

    int size1=m_strSelf.size();
    int size2=m_strCalled.size();


    list_IS.clear();list_CK.clear();list_IS_SELF.clear(); //hu jiao qian init

    if(size1==9)
      init_nine_MMSI(0);  //本台MMSI -》IS-》IK
    else
        init_four_MMSI(0); //add

    if(this->isCallRadio==1)   //当本台是主台时，才需要计算对方台的呼叫码，当本台为副台时，不需要计算。
    {
    if(size2==9)
       init_nine_MMSI(1);  //对方台MMSI -》IS-》IK
    else
        init_four_MMSI(1); //add
    }

}
QList<QString> numToIS(int dec,int size)
{
    QList<QString> listStr;
    GlobalArray globalAry;
    int tempDec;
    if(size==4)
    {
        tempDec=dec;
        int i=4;
        while(i--)
        {
            listStr.prepend(globalAry.mapFourMMSI.value(tempDec%10));
            tempDec=tempDec/10;
        }
    }else if(size==5)
    {
        int column=dec/10000;
        QString str=globalAry.mapFiveToFour.value(column);
        int i=4;
        tempDec=dec%10000;
        while(i--)   //dao xu cha ru,4 ci shu ju
        {
            if(QString::compare(str.at(i),"0")==0)
                listStr.prepend(globalAry.mapFourMMSI.value(tempDec%10));
            else if(QString::compare(str.at(i),"1")==0)
                listStr.prepend(globalAry.mapFiveMMSIAdd.value(tempDec%10));
            tempDec=tempDec/10;
        }
    }
     return listStr;
}
void MainWindow::init_four_MMSI(int flag)
{
    int flag0=flag;
    bool ok;

    if(flag0==0)    // 主台 list_is
        {
        QString str=m_strSelf;
        qlonglong dec=str.toLongLong(&ok,10) ;
        int size=str.size();

        list_IS_SELF=numToIS(dec,size);
        }
    else
        {
        QString str=m_strCalled;
        qlonglong dec=str.toLongLong(&ok,10);
        int size=str.size();

        list_IS=numToIS(dec,size);
        }    //副台 list_is

}

 void MainWindow::send_called_IS_oneAndTwoAndThree()
 {
     //Timer0->start();                  //450 ms timeout
 }
void MainWindow::on_buttonToCall_clicked()
{

}
void MainWindow::on_sendCallCode_callRadio(bool b)
{
    QString strCallType=CallClass::get()->getCallInfo()->getCallType();

    bool isARQType=false;
    if ( strCallType.compare("ARQ") == 0)
        isARQType=true;

    qDebug()<<"connect ok"<<isCallRadio<<b<<strCallType<<CallClass::get()->getIsCall();

    if( CallClass::get()->getIsCall()==true && b == true && isARQType ==true)     //主台调谐success，发送呼叫码,建连成功转入通信界面
    {
             /*******呼叫台标记*********************************/
             isCallRadio=1;
             /****************开启计时器，发射呼叫字组1和呼叫字组2,3*******************/
//             send_flow_state=1;       qDebug()<<"Thread is runing?"<<g_mainTimer.isRunning();
//             g_mainTimer.start(QThread::HighestPriority);        Timer0->start(NBDPTIMER450);

    }
    else if(CallClass::get()->getIsCall()==false && b == true && isARQType ==true) //副调谐success，进入接受呼叫码程序
    {
           calledRadioStart=1;reDirect=0;
           /****************开启计时器，发射呼叫字组1和呼叫字组2,3*******************/
//           send_flow_state=1; this->isCallRadio=0; qDebug()<<" called";
//         g_mainTimer.start(QThread::HighestPriority);  Timer0->start(NBDPTIMER450);

    }
}
void MainWindow::slot_received_CS4()
{

    if(reDirect==0)
      { Timer0->stop(); Timer0Count=0; }
    else
      { Timer5->stop(); Timer5Count=0; }

    Timer2_count();  
}
 void MainWindow::slot_received_CS5()
 {
     Timer0->stop();
     calledRadio_changetoCommuOver16();
 }
 bool isInfoAry(QString strCS0)
 {
     QString str=strCS0;
     if(str.contains("ID")==true)
         return true;
     else
         return false;

 }
  int MainWindow::strRemapIntger(QString str)
  {
      int intCS=0;
      qDebug()<<str;
      QString strCS;
      strCS=str;
      if(strCS.compare(CS1)==0)
          intCS=IntCS1;
      else if(strCS.compare(CS2)==0)
          intCS=IntCS2;
      else if(strCS.compare(CS3)==0)
          intCS=IntCS3;
      else if(strCS.compare(CS4)==0)
          intCS=IntCS4;
//      else if(strCS.compare(CS5)==0)
//          intCS=IntCS5;
      else if(strCS.compare(RQ)==0)
          intCS=IntRQ;
      else if(strCS.compare(beta)==0)
          intCS=Intbeta;
      else if(strCS.compare(alpha)==0)
          intCS=Intalpha;
      else if(strCS.compare(RQ_RQ_RQ)==0)
          intCS=IntRQ_RQ_RQ;
      else if(strCS.compare(betaAlphaBeta)==0)
          intCS=IntbetaAlphaBeta;
      else if(isCallRadio==1  && isFourMMSI==0 && strCS.compare(strCS,list_CK.at(0))==0) // zhu 9
                 intCS=list_CK1;
      else if(isCallRadio==1  && isFourMMSI==0  && strCS.compare(strCS,list_CK.at(1))==0)
                  intCS=list_CK2;
      else if(isCallRadio==1   && isFourMMSI==0 && strCS.compare(strCS,list_CK.at(2))==0)
                  intCS=list_CK3;
      else if(isCallRadio ==0 && isFourMMSI==1 && strCS.compare(strCS,list_IS_SELF.at(2)+list_IS_SELF.at(3)+QString("RQ"))==0 )   // 4 MMSI call 2
                  intCS=receiveRadioCall2_FourMMSI;
      else if(isCallRadio ==0 && strCS.compare(strCS,list_IS_SELF.at(0)+QString("RQ")+list_IS_SELF.at(1))==0 )   // call 1 (4 and 7)
                  intCS=receiveRadioCall1;
      else if(isCallRadio ==0  && isFourMMSI==0 && strCS.compare(strCS,QString("RQ")+list_IS_SELF.at(2)+list_IS_SELF.at(3) )==0 )   // call 2
                  intCS=receiveRadioCall2;
      else if(isCallRadio ==0 && isFourMMSI==0 && strCS.compare(strCS,list_IS_SELF.at(4)+list_IS_SELF.at(5)+list_IS_SELF.at(6))==0 )  // call 3
                 { intCS=receiveRadioCall3;   }
      else if(isCallRadio==0  && isFourMMSI==0 && str.indexOf(alpha,0)==1  && strCS.contains(alphaAlphaAlpha)==false) //identify1
                  intCS=receiveRadioIdentify1;
      else if(isCallRadio==0  && isFourMMSI==0 && str.indexOf(alpha,0)==0 && strCS.contains(alphaAlphaAlpha)==false) //identify2
                  intCS=receiveRadioIdentify2;
//    else if(isCallRadio==0 &&  )) 
//                intCS=receiveRadioIdentify3;
      else if(strCS.contains(alphaAlphaAlpha)==true)
                  intCS=IntalphaAlphaAlpha;
      else if(isInfoAry(strCS)==true)
                  intCS=IntInfo1;
      else
          qDebug()<<"intCS=0  "<<strCS;

      qDebug()<<"intCS is:"<<intCS;
      return intCS;

  }
  void MainWindow::calledRadio_flow(QString str0)
  {
       QString str=str0;
       int index0=0,index1=1,index2=2;
       int sevenOrFour=(list_IS_SELF.length()==7)?1:0;

       index0=0;
if( calledRadioStart==1 && isCallRadio==0 && reDirect==0 )  //被接受台chushi zhuang tai
{
       index1=1;
       switch(strRemapIntger(str))
      {
       case receiveRadioCall1:   //received calledCharAry1---(1,2,3)
           calledRadioStart= 0;
           if(reversedOrder==1 && sevenOrFour==1)  //7wei ,转入识别
                {
                  calledRadioWaitForIdentify1=1;   reversedOrder=0;
                  send_flow_state = 2;   sendTimerStr(CS4,1);
                  g_mainTimer.start(QThread::HighestPriority);
                  Timer2->start(NBDPTIMER450);     Timer2Count=0;
                }
           else if(reversedOrder==1 && sevenOrFour==0) //4wei  ，转入接受1
                 {  calledRadioWaitForInfo1=1;
                    Timer3->start(NBDPTIMER450); Timer3Count=0;
                    reversedOrder=0;  index2=1;
                 }
           else
                 {calledRadioWaitForCalledCharAry2=1;index2=2;}
           break;
       case receiveRadioCall2:  //received calledCharAry2--(2,3,1)
            calledRadioStart=0;
               calledRadioWaitForCalledCharAry3=1; reversedOrder=1;index2=3;
            break;
       case receiveRadioCall2_FourMMSI:
           calledRadioStart=1; reversedOrder=1;index2=4;
           break;
       default:
           index2=5;
           break;
      }       
       qDebug()<<QString("%1-%2-%3").arg(index0).arg(index1).arg(index2);

}
else if(calledRadioWaitForCalledCharAry2==1 && isCallRadio==0  )
      {
       index1=2;
       switch(strRemapIntger(str))
        {
          case receiveRadioCall2:
                   calledRadioWaitForCalledCharAry2=0;  calledRadioWaitForCalledCharAry3=1;     index2=0;
              break;
          case receiveRadioCall2_FourMMSI:       //4wei,zhuan dao 9
                 calledRadioWaitForCalledCharAry2=0;    calledRadioWaitForInfo1=1;
                   Timer3->start(NBDPTIMER450); Timer3Count=0;
                   sendTimerStr(CS1,1); receive_display(tr("call2:4 wei %1").arg(str));index2=1;
                break;
          default:
           break;
         }
         qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
      }
else if(calledRadioWaitForCalledCharAry3==1 && isCallRadio==0)
   {   
     index1=3;
       switch(strRemapIntger(str))
      {
       case  receiveRadioCall3:
            calledRadioWaitForCalledCharAry3=0;

            if( reversedOrder == 0 )
            {
            calledRadioWaitForIdentify1=1;
            send_flow_state = 2;   sendTimerStr(CS4,1);
            g_mainTimer.start(QThread::HighestPriority);
            Timer2->start(NBDPTIMER450);     Timer2Count=0;
            }
            else if(  reversedOrder == 1 )
            {
                 calledRadioStart = 1;
            }
            index2=0;
       break;
       default:  //ready
          calledRadio_changetoReady();  index2=1;
       break;
       }
    }
else  if(calledRadioWaitForIdentify1==1 && isCallRadio==0   )
     {
       index1=4; ReceIdent = 0;
       switch (strRemapIntger(str))
       {
       case IntCommuOver:
           sendTimerStr(CS1,1);    calledRadioWaitForIdentify1=0; ReceIdent =-1;
           Timer2->stop(); Timer2Count =0; calledRadio_changetoReady();
           break;
       case receiveRadioIdentify1:
           calledRadioWaitForIdentify1=0;
           calledRadio_afterSendCK1=1;         Timer2Count = 1;  ReceIdent =-1;
           break;
       default:
                                                                 ReceIdent = 0;
           break;
        }
       qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
     }
else if(calledRadio_afterSendCK1==1 && isCallRadio==0   )
      {
         index1=5;  ReceIdent = 0;
       switch(strRemapIntger(str))
       {
       case IntCommuOver:     // comm end;
              sendTimerStr(CS1,1);           calledRadio_afterSendCK1=0;
              Timer2->stop();Timer2Count=0;  calledRadio_changetoReady();index2=0; ReceIdent = -1;
           break;
       case receiveRadioIdentify2:
              calledRadio_afterSendCK1=0;
              calledRadio_afterSendCK2=1;   Timer2Count = 1;                       ReceIdent = -1;
           break;
       case receiveRadioIdentify1:
                                                                                   ReceIdent = 1;
           break;
       default:                                  // receive error
               {                         index2=4;                                 ReceIdent = 0;}
       break;
       }
         qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
      }
else if(calledRadio_afterSendCK2==1 && isCallRadio ==0  )
       {
       index1=6; ReceIdent = 0;
       switch(strRemapIntger(str))
        {
           case IntCommuOver:
                sendTimerStr(CS1,1);           Timer2->stop(); Timer2Count=0;
                calledRadio_afterSendCK2=0;    calledRadio_changetoReady();        ReceIdent = -1;
                break;
           case receiveRadioIdentify2:
                                                                                   ReceIdent = 2;
                break;
           default:
          if(QString(str).length()==3)                      // Identify3
           {
               Timer2Count=1;       calledRadio_afterSendCK2=0;
               calledRadioWaitForIdentifyOverChar=1;  index2=3;                  ReceIdent = -1;
           }
           else                                            // receive error
           {                           index2=4;                                 ReceIdent = -1;}
               break;
        }        
         qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
       }
else  if(calledRadioWaitForIdentifyOverChar==1 && isCallRadio==0  )
       {
       index1=7;  ReceIdent =0;
       switch(strRemapIntger(str))
       {
       case IntRQ_RQ_RQ:
          calledRadioWaitForIdentifyOverChar=0;    send_flow_state = 3; //进入通信流程

          Timer2->stop();             Timer2Count=0;
          Timer3->start(NBDPTIMER450);Timer3Count=0;
          calledRadioWaitForInfo1=1;                ReceIdent = -1;

          Transit::get()->EmitSignalConnectingResult(true); // connect success!
          break;
       case IntCommuOver:
             sendTimerStr(CS1,1);  calledRadioWaitForIdentifyOverChar=0;
             calledRadio_changetoReady();
           break;
       default:         
            if(QString(str).length()==3)                   //identify 3
           {     index2=5;                                        ReceIdent = 3;}
           else                                            //receive error
           {     index2=6;                                        ReceIdent = 0;}

           break;
       }       
         qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
       }
else if(calledRadioWaitForInfo1==1 && isCallRadio==0 )
       {
       index1=8;  ReceIdent = 0 ;
       switch(strRemapIntger(str))
        {
       case IntCommuOver:              // goto   ready
            sendTimerStr(CS2,1);           Timer2->stop(); Timer2Count = 0;
            calledRadio_changetoReady();   index2=1; calledRadioWaitForInfo1=0;  ReceIdent = -1 ;
          break;
       case IntInfo1:                  // receive info1            
            if( calledRadio_receivedInfo1(str)==1 )
              {  calledRadioWaitForInfo1 = 0; calledRadioWaitForInfo2=1; Timer3Count=1;   index2=5;  ReceIdent = -1 ;  }
            else                      //go to 13,include +?zhuan xiang biao zhi
               { calledRadioWaitForInfo1 = 0;  calledRadio_afterSendCS3=1; Timer3Count=1; index2=6;   ReceIdent = -1 ; }
          break;
       case IntRQ_RQ_RQ:
       default:                          // receive error        
             break;
        }       
         qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
       }
else if(calledRadioWaitForInfo2==1 && isCallRadio==0  )
       {
       index1=9;  ReceIdent =0 ;
       switch(strRemapIntger(str))
        {
       case IntCommuOver:
             sendTimerStr(CS1,1);   calledRadioWaitForInfo2=0;
             Timer2->stop();  Timer2Count =0;        index2=1;
             calledRadio_changetoReady();       ReceIdent = -1 ;
          break;
       case IntInfo1:                    //     receive info2
           if( calledRadio_receivedInfo1(str)==1 )
           { calledRadioWaitForInfo2=0; calledRadioWaitForInfo1=1;  Timer3Count=0;  ReceIdent = -1 ;index2=5;}
           else                          // go to 13
           {  calledRadioWaitForInfo2=0; calledRadio_afterSendCS3=1; Timer3Count=0; ReceIdent = -1 ; index2=6;}
           break;
       case IntRQ_RQ_RQ:
       default:                          // receive error         
           break;
        }      
         qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
       }
else if( calledRadio_afterSendCS3==1 && isCallRadio ==0  )
      {
       index1=10;   ReceIdent = 0 ;
       switch (strRemapIntger(str)) {
       case IntbetaAlphaBeta:
           calledRadio_afterSendCS3=0;       Timer3Count=1;
           calledRadio_receiveToSend=1;      ReceIdent = -1 ;
           break;
       case IntRQ_RQ_RQ:
       default:
       break;
       }    
         qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
      }
else if( calledRadio_receiveToSend==1 && isCallRadio ==0  )
       {
        index1=9;    ReceIdent = 0 ;
        switch(strRemapIntger(str))
        {
        case IntCS2:
            calledRadio_receiveToSend=0;  calledRadio_waitForInfo2Back=1; sendSwitchInfo2=1;index2=1;   ReceIdent = 2 ; Timer3Count=1;
        break;
        case IntCS1:
           calledRadio_receiveToSend=0;   calledRadio_waitForInfo1Back=1; sendSwitchInfo1=1;index2=2; ReceIdent = 1   ; Timer3Count=1;
            break;
        case IntCS3:
           calledRadio_receiveToSend=0;     calledRadio_waitForSendChangeToReceiveBack=1; index2=3; ReceIdent =3 ; Timer3Count=1;
        break;
        default:
        break;
        }
          qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
       }
else if(calledRadio_waitForInfo1Back==1 && isCallRadio==0  )
      {
       index1=11; ReceIdent = 0 ;
       switch(strRemapIntger(str))
       {
       case IntCS2:
          calledRadio_waitForInfo1Back= 0;  sendSwitchInfo1=0;
          calledRadio_waitForInfo2Back= 1;  sendSwitchInfo2=1;                ReceIdent = 2 ; index2=1;
          break;
       case IntCS1:
            index2=2;                                                         ReceIdent = 1 ;
          break;
       case IntCS3:
            calledRadio_waitForInfo1Back= 0;  sendSwitchInfo1=0;
            calledRadio_waitForSendChangeToReceiveBack=1;                     ReceIdent = 3 ;index2=3;
          break;
       default:         
          break;
       }
         qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
      }
else  if(calledRadio_waitForInfo2Back==1 && isCallRadio==0   )
     {
       index1=12; ReceIdent = 0;
       switch(strRemapIntger(str))
       {
       case IntCS1:
             calledRadio_waitForInfo2Back=0; sendSwitchInfo2=0;
             calledRadio_waitForInfo1Back=1; sendSwitchInfo1=1;
             Timer3Count=1;           index2=1;  ReceIdent = 1;
          break;
       case IntCS2:
                                      index2=2;  ReceIdent = 2;
          break;
       case IntCS3:
            calledRadio_waitForInfo2Back=0;                 sendSwitchInfo2=0;
            calledRadio_waitForSendChangeToReceiveBack=1;   Timer3Count=1;
         break;
       default:           
         break;
       }   
         qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
     }
else  if(calledRadio_after14SendCommuOver==1 && isCallRadio==0  )
      {
       index1=13;
       switch(strRemapIntger(str))
         {
       case IntCS1:  
           break;
       case IntCS2:
           Timer4->stop();Timer4Count=0;   calledRadio_after14SendCommuOver=0;
           calledRadio_changetoReady();
           break;
       default:  
           break;
         }

         qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
      }
else if( calledRadio_after16SendCommuOver==1 && isCallRadio==0   )
      {
       index1=14;
       switch(strRemapIntger(str))
        {
       case IntCS2:
           sendTimerStr(alphaAlphaAlpha,3);  index2=1;
          break;
       case IntCS1:
           Timer4->stop(); Timer4Count=0;
           if(Timer5Count==0)
           {calledRadio_changetoReady(); index2=2;}
           else if(Timer5Count!=0)
           {calledRadio_changetoRemap(); index2=3;}
           break;
       default:
           if(isTimer4_timerOut4()==1 && Timer5Count==0)
           {calledRadio_changetoReady(); index2=4;}
           else if(isTimer4_timerOut4()==1 && Timer5Count!=0)
           {calledRadio_changetoRemap(); index2=5;}
           else
            { calledRadio_after16SendCommuOver=1; sendTimerStr(alphaAlphaAlpha,3);
              send_display(alphaAlphaAlpha); index2=6;}
       break;
        }

        qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
      }
      else if(calledRadio_waitForSendChangeToReceiveBack==1 && isCallRadio ==0   )    //20
       {
            index1=15; calledRadio_waitForSendChangeToReceiveBack=0;
       switch(strRemapIntger(str))
          {
             case IntRQ:         // goto 18 same as 9                
                if(calledRadio_gotoCommu()==1)
                {
                    calledRadioWaitForInfo1=1;   //go to 9
                    index2=1;
                }
                else
                {
                    calledRadio_afterSendCS3=1;   //go to 13
                    index2=2;
                }
             break;
             case IntCS3:
                 {
                         calledRadio_waitForSendChangeToReceiveBack=1;
                         calledRadio_changeToReceiveAgain();  index2=3;
                 }
             break;
             default:
           if(isTimer3_timerOut32()==1)
             {calledRadio_changetoRemap();index2=4;}
           else
             {  calledRadio_waitForSendChangeToReceiveBack=1;  sendTimerStr(RQ_RQ_RQ,3);
               send_display(RQ_RQ_RQ); index2=5; }
             break;
          }

         qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
       }
       else if(waitForCall_redirect==1 && isCallRadio==0  && isFourMMSI==0 )         // 9 MMSI receive redirect (call)
       {
           index1=16;  waitForCall_redirect=0;
           switch(strRemapIntger(str))
            {
           case receiveRadioCall1:    // CALL 1,2,3 路线
              if(waitForCall1_call1Lose_redirect==1)
                 {   waitForIdentify_redirect=1;  index2=3;}
                else
                 { waitForCall_redirect=2;  index2=1;}
                break;
           case receiveRadioCall2:     // CALL 2,3,1 路线 （call1 丢失时运行的分支）
                waitForCall_redirect=3; waitForCall1_call1Lose_redirect=1; index2=2;
                 break;
           default:
               if(isTimer5_timerOut32()==1)
               { calledRadio_changetoReady();index2=4; }
               else
                { waitForCall_redirect=1;  index2=3; }
           break;
            }
            qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);

       }
       else if(waitForCall_redirect==2 && isCallRadio==0  && isFourMMSI==0 )
       {
           index1=17;  waitForCall_redirect=0;
           switch(strRemapIntger(str))
            {
           case receiveRadioCall2:
                waitForCall_redirect=3;  index2=1;
                break;
           default:
               if(isTimer5_timerOut32()==1)
               { calledRadio_changetoReady();index2=2; }
                else
               { waitForCall_redirect=1;  index2=3; }
           break;
            }
            qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);

       }
       else if(waitForCall_redirect==3 && isCallRadio==0  && isFourMMSI==0 )
       {
           index1=18;  waitForCall_redirect=0;
           switch(strRemapIntger(str))
            {
           case receiveRadioCall3:
               if(waitForCall1_call1Lose_redirect==1)
                 { waitForCall_redirect=1; index2=1;}
                else
                  {  waitForIdentify_redirect=1;
                   Timer5->stop(); Timer5Count=0; index2=2;}
                break;
           default:
               if(isTimer5_timerOut32()==1)
               { calledRadio_changetoReady();index2=3; }
               else
                { waitForCall_redirect=1;  index2=4;}
           break;
            }
            qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);

       }
       else if(waitForIdentify_redirect==1 && isCallRadio==0 && isFourMMSI==0)       // 9 MMSI receive redirect   (identify)
        {
           index1=19;  waitForIdentify_redirect=0;
           switch(strRemapIntger(str))
            {
           case IntCommuOver:  //通信结束
                sendTimerStr(CS1,1); waitForCall_redirect=1;
                Timer2->stop(); Timer2Count=0;  Timer5->start(NBDPTIMER450); index2=1;
                break;
           default:
               if(isTimer2_timerOut32()==1)
               {  calledRadio_changetoReady();index2=2;}
               else if(str.indexOf(alpha,0)==1) //识别1
                   { calledRadio_afterReceivedIdentifyCharAry1(); waitForIdentify_redirect=2;
                     Timer2Count=0; index2=3; }
               else  //接受异常
                   {  waitForIdentify_redirect=1;index2=4;}
           break;
            }
            qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
        }
       else if(waitForIdentify_redirect==2 && isCallRadio==0  && isFourMMSI==0 )
        {
           index1=20;  waitForIdentify_redirect=0;
           switch(strRemapIntger(str))
            {
           case IntCommuOver:  //通信结束
                sendTimerStr(CS1,1); waitForCall_redirect=1;
                 Timer2->stop(); Timer2Count=0;  Timer5->start(NBDPTIMER450); index2=1;
                break;
           case receiveRadioIdentify1:
                   sendTimerStr(list_CK.at(0),1); waitForIdentify_redirect=2; index2=2;
               break;
           case receiveRadioIdentify2:
                   sendTimerStr(list_CK.at(1),1); waitForIdentify_redirect=3; index2=3;
               break;
          default:  //接受异常
               if(isTimer2_timerOut32()==1)
               {  calledRadio_changetoReady();index2=4;}
               else
               { sendTimerStr(RQ,1);  waitForIdentify_redirect=2;index2=5;}
              break;
            }
            qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
        }
       else if(waitForIdentify_redirect==3 && isCallRadio==0  && isFourMMSI==0 )
        {
           index1=21;  waitForIdentify_redirect=0;
           switch(strRemapIntger(str))
            {
           case IntCommuOver:  //通信结束
                sendTimerStr(CS1,1); waitForCall_redirect=1;
                 Timer2->stop(); Timer2Count=0;  Timer5->start(NBDPTIMER450); index2=1;
                break;
           case receiveRadioIdentify2:
                   sendTimerStr(list_CK.at(1),1); waitForIdentify_redirect=3; index2=2;
               break;
          default:
               if(isTimer2_timerOut32()==1)
               {  calledRadio_changetoReady();index2=3;}
               else if(str.length()==3)
               { sendTimerStr(list_CK.at(2),1); waitForIdentifyOver_redirect=1;index2=4;}
               else  //接受异常
               { sendTimerStr(RQ,1);  waitForIdentify_redirect=2;index2=5;}
              break;
            }
            qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
        }
      else if(waitForIdentifyOver_redirect==1 && isCallRadio==0  && isFourMMSI==0 )
       {
           index1=22; waitForIdentifyOver_redirect=0;
           switch(strRemapIntger(str))
            {
           case IntCommuOver:  //重定向收到通信结束符，继续重定向
                sendTimerStr(CS1,1); waitForCall_redirect=1;
                 Timer2->stop(); Timer2Count=0;  Timer5->start(NBDPTIMER450);index2=1;
                break;
           case IntRQ_RQ_RQ:
                   Timer2->stop(); Timer2Count=0;Timer5->stop(); Timer5Count=0;
                   if(redirect_waitInfo1==1)
                    {redirect_waitInfo1=0; calledRadioWaitForInfo1=1;sendTimerStr(CS1,3);  send_display(CS1);
                     Timer3->start(NBDPTIMER450);Timer3Count=0; index2=2;}
                   else if(redirect_waitInfo1==2)
                    {redirect_waitInfo1=0; calledRadioWaitForInfo2=1;sendTimerStr(CS2,3);   send_display(CS2);
                     Timer3->start(NBDPTIMER450);Timer3Count=0; index2=3;}
               break;
          default:
               if(isTimer2_timerOut32()==1)
               {  calledRadio_changetoReady();index2=4;}
               else if(str.length()==3)
               { sendTimerStr(list_CK.at(2),1); waitForIdentifyOver_redirect=1;index2=5;}
               else  //接受异常
               { sendTimerStr(RQ,1); waitForIdentifyOver_redirect=1;index2=6;}
              break;
            }
            qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
       }
       else if(waitForCall_FourMMSI_reDirect==1 && isCallRadio==0  && isFourMMSI==1 )     // 4 MMSI receive redirect
      {
           index1=23; waitForCall_FourMMSI_reDirect=0;
           switch(strRemapIntger(str))
            {
           case receiveRadioCall1:  // 呼叫1，2 路线
               if(FourMMSI_redirect_called_2and1Road==1)
                  {  FourMMSI_redirect_called_2and1Road=0; if( calledRadio_gotoCommu()==1)       { calledRadioWaitForInfo1=1;    index2=1; }     else           index2=2;}
               else
                  { waitForCall_FourMMSI_reDirect=2;   index2=3; }
                break;
           case receiveRadioCall2_FourMMSI:    // 呼叫2，1路线
                  waitForCall_FourMMSI_reDirect=1; index2=4;
                  FourMMSI_redirect_called_2and1Road=1;
               break;
          default:
               if(isTimer5_timerOut32()==1)
                  {calledRadio_changetoReady();index2=5; }
               else
                  { waitForCall_FourMMSI_reDirect=1; index2=6;}
              break;
            }
            qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
      }
       else if(waitForCall_FourMMSI_reDirect==2 && isCallRadio==0   && isFourMMSI==1 )
      {
           index1=24; waitForCall_FourMMSI_reDirect=0;
           switch(strRemapIntger(str))
            {
           case receiveRadioCall2_FourMMSI:
                Timer5->stop();Timer5Count=0;
               if( redirect_waitInfo1==1) //goto 9(B4)
                  { redirect_waitInfo1=0;calledRadioWaitForInfo1=1; Timer3->start(NBDPTIMER450);Timer3Count=0;   index2=1; }
               else  if(redirect_waitInfo1==2)                          //goto 17 dai ding
                  { redirect_waitInfo1=0;calledRadioWaitForInfo2=1; Timer3->start(NBDPTIMER450);Timer3Count=0;  index2=2; }
               break;
           default:
               if(isTimer5_timerOut32()==1)
               {calledRadio_changetoReady();index2=3; }
               else
                { waitForCall_FourMMSI_reDirect=1; index2=4;}
              break;
            }
             qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
       }
  }
   void MainWindow::received_notExpected_CalledArrayAfter2_FourMMSI()
   {
       //发射呼叫字组1，改变状态
   QString s1=list_IS.at(0)+"RQ"+list_IS.at(1);
   sendTimerStr(s1,3);    send_display(s1);
   }
    void MainWindow::received_notExpected_CalledArrayAfter1_FourMMSI()
    {
        //发射呼叫字组2，改变状态
           QString s2=list_IS.at(2)+list_IS.at(3)+"RQ";
          sendTimerStr(s2,3);    send_display(s2);
    }
    void MainWindow::callRadio_changeToReceive_FourMMSI()
    {
           sendTimerStr(betaAlphaBeta,3);   send_display(betaAlphaBeta);
    }
    int MainWindow::callRadio_receive_FourMMSI()
    {
        if(receivedInfo.contains("+?")==true)  //转入13 ，A11-A12
             return 0;
        else
        {        
        if(sendInfo.compare(sendInfo,CS3)==0)   //转入13 ，A11-A12
            return 0;
        else
        {
             sendTimerStr(CS2,1);  send_display(CS2);
             return 1;
         }
        }
    }
  /************************** 4位码 呼叫台 **********************************************************/

   void MainWindow::callRadio_flow_fourMMSI(QString str0)
   {
       QString str=str0;
       int index0=0,index1=1,index2=2;
       index0=0;

       /*****************************主台发送完呼叫1 和呼叫2，接受到的字符************************/
       if(sendCalledArrayAfter_FourMMSI==2 && isCallRadio==1)
       {
           index1=1; sendCalledArrayAfter_FourMMSI=0;
           switch(strRemapIntger(str)){

           case IntCS1:
                      Timer0->stop(); Timer0Count=0;
                      Timer3->start(NBDPTIMER450);Timer3Count=0;
                      sendSwitchInfo1=1;  index2=1;
                      afterSendInfo1CallRadio_FourMMSI=1;

                      Transit::get()->EmitSignalConnectingResult(true); // connect success!
               break;
           case IntCS2:
                      Timer0->stop(); Timer0Count=0;
                      Timer3->start(NBDPTIMER450);Timer3Count=0;
                      sendSwitchInfo2=1; index2=2;
               break;
           case IntCS3:

                      callRadio_changetoReady();index2=3;
               break;
           default:
               if(isTimer0_timerOut128()==1)
                  {callRadio_changetoReady();index2=4;}
               else
                  { received_notExpected_CalledArrayAfter2_FourMMSI();  sendCalledArrayAfter_FourMMSI=1; index2=5;}
               break;
           }
           qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
       }
       else if(sendCalledArrayAfter_FourMMSI==1 && isCallRadio==1)
       {
           index1=2;  sendCalledArrayAfter_FourMMSI=0;
           switch(strRemapIntger(str)){

           case IntCS1:
                      Timer0->stop(); Timer0Count=0;
                      Timer3->start(NBDPTIMER450);Timer3Count=0;
                      sendSwitchInfo1=1;  index2=1;

                      afterSendInfo1CallRadio_FourMMSI=1;
                      Transit::get()->EmitSignalConnectingResult(true); // connect success!
               break;
           case IntCS2:
                      Timer0->stop(); Timer0Count=0;
                      Timer3->start(NBDPTIMER450);Timer3Count=0;
                      sendSwitchInfo2=1; index2=2;
               break;
           case IntCS3:

                      callRadio_changetoReady(); index2=3;
               break;
           default:
               if(isTimer0_timerOut128()==1)
                  {callRadio_changetoReady();index2=4;}
                else
                  { received_notExpected_CalledArrayAfter1_FourMMSI();  sendCalledArrayAfter_FourMMSI=2; index2=5; }
               break;
           }
           qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
       }
       else if( afterSendInfo1CallRadio_FourMMSI==1 && isCallRadio==1)
       {
           index1=3; afterSendInfo1CallRadio_FourMMSI=0;
           switch(strRemapIntger(str)){

           case IntCS1:                         //重复发送
                      sendTimerStr(sendInfo,3); send_display(sendInfo);
                      afterSendInfo1CallRadio_FourMMSI=1;  index2=1;
               break;
           case IntCS2:                        //接受正常
                    sendSwitchInfo2=1; index2=2;
                    Timer3Count=0;
               break;
           case IntCS3:                             //转入20,发送转为接受                     
                      sendTimerStr(betaAlphaBeta,3); Timer3Count=0;
                      afterSendBetaAlphaBeta_FourMMSI=1; index2=3;
               break;
           default:
               if(isTimer3_timerOut32()==1)
                  { callRadio_changetoReady();Timer5->start(NBDPTIMER450); Timer0->start(NBDPTIMER450);}
               else
                  { afterSendInfo1CallRadio_FourMMSI=1;  sendTimerStr(RQ_RQ_RQ,3);  index2=4;}
               break;
           }
           qDebug()<<QString("%1%2%3,%4").arg(index0).arg(index1).arg(index2).arg(sendInfo);
       }
       else if(afterSendInfo2CallRadio_FourMMSI==1 && isCallRadio==1)
       {
           index1=4; afterSendInfo2CallRadio_FourMMSI=0;
           switch(strRemapIntger(str)){

           case IntCS2:                         //重复发送                      
                      afterSendInfo2CallRadio_FourMMSI=1;
                      sendTimerStr(sendInfo,3);  index2=1;
               break;
           case IntCS1:                        //接受正常
                     Timer3Count=0;
                    sendSwitchInfo1=1; index2=2;
               break;
           case IntCS3:                             //转入20,发送转为接受
                      sendTimerStr(betaAlphaBeta,3);
                     afterSendBetaAlphaBeta_FourMMSI=1; index2=3;
               break;
           default:
               if(isTimer3_timerOut32()==1)
                  { callRadio_changetoReady();Timer5->start(NBDPTIMER450); Timer0->start(NBDPTIMER450);}
               else
                  {  afterSendInfo2CallRadio_FourMMSI=1;  sendTimerStr(RQ_RQ_RQ,3);  index2=4;}
                     break;
           }
           qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
       }
       /***********************发送完转向字符**************************************************/

       else if(afterSendBetaAlphaBeta_FourMMSI==1 && isCallRadio==1) //转向
       {
           index1=5;afterSendBetaAlphaBeta_FourMMSI=0;
           switch(strRemapIntger(str)){
           case IntRQ_RQ_RQ:

                        Timer3Count=0;
                        if(callRadio_receive_FourMMSI()==1) // zhuan dao 18
                           {sendTimerStr(CS1,1);callRadio_waitForInfo1_FourMMSI=1 ; index2=1;}
                        else                              //zhuan dao 13  待定
                           {sendTimerStr(CS3,1); callRadio_changetoSend_FourMMSI=1; index2=2;}
               break;
           case IntCS3:  //重复发送
                     afterSendBetaAlphaBeta_FourMMSI=1;
                     callRadio_changeToReceive_FourMMSI();  index2=3;
               break;
           default:
               if(isTimer3_timerOut32()==1)
               {callRadio_changetoReady();Timer5->start(NBDPTIMER450); Timer0->start(NBDPTIMER450);}
               else
               {  afterSendBetaAlphaBeta_FourMMSI=1;sendTimerStr(RQ_RQ_RQ,3);  send_display(RQ_RQ_RQ);index2=4;}
               break;
           }
           qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
       }
       /**************************** receive info1*****************************/
       else if(callRadio_waitForInfo1_FourMMSI==1 && isCallRadio==1)
       {
           index1=6;  callRadio_waitForInfo1_FourMMSI=0;
           switch (strRemapIntger(str)) {
           case IntCommuOver:  //收到通信结束字符，待填充
           sendTimerStr(CS2,1);  Timer3->stop(); Timer3Count=0;
           send_display(CS2);index2=1;
           if(Timer5Count==0)
              callRadio_changetoReady();
           else
              callRadio_changetoRemap();
           break;
           case IntInfo1:       //受到信息字组1,(include "ID")
                 Timer3Count=0;
                 if(afterReceivedInfo1_callRadio(str0)==1)   //继续作为接收位置通信
                      { sendCS2_waitInfo2_callRadio_FourMMSI=1;index2=2;}
                else                                    //zhuan dao  13
                    {   sendTimerStr(CS3,1);
                        callRadio_changetoSend_FourMMSI=1; index2=3;}
           break;
           case IntRQ_RQ_RQ:
           default:                  //接收异常，要求重新发送
               if(isTimer3_timerOut32()==1)
               {callRadio_changetoReady();Timer5->start(NBDPTIMER450); Timer0->start(NBDPTIMER450); }
               else
                {callRadio_waitForInfo1_FourMMSI=1; sendTimerStr(CS1,1);  send_display(CS1);index2=4;}
           break;
          }
             ui->textBrowser->append(tr("1 after receive info1.\r\n"));
             qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
       }
       else if(sendCS2_waitInfo2_callRadio_FourMMSI==1 && isCallRadio==1)
       {
           index1=7;  sendCS2_waitInfo2_callRadio_FourMMSI=0;
           switch (strRemapIntger(str)) {
           case IntCommuOver:  //收到通信结束字符，待填充
                sendTimerStr(CS1,1);   send_display(CS1);
                index2=1;Timer3->stop(); Timer3Count=0;
                if(Timer5Count==0)
                   callRadio_changetoReady();
                else
                   callRadio_changetoRemap();
           break;
           case IntInfo1:       //受到信息字组1,(include "ID")
               Timer3Count=0;
           if(afterReceivedInfo1_callRadio(str0)==1) // 继续做为接受位置通信
              {sendTimerStr(CS1,1);callRadio_waitForInfo1_FourMMSI=1 ;
              index2=2;}
           else                              //zhuan dao 13  待定
              {sendTimerStr(CS3,1); callRadio_changetoSend_FourMMSI=1;
               index2=3;
              }
           break;
           case IntRQ_RQ_RQ:
           default:                  //接收异常，要求重新发送
             if(isTimer3_timerOut32()==1)
               {callRadio_changetoReady();Timer5->start(NBDPTIMER450); Timer0->start(NBDPTIMER450); index2=4;}
             else
                {sendCS2_waitInfo2_callRadio_FourMMSI=1;sendTimerStr(CS2,1);  send_display(CS2);index2=5;}
           break;
          }
             ui->textBrowser->append(tr("1 after receive info1.\r\n"));
             qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
       }
       else if(callRadio_changetoSend_FourMMSI==1 && isCallRadio==1 )
       {
           index1=8;  callRadio_changetoSend_FourMMSI=0;
           switch (strRemapIntger(str)) {
           case IntbetaAlphaBeta:  //收到转向回复
                sendTimerStr(RQ,1);   send_display(RQ);index2=1;
                Timer3Count=0;
               sendCalledArrayAfter_FourMMSI=2 ;          //转为发送
           break;
           case IntRQ_RQ_RQ:
           default:                  //接收异常，要求重新发送
               if(isTimer3_timerOut32()==1)
               {callRadio_changetoReady();Timer5->start(NBDPTIMER450); Timer0->start(NBDPTIMER450); index2=2;}
               else
                { callRadio_changetoSend_FourMMSI=1;sendTimerStr(CS3,1);  send_display(CS3);index2=3;}
            break;
          }
             ui->textBrowser->append(tr("1 after receive info1.\r\n"));
             qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
       }
       else if(afterSendCommuEnd14_callRadio_FourMMSI==1 && isCallRadio==1)
       {
           index1=9; afterSendCommuEnd14_callRadio_FourMMSI=0;
           switch(strRemapIntger(str)){
           case IntCS2:         // ready
               Timer4->stop();  Timer4Count=0;  index2=1;
               if(Timer5Count==0)
                callRadio_changetoReady();
               else
                  callRadio_changetoRemap();
               break;
           case  IntCS1:
           default:              
               {afterSendCommuEnd14_callRadio_FourMMSI=1; sendTimerStr(alphaAlphaAlpha,3); send_display(alphaAlphaAlpha); index2=2;}
               break;
           }
           qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
       }
       else if(afterSendCommuEnd1617_callRadio_FourMMSI==1 && isCallRadio==1)
       {
           index1=10; afterSendCommuEnd1617_callRadio_FourMMSI=0;
           switch(strRemapIntger(str)){
           case IntCS1:  // ready               
               Timer4->stop();  Timer4Count=0;  index2=1;
               if(Timer5Count==0)
                callRadio_changetoReady();
               else
                  callRadio_changetoRemap();
               break;
           case IntCS2:
           default:             
               { afterSendCommuEnd1617_callRadio_FourMMSI=1; sendTimerStr(alphaAlphaAlpha,3); send_display(alphaAlphaAlpha); index2=2;}
               break;
           }
             qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
       }
       else if(sendCalledArrayAfter_FourMMSI_reDirect==2 && isCallRadio==1)
       {
           index1=11; sendCalledArrayAfter_FourMMSI_reDirect=0;
           switch(strRemapIntger(str)){

           case IntCS1:
                      Timer5->stop(); Timer5Count=0;
                      Timer0->stop(); Timer0Count=0;
                      Timer3->start(NBDPTIMER450);   Timer3Count=0;
                      sendSwitchInfo1=1;  index2=1;
               break;
           case IntCS2:
                     Timer5->stop(); Timer5Count=0;
                     Timer0->stop(); Timer0Count=0;
                     Timer3->start(NBDPTIMER450);   Timer3Count=0;
                     sendSwitchInfo2=1; index2=2;
               break;
           case IntCS3:
               Timer5->stop(); Timer5Count=0;
               Timer3->start(NBDPTIMER450);   Timer3Count=0;
               sendTimerStr(betaAlphaBeta,3);
               afterSendBetaAlphaBeta_FourMMSI=1; index2=3;
               break;
           default:       // send call1
               if(isTimer5_timerOut32()==1)
               {callRadio_changetoReady();index2=4;}
                 else
               {
                   sendTimerStr(list_IS.at(0)+"RQ"+list_IS.at(1),3);
                  sendCalledArrayAfter_FourMMSI_reDirect=1; index2=5;
               }
               break;
           }
           qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);

       }
       else if(sendCalledArrayAfter_FourMMSI_reDirect==1 && isCallRadio==1)
       {
           index1=12; sendCalledArrayAfter_FourMMSI_reDirect=0;
           switch(strRemapIntger(str)){

           case IntCS1:
                     Timer5->stop(); Timer5Count=0;
                     Timer3->start(NBDPTIMER450);   Timer3Count=0;
                     sendSwitchInfo1=1;  index2=1;
               break;
           case IntCS2:
                     Timer5->stop(); Timer5Count=0;
                     Timer3->start(NBDPTIMER450);   Timer3Count=0;
                     sendSwitchInfo2=1; index2=2;
               break;
           case IntCS3:
                sendTimerStr(betaAlphaBeta,3);
                Timer5->stop(); Timer5Count=0;
                Timer3->start(NBDPTIMER450);   Timer3Count=0;
                afterSendBetaAlphaBeta_FourMMSI=1; index2=3;
               break;
           default:       // send call2
               if(isTimer5_timerOut32()==1)
               {callRadio_changetoReady();index2=4;}
               else
               {
               sendTimerStr(list_IS.at(2)+list_IS.at(3)+"RQ",3);
               sendCalledArrayAfter_FourMMSI_reDirect=2; index2=5;
               }
               break;
           }
           qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);

       }


   }
  void MainWindow::callRadio_flow(QString str0)
  {

      QString str=str0,str1,identify1,identify2,identify3;
      int index0=0,index1=1,index2=2;
      index0=0;
      /*****************主台发送完呼叫字组3后，接受到的字符**************************/
  if(sendCalledArrayAfter==3 && isCallRadio==1 )
  {
    index1=1;
      switch (strRemapIntger(str)) {
      case IntCS4:       //接受到信号CS4
          sendCalledArrayAfter=0;
          send_flow_state=2;   //0,no; (1,call)(2,recongnise)
          sendIdentifyArrayAfter=1;    index2=1;
          slot_received_CS4();
          break;
      case IntCS5:                    //接受到信号CS5
//           Timer0->stop();Timer0Count=0; sendCalledArrayAfter=0; afterSendCommuEnd1617_callRadio =1;
//           emit signal_received_CS5();              index2=2;
          break;
      default:
          break;
      }

     qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
  }
        /*****************主台发送完呼叫字组1后，接受到的字符**************************/
  else if(sendCalledArrayAfter==1 && isCallRadio==1 )  //zhu tai jie shou dao cs4
       {
         index1=2;
                                 switch (strRemapIntger(str)) {
                                 case IntCS4:    //接受到信号CS4
                                    sendCalledArrayAfter=0;
                                    send_flow_state=2;   //0,no; (1,call)(2,recongnise)
                                    sendIdentifyArrayAfter=1; index2=1;
                                    slot_received_CS4();
                                     break;
                                 case IntCS5:  //接受到信号CS5
//                                     Timer0->stop(); Timer0Count=0; sendCalledArrayAfter=0;index2=2;
//                                      emit signal_received_CS5();afterSendCommuEnd1617_callRadio =1;
                                     break;
                                 default:
                                     break;
                                 }

  qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
           }
           /*****************主台发送完呼叫字组2后，接受到的字符**************************/
  else if(sendCalledArrayAfter==2 && isCallRadio==1 )  //zhu tai jie shou dao cs4
                              {
          index1=3;
                         switch (strRemapIntger(str)) {
                                                        case IntCS4: //接受到信号CS4
                                                            sendCalledArrayAfter=0;
                                                            send_flow_state=2;   //0,no; (1,call)(2,recongnise)
                                                            sendIdentifyArrayAfter=1; index2=1;
                                                             integerCKVector.clear();
                                                             slot_received_CS4();
                                                            break;
                                                        case IntCS5:  //接受到信号CS5
//                                                             Timer0->stop();Timer0Count=0; sendCalledArrayAfter=0;index2=2;
//                                                             emit signal_received_CS5();afterSendCommuEnd1617_callRadio =1;
                                                            break;
                                                        default:
                                                            break;
                                         }
                 qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
                                  }
   /***********主台发送完识别字组1，接受到的字符******************/
  else if( sendIdentifyArrayAfter==1 &&   isCallRadio==1    )
   {
      index1=4;  int intCK=0;
                             switch (strRemapIntger(str)){
                            case list_CK1:
                                 Timer2Count=1;  sendIdentifyArrayAfter=0;              index2=1;
                                 sendIdentifyArrayAfter=2; integerCKVector.clear();
                                  break;
                             case list_CK2:
                             case list_CK3:
//                                 intCK=strRemapIntger(str);
//                                 if(isLastoneSameCK(1,intCK)==true)
//                                     {
//                                     Timer2->stop();Timer4->start(NBDPTIMER450);
//                                     sendTimerStr(alphaAlphaAlpha,3);send_display("alphaAlphaAlpha");
//                                     sendIdentifyArrayAfter=0; afterSendCommuEnd1617_callRadio =1 ; index2=2;
//                                     }
//                                 else if(integerCKVector.size()>=3)
//                                     {Timer2->stop();sendIdentifyArrayAfter=0;  callRadio_changetoReady();index2=3;}

                                 break;
                             case IntCS4:
                             case IntRQ:
                             default:
                                  break;
                               }
               qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
   }
/********************主台发送完识别字组2，接受到的字符*************************************************/
  else  if(sendIdentifyArrayAfter==2 && isCallRadio ==1)
   {
      index1=5; int intCK=0;
                             switch(strRemapIntger(str)){
                            case list_CK2:
                                  Timer2Count=1;   sendIdentifyArrayAfter=0;
                                  sendIdentifyArrayAfter=3; integerCKVector.clear();   index2=1;
                                  break;
                             case list_CK1:
                             case list_CK3:
//                                 intCK=strRemapIntger(str);
//                                 if(isLastoneSameCK(2,intCK)==true)
//                                     {
//                                     Timer2->stop();Timer4->start(NBDPTIMER450);
//                                     sendTimerStr(alphaAlphaAlpha,3);send_display("alphaAlphaAlpha");
//                                     sendIdentifyArrayAfter=0; afterSendCommuEnd1617_callRadio =1 ; index2=2;
//                                     }
//                                 else if(integerCKVector.size()>=3)
//                                     {Timer2->stop();sendIdentifyArrayAfter=0;  callRadio_changetoReady();index2=3;}

                                      break;
                             case IntRQ:
                             default:
                                  break;
                              }
               qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
}
   /********************主台发送完识别字组3，接受到的字符*************************************************/
  else if(sendIdentifyArrayAfter==3 && isCallRadio ==1)
   {
      index1=6; int intCK=0;

                             switch (strRemapIntger(str)) {
                             case list_CK3:          // receive CK3 ,same as at(2)
                             Timer2Count=1;  sendIdentifyArrayAfter=0;
                             sendIdentifyOverArrayAfter=1;   index2=1;
                             break;
                             case list_CK1:
                             case list_CK2:
//                                 intCK=strRemapIntger(str);
//                                 if(isLastoneSameCK(3,intCK)==true)
//                                     {
//                                     Timer2->stop();Timer4->start(NBDPTIMER450);
//                                     sendTimerStr(alphaAlphaAlpha,3);send_display("alphaAlphaAlpha");
//                                     sendIdentifyArrayAfter=0; afterSendCommuEnd1617_callRadio =1 ; index2=2;
//                                     }
//                                 else if(integerCKVector.size()>=3)
//                                     {Timer2->stop();sendIdentifyArrayAfter=0;  callRadio_changetoReady();index2=3;}

                                      break;
                             case IntRQ:
                             default:
                                 break;
                               }               
                  qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
}
   /********************主台发送完识别结束字符，接受到的字符*************************************************/
  else  if(sendIdentifyOverArrayAfter==1 && isCallRadio ==1)
   {
      index1=7;
                             switch(strRemapIntger(str))
     {
                             case IntCS1: //CS1-- 7
                              send_flow_state=3;   //0,no; (1,call)(2,recongnise)(3,send)
                              sendIdentifyOverArrayAfter=0;      index2=1;
                              sendSwitchInfo1=1;   afterSendInfo1CallRadio=1;
                              Timer2->stop();   Timer2Count=0;
                              Timer3_count();  sendInfo.clear();
                              Transit::get()->EmitSignalConnectingResult(true); // connect success!
                             break;
                             case IntCS3: //CS3 添加重定相函数--22
                               Timer2->stop();Timer2Count=0;    sendIdentifyOverArrayAfter=0;
                               afterSendBetaAlphaBeta=1; index2=2;
                               break;
                             case IntRQ:
                             default:                        
                                 break;
    }
                   qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
}
      /*****************主台发送完信息字组1，接受到的字符************/
  else if(afterSendInfo1CallRadio==1 && isCallRadio==1)
   {
      index1=8; ReceCS = 0;
                             switch (strRemapIntger(str)) {
                             case IntCS2:   // 接受到发送info1的回执
                             Timer3Count=1;
                             afterSendInfo1CallRadio=0; sendSwitchInfo1=0; index2=1;
                             afterSendInfo2CallRadio=1; sendSwitchInfo2=1; ReceCS = -1;
                             break;
                             case IntCS1:  //重新发送，等待接受，不改变状态标志
                                  index2=2; ReceCS =1;
                             break;
                             case IntCS3:  //改变收发方向，待添加
                              afterSendInfo1CallRadio=0;  sendSwitchInfo1=0; //callRadio_changeToReceive();  index2=3;//转入20
                              afterSendBetaAlphaBeta=1;  Timer3Count=1; ReceCS =3;
                             break;
                             default:  //接受异常，发送RQ RQ RQ后 等待接受
                                 ReceCS = 0;
                             break;
                        }

                   qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
}
    /*****************主台发送完信息字组2，接受到的字符************/
  else if(afterSendInfo2CallRadio==1 && isCallRadio ==1)
   {
      index1=9; ReceCS = 0;
                             switch(strRemapIntger(str))
                       {
                             case IntCS1:  //跳转到7-1
                              Timer3Count=1;    sendSwitchInfo2=0;    afterSendInfo2CallRadio=0;
                              index2=1;         sendSwitchInfo1=1;    afterSendInfo1CallRadio=1; ReceCS = -1;
                             break;
                             case IntCS2:   //重新发送，等待接受，不改变状态标志
                              index2=2;   ReceCS = 2;
                             break;
                             case IntCS3:   //改变收发方向，待添加
                              afterSendInfo2CallRadio=0;   sendSwitchInfo2=0;     //callRadio_changeToReceive();   //转入20
                              afterSendBetaAlphaBeta=1;index2=3;  Timer3Count=1;  ReceCS = -1;
                             break;
                             default:   //接受异常，发送RQ RQ RQ后 等待接受
                                 ReceCS = 0;
                             break;
                       }

                      qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
}
/*****************主台发送完转向字符，接受到的字符 （A7）************/
  else if( afterSendBetaAlphaBeta==1 && isCallRadio ==1)
   {
      index1=10; Rece3RQ =0;
                             switch(strRemapIntger(str))
                      {
                             case IntCS3:
                                 index2=1; Rece3RQ =3;
                                 break;
                             case IntRQ_RQ_RQ:
                                 afterSendBetaAlphaBeta=0;  sendCS1_waitInfo1_callRadio=1; ReceInfo =1;
                                 Timer3Count=1;             index2=2;                      Rece3RQ =-1;
                                 break;
                             default:
                                 index2=3; Rece3RQ =0;
                                 break;
                       }
                               qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);

    }
  else if( sendCS1_waitInfo1_callRadio==1 && isCallRadio==1)
   {
       index1=11; ReceInfo =0;
                             switch (strRemapIntger(str)) {
                             case IntCommuOver:  //收到通信结束字符，在定时器里面修改标志
                                  Timer3Count=1 ;  index2=1;
                                  CS_commuOver = 1;
                                  break;
                             case IntInfo1:       //受到信息字组1,(include "ID")
                             sendCS1_waitInfo1_callRadio=0;
                             if(afterReceivedInfo1_callRadio(str0)==1)   //继续作为接收位置通信
                                {
                                   Timer3Count=1; sendCS2_waitInfo2_callRadio=1; ReceInfo =0; index2=3;
                                   qDebug()<<"change state Time:"+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz");
                                }
                             else                                    //接收到转向信号 “+？”
                                {   sendCS3_callRadio=1; index2=4;} // goto 13
                                  break;
                             case IntRQ_RQ_RQ:
                             default:                                //接收异常
                                 ReceInfo =0;
                                  break;
}                        
                               qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
   }
  else if(   sendCS2_waitInfo2_callRadio==1 && isCallRadio ==1)
   {
         index1=12;  ReceInfo =0;
                             switch (strRemapIntger(str))
                           {
                             case IntCommuOver:  //收到通信结束字符
                                 Timer3Count=1 ;  index2=1;
                                 CS_commuOver = 1;
                                  break;
                             case IntInfo1:
                                 sendCS2_waitInfo2_callRadio=0;
                                 if(afterReceivedInfo1_callRadio(str0)==1)   //继续作为接收位置通信
                                    {  Timer3Count=1; sendCS1_waitInfo1_callRadio=1;index2=3; ReceInfo =0;
                                      qDebug()<<"change state Time:"+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz");
                                    }
                                 else                                    //接收到转向信号 “+？”
                                    {   sendCS3_callRadio=1; index2=4;} // goto 13
                                 break;
                             case IntRQ_RQ_RQ:
                             default:
                                  ReceInfo =0;
                                 break;
                            }
                          qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);

  }
  else if(sendCS3_callRadio==1 && isCallRadio ==1)
   {
              index1=13; ReceBetaAlphaBeta =0;
                             switch (strRemapIntger(str)) {

                             case IntbetaAlphaBeta:
                             {
                                  sendCS3_callRadio = 0;      sendRQ_callRadio =1;
                                  index2=2;                   Timer3Count=1;
                             }
                                  break;
                             case IntRQ_RQ_RQ:
                             default:                               
                                  ReceBetaAlphaBeta=0;  index2=3;
                             break;
}                  
                           qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
   }
  else if(sendRQ_callRadio ==1 && isCallRadio == 1)
  {
      index1=13;
      switch(strRemapIntger(str))
      {
      case IntCS1:
           sendRQ_callRadio =0; afterSendInfo1CallRadio=1; ReceCS = -1;  // 已经收到CS信号，所以为-1，周期到了发3beta
           sendSwitchInfo1 =1; Timer3Count=1;

           g_receTimer.stop(); ReceTimerCount =0;  //关闭本计时器
           isMainTimerOpen  = true ;               //ui 不删除直接插入
          break;
      case IntCS2:
           sendRQ_callRadio =0; afterSendInfo2CallRadio=1; ReceCS = -1;
           sendSwitchInfo2 =1; Timer3Count=1;

           g_receTimer.stop(); ReceTimerCount =0;  //关闭本计时器
           isMainTimerOpen  = true ;               //ui 不删除直接插入
          break;
      default:
          break;
      }
  }
  else if(afterSendCommuEnd14_callRadio ==1 && isCallRadio ==1)
   {
      index1=14;
                             switch (strRemapIntger(str))
                          {
                             case IntCS2:         // change to ready or remap
                                  Timer4->stop();Timer4Count=0;
                                  afterSendCommuEnd14_callRadio=0; callRadio_changetoReady(); index2=2;
                             break;
                             case IntCS1:
                             default:
                                 index2=1;  //callRadio_changeTo_commuEnd14();
                             break;
                             }
                           qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
      }
  else if(afterSendCommuEnd1617_callRadio ==1 && isCallRadio ==1)
   {
       index1=15;
                             switch (strRemapIntger(str))
                           {
                             case IntCS1:                        //stop
                                  Timer4->stop(); Timer4Count=0;
                                  callRadio_changetoReady();   afterSendCommuEnd1617_callRadio=0;
                             break;
                             case IntCS2:
                             default:                              
                                  break;
                           }                       
                           qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
   }

  else if(sendCalledArrayAfter_redirect ==3 && isCallRadio ==1)          //redirect 呼叫
  {
         index1=16;  sendCalledArrayAfter_redirect=0;
      switch(strRemapIntger(str))
      {
      case IntCS4:
          sendTimerStr(alphaAlphaAlpha,3);
          send_called_IS_oneAndTwoAndThree();           index2=1;          
          callRadio_changetoRemap();
          break;
      case IntCS5:
          Timer0->stop(); Timer0Count=0;
          str1=list_IS_SELF.at(0)+alpha+list_IS_SELF.at(1);
          sendTimerStr(str1,3);      send_display(str1);    index2=2;
          sendIdentifyArrayAfter_redirect=1;  Timer2->start(NBDPTIMER450);
          break;
      default:
          if(isTimer5_timerOut32()==1)
          {callRadio_changetoReady();}
          else
          {str1=list_IS.at(0)+"RQ"+list_IS.at(1);
           sendTimerStr(str1,3);         send_display(str);  index2=3;
           sendCalledArrayAfter_redirect=1;
          }
          break;
      }
         qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
  }
  else if(sendCalledArrayAfter_redirect ==2 && isCallRadio ==1)
  {
      index1=17;  sendCalledArrayAfter_redirect=0;
   switch(strRemapIntger(str))
   {
   case IntCS4:
       sendTimerStr(alphaAlphaAlpha,3);
       send_called_IS_oneAndTwoAndThree();           index2=1;
       callRadio_changetoRemap();
       break;
   case IntCS5:
       Timer0->stop(); Timer0Count=0;
       str1=list_IS_SELF.at(0)+alpha+list_IS_SELF.at(1);
       sendTimerStr(str1,3);      send_display(str1);    index2=2;
       sendIdentifyArrayAfter_redirect=1; Timer2->start(NBDPTIMER450);
       break;
   default:
       if(isTimer5_timerOut32()==1)
       {callRadio_changetoReady();}
       else
       {
       str1=list_IS.at(4)+list_IS.at(5)+list_IS.at(6);
      sendTimerStr(str1,3);         send_display(str1);  index2=3;
      sendCalledArrayAfter_redirect=3;
       }
       break;
   }
      qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
  }
  else if(sendCalledArrayAfter_redirect ==1 && isCallRadio ==1)
  {
      index1=18;  sendCalledArrayAfter_redirect=0;
   switch(strRemapIntger(str))
   {
   case IntCS4:
       sendTimerStr(alphaAlphaAlpha,3);
       send_called_IS_oneAndTwoAndThree();           index2=1;
       callRadio_changetoRemap();
       break;
   case IntCS5:
       Timer0->stop(); Timer0Count=0;
       identify1=list_IS_SELF.at(0)+alpha+list_IS_SELF.at(1);
       sendTimerStr(identify1,3);      send_display(identify1);    index2=2;
       sendIdentifyArrayAfter_redirect=1; Timer2->start(NBDPTIMER450);
       break;
   default:
       if(isTimer5_timerOut32()==1)
       {callRadio_changetoReady();}
       else
       {
      identify2="RQ"+list_IS.at(2)+list_IS.at(3);
      sendTimerStr(identify2,3);         send_display(identify2);  index2=3;
      sendCalledArrayAfter_redirect=2;
       }
       break;
   }
      qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
  }
  else if(sendIdentifyArrayAfter_redirect ==1 && isCallRadio ==1)      //redirect  识别
  {
      index1=19; sendIdentifyArrayAfter_redirect=0;
      switch(strRemapIntger(str))
      {
      case IntCS3:
          sendTimerStr(betaAlphaBeta,3);   send_display(betaAlphaBeta);
          afterSendBetaAlphaBeta=1;  index2=1;
          break;
      case list_CK1:
           identify2=alpha+list_IS_SELF.at(2)+list_IS_SELF.at(3);
           Timer2->start(NBDPTIMER450); Timer2Count=0;
          sendTimerStr(identify2,3);      send_display(identify2);    index2=2;
          sendIdentifyArrayAfter_redirect=2; index2=2;
          break;
      default:    //N2 he CK* 待添加
          if(isTimer2_timerOut32()==1)
          {callRadio_changetoReady();}
          else
          { identify1=list_IS_SELF.at(0)+alpha+list_IS_SELF.at(1);
          sendTimerStr(identify1,3);      send_display(identify1);    index2=3;
          sendIdentifyArrayAfter_redirect=1;
           }
          break;
      }
      qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
  }
  else if(sendIdentifyArrayAfter_redirect ==2 && isCallRadio ==1)   
  {
      index1=20; sendIdentifyArrayAfter_redirect=0;
      switch(strRemapIntger(str))
      {
      case IntCS3:
          sendTimerStr(betaAlphaBeta,3);   send_display(betaAlphaBeta);
          afterSendBetaAlphaBeta=1;  index2=1;
          break;
      case list_CK2:
            Timer2->start(NBDPTIMER450); Timer2Count=0;
          identify3=list_IS_SELF.at(4)+list_IS_SELF.at(5)+list_IS_SELF.at(6);
          sendTimerStr(identify3,3);      send_display(identify3);    index2=2;
          sendIdentifyArrayAfter_redirect=3;
          break;
      default:    //N2 he CK* 待添加
          if(isTimer2_timerOut32()==1)
          {callRadio_changetoReady();}
          else
          {
          identify2=alpha+list_IS_SELF.at(2)+list_IS_SELF.at(3);
          sendTimerStr(identify2,3);      send_display(identify2);
          sendIdentifyArrayAfter_redirect=2; index2=3;
          }
          break;
      }
      qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
  }
  else if(sendIdentifyArrayAfter_redirect ==3 && isCallRadio ==1)
  {
      index1=21; sendIdentifyArrayAfter_redirect=0;
      switch(strRemapIntger(str))
      {
      case IntCS3:
          sendTimerStr(betaAlphaBeta,3);   send_display(betaAlphaBeta);
          afterSendBetaAlphaBeta=1;  index2=1;
          break;
      case list_CK3:
            Timer2->start(NBDPTIMER450); Timer2Count=0;
          /*identify1=list_IS_SELF.at(0)+alpha+list_IS_SELF.at(1);
          sendTimerStr(identify1,3);      send_display(identify1); */   index2=2;
          //sendIdentifyArrayAfter_redirect=1;
          sendTimerStr(RQ_RQ_RQ,3);    send_display(RQ_RQ_RQ);
          sendIdentifyOverAfter_redirect =1;
          break;
      default:    //N2 he CK* 待添加
          if(isTimer2_timerOut32()==1)
          {callRadio_changetoReady();}
          else
          {
          identify3=list_IS_SELF.at(4)+list_IS_SELF.at(5)+list_IS_SELF.at(6);
          sendTimerStr(identify3,3);      send_display(identify3);
          sendIdentifyArrayAfter_redirect=3; index2=3;
          break;
          }
      }
      qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
  }
  else if(sendIdentifyOverAfter_redirect ==1 && isCallRadio ==1)     //redirect  识别结束
  {
      index1=22; sendIdentifyOverAfter_redirect=0;
      switch(strRemapIntger(str))
      {
      case IntCS1:
           Timer2->stop(); Timer2Count=0;
           Timer5->stop(); Timer5Count=0;
           Timer3->start(NBDPTIMER450);sendSwitchInfo1=1;send_display("send info1,when click.");
            index2=0;
          break;
      case IntCS2:
          Timer2->stop(); Timer2Count=0;
          Timer5->stop(); Timer5Count=0;
          Timer3->start(NBDPTIMER450);   Timer3Count=0;   index2=1;
          afterReceivedInfo1(); sendSwitchInfo2=1;  send_display("send info2,when click.");
          break;
      case IntCS3: //CS3 添加重定相函数--22
         Timer2->stop();     Timer2Count=0;
         Timer3->start(NBDPTIMER450);Timer3Count=0;
         callRadio_changeToReceive();   //转入20
         afterSendBetaAlphaBeta=1; index2=2;
        break;
      case IntRQ: //RQ
      afterReceivedCK3_gotoIdentifyOver(); index2=3; break;
      default:
          if(isTimer2_timerOut32()==1)
          {callRadio_changetoReady();  index2=4;}
          else
          {afterReceivedCK3_gotoIdentifyOver();sendIdentifyOverAfter_redirect=1;  index2=5;}
          break;
      }
      qDebug()<<QString("%1%2%3").arg(index0).arg(index1).arg(index2);
  }

  else
  {
      qDebug()<<"callRadio,no one is compare";
  }
  }
int MainWindow::isLastoneSameCK(int rightCK,int receiveCK)
{
    if( (integerCKVector.size() > 0) && (integerCKVector.at(integerCKVector.size()-1)==receiveCK))
        return 1;
    else
    {  integerCKVector.prepend(receiveCK);
       return 0;
    }
}
     void MainWindow::sendTimerStr(QString str,int flag) // chi xu fa song 210 huo 70 ms
     {
         sendInfo=str;
         sendIndex=flag;

         if(sendIndex==1)
             emit signal_sendNbdp_mesg("1",sendInfo);
         else if(sendIndex == 3)
             emit signal_sendNbdp_mesg("3",sendInfo);
         else if(sendIndex==0)
             emit signal_sendNbdp_mesg("0",sendInfo);
     }


void MainWindow::callRadio_changetoReady()
{
    //public var init
    Timer0->stop(); Timer2->stop(); Timer3->stop(); Timer4->stop(); Timer5->stop();
    MainTimerCount=0;
    g_mainTimer.stop(); g_receTimer.stop();



    calledRadioStart=1;
   // isCallRadio=1;       //重新分配主台,看颜色，手控颜色

    Timer0Count=0; Timer2Count=0; Timer3Count=0; Timer4Count=0; Timer5Count=0; Timer6Count=0;

    if( get_call_or_recg_state()==1 || get_call_or_recg_state()==2 )
        Transit::get()->EmitSignalJianLianEnterReady(); // 建连过程进入ready，通知ui停止建连对话框

    emit signal_workFlow_readyAndIdle();                //初始化变量 和 UI ,break光标

    qDebug()<<"CallRadio go to ready.";
}
void MainWindow::callRadio_changetoRemap()
{
   callRadio_changetoReady(); reDirect=1;isCallRadio=1;
   Timer5->start(NBDPTIMER450);Timer0->start(NBDPTIMER450);
}
void MainWindow::calledRadio_changetoReady()
{
    //public var init
    Timer0->stop(); Timer2->stop(); Timer3->stop(); Timer4->stop(); Timer5->stop();
    MainTimerCount=0;
    g_mainTimer.stop(); g_receTimer.stop();

    calledRadioStart=1;
    isCallRadio=0;          //重新分配主台

    Timer0Count=0; Timer2Count=0; Timer3Count=0; Timer4Count=0; Timer5Count=0; Timer6Count=0;

    if( get_state_recvinfo() == false )
         Transit::get()->EmitSignalJianLianEnterReady(); // 建连过程进入ready，通知ui停止建连对话框
    emit signal_workFlow_readyAndIdle();                 //初始化变量 和 UI
    Var_init();
    qDebug()<<"CalledRadio go to ready.";
}
void MainWindow::calledRadio_changetoRemap()
{
    calledRadio_changetoReady();
    calledRadioStart=1; reDirect=1; waitForCall_redirect=1;
    qDebug()<<"CalledRadio go to remap.";
}
int MainWindow::isTimer0_timerOut128()
{
    if(Timer0Count>=TIMER_0_out128)
        return 1;
    else
        return 0;
}
int MainWindow::isTimer2_timerOut32()
{
    if(Timer2Count>=TIMER_2_3_5_out32)
        return 1;
    else
        return 0;
}
int MainWindow::isTimer3_timerOut32()
{
    if(Timer3Count>=TIMER_2_3_5_out32)
        return 1;
    else
        return 0;
}
int MainWindow::isTimer4_timerOut4()
{
    if(Timer4Count>=4)
        return 1;
    else
        return 0;
}
int MainWindow::isTimer5_timerOut32()
{
    if(Timer5Count>=TIMER_2_3_5_out32)
        return 1;
    else
        return 0;
}
void MainWindow::Var_init()
{

    bHaveSendCommOver = false;
     beginTime=QDateTime::currentDateTime();
     m_SerialSend->init_buffer();    //清楚串口数据
     init_Receive_Send = 0;
     workFlowState=1;
     b_flag_cs4=false;
     sendCalledArrayAfter=0;
     sendIdentifyArrayAfter=0;
     sendIdentifyOverArrayAfter=0;
     send_flow_state=0;
     timer2_switch_timer3=0;
     isLetterState=true;
     isLetterState_receive=true;
     //isCallRadio=1;
     calledRadioStart=1;   //calledRadio first called
     isMainTimerOpen  = true ;
     CS_commuOver = 0 ;
     ReceInfo = 0;
     ReceCS =-1;
     Rece3RQ = -1;
     ReceIdent =-1;
     ReceBetaAlphaBeta =0;

      MainTimerCount=0; ReceTimerCount =0;
      sendIndex=0; receiveIndex=0;receiveCount=0;


    sendCalledArrayAfter_FourMMSI=0;
    afterSendInfo1CallRadio_FourMMSI=0;
    afterSendCommuEnd14_callRadio_FourMMSI=0;
    afterSendBetaAlphaBeta_FourMMSI=0;
    afterSendCommuEnd1617_callRadio_FourMMSI=0;
    afterSendInfo2CallRadio_FourMMSI=0;
    callRadio_waitForInfo1_FourMMSI=0;
    callRadio_changetoSend_FourMMSI=0;
    sendCS2_waitInfo2_callRadio_FourMMSI=0;

     afterSendInfo1CallRadio=0;
     afterSendInfo2CallRadio=0;
     sendSwitchInfo1=0;
     sendSwitchInfo2=0;
     afterSendBetaAlphaBeta=0;            //为了测试置1
      sendCS1_waitInfo1_callRadio=0;
      sendCS2_waitInfo2_callRadio=0;
      sendCS3_callRadio=0;
      sendRQ_callRadio=0;
      afterSendCommuEnd14_callRadio=0;
      afterSendCommuEnd1617_callRadio=0;

      calledRadioWaitForCalledCharAry2=0;
       calledRadioWaitForCalledCharAry3=0;

       calledRadioWaitForIdentify1=0;
       calledRadio_afterSendCK1=0;

       calledRadio_afterSendCK2=0;
       calledRadioWaitForIdentifyOverChar=0;
       calledRadioWaitForInfo1=0;
       calledRadioWaitForInfo1=0;
       calledRadio_afterSendCS3=0;
       calledRadio_receiveToSend=0;
       calledRadio_waitForInfo1Back=0;
       calledRadio_after14SendCommuOver=0;
        calledRadio_after16SendCommuOver=0;
         calledRadio_waitForSendChangeToReceiveBack=0;

        sendCalledArrayAfter_redirect=0;
        sendIdentifyArrayAfter_redirect=0;
        sendIdentifyOverAfter_redirect=0;
        waitForCall_redirect=0; waitForCall1_call1Lose_redirect=0;
        waitForIdentify_redirect=0;
        waitForIdentifyOver_redirect=0;
        FourMMSI_redirect_called_2and1Road=0;

        sendCalledArrayAfter_FourMMSI_reDirect=0;
        waitForCall_FourMMSI_reDirect=0;
        reDirect=0; redirect_waitInfo1=0;
        reversedOrder=0;

        sendData.clear();  //前一次+？没发送完毕，引起下一次自动发送
}

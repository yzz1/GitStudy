#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QtGui/QMainWindow>
#include <QtGui/QPalette>
#include "posix_qextserialport.h"
#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include <QVector>
#include "qextserialport.h"
#include "globalarray.h"
#include "dockwidget.h"
#include "UISerial.h"
#include "transit.h"


#define NBDPTIMER450 450
#define TIMER_2_3_5_out32  32
#define TIMER_4_out4      4
#define TIMER_1_out128      128*10000
#define TIMER_0_out128      128

#define CS1 "BYBYYBB"
#define CS2 "YBYBYBB"
#define CS3 "BYYBBYB"
#define CS4 "BYBYBBY"
//#define CS5 "BYYBYBB"
#define RQ "YBBYYBB"
#define beta "BBYYBBY"
#define alpha "BBBBYYY"
#define  RQ_RQ_RQ "YBBYYBBYBBYYBB"
#define alphaAlphaAlpha "BBBBYYYBBBBYYY"
#define betaAlphaBeta "BBYYBBYBBBBYYY"

#define  IntCS1 0x2c
#define  IntCS2  0x54
#define  IntCS3  0x32
#define  IntCS4  0x29
#define  IntCS5  0x34
#define   IntRQ  0x4c
#define   Intbeta  0x19
#define   Intalpha  0x07

#define   IntRQ_RQ_RQ  0x9

#define   IntalphaAlphaAlpha  21
#define   IntbetaAlphaBeta  11
#define   list_CK1          12
#define   list_CK2          13
#define   list_CK3          14
#define   receiveRadioCall1  15
#define   receiveRadioCall2  16
#define   receiveRadioCall3  17
#define   receiveRadioIdentify1  18
#define   receiveRadioIdentify2  19
#define   receiveRadioIdentify3  20
#define   IntCommuOver           21
#define   IntInfo1               22
#define   receiveRadioCall2_FourMMSI 23

class MainTimer;
class ReceTimer;

namespace Ui {
class MainWindow;
}

class  MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(UISerial* m_SerialSend0);
    ~MainWindow();

public:

    QDateTime beginTime;
    int init_Receive_Send;   //init_Receive_Send ( 0 1 2)
    void Var_init();
    void callRadio_sendMsgARQ();
    void calledRadio_sendMsgARQ();
    void callRadio_changetoReady();
    void calledRadio_changetoReady();
    void receive_display(QString str0);
    void send_display(QString str0);
    void on_buttonSendToSerial_clicked(QString strNo,QString strMsg);
    bool get_state_recvinfo();
    int  get_call_or_recg_state(); //0,no; (1,call)(2,recongnise)
     void calc_IS_IK(QString strSelfMMSI,QString strOtherMMSI);
     //QList<QString> numToIS(int dec,int size);
     void init_nine_MMSI(int flag); //flag==0 本台 flag==1 呼叫台    计算list_IS,list_CK,list_IS_SELF
     void init_four_MMSI(int flag); // flag==0 本台 flag==1 呼叫台   计算list_IS,list_SELF

     void send_called_IS_oneAndTwoAndThree();
     void received_notExpected_CalledArrayAfter3();      //发送呼叫字组3之后
     void received_notExpected_CalledArrayAfter1();      //发送呼叫字组1之后
     void received_notExpected_CalledArrayAfter2();      //发送呼叫字组2之后

     void sendIdentifTwo_receivedCK1();
     void sendIdentifOne_receivedOtherThree();
     void sendIdentifThree_receivedCK2();
     void afterReceivedCK3_gotoIdentifyOver();
//     void afterReceivedCS1_gotoCommunication();
     void afterReceivedInfo1();
     void callRadio_changeToReceive();
     int  callRadio_receive();
     int afterReceivedInfo1_callRadio(QString str);
     void readAndJudgeIfCS3();
     void callRadio_sendAgain_beforeReceiveWait();
     void callRadio_sendAgain_afterReceiveWait();
     void callRadio_changeTo_commuEnd14();
     void callRadio_changeTo_commuEnd16();
     void callRadio_changeTo_commuEnd17();
     void callRadio_changeToRemap();
     void calledRadio_changetoRemap();
     void callRadio_flow(QString str0);
     void callRadio_flow_fourMMSI(QString str0);
     void  received_notExpected_CalledArrayAfter2_FourMMSI();
      void received_notExpected_CalledArrayAfter1_FourMMSI();
     void callRadio_changeToReceive_FourMMSI();
      int callRadio_receive_FourMMSI();
      void callRadio_changetoSendAgain_FourMMSI();

     void calledRadio_afterReceivedCalledCharAry1();
     void calledRadio7_afterReceivedCalledCharAry2();
     int calledRadio4_afterReceivedCalledCharAry2();
     void calledRadio_afterReceivedCalledCharAry3();
//   void calledRadio_afterReceivedCalledCharAry3();
     void calledRadio_afterReceivedIdentifyCharAry1();
     void calledRadio_afterReceivedIdentifyCharAry2();
     void calledRadio_afterReceivedIdentifyCharAry3();
     int  calledRadio_gotoCommu();
     int calledRadio_receivedInfo1(QString str);
     int calledRadio_receivedInfo2();
     void calledRadio_receiveChangeToSend();
     void calledRadio_sendPosition();
     void calledRadio_openSendInfo1Switch();
     int calledRadio_receivedInfo1Back();
     int calledRadio_receivedInfo2Back();
     void  calledRadio_changetoCommuOver14();
     void calledRadio_changetoCommuOver16();
     void calledRadio_changeToReceiveAgain();
     int strRemapIntger(QString str);
     void calledRadio_flow(QString str0);
     void sendTimerStr(QString str,int flag); //通过串口发送字组，计时器计量时间，flag==1，一个信号元，flag==3，三个信号元
     int isLastoneSameCK(int rightCK,int receiveCK);
     QByteArray Str_addZhuanYi(QString strMsg);    //加入转义字符

private:
     Posix_QextSerialPort *myCom;
     UISerial *m_SerialSend;
     QPalette pe;   //

     QByteArray com_receive_Array;
     QVector<int> integerCKVector;
     QString m_strSelf;
     QString m_strCalled;
     QByteArray m_repeate_charMsg;


signals:
     void signal_received_CS4();
     void signal_received_CS5();
     void signal_sendNbdp_mesg(QString strNo,QString strMsg);
     void signal_workFlow_readyAndIdle();
private slots:

     void on_buttonToCall_clicked();


     void slot_received_CS4();
     void slot_received_CS5();

     void on_buttonOpenSerial_clicked();
     void on_buttonCloseSerial_clicked();     


     void Timer0_count();
     void Timer1_count();
     void Timer2_count();
     void Timer3_count();
public slots:
     void MainTimer_count();
     void ReceTimer_count();
     void on_sendCallCode_callRadio(bool b);
     void readMyCom();
private slots:
     void Timer4_count();
     void Timer5_count();
     void Timer6_count();

     int isTimer0_timerOut128();
     int isTimer2_timerOut32();
     int isTimer3_timerOut32();
     int isTimer4_timerOut4();
     int isTimer5_timerOut32();

     void callRadio_changetoRemap();


private:
    Ui::MainWindow *ui;
    DockWidget *testWidget;

    QTimer *readTimer;

    QTimer *Timer0;
    QTimer *Timer1;
    QTimer *Timer2;
    QTimer *Timer3;
    QTimer *Timer4;
    QTimer *Timer5;
    QTimer *Timer6;
public:
    int isSendingMsg;
    int MainTimerCount;
    int ReceTimerCount;
    bool bHaveSendCommOver;
   // int ReverseCount;    //反转计数

    bool b_haveData;
    QByteArray sendData;
private:
    int Timer0Count;
    int Timer1Count;
    int Timer2Count;
    int Timer3Count;
    int Timer4Count;
    int Timer5Count;
    int Timer6Count;

    int sendIndex;
    int receiveIndex;
    int receiveCount;
    int  ReceInfo ;   //0,no;
    int  ReceCS;      // 0,no; 1 cs1; 2 cs2; 3 cs3;
    int  Rece3RQ;     //0,no; 1 3RQ; 3,CS3;
    int  ReceBetaAlphaBeta ;   //反转向    
    int  ReceIdent;          //没接受到就是-1，接受到就是0


    int calledRadioStart;
     bool b_flag_cs4;
    int sendSwitchInfo1;
    int sendSwitchInfo2;
    int timer2_switch_timer3;
     int afterSendBetaAlphaBeta;
public:
     QString sendInfo;   // this two li yong qi lai.
     QString receivedInfo;

private:
     int redirect_waitInfo1; // initial 0; 1 is waiting info1,2 is info2
     int send_flow_state;    //0,no; (1,call)(2,recongnise)

    QMap<QString,int> receiveMap;


    int sendCalledArrayAfter_FourMMSI;
    int afterSendInfo1CallRadio_FourMMSI;
    int afterSendCommuEnd14_callRadio_FourMMSI;
    int afterSendBetaAlphaBeta_FourMMSI;
    int afterSendCommuEnd1617_callRadio_FourMMSI;
    int afterSendInfo2CallRadio_FourMMSI;
    int callRadio_waitForInfo1_FourMMSI;  //1
    int callRadio_changetoSend_FourMMSI;
    int sendCS2_waitInfo2_callRadio_FourMMSI; //1

    int sendCalledArrayAfter;
    int sendIdentifyArrayAfter;
    int sendIdentifyOverArrayAfter;
  public:
    int afterSendInfo1CallRadio;
    int afterSendInfo2CallRadio;
  private:
     int sendCS1_waitInfo1_callRadio;   //1
     int sendCS2_waitInfo2_callRadio;   //1
     int sendCS3_callRadio;
     int sendRQ_callRadio;
     int afterSendCommuEnd14_callRadio;
     int afterSendCommuEnd1617_callRadio;
     int CS_commuOver;

     int calledRadioWaitForCalledCharAry2;
     int calledRadioWaitForCalledCharAry3;
     int calledRadioWaitForIdentify1;
     int calledRadio_afterSendCK1;
     int calledRadio_afterSendCK2;
     int calledRadioWaitForIdentifyOverChar;
     int calledRadioWaitForInfo1;      //1
     int calledRadioWaitForInfo2;      //1
     int calledRadio_afterSendCS3;
     int calledRadio_receiveToSend;


     int calledRadio_waitForInfo1Back;
     int calledRadio_waitForInfo2Back;

     int calledRadio_after14SendCommuOver;
     int calledRadio_after16SendCommuOver;
     int  calledRadio_waitForSendChangeToReceiveBack;

     //redirect call
     int sendCalledArrayAfter_redirect;
     int sendIdentifyArrayAfter_redirect;
     int sendIdentifyOverAfter_redirect;

     //receive
     int waitForCall_redirect;
     int waitForIdentify_redirect;
     int waitForIdentifyOver_redirect;
     int waitForCall1_call1Lose_redirect;
     int FourMMSI_redirect_called_2and1Road;

     int sendCalledArrayAfter_FourMMSI_reDirect;
     int waitForCall_FourMMSI_reDirect;
     int reDirect;
     int reversedOrder;

public:
     int isFourMMSI;
     int isCallRadio;
     QString strSelfMMSI;
     QString strOtherMMSI;
     QList<QString> list_IS;
     QList<QString> list_CK;

     QList<QString> list_IS_SELF;
     QList<QString> list_CK_SELF;
     GlobalArray globalArray;// This is available in all editors.
     int workFlowState;          //（0,未连接）（1，控制指令）（2，建连）（3，数据指令）（4，扫描结果）
     bool isLetterState;
     bool isLetterState_receive;
     bool isMainTimerOpen ;      //处于发送位置的定时器开启状态
};

extern MainTimer g_mainTimer;
extern ReceTimer g_receTimer;
#endif // MAINWINDOW_H

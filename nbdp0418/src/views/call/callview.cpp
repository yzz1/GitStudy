#include "callview.h"
#include "ui_callview.h"
#include "views/common/constants.h"
#include <QEvent>
#include <QKeyEvent>
#include "widgets/button.h"
#include <QDebug>
#include "logging.h"
#include "widgets/messagebox.h"
#include "widgets/iocmessage.h"
#include "transit.h"
#include "callclass.h"
#include "core/utils/configutils.h"

/****************************************************************************
**
** CallContactsData::clear
** 功能概述:
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallContactsData::clear()
{
    Logging::get()->info("CallContactsData::clear");
    // 清空名称标识
    name.clear();

    // 清空call code标识
    callCode.clear();

    // 清空通道标识
    strChannel.clear();

    // 清空TX标识
    strTx.clear();

    // 清空RX标识
    strRx.clear();
}

/****************************************************************************
**
** 函数名称：CallView::CallView
** 功能概述: 初始化
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
CallView::CallView(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::CallView)
{
    Logging::get()->info("CallView::CallView");

    // 初始化UI
    ui->setupUi(this);

    // 初始化m_keyupDown为false
    m_keyupDown = false;

    // 设置页面的标题
    ui->CallTitleWidget->setText("CALL SETUP");

    // 设置通信类别的按钮组：ARQ、SFEC和BFEC，三个按钮只能单选
    QButtonGroup* group = new QButtonGroup;
    group->addButton(ui->arqRadio);
    group->addButton(ui->sfecRadio);
    group->addButton(ui->bfecRadio);
    group->setExclusive(true);

    // 设置电台类别的按钮组：Individual(个人)、Station(站台)和Manual（手工设置）
    // 三个按钮只能单选。
    QButtonGroup* contactsGroup = new QButtonGroup;
    contactsGroup->addButton(ui->individualRadio, 0);
    contactsGroup->addButton(ui->stationRadio, 1);
    contactsGroup->addButton(ui->manualRadio, 2);
    contactsGroup->setExclusive(true);

    // 初始化各全局变量
    m_callModeStaionDate.clear();
    m_callModeIndividualDate.clear();
    m_callModeManualDate.clear();
    m_recvModeStaionDate.clear();
    m_recvModeIndividualDate.clear();
    m_recvModeManualDate.clear();
    m_callMode = 1;
    m_callOrReceive = 1;

    // 设置Individual的按钮图片
    QIcon individualIcon;
    individualIcon.addPixmap(QPixmap(":/images/images/Call_Individual_SelNo.png"), QIcon::Normal);
    individualIcon.addPixmap(QPixmap(":/images/images/Call_Individual_SelYes.png"), QIcon::Selected);
    
    //信号连接槽
    connect(ui->homeBtn, SIGNAL(clicked()), this, SLOT(homeClickedSlot()));
    connect(ui->okBtn, SIGNAL(clicked()), this, SLOT(okButtonClickedSlot()));
    connect(ui->cancelBtn, SIGNAL(clicked()), this, SLOT(cancelButtonClickedSlot()));
    connect(ui->callBtn, SIGNAL(clicked()), this, SLOT(callButtonClickedSlot()));
    connect(ui->receiveBtn, SIGNAL(clicked()), this, SLOT(receiveButtonClickedSlot()));
    connect(contactsGroup, SIGNAL(buttonPressed(int)), this, SLOT(buttonPressedSlot(int)));

    // 安装事件过滤器
    this->installEventFilter(this);

    // 初始化计时器以及连接好超时处理槽，该超时信号只触发一次
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateTimeoutFlagSlot()));
    m_timer->setSingleShot(true);

    // 设置对话框居于屏幕中央
    m_iocMessage.move((SCREEN_SIZE_WIDTH - m_iocMessage.width()) / 2,
                      (SCREEN_SIZE_HEIGHT - m_iocMessage.height()) / 2);

    // 设置对话框珠字体为"Ubuntu"、18号、粗体
    QFont font("Ubuntu", 18, QFont::Bold);
    m_iocMessage.SetFont(font);
}

/****************************************************************************
**
** 函数名称：CallView::buttonPressedSlot
** 功能概述: 电台类别按钮按下处理
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallView::buttonPressedSlot(int id)
{
    Logging::get()->info("CallView::buttonPressedSlot");
    
    // 因为向下向上按键的时候，也会触发该事件，所以要判断是否是上下键触发的，
    // 如果是，则不处理，如果不是，则跳转到对应的通话信息设置页面。
    if (m_keyupDown)
    {
        m_keyupDown = false;
        return;
    }
    
    QMap <QString, QString> paraMap;
    QString flag;
    
    // 根据m_callOrReceive的值，设置参数
    if (m_callOrReceive)
    {
        flag += "1";
    }
    else
    {
        flag += "0";
    }
    
    paraMap.insert(CALL_OR_RECEIVE, flag);
    QString forwardId;
    
    // 如果Id为0，则跳转到个人频率设置页面，如果Id为1，则跳转到站台频率设置页面，否则跳转到手工设置页面。
    if (id == 0)
    {   
        // 个人
        // 设置name标识
        ui->nameLabel->setText(m_individualDate->name);

        // 设置callcode标识
        ui->callCodeLabel->setText(m_individualDate->callCode);

        // 设置通道
        ui->channelLabel->setText(m_individualDate->strChannel);

        // 设置TX和RX
        ui->txLabel->setText(m_individualDate->strTx + " KHz");
        ui->rxLabel->setText(m_individualDate->strRx + " KHz");

        // 设置name标识上方图案
        QPixmap pix1(":/images/images/Call_Info_Name.png");
        ui->nameTitle->setPixmap(pix1);

        // 将individual按钮设为当前焦点，并设为选中
        ui->individualRadio->setFocus();
        ui->individualRadio->setChecked(true);

        // 设置跳转页面的ID
        forwardId = INDIVIDUAL_SELECT_VIEW;
    }
    else if (id == 1)
    {
        // 站台
        // 设置name标识
        ui->nameLabel->setText(m_stationData->name);

        // 设置callcode标识
        ui->callCodeLabel->setText(m_stationData->callCode);

        // 设置通道标识
        ui->channelLabel->setText(m_stationData->strChannel);

        // 设置TX和RX的标识
        ui->txLabel->setText(m_stationData->strTx + " KHz");
        ui->rxLabel->setText(m_stationData->strRx + " KHz");

        // 设置名字上方的图案
        QPixmap pix2(":/images/Call_Info_Station");
        ui->nameTitle->setPixmap(pix2);

        // 将station按钮设为当前焦点，并设为选中
        ui->stationRadio->setFocus();
        ui->stationRadio->setChecked(true);

        // 设置跳转页面的ID
        forwardId = STATION_SELECT_VIEW;
    }
    else if (id == 2)
    {
        // 手动设置
        // 设置name标识
        ui->nameLabel->setText(m_manualDate->name);

        // 设置callcode的标识
        ui->callCodeLabel->setText(m_manualDate->callCode);

        // 设置通道的标识
        ui->channelLabel->setText(m_manualDate->strChannel);

        // 设置TX和RX的标识
        ui->txLabel->setText(m_manualDate->strTx + " KHz");
        ui->rxLabel->setText(m_manualDate->strRx + " KHz");

        // 设置名字上方的文字“Name”
        ui->nameTitle->setText(tr("Name"));
        ui->manualRadio->setFocus();
        ui->manualRadio->setChecked(true);

        // 设置跳转页面的ID
        forwardId = MANUAL_FREQUENCY_VIEW;
    }
    
    // 最后，跳转到相应的目标页面
    emit afterPageSignal(CALL_VIEW_NAME, forwardId, paraMap);
}

/****************************************************************************
**
** 函数名称：CallView::updateTimeoutFlagSlot
** 功能概述: 超时处理
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallView::updateTimeoutFlagSlot()
{
    // 设置超时标志符为true
    timeoutFlag = true;
    
    // 如果超时对话框可见的情况下，则将之关闭，否则不处理
    if (m_iocMessage.isVisible())
    {
        m_iocMessage.close();
    }
}

/****************************************************************************
**
** 函数名称：CallView::~CallView
** 功能概述: 析构函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
CallView::~CallView()
{
    // 销毁ui指针
    delete ui;
}

/****************************************************************************
**
** 函数名称：CallView::homeClickedSlot
** 功能概述: home按钮响应，跳转到主菜单。
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallView:: homeClickedSlot()
{
    Logging::get()->info("CallView::homeClickedSlot");

    // 跳转到Home页面，参数为空Map
    QMap <QString, QString> paraMap;
    emit afterPageSignal(CALL_VIEW_NAME, HOME_VIEW_NAME, paraMap);
}

/****************************************************************************
**
** 函数名称：CallView::okButtonClickedSlot
** 功能概述: 打开通话界面
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallView:: okButtonClickedSlot()
{
    Logging::get()->info("CallView::okButtonClickedSlot");
    
  //   进入通话界面前，首先要判断电台是否处于连接状态，如果处于未连接状态，则弹出警告框，处理结束。
    if (!ConfigUtils::isConnected())
    {
        // 初始化警告对话框：居中，图标以及文字和文本属性
        Transit::get()->EmitSignalRadioConnectAsk();

        IocMessage infomsg1;
        infomsg1.move((SCREEN_SIZE_WIDTH - infomsg1.width()) / 2, (SCREEN_SIZE_HEIGHT - infomsg1.height()) / 2);
        infomsg1.SetIoc(":/images/images/Call_exclamatory_mark.png", 30, false);
        infomsg1.SetMessage(tr("Warning"), tr("Check interconnections between terminal and Main."), tr(""));
        QFont font1("Ubuntu", 18, QFont::Bold);
        infomsg1.SetFont(font1);
        infomsg1.exec();
        return;
    }
    
    MessageBox msg;
    msg.move((SCREEN_SIZE_WIDTH - msg.width()) / 2, (SCREEN_SIZE_HEIGHT - msg.height()) / 2);
    
    // TX和RX中如果有一方为空，另一方不为空，则将为空的值设为不为空的值。
    QString tx = ui->txLabel->text().replace(" KHz", "");
    QString rx = ui->rxLabel->text().replace(" KHz", "");
    if (!tx.isEmpty() && rx.isEmpty())
    {
        // RX为空而TX不为空，则把TX的值赋给RX
        rx = tx;
    }
    else if (tx.isEmpty() && !rx.isEmpty())
    {
        // TX为空而RX不为空，则把RX的值赋给TX
        tx = rx;
    }
    
    // BFEC模式下，只要确保TX和RX都不为空即可
    if (ui->bfecRadio->isChecked() || g_mainWorkFlow->isCallRadio == 0)
    {
        if (tx.isEmpty() || rx.isEmpty())
        {
            // 如果TX或者RX为空，则弹出警告框
            msg.SetMessage(tr("Warning"), tr("Tx,Rx can not be empty"), 0);
            msg.exec() ;
            return ;
        }
    }
    else
    {
        // BFEC模式以外，要确保Callcode、TX、RX都不为空
        if (ui->callCodeLabel->text().isEmpty() || tx.isEmpty()
            || rx.isEmpty())
        {
            // 如果Callcode、TX、RX中有一者为空，则弹出警告框，并结束当前处理
            msg.SetMessage(tr("Warning"), tr("Callcode,Tx,Rx can not be empty"), 0);
            msg.exec() ;
            return ;
        }
    }
    
    // 同一Callcode要等待60秒才能重拨
    if (!timeoutFlag && !m_CallParaMap[Constants::MESSAEGS_LIST_COL_CALLCODE].isEmpty()
        && m_CallParaMap[Constants::MESSAEGS_LIST_COL_CALLCODE] == ui->callCodeLabel->text())
    {
        // 初始化超时警告对话框
        m_iocMessage.SetIoc(":/images/images/Call_Waiting_signs.png", 60, false);
        m_iocMessage.SetMessage(tr("Warning"), tr("The same MMSI, please wait 60 seconds!"), tr(""));
        int ret = m_iocMessage.exec();
        
        // OK按钮按下的情况下，则结束当前处理并返回
        if (ret == 1)
        {
            return;
        }
    }
    
    // Callcode不为空的情况下，Callcode只能为4位，5位或者9位数字，否则报错
    QRegExp re("\\d{4}|\\d{5}|\\d{9}");
    QString callcode  = ui->callCodeLabel->text();
    
    if (!callcode.isEmpty() && !re.exactMatch(callcode))
    {
        // callcode不为空且不为4、5、9位数字时，弹出警告框
        MessageBox mgb;
        mgb.move((SCREEN_SIZE_WIDTH - mgb.width()) / 2, (SCREEN_SIZE_HEIGHT - mgb.height()) / 2);
        mgb.SetMessage(tr("Message"), tr("Callcode must be nine digits !"), 0);
        mgb.exec() ;
        return;
    }
    
    // 设置主呼或被呼参数
    if (m_callOrReceive)
    {
        // Call
        m_CallParaMap.insert(CALL_OR_RECEIVE, Constants::CALL_SET_CALLRECEIVE_CALL);
    }
    else
    {
        // Receive
        m_CallParaMap.insert(CALL_OR_RECEIVE, Constants::CALL_SET_CALLRECEIVE_RECEIVE);
    }
    
    // 设置通信模式参数
    QString strCallMode;
    if (ui->bfecRadio->isChecked())
    {
        // BFEC
        strCallMode = Constants::CALL_SET_MODE_BFEC;
    }
    else if (ui->sfecRadio->isChecked())
    {
        // SFEC
        strCallMode = Constants::CALL_SET_MODE_SFEC;
    }
    else
    {
        // ARQ
        strCallMode = Constants::CALL_SET_MODE_ARQ;
    }
    m_CallParaMap.insert(Constants::CALL_SET_CALL_MODE, strCallMode);
    
    // 设置站台类型参数
    QString strOwner = "";
    if (ui->individualRadio->isChecked())
    {
        // Individual(个人)
        strOwner = COMMON_OWER_INDIVIDUAL;
    }
    else if (ui->stationRadio->isChecked())
    {
        // Station(站台)
        strOwner =  COMMON_OWER_STATION;
    }
    else
    {   
        // Manual（手工设置）
        strOwner = COMMON_OWER_MANUAL;
    }
    m_CallParaMap.insert(Constants::CALL_SET_OWNER, strOwner);


    // 设置名称参数
    m_CallParaMap.insert(Constants::MESSAEGS_LIST_COL_NAME, ui->nameLabel->text());

    // 设置callcode参数
    m_CallParaMap.insert(Constants::MESSAEGS_LIST_COL_CALLCODE, ui->callCodeLabel->text());

    // 设置TX和RX参数
    m_CallParaMap.insert(Constants::MESSAEGS_LIST_COL_TX, tx);
    m_CallParaMap.insert(Constants::MESSAEGS_LIST_COL_RX, rx);
    
    // 设置通道的参数
    m_CallParaMap.insert(Constants::MESSAEGS_LIST_COL_CHANNEL, ui->channelLabel->text());
    
    // 设置呼叫信息参数
    CallInfoClass* callInfo = new CallInfoClass();
    callInfo->setCallChannel(ui->channelLabel->text());
    callInfo->setCallCode(ui->callCodeLabel->text());
    callInfo->setCallName(ui->nameLabel->text());
    callInfo->setCallRx(rx);
    callInfo->setCallTx(tx);
    callInfo->setCallType(strCallMode);
    CallClass::get()->setCallInfo(callInfo);

    if(m_callOrReceive==1) //主叫
      { g_mainWorkFlow->isCallRadio=1;CallClass::get()->setIsCall(true);}
    else//被叫
      { g_mainWorkFlow->isCallRadio=0;CallClass::get()->setIsCall(false);}

    // 发送呼叫信号
    Transit::get()->EmitSignalCallSetup(CallClass::get());



    // 将延时标志位设为false，并开始计时
    timeoutFlag = false;
    m_timer->start(ConfigUtils::getCallInterval());
    emit afterPageSignal(CALL_VIEW_NAME, CALL_COMMUNICATION_VIEW, m_CallParaMap);
}

/****************************************************************************
**
** 函数名称：CallView::callButtonClickedSlot
** 功能概述: 选择主叫模式
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallView:: callButtonClickedSlot()
{
    Logging::get()->info("CallView::callButtonClickedSlot");

    // 呼叫按钮按下时，呼叫按钮设为高亮,接收按钮设为灰色
    ui->receiveBtn->setIcon(QIcon(":/images/images/Receive_Bnt_SelNo.png"));
    ui->callBtn->setIcon(QIcon(":/images/images/Call_Bnt_SelYes.png"));
    m_callOrReceive = 1;

    if(m_callOrReceive==1) //主叫
      { g_mainWorkFlow->isCallRadio=1;CallClass::get()->setIsCall(true);}
    else//被叫
      { g_mainWorkFlow->isCallRadio=0;CallClass::get()->setIsCall(false);}

    // 获取individual、station和manual的临时数据
    m_stationData = &m_callModeStaionDate;
    m_individualDate = &m_callModeIndividualDate;
    m_manualDate = &m_callModeManualDate;
    
    if (ui->individualRadio->isChecked())
    {
        // individual按钮选中时，设置individual的文本信息
        ui->nameLabel->setText(m_individualDate->name);
        ui->callCodeLabel->setText(m_individualDate->callCode);
        ui->channelLabel->setText(m_individualDate->strChannel);
        ui->txLabel->setText(m_individualDate->strTx + " KHz");
        ui->rxLabel->setText(m_individualDate->strRx + " KHz");
    }
    else if (ui->stationRadio->isChecked())
    {
        // station按钮选中时，设置station的文本
        ui->nameLabel->setText(m_stationData->name);
        ui->callCodeLabel->setText(m_stationData->callCode);
        ui->channelLabel->setText(m_stationData->strChannel);
        ui->txLabel->setText(m_stationData->strTx + " KHz");
        ui->rxLabel->setText(m_stationData->strRx + " KHz");
    }
    else if (ui->manualRadio->isChecked())
    {
        // manual按钮选中时，设置manual的文本
        ui->nameLabel->setText(m_manualDate->name);
        ui->callCodeLabel->setText(m_manualDate->callCode);
        ui->channelLabel->setText(m_manualDate->strChannel);
        ui->txLabel->setText(m_manualDate->strTx + " KHz");
        ui->rxLabel->setText(m_manualDate->strRx + " KHz");
    }
}
/****************************************************************************
**
** 函数名称：CallView::receiveButtonClickedSlot
** 功能概述: 选择被叫模式
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallView:: receiveButtonClickedSlot()
{
    Logging::get()->info("CallView::receiveButtonClickedSlot");

    // 接收按钮按下时，接收按钮设为高亮,呼叫按钮设为灰色
    ui->callBtn->setIcon(QIcon(":/images/images/Call_Bnt_SelNo.png"));
    ui->receiveBtn->setIcon(QIcon(":/images/images/Receive_Bnt_SelYes.png"));
    m_callOrReceive = 0;


    if(m_callOrReceive==1) //主叫
      { g_mainWorkFlow->isCallRadio=1;CallClass::get()->setIsCall(true);}
    else//被叫
      { g_mainWorkFlow->isCallRadio=0;CallClass::get()->setIsCall(false);}

    // 获取individual、station和manual的临时数据
    m_stationData = &m_recvModeStaionDate;
    m_individualDate = &m_recvModeIndividualDate;
    m_manualDate = &m_recvModeManualDate;
    
    if (ui->individualRadio->isChecked())
    {
        // individual按钮选中时，设置individual的文本信息    
        ui->nameLabel->setText(m_individualDate->name);
        ui->callCodeLabel->setText(m_individualDate->callCode);
        ui->channelLabel->setText(m_individualDate->strChannel);
        ui->txLabel->setText(m_individualDate->strTx + " KHz");
        ui->rxLabel->setText(m_individualDate->strRx + " KHz");
    }
    else if (ui->stationRadio->isChecked())
    {
        // station按钮选中时，设置station的文本信息
        ui->nameLabel->setText(m_stationData->name);
        ui->callCodeLabel->setText(m_stationData->callCode);
        ui->channelLabel->setText(m_stationData->strChannel);
        ui->txLabel->setText(m_stationData->strTx + " KHz");
        ui->rxLabel->setText(m_stationData->strRx + " KHz");
    }
    else if (ui->manualRadio->isChecked())
    {
        // manual按钮选中时，设置manul的文本信息
        ui->nameLabel->setText(m_manualDate->name);
        ui->callCodeLabel->setText(m_manualDate->callCode);
        ui->channelLabel->setText(m_manualDate->strChannel);
        ui->txLabel->setText(m_manualDate->strTx + " KHz");
        ui->rxLabel->setText(m_manualDate->strRx + " KHz");
    }
}
/****************************************************************************
**
** 函数名称：CallView::cancelButtonClickedSlot
** 功能概述: 退出CALL界面
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallView:: cancelButtonClickedSlot()
{
    Logging::get()->info("CallView::cancelButtonClickedSlot");

    // 取消按钮按下时，直接跳转到Home页面
    QMap <QString, QString> paraMap;
    emit afterPageSignal(CALL_VIEW_NAME, HOME_VIEW_NAME, paraMap);
}
/****************************************************************************
**
** 函数名称：CallView::frontPageSlot
** 功能概述: 打开页面时更新页面数据
** 参数说明： thisID：起始页面， fowordID：目标页面， paraMap：传递参数
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void  CallView::frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap)
{
    if (fowordID != CALL_VIEW_NAME)
    {
        return;
    }
    
    Logging::get()->info("CallView::frontPageSlot");
    
    // 初始化UI界面
    if (thisID == HOME_VIEW_NAME)
    {
        if (paraMap.isEmpty())
        {
            if (ui->sfecRadio->isChecked())
                ui->sfecRadio->setChecked(false);
                
            if (ui->bfecRadio->isChecked())
                ui->bfecRadio->setChecked(false);
                
            ui->arqRadio->setChecked(true);
            ui->arqRadio->setFocus();
            ui->individualRadio->setChecked(true);
            m_callOrReceive = 1;
            ui->homeBtn->setIcon(QIcon(":/images/home_normal"));
        }
        else
        {
            QString callMode = paraMap[Constants::CALL_SET_CALL_MODE];
            ui->manualRadio->setChecked(true);
            
            if (callMode.toLower() == "bfec")
            {
                // BFEC
                m_callMode = 2;
                ui->arqRadio->setChecked(false);
                ui->sfecRadio->setChecked(false);
                ui->bfecRadio->setChecked(true);
                ui->sfecRadio->setFocus();
            }
            else if (callMode.toLower() == "sfec")
            {
                // SFEC
                m_callMode = 3;
                ui->arqRadio->setChecked(false);
                ui->sfecRadio->setChecked(true);
                ui->bfecRadio->setChecked(false);
                ui->bfecRadio->setFocus();
            }
            else
            {
                // ARQ
                m_callMode = 1;
                ui->arqRadio->setChecked(true);
                ui->sfecRadio->setChecked(false);
                ui->bfecRadio->setChecked(false);
                ui->arqRadio->setFocus();
            }
            
            m_callOrReceive = paraMap[CALL_OR_RECEIVE].toInt();
            
            if (m_callOrReceive)
            {
                // 主呼模式时，设置呼叫按钮为高亮，接收按钮为灰色
                ui->receiveBtn->setIcon(QIcon(":/images/images/Receive_Bnt_SelNo.png"));
                ui->callBtn->setIcon(QIcon(":/images/images/Call_Bnt_SelYes.png"));

                // 设置m_stationData、m_individualDate、m_manualDate的值
                m_stationData = &m_callModeStaionDate;
                m_individualDate = &m_callModeIndividualDate;
                m_manualDate = &m_callModeManualDate;
            }
            else
            {
                // 被呼模式时，设置接收按钮为高亮，呼叫按钮为灰色
                ui->callBtn->setIcon(QIcon(":/images/images/Call_Bnt_SelNo.png"));
                ui->receiveBtn->setIcon(QIcon(":/images/images/Receive_Bnt_SelYes.png"));

                // 设置m_stationData、m_individualDate、m_manualDate的值
                m_stationData = &m_recvModeStaionDate;
                m_individualDate = &m_recvModeIndividualDate;
                m_manualDate = &m_recvModeManualDate;
            }
            
            // 设置name和callcode的值，如果callcode不为空而name为空的情况下，
            // 则将callcode的值赋给name。
            QString name = paraMap[Constants::MESSAEGS_LIST_COL_NAME];
            QString callcode = paraMap[Constants::MESSAEGS_LIST_COL_CALLCODE];
            if(name.isEmpty() && !callcode.isEmpty())
            {
                name = callcode;
            }
            m_manualDate->name = name;
            m_manualDate->callCode = callcode;

            // 设置通道的值
            m_manualDate->strChannel = paraMap[Constants::MESSAEGS_LIST_COL_CHANNEL];

            // 设置TX和RX的值，如果TX为空RX不为空，则将RX的值赋给TX，如果RX为空而TX不为空，
            // 则将TX的值赋给RX
            QString tx = paraMap[Constants::MESSAEGS_LIST_COL_TX];
            QString rx = paraMap[Constants::MESSAEGS_LIST_COL_RX];
            if (!tx.isEmpty() && rx.isEmpty())
            {
                rx = tx;
            }
            else if (tx.isEmpty() && !rx.isEmpty())
            {
                tx = rx;
            }
            
            m_manualDate->strTx  = tx;
            m_manualDate->strRx = rx;

            // 设置页面上的文本
            ui->nameLabel->setText(m_manualDate->name);
            ui->callCodeLabel->setText(m_manualDate->callCode);
            ui->channelLabel->setText(m_manualDate->strChannel);
            ui->txLabel->setText(m_manualDate->strTx + " KHz");
            ui->rxLabel->setText(m_manualDate->strRx + " KHz");
            ui->nameTitle->setText(tr("Name"));
            return;
        }
    }
    else if (thisID == FREQUENCY_VIEW)
    {
        m_callOrReceive = paraMap[CALL_OR_RECEIVE].toInt();
    }
    else
        return;
        
    if (m_callOrReceive)
    {
        // 设置主呼时，呼叫和接收按钮的图标以及m_stationData、m_individualDate和m_manualDate的值
        ui->receiveBtn->setIcon(QIcon(":/images/images/Receive_Bnt_SelNo.png"));
        ui->callBtn->setIcon(QIcon(":/images/images/Call_Bnt_SelYes.png"));
        m_stationData = &m_callModeStaionDate;
        m_individualDate = &m_callModeIndividualDate;
        m_manualDate = &m_callModeManualDate;
    }
    else
    {
        // 设置被呼时，呼叫和接收按钮的图标以及m_stationData、m_individualDate和m_manualDate的值
        ui->callBtn->setIcon(QIcon(":/images/images/Call_Bnt_SelNo.png"));
        ui->receiveBtn->setIcon(QIcon(":/images/images/Receive_Bnt_SelYes.png"));
        m_stationData = &m_recvModeStaionDate;
        m_individualDate = &m_recvModeIndividualDate;
        m_manualDate = &m_recvModeManualDate;
    }
    
    if (thisID == FREQUENCY_VIEW)
    {
        if (ui->individualRadio->isChecked())
        {
            QString name = paraMap["name"];
            QString callcode = paraMap["callCode"];
            if(name.isEmpty() && !callcode.isEmpty())
            {
                name = callcode;
            }
            m_individualDate->name = name;
            m_individualDate->callCode = callcode;

            m_individualDate->strChannel = paraMap["channel"];
            QString tx = paraMap["tx"];
            QString rx = paraMap["rx"];
            
            if (!tx.isEmpty() && rx.isEmpty())
            {
                rx = tx;
            }
            else if (tx.isEmpty() && !rx.isEmpty())
            {
                tx = rx;
            }
            
            m_individualDate->strTx = tx;
            m_individualDate->strRx = rx;
        }
        else if (ui->stationRadio->isChecked())
        {
            QString name = paraMap["name"];
            QString callcode = paraMap["callCode"];
            if(name.isEmpty() && !callcode.isEmpty())
            {
                name = callcode;
            }
            m_stationData->name = name;
            m_stationData->callCode = callcode;
            m_stationData->strChannel = paraMap["channel"];
            QString tx = paraMap["tx"];
            QString rx = paraMap["rx"];
            
            if (!tx.isEmpty() && rx.isEmpty())
            {
                rx = tx;
            }
            else if (tx.isEmpty() && !rx.isEmpty())
            {
                tx = rx;
            }
            
            m_stationData->strTx = tx;
            m_stationData->strRx = rx;
        }
        else if (ui->manualRadio->isChecked())
        {
            QString name = paraMap["name"];
            QString callcode = paraMap["callCode"];
            if(name.isEmpty() && !callcode.isEmpty())
            {
                name = callcode;
            }
            m_manualDate->name = name;
            m_manualDate->callCode = callcode;
            m_manualDate->strChannel = paraMap["channel"];
            QString tx = paraMap["tx"];
            QString rx = paraMap["rx"];
            
            if (!tx.isEmpty() && rx.isEmpty())
            {
                rx = tx;
            }
            else if (tx.isEmpty() && !rx.isEmpty())
            {
                tx = rx;
            }
            
            m_manualDate->strTx  = tx;
            m_manualDate->strRx = rx;
        }
    }
    
    if (ui->individualRadio->isChecked())
    {
        ui->nameLabel->setText(m_individualDate->name);
        ui->callCodeLabel->setText(m_individualDate->callCode);
        ui->channelLabel->setText(m_individualDate->strChannel);
        ui->txLabel->setText(m_individualDate->strTx + " KHz");
        ui->rxLabel->setText(m_individualDate->strRx + " KHz");
        QPixmap pix1(":/images/images/Call_Info_Name.png");
        ui->nameTitle->setPixmap(pix1);
    }
    else if (ui->stationRadio->isChecked())
    {
        ui->nameLabel->setText(m_stationData->name);
        ui->callCodeLabel->setText(m_stationData->callCode);
        ui->channelLabel->setText(m_stationData->strChannel);
        ui->txLabel->setText(m_stationData->strTx + " KHz");
        ui->rxLabel->setText(m_stationData->strRx + " KHz");
        QPixmap pix2(":/images/Call_Info_Station");
        ui->nameTitle->setPixmap(pix2);
    }
    else if (ui->manualRadio->isChecked())
    {
        ui->nameLabel->setText(m_manualDate->name);
        ui->callCodeLabel->setText(m_manualDate->callCode);
        ui->channelLabel->setText(m_manualDate->strChannel);
        ui->txLabel->setText(m_manualDate->strTx + " KHz");
        ui->rxLabel->setText(m_manualDate->strRx + " KHz");
        ui->nameTitle->setText(tr("Name"));
    }
}
/****************************************************************************
**
** 函数名称：CallView::eventFilter
** 功能概述: 事件监听函数，响应用户键盘操作。
** 参数说明  watched：发送方， event：事件数据
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool CallView::eventFilter(QObject* watched, QEvent* event)
{
    Logging::get()->info("CallView::eventFilter");
    // 设置焦点切换顺序列表
    QStringList nameList;
    nameList << "arqRadio" << "sfecRadio" << "bfecRadio" << "individualRadio"
             << "stationRadio" << "manualRadio"
             << "okBtn" << "cancelBtn" << "homeBtn" << "callBtn" << "receiveBtn";
    QList<QStringList> names;
    QStringList group1 ;
    group1 << "arqRadio" << "sfecRadio" << "bfecRadio";
    QStringList group2 ;
    group2 << "individualRadio" << "stationRadio" << "manualRadio";
    QStringList group3 ;
    group3 << "okBtn" << "cancelBtn";
    QStringList group4;
    group4 << "homeBtn" << "callBtn" << "receiveBtn";
    names << group1 << group2 << group3 << group4;
    QKeyEvent* key_event = static_cast<QKeyEvent*>(event);
    int a = key_event->key();
    
    switch (a)
    {
    case Qt::Key_A:
    case Qt::Key_F:
    case Qt::Key_B:
    {
        if (QEvent::KeyPress == event->type()) // 按下时键屏蔽
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type()) // 弹起时键屏蔽
        {
            return true;
        }
        
        // 默认键值51 响应一次
        QKeyEvent* key_event = static_cast<QKeyEvent*>(event);
        
        // 判断是否为alt组合键
        if (key_event->modifiers() & Qt::AltModifier)
        {
            // 首先将选中的按钮设置为未选中状态
            if (ui->arqRadio->isChecked())
                ui->arqRadio->setChecked(false);
                
            if (ui->sfecRadio->isChecked())
                ui->sfecRadio->setChecked(false);
                
            if (ui->bfecRadio->isChecked())
                ui->bfecRadio->setChecked(false);
        
            if (a == Qt::Key_A)
            {
                // Alt+A: 选中ARQ按钮
                ui->arqRadio->setFocus();
                m_callMode = 1;
            }
            else if (a == Qt::Key_F)
            {
                // Alt+F: 选中SFEC按钮
                ui->sfecRadio->setFocus();
                m_callMode = 2;
            }
            else if (a == Qt::Key_B)
            {
                // Alt+B: 选中BFEC按钮
                ui->bfecRadio->setFocus();
                m_callMode = 3;
            }
            
            // 最后再将Home键设为普通状态
            ui->homeBtn->setIcon(QIcon(":/images/home_normal"));
        }
        
        break;
    }
    
    case Qt::Key_I:
    case Qt::Key_S:
    case Qt::Key_M:
    {
        if (QEvent::KeyPress == event->type()) // 按下时键屏蔽
        {
            return true;
        }
        
        if (QEvent::KeyRelease == event->type()) // 弹起时键屏蔽
        {
            return true;
        }
        
        // 默认键值51 响应一次
        QKeyEvent* key_event = static_cast<QKeyEvent*>(event);
        
        // 判断是否为alt组合键
        if (key_event->modifiers() & Qt::AltModifier)
        {
            QMap <QString, QString> paraMap;

            // 设置主叫被叫参数
            QString flag;
            
            if (m_callOrReceive)
            {
                flag += "1";
            }
            else
            {
                flag += "0";
            }
            
            paraMap.insert(CALL_OR_RECEIVE, flag);
            QString forwardId;
            
            if (a == Qt::Key_I)
            {
                // Alt+I键，将Individual按钮选中，并设置页面右侧通信信息文本，
                // 然后跳转到个人选择页面
                ui->nameLabel->setText(m_individualDate->name);
                ui->callCodeLabel->setText(m_individualDate->callCode);
                ui->channelLabel->setText(m_individualDate->strChannel);
                ui->txLabel->setText(m_individualDate->strTx + " KHz");
                ui->rxLabel->setText(m_individualDate->strRx + " KHz");
                QPixmap pix1(":/images/images/Call_Info_Name.png");
                ui->nameTitle->setPixmap(pix1);
                ui->individualRadio->setFocus();
                ui->individualRadio->setChecked(true);
                forwardId = INDIVIDUAL_SELECT_VIEW;
            }
            else if (a == Qt::Key_S)
            {
                // Alt+S键，将Station按钮选中，并设置页面右侧通信信息文本，
                // 然后跳转到站台选择页面
                ui->nameLabel->setText(m_stationData->name);
                ui->callCodeLabel->setText(m_stationData->callCode);
                ui->channelLabel->setText(m_stationData->strChannel);
                ui->txLabel->setText(m_stationData->strTx + " KHz");
                ui->rxLabel->setText(m_stationData->strRx + " KHz");
                QPixmap pix2(":/images/Call_Info_Station");
                ui->nameTitle->setPixmap(pix2);
                ui->stationRadio->setFocus();
                ui->stationRadio->setChecked(true);
                forwardId = STATION_SELECT_VIEW;
            }
            else if (a == Qt::Key_M)
            {
                // Alt+M键，将Manual按钮选中，并设置页面右侧通信信息文本，
                // 然后跳转到站台选择页面            
                ui->nameLabel->setText(m_manualDate->name);
                ui->callCodeLabel->setText(m_manualDate->callCode);
                ui->channelLabel->setText(m_manualDate->strChannel);
                ui->txLabel->setText(m_manualDate->strTx + " KHz");
                ui->rxLabel->setText(m_manualDate->strRx + " KHz");
                ui->nameTitle->setText(tr("Name"));
                ui->manualRadio->setFocus();
                ui->manualRadio->setChecked(true);
                forwardId = MANUAL_FREQUENCY_VIEW;
            }
            
            // 跳转到相应页面
            emit afterPageSignal(CALL_VIEW_NAME, forwardId, paraMap);
        }
        
        break;
    }
    
    case Qt::Key_Tab: // Tab键时切换页面控件焦点
    {
        // 键按下和弹起时屏蔽
        if (QEvent::KeyPress == event->type() || QEvent::KeyRelease == event->type())
        {
            return true;
        }
        
        // 根据焦点切换列表切换控件的焦点
        for (int i = 0; i < nameList.length(); i++)
        {
            QWidget* widget = findChild<QWidget*>(nameList.at(i));
            
            // 当前控件为焦点选中状态
            if (widget && widget->hasFocus())
            {
                // 如果是通信类型选择按钮, 则跳转到站台类型按钮个人、站台和人工设置按钮，则将焦点跳到选中的那个按钮上
                if (nameList.at(i) == "arqRadio" || nameList.at(i) == "sfecRadio" || nameList.at(i) == "bfecRadio")
                {
                    if (ui->individualRadio->isChecked())
                    {
                        ui->individualRadio->setFocus();
                    }
                    else if (ui->stationRadio->isChecked())
                    {
                        ui->stationRadio->setFocus();
                    }
                    else if (ui->manualRadio->isChecked())
                    {
                        ui->manualRadio->setFocus();
                    }
                }
                // 如果是站台类型选择按钮，个人、站台和人工设置按钮，则将焦点跳到OK按钮上
                else if (nameList.at(i) == "individualRadio" || nameList.at(i) == "stationRadio" || nameList.at(i) == "manualRadio")
                {
                    ui->okBtn->setFocus();
                    return true;
                }
                // 如果是Cancel和OK按钮组，则将焦点跳转到Home按钮
                else if (nameList.at(i) == "cancelBtn" || nameList.at(i) == "okBtn")
                {
                    ui->homeBtn->setFocus();
                    QToolButton* button = static_cast<QToolButton*>(ui->homeBtn);
                    button->setIcon(QIcon(":/images/home_hover"));
                }
                // 如果是Home、呼叫和接收按钮组，则将焦点跳转到通信类型组中选中的按钮，并将当前选中的按钮状态设为不选中
                else if (nameList.at(i) == "homeBtn" || nameList.at(i) == "callBtn" || nameList.at(i) == "receiveBtn")
                {
                    QString image;
                    
                    if (nameList.at(i) == "homeBtn")
                    {
                        QToolButton* button = static_cast<QToolButton*>(widget);
                        image = ":/images/home_normal";
                        button->setIcon(QIcon(image));
                    }
                    else  if (nameList.at(i) == "callBtn")
                    {
                        if (!m_callOrReceive)
                        {
                            QToolButton* button = static_cast<QToolButton*>(widget);
                            image = ":/images/images/Call_Bnt_SelNo.png";
                            button->setIcon(QIcon(image));
                        }
                    }
                    else  if (nameList.at(i) == "receiveBtn")
                    {
                        if (m_callOrReceive)
                        {
                            QToolButton* button = static_cast<QToolButton*>(widget);
                            image = ":/images/images/Receive_Bnt_SelNo.png";
                            button->setIcon(QIcon(image));
                        }
                    }
                    
                    if (ui->arqRadio->isChecked())
                    {
                        ui->arqRadio->setFocus();
                    }
                    else if (ui->bfecRadio->isChecked())
                    {
                        ui->bfecRadio->setFocus();
                    }
                    else if (ui->sfecRadio->isChecked())
                    {
                        ui->sfecRadio->setFocus();
                    }
                }
                
                break;
            }
        }
        
        break;
    }
    
    // 右键
    case Qt::Key_Right:
    {
        // 屏蔽键按下和弹起
        if (QEvent::KeyPress == event->type() || QEvent::KeyRelease == event->type())
        {
            return true;
        }
        
        // 根据焦点切换列表切换控件的焦点
        for (int i = 0; i < names.length(); i++)
        {
            // 当焦点在站台类型选择按钮组时不用处理, 通信类型按钮组由于button group自带焦点切换功能，也不用处理
            if (i <= 1) continue;
            
            for (int j = 0; j < names.at(i).length(); j++)
            {
                QWidget* widget = findChild<QWidget*>(names.at(i).at(j));
                
                if (widget && widget->hasFocus())
                {
                    // 如果是最后一个控件，则不需要处理
                    if (j == names.at(i).length() - 1)
                    {
                        return true;
                    }
                    
                    QString image;
                    if (widget->objectName() == "homeBtn")
                    {
                        // 如果当前焦点在Home按钮，则将当前Home按钮的高亮图片变为普通图片
                        QToolButton* button = static_cast<QToolButton*>(widget);
                        image = ":/images/home_normal";
                        button->setIcon(QIcon(image));
                    }
                    else  if (widget->objectName() == "callBtn")
                    {
                        // 如果是当前焦点在呼叫按钮,而且被叫模式时，将呼叫按钮的高亮图片变为灰色
                        if (!m_callOrReceive)
                        {
                            QToolButton* button = static_cast<QToolButton*>(widget);
                            image = ":/images/images/Call_Bnt_SelNo.png";
                            button->setIcon(QIcon(image));
                        }
                    }
                    else  if (widget->objectName() == "receiveBtn")
                    {
                        // 如果是当前焦点在接收按钮,而且主叫模式时，将接收按钮的高亮图片变为灰色
                        if (m_callOrReceive)
                        {
                            QToolButton* button = static_cast<QToolButton*>(widget);
                            image = ":/images/images/Receive_Bnt_SelNo.png";
                            button->setIcon(QIcon(image));
                        }
                    }
                    
                    // 获取下一个控件对象
                    int next = j + 1;
                    QWidget* nextWidget = findChild<QWidget*>(names.at(i).at(next));
                    nextWidget->setFocus();
                    
                    if (nextWidget->objectName() == "homeBtn")
                    {
                        // 当下一个控件为home按钮时，则将home按钮的图片设为高亮图片
                        QToolButton* button = static_cast<QToolButton*>(nextWidget);
                        image = ":/images/home_hover";
                        button->setIcon(QIcon(image));
                    }
                    else  if (nextWidget->objectName() == "callBtn")
                    {
                         // 当下一个控件为呼叫按钮时，则将呼叫按钮的图片设为高亮图片
                        QToolButton* button = static_cast<QToolButton*>(nextWidget);
                        image = ":/images/images/Call_Bnt_SelYes.png";
                        button->setIcon(QIcon(image));
                    }
                    else  if (nextWidget->objectName() == "receiveBtn")
                    {
                        // 当下一个控件为接收按钮时，则将接收按钮的图片设为高亮图片
                        QToolButton* button = static_cast<QToolButton*>(nextWidget);
                        image = ":/images/images/Receive_Bnt_SelYes.png";
                        button->setIcon(QIcon(image));
                    }
                    
                    return true;
                }
            }
        }
        
        break;
    }
    // 向下键
    case Qt::Key_Down:
    {
        // 屏蔽键按下和弹起
        if (QEvent::KeyPress == event->type() || QEvent::KeyRelease == event->type())
        {
            return true;
        }
        
        // 根据焦点切换列表切换控件的焦点
        for (int j = 0; j < names.at(1).length(); j++)
        {
            QWidget* widget = findChild<QWidget*>(names.at(1).at(j));
            
            if (widget && widget->hasFocus())
            {
                // 如果当前焦点在站台类型按钮组上，则设置m_keyupDown的值，用于判断该组按钮的点击事件是否有快捷键触发
                if ((widget->objectName() == "manualRadio") || (widget->objectName() == "stationRadio")
                    || (widget->objectName() == "individualRadio"))
                {
                    m_keyupDown = true;
                }
                
                // 如果当前焦点在个人按钮上，则将站台的信息更新的UI
                if (widget->objectName() == "individualRadio")
                {
                    ui->nameLabel->setText(m_stationData->name);
                    ui->callCodeLabel->setText(m_stationData->callCode);
                    ui->channelLabel->setText(m_stationData->strChannel);
                    ui->txLabel->setText(m_stationData->strTx + " KHz");
                    ui->rxLabel->setText(m_stationData->strRx + " KHz");
                    QPixmap pix2(":/images/Call_Info_Station");
                    ui->nameTitle->setPixmap(pix2);
                }
                else if (widget->objectName() == "stationRadio")
                {
                    // 如果当前焦点在个人按钮上，则将人工设置站台的信息更新的UI
                    ui->nameLabel->setText(m_manualDate->name);
                    ui->callCodeLabel->setText(m_manualDate->callCode);
                    ui->channelLabel->setText(m_manualDate->strChannel);
                    ui->txLabel->setText(m_manualDate->strTx + " KHz");
                    ui->rxLabel->setText(m_manualDate->strRx + " KHz");
                    ui->nameTitle->setText(tr("Name"));
                }
            }
        }
        
        return true;
    }
    
    // 向上键
    case Qt::Key_Up:
    {
        // 屏蔽键按下和弹起
        if (QEvent::KeyPress == event->type() || QEvent::KeyRelease == event->type())
        {
            return true;
        }
        
        // 根据焦点切换列表切换控件的焦点
        for (int j = 0; j < names.at(1).length(); j++)
        {
            QWidget* widget = findChild<QWidget*>(names.at(1).at(j));
            
            if (widget && widget->hasFocus())
            {
                // 如果当前焦点在站台类型按钮组上，则设置m_keyupDown的值，用于判断该组按钮的点击事件是否有快捷键触发
                if ((widget->objectName() == "manualRadio") || (widget->objectName() == "stationRadio")
                    || (widget->objectName() == "individualRadio"))
                {
                    m_keyupDown = true;
                }
                
                // 如果当前焦点在人工设置按钮上，则将个人的信息更新的UI
                if (widget->objectName() == "manualRadio")
                {
                    ui->nameLabel->setText(m_stationData->name);
                    ui->callCodeLabel->setText(m_stationData->callCode);
                    ui->channelLabel->setText(m_stationData->strChannel);
                    ui->txLabel->setText(m_stationData->strTx + " KHz");
                    ui->rxLabel->setText(m_stationData->strRx + " KHz");
                    QPixmap pix2(":/images/Call_Info_Station");
                    ui->nameTitle->setPixmap(pix2);
                }
                else if (widget->objectName() == "stationRadio")
                {
                    // 如果当前焦点在站台按钮上，则将个人的信息更新的UI
                    ui->nameLabel->setText(m_individualDate->name);
                    ui->callCodeLabel->setText(m_individualDate->callCode);
                    ui->channelLabel->setText(m_individualDate->strChannel);
                    ui->txLabel->setText(m_individualDate->strTx + " KHz");
                    ui->rxLabel->setText(m_individualDate->strRx + " KHz");
                    QPixmap pix1(":/images/images/Call_Info_Name.png");
                    ui->nameTitle->setPixmap(pix1);
                }
            }
        }
        
        break;
    }
    
    // 回退键和向左键
    case Qt::Key_Backtab:
    case Qt::Key_Left:
    {
        // 屏蔽键按下和弹起
        if (QEvent::KeyPress == event->type() || QEvent::KeyRelease == event->type())
        {
            return true;
        }
        
        // 根据焦点切换列表切换控件的焦点
        for (int i = 0; i < names.length(); i++)
        {
            // 当焦点在站台类型选择按钮组时不用处理,另外通信类型按钮组由于button group自带焦点切换
            // 功能，也不用处理
            if (i <= 1) continue;
            
            for (int j = 0; j < names.at(i).length(); j++)
            {
                QWidget* widget = findChild<QWidget*>(names.at(i).at(j));
                
                if (widget && widget->hasFocus())
                {
                    // 当焦点在第一个，不用处理
                    if (j == 0)
                    {
                        return true;
                    }
                    
                    QString image;
                    
                    // 如果当前焦点在Home按钮，则将当前Home按钮的高亮图片变为普通图片
                    if (widget->objectName() == "homeBtn")
                    {
                        QToolButton* button = static_cast<QToolButton*>(widget);
                        image = ":/images/home_normal";
                        button->setIcon(QIcon(image));
                    }
                    else  if (widget->objectName() == "callBtn")
                    {
                        // 如果是当前焦点在呼叫按钮,而且被叫模式时，将呼叫按钮的高亮图片变为灰色
                        if (!m_callOrReceive)
                        {
                            QToolButton* button = static_cast<QToolButton*>(widget);
                            image = ":/images/images/Call_Bnt_SelNo.png";
                            button->setIcon(QIcon(image));
                        }
                    }
                    else  if (widget->objectName() == "receiveBtn")
                    {
                        if (m_callOrReceive)
                        {
                            // 如果是当前焦点在接收按钮,而且主叫模式时，将接收按钮的高亮图片变为灰色
                            QToolButton* button = static_cast<QToolButton*>(widget);
                            image = ":/images/images/Receive_Bnt_SelNo.png";
                            button->setIcon(QIcon(image));
                        }
                    }
                    
                    // 获取上一个控件对象
                    int previous = j - 1;
                    QWidget* previousWidget = findChild<QWidget*>(names.at(i).at(previous));
                    previousWidget->setFocus();
                    
                    if (previousWidget->objectName() == "homeBtn")
                    {
                        // 当上一个控件为home按钮时，则将home按钮的图片设为高亮图片
                        QToolButton* button = static_cast<QToolButton*>(previousWidget);
                        image = ":/images/home_hover";
                        button->setIcon(QIcon(image));
                    }
                    else  if (previousWidget->objectName() == "callBtn")
                    {
                        // 当上一个控件为呼叫按钮时，则将呼叫按钮的图片设为高亮图片
                        QToolButton* button = static_cast<QToolButton*>(previousWidget);
                        image = ":/images/images/Call_Bnt_SelYes.png";
                        button->setIcon(QIcon(image));
                    }
                    else  if (previousWidget->objectName() == "receiveBtn")
                    {
                        // 当上一个控件为接收按钮时，则将接收按钮的图片设为高亮图片
                        QToolButton* button = static_cast<QToolButton*>(previousWidget);
                        image = ":/images/images/Receive_Bnt_SelYes.png";
                        button->setIcon(QIcon(image));
                    }
                    
                    return true;
                }
            }
        }
        
        break;
    }
    
    // 回车键
    case Qt::Key_Return:
    case Qt::Key_Enter:
    {
        // 屏蔽键按下
        if (QEvent::KeyPress == event->type())
        {
            return true;
        }
        // 屏蔽键弹起
        else if (QEvent::KeyRelease == event->type())
        {
            return true;
        }
        
        // 根据焦点切换列表进行页面跳转
        for (int i = 0; i < nameList.length(); i++)
        {
            QWidget* widget = findChild<QWidget*>(nameList.at(i));
            
            if (widget && widget->hasFocus())
            {
                // 如果当前焦点在通信类型按钮组，则分别跳转到个人、站台或者人工设置页面
                if (nameList.at(i) == "individualRadio" || nameList.at(i) == "stationRadio" || nameList.at(i) == "manualRadio")
                {
                    QMap <QString, QString> paraMap;
                    QString flag;
                    
                    if (m_callOrReceive)
                    {
                        flag += "1";
                    }
                    else
                    {
                        flag += "0";
                    }
                    
                    paraMap.insert(CALL_OR_RECEIVE, flag);
                    QString forwardId;
                    
                    if (ui->individualRadio->isChecked())
                    {
                        forwardId = INDIVIDUAL_SELECT_VIEW;
                    }
                    else if (ui->stationRadio->isChecked())
                    {
                        forwardId = STATION_SELECT_VIEW;
                    }
                    else if (ui->manualRadio->isChecked())
                    {
                        forwardId = MANUAL_FREQUENCY_VIEW;
                    }
                    
                    emit afterPageSignal(CALL_VIEW_NAME, forwardId, paraMap);
                }
                
                // 如果当前焦点在Home按钮，则模拟home按钮点击事件跳转到home页面
                if (nameList.at(i) == "homeBtn")
                {
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                }
                else if (nameList.at(i) == "callBtn")
                {
                    // 如果当前焦点在呼叫按钮，但是接收模式时，则将接收按钮图标设为高亮，呼叫按钮设为灰色
                    if (!m_callOrReceive)
                    {
                        ui->receiveBtn->setIcon(QIcon(":/images/images/Receive_Bnt_SelNo.png"));
                        ui->callBtn->setIcon(QIcon(":/images/images/Call_Bnt_SelYes.png"));
                        m_callOrReceive = !m_callOrReceive;
                    }
                }
                else if (nameList.at(i) == "receiveBtn")
                {
                    // 如果当前焦点在接收按钮，但是呼叫模式时，则将呼叫按钮图标设为高亮，接收按钮设为灰色
                    if (m_callOrReceive)
                    {
                        ui->callBtn->setIcon(QIcon(":/images/images/Call_Bnt_SelNo.png"));
                        ui->receiveBtn->setIcon(QIcon(":/images/images/Receive_Bnt_SelYes.png"));
                        m_callOrReceive = !m_callOrReceive;
                    }
                }
                else if (nameList.at(i) == "arqRadio" || nameList.at(i) == "sfecRadio" || nameList.at(i) == "bfecRadio")
                {
                    // 如果当前焦点是在通信类型选择按钮组，则将触发回车事件的按钮设为高亮选中状态
                    if (ui->arqRadio->isChecked())
                        ui->arqRadio->setChecked(false);
                        
                    if (ui->sfecRadio->isChecked())
                        ui->sfecRadio->setChecked(false);
                        
                    if (ui->bfecRadio->isChecked())
                        ui->bfecRadio->setChecked(false);
                        
                    if (nameList.at(i) == "arqRadio")
                    {
                        m_callMode = 1;
                    }
                    else if (nameList.at(i) == "sfecRadio")
                    {
                        m_callMode = 2;
                    }
                    else if (nameList.at(i) == "bfecRadio")
                    {
                        m_callMode = 3;
                    }
                    
                    QRadioButton* button = static_cast<QRadioButton*>(widget);
                    button->click();
                }
                
                break;
            }
        }
        
        break;
    }
    
    // 退出键
    case Qt::Key_Escape:
    {
        // 屏蔽键按下
        if (QEvent::KeyPress == event->type())
        {
            return true;
        }
        // 屏蔽键弹起
        else if (QEvent::KeyRelease == event->type())
        {
            return true;
        }
        
        // 模拟cancel按钮点击事件
        QWidget* widget = findChild<QWidget*>("cancelBtn");
        
        if (widget)
        {
            Button* button = static_cast<Button*>(widget);
            button->click();
        }
        
        break;
    }
    break;
    }
    
    if (a == Qt::Key_Escape)
    {
        return true;
    }
    
    return QWidget::eventFilter(watched, event);
}

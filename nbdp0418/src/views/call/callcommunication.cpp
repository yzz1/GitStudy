#include "callcommunication.h"
#include "ui_callcommunication.h"
#include <QString>
#include <QUuid>
#include <QDateTime>
#include <QDebug>
 #include <QTableWidget>
#include <QTimer>
#include <QEvent>
#include <QKeyEvent>
#include <QToolButton>
#include <QSqlRecord>
#include <QVariant>
#include "logging.h"
#include "transit.h"
#include "widgets/button.h"
#include "widgets/iocmessage.h"
#include "core/database/database.h"
#include "core/utils/sqlitehelper.h"
#include "views/call/commumessagesstyle.h"
#include "models/messagedetaildelegate.h"
#include "core/utils/commonutils.h"
#include "core/utils/intputcheck.h"
#include "core/utils/configutils.h"
#include "views/common/constants.h"
#include "../myCom/mainwindow.h"
#include "../myCom/nbdpWorkFlow.h"

/****************************************************************************
**
** 函数名称：CallCommunication::CallCommunication
** 功能概述: 初始化
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
CallCommunication::CallCommunication(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::CallCommunication)
{
    Logging::get()->info("CallCommunication::CallCommunication ");

    // ui初始化
    ui->setupUi(this);

    // 安装事件过滤器
    this->installEventFilter(this);

    // 初始化消息列表
    m_model = new MessagesModel(this, SQLiteHelper::openConnection());
    m_model->setTable(tr(Constants::COMMUMESSAEGS_DETAIL_TABLE_NAME));
    m_model->setSort(Constants::COMMUMESSAGEDETAILl_INDEX_CDATETIME, Qt::AscendingOrder);
    ui->tableView->setModel(m_model);
    m_row=0;
    CommuMessagesStyle* style = new CommuMessagesStyle();
    MessageDetailDelegate* messageDetailDelegate = new MessageDetailDelegate(0, style);
    messageDetailDelegate->setCommuMessageFlag(true);
    QWidget* widget = findChild<QWidget*>("tableView");
    if (widget)
    {
        messageDetailDelegate->setTableWidget(widget);
    }
    ui->tableView->setItemDelegate(messageDetailDelegate);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setColumnHidden(Constants::COMMUMESSAGEDETAILl_INDEX_UUID, true);
    ui->tableView->setColumnHidden(Constants::COMMUMESSAGEDETAILl_INDEX_FKEY, true);
    ui->tableView->setColumnHidden(Constants::COMMUMESSAGEDETAILl_INDEX_SENDSTATUS, true);
    ui->tableView->setColumnHidden(Constants::COMMUMESSAGEDETAILl_INDEX_INOUT, true);
    ui->tableView->setColumnHidden(Constants::COMMUMESSAGEDETAILl_INDEX_CDATETIME, true);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->verticalHeader()->hide();
    QHeaderView* header = ui->tableView->horizontalHeader();
    header->setStretchLastSection(true);
    ui->tableView->resizeRowsToContents();

    // 连接信号和槽
    connect(ui->homeTBnt, SIGNAL(clicked()), this, SLOT(homeClickedSlot()));
    connect(ui->optionBnt, SIGNAL(clicked()), this, SLOT(showOptionMenu()));
    connect(ui->insertBnt, SIGNAL(clicked()), this, SLOT(showInsertMenu()));
    connect(ui->sendBnt, SIGNAL(clicked()), this, SLOT(sendMessage()));
    connect(ui->MacroBnt, SIGNAL(clicked()), this, SLOT(macroMenu()));
    connect(ui->phrasebookBnt, SIGNAL(clicked()), this, SLOT(phrasebookMessage()));
    connect(ui->loadBnt, SIGNAL(clicked()), this, SLOT(loadMessage()));
    connect(ui->wruBnt, SIGNAL(clicked()), this, SLOT(sendWRU()));
    connect(ui->HRBnt, SIGNAL(clicked()), this, SLOT(sendHR()));
    connect(ui->overBnt, SIGNAL(clicked()), this, SLOT(sendOver()));
    connect(ui->breakBnt, SIGNAL(clicked()), this, SLOT(sendBreak()));
    connect(ui->printBnt, SIGNAL(clicked()), this, SLOT(printClickedSlot()));

    connect(Transit::get(),SIGNAL(SignalLineEditState(bool)),this,SLOT(SlotSetLineEditState(bool)) );
    connect(Transit::get(),SIGNAL(reflashSignal(QString)),this,SLOT(SlotReflashMMSI(QString)));
    connect(Transit::get(),SIGNAL(reflashCallModeSignal(QString)),this,SLOT(SlotReflashCallMode(QString)));
    m_optionMenuStatus = true;
    m_insertMenuStatus = true;
    ui->phrasebookBnt->setHidden(true);
    ui->MacroBnt->setHidden(true);
    ui->loadBnt->setHidden(true);
    ui->insertBnt->setHidden(true);
    ui->printBnt->setHidden(true);
    m_whiteQIconTransmit.addPixmap(QPixmap(":/images/images/Call_Bnt_SelYes.png"), QIcon::Disabled);
    m_grayQIconTransmit.addPixmap(QPixmap(":/images/images/Call_Bnt_SelNo.png"), QIcon::Disabled);
    m_whiteQIconReceive.addPixmap(QPixmap(":/images/images/Receive_Bnt_SelYes.png"), QIcon::Disabled);
    m_grayQIconReceive.addPixmap(QPixmap(":/images/images/Receive_Bnt_SelNo.png"), QIcon::Disabled);
    m_strStyleSheetGray = "border:none;outline: none;color:rgb(86, 74, 74);background: transparent;font: 18pt \"Ubuntu \";";
    ui->receiveBtn->setStyleSheet(m_strStyleSheetGray);
    ui->callBtn->setStyleSheet(m_strStyleSheetGray);
    m_connectFlag = false;
    m_widget = new CallCommunicationwidget();
    connect(m_widget, SIGNAL(okButtonClickedSignal()), this,  SLOT(widgetDataBackSlot()));
    m_commStatusMessage.move((SCREEN_SIZE_WIDTH - m_commStatusMessage.width()) / 2,
                             (SCREEN_SIZE_HEIGHT - m_commStatusMessage.height()) / 2);
    QFont font("Ubuntu", 18, QFont::Bold);
    m_commStatusMessage.SetFont(font);
    //QRegExp rx("([0-9]+9)");
    QRegExp rx("([≡←↑↓△□a-zA-Z0123456789:@().,'=/-+*? ]+$)");
    QValidator* val = new QRegExpValidator(rx, ui->inputEdit);
    ui->inputEdit->setValidator(val);
    connect(ui->inputEdit,SIGNAL(textChanged(QString)),this,SLOT(CheckInputText()));
    //ui->inputEdit->setMaxLength(6);

    m_commuTimer = new QTimer(this);
    connect(m_commuTimer, SIGNAL(timeout()), this, SLOT(SlotTimerUpdate()));
    m_waitSignalTimer = new QTimer(this);
    m_waitSignalTimer->setSingleShot(true);
    connect(m_waitSignalTimer, SIGNAL(timeout()), this, SLOT(SlotSignalWaitTimeOut()));
    connect(Transit::get(),SIGNAL(SignalJianLianEnterReady()),this,SLOT(SlotSignalWaitTimeOut()));
    m_dialogCloseWaitTime = new QTimer(this);
    m_dialogCloseWaitTime->setSingleShot(true);
    connect(m_dialogCloseWaitTime, SIGNAL(timeout()), this, SLOT(SlotDialogCloseTimeout()));
}
void CallCommunication::CheckInputText()
{
       QString currText =ui->inputEdit->text();
       int currCount= currText.count();

       if(currCount > Constants::MAXINPUTSIZE)  //MAXINPUTSIZE
        {
           int position =ui->inputEdit->cursorPosition();
          // QTextCursor textCursor =ui->inputEdit->cursor(); // 此处需加this
           qDebug()<<"remove one";
          currText.remove(position-(currCount-Constants::MAXINPUTSIZE),currCount-Constants::MAXINPUTSIZE);
          ui->inputEdit->setText(currText);

          //textCursor.setPosition(position-(currCount-MAXINPUTSIZE));
          ui->inputEdit->setCursorPosition(currText.size());
        }
}
//yzz
void CallCommunication::SlotReflashMMSI(QString strMMSI)
{
     ui->name->setText(CommonUtils::wordwrap(strMMSI, Constants::NAME_LABEL_LENGTH));
    qDebug()<<"update otherMMSI";
}
void CallCommunication::SlotReflashCallMode(QString strCallMode)
{
    ui->callmode->setText(strCallMode);
    qDebug()<<"update callMode";
}
void CallCommunication::SlotSetLineEditState(bool b)
{
    if(b==false)
         ui->inputEdit->setReadOnly(true);
    else
      { ui->inputEdit->setReadOnly(false); ui->inputEdit->setFocus();}
}


/****************************************************************************
**
** 函数名称：CallCommunication::～CallCommunication
** 功能概述: 析构函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
CallCommunication::~CallCommunication()
{
    Logging::get()->info("CallCommunication::~CallCommunication ");
    delete ui;
}
/****************************************************************************
**
** 函数名称：CallCommunication::showOptionMenu
** 功能概述: 显示option子菜单
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunication::showOptionMenu()
{
    Logging::get()->info("CallCommunication::showOptionMenu ");
    QWidget widget2;
    widget2.show();
    
    // 如果Option菜单处于显示状态，则隐藏，反之就显示。
    if (m_optionMenuStatus == true)
    {
        if (ui->tableView->hasFocus())
        {
            ui->optionBnt->setFocus();
        }
        
        ui->loadBnt->setHidden(false);
        ui->insertBnt->setHidden(false);
        ui->printBnt->setHidden(false);
        ui->insertBnt->setChecked(true);
        ui->loadBnt->setFocus();
        m_optionMenuStatus = false;
    }
    else
    {
        ui->loadBnt->setHidden(true);
        ui->insertBnt->setHidden(true);
        ui->printBnt->setHidden(true);
        m_optionMenuStatus  = true;
    }
}
/****************************************************************************
**
** 函数名称：CallCommunication::showInsertMenu
** 功能概述: 显示insert子菜单
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunication::showInsertMenu()
{
    Logging::get()->info("CallCommunication::showInsertMenu ");
    
    // 如果Insert菜单处于显示状态，则隐藏，反之就显示。
    if (m_insertMenuStatus == true)
    {
        ui->phrasebookBnt->setHidden(false);
        ui->MacroBnt->setHidden(false);
        ui->MacroBnt->setChecked(true);
        m_insertMenuStatus  = false;
        ui->MacroBnt->setFocus();
    }
    else
    {
        ui->phrasebookBnt->setHidden(true);
        ui->MacroBnt->setHidden(true);
        m_insertMenuStatus  = true;
        ui->insertBnt->setFocus();
    }
}
/****************************************************************************
**
** 函数名称：CallCommunication::frontPageSlot
** 功能概述: 打开页面时更新页面数据
** 参数说明： thisID：起始页面， fowordID：目标页面， paraMap：传递参数
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void  CallCommunication::frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap)
{
    // 如果不是跳转到当前页面的信号，则不处理。
    if (fowordID != CALL_COMMUNICATION_VIEW)
    {
        return;
    }
    
    Logging::get()->info("CallCommunication::frontPageSlot");
    m_model->select();
    ui->tableView->setFocus();
    m_paraMap = paraMap;
    QString name = m_paraMap[Constants::MESSAEGS_LIST_COL_NAME];
    ui->name->setText(CommonUtils::wordwrap(name, Constants::NAME_LABEL_LENGTH));
    ui->callmode->setText(m_paraMap[Constants::MESSAEGS_LIST_COL_MODE]);
    QString calltype = (m_paraMap[CALL_OR_RECEIVE] == "1") ? QString("CALL") : QString("RECEIVE");
    
    // 在FEC的接收模式时，界面上除了home以外的所有的按钮都设为不可用。
    bool flag = ((calltype == "RECEIVE") && (m_paraMap[Constants::MESSAEGS_LIST_COL_MODE] != "ARQ"));
    ui->inputEdit->setDisabled(true);
    ui->wruBnt->setDisabled(flag);
    ui->HRBnt->setDisabled(flag);
    ui->overBnt->setDisabled(flag);
    ui->breakBnt->setDisabled(flag);
    ui->sendBnt->setDisabled(flag);
    ui->optionBnt->setDisabled(flag);
    ui->calltype->setText(calltype);

    if( calltype =="RECEIVE" )
       { ui->inputEdit->setDisabled(false); ui->inputEdit->setReadOnly(true); qDebug()<<"lock ok";}
    else
       { ui->inputEdit->setDisabled(false); ui->inputEdit->setReadOnly(false); qDebug()<<"unlock ok";}
    ui->tx->setText(m_paraMap[Constants::MESSAEGS_LIST_COL_TX] + " KHz");
    ui->rx->setText(m_paraMap[Constants::MESSAEGS_LIST_COL_RX] + " KHz");

    // 停止计时器，并将计时器的显示值初始化为"00:00:00"
    m_commuTimer->stop();
    ui->timer->setText("00:00:00");
    m_connectFlag = true;

    // 获取新的UUID
    QUuid idCommuMessage = QUuid::createUuid();
    m_strMessageListUUID = idCommuMessage.toString();
    
    // 根据源页面的主叫被叫模式来设置主叫被叫按钮。
    // 如果是主叫模式，就高亮显示主叫按钮，反之则高亮显示被叫按钮。
    if (m_paraMap[ CALL_OR_RECEIVE ] == Constants::CALL_SET_CALLRECEIVE_CALL)
    {
        ui->callBtn->setIcon(m_whiteQIconTransmit);
        ui->receiveBtn->setIcon(m_grayQIconReceive);
        ui->inputEdit->setFocus();
    }
    else
    {
        ui->callBtn->setIcon(m_grayQIconTransmit);
        ui->receiveBtn->setIcon(m_whiteQIconReceive);
        ui->tableView->selectRow(0);
        ui->tableView->setFocus();
    }
    
    // 当跳转源页面是call setup页面或者扫描频率页面，则根据传入参数，显示正在谐调的对话框。
    if (thisID == CALL_VIEW_NAME || thisID == SCAN_FREQUENCY_VIEW)
    {
        int intResult;
        m_commStatusMessage.SetIoc(":/images/Call_Wait_flash", 150, true);
        m_commStatusMessage.SetButtonLayout(true, false);
        m_commStatusMessage.SetMessage(tr("Radio is trying to tune"), tr("Radio is tuning..."), tr(""));
        m_state = TUNING;
        m_waitSignalTimer->start(ConfigUtils::getTuneResultWaitTime());
        QString labelStyle = "font: 20pt; background: transparent; font-weight:bold;color: gray;";
        ui->callmode->setStyleSheet(labelStyle);
        ui->calltype->setStyleSheet(labelStyle);
        QString namelabelStyle = "font: 13pt; background: transparent; color: gray;";
        ui->name->setStyleSheet(namelabelStyle);
        QString owner = m_paraMap[ Constants::CALL_SET_OWNER ];
        
        // 根据传入参数，设置页面左上角的图标
        ui->namelabel->setText(""); 
        if (owner == COMMON_OWER_INDIVIDUAL)
        {
            ui->namelabel->setStyleSheet("image: url(:/images/images/Call_Info_Name_gray.png);");
        }
        else if (owner == COMMON_OWER_STATION)
        {
            ui->namelabel->setStyleSheet("image: url(:/images/images/Call_Info_Station_gray.png);");
        }
        else
        {
            ui->namelabel->setText("Name");
            ui->namelabel->setStyleSheet(labelStyle);
        }
        
        // 显示通信状态对话框，如果按了OK按钮，则返回值是1，直接跳转到call setup页面。
        // 如果按了CANCEL按钮，则返回值是2，向协议层反送取消建链信号，并跳转到call setup页面。
        intResult = m_commStatusMessage.exec();
        qDebug()<<"intResult:"<<intResult;

        if (intResult == 2)
        {
            m_waitSignalTimer->stop();
            QMap <QString, QString> paraMap;
            Transit::get()->EmitSignalConnectingCancel();
            g_mainWorkFlow->callRadio_changetoReady();

            emit afterPageSignal(CALL_COMMUNICATION_VIEW, CALL_VIEW_NAME, paraMap);
        }
        
        if (intResult == 1)
        {
            m_waitSignalTimer->stop();
            QMap <QString, QString> paraMap;
            emit afterPageSignal(CALL_COMMUNICATION_VIEW, CALL_VIEW_NAME, paraMap);
        }
    }
}
/****************************************************************************
**
** 函数名称：CallCommunication::homeClickedSlot
** 功能概述: home按钮响应，跳转到主菜单。
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunication:: homeClickedSlot()
{
    Logging::get()->info("CallCommunication:: homeClickedSlot ");
    communicationExit();
}
/****************************************************************************
**
** 函数名称：CallCommunication::homeClickedSlot
** 功能概述: 保存通讯消息记录到数据库。
** 参数说明：showQuitDialog:弹窗标记 isUnread：已读标记
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunication::communicationExit(bool showQuitDialog, bool isUnread)
{
    Logging::get()->info("CallCommunication::communicationExit ");
    

    if (showQuitDialog)
    {
        // 显示退出确认对话框
        IocMessage infomsg;
        infomsg.SetButtonLayout(true, true);
        infomsg.move((SCREEN_SIZE_WIDTH - infomsg.width()) / 2, (SCREEN_SIZE_HEIGHT - infomsg.height()) / 2);
        infomsg.SetIoc(":/images/images/Call_exclamatory_mark.png", 150, false);
        infomsg.SetMessage(tr("Quit"), tr("Make Sure to quit this session?"), tr(""));
        QFont font("Ubuntu", 18, QFont::Bold);
        infomsg.SetFont(font);
        int intResult = infomsg.exec();
        
        if (intResult == 2)
        {            
            return;           //如果是取消键 ，则什么都不做
        }
    }
    
    //串口通知，关闭通信，断开电台
    Transit::get()->EmitSignalInterupt(); // sure,断开电台 202 0xCA
    // 将数据更新至数据库
    QDateTime dateTime = QDateTime::currentDateTime();
    int y = dateTime.date().year();
    int m = dateTime.date().month();
    QString mStr = "0";
    
    if (m < 10)
        mStr += QString::number(m);
    else
        mStr = QString::number(m);
        
    int d = dateTime.date().day();
    QString dStr = "0";
    
    if (d < 10)
        dStr += QString::number(d);
    else
        dStr = QString::number(d);
        
    QString strTime = dateTime.time().toString();
    QString sTime = (QString::number(y) + "-" + mStr + "-" + dStr + "  " + strTime);
    QString strInOutPutFlag;
    
    if (m_paraMap[ CALL_OR_RECEIVE ] == Constants::CALL_SET_CALLRECEIVE_CALL)
    {
        strInOutPutFlag = Constants:: MESSAEGS_LIST_INOUT_O;
    }
    else
    {
        strInOutPutFlag = Constants:: MESSAEGS_LIST_INOUT_I;
    }
    
    QString unreadFlag = isUnread ? Constants::MESSAEGS_LIST_MESSAGE_UNREAD_FLAG :
                         Constants::MESSAEGS_LIST_MESSAGE_READED_FLAG;
    Database* database = new Database();
    database->openConnection();
    bool hasTransaction = database->transaction();
    QString sqlInsertMessage = "INSERT INTO Message (";
    sqlInsertMessage = sqlInsertMessage + Constants::MESSAEGS_LIST_COL_UUID ;
    sqlInsertMessage = sqlInsertMessage + ",";
    sqlInsertMessage = sqlInsertMessage + Constants::MESSAEGS_LIST_COL_SHOWPIX ;
    sqlInsertMessage = sqlInsertMessage + ",";
    sqlInsertMessage = sqlInsertMessage + Constants::MESSAEGS_LIST_COL_INOUT ;
    sqlInsertMessage = sqlInsertMessage + ",";
    sqlInsertMessage = sqlInsertMessage + Constants::MESSAEGS_LIST_COL_CALLCODE ;
    sqlInsertMessage = sqlInsertMessage + ",";
    sqlInsertMessage = sqlInsertMessage + Constants::MESSAEGS_LIST_COL_MODE ;
    sqlInsertMessage = sqlInsertMessage + ",";
    sqlInsertMessage = sqlInsertMessage + Constants::MESSAEGS_LIST_COL_NAME ;
    sqlInsertMessage = sqlInsertMessage + ",";
    sqlInsertMessage = sqlInsertMessage + Constants::MESSAEGS_LIST_COL_TX ;
    sqlInsertMessage = sqlInsertMessage + ",";
    sqlInsertMessage = sqlInsertMessage + Constants::MESSAEGS_LIST_COL_RX ;
    sqlInsertMessage = sqlInsertMessage + ",";
    sqlInsertMessage = sqlInsertMessage + Constants::MESSAEGS_LIST_COL_TIMESTART ;
    sqlInsertMessage = sqlInsertMessage + ",";
    sqlInsertMessage = sqlInsertMessage + Constants::MESSAEGS_LIST_COL_TIMEEND ;
    sqlInsertMessage = sqlInsertMessage + ") VALUES (";
    sqlInsertMessage = sqlInsertMessage + "'";
    sqlInsertMessage = sqlInsertMessage + m_strMessageListUUID;
    sqlInsertMessage = sqlInsertMessage + "',";
    sqlInsertMessage = sqlInsertMessage + "'";
    sqlInsertMessage = sqlInsertMessage + unreadFlag;
    sqlInsertMessage = sqlInsertMessage + "',";
    sqlInsertMessage = sqlInsertMessage + "'";
    sqlInsertMessage = sqlInsertMessage + strInOutPutFlag;
    sqlInsertMessage = sqlInsertMessage + "',";
    sqlInsertMessage = sqlInsertMessage + "'";
    sqlInsertMessage = sqlInsertMessage + m_paraMap[Constants::MESSAEGS_LIST_COL_CALLCODE];
    sqlInsertMessage = sqlInsertMessage + "',";
    sqlInsertMessage = sqlInsertMessage + "'";
    sqlInsertMessage = sqlInsertMessage + m_paraMap[Constants::CALL_SET_CALL_MODE];
    sqlInsertMessage = sqlInsertMessage + "',";
    sqlInsertMessage = sqlInsertMessage + "'";
    sqlInsertMessage = sqlInsertMessage + m_paraMap[Constants::MESSAEGS_LIST_COL_NAME];
    sqlInsertMessage = sqlInsertMessage + "',";
    sqlInsertMessage = sqlInsertMessage + "'";
    sqlInsertMessage = sqlInsertMessage + m_paraMap[Constants::MESSAEGS_LIST_COL_TX];
    sqlInsertMessage = sqlInsertMessage + "',";
    sqlInsertMessage = sqlInsertMessage + "'";
    sqlInsertMessage = sqlInsertMessage + m_paraMap[Constants::MESSAEGS_LIST_COL_RX];
    sqlInsertMessage = sqlInsertMessage + "',";
    sqlInsertMessage = sqlInsertMessage + "'";
    sqlInsertMessage = sqlInsertMessage + m_startTime;
    sqlInsertMessage = sqlInsertMessage + "',";
    sqlInsertMessage = sqlInsertMessage + "'";
    sqlInsertMessage = sqlInsertMessage + sTime;
    sqlInsertMessage = sqlInsertMessage + "');";
    QVariantMap mapInsertMessage;
    bool bInsertMessage  = false;
    bInsertMessage = database->executeSql(sqlInsertMessage, mapInsertMessage);
    QString sqlInsertMessageDetail =
        "INSERT INTO MessageDetail ( UUID,FKey ,InputOutput ,Content ,CommunicationDateTime)  ";
    sqlInsertMessageDetail = sqlInsertMessageDetail +
                             "SELECT  UUID,FKey ,InputOutput ,Content ,CommunicationDateTime From CommuMessageDetail  ";
    sqlInsertMessageDetail = sqlInsertMessageDetail + " where SendStatus <> 'FALSE' ";
    QVariantMap mapInsertMessageDetail;
    bool bInsertMessageDetail  = false;
    bInsertMessageDetail = database->executeSql(sqlInsertMessageDetail, mapInsertMessageDetail);
    QString sqlDeleteCommuMessageDetail =  "delete from CommuMessageDetail ";
    QVariantMap mapDeleteCommuMessageDetail;
    bool bDeleteCommuMessageDetail  = false;
    bDeleteCommuMessageDetail = database->executeSql(sqlDeleteCommuMessageDetail, mapDeleteCommuMessageDetail);
    
    if (hasTransaction && bInsertMessage  && bInsertMessageDetail && bDeleteCommuMessageDetail)
    {
        database->commit();
    }
    else
    {
        database->rollback();
    }
    
    // 跳转到home页面
    QMap <QString, QString>paraMap;
    emit afterPageSignal(CALL_COMMUNICATION_VIEW, HOME_VIEW_NAME, paraMap);


}
/****************************************************************************
**
** 函数名称：CallCommunication::eventFilter
** 功能概述: 事件监听函数，响应用户键盘操作。
** 参数说明：watched：发送方， event：事件数据
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool CallCommunication::eventFilter(QObject* watched, QEvent* event)
{
    Logging::get()->info("CallCommunication::eventFilter");

    // 设置焦点切换顺序列表
    QStringList nameList;
    nameList << "tableView" << "inputEdit" << "wruBnt" << "HRBnt" << "overBnt" << "breakBnt" << "sendBnt" << "optionBnt" <<
             "homeTBnt";
    QKeyEvent* key_event = static_cast<QKeyEvent*>(event);
    int a =   key_event->key();
    
    // 根据键值，切换页面各控件焦点
    switch (a)
    {
    case Qt::Key_T:
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
        
        // 默认键值51 响应一次
        QKeyEvent* key_event = static_cast<QKeyEvent*>(event);
        
        // optionBnt 按钮获得光标
        if (key_event->modifiers() & Qt::AltModifier)
        {
            QWidget* widget = findChild<QWidget*>("optionBnt");
            widget->setFocus();
        }
        
        return true;
    }
    
    case Qt::Key_Right:
    case Qt::Key_Down:
    case Qt::Key_Tab:
    {
        if (QEvent::KeyPress == event->type()) // 按下时键屏蔽
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type()) // 弹起时键屏蔽
        {
            return true;
        }
        
        // MacroBnt phrasebookBnt loadBnt printBnt loadBnt 按钮获得光标
        if (!m_optionMenuStatus && (a == Qt::Key_Down || a == Qt::Key_Tab))
        {
            if (!m_insertMenuStatus)
            {
                if (ui->MacroBnt->hasFocus())
                    ui->phrasebookBnt->setFocus();
                else if (ui->phrasebookBnt->hasFocus())
                    ui->MacroBnt->setFocus();
                else
                    ui->MacroBnt->setFocus();
            }
            else if (ui->loadBnt->hasFocus())
                ui->insertBnt->setFocus();
            else if (ui->insertBnt->hasFocus())
                ui->printBnt->setFocus();
            else if (ui->printBnt->hasFocus())
                ui->loadBnt->setFocus();
            else
                ui->loadBnt->setFocus();
                
            return true;
        }
        // optionBnt 按钮获得光标
        else if (!m_optionMenuStatus && (a == Qt::Key_Right))
        {
            QWidget* widget = findChild<QWidget*>("optionBnt");
            Button* button = static_cast<Button*>(widget);
            
            if (!m_insertMenuStatus)
                ui->insertBnt->click();
            else if (!m_optionMenuStatus)
            {
                button->click();
                widget->setFocus();
            }
            
            return true;
        }
        
        int next = 0;
        bool inTableView = false;
        
        // 按钮图片切换 focus 离开 按钮图片变暗
        for (int i = 0; i < nameList.length(); i++)
        {
            QWidget* widget = findChild<QWidget*>(nameList.at(i));
            
            if (widget && widget->hasFocus())
            {
                if (nameList.at(i) == "tableView")
                {
                    if (a == Qt::Key_Down)
                    {
                        inTableView = true;
                        break;
                    }
                }
                
                if (nameList.at(i) == "homeTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/home_normal"));
                }
                
                next = (i == nameList.length() - 1) ? 0 : i + 1;
                break;
            }
        }
        
        if (inTableView)
            break;
            
        QWidget* widgetnext = findChild<QWidget*>(nameList.at(next));
        
        // 按钮图片切换 focus 获得 按钮图片亮
        if (widgetnext)
        {
            widgetnext->setFocus();
            
            if (nameList.at(next) == "homeTBnt")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetnext);
                button->setIcon(QIcon(":/images/home_hover"));
            }

            if (nameList.at(next) == "tableView")
            {
                //ui->tableView->scrollToBottom();
                ui->tableView->selectRow(m_model->rowCount()-1);
            }

        }
        
        break;
    }
    
    case Qt::Key_Up:
    case Qt::Key_Backtab:
    case Qt::Key_Left:
    {
        if (QEvent::KeyPress == event->type()) // 按下时键屏蔽
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type()) // 弹起时键屏蔽
        {
            return true;
        }
        
        // MacroBnt phrasebookBnt loadBnt printBnt loadBnt 按钮获得光标
        if (!m_optionMenuStatus && (a == Qt::Key_Up))
        {
            if (!m_insertMenuStatus)
            {
                if (ui->MacroBnt->hasFocus())
                    ui->phrasebookBnt->setFocus();
                else if (ui->phrasebookBnt->hasFocus())
                    ui->MacroBnt->setFocus();
                else
                    ui->MacroBnt->setFocus();
            }
            else if (ui->loadBnt->hasFocus())
                ui->printBnt->setFocus();
            else if (ui->printBnt->hasFocus())
                ui->insertBnt->setFocus();
            else if (ui->insertBnt->hasFocus())
                ui->loadBnt->setFocus();
            else
                ui->loadBnt->setFocus();
                
            return true;
        }
        // optionBnt 按钮获得光标
        else if (!m_optionMenuStatus && (a == Qt::Key_Left))
        {
            if (ui->insertBnt->hasFocus())
            {
                ui->insertBnt->click();
            }
            
            return true;
        }
        
        int prev = 0;
        bool inTableView = false;
        
        // 按钮图片切换 focus 离开 按钮图片变暗
        for (int i = 0; i < nameList.length(); i++)
        {
            QWidget* widget = findChild<QWidget*>(nameList.at(i));
            
            if (widget && widget->hasFocus())
            {
                if (nameList.at(i) == "tableView" && a == Qt::Key_Up)
                {
                    inTableView = true;
                    break;
                }
                
                if (nameList.at(i) == "homeTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/home_normal"));
                }
                
                prev = (i == 0) ? nameList.length() - 1 : i - 1;
                break;
            }
        }
        
        if (inTableView)
            break;
            
        QWidget* widgetprev = findChild<QWidget*>(nameList.at(prev));
        widgetprev->setFocus();
        
        // 按钮图片切换 focus 获得 按钮图片亮
        if (widgetprev)
        {
            widgetprev->setFocus();
            if (nameList.at(prev) == "tableView")
            {
                //ui->tableView->scrollToBottom();
                ui->tableView->selectRow(m_model->rowCount()-1);
            }

            if (nameList.at(prev) == "homeTBnt")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetprev);
                button->setIcon(QIcon(":/images/home_hover"));
            }
            
            if (nameList.at(prev) == "inBoxTBnt")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetprev);
                button->setIcon(QIcon(":/images//images/message_inBox_SelYes.png"));
            }
            
            if (nameList.at(prev) == "outBoxTBnt")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetprev);
                button->setIcon(QIcon(":/images//images/message_outBox_SelYes.png"));
            }
        }
        
        break;
    }
    
    case Qt::Key_Return:
    case Qt::Key_Enter:
    {
        // 当键按下，并且焦点在文本输入框时，模拟sendBnt按钮点击，向协议层发送消息
        if (QEvent::KeyPress == event->type())
        {
            if (ui->inputEdit->hasFocus())
            {
                ui->sendBnt->click();
            }
            
            return true;
        }
        // 屏蔽键弹起
        else if (QEvent::KeyRelease == event->type())
        {
            return true;
        }
        
        // 默认键值51 响应一次
        // 按钮响应Enter 事件
        for (int i = 0; i < nameList.length(); i++)
        {
            QWidget* widget = findChild<QWidget*>(nameList.at(i));
            
            if (widget && widget->hasFocus())
            {
                if (nameList.at(i) == "homeTBnt")
                {
                    QWidget* widget = findChild<QWidget*>("homeTBnt");
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                }
                else if (nameList.at(i) == "inBoxTBnt")
                {
                    QWidget* widget = findChild<QWidget*>("inBoxTBnt");
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                }
                else if (nameList.at(i) == "outBoxTBnt")
                {
                    QWidget* widget = findChild<QWidget*>("outBoxTBnt");
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                }
                else if (nameList.at(i) == "copyBnt")
                {
                    QWidget* widget = findChild<QWidget*>("outBoxTBnt");
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                }
                else if (nameList.at(i) == "printBnt")
                {
                    QWidget* widget = findChild<QWidget*>("outBoxTBnt");
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                }
                else if (nameList.at(i) == "closeBnt")
                {
                    QWidget* widget = findChild<QWidget*>("outBoxTBnt");
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                }
                
                break;
            }
        }
        
        break;
    }
    
    case Qt::Key_Escape: // 响应 ESC事件
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
        // optionBnt 按钮获得光标
        if (!m_optionMenuStatus)
        {
            if (!m_insertMenuStatus)
                ui->insertBnt->click();
                
            ui->optionBnt->setFocus();
            ui->optionBnt->click();
        }
        else
        {
            ui->inputEdit->setText(Constants::COMMUMESSAEGS_MACRO_BREAK_SHOW);
            sendMessage();//communicationExit();
        }
            
        break;
    }
    }
    
    if (a == Qt::Key_Escape)
        return true;
        
    return QWidget::eventFilter(watched, event);
}
/****************************************************************************
**
** 函数名称：CallCommunication::widgetDataBackSlot
** 功能概述: 返回通过窗口选择的数据写入编辑框
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunication::widgetDataBackSlot()
{
    Logging::get()->info("CallCommunication::widgetDataBackSlot ");
    QString str = m_widget->dataBack();
    
    if (str != "")
    {
        qDebug() << str;
        QString text = ui->inputEdit->text();
        text += str;
//        ui->inputEdit->setText(text);                yzz
    }
}
/****************************************************************************
**
** 函数名称：CallCommunication::printClickedSlot
** 功能概述: 打印消息数据
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunication:: printClickedSlot()
{
    Logging::get()->info("CallCommunication:: printClickedSlot ");
    QString print;
    print += "\n";
    print += "/************/\n";
    print += "CallMessage\n";
    print += "/************/\n";
    QDateTime dateTime = QDateTime::currentDateTime();
    int y = dateTime.date().year();
    int m = dateTime.date().month();
    QString mStr = "0";
    
    if (m < 10)
        mStr += QString::number(m);
    else
        mStr = QString::number(m);
        
    int d = dateTime.date().day();
    QString dStr = "0";
    
    if (d < 10)
        dStr += QString::number(d);
    else
        dStr = QString::number(d);
        
    QString strTime = dateTime.time().toString();
    QString sTime = (QString::number(y) + "-" + mStr + "-" + dStr + "  " + strTime);
    QString strInOutPutFlag;
    
    if (m_paraMap[ CALL_OR_RECEIVE ] == Constants::CALL_SET_CALLRECEIVE_CALL)
    {
        strInOutPutFlag = Constants:: MESSAEGS_LIST_INOUT_O;
    }
    else
    {
        strInOutPutFlag = Constants:: MESSAEGS_LIST_INOUT_I;
    }
    
    print += Constants::MESSAEGS_LIST_COL_INOUT;
    print += ":";
    print += strInOutPutFlag;
    print += "\n";
    print += Constants::MESSAEGS_LIST_COL_CALLCODE;
    print += ":";
    print += m_paraMap[Constants::MESSAEGS_LIST_COL_CALLCODE];
    print += "\n";
    print += Constants::MESSAEGS_LIST_COL_MODE;
    print += ":";
    print += m_paraMap[Constants::MESSAEGS_LIST_COL_MODE];
    print += "\n";
    print += Constants::MESSAEGS_LIST_COL_NAME;
    print += ":";
    print += m_paraMap[Constants::MESSAEGS_LIST_COL_NAME];
    print += "\n";
    print += Constants::MESSAEGS_LIST_COL_TIMESTART;
    print += ":";
    print += m_model->record(0).value(Constants::MESSAEGSDETAIL_INDEX_CDATETIME).toString();
    print += "\n";
    print += Constants::MESSAEGS_LIST_COL_TIMEEND;
    print += ":";
    print += sTime;
    print += "\n";
    print += "/************/\n";
    print += "Detail\n";
    print += "/************/\n";
    
    for (int i = 0; i < m_model->rowCount(); i++)
    {
        if (m_model->record(i).value(Constants::MESSAEGSDETAIL_INDEX_INOUT) == Constants::MESSAEGS_LIST_INOUT_O)
        {
            print += "OutPut:";
            print += m_model->record(i).value(Constants::MESSAEGSDETAIL_INDEX_CONTENT).toString();
            print += "\n";
            print += "O_Datetime:";
            print += m_model->record(i).value(Constants::MESSAEGSDETAIL_INDEX_CDATETIME).toString();
            print += "\n";
        }
        else
        {
            print += "InPut:";
            print += m_model->record(i).value(Constants::MESSAEGSDETAIL_INDEX_CONTENT).toString();
            print += "\n";
            print += "I_Datetime:";
            print += m_model->record(i).value(Constants::MESSAEGSDETAIL_INDEX_CDATETIME).toString();
            print += "\n";
        }
    }
    
    print += "\n";
    print += "\n";
    print += "\n";
    print += "\n";
    print += "\n";
    print += "\n";
    print += "\n";
    print += "\n";
    print += "\n";
    print += "\n";
    SQLiteHelper::printStr(print);
}
/****************************************************************************
**
** 函数名称：CallCommunication::printClickedSlot
** 功能概述: 打开MACRO数据选择窗口
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunication::macroMenu()
{
    Logging::get()->info(" CallCommunication::macroMenu");
    QString table(Constants::MACRO_LIST_TABLE_NAME);
    m_widget->init(table);
    
    if (!m_insertMenuStatus)
        ui->insertBnt->click();
        
    ui->optionBnt->click();
    ui->inputEdit->setFocus();
    m_widget->show();
}
/****************************************************************************
**
** 函数名称：CallCommunication::phrasebookMessage
** 功能概述: 打开phrasebook数据选择窗口
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunication::phrasebookMessage()
{
    Logging::get()->info("CallCommunication::phrasebookMessage ");
    QString table(Constants::PHRASEBOOK_LIST_TABLE_NAME);
    m_widget->init(table);
    
    if (!m_insertMenuStatus)
        ui->insertBnt->click();
        
    ui->optionBnt->click();
    ui->inputEdit->setFocus();
    m_widget->show();
}
/****************************************************************************
**
** 函数名称：CallCommunication::loadMessage
** 功能概述: 打开File数据选择窗口
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunication::loadMessage()
{
    Logging::get()->info("  CallCommunication::loadMessage");
    QString table(Constants::FILe_LIST_TABLE_NAME);
    m_widget->init(table);
    
    if (!m_insertMenuStatus)
        ui->insertBnt->click();
        
    ui->optionBnt->click();
    ui->inputEdit->setFocus();
    m_widget->show();
}
/****************************************************************************
**
** 函数名称：CallCommunication::loadMessage
** 功能概述: 发送编辑框内的文字消息
** 参数说明：strReceiveMessage：接收到的消息
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunication::sendMessage(QString  strReceiveMessage)
{
    Logging::get()->info(" CallCommunication::sendMessage");
    qDebug()<<"CallCommunication::sendMessage";

    QUuid idCommuMessage = QUuid::createUuid();
    QString strCommuMessageUUID = idCommuMessage.toString();
    QDateTime dateTime = QDateTime::currentDateTime();
    int y = dateTime.date().year();
    int m = dateTime.date().month();


    QString mStr = "0";
    
    if (m < 10)
        mStr += QString::number(m);
    else
        mStr = QString::number(m);
        
    int d = dateTime.date().day();
    QString dStr = "0";
    
    if (d < 10)
        dStr += QString::number(d);
    else
        dStr = QString::number(d);
        
    QString strTime = dateTime.time().toString();
    QString sTime = (QString::number(y) + "-" + mStr + "-" + dStr + "  " + strTime);
    QString strShowText;
    QString strInOutFlag;
    QString print;
    
    if (m_realTimePrinting == SYSTEM_SETTING_PRINTMODE_REAL)
    {
        print += "\n";
        print += "/************/\n";
        print += "/************/\n";
    }
    
    if ( strReceiveMessage.isEmpty() == true ) //发送状态
    {
        qDebug()<<"send is"<<ui->inputEdit->text()<<"size is"<<ui->inputEdit->text().size()<<ui->inputEdit->text().toAscii();

        Transit::get()->EmitSignalLineEditState(false);  //发送开始，关闭光标
        Transit::get()->EmitSignalTalkSend(idCommuMessage, ui->inputEdit->text());

        if( ( ui->inputEdit->isReadOnly() == true &&    // 接受位置时候，不显示+? 和 [break]
                ui->inputEdit->text().compare(Constants::COMMUMESSAEGS_MACRO_OVER_SEND) == 0 )
                 || ui->inputEdit->text().compare(Constants::COMMUMESSAEGS_MACRO_BREAK_SHOW) == 0 )
          {   ui->inputEdit->clear(); return;}

        if( ui->inputEdit->text().size() > 0)
            strReceiveMessage =ui->inputEdit->text() ; // setTexTWrap(ui->inputEdit->text());
        else
            strReceiveMessage="\n";

        strInOutFlag = Constants::MESSAEGS_LIST_INOUT_O;                    // Constants::MESSAEGS_LIST_INOUT_O
        
        if (m_realTimePrinting == SYSTEM_SETTING_PRINTMODE_REAL)
        {
            print += "OutPut:";
            print += strShowText;
            print += "\n";
            print += "O_Datetime:";
            print += sTime;
            print += "\n";
        }

    }
    else
    {
        qDebug()<<"strReceiveMessage.isEmpty() no";
        strReceiveMessage = setTexTWrap(strReceiveMessage);
        strInOutFlag = Constants::MESSAEGS_LIST_INOUT_I;
        
        if (m_realTimePrinting == SYSTEM_SETTING_PRINTMODE_REAL)
        {
            print += "InPut:";
            print += strShowText;
            print += "\n";
            print += "I_Datetime:";
            print += sTime;
            print += "\n";
        }

    }
    
    if (m_realTimePrinting == SYSTEM_SETTING_PRINTMODE_REAL)
    {
        SQLiteHelper::printStr(print);
    }

    qDebug()<<strReceiveMessage;
    if( (g_mainWorkFlow->init_Receive_Send == 2 && strInOutFlag.compare("O") ==0 ) ||
            ( g_mainWorkFlow->init_Receive_Send == 1 && strInOutFlag.compare("I") ==0) )  //当前和前一次是一样
    {

        int rowNum=m_model->rowCount();
        if( ( rowNum > 0) && ( strReceiveMessage.compare("\n")!= 0 ))
        {
            QString beforeStr = m_model->record(rowNum-1).value(Constants::MESSAEGS_SHOW_COL_CONTENT).toString();
            strReceiveMessage.prepend( reMoveHuanHang(beforeStr) );
            m_model->removeRows(rowNum-1,1);  m_model->submitAll(); qDebug()<<"0";
            strShowText =  setTexTWrap(strReceiveMessage);  //strReceiveMessage;
        }
        else if( ( rowNum > 0) && ( strReceiveMessage.compare("\n") == 0 ) )
        {
//            QString beforeStr = m_model->record(rowNum-1).value(Constants::MESSAEGS_SHOW_COL_CONTENT).toString();
//            strReceiveMessage.prepend( beforeStr )  ;
//            m_model->removeRows(rowNum-1,1);  m_model->submitAll();
            strReceiveMessage.clear();
            strShowText = strReceiveMessage; qDebug()<<"1";}

        else if(( rowNum == 0) && (  strReceiveMessage.compare("\n")  == 0  ))
        { /*strShowText = setTexTWrap("\n");*/
            strReceiveMessage.clear();
            strShowText = strReceiveMessage;   qDebug()<<"2";}

        else if(( rowNum == 0) && (  strReceiveMessage.compare("\n") != 0  ))
         { strShowText = strReceiveMessage;qDebug()<<"3"; }

    }else                                                                                    //直接插入新的一行
       strShowText = setTexTWrap(strReceiveMessage);

    int row = 0;
    m_model->insertRows(row, 1);

    m_model->setData(m_model->index(row, Constants::MESSAEGSDETAIL_INDEX_UUID), strCommuMessageUUID);
    m_model->setData(m_model->index(row, Constants::MESSAEGSDETAIL_INDEX_FKEY), m_strMessageListUUID);
    m_model->setData(m_model->index(row, Constants::MESSAEGSDETAIL_INDEX_INOUT), strInOutFlag);
    m_model->setData(m_model->index(row, Constants::MESSAEGSDETAIL_INDEX_CONTENT), strShowText);
    m_model->setData(m_model->index(row, Constants::MESSAEGSDETAIL_INDEX_CDATETIME), sTime);
    m_model->setData(m_model->index(row, Constants::COMMUMESSAGEDETAILl_INDEX_SENDSTATUS),
                     Constants::COMMUMESSAEGS_SENDSTATUS_SEND);
    m_model->submitAll();
    ui->inputEdit->clear();
    m_model->select();
    setTableViewRowHeight();

    if( strInOutFlag.compare("I") == 0 )
        g_mainWorkFlow->init_Receive_Send = 1;
    else
        g_mainWorkFlow->init_Receive_Send = 2;

}
/****************************************************************************
**
** 函数名称：CallCommunication::
** 功能概述: 插入一行
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  YZZ
**
****************************************************************************/
QString CallCommunication::reMoveHuanHang(QString str )
{
    if (str.length() > Constants::COMMUMESSAEGS_SHOW_LENGH)
    {
        for (int pos = 0; pos < str.length()  ;)
        {
          QString tempStr = str.mid(pos,Constants::COMMUMESSAEGS_SHOW_LENGH);
          if( tempStr.indexOf("\n") == -1 )          //如果没有手动换行符
          {
          pos  = pos + Constants::COMMUMESSAEGS_SHOW_LENGH;
          if(str.mid(pos,1).compare("\n") == 0 )
              str.remove(pos,1);
          }
          else                                      //如果有手动换行符，在手动换行符的 下一个长度区域内删除“\n"
          {
              pos = pos + tempStr.indexOf("\n")+1;
          }
        }
    }
    return str;
}
/****************************************************************************
**
** 函数名称：CallCommunication::setTableViewRowHeight
** 功能概述: 获取全部临时消息显示在通讯界面内
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunication::setTableViewRowHeight()
{
    Logging::get()->info("CallCommunication::setTableViewRowHeight");
    int rowCount = m_model->rowCount() ;
    
    for (int rowIndex = 0; rowIndex < rowCount; rowIndex++)
    {
        QSqlRecord  sqlRecord = m_model->record(rowIndex);
        QString strContens = sqlRecord.value(Constants::MESSAEGS_SHOW_COL_CONTENT).toString();
        int rowHeight = 1;
        QString showText = "" ;
        QString showTextTmp = strContens;
        
        for (int pos = 0; pos < showTextTmp.length()  ;)
        {
            if (showTextTmp.at(pos) == '\n'  || showTextTmp.at(pos) == '\r')
            {
                rowHeight = rowHeight + 1;
            }
            
            pos  = pos + 1;
        }
        
         ui->tableView->setRowHeight(rowIndex, rowHeight * Constants::COMMUMESSAEGS_SHOW_ROW_HIGHT);
    }
    
     ui->tableView->scrollToBottom();

}
/****************************************************************************
**
** 函数名称：CallCommunication::setTexTWrap
** 功能概述: 将临时消息显示在通讯界面内（从发送中或接收中获取）
** 参数说明：消息数据
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QString CallCommunication::setTexTWrap(QString strInputText)
{
    Logging::get()->info("CallCommunication::setTexTWrap");
    QString showText = "" ;
    QString showTextTmp = strInputText;

    
    if (showTextTmp.length() > Constants::COMMUMESSAEGS_SHOW_LENGH)
    {
        for (int pos = 0; pos < showTextTmp.length()  ;)
        {
            if ((pos + Constants::COMMUMESSAEGS_SHOW_LENGH)  >=  showTextTmp.length())    //不够一整行，把剩余信息截取
            {
                showText = showText + showTextTmp.mid(pos, showTextTmp.length()  - pos);
            }
            else                                                                          //够一整行，截取一行
            {
//                showText = showText + showTextTmp.mid(pos, Constants::COMMUMESSAEGS_SHOW_LENGH);
//                showText = showText + "\n";
                QString childShow =  showTextTmp.mid(pos, Constants::COMMUMESSAEGS_SHOW_LENGH);
                int tempIndex = childShow.indexOf("\n");
                if(tempIndex == -1)  //没有手动换行符
                    showText = showText + childShow+"\n";
                else
                   {
                    showText = showText + showTextTmp.mid(pos, tempIndex+1);
                    pos = pos + tempIndex+1;
                    continue;
                   }
            }
            
            pos  = pos + Constants::COMMUMESSAEGS_SHOW_LENGH;
        }
    }
    else
    {
        showText = showTextTmp;
    }
//    int pos_length = 0;
//    for (int pos = 0; pos < showTextTmp.length()  ;)
//    {
//        //如果当前长度=SHOW_LENGTH，请加换行，然后复制
//        if(pos_length == Constants::COMMUMESSAEGS_SHOW_LENGH)
//             showText = showText + "\n"+showTextTmp.mid(pos,1);
//        //如果当前是换行符，请复制，然后长度清零
//        if( showTextTmp.mid(pos,1).compare("\n")==0 )
//            showText = showText + showTextTmp.mid(pos,1); pos_length = 0;
//        //如果当前bu是换行符，请复制，然后长度+1
//    }
    
    return showText;
}

/****************************************************************************
**
** 函数名称：CallCommunication::sendWRU
** 功能概述: 发送指定文字
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunication::sendWRU()
{
    Logging::get()->info("CallCommunication::sendWRU");
    ui->inputEdit->setText(Constants::COMMUMESSAEGS_MACRO_WRU);
    sendMessage();
}
/****************************************************************************
**
** 函数名称：CallCommunication::sendHR
** 功能概述: 发送指定文字
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunication::sendHR()
{
    Logging::get()->info("CallCommunication::sendHR");
    QString answerBackCode;
    Database* database = new Database();
    database->openConnection();
    QSqlQuery querySetting = database->getQuery();
    QString sqlSetting = "select answerbackcode from setting ";
    querySetting.prepare(sqlSetting);
    querySetting.exec();
    QSqlQueryModel* settingModel = new QSqlQueryModel(this);
    settingModel->setQuery(querySetting);
    
    if (settingModel->rowCount() > 0)
    {
        QSqlRecord record = settingModel->record(0);
        answerBackCode = record.value(SYSTEM_SETTING_ANSWERBACKCODE).toString();
        ui->inputEdit->setText(answerBackCode);
        sendMessage();
    }
}
/****************************************************************************
**
** 函数名称：CallCommunication::sendOver
** 功能概述: 发送指定文字
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunication::sendOver()
{
    Logging::get()->info("CallCommunication::sendOver");
    ui->inputEdit->setText(Constants::COMMUMESSAEGS_MACRO_OVER_SEND);
    sendMessage();
}
/****************************************************************************
**
** 函数名称：CallCommunication::sendBreak
** 功能概述: 发送指定文字
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunication::sendBreak()
{
    Logging::get()->info("CallCommunication::sendBreak");
    ui->inputEdit->setText(Constants::COMMUMESSAEGS_MACRO_BREAK_SHOW);
    sendMessage();
    // communicationExit(); 有返回结果时候，再停止结束

}
/****************************************************************************
**
** 函数名称：CallCommunication::SlotRealTimePrinting
** 功能概述: 当在系统设置打印机模式时修改打印机模式变量
** 参数说明：打印模式
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunication::SlotRealTimePrinting(QString printMode)
{
    Logging::get()->info("CallCommunication::SlotRealTimePrinting");
    m_realTimePrinting = printMode;
}

/****************************************************************************
**
** 函数名称：CallCommunication::SlotCallWait
** 功能概述: 呼叫等待
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunication::SlotCallWait(bool bWaitFlag)//呼叫等待
{
    Logging::get()->info("CallCommunication::SlotCallWait");
}
/****************************************************************************
**
** 函数名称：CallCommunication::SlotTimerUpdate
** 功能概述: 更新计时器
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunication::SlotTimerUpdate()
{
    m_secs ++;
    int hour = m_secs / 3600;
    int minute = m_secs / 60 % 60;
    int second = m_secs % 60;
    QString text = QString("%1:%2:%3").arg(hour, 2, 10, QLatin1Char('0')).arg(minute, 2, 10, QLatin1Char('0')).arg(second,
                   2, 10, QLatin1Char('0'));
    ui->timer->setText(text);
}
/****************************************************************************
**
** 函数名称：CallCommunication::SlotSignalWaitTimeOut
** 功能概述: 信号等待超时处理
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunication::SlotSignalWaitTimeOut()
{
    QString message;
    QString title;
    
    g_mainWorkFlow->workFlowState=1;   //调谐成功后，建连超时不成功，重新置1接受调谐

    switch (m_state)
    {
    case TUNING:
        title = "Tune Error";
        message = "Tuning false!";
        break;
        
    case CONNECTING:
    case WATINGCONNECT:
        title = "Connect Error";
        message = "Connect false!";
        break;
        
    default:
        return;
    }
    
    m_commStatusMessage.SetIoc(":/images/images/Call_exclamatory_mark.png", 250, true);
    m_commStatusMessage.SetMessage(title, message, tr(""));
    m_commStatusMessage.SetButtonLayout(false, true);

}

/****************************************************************************
**
** 函数名称：CallCommunication::SlotTurningResult
** 功能概述: 调谐结果
** 参数说明：结果
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunication::SlotTurningResult(bool bResult)
{
    Logging::get()->info("CallCommunication::SlotTurningResult");
    
    // 如果返回结果是失败，则弹出调谐失败界面，按确定，则返回call setup界面。
    // 反之，如果是FEC，则关闭对话框，进入通话界面，如果是ARQ的主叫，则弹出正在建链对话框，
    // 如果是ARQ的被叫模式，则弹出等待建链
    if (!bResult)
    {
        m_commStatusMessage.SetIoc(":/images/images/Call_exclamatory_mark.png", 250, true);
        m_commStatusMessage.SetMessage(tr("Tune Error"), tr("Tuning false!"), tr(""));
        m_commStatusMessage.SetButtonLayout(false, true);
        int intResult =  m_commStatusMessage.exec();
        
        if (intResult == 1)
        {
            m_waitSignalTimer->stop();
            QMap <QString, QString> paraMap;
            emit afterPageSignal(CALL_COMMUNICATION_VIEW, CALL_VIEW_NAME, paraMap);
            return;
        }
    }
    else
    {
        if (m_paraMap[Constants::MESSAEGS_LIST_COL_MODE] != "ARQ")
        {
            //startCommunication(); yzz
            if(CallClass::get()->getIsCall())
                { startConnect(); qDebug()<<"  FEC start JIAN lIAN";    }
            else
                { startWaitConnect(); qDebug()<< "  FEC Wait JIAN lIAN";}
            return;
        }
        
        if (m_paraMap[ CALL_OR_RECEIVE ] == Constants::CALL_SET_CALLRECEIVE_RECEIVE || CallClass::get()->getIsCall()==0)
        {
            startWaitConnect(); qDebug()<< "  ARQ Called JIAN lIAN";
            return;
        }
        else
        {
            startConnect();     qDebug()<< "  ARQ Call  JIAN lIAN";
        }
    }
}

/****************************************************************************
**
** 函数名称：CallCommunication::SlotConnectingWait
** 功能概述: 等待建链
** 参数说明：建链结果
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunication::SlotConnectingWait(bool bResult)
{
    Logging::get()->info("CallCommunication::SlotConnectingWait");
    
    // 如果返回结果是失败，则弹出建链失败界面，按确定，则返回call setup界面。
    // 反之，则弹出正在建链对话框。
    if (!bResult)
    {
        m_commStatusMessage.SetIoc(":/images/images/Call_exclamatory_mark.png", 250, true);
        m_commStatusMessage.SetMessage(tr("Connect Error"), tr("Connect false!"), tr(""));
        m_commStatusMessage.SetButtonLayout(false, true);
        int intResult =  m_commStatusMessage.exec();
        
        if (intResult == 1)
        {
            m_waitSignalTimer->stop();
            QMap <QString, QString>paraMap;
            emit afterPageSignal(CALL_COMMUNICATION_VIEW, CALL_VIEW_NAME, paraMap);
        }
    }
    else
    {
        startConnect();
    }
}

/****************************************************************************
**
** 函数名称：CallCommunication::SlotConnectingResult
** 功能概述: 建链成功打印成功消息
** 参数说明：建链结果
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunication::SlotConnectingResult(bool bResult)
{
    Logging::get()->info("CallCommunication::SlotConnectingResult");
    
    // 如果返回结果是失败，则弹出建链失败界面，按确定，则返回call setup界面。
    // 反之，则关闭对话框，进入通话界面
    if (!bResult)
    {
        m_commStatusMessage.SetIoc(":/images/images/Call_exclamatory_mark.png", 250, true);
        m_commStatusMessage.SetMessage(tr("Connect Error"), tr("Connect false!"), tr(""));
        m_commStatusMessage.SetButtonLayout(false, true);
        int intResult =  m_commStatusMessage.exec();
        
        if (intResult == 1)
        {
            g_mainWorkFlow->workFlowState=1;    //建连失败，重新调谐
            QMap <QString, QString>paraMap;
            emit afterPageSignal(CALL_COMMUNICATION_VIEW, CALL_VIEW_NAME, paraMap);
        }

    }
    else
    {
        startCommunication();
    }
}

void CallCommunication::startWaitConnect()
{
    m_commStatusMessage.SetIoc(":/images/images/Call_Waiting_signs.png", 150, true);
    m_commStatusMessage.SetButtonLayout(true, false);
    m_commStatusMessage.SetMessage(tr("Radio is trying to connect"), tr("Waiting for connecting"), tr(""));
    m_state = WATINGCONNECT;

    int time = ConfigUtils::getConnectingWaitTime();
    m_waitSignalTimer->start(time);

//    int backResult=m_commStatusMessage.exec();         //手动取消

//    if(backResult==2)
//       {
//        g_mainWorkFlow->workFlowState=1;
//        m_waitSignalTimer->stop();
//       }

}

void CallCommunication::startConnect()
{
    m_commStatusMessage.SetIoc(":/images/Call_Wait_flash", 150, true);
    m_commStatusMessage.SetButtonLayout(true, false);
    m_commStatusMessage.SetMessage(tr("Radio is trying to connect"), tr("Radio is connecting"), tr(""));
    m_state = CONNECTING;

    int time = ConfigUtils::getConnectResultWaitTime();
    m_waitSignalTimer->start(time);

//    int backResult=m_commStatusMessage.exec();         //手动取消
//     qDebug()<<"backResult is:"<<backResult;
//    if(backResult==-1)
//       {
//        g_mainWorkFlow->workFlowState=1;
//        m_waitSignalTimer->stop();
//        g_mainWorkFlow->calledRadio_changetoReady();
//       }

}

void CallCommunication::startCommunication()
{
    QString print;
    print += "\n";
    print += "/************/\n";
    print += "CallMessage\n";
    print += "/************/\n";
    QString strInOutPutFlag;
    
    if (m_paraMap[ CALL_OR_RECEIVE ] == Constants::CALL_SET_CALLRECEIVE_CALL)
    {
        strInOutPutFlag = Constants:: MESSAEGS_LIST_INOUT_O;
    }
    else
    {
        strInOutPutFlag = Constants:: MESSAEGS_LIST_INOUT_I;
    }
    
    print += Constants::MESSAEGS_LIST_COL_INOUT;
    print += ":";
    print += strInOutPutFlag;
    print += "\n";
    print += Constants::MESSAEGS_LIST_COL_CALLCODE;
    print += ":";
    print += m_paraMap[Constants::MESSAEGS_LIST_COL_CALLCODE];
    print += "\n";
    print += Constants::MESSAEGS_LIST_COL_MODE;
    print += ":";
    print += m_paraMap[Constants::MESSAEGS_LIST_COL_MODE];
    print += "\n";
    print += Constants::MESSAEGS_LIST_COL_NAME;
    print += ":";
    print += m_paraMap[Constants::MESSAEGS_LIST_COL_NAME];
    print += "\n";
    print += Constants::MESSAEGS_LIST_COL_TIMESTART;
    print += ":";
    print += m_model->record(0).value(Constants::MESSAEGSDETAIL_INDEX_CDATETIME).toString();
    print += "\n";
    SQLiteHelper::printStr(print);
    QDateTime dateTime = QDateTime::currentDateTime();
    int y = dateTime.date().year();
    int m = dateTime.date().month();
    QString mStr = "0";
    
    if (m < 10)
        mStr += QString::number(m);
    else
        mStr = QString::number(m);
        
    int d = dateTime.date().day();
    QString dStr = "0";
    
    if (d < 10)
        dStr += QString::number(d);
    else
        dStr = QString::number(d);
        
    QString strTime = dateTime.time().toString();
    m_startTime = (QString::number(y) + "-" + mStr + "-" + dStr + " " + strTime);
    m_state = CONNECTED;
    m_waitSignalTimer->stop();
    m_commStatusMessage.close();
    QString labelStyle = "font: 20pt; background: transparent; font-weight:bold;color: rgb(8, 249,14);";
    ui->callmode->setStyleSheet(labelStyle);
    ui->calltype->setStyleSheet(labelStyle);

    QString namelabelStyle = "font: 13pt; background: transparent; font-weight:bold;color: rgb(8, 249,14);";
    ui->name->setStyleSheet(namelabelStyle);
    QString owner = m_paraMap[ Constants::CALL_SET_OWNER ];
    ui->namelabel->setText("");
    
    if (owner == COMMON_OWER_INDIVIDUAL)
    {
        ui->namelabel->setStyleSheet("image: url(:/images/images/Call_Info_Name.png);");
    }
    else if (owner == COMMON_OWER_STATION)
    {
        ui->namelabel->setStyleSheet("image: url(:/images/Call_Info_Station);");
    }
    else
    {
        ui->namelabel->setText("Name");
        ui->namelabel->setStyleSheet(labelStyle);
    }
    
    m_commuTimer->start(1000);
    m_secs = 0;
}

/****************************************************************************
**
** 函数名称：CallCommunication::SlotTalkSendConfirm
** 功能概述: 通话下发回执
** 参数说明：strMessageID：消息ID bSendResult:通话下发回执
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunication::SlotTalkSendConfirm(QString strMessageID, bool bSendResult)//通话下发回执
{
    Logging::get()->info("CallCommunication::SlotTalkSendConfirm");
    
    for (int i = 0; i < m_model->rowCount(); i++)
    {
        QString msgId = m_model->record(i).value(Constants::MESSAEGSDETAIL_INDEX_UUID).toString();
        
        // 根据消息的UUID，更新消息的状态。如果消息发送失败，则在消息前加上感叹号的图标。
        if (msgId == strMessageID)
        {
            QString status = bSendResult ? Constants::COMMUMESSAEGS_SENDSTATUS_TRUE : Constants::COMMUMESSAEGS_SENDSTATUS_FALSE;
            m_model->setData(m_model->index(i, Constants::COMMUMESSAGEDETAILl_INDEX_SENDSTATUS),
                             status);
        }
    }
    
    m_model->submitAll();
}

/****************************************************************************
**
** 函数名称：CallCommunication::SlotTalkReceive
** 功能概述: 通话上传
** 参数说明：通话上传
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunication::SlotTalkReceive(QString  strReceiveMessage)//通话上传
{
    Logging::get()->info("CallCommunication::SlotTalkReceive");
    sendMessage(strReceiveMessage);
}

/****************************************************************************
**
** 函数名称：CallCommunication::SlotTalkReceive
** 功能概述: ESC中断回执
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunication::SlotInteruptConfirm(bool b)
{
    Logging::get()->info("CallCommunication::SlotInteruptConfirm");
    homeClickedSlot();

}

/****************************************************************************
**
** 函数名称：CallCommunication::SlotInteruptDSC
** 功能概述: DSC中断
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunication::SlotInteruptDSC()
{
    Logging::get()->info("CallCommunication::SlotInteruptDSC");
    int intResult;
    m_commStatusMessage.SetIoc(":/images/images/Call_exclamatory_mark.png", 200, true);
    m_commStatusMessage.SetMessage(tr("Quit"), tr("DSC need NBDP quit!"), tr(""));
    m_commStatusMessage.SetButtonLayout(false, true);
    intResult =  m_commStatusMessage.exec();
    
    // 按下OK按钮,则保存当前数据,并跳到到HOME界面
    if (intResult == 1)
    {
        communicationExit(false);
        QMap <QString, QString>paraMap;
        emit afterPageSignal(CALL_COMMUNICATION_VIEW, HOME_VIEW_NAME, paraMap);
    }
}

/****************************************************************************
**
** 函数名称：CallCommunication::SlotInteruptComu
** 功能概述: Comu中断
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunication::SlotInteruptComu()
{
    Logging::get()->info("CallCommunication::SlotInteruptComu");
    int intResult;
    m_commStatusMessage.SetIoc(":/images/images/Call_exclamatory_mark.png", 200, true);
    m_commStatusMessage.SetMessage(tr("Quit"), tr("Communication outage!"), tr(""));
    m_commStatusMessage.SetButtonLayout(false, true);
    intResult =  m_commStatusMessage.exec();
    
    // 按下OK按钮,则保存当前数据,并跳到到HOME界面
    if (intResult == 1)
    {
        communicationExit(false);
        QMap <QString, QString>paraMap;
        emit afterPageSignal(CALL_COMMUNICATION_VIEW, HOME_VIEW_NAME, paraMap);
    }
}

/****************************************************************************
**
** 函数名称：CallCommunication::SlotMessageEnd
** 功能概述: 通话结束
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunication::SlotMessageEnd()
{
    Logging::get()->info("CallCommunication::SlotMessageEnd");
    int intResult;
    m_commStatusMessage.SetIoc(":/images/images/Call_exclamatory_mark.png", 250, true);
    m_commStatusMessage.SetMessage(tr("Warning"), tr("Message End!"), tr(""));
    m_commStatusMessage.SetButtonLayout(false, true);
    
    // 在FEC模式下,启动对话框操作超时计时器
    if (ui->callmode->text() != "ARQ")
    {
        m_dialogCloseWaitTime->start(ConfigUtils::getDialogCloseWaitTime());
    }
    
    intResult = m_commStatusMessage.exec();
    
    // 按下OK按钮,则跳转到home界面
    if (intResult == 1)
    {
        m_dialogCloseWaitTime->stop();
        communicationExit();
        QMap <QString, QString> paraMap;
        emit afterPageSignal(CALL_COMMUNICATION_VIEW, HOME_VIEW_NAME, paraMap);
    }
}

/****************************************************************************
**
** 函数名称：CallCommunication::SlotDialogCloseTimeout
** 功能概述: 对话框无人操作超时处理
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunication::SlotDialogCloseTimeout()
{
    emit hasUnreadMessage(true);
    communicationExit(false, true);
    m_dialogCloseWaitTime->stop();
    m_commStatusMessage.close();
    QMap <QString, QString> paraMap;
//    emit afterPageSignal(CALL_COMMUNICATION_VIEW, HOME_VIEW_NAME, paraMap);         yzz
}

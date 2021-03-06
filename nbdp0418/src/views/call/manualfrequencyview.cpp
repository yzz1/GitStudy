#include "manualfrequencyview.h"
#include "ui_manualfrequencyview.h"
#include "views/common/constants.h"
#include "widgets/iocmessage.h"
#include <QEvent>
#include <QKeyEvent>
#include "widgets/button.h"
#include "logging.h"
#include <QDebug>
#include "widgets/messagebox.h"
#include "../myCom/mainwindow.h"
/****************************************************************************
**
** 函数名称：ManualFrequencyView::ManualFrequencyView
** 功能概述: 初始化
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ManualFrequencyView::ManualFrequencyView(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::ManualFrequencyView)
{
    Logging::get()->info("ManualFrequencyView::ManualFrequencyView");
    ui->setupUi(this);
    ui->titleWidget->setText("MANUAL FREQUENCY");
    m_callOrReceive = true;
    m_editmode = false;
    QFont font("Ubuntu", 17, QFont::Bold);
    ui->listWidget->setFont(font);
    ui->listWidget->addItem(new QListWidgetItem(tr("    Call Name")));
    QFont font2("Ubuntu", 17);
    ui->listWidget_2->setFont(font2);
    ui->listWidget_2->addItem(new QListWidgetItem(tr("    Call Channel")));
    ui->listWidget_3->setFont(font2);
    ui->listWidget_3->addItem(new QListWidgetItem(tr("    Callcode")));
    ui->listWidget_4->setFont(font2);
    ui->listWidget_4->addItem(new QListWidgetItem(tr("    Tx Frequency(KHz)")));
    ui->listWidget_5->setFont(font2);
    ui->listWidget_5->addItem(new QListWidgetItem(tr("    Rx Frequency(KHz)")));
    ui->listWidget->setCurrentRow(0);
    this->installEventFilter(this);
    QRegExp rx("([0-9]+9)");
    ui->codelEdit->setValidator(new QRegExpValidator(rx, this));
    ui->channelEdit->setValidator(new QRegExpValidator(rx, this));
    ui->codelEdit->setMaxLength(CONTACTS_CALLCODE_MAXLEN);
    ui->nameEdit->setMaxLength(CONTACTS_NAME_MAXLEN);

    // 连接信号和槽
    connect(ui->homeBtn, SIGNAL(clicked()), this, SLOT(homeClickedSlot()));
    connect(ui->okBtn, SIGNAL(clicked()), this, SLOT(okButtonClickedSlot()));
    connect(ui->cancelBtn, SIGNAL(clicked()), this, SLOT(cancelButtonClickedSlot()));
    connect(ui->receiveBtn, SIGNAL(clicked()), this, SLOT(receiveButtonClickedSlot()));
    connect(ui->callBtn, SIGNAL(clicked()), this, SLOT(callButtonClickedSlot()));
}
/****************************************************************************
**
** 函数名称：ManualFrequencyView::callButtonClickedSlot
** 功能概述: 主叫选择
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManualFrequencyView:: callButtonClickedSlot()
{
    Logging::get()->info("ManualFrequencyView::callButtonClickedSlot");
    ui->receiveBtn->setIcon(QIcon(":/images/images/Receive_Bnt_SelNo.png"));
    ui->callBtn->setIcon(QIcon(":/images/images/Call_Bnt_SelYes.png"));
    m_callOrReceive = 1;

    if(m_callOrReceive==1) //主叫
      { g_mainWorkFlow->isCallRadio=1;CallClass::get()->setIsCall(true);}
    else//被叫
      { g_mainWorkFlow->isCallRadio=0;CallClass::get()->setIsCall(false);}

}
/****************************************************************************
**
** 函数名称：ManualFrequencyView::receiveButtonClickedSlot
** 功能概述: 被叫选择
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManualFrequencyView:: receiveButtonClickedSlot()
{
    Logging::get()->info("ManualFrequencyView::receiveButtonClickedSlot");
    ui->callBtn->setIcon(QIcon(":/images/images/Call_Bnt_SelNo.png"));
    ui->receiveBtn->setIcon(QIcon(":/images/images/Receive_Bnt_SelYes.png"));
    m_callOrReceive = 0;

    if(m_callOrReceive==1) //主叫
      { g_mainWorkFlow->isCallRadio=1;CallClass::get()->setIsCall(true);}
    else//被叫
      { g_mainWorkFlow->isCallRadio=0;CallClass::get()->setIsCall(false);}

}
/****************************************************************************
**
** 函数名称：ManualFrequencyView::frontPageSlot
** 功能概述: 打开页面时更新页面数据
** 参数说明： thisID：起始页面， fowordID：目标页面， paraMap：传递参数
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void  ManualFrequencyView::frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap)
{
    if (fowordID != MANUAL_FREQUENCY_VIEW)
    {
        return;
    }
    
    Logging::get()->info("ManualFrequencyView::frontPageSlot");
    m_editmode = false;

    /***************保存上一次的输入不清除*************/
//    ui->widget->editDataClean();
//    ui->widget_2->editDataClean();
//    ui->nameEdit->clear();
//    ui->channelEdit->clear();
//    ui->codelEdit->clear();
    m_callOrReceive = paraMap["callOrReceive"].toInt();
    
    if (m_callOrReceive)
    {
        ui->receiveBtn->setIcon(QIcon(":/images/images/Receive_Bnt_SelNo.png"));
        ui->callBtn->setIcon(QIcon(":/images/images/Call_Bnt_SelYes.png"));
    }
    else
    {
        ui->callBtn->setIcon(QIcon(":/images/images/Call_Bnt_SelNo.png"));
        ui->receiveBtn->setIcon(QIcon(":/images/images/Receive_Bnt_SelYes.png"));
    }
    
    ui->listWidget->setCurrentRow(0);
    ui->listWidget_2->setCurrentRow(-1);
    ui->listWidget_3->setCurrentRow(-1);
    ui->listWidget_4->setCurrentRow(-1);
    ui->listWidget_5->setCurrentRow(-1);
    QString image = ":/images/home_normal";
    ui->homeBtn->setIcon(QIcon(image));
    QString image2 = ":/images/images/Receive_Bnt_SelNo.png";
    ui->receiveBtn->setIcon(QIcon(image2));
    ui->nameEdit->setFocus();
}
/****************************************************************************
**
** 函数名称：ManualFrequencyView::～ManualFrequencyView
** 功能概述: 析构函数
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ManualFrequencyView::~ManualFrequencyView()
{
    Logging::get()->info("ManualFrequencyView::~ManualFrequencyView");
    delete ui;
}
/****************************************************************************
**
** 函数名称：ManualFrequencyView::eventFilter
** 功能概述: 事件监听函数，响应用户键盘操作。
** 参数说明：watched：发送方， event：事件数据
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool ManualFrequencyView::eventFilter(QObject* watched, QEvent* event)
{
    Logging::get()->info("ManualFrequencyView::eventFilter");
    QStringList nameList;
    nameList << "nameEdit" << "channelEdit" << "codelEdit" << "widget" << "widget_2"
             << "okBtn" << "cancelBtn" << "homeBtn" << "callBtn" << "receiveBtn";
    QKeyEvent* key_event = static_cast<QKeyEvent*>(event);
    int a =   key_event->key();
    QStringList widgetList;
    widgetList << "widget" << "widget_2";
    
    if (m_editmode)
    {
        if (QEvent::KeyPress == event->type()) // 按下时键屏蔽
        {
            return true;
        }
        else if (QEvent::KeyRelease  == event->type()) // 弹起时键屏蔽
        {
            return true;
        }
        
        if (a == Qt::Key_Enter || a == Qt::Key_Return)
        {
            m_editmode = false;
            
            for (int i = 0; i < widgetList.length(); i++)
            {
                QWidget* widget = findChild<QWidget*>(widgetList.at(i));
                
                if (widget && widget->hasFocus())
                {
                    FrequencyInput* inputwidget = static_cast<FrequencyInput*>(widget);
                    inputwidget->offEditmode();
                }
            }
        }
        else if (a == Qt::Key_Escape)
        {
            m_editmode = false;
            
            for (int i = 0; i < widgetList.length(); i++)
            {
                QWidget* widget = findChild<QWidget*>(widgetList.at(i));
                
                if (widget && widget->hasFocus())
                {
                    FrequencyInput* inputwidget = static_cast<FrequencyInput*>(widget);
                    inputwidget->offEditmode(false);
                }
            }
        }
        
        return true;
    }
    
    switch (a)
    {
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
        
        int next = 0;
        bool inTableView = false;
        
        for (int i = 0; i < nameList.length(); i++)
        {
            QWidget* widget = findChild<QWidget*>(nameList.at(i));
            
            if (widget && widget->hasFocus())
            {
                if (i < 5 && a == Qt::Key_Right)
                {
                    inTableView = true;
                    break;
                }
                
                // homeBtn callBtn receiveBtn 按钮获得光标
                if (nameList.at(i) == "homeBtn" || nameList.at(i) == "callBtn" || nameList.at(i) == "receiveBtn")
                {
                    if (nameList.at(i) == "homeBtn")
                    {
                        QToolButton* button = static_cast<QToolButton*>(widget);
                        QString image = ":/images/home_normal";
                        button->setIcon(QIcon(image));
                    }
                    else  if (nameList.at(i) == "callBtn")
                    {
                        if (!m_callOrReceive)
                        {
                            QToolButton* button = static_cast<QToolButton*>(widget);
                            QString image = ":/images/images/Call_Bnt_SelNo.png";
                            button->setIcon(QIcon(image));
                        }
                    }
                    else  if (nameList.at(i) == "receiveBtn")
                    {
                        if (m_callOrReceive)
                        {
                            QToolButton* button = static_cast<QToolButton*>(widget);
                            QString image = ":/images/images/Receive_Bnt_SelNo.png";
                            button->setIcon(QIcon(image));
                        }
                    }
                }
                else if (widgetList.count(nameList.at(i)))
                {
                    FrequencyInput* inputwidget = static_cast<FrequencyInput*>(widget);
                    inputwidget->widgetCleanFocus();
                }
                else if (i >= 0 && i <= 4)
                {
                    switch (i)
                    {
                    case 0:
                    {
                        ui->listWidget->setCurrentRow(-1);
                        break;
                    }
                    
                    case 1:
                    {
                        ui->listWidget_2->setCurrentRow(-1);
                        break;
                    }
                    
                    case 2:
                    {
                        ui->listWidget_3->setCurrentRow(-1);
                        break;
                    }
                    
                    case 3:
                    {
                        ui->listWidget_4->setCurrentRow(-1);
                        break;
                    }
                    
                    case 4:
                    {
                        ui->listWidget_5->setCurrentRow(-1);
                        break;
                    }
                    break;
                    }
                }
                
                next = (i == nameList.length() - 1) ? 0 : i + 1;
                break;
            }
        }
        
        if (inTableView)
            break;
            
        QWidget* widgetnext = findChild<QWidget*>(nameList.at(next));
        
        if (widgetnext)
        {
            widgetnext->setFocus();
            
            // homeBtn callBtn receiveBtn 按钮获得光标
            if (nameList.at(next) == "homeBtn" || nameList.at(next) == "callBtn" || nameList.at(next) == "receiveBtn")
            {
                if (nameList.at(next) == "homeBtn")
                {
                    QToolButton* button = static_cast<QToolButton*>(widgetnext);
                    QString image = ":/images/home_hover";
                    button->setIcon(QIcon(image));
                }
                else  if (nameList.at(next) == "callBtn")
                {
                    if (!m_callOrReceive)
                    {
                        QToolButton* button = static_cast<QToolButton*>(widgetnext);
                        QString image = ":/images/images/Call_Bnt_SelYes.png";
                        button->setIcon(QIcon(image));
                    }
                }
                else  if (nameList.at(next) == "receiveBtn")
                {
                    if (m_callOrReceive)
                    {
                        QToolButton* button = static_cast<QToolButton*>(widgetnext);
                        QString image = ":/images/images/Receive_Bnt_SelYes.png";
                        button->setIcon(QIcon(image));
                    }
                }
            }
            else if (widgetList.count(nameList.at(next)))
            {
                FrequencyInput* inputwidget = static_cast<FrequencyInput*>(widgetnext);
                inputwidget->widgetSetFocus();
            }
            else if (next >= 0 && next <= 4)
            {
                switch (next)
                {
                case 0:
                {
                    ui->listWidget->setCurrentRow(0);
                    break;
                }
                
                case 1:
                {
                    ui->listWidget_2->setCurrentRow(0);
                    break;
                }
                
                case 2:
                {
                    ui->listWidget_3->setCurrentRow(0);
                    break;
                }
                
                case 3:
                {
                    ui->listWidget_4->setCurrentRow(0);
                    break;
                }
                
                case 4:
                {
                    ui->listWidget_5->setCurrentRow(0);
                    break;
                }
                break;
                }
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
        
        int prev = 0;
        bool inTableView = false;
        
        for (int i = 0; i < nameList.length(); i++)
        {
            QWidget* widget = findChild<QWidget*>(nameList.at(i));
            
            if (widget && widget->hasFocus())
            {
                if (i < 5 && a == Qt::Key_Left)
                {
                    inTableView = true;
                    break;
                }
                
                // homeBtn callBtn receiveBtn 按钮获得光标
                if (nameList.at(i) == "homeBtn" || nameList.at(i) == "callBtn" || nameList.at(i) == "receiveBtn")
                {
                    if (nameList.at(i) == "homeBtn")
                    {
                        QToolButton* button = static_cast<QToolButton*>(widget);
                        QString image = ":/images/home_normal";
                        button->setIcon(QIcon(image));
                    }
                    else  if (nameList.at(i) == "callBtn")
                    {
                        if (!m_callOrReceive)
                        {
                            QToolButton* button = static_cast<QToolButton*>(widget);
                            QString image = ":/images/images/Call_Bnt_SelNo.png";
                            button->setIcon(QIcon(image));
                        }
                    }
                    else  if (nameList.at(i) == "receiveBtn")
                    {
                        if (m_callOrReceive)
                        {
                            QToolButton* button = static_cast<QToolButton*>(widget);
                            QString image = ":/images/images/Receive_Bnt_SelNo.png";
                            button->setIcon(QIcon(image));
                        }
                    }
                }
                else if (widgetList.count(nameList.at(i)))
                {
                    FrequencyInput* inputwidget = static_cast<FrequencyInput*>(widget);
                    inputwidget->widgetCleanFocus();
                }
                else if (i >= 0 && i <= 4)
                {
                    switch (i)
                    {
                    case 0:
                    {
                        ui->listWidget->setCurrentRow(-1);
                        break;
                    }
                    
                    case 1:
                    {
                        ui->listWidget_2->setCurrentRow(-1);
                        break;
                    }
                    
                    case 2:
                    {
                        ui->listWidget_3->setCurrentRow(-1);
                        break;
                    }
                    
                    case 3:
                    {
                        ui->listWidget_4->setCurrentRow(-1);
                        break;
                    }
                    
                    case 4:
                    {
                        ui->listWidget_5->setCurrentRow(-1);
                        break;
                    }
                    break;
                    }
                }
                
                prev = (i == 0) ? nameList.length() - 1 : i - 1;
                break;
            }
        }
        
        if (inTableView)
            break;
            
        QWidget* widgetprev = findChild<QWidget*>(nameList.at(prev));
        widgetprev->setFocus();
        
        if (widgetprev)
        {
            widgetprev->setFocus();
            
            // homeBtn callBtn receiveBtn 按钮获得光标
            if (nameList.at(prev) == "homeBtn" || nameList.at(prev) == "callBtn" || nameList.at(prev) == "receiveBtn")
            {
                if (nameList.at(prev) == "homeBtn")
                {
                    QToolButton* button = static_cast<QToolButton*>(widgetprev);
                    QString image = ":/images/home_hover";
                    button->setIcon(QIcon(image));
                }
                else  if (nameList.at(prev) == "callBtn")
                {
                    if (!m_callOrReceive)
                    {
                        QToolButton* button = static_cast<QToolButton*>(widgetprev);
                        QString image = ":/images/images/Call_Bnt_SelYes.png";
                        button->setIcon(QIcon(image));
                    }
                }
                else  if (nameList.at(prev) == "receiveBtn")
                {
                    if (m_callOrReceive)
                    {
                        QToolButton* button = static_cast<QToolButton*>(widgetprev);
                        QString image = ":/images/images/Receive_Bnt_SelYes.png";
                        button->setIcon(QIcon(image));
                    }
                }
            }
            else if (widgetList.count(nameList.at(prev)))
            {
                FrequencyInput* inputwidget = static_cast<FrequencyInput*>(widgetprev);
                inputwidget->widgetSetFocus();
            }
            else if (prev >= 0 && prev <= 4)
            {
                switch (prev)
                {
                case 0:
                {
                    ui->listWidget->setCurrentRow(0);
                    break;
                }
                
                case 1:
                {
                    ui->listWidget_2->setCurrentRow(0);
                    break;
                }
                
                case 2:
                {
                    ui->listWidget_3->setCurrentRow(0);
                    break;
                }
                
                case 3:
                {
                    ui->listWidget_4->setCurrentRow(0);
                    break;
                }
                
                case 4:
                {
                    ui->listWidget_5->setCurrentRow(0);
                    break;
                }
                break;
                }
            }
        }
        
        break;
    }
    
    case Qt::Key_Return:
    case Qt::Key_Enter:
    {
        if (QEvent::KeyPress == event->type()) // 按下时键屏蔽
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type()) // 弹起时键屏蔽
        {
            return true;
        }
        
        for (int i = 0; i < nameList.length(); i++)
        {
            QWidget* widget = findChild<QWidget*>(nameList.at(i));
            
            // homeBtn callBtn receiveBtn 按钮获得光标
            if (widget && widget->hasFocus())
            {
                if (nameList.at(i) == "homeBtn")
                {
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                }
                else if (nameList.at(i) == "callBtn")
                {
                    ui->receiveBtn->setIcon(QIcon(":/images/images/Receive_Bnt_SelNo.png"));
                    ui->callBtn->setIcon(QIcon(":/images/images/Call_Bnt_SelYes.png"));
                    m_callOrReceive = !m_callOrReceive;
                }
                else if (nameList.at(i) == "receiveBtn")
                {
                    ui->callBtn->setIcon(QIcon(":/images/images/Call_Bnt_SelNo.png"));
                    ui->receiveBtn->setIcon(QIcon(":/images/images/Receive_Bnt_SelYes.png"));
                    m_callOrReceive = !m_callOrReceive;
                }
                else if (widgetList.count(nameList.at(i)))
                {
                    FrequencyInput* inputwidget = static_cast<FrequencyInput*>(widget);
                    bool txOrRx;
                    int n = 0;
                    
                    for (; n < widgetList.length(); n++)
                    {
                        if (widgetList.at(n) == nameList.at(i))
                            break;
                            
                        if (n + 1 == widgetList.length())
                            n = -1;
                    }
                    
                    if (n % 2 == 1)
                        txOrRx = false;
                    else
                        txOrRx = true;
                        
                    inputwidget->openEditmode(txOrRx);
                    inputwidget->widgetCleanFocus();
                    m_editmode = true;
                }
                
                break;
            }
        }
        
        break;
    }
    
    case Qt::Key_Escape:
    {
        if (QEvent::KeyPress == event->type()) // 按下时键屏蔽
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type()) // 弹起时键屏蔽
        {
            return true;
        }
        
        QWidget* widget = findChild<QWidget*>("cancelBtn");
        
        if (widget)
        {
            Button* button = static_cast<Button*>(widget);
            button->click();
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
** 函数名称：ManualFrequencyView::homeClickedSlot
** 功能概述: home按钮响应，跳转到主菜单。
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManualFrequencyView:: homeClickedSlot()
{
    Logging::get()->info("ManualFrequencyView::homeClickedSlot");
    QMap <QString, QString> paraMap;
    emit afterPageSignal(MANUAL_FREQUENCY_VIEW, HOME_VIEW_NAME, paraMap);
}
/****************************************************************************
**
** 函数名称：ManualFrequencyView::okButtonClickedSlot
** 功能概述: 跳转到CALL主菜单。
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManualFrequencyView:: okButtonClickedSlot()
{
    Logging::get()->info("ManualFrequencyView::okButtonClickedSlot");
    QMap <QString, QString> paraMap;
    QString name = ui->nameEdit->text();
    QString callCode = ui->codelEdit->text();
    QString channel = ui->channelEdit->text();
    QString tx = ui->widget->getData();
    QString rx = ui->widget_2->getData();
    
    // 如果Callcode、Channel、TX和RX都为空，则报错
    if (callCode.isEmpty() && channel.isEmpty() && tx.isEmpty() && rx.isEmpty())
    {
        IocMessage infomsg;
        infomsg.move((SCREEN_SIZE_WIDTH - infomsg.width()) / 2, (SCREEN_SIZE_HEIGHT - infomsg.height()) / 2);
        infomsg.SetIoc(":/images/images/Call_exclamatory_mark.png", 20, false);
        infomsg.SetMessage(tr("Warning"), tr("The  channel or call code,Tx and Rx cann't be empty!"),
                           tr("Please check and type in!"));
        QFont font("Ubuntu", 18, QFont::Bold);
        infomsg.SetFont(font);
        infomsg.exec();
        return ;
    }
    
    // 如果通道不为空，则查询数据库，判断当前通道是否存在，不存在则报错
    if (!channel.isEmpty())
    {
        Database* database = new Database();
        database->openConnection();
        QSqlQuery queryFrequency = database->getQuery();
        QString Frequency = "select FKey,Tx,Rx from Frequency where channel= ";
        Frequency.append("'");
        Frequency.append(channel);
        Frequency.append("';");
        queryFrequency.prepare(Frequency);
        queryFrequency.exec();
        
        if (queryFrequency.next())
        {
            QSqlQuery queryStation = database->getQuery();
            QString station = "select  name,CallCode  from station  where uuid=";
            station.append("'") ;
            station.append(queryFrequency.value(0).toString());
            station.append("';  ") ;
            queryStation.prepare(station);
            queryStation.exec();
            
            if (queryStation.next())
            {
                name = queryStation.value(0).toString();
                callCode = queryStation.value(1).toString();
            }
            else
            {
                name.clear();
                callCode.clear();
            }
            
            tx = queryFrequency.value(1).toString();
            rx = queryFrequency.value(2).toString();
            ui->nameEdit->setText(name);
            ui->codelEdit->setText(callCode);
            ui->widget->setData(tx);
            ui->widget_2->setData(rx);
        }
        else
        {
            IocMessage infomsg;
            infomsg.move((SCREEN_SIZE_WIDTH - infomsg.width()) / 2, (SCREEN_SIZE_HEIGHT - infomsg.height()) / 2);
            infomsg.SetIoc(":/images/images/Call_exclamatory_mark.png", 120, false);
            infomsg.SetMessage(tr("Warning"), tr("The channel does not exist ! "), tr("Please check and type in!"));
            QFont font("Ubuntu", 18, QFont::Bold);
            infomsg.SetFont(font);
            infomsg.exec();
            return;
        }
    }
    
    // 判断Callcode是否为4位，5位，9位数字，如果不是，则报错
    QRegExp re("\\d{4}|\\d{5}|\\d{9}");
    if (!callCode.isEmpty() && !re.exactMatch(callCode))
    {
        IocMessage infomsg;
        infomsg.move((SCREEN_SIZE_WIDTH - infomsg.width()) / 2, (SCREEN_SIZE_HEIGHT - infomsg.height()) / 2);
        infomsg.SetIoc(":/images/images/Call_exclamatory_mark.png", 120, false);
        infomsg.SetMessage(tr("Warning"), tr("Callcode Error! "), tr("Callcode must be 4 or 5 or 9 digits!"));
        QFont font("Ubuntu", 18, QFont::Bold);
        infomsg.SetFont(font);
        infomsg.exec();
        return;
    }
    
    paraMap.insert("name", name);
    paraMap.insert("callCode", callCode);
    paraMap.insert("channel", channel);
    paraMap.insert("tx", tx);
    paraMap.insert("rx", rx);
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
    emit afterPageSignal(FREQUENCY_VIEW, CALL_VIEW_NAME, paraMap);
}
/****************************************************************************
**
** 函数名称：ManualFrequencyView::cancelButtonClickedSlot
** 功能概述: 返回到CALL主菜单。
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManualFrequencyView:: cancelButtonClickedSlot()
{
    Logging::get()->info("ManualFrequencyView::cancelButtonClickedSlot");
    QMap <QString, QString> paraMap;
    emit afterPageSignal(MANUAL_FREQUENCY_VIEW, CALL_VIEW_NAME, paraMap);
}

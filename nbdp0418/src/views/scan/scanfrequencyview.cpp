#include "scanfrequencyview.h"
#include "ui_scanfrequencyview.h"
#include "views/common/constants.h"
#include <QEvent>
#include <QKeyEvent>
#include "widgets/button.h"
#include <QDebug>  //qi
#include "logging.h"
/****************************************************************************
**
** 函数名称：ScanFrequencyView::ScanFrequencyView
** 功能概述: 初始化
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ScanFrequencyView::ScanFrequencyView(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::ScanFrequencyView)
{
    Logging::get()->info("ScanFrequencyView::ScanFrequencyView");
    ui->setupUi(this);
    ui->titleWidget->setText(Constants::SCAN_FREQUENCY_TITLE);
    this->installEventFilter(this);
    m_TimeCount = 1;
    ui->listWidget->addItem(new QListWidgetItem(
                                tr("1            0000.0    0000.0"))); //1+12+6+4+6   手动设置间隔空间  下同
    ui->listWidget->setCurrentRow(0);
    ui->listWidget->addItem(new QListWidgetItem(tr("2")));
    ui->listWidget->addItem(new QListWidgetItem(tr("3")));
    ui->listWidget->addItem(new QListWidgetItem(tr("4")));
    ui->listWidget->addItem(new QListWidgetItem(tr("5")));
    ui->listWidget->addItem(new QListWidgetItem(tr("6")));
    ui->listWidget->addItem(new QListWidgetItem(tr("7")));
    ui->listWidget->addItem(new QListWidgetItem(tr("8")));
    ui->listWidget->addItem(new QListWidgetItem(tr("9")));
    ui->listWidget->addItem(new QListWidgetItem(tr("10")));
    ui->listWidget_2->addItem(new QListWidgetItem(tr("11")));
    ui->listWidget_2->addItem(new QListWidgetItem(tr("12")));
    ui->listWidget_2->addItem(new QListWidgetItem(tr("13")));
    ui->listWidget_2->addItem(new QListWidgetItem(tr("14")));
    ui->listWidget_2->addItem(new QListWidgetItem(tr("15")));
    ui->listWidget_2->addItem(new QListWidgetItem(tr("16")));
    ui->listWidget_2->addItem(new QListWidgetItem(tr("17")));
    ui->listWidget_2->addItem(new QListWidgetItem(tr("18")));
    ui->listWidget_2->addItem(new QListWidgetItem(tr("19")));
    ui->listWidget_2->addItem(new QListWidgetItem(tr("20")));
    QFont font("Ubuntu", 18, QFont::Normal);
    
    for (int i = 0; i < 10; i++)
    {
        ui->listWidget_2->item(i)->setFont(font);
        ui->listWidget->item(i)->setFont(font);
    }    
    connect(ui->stopBnt, SIGNAL(clicked()), this, SLOT(stopClickedSolt()));
}
/****************************************************************************
**
** 函数名称：ScanFrequencyView::SlotScanData
** 功能概述: 返回频率保存数据到call页面
** 参数说明  扫描成功后的频率数据
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ScanFrequencyView::SlotScanData(CallInfoClass* cic)
{
    QMap <QString, QString> paraMap;
    paraMap.insert(CALL_OR_RECEIVE, Constants::CALL_SET_CALLRECEIVE_RECEIVE);
    QString strCallMode = cic->getCallType();
    QString name = cic->getCallName();
    QString callcode = cic->getCallCode();

    if (name.isEmpty() && !callcode.isEmpty())
    {
        name = callcode;
    }

    paraMap.insert(Constants::CALL_SET_CALL_MODE, strCallMode);
    paraMap.insert(Constants::MESSAEGS_LIST_COL_NAME, name);
    paraMap.insert(Constants::MESSAEGS_LIST_COL_CALLCODE, callcode);
    QString tx = cic->getCallTx();
    QString rx = cic->getCallRx();
    
    if (tx == "" && rx != "")
    {
        tx = rx;
    }
    
    paraMap.insert(Constants::MESSAEGS_LIST_COL_TX, tx);
    paraMap.insert(Constants::MESSAEGS_LIST_COL_RX, rx);
    paraMap.insert(Constants::MESSAEGS_LIST_COL_CHANNEL, cic->getCallChannel());
    emit afterPageSignal(SCAN_FREQUENCY_VIEW, CALL_COMMUNICATION_VIEW, paraMap);
}
/****************************************************************************
**
** 函数名称：ScanFrequencyView::timerEvent
** 功能概述: 定时器，定时滚动频率
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ScanFrequencyView::timerEvent(QTimerEvent* event)
{
    Logging::get()->info("ScanFrequencyView::timerEvent");
    
    if (!m_recordCount)
        return;
        
    if (m_recordCount == m_TimeCount)
    {
        m_TimeCount = 0;
    }
    
    if (m_TimeCount < 10)
    {
        ui->listWidget->setCurrentRow(m_TimeCount);
    }
    else if (m_TimeCount < SCAN_GROUP_MAX_DISPLAY_DATA)
    {
        ui->listWidget_2->setCurrentRow(m_TimeCount - 10);
    }
    
    if (m_TimeCount == 10)
        ui->listWidget->setCurrentRow(-1);
        
    if (m_TimeCount == 0)
        ui->listWidget_2->setCurrentRow(-1);
        
    m_TimeCount++;
}

/****************************************************************************
**
** 函数名称：ScanFrequencyView::frontPageSlot
** 功能概述: 打开页面时更新页面数据
** 参数说明： thisID：起始页面， fowordID：目标页面， paraMap：传递参数
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void  ScanFrequencyView::frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap)
{
    if (fowordID != SCAN_FREQUENCY_VIEW) {return;}
    
    Logging::get()->info("ScanFrequencyView::frontPageSlot");
    int recordCount = paraMap["recordCount"].toInt();
    m_recordCount = recordCount;
    
    for (int n = 0; n < SCAN_GROUP_MAX_DISPLAY_DATA; n++)
    {
        QString tx = "TX";
        tx += QString::number(n + 1);
        QString rx = "RX";
        rx += QString::number(n + 1);
        
        if (n < 10)
        {
            if (n < recordCount)
            {
                QString text = QString::number(n + 1);
                int m = 18;
                
                if (n == 9)
                    m = 16;
                    
                for (int i = 0 ; i < m - paraMap[tx].length() ; i++)
                    text += " ";
                    
                text += paraMap[tx];
                
                if (paraMap[tx].length() < 5)
                {
                    for (int i = 0 ; i < 5 - paraMap[tx].length() ; i++)
                    {
                        text += " ";
                    }
                }
                
                for (int i = 0 ; i < 10 - paraMap[rx].length() ; i++)
                    text += " ";
                    
                text += paraMap[rx];
                ui->listWidget->item(n)->setText(text);
            }
            else
            {
                QString text = QString::number(n + 1);
                ui->listWidget->item(n)->setText(text);
            }
        }
        else
        {
            if (n < recordCount)
            {
                QString text = QString::number(n);
                
                for (int i = 0 ; i < 18 - paraMap[tx].length() ; i++)
                    text += " ";
                    
                text += paraMap[tx];
                
                if (paraMap[tx].length() < 5)
                {
                    for (int i = 0 ; i < 5 - paraMap[tx].length() ; i++)
                    {
                        text += " ";
                    }
                }
                
                for (int i = 0 ; i < 10 - paraMap[rx].length() ; i++)
                    text += " ";
                    
                text += paraMap[rx];
                ui->listWidget_2->item(n - 10)->setText(text);
            }
            else
            {
                QString text = QString::number(n);
                ui->listWidget_2->item(n - 10)->setText(text);
            }
        }
    }
    
    ui->stopBnt->setFocus();
    m_nTimerId = startTimer(3000);
}
/****************************************************************************
**
** 函数名称：ScanFrequencyView::stopClickedSolt
** 功能概述: 停止扫描
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ScanFrequencyView::stopClickedSolt()
{
    Logging::get()->info("ScanFrequencyView::stopClickedSolt");
    killTimer(m_nTimerId);
    Transit::get()->EmitSignalKillSendScanFreqTimer();

    ui->listWidget->setCurrentRow(0);
    ui->listWidget_2->setCurrentRow(-1);
    m_TimeCount = 1;
    QMap <QString, QString>paraMap;
    emit afterPageSignal(SCAN_FREQUENCY_VIEW, SCAN_GROUP_VIEW, paraMap);
}
/****************************************************************************
**
** 函数名称：ScanFrequencyView::～ScanFrequencyView
** 功能概述: 析构函数
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ScanFrequencyView::~ScanFrequencyView()
{
    Logging::get()->info("ScanFrequencyView::~ScanFrequencyView");
    delete ui;
}
/****************************************************************************
**
** 函数名称：ScanFrequencyView::eventFilter
** 功能概述: 事件监听函数，响应用户键盘操作
** 参数说明：watched：发送方， event：事件数据
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool ScanFrequencyView::eventFilter(QObject* watched, QEvent* event)
{
    Logging::get()->info("ScanFrequencyView::eventFilter");
    QKeyEvent* key_event = static_cast<QKeyEvent*>(event);
    int a =   key_event->key();
    // 按下时键屏蔽
    // 弹起时键屏蔽
    // 默认键值51 响应一次
    switch (a)
    {
    case Qt::Key_Right:
    case Qt::Key_Down:
    case Qt::Key_Tab:
    case Qt::Key_Up:
    case Qt::Key_Backtab:
    case Qt::Key_Left:
    {
        if (QEvent::KeyPress == event->type())
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type())
        {
            return true;
        }
        
        if (ui->startBnt->hasFocus())
        {
            ui->stopBnt->setFocus();
        }
        else
        {
            ui->startBnt->setFocus();
        }
        
        break;
    }
    
    case Qt::Key_Return:
    case Qt::Key_Enter:
    {
        if (QEvent::KeyPress == event->type())
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type())
        {
            return true;
        }
        
        if (ui->startBnt->hasFocus())
        {
            ui->startBnt->click();
        }
        else
        {
            ui->stopBnt->click();
        }
        
        break;
    }
    }
    
    if (a == Qt::Key_Escape)
        return true;
        
    return QWidget::eventFilter(watched, event);
}

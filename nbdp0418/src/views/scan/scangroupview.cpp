#include "scangroupview.h"
#include "ui_scangroupview.h"
#include "views/common/constants.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include "models/managerdelegate.h"
//#include <QVariant>
#include "core/database/connectionpool.h"
#include "core/database/database.h"
#include "core/utils/sqlitehelper.h"
#include "widgets/messagebox.h"
#include <QEvent>
#include <QKeyEvent>
#include "widgets/button.h"
#include "scangroupstyle.h"
#include "logging.h"
#include <QDebug>
/****************************************************************************
**
** 函数名称：ScanGroupView::ScanGroupView
** 功能概述: 初始化
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ScanGroupView::ScanGroupView(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::ScanGroupView)
{
    Logging::get()->info("ScanGroupView::ScanGroupView");
    ui->setupUi(this);
    ui->titleWidget->setText(Constants::SCAN_GROUP_TITLE);
    this->installEventFilter(this);
    m_sc =  ScanClass::get();
    m_model = new ContactsModel(this, SQLiteHelper::openConnection());
    m_model->setTable(tr("scangroup"));
    m_model->setSort(2, Qt::AscendingOrder);
    m_model->select();
    ui->tableView->setModel(m_model);
    Qt::Alignment am = Qt::AlignLeft | Qt::AlignVCenter;
    m_model->setAlignment(am);
    ScanGroupStyle* contactsStyle = new ScanGroupStyle();
    ManagerDelegate* contactsItemDelegate = new ManagerDelegate(0, contactsStyle);
    ui->tableView->setItemDelegate(contactsItemDelegate);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(6, true);
    ui->tableView->setColumnHidden(3, true);
    ui->tableView->setColumnHidden(4, true);
    ui->tableView->setColumnHidden(5, true);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->verticalHeader()->hide();
    QHeaderView* header = ui->tableView->horizontalHeader();
    header->resizeSection(Constants::SCAN_GROUP_INDEX_SHOWPIX, 40);
    header->resizeSection(Constants::SCAN_GROUP_INDEX_GROUPNAME, 160);
    ui->tableView->selectRow(0);
    ui->tableView->setFocus();
    ScanGroupFrequency temp;
    
    for (int i = 0; i < 20; i++)
    {
        m_display[i] = false;
        m_list.append(temp);
    }
    
    m_display[0] = true;
    m_display[1] = true;
    m_display[2] = true;
    m_display[3] = true;
    connect(ui->arrowUpButton_2, SIGNAL(clicked()), this, SLOT(arrowUpButtonClicked()));
    connect(ui->arrowDownButton_2, SIGNAL(clicked()), this, SLOT(arrowDownButtonClicked()));
    connect(ui->tableView->selectionModel(), SIGNAL(currentChanged(const QModelIndex&, const QModelIndex&)),
            this, SLOT(currentChangedSlot(const QModelIndex&, const QModelIndex&)));
    connect(ui->deleteBnt, SIGNAL(clicked()), this, SLOT(deleteSelectedRow()));
    connect(ui->editBnt, SIGNAL(clicked()), this, SLOT(editClickedSolt()));
    connect(ui->newBnt, SIGNAL(clicked()), this, SLOT(newClickedSolt()));
    connect(ui->startBnt, SIGNAL(clicked()), this, SLOT(startClickedSolt()));
    connect(ui->homeBtn, SIGNAL(clicked()), this, SLOT(homeClickedSlot()));
    QModelIndex current;
    QModelIndex previous;
    currentChangedSlot(current,  previous);
}
/****************************************************************************
**
** 函数名称：ScanGroupView::startClickedSolt
** 功能概述: 进入扫描频率界面
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ScanGroupView:: startClickedSolt()
{
    Logging::get()->info("ScanGroupView::startClickedSolt");
    bool bError = false;
    
    for (int n = 0; n < m_recordCount; n++)
    {
        if (m_list[n].strTx.trimmed() == "" || m_list[n].strRx.trimmed()  == "")
        {
            bError = true;
        }
    }
    
    if (bError || !m_recordCount)//数据不全或为空
    {
        MessageBox  msg;
        msg.SetMessage(tr("Error"), tr("TX and RX cannot be empty."), 0);
        msg.exec() ;
        return ;
    }
    
    QMap <QString, QString>paraMap;
    m_sc->setIsScan(true);
    QString dwellTime = ui->tableView->model()->index(ui->tableView->currentIndex().row(), 3).data().toString();
    QString scanMode = ui->tableView->model()->index(ui->tableView->currentIndex().row(), 4).data().toString();
    m_sc->setDwellTime(dwellTime);
    m_sc->setScanMode(scanMode);
    m_sc->setScanGroup(m_recordCount);
    QList<ChannelInfoClass>* cnlicl = m_sc->getChannelInfoList();
    cnlicl->clear();
    int m = 0;
    
    for (int n = 0; n < m_recordCount; n++)
    {
        if (m_list[n].scanFlag == "S")
        {
            QString num = "TX";
            num += QString::number(m + 1);
            paraMap.insert(num, m_list[n].strTx);
            QString num2 = "RX";
            num2 += QString::number(m + 1);
            paraMap.insert(num2, m_list[n].strRx);
            ChannelInfoClass temp;
            temp.setTx(m_list[n].strTx);
            temp.setRx(m_list[n].strRx);
            m_sc->addChannelInfoClass(temp);
            m++;
        }
    }
    
    paraMap.insert("recordCount", QString::number(m));
    Transit::get()->EmitSignalScan(m_sc);

    emit afterPageSignal(SCAN_GROUP_VIEW, SCAN_FREQUENCY_VIEW, paraMap);
}
/****************************************************************************
**
** 函数名称：ScanGroupView::deleteSelectedRow
** 功能概述: 删除记录
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ScanGroupView:: deleteSelectedRow()
{
    Logging::get()->info("ScanGroupView::deleteSelectedRow");
    MessageBox  msg;
    
    if (m_model->rowCount() == 0)
    {
        msg.SetMessage(tr("Delete"), tr("No row is selected"), 0);
        msg.exec() ;
        return ;
    }
    
    msg.SetMessage(tr("Delete"), tr("Are you sure to delete this item ?"), 1);
    
    if (msg.exec() != 1) {return ;}
    
    int curRow = ui->tableView->currentIndex().row();
    QModelIndex index = ui->tableView->currentIndex();
    QString strUUID = index.sibling(curRow, 0).data().toString();
    int intSelectRow;
    int intRowCount = m_model->rowCount();
    
    if (intRowCount - 1 > curRow)
    {
        intSelectRow = curRow;
    }
    else if (intRowCount - 1 == curRow  && curRow != 0)
    {
        intSelectRow = curRow - 1;
    }
    else
    {
        intSelectRow = 0;
    }
    
    m_model->removeRows(curRow, 1);
    m_model->submitAll();
    Database* database = new Database();
    database->openConnection();
    bool hasTransaction = database->transaction();
    QString sqlFrequencyDel = "delete from Frequency where FKey=:Fkey";
    QVariantMap mapMessageDetail;
    bool bResultExe = false;
    mapMessageDetail.insert(Constants::MESSAEGS_SHOW_COL_FKEY, strUUID);
    bResultExe = database->executeSql(sqlFrequencyDel, mapMessageDetail);
    
    if (hasTransaction && bResultExe)
    {
        database->commit();
    }
    else
    {
        database->rollback();
    }
    
    ui->tableView->setFocus();
    ui->tableView->selectRow(intSelectRow);
}
/****************************************************************************
**
** 函数名称：ScanGroupView::editClickedSolt
** 功能概述: 进入编辑记录界面
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ScanGroupView:: editClickedSolt()
{
    Logging::get()->info("ScanGroupView::editClickedSolt");
    QMap <QString, QString>paraMap;
    int curRow = ui->tableView->currentIndex().row();
    QModelIndex index = ui->tableView->currentIndex();
    QString strModle  =  QString(SCAN_GROUP_MODLE_EDIT);
    QString strUUID = index.sibling(curRow, 0).data().toString();
    QString strGroupName = index.sibling(curRow, 2).data().toString();
    QString strDwellTime = index.sibling(curRow, 3).data().toString();
    QString strScanMode = index.sibling(curRow, 4).data().toString();
    paraMap.insert(CONTACTS_STATION_MODLE_NAME, strModle);
    paraMap.insert(Constants::SCAN_GROUP_UUID, strUUID);
    paraMap.insert(Constants::SCAN_GROUP_GROUPNAME, strGroupName);
    paraMap.insert(Constants::SCAN_GROUP_DWELLTIME, strDwellTime);
    paraMap.insert(Constants::SCAN_GROUP_SCANMODE, strScanMode);
    emit afterPageSignal(SCAN_GROUP_VIEW, SCAN_GROUP_EDIT_VIEW, paraMap);
}
/****************************************************************************
**
** 函数名称：ScanGroupView::newClickedSolt
** 功能概述: 进入新建记录界面
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ScanGroupView:: newClickedSolt()
{
    Logging::get()->info("ScanGroupView::newClickedSolt");
    
    if (m_model->rowCount() >= 20)
    {
        MessageBox  msg;
        msg.SetMessage(tr("Warning"), tr("The maximum number of records is 20."), 0);
        msg.exec() ;
        return;
    }
    
    QMap <QString, QString>paraMap;
    QString strModle  =  QString(SCAN_GROUP_MODLE_NEW);
    paraMap.insert(SCAN_GROUP_MODLE_NAME, strModle);
    emit afterPageSignal(SCAN_GROUP_VIEW, SCAN_GROUP_EDIT_VIEW, paraMap);
}
/****************************************************************************
**
** 函数名称：ScanGroupView::homeClickedSlot
** 功能概述: 返回到主菜单
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ScanGroupView:: homeClickedSlot()
{
    Logging::get()->info("ScanGroupView::homeClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(SCAN_GROUP_VIEW, HOME_VIEW_NAME, paraMap);
}
/****************************************************************************
**
** 函数名称：ScanGroupView::arrowDownButtonClicked
** 功能概述: 频率下拉处理
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void  ScanGroupView::arrowDownButtonClicked()
{
    Logging::get()->info("ScanGroupView::arrowDownButtonClicked");
    
    if (ui->tx_5->text() == NULL && ui->rx_5->text() == NULL)//最后一行为空时，不往下翻
    {
        if (m_display[SCAN_GROUP_MAX_DISPLAY_DATA - 1])
        {
            MessageBox  msg;
            msg.SetMessage(tr("Warning"), tr("No data to display"), 0);
            msg.exec() ;
            return;
        }
        else
        {
            int n = 0;
            bool bDisplay = false;
            
            while (n < SCAN_GROUP_MAX_DISPLAY_DATA)
            {
                if (m_display[n])
                {
                    bDisplay = true;
                }
                else if (bDisplay)
                {
                    if (m_list[n].strTx  != "" || m_list[n].strRx  != "")
                        break;
                }
                
                if (n == SCAN_GROUP_MAX_DISPLAY_DATA - 1)
                {
                    MessageBox  msg;
                    msg.SetMessage(tr("Warning"), tr("No data to display"), 0);
                    msg.exec() ;
                    return;
                }
                
                n++;
            }
        }
    }
    
    for (int n = 0 ; n < SCAN_GROUP_MAX_DISPLAY_DATA - 4; n++)
    {
        if (m_display[n])
        {
            m_display[n] = false;
            ui->tx_2->setText(m_list[n + 1].strTx);
            ui->rx_2->setText(m_list[n + 1].strRx);
            ui->tx_3->setText(m_list[n + 2].strTx);
            ui->rx_3->setText(m_list[n + 2].strRx);
            ui->tx_4->setText(m_list[n + 3].strTx);
            ui->rx_4->setText(m_list[n + 3].strRx);
            ui->tx_5->setText(m_list[n + 4].strTx);
            ui->rx_5->setText(m_list[n + 4].strRx);
            m_display[n + 4] = true;
            break;
        }
    }
}
/****************************************************************************
**
** 函数名称：ScanGroupView::arrowUpButtonClicked
** 功能概述: 频率上拉处理
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void  ScanGroupView::arrowUpButtonClicked()
{
    Logging::get()->info("ScanGroupView::arrowUpButtonClicked");
    
    if (m_display[0])//到最顶端时不往上翻 m_displaya保存当前哪些行的数据是显示状态
    {
        return;
    }
    
    for (int n = 1; n < SCAN_GROUP_MAX_DISPLAY_DATA - 3; n++)
    {
        if (m_display[n])
        {
            m_display[n + 3] = false;
            ui->tx_5->setText(m_list[n + 2].strTx);
            ui->rx_5->setText(m_list[n + 2].strRx);
            ui->tx_4->setText(m_list[n + 1].strTx);
            ui->rx_4->setText(m_list[n + 1].strRx);
            ui->tx_3->setText(m_list[n].strTx);
            ui->rx_3->setText(m_list[n].strRx);
            ui->tx_2->setText(m_list[n - 1].strTx);
            ui->rx_2->setText(m_list[n - 1].strRx);
            m_display[n - 1] = true;
            break;
        }
    }
}
/****************************************************************************
**
** 函数名称：ScanGroupView::eventFilter
** 功能概述: 事件监听函数，响应用户键盘操作
** 参数说明 watched：发送方， event：事件数据
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool ScanGroupView::eventFilter(QObject* watched, QEvent* event)
{
    Logging::get()->info("ScanGroupView::eventFilter");
    QStringList nameList;
    nameList << "tableView" << "arrowUpButton_2" << "arrowDownButton_2" << "newBnt" << "editBnt" << "deleteBnt"
             << "startBnt" << "stopBnt" << "homeBtn";
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
    {
        if (QEvent::KeyPress == event->type())
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type())
        {
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
                if (nameList.at(i) == "tableView" && a == Qt::Key_Down)
                {
                    inTableView = true;
                    break;
                }
                
                if (nameList.at(i) == "homeBtn")
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
            
            if (nameList.at(next) == "homeBtn")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetnext);
                button->setIcon(QIcon(":/images/home_hover"));
            }
            
            if (nameList.at(next) == "tableView")
            {
                ui->tableView->selectRow(0);
            }
        }
        
        break;
    }
    
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
                
                if (nameList.at(i) == "homeBtn")
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
             // 按钮图片切换 focus 获得 按钮图片亮
        QWidget* widgetprev = findChild<QWidget*>(nameList.at(prev));
        widgetprev->setFocus();
        
        if (widgetprev)
        {
            widgetprev->setFocus();
            
            if (nameList.at(prev) == "homeBtn")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetprev);
                button->setIcon(QIcon(":/images/home_hover"));
            }
            
            if (nameList.at(prev) == "tableView")
            {
                ui->tableView->selectRow(0);
            }
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
        
        for (int i = 0; i < nameList.length(); i++)
        {
            QWidget* widget = findChild<QWidget*>(nameList.at(i));
            
            if (widget && widget->hasFocus())
            {
                if (nameList.at(i) == "homeBtn")
                {
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                }
                
                break;
            }
        }
        
        break;
    }
    //触发按键事件
    case Qt::Key_Escape:
    {
        if (QEvent::KeyPress == event->type())
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type())
        {
            return true;
        }
        
        QWidget* widget = findChild<QWidget*>("homeBtn");
        
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
** 函数名称：ScanGroupView::currentChangedSlot
** 功能概述: 变更主记录时，刷新右侧频率记录
** 参数说明: current:模式队列
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ScanGroupView:: currentChangedSlot(const QModelIndex& current, const QModelIndex& previous)
{
    Logging::get()->info("ScanGroupView::currentChangedSlot");
    int curRow = ui->tableView->currentIndex().row();
    QModelIndex index = ui->tableView->currentIndex();
    QString fkey =   index.sibling(curRow, 0).data().toString();
    Database* database = new Database();
    database->openConnection();
    QSqlQuery queryFrequency = database->getQuery();
    QString Frequency = "select Tx,Rx,scanFlag  from Frequency  where FKey= ";
    Frequency.append("'");
    Frequency.append(fkey);
    Frequency.append("' and scanFlag = 'S';");
    queryFrequency.prepare(Frequency);
    queryFrequency.exec();
    m_recordCount = 0;
    
    for (int i = 0; i < 20; i++)
    {
        m_display[i] = false;
        m_list[i].strTx.clear();
        m_list[i].strRx.clear();
        m_list[i].scanFlag.clear();
    }
    
    while (queryFrequency.next())
    {
        m_list[m_recordCount].strTx = queryFrequency.value(0).toString();
        m_list[m_recordCount].strRx = queryFrequency.value(1).toString();
        m_list[m_recordCount].scanFlag = queryFrequency.value(2).toString();
        m_recordCount++;
        
        if (m_recordCount == SCAN_GROUP_MAX_DISPLAY_DATA)
            break;
    }
    
    for (int i = 4; i < 20; i++)
    {
        m_display[i] = false;
    }
    
    m_display[0] = true;
    m_display[1] = true;
    m_display[2] = true;
    m_display[3] = true;
    ui->tx_2->setText(m_list[0].strTx);
    ui->rx_2->setText(m_list[0].strRx);
    ui->tx_3->setText(m_list[1].strTx);
    ui->rx_3->setText(m_list[1].strRx);
    ui->tx_4->setText(m_list[2].strTx);
    ui->rx_4->setText(m_list[2].strRx);
    ui->tx_5->setText(m_list[3].strTx);
    ui->rx_5->setText(m_list[3].strRx);
}
/****************************************************************************
**
** 函数名称：ScanGroupView::frontPageSlot
** 功能概述: 打开页面时更新页面数据
** 参数说明： thisID：起始页面， fowordID：目标页面， paraMap：传递参数
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void  ScanGroupView::frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap)
{
    if (fowordID != SCAN_GROUP_VIEW) {return;}
    
    Logging::get()->info("ScanGroupView::frontPageSlot");
    m_model->select();
    ui->homeBtn->setIcon(QIcon(":/images/home_normal"));
    ui->tableView->setFocus();
    ui->tableView->selectRow(0);
    
    if (paraMap[SCAN_GROUP_MODLE_NAME] != SCAN_GROUP_MODLE_OK) {return;}
    
    QModelIndex current;
    QModelIndex previous;
    currentChangedSlot(current,  previous);
}

ScanGroupView::~ScanGroupView()
{
    Logging::get()->info("ScanGroupView::~ScanGroupView");
    delete ui;
}

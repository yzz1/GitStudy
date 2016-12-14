#include "messageslistview.h"
#include "ui_messageslistview.h"
#include <QSqlRecord>
#include "models/messagesitemdelegate.h"
#include <QVariant>
#include "core/utils/sqlitehelper.h"
#include "core/database/database.h"
#include "views/common/constants.h"
#include "messagesstyle.h"
#include "widgets/messagebox.h"
#include <QFileDialog>
#include <QEvent>
#include <QKeyEvent>
#include "widgets/button.h"
#include "logging.h"
/****************************************************************************
**
** 函数名称：MessagesListView::MessagesListView
** 功能概述: 初始化
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
MessagesListView::MessagesListView(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::MessagesListView)
{
    Logging::get()->info("MessagesListView::MessagesListView");
    ui->setupUi(this);
    this->installEventFilter(this);
    this->setWindowIcon(QIcon(":/images/null.png"));
    m_selectAllFlag = false;
    m_bOutBoxFlag = false;
    m_currow = 0;
    ui->contactsTiltewidget->setText(Constants::MESSAEGS_LIST_TITLE_INBOX);
    m_model = new ContactsModel(this, SQLiteHelper::openConnection());
    m_model->setTable(Constants::MESSAEGS_LIST_TABLE_NAME);
    m_strInboxFiter = Constants::MESSAEGS_LIST_COL_INOUT;
    m_strInboxFiter.append(" = '");
    m_strInboxFiter.append(Constants::MESSAEGS_LIST_INOUT_I);
    m_strInboxFiter.append("'");
    m_strOutboxFiter = Constants:: MESSAEGS_LIST_COL_INOUT;
    m_strOutboxFiter.append(" = '");
    m_strOutboxFiter.append(Constants::MESSAEGS_LIST_INOUT_O);
    m_strOutboxFiter.append("'");
    m_model->setFilter(m_strInboxFiter);
    m_model->setSort(Constants::MESSAEGS_INDEX_TIMEEND, Qt::DescendingOrder);
    m_model->select();
    int cout =     m_model->rowCount();
    ui->tableView->setModel(m_model);
    MessagesStyle* style = new MessagesStyle();
    MessagesItemDelegate* messagesItemDelegate = new MessagesItemDelegate(0, style);
    ui->tableView->setItemDelegate(messagesItemDelegate);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setColumnHidden(Constants::MESSAEGS_INDEX_UUID, true);
    ui->tableView->setColumnHidden(Constants::MESSAEGS_INDEX_INOUT, true);
    ui->tableView->setColumnHidden(Constants::MESSAEGS_INDEX_CALLCODE, true);
    ui->tableView->setColumnHidden(Constants::MESSAEGS_INDEX_MODE, true);
    ui->tableView->setColumnHidden(Constants::MESSAEGS_INDEX_SIGN, true);
    ui->tableView->setColumnHidden(Constants::MESSAEGS_INDEX_COUNTRY, true);
    ui->tableView->setColumnHidden(Constants::MESSAEGS_INDEX_TX, true);
    ui->tableView->setColumnHidden(Constants::MESSAEGS_INDEX_RX, true);
    ui->tableView->setColumnHidden(Constants::MESSAEGS_INDEX_CHANNEL, true);
    ui->tableView->setColumnHidden(Constants::MESSAEGS_INDEX_TIMESTART, true);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->verticalHeader()->hide();
    QHeaderView* header = ui->tableView->horizontalHeader();
    header->resizeSection(Constants::MESSAEGS_INDEX_CHECKFLAG, 50);
    header->resizeSection(Constants::MESSAEGS_INDEX_SHOWPIX, 50);
    header->resizeSection(Constants::MESSAEGS_INDEX_NAME, 400);
    header->resizeSection(Constants::MESSAEGS_INDEX_TIMEEND, 300);
    header->setStretchLastSection(true);
    ui->tableView->setFocus();
    ui->tableView->selectRow(m_currow);

    nameList << "tableView" << "selectallBnt" << "selectBnt" << "openBnt"
             << "deleteBnt" << "exportBnt" << "homeTBnt" << "inBoxTBnt";
    connect(ui->homeTBnt, SIGNAL(clicked()), this, SLOT(homeClickedSlot()));
    connect(ui->selectBnt, SIGNAL(clicked()), this, SLOT(selectClickedSlot()));
    connect(ui->selectallBnt, SIGNAL(clicked()), this, SLOT(selectAllClickedSlot()));
    connect(ui->deleteBnt, SIGNAL(clicked()), this, SLOT(deleteSelectedRow()));
    connect(ui->inBoxTBnt, SIGNAL(clicked()), this, SLOT(inBoxClickedSlot()));
    connect(ui->outBoxTBnt, SIGNAL(clicked()), this, SLOT(outBoxClickedSlot()));
    connect(ui->openBnt, SIGNAL(clicked()), this, SLOT(openClickedSlot()));
    connect(ui->exportBnt, SIGNAL(clicked()), this, SLOT(exportClickedSlot()));
}
/****************************************************************************
**
** 函数名称：MessagesListView::~MessagesListView
** 功能概述: 析构函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
MessagesListView::~MessagesListView()
{
    Logging::get()->info("MessagesListView::~MessagesListView");
    delete ui;
}
/****************************************************************************
**
** 函数名称：MessagesListView::eventFilter
** 功能概述: 事件监听函数，响应用户键盘操作
** 参数说明 watched：发送方， event：事件数据
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool MessagesListView::eventFilter(QObject* watched, QEvent* event)
{
    Logging::get()->info("MessagesListView::eventFilter");
    QKeyEvent* key_event = static_cast<QKeyEvent*>(event);
    int a =   key_event->key();
    
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
                // 光标在tableview内时上下移动不改变光标
                if (nameList.at(i) == "tableView")
                {
                    if (a == Qt::Key_Down)
                    {
                        inTableView = true;
                        break;
                    }
                }
                
                // home按钮获得焦点，图片高亮显示
                if (nameList.at(i) == "homeTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/home_normal"));
                }
                
                // inBox按钮获得焦点，图片高亮显示
                if (nameList.at(i) == "inBoxTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/images/message_inBox_SelNo.png"));
                }
                
                // outBox按钮获得焦点，图片高亮显示
                if (nameList.at(i) == "outBoxTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/images/message_outBox_SelNo.png"));
                }
                
                // 计算得出下一个控件的下标
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
            
            // home按钮获得焦点，图片高亮显示
            if (nameList.at(next) == "homeTBnt")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetnext);
                button->setIcon(QIcon(":/images/home_hover"));
            }
            
            // inBox按钮获得焦点，图片高亮显示
            if (nameList.at(next) == "inBoxTBnt")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetnext);
                button->setIcon(QIcon(":/images/images/message_inBox_SelYes.png"));
            }
            
            // outBox按钮获得焦点，图片高亮显示
            if (nameList.at(next) == "outBoxTBnt")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetnext);
                button->setIcon(QIcon(":/images/images/message_outBox_SelYes.png"));
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
                // 光标在tableview内时上下移动不改变光标
                if (nameList.at(i) == "tableView" && a == Qt::Key_Up)
                {
                    inTableView = true;
                    break;
                }
                
                // name按钮获得焦点，图片高亮显示
                if (nameList.at(i) == "homeTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/home_normal"));
                }
                
                // inBox按钮获得焦点，图片高亮显示
                if (nameList.at(i) == "inBoxTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/images/message_inBox_SelNo.png"));
                }
                
                // outBox按钮获得焦点，图片高亮显示
                if (nameList.at(i) == "outBoxTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/images/message_outBox_SelNo.png"));
                }
                
                // 计算获得上一个控件的下标
                prev = (i == 0) ? nameList.length() - 1 : i - 1;
                break;
            }
        }
        
        if (inTableView)
            break;
            
        QWidget* widgetprev = findChild<QWidget*>(nameList.at(prev));
        if (widgetprev)
        {
            widgetprev->setFocus();
            
            // home按钮获得焦点，图片高亮显示
            if (nameList.at(prev) == "homeTBnt")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetprev);
                button->setIcon(QIcon(":/images/home_hover"));
            }
            
            // inBox按钮获得焦点，图片高亮显示
            if (nameList.at(prev) == "inBoxTBnt")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetprev);
                button->setIcon(QIcon(":/images//images/message_inBox_SelYes.png"));
            }
            
            // outBox按钮获得焦点，图片高亮显示
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
            
            if (widget && widget->hasFocus())
            {
                // 模拟home按钮点击事件
                if (nameList.at(i) == "homeTBnt")
                {
                    QWidget* widget = findChild<QWidget*>("homeTBnt");
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                }
                // 模拟inBox按钮点击事件
                else if (nameList.at(i) == "inBoxTBnt")
                {
                    QWidget* widget = findChild<QWidget*>("inBoxTBnt");
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                }
                // 模拟outBox按钮点击事件
                else if (nameList.at(i) == "outBoxTBnt")
                {
                    QWidget* widget = findChild<QWidget*>("outBoxTBnt");
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                }
                else if (nameList.at(i) == "tableView")
                {
                    openClickedSlot();
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
        
        // 模拟home按钮点击事件
        QWidget* widget = findChild<QWidget*>("homeTBnt");
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
** 函数名称：MessagesListView::homeClickedSlot
** 功能概述: 返回主菜单
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessagesListView:: homeClickedSlot()
{
    Logging::get()->info("MessagesListView::homeClickedSlot");
    int curRow = ui->tableView->currentIndex().row();
    m_currow = curRow;
    QMap <QString, QString>paraMap;
    emit afterPageSignal(Constants::MESSAEGS_LIST_VIEW_NAME, HOME_VIEW_NAME, paraMap);
}
/****************************************************************************
**
** 函数名称：MessagesListView::exportClickedSlot
** 功能概述: 导出处理
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessagesListView:: exportClickedSlot()
{
    Logging::get()->info("MessagesListView::exportClickedSlot");
    QFileDialog w;
    w.setDirectory(QString("/"));
    w.setFilter(QString("xml Files(*.xml)"));
    w.setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
    w.setAcceptMode(QFileDialog::AcceptSave); //AcceptOpen打开,AcceptSave保存
    w.setOption(QFileDialog::ReadOnly, true); 
    QString style = "background-color:rgb(65, 85, 100);";
    w.setStyleSheet(style);
    QStringList fileName;
    
    if (w.exec() == QFileDialog::Accepted) // ok
    {
        fileName = w.selectedFiles();
        QString file = fileName.at(0);
        
        if (!file.isEmpty())
        {
            QString txt = file.mid(file.length() - 4, 4);
            
            if (txt != ".txt" && txt != ".txt")
                file.append(".txt");
                
            QString inOutFlag;
            
            if (m_bOutBoxFlag == false)
                inOutFlag = "I";
            else
                inOutFlag = "O";
                
            bool ret = SQLiteHelper::exportData(Constants::MESSAEGS_LIST_TABLE_NAME, file,  inOutFlag);
            
            if (ret)
            {
                MessageBox  msg;
                msg.move((SCREEN_SIZE_WIDTH - msg.width()) / 2, (SCREEN_SIZE_HEIGHT - msg.height()) / 2);
                msg.SetMessage(tr("system"), tr("Export done"), 0);
                msg.exec() ;
            }
            else
            {
                MessageBox  msg;
                msg.move((SCREEN_SIZE_WIDTH - msg.width()) / 2, (SCREEN_SIZE_HEIGHT - msg.height()) / 2);
                msg.SetMessage(tr("system"), tr("Export failed"), 0);
                msg.exec() ;
            }
            
            return;
        }
    }
}
/****************************************************************************
**
** 函数名称：MessagesListView::selectClickedSlot
** 功能概述: 选中处理
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessagesListView:: selectClickedSlot()
{
    Logging::get()->info("MessagesListView::selectClickedSlot");
    int curRow = ui->tableView->currentIndex().row();
    QModelIndex index = ui->tableView->currentIndex();
    QString strUUID = index.sibling(curRow, 0).data().toString();
    QString strFiter = " UUID = ";
    strFiter.append("'");
    strFiter.append(strUUID);
    strFiter.append("'");
    m_model->setFilter(strFiter);
    
    if (m_model->select())
    {
        if (m_model->rowCount() == 1)
        {
            QSqlRecord record = m_model->record(0);
            int intCheckFlag;
            
            if ((record.value(Constants::MESSAEGS_LIST_COL_CHECKFLAG).toInt()) == 0)
            {
                intCheckFlag  = 1;
            }
            else
            {
                intCheckFlag  = 0;
            }
            
            record.setValue(Constants::MESSAEGS_LIST_COL_CHECKFLAG, intCheckFlag);
            m_model->setRecord(0, record);
            m_model->submitAll();
            
            if (m_bOutBoxFlag == true)
            {
                m_model->setFilter(m_strOutboxFiter);
            }
            else
            {
                m_model->setFilter(m_strInboxFiter);
            }
        }
    }
    
    ui->tableView->selectRow(curRow);
}
/****************************************************************************
**
** 函数名称：MessagesListView::selectAllClickedSlot
** 功能概述: 全选中处理
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessagesListView:: selectAllClickedSlot()
{
    Logging::get()->info("MessagesListView::selectAllClickedSlot");
    int curRow = ui->tableView->currentIndex().row();
    
    if (m_model->select())
    {
        int intRowCount = m_model->rowCount() ;
        int intCheckFlag;
        
        if (m_selectAllFlag == false)
        {
            intCheckFlag = 1;
            m_selectAllFlag = true;
        }
        else
        {
            intCheckFlag = 0;
            m_selectAllFlag = false;
        }
        
        for (int i = 0; i < intRowCount; i++)
        {
            QSqlRecord record = m_model->record(i);
            record.setValue(Constants::MESSAEGS_LIST_COL_CHECKFLAG, intCheckFlag);
            m_model->setRecord(i, record);
        }
        
        m_model->submitAll();
    }
    
    ui->tableView->selectRow(curRow);
}
/****************************************************************************
**
** 函数名称：MessagesListView::deleteSelectedRow
** 功能概述: 删除记录处理
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessagesListView:: deleteSelectedRow()
{
    Logging::get()->info("MessagesListView::deleteSelectedRow");
    MessageBox  msg;
    msg.move((SCREEN_SIZE_WIDTH - msg.width()) / 2, (SCREEN_SIZE_HEIGHT - msg.height()) / 2);
    
    if (m_model->rowCount() == 0)
    {
        msg.SetMessage(tr("Delete"), tr("No row is selected"), 0);
        msg.exec() ;
        return ;
    }
    
    int curRow = ui->tableView->currentIndex().row();
    QModelIndex index = ui->tableView->currentIndex();
    QString strUUID = index.sibling(curRow, Constants::MESSAEGS_INDEX_UUID).data().toString();
    msg.SetMessage(tr("Delete"), tr("Are you sure to delete this item ?"), 1);
    
    if (msg.exec() != 1) {return ;}
    
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
    QString strMessageDetailSql = "DELETE FROM  MessageDetail where  FKey =:FKey";
    QVariantMap mapMessageDetail;
    bool bResultExe = false;
    mapMessageDetail.insert(Constants::MESSAEGS_SHOW_COL_FKEY, strUUID);
    bResultExe = database->executeSql(strMessageDetailSql, mapMessageDetail);
    
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
** 函数名称：MessagesListView::outBoxClickedSlot
** 功能概述: 跳转到outbox界面
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessagesListView::outBoxClickedSlot()
{
    Logging::get()->info("MessagesListView::outBoxClickedSlot");
    m_bOutBoxFlag = true;
    ui->contactsTiltewidget->setText(Constants::MESSAEGS_LIST_TITLE_OUTBOX);
    m_model->setFilter(m_strOutboxFiter);
    m_model->setSort(Constants::MESSAEGS_INDEX_TIMEEND, Qt::DescendingOrder);
    m_model->select();
    ui->homeTBnt->setIcon(QIcon(":/images/home_normal"));
    ui->tableView->setFocus();
    ui->tableView->selectRow(0);
    QIcon outboxIcon;
    outboxIcon.addPixmap(QPixmap(":/images/images/message_outBox_SelYes.png"), QIcon::Disabled);
    ui->outBoxTBnt->setIcon(outboxIcon);
    ui->inBoxTBnt->setIcon(QIcon(":/images/images/message_inBox_SelNo.png"));
    ui->outBoxTBnt->setEnabled(false);
    ui->outBoxTBnt->setText(tr("OutBox"));
    ui->inBoxTBnt->setEnabled(true);
    ui->inBoxTBnt->setText(tr("&InBox"));
    nameList.removeLast();
    nameList.append("inBoxTBnt");
}
/****************************************************************************
**
** 函数名称：MessagesListView::inBoxClickedSlot
** 功能概述: 跳转到inbox界面
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessagesListView::inBoxClickedSlot()
{
    Logging::get()->info("MessagesListView::inBoxClickedSlot");
    m_bOutBoxFlag = false;
    ui->contactsTiltewidget->setText(Constants::MESSAEGS_LIST_TITLE_INBOX);
    m_model->setFilter(m_strInboxFiter);
    m_model->setSort(Constants::MESSAEGS_INDEX_TIMEEND, Qt::DescendingOrder);
    m_model->select();
    ui->homeTBnt->setIcon(QIcon(":/images/home_normal"));
    ui->tableView->setFocus();
    ui->tableView->selectRow(0);
    QIcon inboxIcon;
    inboxIcon.addPixmap(QPixmap(":/images/images/message_inBox_SelYes.png"), QIcon::Disabled);
    ui->inBoxTBnt->setIcon(inboxIcon);
    ui->outBoxTBnt->setIcon(QIcon(":/images/images/message_outBox_SelNo.png"));
    ui->outBoxTBnt->setEnabled(true);
    ui->outBoxTBnt->setText(tr("&OutBox"));
    ui->inBoxTBnt->setEnabled(false);
    ui->inBoxTBnt->setText(tr("InBox"));
    nameList.removeLast();
    nameList.append("outBoxTBnt");
}
/****************************************************************************
**
** 函数名称：MessagesListView::openClickedSlot
** 功能概述: 打开消息
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessagesListView::openClickedSlot()
{
    Logging::get()->info("MessagesListView::openClickedSlot");
    MessageBox  msg;
    msg.move((SCREEN_SIZE_WIDTH - msg.width()) / 2, (SCREEN_SIZE_HEIGHT - msg.height()) / 2);
    
    if (m_model->rowCount() == 0)
    {
        msg.SetMessage(tr("Open"), tr("No row is selected"), 0);
        msg.exec() ;
        return ;
    }
    
    int curRow = ui->tableView->currentIndex().row();
    m_currow = curRow;
    QModelIndex index = ui->tableView->currentIndex();

    QMap <QString, QString>paraMap;
    QString strUUID = index.sibling(curRow, Constants::MESSAEGS_INDEX_UUID).data().toString();
    QString strCallMode = index.sibling(curRow, Constants::MESSAEGS_INDEX_MODE).data().toString();
    QString strName = index.sibling(curRow, Constants::MESSAEGS_INDEX_NAME).data().toString();
    QString strTx = index.sibling(curRow, Constants::MESSAEGS_INDEX_TX).data().toString();
    QString strRx = index.sibling(curRow, Constants::MESSAEGS_INDEX_RX).data().toString();
    
    if (m_bOutBoxFlag == true)
    {
        paraMap.insert(COMMON_MODLE_NAME, Constants:: MESSAEGS_LIST_INOUT_O);
    }
    else
    {
        paraMap.insert(COMMON_MODLE_NAME, Constants:: MESSAEGS_LIST_INOUT_I);
    }
    
    paraMap.insert(Constants::MESSAEGS_LIST_COL_UUID, strUUID);
    paraMap.insert(Constants::MESSAEGS_LIST_COL_MODE, strCallMode);
    paraMap.insert(Constants::MESSAEGS_LIST_COL_NAME, strName);
    paraMap.insert(Constants::MESSAEGS_LIST_COL_TX, strTx);
    paraMap.insert(Constants::MESSAEGS_LIST_COL_RX, strRx);
    emit afterPageSignal(Constants::MESSAEGS_LIST_VIEW_NAME, Constants::MESSAEGS_SHOW_VIEW_NAME, paraMap);
    QString strFiter = " UUID = ";
    strFiter.append("'");
    strFiter.append(strUUID);
    strFiter.append("'");
    m_model->setFilter(strFiter);
    
    if (m_model->select())
    {
        if (m_model->rowCount() == 1)
        {
            QSqlRecord record = m_model->record(0);
            
            if (record.value(Constants::MESSAEGS_LIST_COL_SHOWPIX).toString() != Constants::MESSAEGS_LIST_MESSAGE_READED_FLAG)
            {
                record.setValue(Constants::MESSAEGS_LIST_COL_SHOWPIX, Constants::MESSAEGS_LIST_MESSAGE_READED_FLAG);
                m_model->setRecord(0, record);
                m_model->submitAll();
            }
        }
    }
    
    m_model->setFilter(m_strInboxFiter);
    m_model->select();
    bool hasUnreadMsg = false;
    
    for (int i = 0 ; i < m_model->rowCount() ; i++)
    {
        QSqlRecord record = m_model->record(i);
        
        if (record.value(Constants::MESSAEGS_LIST_COL_SHOWPIX).toString() == Constants::MESSAEGS_LIST_MESSAGE_UNREAD_FLAG)
        {
            hasUnreadMsg = true;
            break;
        }
    }
    
    if (!hasUnreadMsg)
    {
        emit  hasUnreadMessage(false);
    }
}
/****************************************************************************
**
** 函数名称：MessagesListView::frontPageSlot
** 功能概述: 打开页面时更新页面数据
** 参数说明： thisID：起始页面， fowordID：目标页面， paraMap：传递参数
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void  MessagesListView::frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap)
{
    if (fowordID != Constants::MESSAEGS_LIST_VIEW_NAME) {return;}
    
    Logging::get()->info("MessagesListView::frontPageSlot");
    QString strModle = paraMap[COMMON_MODLE_NAME];
    
    if ((strModle == Constants:: MESSAEGS_LIST_INOUT_I) || (thisID == HOME_VIEW_NAME))
    {
        inBoxClickedSlot();
    }
    else
    {
        outBoxClickedSlot();
    }
    
}

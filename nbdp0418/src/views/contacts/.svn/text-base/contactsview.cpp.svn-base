#include "contactsview.h"
#include "ui_contactsview.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include "models/contactsitemdelegate.h"
#include <QVariant>
#include "core/database/connectionpool.h"
#include "core/database/database.h"
#include "core/utils/sqlitehelper.h"
#include "views/common/constants.h"
#include <QFileDialog>
#include "widgets/messagebox.h"
#include <QEvent>
#include <QKeyEvent>
#include <QPrintDialog>
#include <QPrinter>
#include "widgets/button.h"
#include <QDebug>  //qi
#include "logging.h"
/****************************************************************************
**
** 函数名称：ContactsView::ContactsView
** 功能概述: 初始化
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ContactsView::ContactsView(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::ContactsView)
{
    Logging::get()->info("ContactsView::ContactsView");
    ui->setupUi(this);
    ui->contactsTiltewidget->setText(tr("CONTACTS  STATION"));
    this->installEventFilter(this);
    this->setWindowIcon(QIcon(":/images/null.png"));
    m_model = new ContactsModel(this, SQLiteHelper::openConnection());
    m_model->setTable(tr("station"));
    m_model->setSort(1, Qt::AscendingOrder);
    m_model->select();
    ui->tableView->setModel(m_model);
    ContactsStyle* contactsStyle = new ContactsStyle();
    ContactsItemDelegate* contactsItemDelegate = new ContactsItemDelegate(0, contactsStyle);
    ui->tableView->setItemDelegate(contactsItemDelegate);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(4, true);
    ui->tableView->setColumnHidden(5, true);
    ui->tableView->setColumnHidden(6, true);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->verticalHeader()->hide();
    QHeaderView* header = ui->tableView->horizontalHeader();
    header->resizeSection(1,310);
    header->resizeSection(2,215);
    header->resizeSection(3,275);
    header->setStretchLastSection(true);
    ui->tableView->resizeRowsToContents();
    ui->tableView->selectRow(0);
    ui->tableView->setFocus();
    ui->exportBnt->setHidden(true);
    ui->importBnt->setHidden(true);
    ui->printBnt->setHidden(true);
    connect(ui->optionBnt, SIGNAL(clicked()), this, SLOT(showOptionMenu()));
    connect(ui->exportBnt, SIGNAL(clicked()), this, SLOT(exportClickedSlot()));
    connect(ui->importBnt, SIGNAL(clicked()), this, SLOT(importClickedSlot()));
    connect(ui->deleteBnt, SIGNAL(clicked()), this, SLOT(deleteSelectedRow()));
    connect(ui->editBnt, SIGNAL(clicked()), this, SLOT(editClickedSolt()));
    connect(ui->newBnt, SIGNAL(clicked()), this, SLOT(newClickedSolt()));
    connect(ui->contactsCancelBnt, SIGNAL(clicked()), this, SLOT(cancelClickedSolt()));
    connect(ui->homeTBnt, SIGNAL(clicked()), this, SLOT(homeClickedSlot()));
    connect(ui->individualTBnt, SIGNAL(clicked()), this, SLOT(individualClickedSlot()));
    connect(ui->printBnt, SIGNAL(clicked()), this, SLOT(printClickedSlot()));
    m_optionMenuStatus  = true;
}
/****************************************************************************
**
** 函数名称：ContactsView::~ContactsView
** 功能概述: 析构函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ContactsView::~ContactsView()
{
    Logging::get()->info("ContactsView::~ContactsView");
    delete ui;
}
/****************************************************************************
**
** 函数名称：ContactsView::showOptionMenu
** 功能概述: 打开option子菜单
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ContactsView::showOptionMenu()
{
    Logging::get()->info("ContactsView::showOptionMenu");
    
    if (m_optionMenuStatus  == true)
    {
        if (ui->tableView->hasFocus())
        {
            ui->optionBnt->setFocus();
        }
        
        ui->exportBnt->setHidden(false);
        ui->importBnt->setHidden(false);
        ui->printBnt->setHidden(false);
        ui->importBnt->setChecked(true);
        m_optionMenuStatus  = false;
        ui->exportBnt->setFocus();
    }
    else
    {
        ui->exportBnt->setHidden(true);
        ui->importBnt->setHidden(true);
        ui->printBnt->setHidden(true);
        ui->optionBnt->setFocus();
        m_optionMenuStatus  = true;
    }
}
/****************************************************************************
**
** 函数名称：ContactsView::exportClickedSlot
** 功能概述: 导出站台联系表
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ContactsView:: exportClickedSlot()
{
    Logging::get()->info("ContactsView::exportClickedSlot");
    ui->optionBnt->click();
    QFileDialog w;
    w.setDirectory(QString("/"));
    w.setFilter(QString("xml Files(*.xml)"));
    w.setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
    w.setAcceptMode(QFileDialog::AcceptSave); //AcceptOpen打开,AcceptSave保存
    w.setOption(QFileDialog::ReadOnly, true);
    QString style = "background-color:rgb(65, 85, 100);";
    w.setStyleSheet(style);
    w.setViewMode(QFileDialog::List);
    QStringList fileName;
    
    if (w.exec() == QFileDialog::Accepted) // ok
    {
        fileName = w.selectedFiles();
        QString file = fileName.at(0);
        
        if (!file.isEmpty())
        {
            QString xml = file.mid(file.length() - 4, 4);
            
            if (xml != ".xml" && xml != ".XML")
                file.append(".xml");
                
            bool ret = SQLiteHelper::exportData("station", file);
            
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
            
            ui->tableView->setFocus();
        }
    }
}
/****************************************************************************
**
** 函数名称：ContactsView::importClickedSlot
** 功能概述: 导入站台联系表
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ContactsView:: importClickedSlot()
{
    Logging::get()->info("ContactsView::importClickedSlot");
    ui->optionBnt->click();
    QFileDialog w;
    w.setDirectory(QString("/"));
    w.setFilter(QString("xml Files(*.xml)"));
    w.setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
    w.setAcceptMode(QFileDialog::AcceptOpen); //AcceptOpen打开,AcceptSave保存
    w.setOption(QFileDialog::ReadOnly, true);
    QString style = "background-color:rgb(65, 85, 100);";
    w.setStyleSheet(style);
    w.setViewMode(QFileDialog::List);
    QStringList fileName;
    
    if (w.exec() == QFileDialog::Accepted) // ok
    {
        fileName = w.selectedFiles();
        QString file = fileName.at(0);
        
        if (!file.isEmpty())
        {
            bool ret = SQLiteHelper::importData(file, m_model);
            
            if (ret)
            {
                MessageBox  msg;
                msg.move((SCREEN_SIZE_WIDTH - msg.width()) / 2, (SCREEN_SIZE_HEIGHT - msg.height()) / 2);
                msg.SetMessage(tr("system"), tr("Import done"), 0);
                msg.exec() ;
            }
            else
            {
                MessageBox  msg;
                msg.move((SCREEN_SIZE_WIDTH - msg.width()) / 2, (SCREEN_SIZE_HEIGHT - msg.height()) / 2);
                msg.SetMessage(tr("system"), tr("Import failed"), 0);
                msg.exec() ;
            }
            
            m_model->select();
            ui->tableView->selectRow(0);
            ui->tableView->setFocus();
        }
    }
}
/****************************************************************************
**
** 函数名称：ContactsView::deleteSelectedRow
** 功能概述: 删除记录
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ContactsView:: deleteSelectedRow()
{
    Logging::get()->info("ContactsView::deleteSelectedRow");
    MessageBox  msg;
    msg.move((SCREEN_SIZE_WIDTH - msg.width()) / 2, (SCREEN_SIZE_HEIGHT - msg.height()) / 2);
    
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
** 函数名称：ContactsView::editClickedSolt
** 功能概述: 打开编辑界面
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ContactsView:: editClickedSolt()
{
    Logging::get()->info("ContactsView::editClickedSolt");
    QMap <QString, QString>paraMap;
    int curRow = ui->tableView->currentIndex().row();
    QModelIndex index = ui->tableView->currentIndex();
    QString strModle  =  QString(CONTACTS_STATION_MODLE_EDIT);
    QString strUUID = index.sibling(curRow, 0).data().toString();
    QString strName = index.sibling(curRow, 1).data().toString();
    QString strCallsign = index.sibling(curRow, 2).data().toString();
    QString strCountry = index.sibling(curRow, 3).data().toString();
    paraMap.insert(CONTACTS_STATION_MODLE_NAME, strModle);
    paraMap.insert(CONTACTS_STATION_UUID, strUUID);
    paraMap.insert(CONTACTS_STATION_NAME, strName);
    paraMap.insert(CONTACTS_STATION_CALLSIGN, strCallsign);
    paraMap.insert(CONTACTS_STATION_COUNTRY, strCountry);
    emit afterPageSignal(CONTACTS_STATION_VIEW_NAME, CONTACTS_STATION_EDIT_NAME, paraMap);
}
/****************************************************************************
**
** 函数名称：ContactsView::newClickedSolt
** 功能概述: 打开新建记录界面
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ContactsView:: newClickedSolt()
{
    Logging::get()->info("ContactsView::newClickedSolt");
    QMap <QString, QString>paraMap;
    int curRow = ui->tableView->currentIndex().row();
    QModelIndex index = ui->tableView->currentIndex();
    QString strModle  =  QString(CONTACTS_STATION_MODLE_NEW);
    paraMap.insert(CONTACTS_STATION_MODLE_NAME, strModle);
    emit afterPageSignal(CONTACTS_STATION_VIEW_NAME, CONTACTS_STATION_EDIT_NAME, paraMap);
}
/****************************************************************************
**
** 函数名称：ContactsView::cancelClickedSolt
** 功能概述: 返回到主界面
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ContactsView:: cancelClickedSolt()
{
    Logging::get()->info("ContactsView::cancelClickedSolt");
    QMap <QString, QString>paraMap;
    int curRow = ui->tableView->currentIndex().row();
    QModelIndex index = ui->tableView->currentIndex();
    emit afterPageSignal(CONTACTS_STATION_VIEW_NAME, HOME_VIEW_NAME, paraMap);
}
/****************************************************************************
**
** 函数名称：ContactsView::homeClickedSlot
** 功能概述: 返回到主界面
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ContactsView:: homeClickedSlot()
{
    Logging::get()->info("ContactsView::homeClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(CONTACTS_STATION_VIEW_NAME, HOME_VIEW_NAME, paraMap);
}
/****************************************************************************
**
** 函数名称：ContactsView::printClickedSlot
** 功能概述: 打印站台联系表
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ContactsView:: printClickedSlot()
{
    Logging::get()->info("ContactsView::printClickedSlot");
    ui->optionBnt->click();
    QString printStr;
    SQLiteHelper::printData("station", printStr);
    ui->tableView->setFocus();
}
/****************************************************************************
**
** 函数名称：ContactsView::individualClickedSlot
** 功能概述: 打开个人联系表界面
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ContactsView:: individualClickedSlot()
{
    Logging::get()->info("ContactsView::individualClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(CONTACTS_STATION_VIEW_NAME, CONTACTS_INDIVIDUAL_VIEW, paraMap);
}
/****************************************************************************
**
** 函数名称：ContactsView::frontPageSlot
** 功能概述: 打开页面时更新页面数据
** 参数说明： thisID：起始页面， fowordID：目标页面， paraMap：传递参数
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ContactsView::frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap)
{
    if (fowordID != CONTACTS_STATION_VIEW_NAME) {return;}
    
    Logging::get()->info("ContactsView::frontPageSlot");
    m_model->select();
    m_optionMenuStatus = false;
    showOptionMenu();
    ui->individualTBnt->setIcon(QIcon(":/images/images/individual_gray.png"));
    ui->homeTBnt->setIcon(QIcon(":/images/home_normal"));
    ui->tableView->setFocus();
    ui->tableView->scrollToTop();
    ui->tableView->selectRow(0);
}
/****************************************************************************
**
** 函数名称：ContactsView::eventFilter
** 功能概述: 事件监听函数，响应用户键盘操作。
** 参数说明：watched：发送方， event：事件数据
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool ContactsView::eventFilter(QObject* watched, QEvent* event)
{
    Logging::get()->info("ContactsView::eventFilter");
    QStringList nameList;
    nameList << "tableView" << "newBnt" << "editBnt" << "deleteBnt"
             << "optionBnt" << "contactsCancelBnt" << "homeTBnt" << "individualTBnt";
    QKeyEvent* key_event = static_cast<QKeyEvent*>(event);
    int a =   key_event->key();
    
    switch (a)
    {
    case Qt::Key_T:
    {
        if (QEvent::KeyPress == event->type())// 按下时键屏蔽
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type())// 弹起时键屏蔽
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
        
        break;
    }
    
    case Qt::Key_Right:
    case Qt::Key_Down:
    case Qt::Key_Tab:
    {
        if (QEvent::KeyPress == event->type())// 按下时键屏蔽
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type())// 弹起时键屏蔽
        {
            return true;
        }
        // importBnt exportBnt 按钮获得光标
        if (!m_optionMenuStatus && (a == Qt::Key_Down || a == Qt::Key_Tab))
        {
            if (ui->exportBnt->hasFocus())
                ui->importBnt->setFocus();
            else if (ui->importBnt->hasFocus())
                ui->printBnt->setFocus();
            else if (ui->printBnt->hasFocus())
                ui->exportBnt->setFocus();
            else
                ui->exportBnt->setFocus();
                
            return true;
        }
        // optionBnt 按钮获得光标
        else if (!m_optionMenuStatus && (a == Qt::Key_Right))
        {
            QWidget* widget = findChild<QWidget*>("optionBnt");
            Button* button = static_cast<Button*>(widget);
            button->click();
            widget->setFocus();
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
                
                if (nameList.at(i) == "homeTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/home_normal"));
                }
                
                if (nameList.at(i) == "individualTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/images/individual_gray.png"));
                }
                
                if (nameList.at(i) == "stationTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/images/station_gray.png"));
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
            
            if (nameList.at(next) == "individualTBnt")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetnext);
                button->setIcon(QIcon(":/images/images/individual_white.png"));
            }
            
            if (nameList.at(next) == "stationTBnt")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetnext);
                button->setIcon(QIcon(":/images/images/station_white.png"));
            }
        }
        
        break;
    }
    
    case Qt::Key_Up:
    case Qt::Key_Backtab:
    case Qt::Key_Left:
    {
        if (QEvent::KeyPress == event->type())// 按下时键屏蔽
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type())// 弹起时键屏蔽
        {
            return true;
        }
        // 默认键值51 响应一次
        // importBnt exportBnt 按钮获得光标
        if (!m_optionMenuStatus && (a == Qt::Key_Up))
        {
            if (ui->exportBnt->hasFocus())
                ui->printBnt->setFocus();
            else if (ui->importBnt->hasFocus())
                ui->exportBnt->setFocus();
            else if (ui->printBnt->hasFocus())
                ui->importBnt->setFocus();
            else
                ui->exportBnt->setFocus();
                
            break;
        }
        // optionBnt 按钮获得光标
        else if (!m_optionMenuStatus && (a == Qt::Key_Left))
        {
            QWidget* widget = findChild<QWidget*>("optionBnt");
            Button* button = static_cast<Button*>(widget);
            button->click();
            widget->setFocus();
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
                
                if (nameList.at(i) == "individualTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/images/individual_gray.png"));
                }
                
                if (nameList.at(i) == "stationTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/images/station_gray.png"));
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
            
            if (nameList.at(prev) == "homeTBnt")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetprev);
                button->setIcon(QIcon(":/images/home_hover"));
            }
            
            if (nameList.at(prev) == "individualTBnt")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetprev);
                button->setIcon(QIcon(":/images/images/individual_white.png"));
            }
            
            if (nameList.at(prev) == "stationTBnt")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetprev);
                button->setIcon(QIcon(":/images/images/station_white.png"));
            }
        }
        
        break;
    }
    
    case Qt::Key_Return:
    case Qt::Key_Enter:
    {
        if (QEvent::KeyPress == event->type())// 按下时键屏蔽
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type())// 弹起时键屏蔽
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
                    QWidget* widget = findChild<QWidget*>("contactsCancelBnt");
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                }
                else if (nameList.at(i) == "individualTBnt")
                {
                    QWidget* widget = findChild<QWidget*>("individualTBnt");
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                }
                else if (nameList.at(i) == "stationTBnt")
                {
                    break;
                }
                else if (nameList.at(i) == "tableView")
                {
                    editClickedSolt();
                }
                break;
            }
        }
        
        break;
    }
    
    case Qt::Key_Escape:// 响应 ESC事件
    {
        if (QEvent::KeyPress == event->type())// 按下时键屏蔽
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type())// 弹起时键屏蔽
        {
            return true;
        }
        // 默认键值51 响应一次
        // optionBnt 按钮获得光标
        if (!m_optionMenuStatus)
        {
            QWidget* widget = findChild<QWidget*>("optionBnt");
            Button* button = static_cast<Button*>(widget);
            ui->optionBnt->setFocus();
            button->click();
        }
        else
        {
            QWidget* widget = findChild<QWidget*>("contactsCancelBnt");
            
            if (widget)
            {
                Button* button = static_cast<Button*>(widget);
                button->click();
            }
        }
        
        break;
    }
    }
    
    if (a == Qt::Key_Escape)
        return true;
        
    return QWidget::eventFilter(watched, event);
}

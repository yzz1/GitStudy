#include "managermacro.h"
#include "ui_managermacro.h"
#include "views/contacts/contactsindstyle.h"
#include "core/utils/sqlitehelper.h"
#include "core/database/database.h"
#include "views/common/constants.h"
#include "views/manager/managerstyle.h"
#include "widgets/messagebox.h"
#include <QKeyEvent>
#include <QSqlRecord>
#include <QLineEdit>
#include <QEvent>
#include "widgets/button.h"
#include <QFileDialog>
#include <widgets/inputdialog.h>
#include <QDateTime>
#include "QUuid"
#include "logging.h"
#include <QDebug>
/****************************************************************************
**
** 函数名称：ManagerMacro::ManagerMacro
** 功能概述: 初始化
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ManagerMacro::ManagerMacro(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::ManagerMacro)
{
    Logging::get()->info("ManagerMacro::ManagerMacro");
    ui->setupUi(this);
    ui->contactsTiltewidget->setText(Constants::MANAGER_MACRO_TITLE);
    this->installEventFilter(this);
    this->setWindowIcon(QIcon(":/images/null.png"));
    m_model = new ManagerModel(this, SQLiteHelper::openConnection());
    m_model->setTable(tr(Constants::MACRO_LIST_TABLE_NAME));
    m_model->setSort(Constants::MACRO_INDEX_NO, Qt::AscendingOrder);
    m_model->select();
    ui->tableView->setModel(m_model);
    ManagerStyle* managerStyle = new ManagerStyle();
    m_managerDelegate = new ManagerDelegate(0, managerStyle);
    ui->tableView->setItemDelegate(m_managerDelegate);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setColumnHidden(Constants::MACRO_INDEX_UUID, true);
    ui->tableView->setColumnHidden(Constants::MACRO_INDEX_CDATETIME, true);
    ui->tableView->setColumnHidden(Constants::MACRO_INDEX_CDATETIME, true);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->verticalHeader()->hide();
    QHeaderView* header = ui->tableView->horizontalHeader();
    header->resizeSection(Constants::MACRO_INDEX_SHOWPIX, 100);
    header->resizeSection(Constants::MACRO_INDEX_NO, 200);
    header->resizeSection(Constants::MACRO_INDEX_NAME, 500);
    ui->tableView->selectRow(0);
    ui->tableView->setFocus();
    QModelIndex index = m_model->index(0, 0);
    ui->exportBnt->setHidden(true);
    ui->importBnt->setHidden(true);
    connect(ui->optionBnt, SIGNAL(clicked()), this, SLOT(showOptionMenu()));
    connect(ui->importBnt, SIGNAL(clicked()), this, SLOT(importClickedSlot()));
    connect(ui->deleteBnt, SIGNAL(clicked()), this, SLOT(deleteSelectedRow()));
    connect(ui->editBnt, SIGNAL(clicked()), this, SLOT(editClickedSolt()));
    connect(ui->newBnt, SIGNAL(clicked()), this, SLOT(newClickedSolt()));
    connect(ui->homeTBnt, SIGNAL(clicked()), this, SLOT(homeClickedSlot()));
    connect(ui->fileTBnt, SIGNAL(clicked()), this, SLOT(fileClickedSlot()));
    connect(ui->phrasebookTBnt, SIGNAL(clicked()), this, SLOT(phrasebookClickedSlot()));
    connect(ui->exportBnt, SIGNAL(clicked()), this, SLOT(exportClickedSlot()));
    m_optionMenuStatus  = true;
}
/****************************************************************************
**
** 函数名称：ManagerMacro::~ManagerMacro
** 功能概述: 析构函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ManagerMacro::~ManagerMacro()
{
    Logging::get()->info("ManagerMacro::~ManagerMacro");
    delete ui;
}
/****************************************************************************
**
** 函数名称：ManagerMacro::eventFilter
** 功能概述: 事件监听函数，响应用户键盘操作
** 参数说明 watched：发送方， event：事件数据
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool ManagerMacro::eventFilter(QObject* watched, QEvent* event)
{
    Logging::get()->info("ManagerMacro::eventFilter");
    QStringList nameList;
    nameList << "tableView" << "newBnt" << "editBnt"
             << "deleteBnt" << "optionBnt" << "homeTBnt" << "fileTBnt" << "phrasebookTBnt";
    QKeyEvent* key_event = static_cast<QKeyEvent*>(event);
    int a =   key_event->key();
    // 按下时键屏蔽
    // 弹起时键屏蔽
    // 默认键值51 响应一次
    switch (a)
    {
    case Qt::Key_T:
    {
        if (QEvent::KeyPress == event->type())
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type())
        {
            return true;
        }
        
        QKeyEvent* key_event = static_cast<QKeyEvent*>(event);
        
        if (key_event->modifiers() & Qt::AltModifier)// optionBnt 按钮获得光标
        {
            QWidget* widget = findChild<QWidget*>("optionBnt");
            Button* button = static_cast<Button*>(widget);
            widget->setFocus();
        }
        
        break;
    }
    
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
        
        if (!m_optionMenuStatus && (a == Qt::Key_Down || a == Qt::Key_Tab))//一定OPTION菜单内的光标
        {
            if (ui->exportBnt->hasFocus())
                ui->importBnt->setFocus();
            else if (ui->importBnt->hasFocus())
                ui->exportBnt->setFocus();
            else
                ui->exportBnt->setFocus();
                
            break;
        }
        else if (!m_optionMenuStatus && (a == Qt::Key_Right))//关闭OPTION菜单
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
                if (nameList.at(i) == "tableView")
                {
                    QModelIndex index = m_model->index(ui->tableView->currentIndex().row(),0);
                    ui->tableView->setCurrentIndex(index);
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
                
                if (nameList.at(i) == "fileTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/manager_File_Btn_SelNo"));
                }
                
                if (nameList.at(i) == "macroTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/manager_Macro_Btn_SelNo"));
                }
                
                if (nameList.at(i) == "phrasebookTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/manager_PhraseBook_Btn_SelNo"));
                }
                
                next = (i == nameList.length() - 1) ? 0 : i + 1;
                break;
            }
        }
        
        if (inTableView)
            break;
            // 按钮图片切换 focus 获得 按钮图片亮
        QWidget* widgetnext = findChild<QWidget*>(nameList.at(next));
        
        if (widgetnext)
        {
            widgetnext->setFocus();
            
            if (nameList.at(next) == "homeTBnt")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetnext);
                button->setIcon(QIcon(":/images/home_hover"));
            }
            
            if (nameList.at(next) == "fileTBnt")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetnext);
                button->setIcon(QIcon(":/images/manager_File_Btn_SelYes"));
            }
            
            if (nameList.at(next) == "macroTBnt")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetnext);
                button->setIcon(QIcon(":/images/manager_Macro_Btn_SelYes"));
            }
            
            if (nameList.at(next) == "phrasebookTBnt")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetnext);
                button->setIcon(QIcon(":/images/manager_PhraseBook_Btn_SelYes"));
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
        
        if (!m_optionMenuStatus && (a == Qt::Key_Up))//移动OPTION菜单内光标
        {
            if (ui->exportBnt->hasFocus())
                ui->importBnt->setFocus();
            else if (ui->importBnt->hasFocus())
                ui->exportBnt->setFocus();
            else
                ui->exportBnt->setFocus();
                
            break;
        }
        else if (!m_optionMenuStatus && (a == Qt::Key_Left))//关闭OPTION菜单
        {
            QWidget* widget = findChild<QWidget*>("optionBnt");
            Button* button = static_cast<Button*>(widget);
            button->click();
            widget->setFocus();
            return true;
        }
        
        int prev = 0;
        bool inTableView = false;
        
        for (int i = 0; i < nameList.length(); i++)
        {
            QWidget* widget = findChild<QWidget*>(nameList.at(i));
            // 按钮图片切换 focus 离开 按钮图片变暗
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
                
                if (nameList.at(i) == "fileTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/manager_File_Btn_SelNo"));
                }
                
                if (nameList.at(i) == "macroTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/manager_Macro_Btn_SelNo"));
                }
                
                if (nameList.at(i) == "phrasebookTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/manager_PhraseBook_Btn_SelNo"));
                }
                
                prev = (i == 0) ? nameList.length() - 1 : i - 1;
                break;
            }
        }
        
        if (inTableView)
            break;
            // 按钮图片切换 focus 获得 按钮图片亮
        QWidget* widgetprev = findChild<QWidget*>(nameList.at(prev));
        
        //widgetprev->setFocus();
        if (widgetprev)
        {
            widgetprev->setFocus();
            
            if (nameList.at(prev) == "homeTBnt")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetprev);
                button->setIcon(QIcon(":/images/home_hover"));
            }
            
            if (nameList.at(prev) == "fileTBnt")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetprev);
                button->setIcon(QIcon(":/images/manager_File_Btn_SelYes"));
            }
            
            if (nameList.at(prev) == "macroTBnt")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetprev);
                button->setIcon(QIcon(":/images/manager_Macro_Btn_SelYes"));
            }
            
            if (nameList.at(prev) == "phrasebookTBnt")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetprev);
                button->setIcon(QIcon(":/images/manager_PhraseBook_Btn_SelYes"));
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
        
        for (int i = 0; i < nameList.length(); i++)//触发按键事件
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
                else if (nameList.at(i) == "phrasebookTBnt")
                {
                    QWidget* widget = findChild<QWidget*>("phrasebookTBnt");
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                }
                else if (nameList.at(i) == "macroTBnt")
                {

                }
                else if (nameList.at(i) == "fileTBnt")
                {
                    QWidget* widget = findChild<QWidget*>("fileTBnt");
                    Button* button = static_cast<Button*>(widget);
                    button->click();
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
             // optionBnt 按钮获得光标
        if (!m_optionMenuStatus)
        {
            QWidget* widget = findChild<QWidget*>("optionBnt");
            Button* button = static_cast<Button*>(widget);
            button->click();
            ui->optionBnt->setFocus();
        }
        else
        {
            QWidget* widget = findChild<QWidget*>("homeTBnt");
            
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

/****************************************************************************
**
** 函数名称：ManagerMacro::showOptionMenu
** 功能概述: option菜单处理
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerMacro::showOptionMenu()
{
    Logging::get()->info("ManagerMacro::showOptionMenu");
    
    if (m_optionMenuStatus  == true)//打开菜单
    {
        if (ui->tableView->hasFocus())
        {
            ui->optionBnt->setFocus();
        }
        
        ui->exportBnt->setHidden(false);
        ui->importBnt->setHidden(false);
        ui->importBnt->setChecked(true);
        ui->exportBnt->setFocus();
        m_optionMenuStatus  = false;
    }
    else//关闭菜单
    {
        ui->exportBnt->setHidden(true);
        ui->importBnt->setHidden(true);
        ui->optionBnt->setFocus();
        m_optionMenuStatus  = true;
    }
}
/****************************************************************************
**
** 函数名称：ManagerMacro::exportClickedSlot
** 功能概述: 导出处理
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerMacro:: exportClickedSlot()
{
    Logging::get()->info("ManagerMacro::exportClickedSlot");
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
                
            bool ret = SQLiteHelper::exportData("macro", file);
            
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
        }
    }
    
    ui->tableView->selectRow(0);
    ui->tableView->setFocus();
}
/****************************************************************************
**
** 函数名称：ManagerMacro::importClickedSlot
** 功能概述: 导入处理
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerMacro:: importClickedSlot()
{
    Logging::get()->info("ManagerMacro::importClickedSlot");
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
                m_model->select();
            }
            else
            {
                MessageBox  msg;
                msg.move((SCREEN_SIZE_WIDTH - msg.width()) / 2, (SCREEN_SIZE_HEIGHT - msg.height()) / 2);
                msg.SetMessage(tr("system"), tr("Import failed"), 0);
                msg.exec() ;
            }
        }
    }
    
    for (int n = 1; n <= m_model->rowCount(); n++)
    {
        QSqlRecord record = m_model->record(n - 1);
        record.setValue(Constants::MACRO_INDEX_NO, n);
        m_model->setRecord(n - 1, record);
    }
    
    m_model->submitAll();
    ui->tableView->selectRow(0);
    ui->tableView->setFocus();
}
/****************************************************************************
**
** 函数名称：ManagerMacro::deleteSelectedRow
** 功能概述: 删除记录处理
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerMacro:: deleteSelectedRow()
{
    Logging::get()->info("ManagerMacro::deleteSelectedRow");
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
    
    SQLiteHelper::beginTransaction();
    int curRow = ui->tableView->currentIndex().row();
    //QModelIndex index = ui->tableView->currentIndex();
    //QString strUUID = index.sibling(curRow, 0).data().toString();
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
    SQLiteHelper::endTransaction();
    ui->tableView->setFocus();
    ui->tableView->selectRow(intSelectRow);
    
    for (int n = 1; n <= m_model->rowCount(); n++)
    {
        QSqlRecord record = m_model->record(n - 1);
        record.setValue(Constants::MACRO_LIST_COL_NO, n);
        m_model->setRecord(n - 1, record);
    }
    
    m_model->submitAll();
    ui->tableView->selectRow(0);
    ui->tableView->setFocus();
}
/****************************************************************************
**
** 函数名称：ManagerMacro::newClickedSolt
** 功能概述: 新建记录
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerMacro:: newClickedSolt()
{
    Logging::get()->info("ManagerMacro::newClickedSolt");
    int ret = 0;
    QString macroname ;
    InputDialog  inputDialog;
    inputDialog.move((SCREEN_SIZE_WIDTH - inputDialog.width()) / 2, (SCREEN_SIZE_HEIGHT - inputDialog.height()) / 2);
    inputDialog.SetTitle(tr("macro"));
    inputDialog.SetLineEditMaxLen(Constants::MACROMAX_EDIT_SIZE);
    ret =  inputDialog.exec() ;
    
    if (ret)//确认输入
    {
        QUuid uuid = QUuid::createUuid();
        QString strUUID = uuid.toString();
        macroname = inputDialog.getTextContent();
        int intInserRow = 0;
        int intRowCout = m_model->rowCount();
        int intNo = intRowCout + 1;
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
        QString strDateTime = (QString::number(y) + "-" + mStr + "-" + dStr + "  " + strTime);
        m_model->insertRows(intInserRow, 1);
        m_model->setData(m_model->index(intInserRow, Constants::MACRO_INDEX_UUID), strUUID);
        m_model->setData(m_model->index(intInserRow, Constants::MACRO_INDEX_NO), intNo);
        m_model->setData(m_model->index(intInserRow, Constants::MACRO_INDEX_NAME), macroname);
        m_model->setData(m_model->index(intInserRow, Constants::MACRO_INDEX_CDATETIME), strDateTime);
        m_model->setData(m_model->index(intInserRow, Constants::MACRO_INDEX_UDATETIME), strDateTime);
        m_model->submitAll();
        m_model->select();
        ui->tableView->selectRow(0);
        ui->tableView->setFocus();
    }
}
/****************************************************************************
**
** 函数名称：ManagerMacro::editClickedSolt
** 功能概述: 编辑记录
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerMacro:: editClickedSolt()
{
    Logging::get()->info("ManagerMacro::editClickedSolt");
    QMap <QString, QString>paraMap;
    int curRow = ui->tableView->currentIndex().row();
    QModelIndex index = ui->tableView->currentIndex();
    QString strUUID = index.sibling(curRow, Constants::PHRASEBOOK_INDEX_UUID).data().toString();
    QString strContent = index.sibling(curRow, Constants::PHRASEBOOK_INDEX_CONTENT).data().toString();
    int ret = 0;
    QString macroname ;
    InputDialog  inputDialog;
    inputDialog.move((SCREEN_SIZE_WIDTH - inputDialog.width()) / 2, (SCREEN_SIZE_HEIGHT - inputDialog.height()) / 2);
    inputDialog.SetTitle(tr("macro"));
    inputDialog.SetLineEditMaxLen(Constants::MACROMAX_EDIT_SIZE);
    inputDialog.SetTextContent(strContent);
    ret =  inputDialog.exec() ;
    
    if (ret)//确认输入
    {
        macroname = inputDialog.getTextContent();
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
        QString strDateTime = (QString::number(y) + "-" + mStr + "-" + dStr + "  " + strTime);
        QString  strFiter;
        strFiter = Constants::PHRASEBOOK_LIST_COL_UUID  ;
        strFiter = strFiter + "  = '";
        strFiter = strFiter + strUUID ;
        strFiter = strFiter + "' ";
        m_model->setFilter(strFiter);
        
        if (m_model->select())
        {
            if (m_model->rowCount() == 1)
            {
                QSqlRecord record = m_model->record(0);
                record.setValue(Constants::MACRO_LIST_COL_NAME, macroname);
                record.setValue(Constants::MACRO_LIST__COL_UDATETIME, strDateTime);
                m_model->setRecord(0, record);
                m_model->submitAll();
            }
        }
        
        m_model->setFilter("");
        m_model->select();
        ui->tableView->selectRow(curRow);
        ui->tableView->setFocus();
    }
}
/****************************************************************************
**
** 函数名称：ManagerMacro::homeClickedSlot
** 功能概述: 返回到主菜单
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerMacro:: homeClickedSlot()
{
    Logging::get()->info("ManagerMacro::homeClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(Constants::MANAGER_MACRO, "homeWidget", paraMap);
}
/****************************************************************************
**
** 函数名称：ManagerMacro::phrasebookClickedSlot
** 功能概述: 打开phrasebook页面
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerMacro::phrasebookClickedSlot()
{
    Logging::get()->info("ManagerMacro::phrasebookClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(Constants::MANAGER_MACRO, Constants::MANAGER_PHRASEBOOK, paraMap);
}
/****************************************************************************
**
** 函数名称：ManagerMacro::fileClickedSlot
** 功能概述: 打开文件列表页面
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerMacro::fileClickedSlot()
{
    Logging::get()->info("ManagerMacro::fileClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(Constants::MANAGER_MACRO, Constants::MANAGER_FILE, paraMap);
}
/****************************************************************************
**
** 函数名称：ManagerMacro::frontPageSlot
** 功能概述: 打开页面时更新页面数据
** 参数说明： thisID：起始页面， fowordID：目标页面， paraMap：传递参数
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerMacro::frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap)
{
    if (fowordID != Constants::MANAGER_MACRO) {return;}
    
    Logging::get()->info("ManagerMacro::frontPageSlot");
    m_model->select();
    m_optionMenuStatus = false;
    showOptionMenu();
    ui->homeTBnt->setIcon(QIcon(":/images/home_normal"));
    ui->fileTBnt->setIcon(QIcon(":/images/manager_File_Btn_SelNo"));
    ui->phrasebookTBnt->setIcon(QIcon(":/images/manager_PhraseBook_Btn_SelNo"));
    ui->tableView->selectRow(0);
    ui->tableView->setFocus();
}

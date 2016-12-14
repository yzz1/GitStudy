#include "managerfile.h"
#include "ui_managerfile.h"
#include "views/contacts/contactsindstyle.h"
#include "core/utils/sqlitehelper.h"
#include "core/database/database.h"
//#include "views/messages/messagesstyle.h"
#include "views/common/constants.h"
#include "views/manager/managerfilestyle.h"
#include "widgets/messagebox.h"
#include <QKeyEvent>
#include <QSqlRecord>
#include <QLineEdit>
#include <QEvent>
#include "widgets/button.h"
#include <QFileDialog>
#include "logging.h"
#include <widgets/inputdialog.h>
/****************************************************************************
**
** 函数名称：ManagerFile::ManagerFile
** 功能概述: 初始化
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ManagerFile::ManagerFile(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::ManagerFile)
{
    Logging::get()->info("ManagerFile::ManagerFile");
    ui->setupUi(this);
    ui->contactsTiltewidget->setText(Constants::MANAGER_FILE_TITLE);
    this->installEventFilter(this);
    this->setWindowIcon(QIcon(":/images/null.png"));
    m_curWidget = NULL;
    m_lostFocus = false;
    m_TableToNext = false;
    m_model = new FileModels(this, SQLiteHelper::openConnection());
    m_model->setTable(tr(Constants::FILe_LIST_TABLE_NAME));
    m_model->setSort(Constants::FILe_INDEX_UDATETIME, Qt::DescendingOrder);
    m_model->select();
    ui->tableView->setModel(m_model);
    ManagerFileStyle* managerfileStyle = new ManagerFileStyle();
    m_fileItemDelegate = new FileItemDelegate(0, managerfileStyle);
    ui->tableView->setItemDelegate(m_fileItemDelegate);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setColumnHidden(Constants::FILe_INDEX_UUID, true);
    ui->tableView->setColumnHidden(Constants::FILe_INDEX_CONTENT, true);
    ui->tableView->setColumnHidden(Constants::FILe_INDEX_CDATETIME, true);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->verticalHeader()->hide();
    QHeaderView* header = ui->tableView->horizontalHeader();
    header->resizeSection(Constants::FILe_INDEX_SHOWPIX, 100);
    header->resizeSection(Constants::FILe_INDEX_NAME, 450);
    header->resizeSection(Constants::FILe_INDEX_UDATETIME, 250);
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
    connect(ui->renameBnt, SIGNAL(clicked()), this, SLOT(renameClickedSolt()));
    connect(ui->homeTBnt, SIGNAL(clicked()), this, SLOT(homeClickedSlot()));
    connect(ui->macroTBnt, SIGNAL(clicked()), this, SLOT(macroClickedSlot()));
    connect(ui->phrasebookTBnt, SIGNAL(clicked()), this, SLOT(phrasebookClickedSlot()));
    connect(ui->exportBnt, SIGNAL(clicked()), this, SLOT(exportClickedSlot()));
    m_optionMenuStatus  = true;
    ui->tableView->installEventFilter(this);
}
/****************************************************************************
**
** 函数名称：ManagerFile::～ManagerFile
** 功能概述: 析构函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ManagerFile::~ManagerFile()
{
    Logging::get()->info("ManagerFile::~ManagerFile");
    delete ui;
}
/****************************************************************************
**
** 函数名称：ManagerFile::showOptionMenu
** 功能概述: option菜单处理
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerFile::showOptionMenu()
{
    Logging::get()->info("ManagerFile::showOptionMenu");
    
    if (m_optionMenuStatus  == true)//菜单展开
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
    else//菜单关闭
    {
        ui->exportBnt->setHidden(true);
        ui->importBnt->setHidden(true);
        ui->optionBnt->setFocus();
        m_optionMenuStatus  = true;
    }
}
/****************************************************************************
**
** 函数名称：ManagerFile::exportClickedSlot
** 功能概述: 导出处理
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerFile:: exportClickedSlot()
{
    Logging::get()->info("ManagerFile::exportClickedSlot");
    ui->optionBnt->click();
    QFileDialog w;
    QSqlRecord record = m_model->record(ui->tableView->currentIndex().row());
    QString filename(record.value(Constants::FILe_INDEX_NAME).toString());
    w.selectFile(filename);
    w.setDirectory(QString("/"));
    w.setFilter(QString("txt Files(*.txt)"));
    w.setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
    w.setAcceptMode(QFileDialog::AcceptSave); //AcceptOpen打开,AcceptSave保存
    w.setOption(QFileDialog::ReadOnly, true);
    QString style = "background-color:rgb(65, 85, 100);";
    w.setStyleSheet(style);
    w.setViewMode(QFileDialog::List);
    QStringList dir;
    
    if (w.exec() == QFileDialog::Accepted) // ok
    {
        dir = w.selectedFiles();
        QString file = dir.at(0);
        
        if (!file.isEmpty())
        {
            QString xml = file.mid(file.length() - 4, 4);
            
            if (xml != ".txt" && xml != ".TXT")
                file.append(".txt");
                
            bool ret = SQLiteHelper::exportData("file", file, filename);
            
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
** 函数名称：ManagerFile::exportClickedSlot
** 功能概述: 导入处理
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerFile:: importClickedSlot()
{
    Logging::get()->info("ManagerFile::importClickedSlot");
    ui->optionBnt->click();
    QFileDialog w;
    w.setDirectory(QString("/"));
    w.setFilter(QString("txt Files(*.txt)"));
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
                msg.SetMessage(tr("system"), tr("Import failed: Illegal character"), 0);
                msg.exec() ;
            }
        }
    }
    
    ui->tableView->selectRow(0);
    ui->tableView->setFocus();
}
/****************************************************************************
**
** 函数名称：ManagerFile::deleteSelectedRow
** 功能概述: 删除记录处理
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerFile:: deleteSelectedRow()
{
    Logging::get()->info("ManagerFile::deleteSelectedRow");
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
}
/****************************************************************************
**
** 函数名称：ManagerFile::newClickedSolt
** 功能概述: 新建记录处理
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerFile:: newClickedSolt()
{
    Logging::get()->info("ManagerFile::newClickedSolt");
    QMap <QString, QString>paraMap;
    int curRow = ui->tableView->currentIndex().row();
    m_curRow = curRow;
    QModelIndex index = ui->tableView->currentIndex();
    QString strModle  =  QString(Constants::MANAGER_FILE_NEW);
    paraMap.insert(Constants::MANAGER_MODLE_NAME, strModle);
    emit afterPageSignal(Constants::MANAGER_FILE, Constants::MANAGER_FILE_EDIT_VIEW, paraMap);
}
/****************************************************************************
**
** 函数名称：ManagerFile::renameClickedSolt
** 功能概述: 修改记录名称
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerFile:: renameClickedSolt()
{
    Logging::get()->info("ManagerFile::renameClickedSolt");
    int curRow = ui->tableView->currentIndex().row();
    //m_fileItemDelegate->setIntEditRow(curRow);
    QModelIndex index = m_model->index(curRow, Constants::FILe_INDEX_NAME);
    QString strOldFileName = index.sibling(curRow, Constants::FILe_INDEX_NAME).data().toString();
    int ret = 0;
    InputDialog  inputDialog;
    inputDialog.move((SCREEN_SIZE_WIDTH - inputDialog.width()) / 2, (SCREEN_SIZE_HEIGHT - inputDialog.height()) / 2);
    inputDialog.SetTitle(tr("File Rename"));
    inputDialog.SetTextContent(strOldFileName);
    ret =  inputDialog.exec() ;
    if (ret)//确认输入
    {
        QString fileName = inputDialog.getTextContent();
        reNameFile(fileName);

    }
    else
    {
        ui->tableView->setFocus();
    }
    //ui->tableView->setFocus();//把输入焦点交给TABLEVIEW
    //ui->tableView->setCurrentIndex(index);//设定需要编辑的单元格
    //ui->tableView->edit(index);//开始编辑
}
/****************************************************************************
**
** 函数名称：ManagerFile::reNameFile
** 功能概述: 修改名称后处理
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerFile::reNameFile(QString  filenameEdited)
{
    Logging::get()->info("ManagerFile::reNameFile");
    int curRow = ui->tableView->currentIndex().row();
    //m_fileItemDelegate->setIntEditRow(curRow);
    QModelIndex index = m_model->index(curRow, Constants::FILe_INDEX_UUID);
    QString strUUID = index.sibling(curRow, Constants::FILe_INDEX_UUID).data().toString();
    //QLineEdit*  linEdit  = static_cast<QLineEdit*>(ui->tableView->indexWidget(index));
    //QString  filenameEdited = linEdit->text();
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
            record.setValue(Constants::FILe_LIST_COL_NAME, filenameEdited);
            m_model->setRecord(0, record);
            m_model->submitAll();
            m_model->setFilter("");
            m_model->select();
        }
    }
    
    //m_fileItemDelegate->setIntEditRow(-1);
    //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->selectRow(curRow);
    ui->tableView->setFocus();
}
/****************************************************************************
**
** 函数名称：ManagerFile::editClickedSolt
** 功能概述: 打开修改内容页面
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerFile:: editClickedSolt()
{
    Logging::get()->info("ManagerFile::editClickedSolt");
    QMap <QString, QString>paraMap;
    int curRow = ui->tableView->currentIndex().row();
    m_curRow = curRow;
    QModelIndex index = ui->tableView->currentIndex();
    QString strModle  =  QString(Constants::MANAGER_FILE_EDIT);
    QString strUUID = index.sibling(curRow, Constants::FILe_INDEX_UUID).data().toString();
    QString strName = index.sibling(curRow, Constants::FILe_INDEX_NAME).data().toString();
    QString strContent = index.sibling(curRow, Constants::FILe_INDEX_CONTENT).data().toString();
    paraMap.insert(Constants::MANAGER_MODLE_NAME, strModle);
    paraMap.insert(Constants::MANAGER_FILE_UUID, strUUID);
    paraMap.insert(Constants::FILe_LIST_COL_NAME, strName);
    paraMap.insert(Constants::FILe_LIST_COL_CONTENT, strContent);
    emit afterPageSignal(Constants::MANAGER_FILE, Constants::MANAGER_FILE_EDIT_VIEW, paraMap);
}
/****************************************************************************
**
** 函数名称：ManagerFile::homeClickedSlot
** 功能概述: 返回主菜单
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerFile:: homeClickedSlot()
{
    Logging::get()->info("ManagerFile::homeClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(Constants::MANAGER_FILE, HOME_VIEW_NAME, paraMap);
}
/****************************************************************************
**
** 函数名称：ManagerFile::eventFilter
** 功能概述: 事件监听函数，响应用户键盘操作
** 参数说明 watched：发送方， event：事件数据
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool ManagerFile::eventFilter(QObject* watched, QEvent* event)
{
    Logging::get()->info("ManagerFile::eventFilter");
    QStringList nameList;
    nameList << "tableView" << "newBnt" << "editBnt" << "deleteBnt" << "renameBnt"
             << "optionBnt" << "homeTBnt" << "macroTBnt" << "phrasebookTBnt";
    QKeyEvent* key_event = static_cast<QKeyEvent*>(event);
    int a =   key_event->key();
    
    if (m_lostFocus)	//在光标丢失时自动设置焦点到tableview
    {
        ui->tableView->setFocus();
        ui->tableView->selectRow(0);
        m_lostFocus = false;
    }
    
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
        
        if (key_event->modifiers() & Qt::AltModifier)//使用快捷键时，进入处理
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
        if (ui->tableView->hasFocus() && !m_TableToNext)//解决光标丢失的问题
        {
            m_TableToNext = true;
            if (m_fileItemDelegate->getIntEditRow() != -1)
            {
                Logging::get()->info("ManagerFile::eventFilter test31");
                return true;
            }
            return QWidget::eventFilter(watched, event);
        }
        else if (!ui->tableView->hasFocus() && m_TableToNext)//解决光标丢失的问题
        {
            m_TableToNext = false;
            if (m_fileItemDelegate->getIntEditRow() != -1)
            {
                Logging::get()->info("ManagerFile::eventFilter test32");
                return true;
            }

            return QWidget::eventFilter(watched, event);
        }
        
        if (QEvent::KeyPress == event->type())// 按下时键屏蔽
        {
            return QWidget::eventFilter(watched, event);;
        }
        else if (QEvent::KeyRelease == event->type())// 弹起时键屏蔽
        {
            return true;
        }
        
        if (!m_optionMenuStatus && (a == Qt::Key_Down || a == Qt::Key_Tab))
        {
            if (ui->exportBnt->hasFocus())
                ui->importBnt->setFocus();
            else if (ui->importBnt->hasFocus())
                ui->exportBnt->setFocus();
            else
                ui->exportBnt->setFocus();
                
            break;
        }
        else if (!m_optionMenuStatus && (a == Qt::Key_Right))//关闭OPTION
        {
            QWidget* widget = findChild<QWidget*>("optionBnt");
            Button* button = static_cast<Button*>(widget);
            button->click();
            widget->setFocus();
            return true;
        }
        
        int next = 0;
        bool inTableView = false;
        
        for (int i = 0; i < nameList.length(); i++)// 按钮图片切换 focus 离开 按钮图片变暗
        {
            QWidget* widget = findChild<QWidget*>(nameList.at(i));
            
            if (widget && widget->hasFocus())
            {
                if (nameList.at(i) == "tableView")
                {
                    if (a == Qt::Key_Down)
                    {
                        if (m_fileItemDelegate->getIntEditRow() != -1)
                        {
                            Logging::get()->info("ManagerFile::eventFilter test3");
                            return true;
                        }
                        inTableView = true;
                        break;
                    }
                }
                
                if (nameList.at(i) == "homeTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/home_normal"));
                }
                
                if (nameList.at(i) == "fileTBnt_2")
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
            
            if (nameList.at(next) == "fileTBnt_2")
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
        if (ui->tableView->hasFocus() && !m_TableToNext)// 解决丢失焦点的问题
        {
            m_TableToNext = true;
            return QWidget::eventFilter(watched, event);
        }
        else if (!ui->tableView->hasFocus() && m_TableToNext)// 解决丢失焦点的问题
        {
            m_TableToNext = false;
            return QWidget::eventFilter(watched, event);
        }
        
        if (QEvent::KeyPress == event->type())// 按下时键屏蔽
        {
            return QWidget::eventFilter(watched, event);
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
                
                if (nameList.at(i) == "fileTBnt_2")
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
            
            if (nameList.at(prev) == "fileTBnt_2")
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
        if (QEvent::KeyPress == event->type())// 按下时键屏蔽
        {
            //if (m_fileItemDelegate->getIntEditRow() != -1)
            //{
            //    enterKeyPress();
            //}
            
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
                    QWidget* widget = findChild<QWidget*>("macroTBnt");
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
** 函数名称：ManagerFile::macroClickedSlot
** 功能概述: 打开macro页面
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerFile::macroClickedSlot()
{
    Logging::get()->info("ManagerFile::macroClickedSlot");
    int curRow = ui->tableView->currentIndex().row();
    m_curRow = curRow;
    QMap <QString, QString>paraMap;
    emit afterPageSignal(Constants::MANAGER_FILE, Constants::MANAGER_MACRO, paraMap);
}
/****************************************************************************
**
** 函数名称：ManagerFile::phrasebookClickedSlot
** 功能概述: 打开phrasebook页面
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerFile::phrasebookClickedSlot()
{
    Logging::get()->info("ManagerFile::phrasebookClickedSlot");
    int curRow = ui->tableView->currentIndex().row();
    m_curRow = curRow;
    QMap <QString, QString>paraMap;
    emit afterPageSignal(Constants::MANAGER_FILE, Constants::MANAGER_PHRASEBOOK, paraMap);
}
/****************************************************************************
**
** 函数名称：ManagerFile::frontPageSlot
** 功能概述: 打开页面时更新页面数据
** 参数说明： thisID：起始页面， fowordID：目标页面， paraMap：传递参数
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerFile::frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap)
{
    if (fowordID != Constants::MANAGER_FILE) {return;}
    
    Logging::get()->info("ManagerFile::frontPageSlot");
    m_model->select();
    m_optionMenuStatus = false;
    showOptionMenu();
    ui->homeTBnt->setIcon(QIcon(":/images/home_normal"));
    ui->macroTBnt->setIcon(QIcon(":/images/manager_Macro_Btn_SelNo"));
    ui->phrasebookTBnt->setIcon(QIcon(":/images/manager_PhraseBook_Btn_SelNo"));
    ui->tableView->selectRow(0);
    ui->tableView->setFocus();
}

#include "callcommunicationwidget.h"
#include "ui_callcommunicationwidget.h"
#include "views/contacts/contactsindstyle.h"

#include "core/utils/sqlitehelper.h"
#include "core/database/database.h"
#include "views/common/constants.h"
#include "views/manager/managerstyle.h"
#include <QDesktopWidget>
#include <QEvent>
#include <QKeyEvent>
#include "widgets/button.h"
#include <QDebug>
#include <QSqlRecord>
#include "logging.h"
/****************************************************************************
**
** 函数名称：CallCommunicationwidget::CallCommunicationwidget
** 功能概述: 初始化
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
CallCommunicationwidget::CallCommunicationwidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::CallCommunicationwidget)
{
    Logging::get()->info("CallCommunicationwidget::CallCommunicationwidget");

    // 初始化UI
    ui->setupUi(this);
    m_callCommunicationStyle = new CallCommunicationStyle();
    m_callPhraseBookStyle = new CallPhraseBookStyle();
    m_callFileStyle = new CallFileStyle();
    m_macroDelegate = new ManagerDelegate(0, m_callCommunicationStyle);
    m_macroDelegate2 = new ManagerDelegate(0, m_callCommunicationStyle);
    m_phraseBookDelegate = new ManagerDelegate(0, m_callPhraseBookStyle);
    m_phraseBookDelegate2 = new ManagerDelegate(0, m_callPhraseBookStyle);
    m_fileDelegate = new ManagerDelegate(0, m_callFileStyle);
    m_fileDelegate2 = new ManagerDelegate(0, m_callFileStyle);
    m_fileDelegate->setCallFileFlag(true);
    m_fileDelegate2->setCallFileFlag(true);
    m_model = new ManagerModel(this, SQLiteHelper::openConnection());
    m_model_2 = new ManagerModel(this, SQLiteHelper::openConnection());
    m_model_3 = new ManagerLoadFileModel(this);
    m_model_4 = new ManagerLoadFileModel(this);
    QDesktopWidget* desktop = QApplication::desktop();
    this->move((desktop->width() - width()) / 2, (desktop->height() - height()) / 2);
    connect(ui->cancelBtn, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->okBtn, SIGNAL(clicked()), this, SLOT(okButtonClickedSlot()));
    connect(ui->okBtn, SIGNAL(clicked()), this, SIGNAL(okButtonClickedSignal()));
    this->installEventFilter(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
}
/****************************************************************************
**
** 函数名称：CallCommunicationwidget::eventFilter
** 功能概述: 事件监听函数，响应用户键盘操作。
** 参数说明： watched：发送方， event：事件数据
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool CallCommunicationwidget::eventFilter(QObject* watched, QEvent* event)
{
    Logging::get()->info("CallCommunicationwidget::eventFilter");
    QStringList nameList;
    nameList << "tableView" << "tableView_2" << "okBtn" << "cancelBtn";
    QKeyEvent* key_event = static_cast<QKeyEvent*>(event);
    int a = key_event->key();
    
    switch (a)
    {
    // Tab键
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
        
        if (ui->tableView->hasFocus())
        {
            m_managerDelegate->setSelectedHidden(true);
            m_managerDelegate2->setSelectedHidden(false);
            ui->tableView_2->selectRow(0);
        }
        else if (ui->tableView_2->hasFocus())
        {
            m_managerDelegate2->setSelectedHidden(true);
            m_managerDelegate->setSelectedHidden(false);
            ui->tableView->selectRow(0);
            ui->tableView_2->scrollToTop();
        }
        
        break;
    }
    
    // 后退、向左、向右键
    case Qt::Key_Backtab:
    case Qt::Key_Left:
    case Qt::Key_Right:
    {
        if (QEvent::KeyPress == event->type())
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type())
        {
            return true;
        }
        
        if (ui->tableView->hasFocus())
        {
            ui->tableView_2->selectRow(0);
            ui->tableView_2->setFocus();
            m_managerDelegate->setSelectedHidden(true);
            m_managerDelegate2->setSelectedHidden(false);
        }
        else if (ui->tableView_2->hasFocus())
        {
            m_managerDelegate2->setSelectedHidden(true);
            m_managerDelegate->setSelectedHidden(false);
            ui->tableView->setFocus();
            ui->tableView->selectRow(0);
            ui->tableView_2->scrollToTop();
        }
        
        break;
    }
    
    // 向下键
    case Qt::Key_Down:
    {
        if (QEvent::KeyPress == event->type())
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type())
        {
            return true;
        }
        
        if (ui->tableView->hasFocus())
        {
            if (ui->tableView->currentIndex().row() == 9)
            {
                ui->tableView_2->selectRow(0);
                ui->tableView_2->setFocus();
                m_managerDelegate->setSelectedHidden(true);
                m_managerDelegate2->setSelectedHidden(false);
                ui->tableView_2->scrollToTop();
            }
        }
        
        break;
    }
    
    // 向上键
    case Qt::Key_Up:
    {
        if (QEvent::KeyPress == event->type())
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type())
        {
            return true;
        }
        
        if (ui->tableView_2->hasFocus())
        {
            if (ui->tableView_2->currentIndex().row() == 0)
            {
                ui->tableView->selectRow(9);
                ui->tableView->setFocus();
                m_managerDelegate2->setSelectedHidden(true);
                m_managerDelegate->setSelectedHidden(false);
            }
        }
        
        break;
    }
    
    // 回车键
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
        
        ui->okBtn->click();
        break;
    }
    
    // ESC键
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
        
        ui->cancelBtn->click();
        break;
    }
    }
    
    if (a == Qt::Key_Escape)
        return true;
        
    return QWidget::eventFilter(watched, event);
}

/****************************************************************************
**
** 函数名称：CallCommunicationwidget::okButtonClickedSlot
** 功能概述: 确定按钮响应处理。
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunicationwidget::okButtonClickedSlot()
{
    Logging::get()->info("CallCommunicationwidget::okButtonClickedSlot");
    
    if (ui->tableView->hasFocus())
    {
        int count;
        
        if (m_table == Constants::FILe_LIST_TABLE_NAME)
        {
            count = ui->tableView->currentIndex().row();
            QSqlRecord  sqlRecord = m_model_3->record(count);
            m_str = sqlRecord.value(Constants::FILe_INDEX_CONTENT).toString();
            qDebug() << "okButtonClickedSlot" << m_str;
        }
        else
        {
            count = ui->tableView->currentIndex().row();
            QSqlRecord  sqlRecord = m_model->record(count);
            QString name = sqlRecord.value(Constants::MACRO_INDEX_NAME).toString();
            m_str = name;
        }
    }
    else if (ui->tableView_2->hasFocus())
    {
        int count;
        
        if (m_table == Constants::FILe_LIST_TABLE_NAME)
        {
            count = ui->tableView_2->currentIndex().row();
            QSqlRecord  sqlRecord = m_model_4->record(count);
            m_str = sqlRecord.value(Constants::FILe_INDEX_CONTENT).toString();
            qDebug() << "okButtonClickedSlot" << m_str;
        }
        else
        {
            count = ui->tableView_2->currentIndex().row();
            QSqlRecord  sqlRecord = m_model_2->record(count);
            QString name = sqlRecord.value(Constants::MACRO_INDEX_NAME).toString();
            m_str = name;
        }
    }
    
    close();
}
/****************************************************************************
**
** 函数名称：CallCommunicationwidget::dataBack
** 功能概述: 选择的数据获取方式。
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QString CallCommunicationwidget::dataBack()
{
    Logging::get()->info("CallCommunicationwidget::dataBack");
    return m_str;
}
/****************************************************************************
**
** 函数名称：CallCommunicationwidget::init
** 功能概述: 初始化对话框。
** 参数说明： table  数据库名称
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void CallCommunicationwidget::init(QString& table)
{
    Logging::get()->info("CallCommunicationwidget::init");
    m_table = table;
    
    if (table == Constants::MACRO_LIST_TABLE_NAME)
    {
        m_managerDelegate = m_macroDelegate;
        m_managerDelegate2 = m_macroDelegate2;
        ui->lab_Title->setText(QString("Macros"));
    }
    else if (table == Constants::PHRASEBOOK_LIST_TABLE_NAME)
    {
        m_managerDelegate = m_phraseBookDelegate;
        m_managerDelegate2 = m_phraseBookDelegate2;
        ui->lab_Title->setText(QString("Phrasebook"));
    }
    else if (table == Constants::FILe_LIST_TABLE_NAME)
    {
        m_managerDelegate = m_fileDelegate;
        m_managerDelegate2 = m_fileDelegate2;
        ui->lab_Title->setText(QString("Load"));
    }
    
    m_managerDelegate2->setSelectedHidden(true);
    m_managerDelegate->setSelectedHidden(false);
    ui->tableView->selectRow(0);
    ui->tableView->setFocus();
    ui->tableView_2->scrollToTop();
    m_model->setTable(table);
    QString fiter("no < 11");
    
    if (table == Constants::FILe_LIST_TABLE_NAME)
    {
        Database* database = new Database();
        database->openConnection();
        QSqlQuery sqlTable = database->getQuery();
        QString sql = "select * from file  ORDER BY updatedatetime DESC limit 10 offset 0;";
        sqlTable.prepare(sql);
        sqlTable.exec();
        m_model_3->setQuery(sqlTable);
    }
    else
    {
        m_model->setFilter(fiter);
        m_model->setSort(Constants::MACRO_INDEX_NO, Qt::AscendingOrder);
        m_model->select();
    }
    
    if (table == Constants::FILe_LIST_TABLE_NAME)
    {
        ui->tableView->setModel(m_model_3);
    }
    else
        ui->tableView->setModel(m_model);
        
    ui->tableView->setItemDelegate(m_managerDelegate);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setColumnHidden(Constants::MACRO_INDEX_UUID, true);
    
    if (table == Constants::FILe_LIST_TABLE_NAME)
    {
        ui->tableView->setColumnHidden(Constants::FILe_INDEX_CONTENT, true);
        ui->tableView->setColumnHidden(Constants::FILe_INDEX_NAME, false);
    }
    else
    {
        ui->tableView->setColumnHidden(Constants::MACRO_INDEX_NAME, false);
        ui->tableView->setColumnHidden(Constants::MACRO_INDEX_NO, true);
    }
    
    ui->tableView->setColumnHidden(Constants::MACRO_INDEX_CDATETIME, true);
    ui->tableView->setColumnHidden(Constants::MACRO_INDEX_UDATETIME, true);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->verticalHeader()->hide();
    QHeaderView* header = ui->tableView->horizontalHeader();
    header->resizeSection(Constants::MACRO_INDEX_SHOWPIX, 70);
    
    if (table == Constants::FILe_LIST_TABLE_NAME)
    {
        header->resizeSection(Constants::FILe_INDEX_NAME, 260);
    }
    else
        header->resizeSection(Constants::MACRO_INDEX_NAME, 260);
        
    ui->tableView->selectRow(0);
    ui->tableView->setFocus();
    m_model_2->setTable(table);
    
    if (table == Constants::FILe_LIST_TABLE_NAME)
    {
        Database* database = new Database();
        database->openConnection();
        QSqlQuery sqlTable = database->getQuery();
        QString sql = "select * from file  ORDER BY updatedatetime DESC limit 1000 offset 10;";
        sqlTable.prepare(sql);
        sqlTable.exec();
        m_model_4->setQuery(sqlTable);
        ui->tableView_2->setModel(m_model_4);
    }
    else
    {
        QString fiter2("no > 10");
        m_model_2->setFilter(fiter2);
        m_model_2->setSort(Constants::MACRO_INDEX_NO, Qt::AscendingOrder);
        m_model_2->select();
        ui->tableView_2->setModel(m_model_2);
    }
    
    ui->tableView_2->setItemDelegate(m_managerDelegate2);
    ui->tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_2->setColumnHidden(Constants::MACRO_INDEX_UUID, true);
    
    if (table == Constants::FILe_LIST_TABLE_NAME)
    {
        ui->tableView_2->setColumnHidden(Constants::FILe_INDEX_CONTENT, true);
        ui->tableView_2->setColumnHidden(Constants::FILe_INDEX_NAME, false);
    }
    else
    {
        ui->tableView_2->setColumnHidden(Constants::MACRO_INDEX_NAME, false);
        ui->tableView_2->setColumnHidden(Constants::MACRO_INDEX_NO, true);
    }
    
    ui->tableView_2->setColumnHidden(Constants::MACRO_INDEX_CDATETIME, true);
    ui->tableView_2->setColumnHidden(Constants::MACRO_INDEX_UDATETIME, true);
    ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_2->verticalHeader()->hide();
    QHeaderView* header2 = ui->tableView_2->horizontalHeader();
    header2->resizeSection(Constants::MACRO_INDEX_SHOWPIX, 70);
    
    if (table == Constants::FILe_LIST_TABLE_NAME)
    {
        header2->resizeSection(Constants::FILe_INDEX_NAME, 260);
    }
    else
        header2->resizeSection(Constants::MACRO_INDEX_NAME, 260);
}


/****************************************************************************
**
** 函数名称：CallCommunicationwidget::～CallCommunicationwidget
** 功能概述: 析构函数
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
CallCommunicationwidget::~CallCommunicationwidget()
{
    Logging::get()->info("CallCommunicationwidget::~CallCommunicationwidget");
    delete ui;
}

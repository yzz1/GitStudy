#include "frequencyview.h"
#include "ui_frequencyview.h"
#include "models/contactsmodel.h"
#include "core/utils/sqlitehelper.h"
#include "views/common/constants.h"
#include "views/contacts/contactsindstyle.h"
#include "models/contactsitemdelegate.h"
#include <QEvent>
#include <QKeyEvent>
#include "widgets/button.h"
#include "logging.h"
/****************************************************************************
**
** 函数名称：FrequencyView::FrequencyView
** 功能概述: 初始化
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
FrequencyView::FrequencyView(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::FrequencyView)
{
    Logging::get()->info("FrequencyView::FrequencyView");
    ui->setupUi(this);
    m_callOrReceive = true;
    this->installEventFilter(this);
    connect(ui->tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(activatedSlot(QModelIndex)));
    connect(ui->homeBtn, SIGNAL(clicked()), this, SLOT(homeClickedSlot()));
    connect(ui->okBtn, SIGNAL(clicked()), this, SLOT(okButtonClickedSlot()));
    connect(ui->cancelBtn, SIGNAL(clicked()), this, SLOT(cancelButtonClickedSlot()));
    connect(ui->receiveBtn, SIGNAL(clicked()), this, SLOT(receiveButtonClickedSlot()));
    connect(ui->callBtn, SIGNAL(clicked()), this, SLOT(callButtonClickedSlot()));
}
/****************************************************************************
**
** 函数名称：FrequencyView::activatedSlot
** 功能概述: 在Frequency数据库中选择频率后返回到CALL主界面
** 参数说明  index 选择的数据位置
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void FrequencyView::activatedSlot(QModelIndex index)
{
    Logging::get()->info("FrequencyView::activatedSlot");
    QMap <QString, QString> paraMap;
    int curRow = index.row();
    QString channel = ui->tableView->model()->index(curRow, 4).data().toString();
    QString tx = ui->tableView->model()->index(curRow, 5).data().toString();
    QString rx = ui->tableView->model()->index(curRow, 6).data().toString();
    paraMap.insert("name", m_name);
    paraMap.insert("callCode", m_callCode);
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
** 函数名称：FrequencyView::callButtonClickedSlot
** 功能概述: 选择主叫模式
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void FrequencyView:: callButtonClickedSlot()
{
    Logging::get()->info("FrequencyView::callButtonClickedSlot");
    ui->receiveBtn->setIcon(QIcon(":/images/images/Receive_Bnt_SelNo.png"));
    ui->callBtn->setIcon(QIcon(":/images/images/Call_Bnt_SelYes.png"));
    m_callOrReceive = 1;
}
/****************************************************************************
**
** 函数名称：FrequencyView::receiveButtonClickedSlot
** 功能概述: 选择被叫模式
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void FrequencyView:: receiveButtonClickedSlot()
{
    Logging::get()->info("FrequencyView::receiveButtonClickedSlot");
    ui->callBtn->setIcon(QIcon(":/images/images/Call_Bnt_SelNo.png"));
    ui->receiveBtn->setIcon(QIcon(":/images/images/Receive_Bnt_SelYes.png"));
    m_callOrReceive = 0;
}
/****************************************************************************
**
** 函数名称：FrequencyView::eventFilter
** 功能概述: 事件监听函数，响应用户键盘操作。
** 参数说明  watched：发送方， event：事件数据
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool FrequencyView::eventFilter(QObject* watched, QEvent* event)
{
    Logging::get()->info("FrequencyView::eventFilter");
    QStringList nameList;
    nameList << "tableView" << "okBtn" << "cancelBtn" << "homeBtn" << "callBtn" << "receiveBtn";
    QKeyEvent* key_event = static_cast<QKeyEvent*>(event);
    int a = key_event->key();

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

        // 默认键值51 响应一次
        int next = 0;
        bool inTableView = false;

        for (int i = 0; i < nameList.length(); i++)
        {
            QWidget* widget = findChild<QWidget*>(nameList.at(i));

            if (widget && widget->hasFocus())
            {
                // 如果焦点在table里，则焦点不切换
                if (nameList.at(i) == "tableView" && a == Qt::Key_Down)
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
                // 如果焦点在table里，则焦点不切换
                if (nameList.at(i) == "tableView" && a == Qt::Key_Up)
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
                else if (nameList.at(i) == "tableView")
                {
                    activatedSlot(ui->tableView->currentIndex());
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

        // 模拟cancel按钮点击事件
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
** 函数名称：FrequencyView::～FrequencyView
** 功能概述: 析构函数。
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
FrequencyView::~FrequencyView()
{
    Logging::get()->info("FrequencyView::~FrequencyView");
    delete ui;
}
/****************************************************************************
**
** 函数名称：FrequencyView::homeClickedSlot
** 功能概述: home按钮响应，跳转到主菜单。
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void FrequencyView:: homeClickedSlot()
{
    Logging::get()->info("FrequencyView::homeClickedSlot");
    QMap <QString, QString> paraMap;
    emit afterPageSignal(FREQUENCY_VIEW, HOME_VIEW_NAME, paraMap);
}
/****************************************************************************
**
** 函数名称：FrequencyView::okButtonClickedSlot
** 功能概述: OK按钮响应，跳转到CALL主菜单。
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void FrequencyView::okButtonClickedSlot()
{
    Logging::get()->info("FrequencyView::okButtonClickedSlot");
    QMap <QString, QString> paraMap;
    int curRow = ui->tableView->currentIndex().row();
    QString channel = ui->tableView->model()->index(curRow, 4).data().toString();
    QString tx = ui->tableView->model()->index(curRow, 5).data().toString();
    QString rx = ui->tableView->model()->index(curRow, 6).data().toString();
    paraMap.insert("name", m_name);
    paraMap.insert("callCode", m_callCode);
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
** 函数名称：FrequencyView::cancelButtonClickedSlot
** 功能概述: cancel按钮响应，返回到CALL主菜单。
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void FrequencyView::cancelButtonClickedSlot()
{
    Logging::get()->info("FrequencyView::cancelButtonClickedSlot");
    QMap <QString, QString> paraMap;
    QString forwardId = m_owner == "I" ? INDIVIDUAL_SELECT_VIEW : STATION_SELECT_VIEW;
    emit afterPageSignal(FREQUENCY_VIEW, forwardId , paraMap);
}
/****************************************************************************
**
** 函数名称：FrequencyView::frontPageSlot
** 功能概述: 打开页面时更新页面数据
** 参数说明： thisID：起始页面， fowordID：目标页面， paraMap：传递参数
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void  FrequencyView::frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap)
{
    if (fowordID != FREQUENCY_VIEW)
    {
        return;
    }

    Logging::get()->info("FrequencyView::frontPageSlot");
    m_name = paraMap["name"];
    m_owner = paraMap["type"];
    m_fkey = paraMap["uuid"];
    m_callCode = paraMap["callCode"];
    m_callOrReceive = paraMap[CALL_OR_RECEIVE].toInt();

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

    ui->titleWidget->setText(m_name);
    initTableView();
}
/****************************************************************************
**
** 函数名称：FrequencyView::initTableView
** 功能概述: 初始化，获取Frequency数据显示
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void FrequencyView::initTableView()
{
    Logging::get()->info("FrequencyView::initTableView");
    m_model = new ContactsModel(this, SQLiteHelper::openConnection());
    m_model->setTable(tr("frequency"));
    m_model->setSort(3, Qt::AscendingOrder);
    m_model->setHeaderData(4, Qt::Horizontal, tr("channel"));
    m_model->setHeaderData(5, Qt::Horizontal, tr("tx"));
    m_model->setHeaderData(6, Qt::Horizontal, tr("rx"));
    m_model->setFilter(tr("fkey = '%1' and ower = '%2' ").arg(m_fkey).arg(m_owner));
    m_model->select();
    ui->tableView->setModel(m_model);
    ContactsIndStyle* contactsIndStyle = new ContactsIndStyle();
    ContactsItemDelegate* contactsItemDelegate = new ContactsItemDelegate(0, contactsIndStyle);
    ui->tableView->setItemDelegate(contactsItemDelegate);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(1, true);
    ui->tableView->setColumnHidden(2, true);
    ui->tableView->setColumnHidden(3, true);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->horizontalHeader()->setResizeMode(4, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setResizeMode(5, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setResizeMode(6, QHeaderView::Stretch);
    ui->tableView->selectRow(0);
    ui->tableView->setFocus();
}

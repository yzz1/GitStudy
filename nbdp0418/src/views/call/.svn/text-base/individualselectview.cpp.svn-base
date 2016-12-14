#include "individualselectview.h"
#include "ui_individualselectview.h"
#include "views/common/constants.h"
#include "core/utils/sqlitehelper.h"
#include "views/contacts/contactsindstyle.h"
#include "models/contactsitemdelegate.h"
#include <QListWidgetItem>
#include <QEvent>
#include <QKeyEvent>
#include "widgets/button.h"
#include "logging.h"

/****************************************************************************
**
** 函数名称：IndividualSelectView::IndividualSelectView
** 功能概述: 初始化
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
IndividualSelectView::IndividualSelectView(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::IndividualSelectView)
{
    Logging::get()->info("IndividualSelectView::IndividualSelectView");
    ui->setupUi(this);
    ui->tiltewidget->setText(tr("CONTACTS  INDIVIDUAL"));
    this->installEventFilter(this);
    m_callOrReceive = true;
    m_model = new ContactsModel(this, SQLiteHelper::openConnection());
    m_model->setTable(tr("individual"));
    m_model->setSort(4, Qt::DescendingOrder);
    m_model->select();
    ui->tableView->setModel(m_model);
    ContactsIndStyle* contactsIndStyle = new ContactsIndStyle();
    ContactsItemDelegate* contactsItemDelegate = new ContactsItemDelegate(0, contactsIndStyle);
    contactsItemDelegate->setIndividualFlag(true);
    ui->tableView->setItemDelegate(contactsItemDelegate);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(3, true);
    ui->tableView->setColumnHidden(4, true);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->verticalHeader()->hide();
    QHeaderView* header = ui->tableView->horizontalHeader();
    header->resizeSection(1, 400);
    header->resizeSection(2, 400);
    header->setStretchLastSection(true);
    ui->tableView->selectRow(0);
    ui->tableView->setFocus();
    connect(ui->tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(activatedSlot(QModelIndex)));
    connect(ui->homeBtn, SIGNAL(clicked()), this, SLOT(homeClickedSlot()));
    connect(ui->okBtn, SIGNAL(clicked()), this, SLOT(okButtonClickedSlot()));
    connect(ui->cancelBtn, SIGNAL(clicked()), this, SLOT(cancelButtonClickedSlot()));
    connect(ui->receiveBtn, SIGNAL(clicked()), this, SLOT(receiveButtonClickedSlot()));
    connect(ui->callBtn, SIGNAL(clicked()), this, SLOT(callButtonClickedSlot()));
}
/****************************************************************************
**
** 函数名称：IndividualSelectView::callButtonClickedSlot
** 功能概述: 选择主叫模式
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void IndividualSelectView:: callButtonClickedSlot()
{
    ui->receiveBtn->setIcon(QIcon(":/images/images/Receive_Bnt_SelNo.png"));
    ui->callBtn->setIcon(QIcon(":/images/images/Call_Bnt_SelYes.png"));
    m_callOrReceive = 1;
}
/****************************************************************************
**
** 函数名称：IndividualSelectView::callButtonClickedSlot
** 功能概述: 选择被叫模式
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void IndividualSelectView:: receiveButtonClickedSlot()
{
    Logging::get()->info("IndividualSelectView::receiveButtonClickedSlot");
    ui->callBtn->setIcon(QIcon(":/images/images/Call_Bnt_SelNo.png"));
    ui->receiveBtn->setIcon(QIcon(":/images/images/Receive_Bnt_SelYes.png"));
    m_callOrReceive = 0;
}
/****************************************************************************
**
** 函数名称：IndividualSelectView::frontPageSlot
** 功能概述: 打开页面时更新页面数据
** 参数说明： thisID：起始页面， fowordID：目标页面， paraMap：传递参数
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void  IndividualSelectView::frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap)
{
    if (fowordID != INDIVIDUAL_SELECT_VIEW)
    {
        return;
    }

    Logging::get()->info("IndividualSelectView::frontPageSlot");
    m_model->select();
    ui->tableView->selectRow(0);
    ui->tableView->setFocus();
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
}
/****************************************************************************
**
** 函数名称：IndividualSelectView::eventFilter
** 功能概述: 事件监听函数，响应用户键盘操作。
** 参数说明：watched：发送方， event：事件数据
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool IndividualSelectView::eventFilter(QObject* watched, QEvent* event)
{
    Logging::get()->info("IndividualSelectView::eventFilter");
    QStringList nameList;
    nameList << "tableView" << "okBtn" << "cancelBtn" << "homeBtn" << "callBtn" << "receiveBtn";
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

             // 模拟homeBtn按钮点击事件
            if (widget && widget->hasFocus())
            {
                if (nameList.at(i) == "homeBtn")
                {
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                }
                // callBtn获得焦点
                else if (nameList.at(i) == "callBtn")
                {
                    ui->receiveBtn->setIcon(QIcon(":/images/images/Receive_Bnt_SelNo.png"));
                    ui->callBtn->setIcon(QIcon(":/images/images/Call_Bnt_SelYes.png"));
                    m_callOrReceive = !m_callOrReceive;
                }
                // receiveBtn获得焦点
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
** 函数名称：IndividualSelectView::～IndividualSelectView
** 功能概述: 析构函数。
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
IndividualSelectView::~IndividualSelectView()
{
    Logging::get()->info("IndividualSelectView::~IndividualSelectView");
    delete ui;
}
/****************************************************************************
**
** 函数名称：IndividualSelectView::homeClickedSlot
** 功能概述: home按钮响应，跳转到主菜单。
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void IndividualSelectView:: homeClickedSlot()
{
    Logging::get()->info("IndividualSelectView::homeClickedSlot");
    QMap <QString, QString> paraMap;
    emit afterPageSignal(INDIVIDUAL_SELECT_VIEW, HOME_VIEW_NAME, paraMap);
}
/****************************************************************************
**
** 函数名称：IndividualSelectView::okButtonClickedSlot
** 功能概述: 跳转到频率选择界面。
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void IndividualSelectView::okButtonClickedSlot()
{
    Logging::get()->info("IndividualSelectView::okButtonClickedSlot");
    QMap <QString, QString> paraMap;
    int curRow = ui->tableView->currentIndex().row();
    QString uuid = ui->tableView->model()->index(curRow, 0).data().toString();
    QString name = ui->tableView->model()->index(curRow, 1).data().toString();
    QString callCode = ui->tableView->model()->index(curRow, 2).data().toString();
    //currentItem->listWidget()
    paraMap.insert("uuid", uuid);
    paraMap.insert("name", name);
    paraMap.insert("type", "I");
    paraMap.insert("callCode", callCode);
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
    emit afterPageSignal(INDIVIDUAL_SELECT_VIEW, FREQUENCY_VIEW, paraMap);
}
/****************************************************************************
**
** 函数名称：IndividualSelectView::cancelButtonClickedSlot
** 功能概述: 返回到CALL主界面。
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void IndividualSelectView::cancelButtonClickedSlot()
{
    Logging::get()->info("IndividualSelectView::cancelButtonClickedSlot");
    QMap <QString, QString> paraMap;
    emit afterPageSignal(INDIVIDUAL_SELECT_VIEW, CALL_VIEW_NAME, paraMap);
}
/****************************************************************************
**
** 函数名称：IndividualSelectView::cancelButtonClickedSlot
** 功能概述: 跳转到频率选择页面。
** 参数说明：把选中的联系人数据保存传到下一个页面
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void IndividualSelectView::activatedSlot(QModelIndex index)
{
    Logging::get()->info("IndividualSelectView::activatedSlot");
    QMap <QString, QString> paraMap;
    int curRow = index.row();
    QString uuid = ui->tableView->model()->index(curRow, 0).data().toString();
    QString name = ui->tableView->model()->index(curRow, 1).data().toString();
    QString callCode = ui->tableView->model()->index(curRow, 2).data().toString();
    paraMap.insert("uuid", uuid);
    paraMap.insert("name", name);
    paraMap.insert("type", COMMON_OWER_INDIVIDUAL);
    paraMap.insert("callCode", callCode);
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
    emit afterPageSignal(INDIVIDUAL_SELECT_VIEW, FREQUENCY_VIEW, paraMap);
}

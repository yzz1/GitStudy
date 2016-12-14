#include "messagesshowview.h"
#include "ui_messagesshowview.h"
#include "core/utils/sqlitehelper.h"
#include "views/messages/messagesstyle.h"
#include "models/messagedetaildelegate.h"
#include "core/database/database.h"
#include <QClipboard>
#include <QSqlRecord>
#include <QUuid>
#include <QEvent>
#include <QKeyEvent>
#include "widgets/button.h"
#include <QDebug>
#include "logging.h"
#include "core/utils/commonutils.h"
/****************************************************************************
**
** 函数名称：MessagesShowView::MessagesShowView
** 功能概述: 初始化
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
MessagesShowView::MessagesShowView(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::MessagesShowView)
{
    Logging::get()->info("MessagesShowView::MessagesShowView");
    ui->setupUi(this);
    ui->contactsTiltewidget->setText(Constants::MESSAEGS_LIST_TITLE_INBOX);
    this->installEventFilter(this);
    m_strModle = Constants::MESSAEGS_LIST_INOUT_I;
    m_model = new MessagesModel(this, SQLiteHelper::openConnection());
    m_model->setTable(tr(Constants::MESSAEGS_SHOW_TABLE_NAME));
    m_model->setSort(Constants::MESSAEGSDETAIL_INDEX_CDATETIME, Qt::AscendingOrder);
    ui->tableView->setModel(m_model);
    MessagesStyle* style = new MessagesStyle();
    MessageDetailDelegate* messageDetailDelegate = new MessageDetailDelegate(0, style);
    QWidget* widget = findChild<QWidget*>("tableView");
    if (widget)
    {
        messageDetailDelegate->setTableWidget(widget);
    }
    ui->tableView->setItemDelegate(messageDetailDelegate);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setColumnHidden(Constants::MESSAEGSDETAIL_INDEX_UUID, true);
    ui->tableView->setColumnHidden(Constants::MESSAEGSDETAIL_INDEX_FKEY, true);
    ui->tableView->setColumnHidden(Constants::MESSAEGSDETAIL_INDEX_INOUT, true);
    ui->tableView->setColumnHidden(Constants::MESSAEGSDETAIL_INDEX_CDATETIME, true);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->verticalHeader()->hide();
    QHeaderView* header = ui->tableView->horizontalHeader();
    header->setStretchLastSection(true);
    ui->tableView->resizeRowsToContents();
    nameList << "tableView" << "copyBnt" << "printBnt" << "closeBnt" << "homeTBnt" << "inBoxTBnt";
    connect(ui->homeTBnt, SIGNAL(clicked()), this, SLOT(homeClickedSlot()));
    connect(ui->inBoxTBnt, SIGNAL(clicked()), this, SLOT(inBoxClickedSlot()));
    connect(ui->outBoxTBnt, SIGNAL(clicked()), this, SLOT(OutBoxClickedSlot()));
    connect(ui->closeBnt, SIGNAL(clicked()), this, SLOT(CloseClickedSlot()));
    connect(ui->copyBnt, SIGNAL(clicked()), this, SLOT(setClipboardContent()));
    connect(ui->printBnt, SIGNAL(clicked()), this, SLOT(printClickedSlot()));
}
/****************************************************************************
**
** 函数名称：MessagesShowView::printClickedSlot
** 功能概述: 打印处理
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessagesShowView:: printClickedSlot()
{
    Logging::get()->info("MessagesShowView::printClickedSlot");
    QString printStr;
    QString inOutFlag;

    if (m_strModle == Constants:: MESSAEGS_LIST_INOUT_I)
        inOutFlag = "I";
    else
        inOutFlag = "O";
    SQLiteHelper::printData(Constants::MESSAEGS_LIST_TABLE_NAME, printStr, inOutFlag, m_uuid);
}
/****************************************************************************
**
** 函数名称：MessagesShowView::eventFilter
** 功能概述: 事件监听函数，响应用户键盘操作
** 参数说明 watched：发送方， event：事件数据
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool MessagesShowView::eventFilter(QObject* watched, QEvent* event)
{
    Logging::get()->info("MessagesShowView::eventFilter");
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

                // 通过计算获得下一个控件的下标
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

                // 通过计算获得上一个控件的下标
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
                // 模拟copy按钮点击事件
                else if (nameList.at(i) == "copyBnt")
                {
                    QWidget* widget = findChild<QWidget*>("outBoxTBnt");
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                }
                // 模拟print按钮点击事件
                else if (nameList.at(i) == "printBnt")
                {
                    QWidget* widget = findChild<QWidget*>("outBoxTBnt");
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                }
                // 模拟close按钮点击事件
                else if (nameList.at(i) == "closeBnt")
                {
                    QWidget* widget = findChild<QWidget*>("outBoxTBnt");
                    Button* button = static_cast<Button*>(widget);
                    button->click();
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

        // 模拟close按钮点击事件
        QWidget* widget = findChild<QWidget*>("closeBnt");

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
** 函数名称：MessagesShowView::～MessagesShowView
** 功能概述: 析构函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
MessagesShowView::~MessagesShowView()
{
    Logging::get()->info("MessagesShowView:::~MessagesShowView");
    delete ui;
}
/****************************************************************************
**
** 函数名称：MessagesShowView::frontPageSlot
** 功能概述: 打开页面时更新页面数据
** 参数说明： thisID：起始页面， fowordID：目标页面， paraMap：传递参数
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void  MessagesShowView::frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap)
{
    if (fowordID != Constants::MESSAEGS_SHOW_VIEW_NAME) {return;}

    Logging::get()->info("MessagesShowView:::frontPageSlot");
    m_strModle = paraMap[COMMON_MODLE_NAME];
    ui->homeTBnt->setIcon(QIcon(":/images/home_normal"));

    if (m_strModle == Constants:: MESSAEGS_LIST_INOUT_I)
    {
        ui->outBoxTBnt->setIcon(QIcon(":/images/images/message_inBox_SelNo.png"));
        QIcon inboxIcon;
        inboxIcon.addPixmap(QPixmap(":/images/images/message_inBox_SelYes.png"), QIcon::Disabled);
        ui->inBoxTBnt->setIcon(inboxIcon);
        ui->contactsTiltewidget->setText(Constants::MESSAEGS_LIST_TITLE_INBOX);
        ui->outBoxTBnt->setEnabled(true);
        ui->outBoxTBnt->setText(tr("&OutBox"));
        ui->inBoxTBnt->setEnabled(false);
        ui->inBoxTBnt->setText(tr("InBox"));
        //<<"inBoxTBnt"<<"outBoxTBnt";
        nameList.removeLast();
        nameList.append("outBoxTBnt");
    }
    else
    {
        QIcon outboxIcon;
        outboxIcon.addPixmap(QPixmap(":/images/images/message_outBox_SelYes.png"), QIcon::Disabled);
        ui->outBoxTBnt->setIcon(outboxIcon);
        ui->inBoxTBnt->setIcon(QIcon(":/images/images/message_inBox_SelNo.png"));
        ui->contactsTiltewidget->setText(Constants::MESSAEGS_LIST_TITLE_OUTBOX);
        ui->outBoxTBnt->setEnabled(false);
        ui->outBoxTBnt->setText(tr("OutBox"));
        ui->inBoxTBnt->setEnabled(true);
        ui->inBoxTBnt->setText(tr("&InBox"));
        //<<"inBoxTBnt"<<"outBoxTBnt";
        nameList.removeLast();
        nameList.append("inBoxTBnt");
    }

    QString strUUID = paraMap[Constants::MESSAEGS_LIST_COL_UUID];
    QString strCallMode = paraMap[Constants::MESSAEGS_LIST_COL_MODE];
    QString strName = paraMap[Constants::MESSAEGS_LIST_COL_NAME];
    QString strTx = paraMap[Constants::MESSAEGS_LIST_COL_TX];
    QString strRx = paraMap[Constants::MESSAEGS_LIST_COL_RX];
    m_uuid = strUUID;
    ui->name->setText(CommonUtils::wordwrap(strName, Constants::NAME_LABEL_LENGTH));
    ui->callmode->setText(strCallMode);
    ui->tx->setText(strTx);
    ui->rx->setText(strRx);
    QString strMessageDetailFiter  = Constants:: MESSAEGS_SHOW_COL_FKEY;
    strMessageDetailFiter.append(" = '");
    strMessageDetailFiter.append(strUUID);
    strMessageDetailFiter.append("'");
    m_model->setFilter(strMessageDetailFiter);
    m_model->select();
    ui->tableView->setFocus();
    ui->tableView->selectRow(0);
    setTableViewRowHeight();
}
/****************************************************************************
**
** 函数名称：MessagesShowView::homeClickedSlot
** 功能概述: 返回主菜单
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessagesShowView:: homeClickedSlot()
{
    Logging::get()->info("MessagesShowView:::homeClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(Constants::MESSAEGS_SHOW_VIEW_NAME, HOME_VIEW_NAME, paraMap);
}
/****************************************************************************
**
** 函数名称：MessagesShowView::inBoxClickedSlot
** 功能概述: 跳转到inbox界面
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessagesShowView:: inBoxClickedSlot()
{
    Logging::get()->info("MessagesShowView:::inBoxClickedSlot");
    QMap <QString, QString>paraMap;
    paraMap.insert(COMMON_MODLE_NAME, Constants::MESSAEGS_LIST_INOUT_I);
    emit afterPageSignal(Constants::MESSAEGS_SHOW_VIEW_NAME, Constants::MESSAEGS_LIST_VIEW_NAME, paraMap);
}
/****************************************************************************
**
** 函数名称：MessagesShowView::OutBoxClickedSlot
** 功能概述: 跳转到outbox界面
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessagesShowView:: OutBoxClickedSlot()
{
    Logging::get()->info("MessagesShowView:::OutBoxClickedSlot");
    QMap <QString, QString>paraMap;
    paraMap.insert(COMMON_MODLE_NAME, Constants::MESSAEGS_LIST_INOUT_O);
    emit afterPageSignal(Constants::MESSAEGS_SHOW_VIEW_NAME, Constants::MESSAEGS_LIST_VIEW_NAME, paraMap);
}
/****************************************************************************
**
** 函数名称：MessagesShowView::CloseClickedSlot
** 功能概述: 返回到上一层界面
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessagesShowView::CloseClickedSlot()
{
    Logging::get()->info("MessagesShowView:::CloseClickedSlot");
    QMap <QString, QString>paraMap;

    if (m_strModle == Constants:: MESSAEGS_LIST_INOUT_I)
    {
        paraMap.insert(COMMON_MODLE_NAME, Constants::MESSAEGS_LIST_INOUT_I);
    }
    else
    {
        paraMap.insert(COMMON_MODLE_NAME, Constants::MESSAEGS_LIST_INOUT_O);
    }

    emit afterPageSignal(Constants::MESSAEGS_SHOW_VIEW_NAME, Constants::MESSAEGS_LIST_VIEW_NAME, paraMap);
}
/****************************************************************************
**
** 函数名称：MessagesShowView::setClipboardContent
** 功能概述: copy功能
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessagesShowView:: setClipboardContent()
{
    Logging::get()->info("MessagesShowView:::setClipboardContent");
    QClipboard* board = QApplication::clipboard();
    int curRow = ui->tableView->currentIndex().row();
    QModelIndex index = ui->tableView->currentIndex();
    QString strContent = index.sibling(curRow, Constants::MESSAEGSDETAIL_INDEX_CONTENT).data().toString();
    board->setText(strContent);
}
/****************************************************************************
**
** 函数名称：MessagesShowView::setTableViewRowHeight
** 功能概述: 自动换行
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessagesShowView::setTableViewRowHeight()
{
    Logging::get()->info("MessagesShowView:::setTableViewRowHeight");
    int rowCount = m_model->rowCount() ;

    for (int rowIndex = 0; rowIndex < rowCount; rowIndex++)
    {
        QSqlRecord  sqlRecord = m_model->record(rowIndex);
        QString strContens = sqlRecord.value(Constants::MESSAEGS_SHOW_COL_CONTENT).toString();
        int rowHeight = 1;
        QString showText = "" ;
        QString showTextTmp = strContens; //neirongyaoxianfasong,ran hou xianshi

        for (int pos = 0; pos < showTextTmp.length()  ;)
        {
            if (showTextTmp.at(pos) == '\n'  || showTextTmp.at(pos) == '\r')
            {
                rowHeight = rowHeight + 1;
            }

            pos  = pos + 1;
        }

        ui->tableView->setRowHeight(rowIndex, rowHeight * Constants::COMMUMESSAEGS_SHOW_ROW_HIGHT);
    }

    ui->tableView->scrollToTop();
}

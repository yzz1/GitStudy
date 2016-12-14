#include "individualfrequencyview.h"
#include "ui_individualfrequencyview.h"
#include "models/contactsmodel.h"
#include "core/utils/sqlitehelper.h"
#include "views/common/constants.h"
#include "views/contacts/contactsindstyle.h"
#include "models/contactsitemdelegate.h"
/****************************************************************************
**
** 函数名称：IndividualFrequencyView::IndividualFrequencyView
** 功能概述: 初始化
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
IndividualFrequencyView::IndividualFrequencyView(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::IndividualFrequencyView)
{
    ui->setupUi(this);
    this->installEventFilter(this);
    connect(ui->homeBtn, SIGNAL(clicked()), this, SLOT(homeClickedSlot()));
    connect(ui->okBtn, SIGNAL(clicked()), this, SLOT(okButtonClickedSlot()));
    connect(ui->cancelBtn, SIGNAL(clicked()), this, SLOT(cancelButtonClickedSlot()));
}
/****************************************************************************
**
** 函数名称：IndividualFrequencyView::~IndividualFrequencyView
** 功能概述: 析构函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
IndividualFrequencyView::~IndividualFrequencyView()
{
    delete ui;
}
/****************************************************************************
**
** 函数名称：IndividualFrequencyView::homeClickedSlot
** 功能概述: home按钮响应，跳转到主菜单。
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void IndividualFrequencyView:: homeClickedSlot()
{
    QMap <QString, QString> paraMap;
    emit afterPageSignal(INDIVIDUAL_FREQUENCY_VIEW, HOME_VIEW_NAME, paraMap);
}
/****************************************************************************
**
** 函数名称：IndividualFrequencyView::okButtonClickedSlot
** 功能概述: 跳转到频率选择界面。
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void IndividualFrequencyView::okButtonClickedSlot()
{
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
    emit afterPageSignal(INDIVIDUAL_FREQUENCY_VIEW, CALL_VIEW_NAME, paraMap);
}
/****************************************************************************
**
** 函数名称：IndividualFrequencyView::cancelButtonClickedSlot
** 功能概述: 返回到CALL主界面。
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void IndividualFrequencyView::cancelButtonClickedSlot()
{
    QMap <QString, QString> paraMap;
    emit afterPageSignal(INDIVIDUAL_FREQUENCY_VIEW, INDIVIDUAL_SELECT_VIEW, paraMap);
}
/****************************************************************************
**
** 函数名称：IndividualFrequencyView::frontPageSlot
** 功能概述: 打开页面时更新页面数据
** 参数说明： thisID：起始页面， fowordID：目标页面， paraMap：传递参数
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void  IndividualFrequencyView::frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap)
{
    if (fowordID != INDIVIDUAL_FREQUENCY_VIEW)
    {
        return;
    }
    
    m_name = paraMap["name"];
    m_owner = paraMap["type"];
    m_fkey = paraMap["uuid"];
    m_callCode = paraMap["callCode"];
    ui->titleWidget->setText(m_name);
    initTableView();
}
/****************************************************************************
**
** 函数名称：IndividualFrequencyView::initTableView
** 功能概述: 初始化，显示联系人列表
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void IndividualFrequencyView::initTableView()
{
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

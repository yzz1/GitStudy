#include <QtCore>
#include <QLabel>
#include <QIcon>
#include "contactsmodel.h"

/****************************************************************************
**
** ContactsModel::ContactsModel
** 功能概述: 构造函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ContactsModel::ContactsModel(QObject* parent , QSqlDatabase db)
    : QSqlTableModel(parent, db)
{
    m_alignMentFlag = Qt::AlignCenter;
}

/****************************************************************************
**
** ContactsModel::data
** 功能概述: 获取单元格数据函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QVariant ContactsModel::data(const QModelIndex& index, int role) const
{
    QVariant value = QSqlTableModel::data(index, role);

    if (role == Qt::TextAlignmentRole)
    {
        value = int(m_alignMentFlag);
        return value;
    }

    return value;
}

/****************************************************************************
**
** ContactsModel::data
** 功能概述: 设置单元格对齐函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ContactsModel::setAlignment(const Qt::Alignment flag)
{
    m_alignMentFlag = flag;
}

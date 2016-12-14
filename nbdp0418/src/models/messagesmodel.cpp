#include "messagesmodel.h"

/****************************************************************************
**
** MessagesModel::MessagesModel
** 功能概述: 构造函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
MessagesModel::MessagesModel(QObject* parent , QSqlDatabase db)
    : QSqlTableModel(parent, db)
{
}

/****************************************************************************
**
** MessagesModel::data
** 功能概述: 获取单元格数据函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QVariant MessagesModel::data(const QModelIndex& index, int role) const
{
    QVariant value = QSqlTableModel::data(index, role);

    if (role == Qt::TextAlignmentRole)
    {
        value = Qt::AlignLeft;
        return value;
    }

    return value;
}
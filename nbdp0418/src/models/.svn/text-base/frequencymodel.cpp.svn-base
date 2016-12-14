#include "frequencymodel.h"

/****************************************************************************
**
** FrequencyModel::FrequencyModel
** 功能概述: 构造函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
FrequencyModel::FrequencyModel(QObject* parent , QSqlDatabase db)
    : QSqlTableModel(parent, db)
{
}

/****************************************************************************
**
** FrequencyModel::data
** 功能概述: 获取某一行数据函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QVariant FrequencyModel::data(const QModelIndex& index, int role) const
{
    QVariant value = QSqlTableModel::data(index, role);

    if (role == Qt::TextAlignmentRole)
    {
        return Qt::AlignCenter;
    }

    return value;
}

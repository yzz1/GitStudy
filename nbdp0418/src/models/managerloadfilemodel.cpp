#include "managerloadfilemodel.h"
#include <QtCore>
#include <QLabel>
#include <QIcon>
#include "views/common/constants.h"

/****************************************************************************
**
** ManagerLoadFileModel::ManagerLoadFileModel
** 功能概述: 构造函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ManagerLoadFileModel::ManagerLoadFileModel(QObject* parent)
    : QSqlQueryModel(parent)
{
}

/****************************************************************************
**
** ManagerLoadFileModel::data
** 功能概述: 获取某行数据函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QVariant ManagerLoadFileModel::data(const QModelIndex& index, int role) const
{
    QVariant value;

    if (role == Qt::TextAlignmentRole)
    {
        return value = int(Qt::AlignHCenter | Qt::AlignVCenter);
    }
    else
    {
        value = QSqlQueryModel::data(index, role);
    }

    return value;
}

/****************************************************************************
**
** ManagerLoadFileModel::setQuery
** 功能概述: 设置查询语句函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerLoadFileModel::setQuery(const QSqlQuery& query)
{
    QSqlQueryModel::setQuery(query);
}
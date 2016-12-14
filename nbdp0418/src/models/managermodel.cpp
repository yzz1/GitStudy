#include "managermodel.h"
#include <QtCore>
#include <QLabel>
#include <QIcon>
#include "views/common/constants.h"

/****************************************************************************
**
** ManagerModel::ManagerModel
** 功能概述: 构造函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ManagerModel::ManagerModel(QObject* parent , QSqlDatabase db)
    : QSqlTableModel(parent, db)
{
}

/****************************************************************************
**
** ManagerModel::data
** 功能概述: 获取某行数据函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QVariant ManagerModel::data(const QModelIndex& index, int role) const
{
    QVariant value;

    if ((index.column() == Constants::PHRASEBOOK_INDEX_NO) && role == Qt::TextAlignmentRole)
    {
        return value = int(Qt::AlignLeft | Qt::AlignVCenter);
    }

    if ((index.column() == Constants::PHRASEBOOK_INDEX_CONTENT) && role == Qt::TextAlignmentRole)
    {
        return value = int(Qt::AlignCenter | Qt::AlignVCenter);
    }
    else  if (index.column() == Constants::PHRASEBOOK_INDEX_NO  && role == Qt::DisplayRole)
    {
        QString strNum =  QSqlTableModel::data(index, role).toString();
        strNum = Constants::PHRASEBOOK_LIST_NODOT  + strNum;
        value = (strNum);
    }
    else
    {
        value = QSqlTableModel::data(index, role);
    }

    return value;
}
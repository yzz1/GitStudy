#include "filemodels.h"
#include <QtCore>
#include <QLabel>
#include <QIcon>
#include "views/common/constants.h"

/****************************************************************************
**
** FileModels::FileModels
** 功能概述: 构造函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
FileModels::FileModels(QObject* parent , QSqlDatabase db)
    : QSqlTableModel(parent, db)
{
}

/****************************************************************************
**
** FileModels::FileModels
** 功能概述: 获取某行数据函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QVariant FileModels::data(const QModelIndex& index, int role) const
{
    QVariant value;

    if ((index.column() == Constants::FILe_INDEX_NAME  || index.column() == Constants::FILe_INDEX_UDATETIME)
        && role == Qt::TextAlignmentRole)
    {
        return value = int(Qt::AlignLeft | Qt::AlignVCenter);
    }
    else  if (index.column() == Constants::FILe_INDEX_UDATETIME  && role == Qt::DisplayRole)
    {
        QDateTime dtval =  QSqlTableModel::data(index, role).toDateTime();
        QString strDateTime = tr("Date not set");

        if (dtval.isValid())
        {
            strDateTime = dtval.toString(COMMON_DATETIME_FORMAT);
        }

        value = (strDateTime);
    }
    else
    {
        value = QSqlTableModel::data(index, role);
    }

    return value;
}

/****************************************************************************
**
** FileModels::flags
** 功能概述: 获取某行标志函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
Qt::ItemFlags FileModels::flags(const QModelIndex& index) const
{
    if (index.column() == Constants::FILe_INDEX_UDATETIME)
    {
        return Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable;
    }
    else
    {
        return QSqlTableModel::flags(index);
    }
}

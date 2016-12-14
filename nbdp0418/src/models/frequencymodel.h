/****************************************************************************
**
** 文件名称： frequencymodel.h
** 功能概述: 频率列表Model类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef FREQUENCYMODEL_H
#define FREQUENCYMODEL_H

#include <QSqlTableModel>

class FrequencyModel : public QSqlTableModel
{
        Q_OBJECT
    public:
        FrequencyModel(QObject* parent = 0, QSqlDatabase db = QSqlDatabase());
        
        QVariant data(const QModelIndex& index, int role) const;
        
    protected:
};

#endif // FREQUENCYMODEL_H

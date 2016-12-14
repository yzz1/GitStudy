/****************************************************************************
**
** 文件名称： managerloadfilemodel.h
** 功能概述: 导入文件列表Model类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef MANAGERLOADFILEMODEL_H
#define MANAGERLOADFILEMODEL_H

#include <QSqlTableModel>
#include <QStringList>
#include <QVector>

class ManagerLoadFileModel: public QSqlQueryModel
{
        Q_OBJECT
        
    public:
        ManagerLoadFileModel(QObject* parent = 0);
        QVariant data(const QModelIndex& index, int role) const;
        void setQuery(const QSqlQuery& query);
};
#endif // MANAGERLOADFILEMODEL_H

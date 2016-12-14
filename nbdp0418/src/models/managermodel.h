/****************************************************************************
**
** 文件名称： managermodel.h
** 功能概述: 文件管理列表Model类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef MANAGERMODEL_H
#define MANAGERMODEL_H
#include <QSqlTableModel>
#include <QStringList>
#include <QVector>

class  ManagerModel: public QSqlTableModel
{
        Q_OBJECT
        
    public:
        ManagerModel(QObject* parent = 0, QSqlDatabase db = QSqlDatabase());
        QVariant data(const QModelIndex& index, int role) const;
};

#endif // MANAGERMODEL_H
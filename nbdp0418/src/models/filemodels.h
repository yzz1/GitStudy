/****************************************************************************
**
** 文件名称： filemodels.h
** 功能概述: 文件列表Model类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef FILEMODELS_H
#define FILEMODELS_H

#include <QSqlTableModel>
#include <QStringList>
#include <QVector>

class  FileModels: public QSqlTableModel
{
        Q_OBJECT
        
    public:
        FileModels(QObject* parent = 0, QSqlDatabase db = QSqlDatabase());
        QVariant data(const QModelIndex& index, int role) const;
        Qt::ItemFlags flags(const QModelIndex& index) const;
};

#endif // FILEMODELS_H

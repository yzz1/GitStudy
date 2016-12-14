/****************************************************************************
**
** 文件名称： messagesmodel.h
** 功能概述: 消息列表Model类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef MESSAGESMODEL_H
#define MESSAGESMODEL_H

#include <QSqlTableModel>
#include <QStringList>
#include <QVector>

class  MessagesModel: public QSqlTableModel
{
        Q_OBJECT
    public:
        MessagesModel(QObject* parent = 0, QSqlDatabase db = QSqlDatabase());
        QVariant data(const QModelIndex& index, int role) const;
};


#endif // MESSAGESMODEL_H

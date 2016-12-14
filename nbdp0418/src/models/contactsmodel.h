/****************************************************************************
**
** 文件名称： contactsmodel.h
** 功能概述: 联系人列表Model类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef CONTACTSMODEL_H
#define CONTACTSMODEL_H

#include <QtSql/QSqlTableModel>
#include <QStringList>
#include <QVector>

class  ContactsModel: public QSqlTableModel
{
        Q_OBJECT
        
    public:
        ContactsModel(QObject* parent = 0, QSqlDatabase db = QSqlDatabase());
        QVariant data(const QModelIndex& index, int role) const;
        void  setAlignment(const Qt::Alignment flag);
    protected:
        void reset() { QSqlTableModel::reset() ;}
        Qt::Alignment m_alignMentFlag;
        
};

#endif // CONTACTSMODEL_H

/****************************************************************************
**
** 文件名称： frequencyitemdelegate.h
** 功能概述: 频率列表Delegate类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef FREQUENCYITEMDELEGATE_H
#define FREQUENCYITEMDELEGATE_H

#include <QStyledItemDelegate>

class FrequencyItemDelegate : public QStyledItemDelegate
{
    public:
        FrequencyItemDelegate(QObject* parent = 0);
        
        void paint(QPainter* painter,
                   const QStyleOptionViewItem& option, const QModelIndex& index) const;
                   
        QWidget* createEditor(QWidget* parent,
                              const QStyleOptionViewItem& option,
                              const QModelIndex& index) const;
                              
        void setEditorData(QWidget* editor, const QModelIndex& index) const;
};

#endif // FREQUENCYITEMDELEGATE_H

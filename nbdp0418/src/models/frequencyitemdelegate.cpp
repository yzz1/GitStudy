#include "frequencyitemdelegate.h"
#include <QLineEdit>
#include <QApplication>
#include <QPainter>

/****************************************************************************
**
** FrequencyItemDelegate::FrequencyItemDelegate
** 功能概述: 构造函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
FrequencyItemDelegate::FrequencyItemDelegate(QObject* parent)
    : QStyledItemDelegate(parent)
{
}

/****************************************************************************
**
** FrequencyItemDelegate::createEditor
** 功能概述: 创建编辑框函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QWidget* FrequencyItemDelegate::createEditor(QWidget* parent,
        const QStyleOptionViewItem& item,
        const QModelIndex& index) const
{
    QLineEdit* inputText = new QLineEdit(parent);
    inputText->setFrame(false);
    inputText->setAlignment(Qt::AlignCenter);
    return inputText;
}

/****************************************************************************
**
** FrequencyItemDelegate::setEditorData
** 功能概述: 设置编辑框数据函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void FrequencyItemDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const
{
    QStyledItemDelegate::setEditorData(editor, index);
}

/****************************************************************************
**
** FrequencyItemDelegate::paint
** 功能概述: 绘图函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void FrequencyItemDelegate::paint(QPainter* painter,
                                  const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    const QRect rect(option.rect);
    painter->drawRect(rect.adjusted(20, 5, -20, -5));
    QStyledItemDelegate::paint(painter, option, index);
}

#include "contactsitemdelegate.h"
#include <QPainter>
#include <QString>
#include <QFont>
#include <QRectF>

/****************************************************************************
**
** 函数名称：ContactsItemDelegate::ContactsItemDelegate
** 功能概述: 构造函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ContactsItemDelegate::ContactsItemDelegate(QObject* parent, ContactsStyle* contactsStyle)
    : QItemDelegate(parent)
{
    m_contactsStyle = contactsStyle;
    m_individualFlag = false;
}

/****************************************************************************
**
** 函数名称：ContactsItemDelegate::paint
** 功能概述: 绘图函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ContactsItemDelegate::paint(QPainter* painter,
                                 const QStyleOptionViewItem& option,
                                 const QModelIndex& index) const
{
    QStyleOptionViewItem editOption;
    editOption = option;
    QPixmap pixmap;
    QFont  tempFont(option.font);
    QPen tempPen ;
    QFont oldFont(painter->font());
    QPen oldPen(painter->pen());
    pixmap = QPixmap(m_contactsStyle->getNoSelectedPixmap());
    tempPen = painter->pen();
    tempFont = editOption.font;

    //选中的场合 背景色变化
    if (option.showDecorationSelected && (option.state & QStyle::State_Selected))
    {
        QPalette::ColorGroup cg = option.state & QStyle::State_Enabled
                                  ? QPalette::Normal : QPalette::Disabled;

        if (cg == QPalette::Normal && !(option.state & QStyle::State_Active))
            cg = QPalette::Inactive;

        pixmap = QPixmap(m_contactsStyle->getSelectedPixmap());
        tempFont.setPixelSize(m_contactsStyle->getSelectedFontSize());
        editOption.font = tempFont;
        tempPen = QPen(QColor(m_contactsStyle->getSelectedFontColor()));
        painter->fillRect(option.rect, option.palette.brush(cg, QPalette::Highlight));
    }
    else
    {
        QVariant value = index.data(Qt::BackgroundRole);

        if (value.canConvert<QBrush>())
        {
            QPointF oldBO = painter->brushOrigin();
            painter->setBrushOrigin(option.rect.topLeft());
            painter->fillRect(option.rect, qvariant_cast<QBrush>(value));
            painter->setBrushOrigin(oldBO);
        }
    }

    painter->setPen(tempPen);
    painter->setFont(tempFont);

    // 画图标
    if (index.column() == m_contactsStyle->getPixmapColummIndex())
    {
        const QAbstractItemModel* model = index.model();
        int width = pixmap.width();
        int height = pixmap.height();
        QRect rect = option.rect;
        int x;

        if (m_individualFlag)
        {
            x = rect.x() + 50;
        }
        else
        {
            x = rect.x() + 20;
        }

        int y = rect.y() + rect.height() / 2 - height / 2;
        painter->drawPixmap(x, y, pixmap);
        QString strColumnValueName;
        strColumnValueName = model->data(index, Qt::DisplayRole).toString();
        QRectF textrect(x + width + 10, rect.y(), rect.width() - width - 30, rect.height());
        painter->drawText(textrect, Qt::AlignLeft | Qt::AlignVCenter, strColumnValueName);
    }
    else
    {
        QString  strColumnValue = index.data(Qt::DisplayRole).toString();
        //绘制文本
        painter->drawText(editOption.rect, Qt::AlignCenter, strColumnValue);
    }

    painter->setFont(oldFont);//字体
    painter->setPen(oldPen);
}

/****************************************************************************
**
** 函数名称：ContactsItemDelegate::drawFocus
** 功能概述: 焦点绘制函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ContactsItemDelegate::drawFocus(QPainter* painter,
                                     const QStyleOptionViewItem& option,
                                     const QRect& rect) const
{
}

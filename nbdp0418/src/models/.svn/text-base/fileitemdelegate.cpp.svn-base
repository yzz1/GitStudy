#include "fileitemdelegate.h"
#include "views/common/constants.h"
#include <QPainter>
#include <QString>
#include <QFont>
#include <QRectF>
#include <QDateTime>
#include <QStyleOptionButton>
#include <QApplication>
#include <QLineEdit>

/****************************************************************************
**
** FileItemDelegate::FileItemDelegate
** 功能概述: 构造函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
FileItemDelegate::FileItemDelegate(QObject* parent, ManagerFileStyle* style)
    : QItemDelegate(parent)
{
    m_style = style;
    m_intEditRow = -1;
    m_intEditCol   = -1;
}

/****************************************************************************
**
** FileItemDelegate::paint
** 功能概述: 绘图函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void FileItemDelegate::paint(QPainter* painter,
                             const QStyleOptionViewItem& option,
                             const QModelIndex& index) const
{
    QStyleOptionViewItem editOption;
    editOption = option;
    QPixmap pixmap;
    QFont  tempFont(option.font);

    //选中的场合 背景色变化
    if (option.state & QStyle::State_Selected)
    {
        if (index.column() == m_style->getPixmapColummIndex())
        {
            pixmap = QPixmap(m_style->getSelectedPixmap());
        }

        tempFont.setPixelSize(m_style->getSelectedFontSize());
        editOption.font = tempFont;
    }
    else
    {
        if (index.column() == m_style->getPixmapColummIndex())
        {
            pixmap = QPixmap(m_style->getNoSelectedPixmap());
        }
    }

    // 画图标
    if (index.column() == m_style->getPixmapColummIndex())
    {
        if (option.showDecorationSelected && (option.state & QStyle::State_Selected))
        {
            QPalette::ColorGroup cg = option.state & QStyle::State_Enabled
                                      ? QPalette::Normal : QPalette::Disabled;

            if (cg == QPalette::Normal && !(option.state & QStyle::State_Active))
                cg = QPalette::Inactive;

            painter->fillRect(editOption.rect, editOption.palette.brush(cg, QPalette::Highlight));
        }
        else
        {
            QVariant value = index.data(Qt::BackgroundRole);

            if (value.canConvert<QBrush>())
            {
                QPointF oldBO = painter->brushOrigin();
                painter->setBrushOrigin(editOption.rect.topLeft());
                painter->fillRect(editOption.rect, qvariant_cast<QBrush>(value));
                painter->setBrushOrigin(oldBO);
            }
        }

        const QAbstractItemModel* model = index.model();
        int width = pixmap.width();
        int height = pixmap.height();
        QRect rect = editOption.rect;
        int x = rect.width() - width - rect.width() / 8;
        int y = rect.y() + rect.height() / 2 - height / 2;
        painter->drawPixmap(x, y, pixmap);
    }

    // 文件名编辑是背景色的变化
    else if ((index.column() == Constants::FILe_INDEX_NAME)
             && (option.state & QStyle::State_Selected) &&  m_intEditRow == index.row())
    {
        QPalette::ColorGroup cg = option.state & QStyle::State_Enabled
                                  ? QPalette::Normal : QPalette::Disabled;

        if (cg == QPalette::Normal && !(option.state & QStyle::State_Active))
            cg = QPalette::Inactive;

        painter->fillRect(editOption.rect, editOption.palette.brush(cg, QPalette::Highlight));
    }
    else  //父类填充
    {
        QItemDelegate::paint(painter, editOption, index);
    }
}

/****************************************************************************
**
** FileItemDelegate::drawFocus
** 功能概述: 焦点绘制函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void FileItemDelegate::drawFocus(QPainter* painter,
                                 const QStyleOptionViewItem& option,
                                 const QRect& rect) const
{
}

#include "messagesitemdelegate.h"
#include "views/common/constants.h"
#include <QPainter>
#include <QString>
#include <QFont>
#include <QRectF>
#include <QDateTime>
#include <QStyleOptionButton>
#include <QApplication>

/****************************************************************************
**
** MessagesItemDelegate::MessagesItemDelegate
** 功能概述: 构造函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
MessagesItemDelegate::MessagesItemDelegate(QObject* parent, MessagesStyle* style)
    : QItemDelegate(parent)
{
    m_style = style;
}

/****************************************************************************
**
** MessagesItemDelegate::paint
** 功能概述: 绘图函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessagesItemDelegate::paint(QPainter* painter,
                                 const QStyleOptionViewItem& option,
                                 const QModelIndex& index) const
{
    QStyleOptionViewItem editOption;
    editOption = option;
    QPixmap pixmap;
    QFont  tempFont(option.font);
    // 选中的场合，字体颜色变化
    if (editOption.state & QStyle::State_Selected)
    {
        tempFont.setPixelSize(m_style->getSelectedFontSize());
        editOption.font = tempFont;
    }

    // 时间显示方式排版
    if (m_style->getDateFormatColIndex() != -1 &&  index.column() ==  m_style->getDateFormatColIndex())
    {
        QDateTime dtval = index.data(Qt::DisplayRole).toDateTime();
        QString strDateTime = tr("Date not set");

        if (dtval.isValid())
        {
            strDateTime = dtval.toString(m_style->getDateFormat());
        }

        //获取项风格设置
        editOption.displayAlignment = Qt::AlignLeft | Qt::AlignVCenter;
        //绘制文本
        drawDisplay(painter, editOption, editOption.rect, strDateTime);
    }
    // check  图标显示方式变化
    else if (index.column() == Constants::MESSAEGS_INDEX_CHECKFLAG)
    {
        int  intCheckFlag = index.data(Qt::DisplayRole).toInt();

        if (editOption.showDecorationSelected && (editOption.state & QStyle::State_Selected))
        {
            if (intCheckFlag == 1)
            {
                pixmap =  QPixmap(m_style->getCheckSelYesPixmap());
            }
            else
            {
                pixmap =  QPixmap(m_style->getCheckSelNoPixmap());
            }

            QPalette::ColorGroup cg = editOption.state & QStyle::State_Enabled
                                      ? QPalette::Normal : QPalette::Disabled;

            if (cg == QPalette::Normal && !(editOption.state & QStyle::State_Active))
                cg = QPalette::Inactive;

            painter->fillRect(editOption.rect, editOption.palette.brush(cg, QPalette::Highlight));
        }
        else
        {
            if (intCheckFlag == 1)
            {
                pixmap =  QPixmap(m_style->getCheckYesPixmap());
            }
            else
            {
                pixmap =  QPixmap(m_style->getCheckNoPixmap());
            }

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
        int x = rect.x() + rect.width() / 2 - width / 2;
        int y = rect.y() + rect.height() / 2 - height / 2;
        painter->drawPixmap(x, y, pixmap);
    }
    // 信封图标显示方式变化
    else if (index.column() == m_style->getPixmapColummIndex())
    {
        QString  strColumnValue;
        strColumnValue = index.data(Qt::DisplayRole).toString();

        if (editOption.showDecorationSelected && (editOption.state & QStyle::State_Selected))
        {
            if (strColumnValue == Constants::MESSAEGS_LIST_MESSAGE_READED_FLAG)
            {
                pixmap = QPixmap(m_style->getReadedSelYesPixmap());
            }
            else
            {
                pixmap = QPixmap(m_style->getSelectedPixmap());
            }

            QPalette::ColorGroup cg = editOption.state & QStyle::State_Enabled
                                      ? QPalette::Normal : QPalette::Disabled;

            if (cg == QPalette::Normal && !(editOption.state & QStyle::State_Active))
                cg = QPalette::Inactive;

            painter->fillRect(editOption.rect, editOption.palette.brush(cg, QPalette::Highlight));
        }
        else
        {
            // 信封是否已读
            if (strColumnValue == Constants::MESSAEGS_LIST_MESSAGE_READED_FLAG)
            {
                pixmap = QPixmap(m_style->getReadedSelNoPixmap());
            }
            else
            {
                pixmap = QPixmap(m_style->getNoSelectedPixmap());
            }

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
        int x = rect.x() + rect.width() / 2 - width / 2;
        int y = rect.y() + rect.height() / 2 - height / 2;
        painter->drawPixmap(x, y, pixmap);
    }
    else if (index.column() ==  Constants::MESSAEGS_INDEX_NAME)
    {
        QString  strColumnValue = index.data(Qt::DisplayRole).toString();
        editOption.displayAlignment = Qt::AlignLeft | Qt::AlignVCenter;
        //绘制文本
        drawDisplay(painter, editOption, editOption.rect, strColumnValue);
    }
    else
    {
        QItemDelegate::paint(painter, editOption, index);
    }
}

/****************************************************************************
**
** MessagesItemDelegate::drawFocus
** 功能概述: 绘制焦点函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessagesItemDelegate::drawFocus(QPainter* painter,
                                     const QStyleOptionViewItem& option,
                                     const QRect& rect) const
{
}

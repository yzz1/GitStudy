#include "messagedetaildelegate.h"
#include "views/common/constants.h"
#include <QPainter>
#include <QString>
#include <QFont>
#include <QRectF>
#include <QDateTime>
#include <QStyleOptionButton>
#include <QApplication>
#include <QBrush>

/****************************************************************************
**
** MessageDetailDelegate::MessageDetailDelegate
** 功能概述: 构造函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
MessageDetailDelegate::MessageDetailDelegate(QObject* parent, MessagesStyle* style)
    : QItemDelegate(parent)
{
    m_style = style;
    m_commuMessageFlag = false;
    m_tableWidget = NULL;
}

/****************************************************************************
**
** MessageDetailDelegate::paint
** 功能概述: 绘图函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessageDetailDelegate::paint(QPainter* painter,
                                  const QStyleOptionViewItem& option,
                                  const QModelIndex& index) const
{
    QStyleOptionViewItem editOption;
    editOption = option;

    if (index.column() == Constants::MESSAEGSDETAIL_INDEX_CONTENT)
    {
        int intRow =  index.row();
        QString strInOutFlag = index.sibling(intRow, Constants::MESSAEGSDETAIL_INDEX_INOUT).data().toString();
        QString  strColumnValue = index.data(Qt::DisplayRole).toString();
        // 发送消息的场合，背景色变化
        if (strInOutFlag == Constants::MESSAEGS_LIST_INOUT_O)
        {
            QBrush  msContentBgColor = QBrush(m_style->getMsContentBgColor());
            QPointF oldBO = painter->brushOrigin();
            painter->setBrushOrigin(editOption.rect.topLeft());
            painter->fillRect(editOption.rect, msContentBgColor);
            painter->setBrushOrigin(oldBO);
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

        if (option.state & QStyle::State_Selected)
        {
            if (m_tableWidget && m_tableWidget->hasFocus())
            {
                QBrush  msSelectedBgColor = QBrush(m_style->getMsSelectedBgColor());
                QPointF oldBO = painter->brushOrigin();
                painter->setBrushOrigin(editOption.rect.topLeft());
                painter->fillRect(editOption.rect, msSelectedBgColor);
                painter->setBrushOrigin(oldBO);
            }
            //drawFocus(painter, editOption, editOption.rect);
        }

        if (m_commuMessageFlag == false) // 不是通信画面
        {
            painter->drawText(editOption.rect, Qt::TextWordWrap | Qt::AlignLeft | Qt::AlignVCenter, strColumnValue);
        }
        else // 是通信画面
        {
            QString strSendStatus = index.sibling(intRow, Constants::COMMUMESSAGEDETAILl_INDEX_SENDSTATUS).data().toString();

            // 发送是不成功，显示感叹号标识
            if (strSendStatus == Constants::COMMUMESSAEGS_SENDSTATUS_FALSE  && strInOutFlag == Constants::MESSAEGS_LIST_INOUT_O)
            {
                QPixmap pixmap;
                pixmap = QPixmap(m_style->getSelectedPixmap());
                QFont  tempFont(option.font);
                QPen tempPen ;

                if (option.state & QStyle::State_Selected)
                {
                    tempFont.setPixelSize(m_style->getSelectedFontSize());
                    editOption.font = tempFont;
                    tempPen = QPen(QColor(m_style->getSelectedFontColor()));
                }
                else
                {
                    tempPen = painter->pen();
                    tempFont = editOption.font;
                }

                int width = pixmap.width();
                int height = pixmap.height();
                QRect rect = option.rect;
                int x = rect.x() + 5;
                int y = rect.y() + rect.height() / 2 - height / 2;
                painter->drawPixmap(x, y, pixmap);
                QFont oldFont(painter->font());
                QPen oldPen(painter->pen());
                painter->setFont(tempFont);//字体
                painter->setPen(tempPen);
                QRectF textrect(x + width + 10, rect.y(), rect.width() / 2, rect.height());
                painter->drawText(textrect, Qt::TextWordWrap | Qt::AlignLeft | Qt::AlignVCenter, strColumnValue);
                painter->setFont(oldFont);//字体
                painter->setPen(oldPen);
            }
            else
            {
                painter->drawText(editOption.rect, Qt::TextWordWrap | Qt::AlignLeft | Qt::AlignVCenter, strColumnValue);
            }
        }
    }
    else
    {
        QItemDelegate::paint(painter, editOption, index);
    }
}

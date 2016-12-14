#include "managerdelegate.h"
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
** ManagerDelegate::ManagerDelegate
** 功能概述: 构造函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ManagerDelegate::ManagerDelegate(QObject* parent, ManagerStyle* style)
    : QItemDelegate(parent)
{
    m_style = style;
    m_selectedHidden = false;
    m_callFileFlag = false;
}

/****************************************************************************
**
** ManagerDelegate::ManagerDelegate
** 功能概述: 构造函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ManagerDelegate::ManagerDelegate(QObject* parent, ScanGroupStyle* style)
    : QItemDelegate(parent)
{
    m_style = style;
    m_selectedHidden = false;
    m_callFileFlag = false;
}

/****************************************************************************
**
** ManagerDelegate::ManagerDelegate
** 功能概述: 构造函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ManagerDelegate::ManagerDelegate(QObject* parent, CallCommunicationStyle* style)
    : QItemDelegate(parent)
{
    m_style = style;
    m_callFileFlag = false;
}

/****************************************************************************
**
** ManagerDelegate::ManagerDelegate
** 功能概述: 构造函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ManagerDelegate::ManagerDelegate(QObject* parent, CallFileStyle* style)
    : QItemDelegate(parent)
{
    m_style = style;
    m_callFileFlag = false;
}

/****************************************************************************
**
** ManagerDelegate::ManagerDelegate
** 功能概述: 构造函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ManagerDelegate::ManagerDelegate(QObject* parent, CallPhraseBookStyle* style)
    : QItemDelegate(parent)
{
    m_style = style;
    m_callFileFlag = false;
}

/****************************************************************************
**
** ManagerDelegate::paint
** 功能概述: 绘图函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerDelegate::paint(QPainter* painter,
                            const QStyleOptionViewItem& option,
                            const QModelIndex& index) const
{
    QStyleOptionViewItem editOption;
    editOption = option;
    QPixmap pixmap;
    QFont  tempFont(option.font);
    //选中的场合 图标色变化
    if (option.state & QStyle::State_Selected)
    {
        if (m_selectedHidden == true)
        {
            if (index.column() == m_style->getPixmapColummIndex())
            {
                pixmap = QPixmap(m_style->getNoSelectedPixmap());
            }
        }
        else
        {
            if (index.column() == m_style->getPixmapColummIndex())
            {
                pixmap = QPixmap(m_style->getSelectedPixmap());
            }

            tempFont.setPixelSize(m_style->getSelectedFontSize());
            editOption.font = tempFont;
            editOption.displayAlignment = Qt::AlignLeft | Qt::AlignVCenter;
        }
    }
    else
    {
        if (index.column() == m_style->getPixmapColummIndex())
        {
            pixmap = QPixmap(m_style->getNoSelectedPixmap());
        }
    }
    //选中的场合 背景色变化
    if (option.showDecorationSelected && (option.state & QStyle::State_Selected))
    {
        QPalette::ColorGroup cg = option.state & QStyle::State_Enabled
                                  ? QPalette::Normal : QPalette::Disabled;

        if (cg == QPalette::Normal && !(option.state & QStyle::State_Active))
            cg = QPalette::Inactive;

        if (m_selectedHidden == true)  // call insert 画面 光标丢失后不高亮显示
        {
        }
        else
        {
            painter->fillRect(editOption.rect, editOption.palette.brush(cg, QPalette::Highlight));
        }
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
    // 画图标
    if (index.column() == m_style->getPixmapColummIndex())
    {
        const QAbstractItemModel* model = index.model();
        int width = pixmap.width();
        int height = pixmap.height();
        QRect rect = editOption.rect;
        int x = rect.width() - width - rect.width() / 8;
        int y = rect.y() + rect.height() / 2 - height / 2;
        painter->drawPixmap(x, y, pixmap);
    }
    else
    {
        QString  strColumnValue = index.data(Qt::DisplayRole).toString();
        QString  strColumnShowValue;

        if (option.state & QStyle::State_Selected)
        {
            if (strColumnValue.length() > Constants::PHRASEBOOK_SHOW_LENGH)
            {
                strColumnShowValue = strColumnValue.mid(0, Constants::COMMUMESSAEGS_SHOW_LENGH - 1);
                strColumnShowValue = strColumnShowValue + ("...");
            }
            else
            {
                strColumnShowValue = strColumnValue;
            }
        }
        else
        {
            strColumnShowValue = strColumnValue;
        }

        if (index.column() == Constants::PHRASEBOOK_INDEX_NO || index.column() == Constants::FILe_INDEX_NAME)
        {
            //绘制文本
            if (m_callFileFlag == true)
            {
                painter->drawText(editOption.rect, Qt::AlignHCenter | Qt::AlignVCenter, strColumnShowValue);
            }
            else
            {
                painter->drawText(editOption.rect, Qt::AlignLeft | Qt::AlignVCenter, strColumnShowValue);
            }
        }
        else //父类填充
        {
            painter->drawText(editOption.rect, Qt::AlignHCenter | Qt::AlignVCenter, strColumnShowValue);
        }
    }
}

/****************************************************************************
**
** ManagerDelegate::drawFocus
** 功能概述: 焦点绘制函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerDelegate::drawFocus(QPainter* painter,
                                const QStyleOptionViewItem& option,
                                const QRect& rect) const
{
}

/****************************************************************************
**
** ManagerDelegate::setSelectedHidden
** 功能概述: 设置选中行隐藏函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerDelegate::setSelectedHidden(bool hiddenFlag)
{
    m_selectedHidden = hiddenFlag;
}

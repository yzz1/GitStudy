#include <QPainter>
#include <QVariant>
#include <QDebug>
#include <core/database/database.h>
#include "core/utils/pathresolve.h"
#include "views/common/constants.h"

#include "button.h"
/****************************************************************************
**
** 函数名称：getNormalIcon
** 功能概述: 获取图片路径
** 参数说明 iconName：图片名称
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
static inline QString getNormalIcon(const QString& iconName)
{
    return QString().append(Constants::IMAGE_PATH).append(iconName).append(Constants::NORMAL_ICON_SUFFIX);
}
/****************************************************************************
**
** 函数名称：getHoverIcon
** 功能概述: 获取图片路径
** 参数说明 iconName：图片名称
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
static inline QString getHoverIcon(const QString& iconName)
{
    return QString().append(Constants::IMAGE_PATH).append(iconName).append(Constants::HOVER_ICON_SUFFIX);
}
/****************************************************************************
**
** 函数名称：getPressedIcon
** 功能概述: 获取图片路径
** 参数说明 iconName：图片名称
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
static inline QString getPressedIcon(const QString& iconName)
{
    return QString().append(Constants::IMAGE_PATH).append(iconName).append(Constants::PRESSED_ICON_SUFFIX);
}
/****************************************************************************
**
** 函数名称：Button：：Button
** 功能概述: 初始化
** 参数说明 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
Button::Button(QWidget* parent)
    : QToolButton(parent), m_iconName("")
{
}
/****************************************************************************
**
** 函数名称：Button：：Button
** 功能概述: 初始化
** 参数说明 iconName：图片名称 ，textLabel：按钮名称 ，parent：父对象
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
Button::Button(const QString& iconName, const QString& textLabel, QWidget* parent)
    : QToolButton(parent), m_iconName(iconName)
{
    setIconName(iconName);
    setIcon(QIcon(getNormalIcon(iconName)));
    setText(textLabel);
}
/****************************************************************************
**
** 函数名称：Button：：setIconName
** 功能概述: 设置图片名称
** 参数说明 iconName：图片名称 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Button::setIconName(const QString& iconName)
{
    if (m_iconName == iconName)
        return;

    m_iconName = iconName;
}
/****************************************************************************
**
** 函数名称：Button：：iconName
** 功能概述: 返回图片名称
** 参数说明  
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QString Button::iconName() const
{
    return m_iconName;
}
/****************************************************************************
**
** 函数名称：Button：：mousePressEvent
** 功能概述: 点击事件发送
** 参数说明  
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Button::mousePressEvent(QMouseEvent*)
{
    this->setIcon(QIcon(getPressedIcon(m_iconName)));
    emit clicked();
}
/****************************************************************************
**
** 函数名称：Button：：mouseReleaseEvent
** 功能概述: 点击事件发送
** 参数说明  
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Button::mouseReleaseEvent(QMouseEvent*)
{
}
/****************************************************************************
**
** 函数名称：Button：：enterEvent
** 功能概述: 设置焦点
** 参数说明  
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Button::enterEvent(QEvent*)
{
    this->setFocus();
}
/****************************************************************************
**
** 函数名称：Button：：focusInEvent
** 功能概述: 高亮图片，在获取焦点时
** 参数说明  
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Button::focusInEvent(QFocusEvent*)
{
    this->setIcon(QIcon(getHoverIcon(m_iconName)));
}
/****************************************************************************
**
** 函数名称：Button：：focusOutEvent
** 功能概述: 不高亮图片，在离开焦点时
** 参数说明  
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Button::focusOutEvent(QFocusEvent*)
{
    this->setIcon(QIcon(getNormalIcon(m_iconName)));
}

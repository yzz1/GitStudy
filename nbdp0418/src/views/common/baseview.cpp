#include "baseview.h"
#include <QPainter>
#include <QMouseEvent>
#include <qmath.h>
/****************************************************************************
**
** 函数名称：BaseView::BaseView
** 功能概述: 初始化
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
BaseView::BaseView(QWidget* parent) :
    QDialog(parent), m_mousePress(false)
{
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
}
/****************************************************************************
**
** 函数名称：BaseView::paintEvent
** 功能概述: 绘图事件
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void BaseView::paintEvent(QPaintEvent*)
{
    QPainter p(this);
}

/****************************************************************************
**
** 函数名称：BaseView::forward
** 功能概述: 
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void BaseView::forward(int viewId)
{
}

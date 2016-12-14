#include "viewmanager.h"
#include "viewmanager_p.h"
#include <QWidget>

static ViewManagerPrivate* d = 0;
static ViewManager* m_instance = 0;
/****************************************************************************
**
** 函数名称：ViewManagerPrivate::ViewManagerPrivate
** 功能概述: 初始化
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ViewManagerPrivate::ViewManagerPrivate(ViewManager* viewManager) :
    q(viewManager)
{
}
/****************************************************************************
**
** 函数名称：ViewManagerPrivate::～ViewManagerPrivate
** 功能概述: 析构函数
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ViewManagerPrivate::~ViewManagerPrivate()
{
}
/****************************************************************************
**
** 函数名称：ViewManagerPrivate::addView
** 功能概述: 添加界面
** 参数说明： 界面指针
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ViewManagerPrivate::addView(QWidget* view)
{
    m_views.append(view);
}
/****************************************************************************
**
** 函数名称：ViewManagerPrivate::removeView
** 功能概述: 删除界面
** 参数说明： 界面指针
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ViewManagerPrivate::removeView(QWidget* view)
{
    m_views.removeOne(view);
}
/****************************************************************************
**
** 函数名称：ViewManagerPrivate::allViews
** 功能概述: 所有界面列表
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QWidgetList ViewManagerPrivate::allViews()
{
    return m_views;
}
/****************************************************************************
**
** 函数名称：ViewManager::ViewManager
** 功能概述: 初始化
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ViewManager::ViewManager()
{
    m_instance = this;
    d = new ViewManagerPrivate(this);
}
/****************************************************************************
**
** 函数名称：ViewManager::～ViewManager
** 功能概述: 析构函数
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ViewManager::~ViewManager()
{
    delete d;
}
/****************************************************************************
**
** 函数名称：ViewManager::instance
** 功能概述: 返回单例
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ViewManager* ViewManager::instance()
{
    return m_instance;
}
/****************************************************************************
**
** 函数名称：ViewManager::addView
** 功能概述: 添加界面
** 参数说明： 界面指针
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ViewManager::addView(QWidget* view)
{
    d->addView(view);
}
/****************************************************************************
**
** 函数名称：ViewManager::allViews
** 功能概述: 所有界面列表
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QWidgetList ViewManager::allViews() const
{
    return d->allViews();
}
/****************************************************************************
**
** 函数名称：ViewManager::removeView
** 功能概述: 删除界面
** 参数说明： 界面指针
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ViewManager::removeView(QWidget* view)
{
    d->removeView(view);
}
/****************************************************************************
**
** 函数名称：ViewManager::getViewByName
** 功能概述: 获取界面指针
** 参数说明：界面名称
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QWidget* ViewManager::getViewByName(const QString& name) const
{
    QWidgetList views = d->allViews();
    foreach(QWidget * view, views)
    {
        if (view->objectName() == name)
        {
            return view;
        }
    }
    return 0;
}
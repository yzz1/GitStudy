/****************************************************************************
**
** 文件名称： viewmanager_p.h
** 功能概述:  主菜单各界面管理处理类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef VIEWMANAGER_P_H
#define VIEWMANAGER_P_H

#include <QObject>
#include <QWidgetList>

class ViewManager;
class ViewManagerPrivate : QObject
{
        Q_OBJECT
    public:
        ViewManagerPrivate(ViewManager* viewManager);
        
        virtual ~ViewManagerPrivate();
        
        void addView(QWidget* view);
        
        QWidgetList allViews();
        
        void removeView(QWidget* view);
        
    private:
        QWidgetList m_views;
        
        ViewManager* q;
};

#endif // VIEWMANAGER_P_H


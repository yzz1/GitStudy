/****************************************************************************
**
** 文件名称： viewmanager.h
** 功能概述:  主菜单各界面管理类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef VIEWMANAGER_H
#define VIEWMANAGER_H

#include <QObject>
#include <QReadWriteLock>
#include <QStringList>
#include <utility>
#include <QWidgetList>

class ViewManagerPrivate;

class  ViewManager : public QObject
{
        Q_OBJECT
    public:
        static ViewManager* instance();
        ~ViewManager();
        ViewManager();
        
        
        QWidgetList allViews() const;
        
        void addView(QWidget* view);
        void removeView(QWidget* view);
        
//    //void removeViewByName(const QString &name);
        QWidget* getViewByName(const QString& name) const;
        
    private:
    
        //ViewManagerPrivate *d;
        //static ViewManager *m_instance;
//   mutable QReadWriteLock m_lock;

        friend class ViewManagerPrivate;
};

#endif // VIEWMANAGER_H

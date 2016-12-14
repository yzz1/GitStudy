/****************************************************************************
**
** 文件名称： baseview.h
** 功能概述:  基础页面类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef BaseView_H
#define BaseView_H

#include <QWidget>
#include <QDialog>

class BaseView : public QDialog
{
        Q_OBJECT
    public:
        explicit BaseView(QWidget* parent = 0);
        
        Q_INVOKABLE void forward(int viewId);
        
    protected:
        
        virtual void paintEvent(QPaintEvent* event);
        
    private:
        QPoint m_movePoint;
        bool m_mousePress;
        int m_previousViewId;
        int m_nextViewId;
};

#endif // BaseView_H

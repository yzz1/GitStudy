/****************************************************************************
**
** 文件名称： homeview.h
** 功能概述:  主菜单事件处理界面类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef HOMEWIDGET_H
#define HOMEWIDGET_H

#include <QGridLayout>
#include <QSignalMapper>
#include <QWidget>
#include <QMap>

class HomeWidget: public QWidget
{
        Q_OBJECT
        
    public:
        explicit HomeWidget(QWidget* parent = NULL);
        ~HomeWidget() {}
    signals :
        void afterPageSignal(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        
    private:
        HomeWidget& operator=(const HomeWidget& obj);
        HomeWidget(const HomeWidget& obj);
        bool eventFilter(QObject* watched, QEvent* event);
    private:
        QGridLayout* m_layout;   //主页面框架变量
        bool m_enterflag;	//enter按键确认判断  用于规避从子菜单返回时接收到enter键弹起消息的处理
    signals:
        void buttonClicked(int index);
};

#endif // HOMEWIDGET_H

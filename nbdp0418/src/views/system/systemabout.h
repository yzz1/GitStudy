/****************************************************************************
**
** 文件名称： systemabout.h
** 功能概述:  systemabout界面类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef SYSTEMABOUT_H
#define SYSTEMABOUT_H

#include <QWidget>
#include <QMap>

namespace Ui
{
    class SystemAbout;
}

class SystemAbout : public QWidget
{
        Q_OBJECT
        
    public:
        explicit SystemAbout(QWidget* parent = 0);
        ~SystemAbout();
    signals :
        void afterPageSignal(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
    public slots:
        void homeClickedSlot();
        void settingClickedSlot();
        void testClickedSlot();
        void aboutClickedSlot();
        void frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
    private:
        Ui::SystemAbout* ui;
        bool eventFilter(QObject* watched, QEvent* event);
};

#endif // SYSTEMABOUT_H

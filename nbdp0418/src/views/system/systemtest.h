/****************************************************************************
**
** 文件名称： systemtest.h
** 功能概述:  系统测试界面类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef SYSTEMTEST_H
#define SYSTEMTEST_H

#include <QWidget>
#include <QMap>

namespace Ui
{
    class SystemTest;
}

class SystemTest : public QWidget
{
        Q_OBJECT
        
    public:
        explicit SystemTest(QWidget* parent = 0);
        ~SystemTest();
        void selfTest(QList<bool> test);
        
    signals :
        void afterPageSignal(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        void selfTestSignal(QList<bool> bTest);
    private:
        Ui::SystemTest* ui;
        bool eventFilter(QObject* watched, QEvent* event);
    public slots:
        void homeClickedSlot();
        void settingClickedSlot();
        void testClickedSlot();
        void aboutClickedSlot();
        void okButtonClickedSlot();
        void cancelButtonClickedSlot();
        void frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
};


#endif // SYSTEMTEST_H

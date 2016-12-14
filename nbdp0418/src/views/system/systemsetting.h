/****************************************************************************
**
** 文件名称： systemsetting.h
** 功能概述:  系统设置界面类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef SYSTEMSETTING_H
#define SYSTEMSETTING_H

#include <QWidget>
#include <QMap>
#include <QAbstractItemModel>
#include "models/contactsmodel.h"
#include <QtGui/QListWidget>
namespace Ui
{
    class SystemSetting;
}

class SystemSetting : public QWidget
{
        Q_OBJECT
        
    public:
        explicit SystemSetting(QWidget* parent = 0);
        ~SystemSetting();
    signals :
        void afterPageSignal(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        void realTimePrinting(QString realTimePrinting);
    private:
        Ui::SystemSetting* ui;
        bool m_bInTimeEdit;		//时间设置标记
        QSqlTableModel* m_model;
        bool eventFilter(QObject* watched, QEvent* event);
        QString m_timeStr;      //时间字符串缓存
    public slots:
        void homeClickedSlot();
        void settingClickedSlot();
        void testClickedSlot();
        void aboutClickedSlot();
        void identificationSettingClickedSlot();
        void frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        void listwidgetClickedSlot(QListWidgetItem* item);
        void listwidget2ClickedSlot(QListWidgetItem* item);
        void listwidget3ClickedSlot(QListWidgetItem* item);
        void listwidget4ClickedSlot(QListWidgetItem* item);
        void listwidget5ClickedSlot(QListWidgetItem* item);
        void listwidget6ClickedSlot(QListWidgetItem* item);
        void listwidget7ClickedSlot(QListWidgetItem* item);
        void dateTimeButtonClick();
};

#endif // SYSTEMSETTING_H

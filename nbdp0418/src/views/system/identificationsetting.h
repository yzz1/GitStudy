/****************************************************************************
**
** 文件名称： identificationsetting.h
** 功能概述:  系统设置子界面类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef IDENTIFICATIONSETTING_H
#define IDENTIFICATIONSETTING_H

#include <QWidget>
#include <QMap>
#include <QTimer>
#include "models/contactsmodel.h"

namespace Ui
{
    class IdentificationSetting;
}

class IdentificationSetting : public QWidget
{
        Q_OBJECT
        
    public:
        explicit IdentificationSetting(QWidget* parent = 0);
        ~IdentificationSetting();
        
    public slots:
        void slotSendDeviceInfo();
        void homeClickedSlot();
        void settingClickedSlot();
        void testClickedSlot();
        void aboutClickedSlot();
        void okButtonClickedSlot();
        void cancelButtonClickedSlot();
        void frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        
    signals :
        void afterPageSignal(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        void setMMSI(QString mmsi);
        
    private:
        Ui::IdentificationSetting* ui;
        int  m_NumEdit;			//保存当前编辑位置
        QSqlTableModel* m_model;		//数据模型
        //QStringList identificationinfo;
        bool eventFilter(QObject* watched, QEvent* event);
       QString digitcallcode;
       QString mmsicode;
       QString answerbackcode;
};

#endif // IDENTIFICATIONSETTING_H

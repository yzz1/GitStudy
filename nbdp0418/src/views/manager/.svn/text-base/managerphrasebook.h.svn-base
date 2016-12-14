/****************************************************************************
**
** 文件名称： managerphrasebook.h
** 功能概述:  Phrasebook界面类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef MANAGERPHRASEBOOK_H
#define MANAGERPHRASEBOOK_H

#include <QWidget>
#include <QMap>
#include "models/managermodel.h"
#include "models/managerdelegate.h"


namespace Ui
{
    class ManagerPhrasebook;
}

class ManagerPhrasebook : public QWidget
{
        Q_OBJECT
        
    public:
        explicit ManagerPhrasebook(QWidget* parent = 0);
        ~ManagerPhrasebook();
        //void show();
        // void  enterKeyPress();
        // bool eventFilter(QObject* watched, QEvent* event);
        
    signals :
        void afterPageSignal(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        
    private:
        Ui::ManagerPhrasebook* ui;
        bool m_optionMenuStatus;  //option 菜单的开关
        ManagerModel* m_model;   //数据模型
        ManagerDelegate* m_managerDelegate;	//数据委托处理
        bool eventFilter(QObject* watched, QEvent* event);
    public slots:
        void showOptionMenu();
        void  importClickedSlot();
        void  exportClickedSlot();
        void deleteSelectedRow();
        void editClickedSolt();
        void  newClickedSolt();
        void  homeClickedSlot();
        void  macroClickedSlot();
        void  fileClickedSlot();
        void frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        
};

#endif // MANAGERPHRASEBOOK_H

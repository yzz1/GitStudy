/****************************************************************************
**
** 文件名称： managermacro.h
** 功能概述:  macro界面类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef MANAGERMACRO_H
#define MANAGERMACRO_H

#include <QWidget>
#include <QMap>
#include "models/managermodel.h"
#include "models/managerdelegate.h"


namespace Ui
{
    class ManagerMacro;
}

class ManagerMacro : public QWidget
{
        Q_OBJECT
        
    public:
        explicit ManagerMacro(QWidget* parent = 0);
        ~ManagerMacro();
//   void show();
        //   void  enterKeyPress();
        //    bool eventFilter(QObject* watched, QEvent* event);
        
    signals :
        void afterPageSignal(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        
    private:
        Ui::ManagerMacro* ui;
        bool m_optionMenuStatus;  //option 菜单的开关
        ManagerModel* m_model;   //数据模型
        ManagerDelegate* m_managerDelegate;		//数据委托处理
        bool eventFilter(QObject* watched, QEvent* event);
    public slots:
        void showOptionMenu();
        void  importClickedSlot();
        void  exportClickedSlot();
        void deleteSelectedRow();
        void editClickedSolt();
        void  newClickedSolt();
        void  homeClickedSlot();
        void  phrasebookClickedSlot();
        void  fileClickedSlot();
        void frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        
};


#endif // MANAGERMACRO_H

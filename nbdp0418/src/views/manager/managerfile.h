/****************************************************************************
**
** 文件名称： managerfile.h
** 功能概述:  文件列表界面类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef MANAGERFILE_H
#define MANAGERFILE_H

#include <QWidget>
#include <QMap>
#include "models/filemodels.h"
#include "models/fileitemdelegate.h"

namespace Ui
{
    class ManagerFile;
}

class ManagerFile : public QWidget
{
        Q_OBJECT
        
    public:
        explicit ManagerFile(QWidget* parent = 0);
        ~ManagerFile();
        void show();
        void  reNameFile(QString  filenameEdited);
        
    signals :
        void afterPageSignal(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        
    private:
        Ui::ManagerFile* ui;
        bool m_optionMenuStatus;  //option 菜单的开关
        FileModels* m_model;   //数据模型
        FileItemDelegate* m_fileItemDelegate; //数据委托处理
        int m_curRow;
        QWidget* m_curWidget;
        bool m_TableToNext;			//标记处理响应
        bool m_lostFocus;			//保存上一次光标位置
        bool eventFilter(QObject* watched, QEvent* event);
        
    public slots:
        void showOptionMenu();
        void  importClickedSlot();
        void  exportClickedSlot();
        void deleteSelectedRow();
        void editClickedSolt();
        void  newClickedSolt();
        void renameClickedSolt();
        void  homeClickedSlot();
        void macroClickedSlot();
        void phrasebookClickedSlot();
        void frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        
};

#endif // MANAGERFILE_H

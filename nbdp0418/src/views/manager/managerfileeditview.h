/****************************************************************************
**
** 文件名称： managerfileeditview.h
** 功能概述:  文件内容编辑界面类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef MANAGERFILEEDITVIEW_H
#define MANAGERFILEEDITVIEW_H

#include <QWidget>
#include <QMap>
#include <QLabel>

namespace Ui
{
    class ManagerFileEditView;
}

class ManagerFileEditView : public QWidget
{
        Q_OBJECT
        
    public:
        explicit ManagerFileEditView(QWidget* parent = 0);
        ~ManagerFileEditView();
        
    private:
        Ui::ManagerFileEditView* ui;
        QString m_strModle;				//保存编辑或新建标记
        QMap <QString, QString> m_paraMap;
        QString m_editStr;				//保存最近一次编辑框的内容
        bool eventFilter(QObject* watched, QEvent* event);
    signals :
        void afterPageSignal(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
    public  slots:
        void saveData();
        void  homeClickedSlot();
        void cancelClickedSlot();
        void copyClicedSlot();
        void pasteClicedSlot();
        void cutClicedSlot();
        void undoClicedSlot();
        void  phrasebookClickedSlot();
        void  fileClickedSlot();
        void  macroClickedSlot();
        void inputCheckSlot();
        void frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
};

#endif // MANAGERFILEEDITVIEW_H

/****************************************************************************
**
** 文件名称： contactsinput.h
** 功能概述:  频率输入控件类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef CONTACTSINPUT_H
#define CONTACTSINPUT_H

#include <QWidget>

namespace Ui
{
    class ContactsInput;
}

class ContactsInput : public QWidget
{
        Q_OBJECT
        
    public:
        explicit ContactsInput(QWidget* parent = 0);
        ~ContactsInput();
        void openEditmode(bool txOrRx = true);
        void offEditmode(bool save = true);
        void widgetSetFocus();
        void widgetCleanFocus();
        QString getData();
        void setData(QString str);
        void editDataClean();
        
    private:
        Ui::ContactsInput* ui;
        bool eventFilter(QObject* watched, QEvent* event);
        int editNum;
        bool m_editMode;
        bool m_txOrRx;
        QString m_oldStr;
        QString  getText();
};
#endif // CONTACTSINPUT_H

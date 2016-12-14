/****************************************************************************
**
** 文件名称： inputdialog.h
** 功能概述:  输入栏对话框类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui
{
    class InputDialog;
}

class InputDialog : public QDialog
{
        Q_OBJECT
        
    public:
        explicit InputDialog(QWidget* parent = 0);
        ~InputDialog();
        QString getTextContent();
        void  SetTextContent(QString text);
        void SetTitle(QString title);
        void  SetLineEditMaxLen(int maxLen);
        
    private:
        Ui::InputDialog* ui;
    private slots:
        void on_btnOk_clicked();
};

#endif // INPUTDIALOG_H

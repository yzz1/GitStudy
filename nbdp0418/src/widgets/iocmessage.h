/****************************************************************************
**
** 文件名称： iomessage.h
** 功能概述:  消息对话框类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef IOCMESSAGE_H
#define IOCMESSAGE_H

#include <QWidget>
#include <QDialog>

namespace Ui
{
    class IocMessage;
}

class IocMessage : public QDialog
{
        Q_OBJECT
        
    public:
        explicit IocMessage(QWidget* parent = 0);
        ~IocMessage();
        
        void SetMessage(QString title, QString msg1, QString msg2);
        void SetButtonLayout(bool showCancelButton = false, bool showOkButton = true);
        void SetBtnName(QString btnName);
        void SetIoc(QString iocPix, int iconPosX, bool moveFlag = false);
        void SetFont(const QFont font);
        void keyPressEvent(QKeyEvent* event);
    private slots:
        void on_btnOk_clicked();
        void on_btnCancel_clicked();
        
    private:
        Ui::IocMessage* ui;
        void InitStyle();   //初始化无边框窗体
};

#endif // IOCMESSAGE_H

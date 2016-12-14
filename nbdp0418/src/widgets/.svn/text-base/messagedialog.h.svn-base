/****************************************************************************
**
** 文件名称： messagedialog.h
** 功能概述:  消息对话框类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef MESSAGEDIALOG_H
#define MESSAGEDIALOG_H

#include <QDialog>

namespace Ui
{
    class MessageDialog;
}

class MessageDialog : public QDialog
{
        Q_OBJECT
        
    public:
        explicit MessageDialog(QWidget* parent = 0);
        ~MessageDialog();
        void SetMessage(QString title, QString msg, int type);
        
    public slots:
        void selfTestSlot(QList<bool> test);
    protected:
        void mouseMoveEvent(QMouseEvent* e);
        void mousePressEvent(QMouseEvent* e);
        void mouseReleaseEvent(QMouseEvent*);
        void msgTimerUpDate();
        void timerEvent(QTimerEvent* event);
        void keyPressEvent(QKeyEvent* event);
    private slots:
        void on_btnOk_clicked();
        
    private:
        Ui::MessageDialog* ui;
        void InitStyle();   //初始化无边框窗体
        QPoint mousePoint;  //鼠标拖动自定义标题栏时的坐标
        bool mousePressed;  //鼠标是否按下
        int m_count;
        int m_nTimerId;
};

#endif // MESSAGEDIALOG_H

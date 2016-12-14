/****************************************************************************
**
** 文件名称： messageBox.h
** 功能概述:  消息对话类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef MessageBox_H
#define MessageBox_H

#include <QDialog>

namespace Ui
{
    class MessageBox;
}

class MessageBox : public QDialog
{
        Q_OBJECT
        
    public:
        explicit MessageBox(QWidget* parent = 0);
        ~MessageBox();
        
        void SetMessage(QString title, QString msg, int type);
        
    protected:
        void mouseMoveEvent(QMouseEvent* e);
        void mousePressEvent(QMouseEvent* e);
        void mouseReleaseEvent(QMouseEvent*);
        
    private slots:
        void on_btnOk_clicked();
        
    private:
        Ui::MessageBox* ui;
        
        QPoint mousePoint;  //鼠标拖动自定义标题栏时的坐标
        bool mousePressed;  //鼠标是否按下
        void InitStyle();   //初始化无边框窗体
};

#endif // MessageBox_H

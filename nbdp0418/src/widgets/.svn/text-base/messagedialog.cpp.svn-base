#include "messagedialog.h"
#include "ui_messagedialog.h"
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>
#include "widgets/button.h"
#include "control.h"
#include <QMovie>
/****************************************************************************
**
** 函数名称：MessageDialog::MessageDialog
** 功能概述: 初始化
** 参数说明 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
MessageDialog::MessageDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::MessageDialog)
{
    ui->setupUi(this);
    this->InitStyle();
    m_count = -1;
    QMovie* movie = new QMovie(":/images/Call_Wait_flash");
    ui->label_2->setMovie(movie);
    ui->label_3->setMovie(movie);
    ui->label_4->setMovie(movie);
    movie->start();
}
/****************************************************************************
**
** 函数名称：MessageDialog::keyPressEvent
** 功能概述: 快捷键功能处理
** 参数说明  事件键值
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessageDialog::keyPressEvent(QKeyEvent* event)
{
    int keyValue = event->key();
    QString strMdf = "";

    if (event->modifiers() == Qt::AltModifier)
    {
        strMdf = "Alt";
    }
    else if (event->modifiers() == Qt::ControlModifier)
    {
        strMdf = "Ctrl";
    }
    else if (event->modifiers() == (Qt::AltModifier | Qt::ControlModifier))
    {
        strMdf = "Ctrl+Alt";
    }

    Control::get()->KeyDownForTest(strMdf, keyValue);
    QWidget::keyPressEvent(event);
}
/****************************************************************************
**
** 函数名称：MessageDialog::mouseMoveEvent
** 功能概述: 
** 参数说明  
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessageDialog::mouseMoveEvent(QMouseEvent* e)
{

}
/****************************************************************************
**
** 函数名称：MessageDialog::mousePressEvent
** 功能概述: 
** 参数说明  
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessageDialog::mousePressEvent(QMouseEvent* e)
{
}
/****************************************************************************
**
** 函数名称：MessageDialog::mouseReleaseEvent
** 功能概述: 
** 参数说明  
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessageDialog::mouseReleaseEvent(QMouseEvent*)
{
    mousePressed = false;
}
/****************************************************************************
**
** 函数名称：MessageDialog::InitStyle
** 功能概述: 初始化样式
** 参数说明  
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessageDialog::InitStyle()
{
    this->mousePressed = false;
    //设置窗体标题栏隐藏
    this->setWindowFlags(Qt::FramelessWindowHint);
    connect(ui->okBtn, SIGNAL(clicked()), this, SLOT(on_btnOk_clicked()));
    connect(ui->cancelBtn, SIGNAL(clicked()), this, SLOT(close()));
}
/****************************************************************************
**
** 函数名称：MessageDialog::selfTestSlot
** 功能概述: 测试回调处理
** 参数说明  
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessageDialog::selfTestSlot(QList<bool> test)
{
    QPixmap truePix(QString(":/images/images/OK.png"));
    QPixmap falsePix(QString(":/images/cancel"));

    if (test.at(0))
    {
        ui->label_2->setPixmap(truePix);
    }
    else
    {
        ui->label_2->setPixmap(falsePix);
    }

    if (test.at(1))
    {
        ui->label_3->setPixmap(truePix);
    }
    else
    {
        ui->label_3->setPixmap(falsePix);
    }

    if (test.at(2))
    {
        ui->label_4->setPixmap(truePix);
    }
    else
    {
        ui->label_4->setPixmap(falsePix);
    }
}
/****************************************************************************
**
** 函数名称：MessageDialog::SetMessage
** 功能概述: 设置对话框标题和类型
** 参数说明  title：标题 ，msg：消息，type：类型
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessageDialog::SetMessage(QString title, QString msg, int type)
{
    if (type == 0 || type == 2)
    {
        ui->cancelBtn->hide();
        ui->label_5->hide();
        ui->label_6->hide();
    }
    else if (type == 1)
    {
        ui->label_5->hide();
        ui->label_6->hide();
    }
    else if (type == 3)
    {
        ui->okBtn->hide();
        ui->label->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_4->hide();
        m_nTimerId = startTimer(1000);
        QRect  rect = ui->cancelBtn->geometry();
        rect = QRect((rect.x() - 250), rect.y(), rect.width(), rect.height());
        ui->cancelBtn->setGeometry(rect);
    }

    ui->lab_Title->setText(title);
    this->setWindowTitle(ui->lab_Title->text());
}
/****************************************************************************
**
** 函数名称：MessageDialog::on_btnOk_clicked
** 功能概述: 确定键响应
** 参数说明  
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessageDialog::on_btnOk_clicked()
{
    done(1);
    this->close();
}
/****************************************************************************
**
** 函数名称：MessageDialog::on_msgTimerUpDate_clicked
** 功能概述: 刷新倒计时数字
** 参数说明  
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessageDialog::msgTimerUpDate()
{
    if (m_count <= -1)
    {
        m_count = 15;
    }

    QString text(QString::number(m_count, 10));
    text += 'S';
    ui->label_6->setText(text);
    m_count--;

    if (m_count == -1)
        this->close();
}
/****************************************************************************
**
** 函数名称：MessageDialog::timerEvent
** 功能概述: 计时器调用接口
** 参数说明  
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessageDialog::timerEvent(QTimerEvent* event)
{
    msgTimerUpDate();
}

MessageDialog::~MessageDialog()
{
    if (m_nTimerId != 0)
        killTimer(m_nTimerId);

    delete ui;
}


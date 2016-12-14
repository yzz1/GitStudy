#include "iocmessage.h"
#include "ui_iocmessage.h"
#include <QDesktopWidget>
#include <QKeyEvent>
#include <QMovie>
#include "control.h"
/****************************************************************************
**
** 函数名称：IocMessage::IocMessage
** 功能概述: 初始化
** 参数说明 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
IocMessage::IocMessage(QWidget* parent):
    QDialog(parent),
    ui(new Ui::IocMessage)
{
    ui->setupUi(this);
    this->InitStyle();
}
/****************************************************************************
**
** 函数名称：IocMessage::~IocMessage
** 功能概述: 析构函数
** 参数说明 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
IocMessage::~IocMessage()
{
    delete ui;
}

/****************************************************************************
**
** 函数名称：IocMessage::InitStyle
** 功能概述: 初始化样式
** 参数说明 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void IocMessage::InitStyle()
{
    //窗体居中显示
    ui->cancelBtn->hide();
    ui->okBtn->show();
    ui->okBtn->move((ui->widget_main->width() - ui->okBtn->width()) / 2 , ui->okBtn->pos().ry());
    //设置窗体标题栏隐藏
    this->setWindowFlags(Qt::FramelessWindowHint);
    connect(ui->okBtn, SIGNAL(clicked()), this, SLOT(on_btnOk_clicked()));
    connect(ui->cancelBtn, SIGNAL(clicked()), this, SLOT(on_btnCancel_clicked()));
}
/****************************************************************************
**
** 函数名称：IocMessage::SetMessage
** 功能概述: 设置标题内容
** 参数说明 title：标题，msg1：内容，msg2：内容
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void IocMessage::SetMessage(QString title, QString msg1, QString msg2)
{
    ui->lab_Title->setText(title);

    if (msg2.isEmpty())
    {
        ui->textEdit2->setText(msg1);
    }
    else
    {
        ui->textEdit1->setText(msg1);
        ui->textEdit3->setText(msg2);
    }

    this->setWindowTitle(ui->lab_Title->text());
}
/****************************************************************************
**
** 函数名称：IocMessage::SetMessage
** 功能概述: 设置按钮内容
** 参数说明  btnName：内容
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void IocMessage::SetBtnName(QString btnName)
{
    ui->okBtn->setText(btnName);
}
/****************************************************************************
**
** 函数名称：IocMessage::SetButtonLayout
** 功能概述: 设置显示隐藏按钮
** 参数说明  showCancelButton：取消按钮，showOkButton：OK按钮
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void IocMessage::SetButtonLayout(bool showCancelButton, bool showOkButton)
{
    if (showCancelButton)
    {
        ui->cancelBtn->show();
    }
    else
    {
        ui->cancelBtn->hide();
    }

    if (showOkButton)
    {
        ui->okBtn->show();
    }
    else
    {
        ui->okBtn->hide();
    }

    if (ui->okBtn->isHidden())
    {
        ui->cancelBtn->move((ui->widget_main->width() - ui->cancelBtn->width()) / 2, ui->cancelBtn->pos().ry());
    }

    if (ui->cancelBtn->isHidden())
    {
        ui->okBtn->move((ui->widget_main->width() - ui->okBtn->width()) / 2 , ui->okBtn->pos().ry());
    }

    if (!ui->okBtn->isHidden() && !ui->cancelBtn->isHidden())
    {
        ui->okBtn->move((ui->widget_main->width() - ui->okBtn->width()) / 4 , ui->okBtn->pos().ry());
        ui->cancelBtn->move((ui->widget_main->width() - ui->cancelBtn->width()) * 3 / 4 , ui->cancelBtn->pos().ry());
    }

    if (ui->okBtn->isVisible())
    {
        ui->okBtn->setFocus();
    }
    else if (ui->cancelBtn->isVisible())
    {
        ui->cancelBtn->setFocus();
    }
}
/****************************************************************************
**
** 函数名称：IocMessage::SetFont
** 功能概述: 设置字体格式
** 参数说明  font：格式
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void IocMessage::SetFont(const QFont font)
{
    ui->textEdit1->setFont(font);
    ui->textEdit2->setFont(font);
    ui->textEdit3->setFont(font);
}
/****************************************************************************
**
** 函数名称：IocMessage::SetIoc
** 功能概述: 设置图片
** 参数说明  iocPix：图片路径，iconPosX：图片坐标，moveFlag：移动标记
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void IocMessage::SetIoc(QString iocPix, int iconPosX, bool moveFlag)
{
    QRect  rectIco = ui->label_ico->geometry();
    QRect  rectTextEdit1 = ui->textEdit1->geometry();
    QRect  rectTextEdit2 = ui->textEdit2->geometry();
    QRect  rectTextEdit3 = ui->textEdit3->geometry();
    rectIco = QRect(iconPosX, rectIco.y(), rectIco.width(), rectIco.height());
    ui->label_ico->setGeometry(rectIco);
    rectTextEdit1 = QRect((rectIco.x() + rectIco.width() + 10), rectTextEdit1.y(), rectTextEdit1.width(),
                          rectTextEdit1.height());
    rectTextEdit2 = QRect((rectIco.x() + rectIco.width() + 10), rectTextEdit2.y(), rectTextEdit2.width(),
                          rectTextEdit2.height());
    rectTextEdit3 = QRect((rectIco.x() + rectIco.width() + 10), rectTextEdit3.y(), rectTextEdit3.width(),
                          rectTextEdit3.height());
    ui->textEdit1->setGeometry(rectTextEdit1);
    ui->textEdit2->setGeometry(rectTextEdit2);
    ui->textEdit3->setGeometry(rectTextEdit3);

    if (moveFlag == true)
    {
        QMovie* movie = new QMovie(iocPix);
        ui->label_ico->setMovie(movie);
        movie->start();
    }
    else
    {
        QString styleSheet;
        styleSheet = "image: url(";
        styleSheet = styleSheet + iocPix;
        styleSheet = styleSheet + ");";
        ui->label_ico->setStyleSheet(styleSheet);
    }
}
/****************************************************************************
**
** 函数名称：IocMessage::on_btnOk_clicked
** 功能概述: OK按钮响应
** 参数说明  
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void IocMessage::on_btnOk_clicked()
{
    done(1);
    this->close();
}
/****************************************************************************
**
** 函数名称：IocMessage::on_btnCancel_clicked
** 功能概述: Cancel按钮响应
** 参数说明  
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void IocMessage::on_btnCancel_clicked()
{
    done(2);
    this->close();
}
/****************************************************************************
**
** 函数名称：IocMessage::keyPressEvent
** 功能概述: 键盘快捷键监听处理
** 参数说明  键值
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void IocMessage::keyPressEvent(QKeyEvent* event)
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

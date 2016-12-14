#include "messagebox.h"
#include "ui_messagebox.h"
/****************************************************************************
**
** 函数名称：MessageBox::MessageBox
** 功能概述: 初始化
** 参数说明 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
MessageBox::MessageBox(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::MessageBox)
{
    ui->setupUi(this);
    this->InitStyle();
}
/****************************************************************************
**
** 函数名称：MessageBox::～MessageBox
** 功能概述: 析构函数
** 参数说明 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
MessageBox::~MessageBox()
{
    delete ui;
}
/****************************************************************************
**
** 函数名称：MessageBox::mouseMoveEvent
** 功能概述: 
** 参数说明 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessageBox::mouseMoveEvent(QMouseEvent* e)
{
}
/****************************************************************************
**
** 函数名称：MessageBox::mousePressEvent
** 功能概述: 
** 参数说明 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessageBox::mousePressEvent(QMouseEvent* e)
{
}
/****************************************************************************
**
** 函数名称：MessageBox::mouseReleaseEvent
** 功能概述: 
** 参数说明 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessageBox::mouseReleaseEvent(QMouseEvent*)
{
    mousePressed = false;
}
/****************************************************************************
**
** 函数名称：MessageBox::InitStyle
** 功能概述: 初始化样式
** 参数说明 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessageBox::InitStyle()
{
    //this->setProperty("Form", true);
    //窗体居中显示
    this->mousePressed = false;
    //设置窗体标题栏隐藏
    this->setWindowFlags(Qt::FramelessWindowHint);
    connect(ui->okBtn, SIGNAL(clicked()), this, SLOT(on_btnOk_clicked()));
    connect(ui->okBtn_2, SIGNAL(clicked()), this, SLOT(on_btnOk_clicked()));
    connect(ui->cancelBtn, SIGNAL(clicked()), this, SLOT(close()));
}
/****************************************************************************
**
** 函数名称：MessageBox::InitStyle
** 功能概述: 设置标题内容和类型
** 参数说明 title：标题，msg：内容，type：类型
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessageBox::SetMessage(QString title, QString msg, int type)
{
    if (type == 0 || type == 2)
    {
        ui->cancelBtn->hide();
        ui->okBtn->hide();
    }
    else
    {
        ui->okBtn_2->hide();
    }

    ui->lab_Title->setText(title);
    ui->labInfo->setText(msg);
    this->setWindowTitle(ui->lab_Title->text());
}
/****************************************************************************
**
** 函数名称：MessageBox::on_btnOk_clicked
** 功能概述: 确定按钮响应
** 参数说明 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void MessageBox::on_btnOk_clicked()
{
    done(1);
    this->close();
}

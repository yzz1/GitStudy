#include "inputdialog.h"
#include "ui_inputdialog.h"
#include <QDesktopWidget>
#include <QEvent>
#include <QKeyEvent>
/****************************************************************************
**
** 函数名称：InputDialog::InputDialog
** 功能概述: 初始化
** 参数说明 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
InputDialog::InputDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::InputDialog)
{
    ui->setupUi(this);
    //设置窗体标题栏隐藏
    this->setWindowFlags(Qt::FramelessWindowHint);
    //关联关闭按钮
    connect(ui->okBtn, SIGNAL(clicked()), this, SLOT(on_btnOk_clicked()));
    connect(ui->cancelBtn, SIGNAL(clicked()), this, SLOT(close()));
    ui->lineEdit->setFocus();
}
/****************************************************************************
**
** 函数名称：InputDialog::~InputDialog
** 功能概述: 析构函数
** 参数说明 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
InputDialog::~InputDialog()
{
    delete ui;
}
/****************************************************************************
**
** 函数名称：InputDialog::SetTitle
** 功能概述: 设置标题
** 参数说明 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void InputDialog::SetTitle(QString title)
{
    ui->lab_Title->setText(title);
}
/****************************************************************************
**
** 函数名称：InputDialog::on_btnOk_clicked
** 功能概述: 确定按钮响应
** 参数说明 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void InputDialog::on_btnOk_clicked()
{
    done(1);
    this->close();
}
/****************************************************************************
**
** 函数名称：InputDialog::getTextContent
** 功能概述: 获取输入栏数据
** 参数说明 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QString InputDialog::getTextContent()
{
    return ui->lineEdit->text();
}
/****************************************************************************
**
** 函数名称：InputDialog::SetTextContent
** 功能概述: 插入输入栏数据
** 参数说明 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void  InputDialog::SetTextContent(QString text)
{
    ui->lineEdit->setText(text);
}
/****************************************************************************
**
** 函数名称：InputDialog::SetLineEditMaxLen
** 功能概述: 设置输入栏数据最大长度
** 参数说明 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void  InputDialog::SetLineEditMaxLen(int maxLen)
{
    return ui->lineEdit->setMaxLength(maxLen);
}


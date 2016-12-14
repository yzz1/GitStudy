#include "frequencyinput.h"
#include "ui_frequencyinput.h"
#include <QEvent>
#include <QKeyEvent>
#include <QDebug>
/****************************************************************************
**
** 函数名称：FrequencyInput::FrequencyInput
** 功能概述: 初始化
** 参数说明： 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
FrequencyInput::FrequencyInput(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::FrequencyInput)
{
    ui->setupUi(this);
    this->installEventFilter(this);
    m_editMode = false;
    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->lineEdit_5->hide();
    ui->lineEdit_6->hide();
    ui->lineEdit_7->hide();
    ui->lineEdit_8->hide();
    ui->lineEdit->setMaxLength(1);
    ui->lineEdit_2->setMaxLength(1);
    ui->lineEdit_3->setMaxLength(1);
    ui->lineEdit_4->setMaxLength(1);
    ui->lineEdit_5->setMaxLength(1);
    ui->lineEdit_6->setMaxLength(1);
    ui->lineEdit_7->setMaxLength(1);
    ui->lineEdit_8->setMaxLength(1);
    QRegExp rx("[0-9]");
    ui->lineEdit->setValidator(new QRegExpValidator(rx, this));
    ui->lineEdit_2->setValidator(new QRegExpValidator(rx, this));
    ui->lineEdit_3->setValidator(new QRegExpValidator(rx, this));
    ui->lineEdit_4->setValidator(new QRegExpValidator(rx, this));
    ui->lineEdit_5->setValidator(new QRegExpValidator(rx, this));
    ui->lineEdit_7->setValidator(new QRegExpValidator(rx, this));
    ui->lineEdit_8->setValidator(new QRegExpValidator(rx, this));
    editNum = 0;
    m_txOrRx = true;
}
/****************************************************************************
**
** 函数名称：FrequencyInput::~FrequencyInput
** 功能概述: 析构函数
** 参数说明： 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
FrequencyInput::~FrequencyInput()
{
    delete ui;
}
/****************************************************************************
**
** 函数名称：FrequencyInput::openEditmode
** 功能概述: 开启编辑模式
** 参数说明： tx或者是rx频率标记
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void FrequencyInput::openEditmode(bool txOrRx)
{
    m_txOrRx = txOrRx;
    m_editMode = true;
    QString str = ui->pushButton->text();

    if (str == "00000.00")//默认值处理
    {
        ui->lineEdit->setText(QString("0"));
        ui->lineEdit_2->setText(QString("0"));
        ui->lineEdit_3->setText(QString("0"));
        ui->lineEdit_4->setText(QString("0"));
        ui->lineEdit_5->setText(QString("0"));
        ui->lineEdit_6->setText(QString("."));
        ui->lineEdit_7->setText(QString("0"));
        ui->lineEdit_8->setText(QString("0"));
        m_oldStr = "";
    }
    else//把显示按钮的值填入到编辑框内。
    {
        m_oldStr = str;
        int flag = -1;
        int len = str.length();
        QStringList str1;

        if (len <= 0)
        {
            return;
        }

        for (int i = 0; i < len; i++)
        {
            QString str2(1, str[i]);

            if (str2 == ".")
            {
                flag = i;
            }

            str1 << str2;
        }

        if (flag == -1)//没有“.”号
        {
            ui->lineEdit_5->setText(str1.at(--len));

            if (len > 0)
                ui->lineEdit_4->setText(str1.at(--len));
            else
                ui->lineEdit_4->setText(QString("0"));

            if (len > 0)
                ui->lineEdit_3->setText(str1.at(--len));
            else
                ui->lineEdit_3->setText(QString("0"));

            if (len > 0)
                ui->lineEdit_2->setText(str1.at(--len));
            else
                ui->lineEdit_2->setText(QString("0"));

            if (len > 0)
                ui->lineEdit->setText(str1.at(--len));
            else
                ui->lineEdit->setText(QString("0"));

            ui->lineEdit_7->setText(QString("0"));
            ui->lineEdit_8->setText(QString("0"));
            ui->lineEdit_6->setText(QString("."));
        }
        else
        {
            ui->lineEdit_6->setText(QString("."));

            if (len > flag + 1)
                ui->lineEdit_7->setText(str1.at(flag + 1));
            else
                ui->lineEdit_7->setText(QString("0"));

            if (len > flag + 2)
                ui->lineEdit_8->setText(str1.at(flag + 2));
            else
                ui->lineEdit_8->setText(QString("0"));

            if (flag > 0)
                ui->lineEdit_5->setText(str1.at(--flag));
            else
                ui->lineEdit_5->setText(QString("0"));

            if (flag > 0)
                ui->lineEdit_4->setText(str1.at(--flag));
            else
                ui->lineEdit_4->setText(QString("0"));

            if (flag > 0)
                ui->lineEdit_3->setText(str1.at(--flag));
            else
                ui->lineEdit_3->setText(QString("0"));

            if (flag > 0)
                ui->lineEdit_2->setText(str1.at(--flag));
            else
                ui->lineEdit_2->setText(QString("0"));

            if (flag > 0)
                ui->lineEdit->setText(str1.at(--flag));
            else
                ui->lineEdit->setText(QString("0"));
        }
    }

    editNum = 0;
    ui->pushButton->setText(QString(""));
    ui->lineEdit->show();
    ui->lineEdit_2->show();
    ui->lineEdit_3->show();
    ui->lineEdit_4->show();
    ui->lineEdit_5->show();
    ui->lineEdit_6->show();
    ui->lineEdit_7->show();
    ui->lineEdit_8->show();
    ui->lineEdit->setStyleSheet(QString("color:rgb(0, 0, 0);background-color:white;"));
}
/****************************************************************************
**
** 函数名称：FrequencyInput::offEditmode
** 功能概述: 关闭编辑模式
** 参数说明： 是否保存标记
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void FrequencyInput::offEditmode(bool save)
{
    m_editMode = false;
    QStringList lineList;
    lineList << "lineEdit" << "lineEdit_2" << "lineEdit_3" << "lineEdit_4" << "lineEdit_5" << "lineEdit_7" << "lineEdit_8";
    QString str = getText();

    if (!save)//不保存，保留原值返回
    {
        ui->pushButton->setText(m_oldStr);
    }
    else
    {
        if (m_txOrRx)//TX和RX值范围分开处理
        {
            double num = str.toDouble();

            if (num < 1605 || num > 27500)
            {
                if (num == 0)
                    ui->pushButton->setText(QString(""));
                else
                    ui->pushButton->setText(m_oldStr);
            }
            else
            {
                ui->pushButton->setText(str);
            }
        }
        else
        {
            double num = str.toDouble();

            if (num < 500 || num > 30000)
            {
                if (num == 0)
                    ui->pushButton->setText(QString(""));
                else
                    ui->pushButton->setText(m_oldStr);
            }
            else
            {
                ui->pushButton->setText(str);
            }
        }
    }

    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->lineEdit_5->hide();
    ui->lineEdit_6->hide();
    ui->lineEdit_7->hide();
    ui->lineEdit_8->hide();
    QWidget* widget = findChild<QWidget*>(lineList.at(editNum));
    QLineEdit* edit = static_cast<QLineEdit*>(widget);
    edit->setStyleSheet(QString("    border:none;outline: none;    background: transparent;color:white;"));
    widgetSetFocus();
    editNum = 0;
}
/****************************************************************************
**
** 函数名称：FrequencyInput::editDataClean
** 功能概述: 清除数据
** 参数说明： 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void FrequencyInput::editDataClean()
{
    ui->lineEdit->setStyleSheet(QString("    border:none;outline: none;    background: transparent;color:white;"));
    ui->lineEdit_2->setStyleSheet(QString("    border:none;outline: none;    background: transparent;color:white;"));
    ui->lineEdit_3->setStyleSheet(QString("    border:none;outline: none;    background: transparent;color:white;"));
    ui->lineEdit_4->setStyleSheet(QString("    border:none;outline: none;    background: transparent;color:white;"));
    ui->lineEdit_5->setStyleSheet(QString("    border:none;outline: none;    background: transparent;color:white;"));
    ui->lineEdit_6->setStyleSheet(QString("    border:none;outline: none;    background: transparent;color:white;"));
    ui->lineEdit_7->setStyleSheet(QString("    border:none;outline: none;    background: transparent;color:white;"));
    ui->lineEdit_8->setStyleSheet(QString("    border:none;outline: none;    background: transparent;color:white;"));
    ui->lineEdit->setText(QString(""));
    ui->lineEdit_2->setText(QString(""));
    ui->lineEdit_3->setText(QString(""));
    ui->lineEdit_4->setText(QString(""));
    ui->lineEdit_5->setText(QString(""));
    ui->lineEdit_6->setText(QString(""));
    ui->lineEdit_7->setText(QString(""));
    ui->lineEdit_8->setText(QString(""));
    m_oldStr = "";
    m_txOrRx = true;
    editNum = 0;
    m_editMode = false;
    ui->pushButton->setStyleSheet(QString(" border: none;font-size: 16pt;color: rgb(105, 115, 119);"));
    ui->pushButton->setText(QString(""));
}
/****************************************************************************
**
** 函数名称：FrequencyInput::setData
** 功能概述: 填入数据
** 参数说明： 频率数据
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void FrequencyInput::setData(QString str)
{
    ui->pushButton->setText(str);
}
/****************************************************************************
**
** 函数名称：FrequencyInput::getData
** 功能概述: 获取字符串
** 参数说明： 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QString  FrequencyInput::getData()
{
    QString data = ui->pushButton->text();

    if (data == "00000.00")
    {
        data = "";
    }

    return data;
}
/****************************************************************************
**
** 函数名称：FrequencyInput::getText
** 功能概述: 转换数据成字符串
** 参数说明： 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QString  FrequencyInput::getText()
{
    QString text;
	//为空的格子自动补零
    if (ui->lineEdit->text() != "")
        text += ui->lineEdit->text();
    else
        text += "0";

    if (ui->lineEdit_2->text() != "")
        text += ui->lineEdit_2->text();
    else
        text += "0";

    if (ui->lineEdit_3->text() != "")
        text += ui->lineEdit_3->text();
    else
        text += "0";

    if (ui->lineEdit_4->text() != "")
        text += ui->lineEdit_4->text();
    else
        text += "0";

    if (ui->lineEdit_5->text() != "")
        text += ui->lineEdit_5->text();
    else
        text += "0";

    text += ui->lineEdit_6->text();

    if (ui->lineEdit_7->text() != "")
        text += ui->lineEdit_7->text();
    else
        text += "0";

    if (ui->lineEdit_8->text() != "")
        text += ui->lineEdit_8->text();
    else
        text += "0";

    QString text2;
    bool bFlag = false;

    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] != '0' || bFlag)//只提取第一位不是零的后续数据
        {
            bFlag = true;
            text2 += text[i];
        }
    }

    return text2;
}
/****************************************************************************
**
** 函数名称：FrequencyInput::widgetSetFocus
** 功能概述: 高亮控件
** 参数说明： 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void  FrequencyInput::widgetSetFocus()
{
    ui->pushButton->setStyleSheet(
        QString(" background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));border: none;font-size: 16pt;color: white;"));

    if (ui->pushButton->text() == "")
        ui->pushButton->setText(QString("00000.00"));
}
/****************************************************************************
**
** 函数名称：FrequencyInput::widgetCleanFocus
** 功能概述: 不高亮控件
** 参数说明： 
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void  FrequencyInput::widgetCleanFocus()
{
    ui->pushButton->setStyleSheet(QString(" border: none;font-size: 16pt;color: rgb(105, 115, 119);"));

    if (ui->pushButton->text() == "00000.00")
    {
        ui->pushButton->setText(QString(""));
    }
}
/****************************************************************************
**
** 函数名称：FrequencyInput::eventFilter
** 功能概述: 事件监听函数，响应用户键盘操作
** 参数说明：watched：发送方， event：事件数据
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool FrequencyInput::eventFilter(QObject* watched, QEvent* event)
{
    QStringList lineList;
    lineList << "lineEdit" << "lineEdit_2" << "lineEdit_3" << "lineEdit_4" << "lineEdit_5" << "lineEdit_7" << "lineEdit_8";
    QKeyEvent* key_event = static_cast<QKeyEvent*>(event);
    int a =   key_event->key();

    if (!m_editMode)//只在打开编辑模式后开始监听键盘操作
        return true;

    if (QEvent::KeyPress == event->type())
    {
        return true;
    }
    else if (QEvent::KeyRelease == event->type())
    {
        return true;
    }

    switch (a)
    {
    case Qt::Key_0:
    case Qt::Key_1:
    case Qt::Key_2:
    case Qt::Key_3:
    case Qt::Key_4:
    case Qt::Key_5:
    case Qt::Key_6:
    case Qt::Key_7:
    case Qt::Key_8:
    case Qt::Key_9:
    {
        if (51 != event->type())//只处理51类型的键值
        {
            return true;
        }

        QWidget* widget = findChild<QWidget*>(lineList.at(editNum));
        QLineEdit* edit = static_cast<QLineEdit*>(widget);
        edit->clear();
        edit->setText(QString::number(a - 0x30));

        if ((editNum + 1) < lineList.length())
        {
            QWidget* widget2 = findChild<QWidget*>(lineList.at(editNum + 1));
            QLineEdit* edit2 = static_cast<QLineEdit*>(widget2);

            if (edit2)
            {
                edit->setStyleSheet(QString("    border:none;outline: none;    background: transparent;color:white;"));
                edit2->setStyleSheet(QString("color:rgb(0, 0, 0);background-color:white;"));
                editNum++;
            }
        }

        break;
    }

    case Qt::Key_Right:
    case Qt::Key_Down:
    case Qt::Key_Tab:
    {
        QWidget* widget = findChild<QWidget*>(lineList.at(editNum));

        if (widget)
        {
            QLineEdit* edit = static_cast<QLineEdit*>(widget);
            edit->setStyleSheet(QString("    border:none;outline: none;    background: transparent;color:white;"));

            if ((editNum + 1) >= lineList.length())
            {
                editNum = 0;
            }
            else
            {
                editNum++;
            }

            QWidget* widget2 = findChild<QWidget*>(lineList.at(editNum));
            QLineEdit* edit2 = static_cast<QLineEdit*>(widget2);

            if (edit2)
            {
                edit2->setStyleSheet(QString("color:rgb(0, 0, 0);background-color:white;"));
            }
        }

        break;
    }

    case Qt::Key_Up:
    case Qt::Key_Backtab:
    case Qt::Key_Left:
    {
        QWidget* widget = findChild<QWidget*>(lineList.at(editNum));

        if (widget)
        {
            QLineEdit* edit = static_cast<QLineEdit*>(widget);
            edit->setStyleSheet(QString("    border:none;outline: none;    background: transparent;color:white;"));
            editNum--;

            if (editNum < 0)
            {
                editNum = lineList.length() - 1;
            }

            QWidget* widget2 = findChild<QWidget*>(lineList.at(editNum));
            QLineEdit* edit2 = static_cast<QLineEdit*>(widget2);

            if (edit2)
            {
                edit2->setStyleSheet(QString("color:rgb(0, 0, 0);background-color:white;"));
            }
        }

        break;
    }

    case Qt::Key_Return:
    case Qt::Key_Enter:
    {
        break;
    }

    case Qt::Key_Backspace:
    case Qt::Key_Delete:
    {
        QWidget* widget = findChild<QWidget*>(lineList.at(editNum));
        QLineEdit* edit = static_cast<QLineEdit*>(widget);
        edit->clear();
        break;
    }

    case Qt::Key_Escape:
    {
        break;
    }
    }

    if (a == Qt::Key_Escape)
        return true;

    return QWidget::eventFilter(watched, event);
}


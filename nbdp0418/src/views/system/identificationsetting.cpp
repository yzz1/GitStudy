#include "identificationsetting.h"
#include "ui_identificationsetting.h"
#include "views/common/constants.h"
#include <QEvent>
#include <QKeyEvent>
#include "widgets/button.h"
#include "core/utils/sqlitehelper.h"
#include <QSqlRecord>
#include "widgets/messagebox.h"
#include "logging.h"
#include "../transit/transit.h"
/****************************************************************************
**
** 函数名称：IdentificationSetting::IdentificationSetting
** 功能概述: 初始化
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
IdentificationSetting::IdentificationSetting(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::IdentificationSetting)
{
    Logging::get()->info("IdentificationSetting::IdentificationSetting");
    ui->setupUi(this);
    m_NumEdit = 1;
    m_model = new ContactsModel(this, SQLiteHelper::openConnection());
    m_model->setTable(Constants::SYSTEM_SETTING_TABLE_NAME);
    m_model->select();
    QSqlRecord  sqlRecord = m_model->record(0);
    QString digitcallcode = sqlRecord.value(SYSTEM_SETTING_DIGITCALLCODE).toString();
    QString mmsicode = sqlRecord.value(SYSTEM_SETTING_MMSICODE).toString();
    QString answerbackcode = sqlRecord.value(SYSTEM_SETTING_ANSWERBACKCODE).toString();



    if (digitcallcode != "")
    {
        QString d(1, digitcallcode[0]);
        ui->lineEdit_4->setText(d);
        QString d2(1, digitcallcode[1]);
        ui->lineEdit_5->setText(d2);
        QString d3(1, digitcallcode[2]);
        ui->lineEdit_6->setText(d3);
        QString d4(1, digitcallcode[3]);
        ui->lineEdit_7->setText(d4);
        QString d5(1, digitcallcode[4]);
        ui->lineEdit_8->setText(d5);
    }
    
    if (mmsicode != "")
    {
        QString m(1, mmsicode[0]);
        ui->lineEdit_12->setText(m);
        QString m2(1, mmsicode[1]);
        ui->lineEdit_13->setText(m2);
        QString m3(1, mmsicode[2]);
        ui->lineEdit_14->setText(m3);
        QString m4(1, mmsicode[3]);
        ui->lineEdit_15->setText(m4);
        QString m5(1, mmsicode[4]);
        ui->lineEdit_16->setText(m5);
        QString m6(1, mmsicode[5]);
        ui->lineEdit_17->setText(m6);
        QString m7(1, mmsicode[6]);
        ui->lineEdit_18->setText(m7);
        QString m8(1, mmsicode[7]);
        ui->lineEdit_19->setText(m8);
        QString m9(1, mmsicode[8]);
        ui->lineEdit_20->setText(m);
    }
    
    if (answerbackcode != "")
    {
        ui->lineEdit->setText(answerbackcode);
    }
    
    ui->tiltewidget->setText(Constants::SYSTEM_IDENTIFICATION_SETTING_TITLE);
    QFont fontfirst("Ubuntu", 18, QFont::Bold);
    QFont font("Ubuntu", 15, QFont::Bold);
    ui->numFocus->setFocus();
    ui->listWidget->addItem(SYSTEM_SETTING_DIGITCALLCODELABEL);
    ui->listWidget->item(0)->setFont(fontfirst);
    ui->listWidget->setCurrentRow(0);
    ui->listWidget_2->addItem(SYSTEM_SETTING_DIGITMMSICODELABEL);
    ui->listWidget_2->item(0)->setFont(font);
    ui->listWidget_3->addItem(SYSTEM_SETTING_ANSWERBACKCODELABEL);
    ui->listWidget_3->item(0)->setFont(font);
    QString styleStr =
        "QLineEdit{border:none;outline: none;background: transparent;color: white;background-color :qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255))}"
        "QLineEdit:focus{color:rgb(0, 0, 0);background-color:white;}"
        "QLineEdit:selected{color:rgb(0, 0, 0);background-color:white;}";
    QRegExp rx("[0-9]");
    //  QRegExp rx1("([0-9A-Z)");
    ui-> lineEdit_4->setValidator(new QRegExpValidator(rx, this));
    ui->lineEdit_4->setMaxLength(1);
    ui-> lineEdit_4->setValidator(new QRegExpValidator(rx, this));
    ui->lineEdit_4->setStyleSheet(styleStr);
    ui->lineEdit_4->setFocus();
    ui->lineEdit_5->setMaxLength(1);
    ui->lineEdit_5->setStyleSheet(styleStr);
    ui-> lineEdit_5->setValidator(new QRegExpValidator(rx, this));
    ui->lineEdit_6->setMaxLength(1);
    ui->lineEdit_6->setStyleSheet(styleStr);
    ui-> lineEdit_6->setValidator(new QRegExpValidator(rx, this));
    ui->lineEdit_7->setMaxLength(1);
    ui->lineEdit_7->setStyleSheet(styleStr);
    ui-> lineEdit_7->setValidator(new QRegExpValidator(rx, this));
    ui->lineEdit_8->setMaxLength(1);
    ui->lineEdit_8->setStyleSheet(styleStr);
    ui-> lineEdit_8->setValidator(new QRegExpValidator(rx, this));
    ui->lineEdit_9->setStyleSheet(styleStr);
    ui->lineEdit_10->setStyleSheet(styleStr);
    ui-> lineEdit_12->setValidator(new QRegExpValidator(rx, this));
    ui-> lineEdit_13->setValidator(new QRegExpValidator(rx, this));
    ui-> lineEdit_14->setValidator(new QRegExpValidator(rx, this));
    ui-> lineEdit_15->setValidator(new QRegExpValidator(rx, this));
    ui-> lineEdit_16->setValidator(new QRegExpValidator(rx, this));
    ui-> lineEdit_17->setValidator(new QRegExpValidator(rx, this));
    ui-> lineEdit_18->setValidator(new QRegExpValidator(rx, this));
    ui-> lineEdit_19->setValidator(new QRegExpValidator(rx, this));
    ui-> lineEdit_20->setValidator(new QRegExpValidator(rx, this));
    ui-> lineEdit_12->setMaxLength(1);
    ui-> lineEdit_13->setMaxLength(1);
    ui-> lineEdit_14->setMaxLength(1);
    ui-> lineEdit_15->setMaxLength(1);
    ui-> lineEdit_16->setMaxLength(1);
    ui-> lineEdit_17->setMaxLength(1);
    ui-> lineEdit_18->setMaxLength(1);
    ui-> lineEdit_19->setMaxLength(1);
    ui-> lineEdit_20->setMaxLength(1);
    ui-> lineEdit->setMaxLength(20);
    this->installEventFilter(this);
    connect(ui->homeTBnt, SIGNAL(clicked()), this, SLOT(homeClickedSlot()));
    connect(ui->settingTBtn, SIGNAL(clicked()), this, SLOT(settingClickedSlot()));
    connect(ui->testTBtn, SIGNAL(clicked()), this, SLOT(testClickedSlot()));
    connect(ui->aboutTBtn, SIGNAL(clicked()), this, SLOT(aboutClickedSlot()));
    connect(ui->okBtn, SIGNAL(clicked()), this, SLOT(okButtonClickedSlot()));
    connect(ui->cancelBtn, SIGNAL(clicked()), this, SLOT(cancelButtonClickedSlot()));

    this->digitcallcode=digitcallcode;
    this->mmsicode = mmsicode;
    this->answerbackcode =answerbackcode;
    QTimer::singleShot( 2000,this,SLOT(slotSendDeviceInfo()));

}

void IdentificationSetting::slotSendDeviceInfo()
{
     Transit::get()->EmitSignalReflashDeviceInfo(digitcallcode,mmsicode,answerbackcode);
}
/****************************************************************************
**
** 函数名称：IdentificationSetting::eventFilter
** 功能概述: 事件监听函数，响应用户键盘操作
** 参数说明 watched：发送方， event：事件数据
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool IdentificationSetting::eventFilter(QObject* watched, QEvent* event)
{
    Logging::get()->info("IdentificationSetting::eventFilter");
    //画面控件光标切换
    QStringList nameList;
    nameList << "numFocus" << "numFocus2"
             << "numFocus3" << "okBtn" << "cancelBtn" << "homeTBnt" << "settingTBtn" << "testTBtn" << "aboutTBtn";

    //4 or 5-digit Call Code 的子编辑框光标切换
    QStringList lineList;
    lineList << "lineEdit_4" << "lineEdit_5" << "lineEdit_6" << "lineEdit_7" << "lineEdit_8";

    //9-digit MMSI Code 的子编辑框光标切换
    QStringList lineList2;
    lineList2 << "lineEdit_12" << "lineEdit_13" << "lineEdit_14" << "lineEdit_15" << "lineEdit_16" << "lineEdit_17" <<
              "lineEdit_18" << "lineEdit_19" << "lineEdit_20";

    QKeyEvent* key_event = static_cast<QKeyEvent*>(event);
    int a =   key_event->key();
    //按键触发三种类型键值：51，按下，弹起。部分按键，按下类型不处理，51类型不处理，弹起时处理
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
        if (QEvent::KeyPress == event->type())//9-digit MMSI Code 的子编辑框光标切换
        {
            return true;
        }
        else if (51 == event->type())// 默认键值51 屏蔽
        {
            return true;
        }
        
        if (m_NumEdit >= 1 && m_NumEdit <= 2)//当前光标在三个编辑CODE区域
        {
            QStringList list;
            
            if (m_NumEdit == 1)//4 or 5-digit Call Code 的子编辑框光标切换
            {
                list = lineList;
            }
            else if (m_NumEdit == 2)//9-digit MMSI Code 的子编辑框光标切换
            {
                list = lineList2;
            }
            
            //子编辑框光标切换
            for (int i = 0; i < list.length(); i++)
            {
                QWidget* widget = findChild<QWidget*>(list.at(i));
                
                if (widget && widget->hasFocus())
                {
                    QLineEdit* edit = static_cast<QLineEdit*>(widget);
                    edit->clear();
                    edit->setText(QString::number(a - 0x30));
                    
                    if ((i + 1) < list.length())
                    {
                        QWidget* widget2 = findChild<QWidget*>(list.at(i + 1));
                        
                        if (widget2)
                            widget2->setFocus();
                    }
                    
                    break;
                }
            }
        }
        
        break;
    }
    
    case Qt::Key_Right:
    case Qt::Key_Down:
    case Qt::Key_Tab:
    {
        if (QEvent::KeyPress == event->type())// 按下时键屏蔽
        {
            return true;
        }
        else if (51 == event->type()  && a != Qt::Key_Right)// 默认键值51 屏蔽
        {
            return true;
        }
        else if (51 == event->type() &&  m_NumEdit == 0)// 默认键值51 屏蔽
        {
            return true;
        }
        
        int next = 0;
        
        if (m_NumEdit >= 1 && m_NumEdit <= 3 && a == Qt::Key_Right)//左右键移动编辑单元，否则移动到下个CODE编辑栏
        {
            QStringList list;
            
            if (m_NumEdit == 1)//4 or 5-digit Call Code 的子编辑框光标切换
            {
                list = lineList;
            }
            else if (m_NumEdit == 2)//9-digit MMSI Code 的子编辑框光标切换
            {
                list = lineList2;
            }
            else if (m_NumEdit == 3)//Answer Back Code编辑框没有子编辑框
            {
                break;
            }
            //子编辑框光标切换
            for (int i = 0; i < list.length(); i++)
            {
                QWidget* widget = findChild<QWidget*>(list.at(i));
                
                if (widget && widget->hasFocus())
                {
                    next = (i == list.length() - 1) ? 0 : i + 1;
                    break;
                }
            }
            
            if (list.length())
            {
                QWidget* widgetnext = findChild<QWidget*>(list.at(next));
                
                if (widgetnext)
                {
                    widgetnext->setFocus();
                }
            }
        }
        else
        {
            // 按钮图片切换 focus 离开 按钮图片变暗
            for (int i = 0; i < nameList.length(); i++)
            {
                QWidget* widget = findChild<QWidget*>(nameList.at(i));
                
                if (widget && widget->hasFocus())
                {
                    if (nameList.at(i) == "homeTBnt")
                    {
                        QToolButton* button = static_cast<QToolButton*>(widget);
                        button->setIcon(QIcon(":/images/home_normal"));
                    }
                    else if (nameList.at(i) == "settingTBtn")
                    {
                        QToolButton* button = static_cast<QToolButton*>(widget);
                        button->setIcon(QIcon(":/images/System_SetBtn_SelNo"));
                    }
                    else if (nameList.at(i) == "testTBtn")
                    {
                        QToolButton* button = static_cast<QToolButton*>(widget);
                        button->setIcon(QIcon(":/images/System_TestBtn_SelNo"));
                    }
                    else if (nameList.at(i) == "aboutTBtn")
                    {
                        QToolButton* button = static_cast<QToolButton*>(widget);
                        button->setIcon(QIcon(":/images/System_AboutBtn_SelNo"));
                    }
                    
                    next = (i == nameList.length() - 1) ? 0 : i + 1;
                    break;
                }
                else if (m_NumEdit >= 1 && m_NumEdit <= 3)//  focus 离开 编辑框字体变更
                {
                    next = m_NumEdit;
                    
                    switch (m_NumEdit - 1)
                    {
                    case 0:
                    {
                        ui->listWidget->setCurrentRow(-1);
                        QFont font("Ubuntu", 15, QFont::Bold);
                        ui->listWidget->item(0)->setFont(font);
                        break;
                    }
                    
                    case 1:
                    {
                        ui->listWidget_2->setCurrentRow(-1);
                        QFont font("Ubuntu", 15, QFont::Bold);
                        ui->listWidget_2->item(0)->setFont(font);
                        break;
                    }
                    
                    case 2:
                    {
                        ui->listWidget_3->setCurrentRow(-1);
                        QFont font("Ubuntu", 15, QFont::Bold);
                        ui->listWidget_3->item(0)->setFont(font);
                        break;
                    }
                    break;
                    }
                    
                    break;
                }
            }
            
            if (m_NumEdit > 3 || m_NumEdit == 0)//光标不在编辑CODE区域
            {
                m_NumEdit = 0;
            }
            else	//编辑下一个CODE时隐藏上一个CODE的颜色样式
            {
                QString styleStr =
                    "QLineEdit{border:none;outline: none;background: transparent;color: rgb(105, 115, 119);background-color :transparent;}"
                    "QLineEdit:focus{color:rgb(0, 0, 0);background-color:white;}"
                    "QLineEdit:selected{color:rgb(0, 0, 0);background-color:white;}";
                    
                if (m_NumEdit == 1) //4 or 5-digit Call Code 的编辑框切换颜色
                {
                    ui->lineEdit_4->setStyleSheet(styleStr);
                    ui->lineEdit_5->setStyleSheet(styleStr);
                    ui->lineEdit_6->setStyleSheet(styleStr);
                    ui->lineEdit_7->setStyleSheet(styleStr);
                    ui->lineEdit_8->setStyleSheet(styleStr);
                    ui->lineEdit_9->hide();
                    ui->lineEdit_10->hide();
                }
                else if (m_NumEdit == 2)//9-digit MMSI Code 的编辑框切换颜色
                {
                    ui->lineEdit_12->setStyleSheet(styleStr);
                    ui->lineEdit_13->setStyleSheet(styleStr);
                    ui->lineEdit_14->setStyleSheet(styleStr);
                    ui->lineEdit_15->setStyleSheet(styleStr);
                    ui->lineEdit_16->setStyleSheet(styleStr);
                    ui->lineEdit_17->setStyleSheet(styleStr);
                    ui->lineEdit_18->setStyleSheet(styleStr);
                    ui->lineEdit_19->setStyleSheet(styleStr);
                    ui->lineEdit_20->setStyleSheet(styleStr);
                    ui->lineEdit_11->hide();
                    ui->lineEdit_21->hide();
                }
                else if (m_NumEdit == 3)//Answer Back Code 的编辑框切换颜色
                {
                    ui->lineEdit->setStyleSheet(styleStr);
                }
                
                m_NumEdit++;
            }
            
            QWidget* widgetnext = findChild<QWidget*>(nameList.at(next));
            
            if (widgetnext)// 按钮图片切换 focus 获得 按钮图片亮
            {
                widgetnext->setFocus();
                
                if (nameList.at(next) == "numFocus")
                {
                    m_NumEdit = 1;
                }
                else if (m_NumEdit >= 2 && m_NumEdit <= 3)
                {
                    next = m_NumEdit - 1;
                }
                else if (nameList.at(next) == "homeTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widgetnext);
                    button->setIcon(QIcon(":/images/home_hover"));
                }
                else if (nameList.at(next) == "settingTBtn")
                {
                    QToolButton* button = static_cast<QToolButton*>(widgetnext);
                    button->setIcon(QIcon(":/images/System_SetBtn_SelYes"));
                }
                else if (nameList.at(next) == "testTBtn")
                {
                    QToolButton* button = static_cast<QToolButton*>(widgetnext);
                    button->setIcon(QIcon(":/images/System_TestBtn_SelYes"));
                }
                else if (nameList.at(next) == "aboutTBtn")
                {
                    QToolButton* button = static_cast<QToolButton*>(widgetnext);
                    button->setIcon(QIcon(":/images/System_AboutBtn_SelYes"));
                }
                
                if (next >= 0 && next <= 2)
                {
                    switch (next)//focus 获得 编辑框字体亮
                    {
                    case 0:
                    {
                        ui->listWidget->setCurrentRow(0);
                        QFont font("Ubuntu", 18, QFont::Bold);
                        ui->listWidget->item(0)->setFont(font);
                        break;
                    }
                    
                    case 1:
                    {
                        ui->listWidget_2->setCurrentRow(0);
                        QFont font("Ubuntu", 18, QFont::Bold);
                        ui->listWidget_2->item(0)->setFont(font);
                        break;
                    }
                    
                    case 2:
                    {
                        ui->listWidget_3->setCurrentRow(0);
                        QFont font("Ubuntu", 18, QFont::Bold);
                        ui->listWidget_3->item(0)->setFont(font);
                        break;
                    }
                    break;
                    }
                }
                
                if (m_NumEdit >= 1 && m_NumEdit <= 3)//高亮下一个准备编辑的CODE编辑栏样式
                {
                    QStringList list;
                    QString styleStr =
                        "QLineEdit{border:none;outline: none;background: transparent;color: white;background-color :qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255))}"
                        "QLineEdit:focus{color:rgb(0, 0, 0);background-color:white;}"
                        "QLineEdit:selected{color:rgb(0, 0, 0);background-color:white;}";
                        
                    if (m_NumEdit == 1)//4 or 5-digit Call Code 的编辑框
                    {
                        ui->lineEdit_4->setStyleSheet(styleStr);
                        ui->lineEdit_4->setFocus();
                        ui->lineEdit_5->setStyleSheet(styleStr);
                        ui->lineEdit_6->setStyleSheet(styleStr);
                        ui->lineEdit_7->setStyleSheet(styleStr);
                        ui->lineEdit_8->setStyleSheet(styleStr);
                        ui->lineEdit_9->setStyleSheet(styleStr);
                        ui->lineEdit_9->show();
                        ui->lineEdit_10->setStyleSheet(styleStr);
                        ui->lineEdit_10->show();
                    }
                    else if (m_NumEdit == 2)//9-digit MMSI Code 的编辑框
                    {
                        ui->lineEdit_12->setStyleSheet(styleStr);
                        ui->lineEdit_12->setFocus();
                        ui->lineEdit_13->setStyleSheet(styleStr);
                        ui->lineEdit_14->setStyleSheet(styleStr);
                        ui->lineEdit_15->setStyleSheet(styleStr);
                        ui->lineEdit_16->setStyleSheet(styleStr);
                        ui->lineEdit_17->setStyleSheet(styleStr);
                        ui->lineEdit_18->setStyleSheet(styleStr);
                        ui->lineEdit_19->setStyleSheet(styleStr);
                        ui->lineEdit_20->setStyleSheet(styleStr);
                        ui->lineEdit_11->setStyleSheet(styleStr);
                        ui->lineEdit_11->show();
                        ui->lineEdit_21->setStyleSheet(styleStr);
                        ui->lineEdit_21->show();
                    }
                    else if (m_NumEdit == 3)//Answer Back Code 的编辑框
                    {
                        ui->lineEdit->setStyleSheet(styleStr);
                        ui->lineEdit->setFocus();
                    }
                }
                else
                    m_NumEdit = 0;
            }
        }
        
        break;
    }
    
    case Qt::Key_Up:
    case Qt::Key_Backtab:
    case Qt::Key_Left:
    {
        if (QEvent::KeyPress == event->type())// 按下时键屏蔽
        {
            return true;
        }
        else if (51 == event->type()  && a != Qt::Key_Left)// 默认键值51 屏蔽
        {
            return true;
        }
        else if (51 == event->type() &&  m_NumEdit == 0)//只在编辑CODE时处理51类型的按键键值
        {
            return true;
        }
        
        int prev = 0;
        
        if (m_NumEdit >= 1 && m_NumEdit <= 3 && a == Qt::Key_Left)
        {
            QStringList list;
            
            if (m_NumEdit == 1)//4 or 5-digit Call Code 的子编辑框光标切换
            {
                list = lineList;
            }
            else if (m_NumEdit == 2)//9-digit MMSI Code 的子编辑框光标切换
            {
                list = lineList2;
            }
            else if (m_NumEdit == 3)//Answer Back Code编辑框没有子编辑框
            {
                break;
            }
            //子编辑框光标切换
            for (int i = 0; i < list.length(); i++)
            {
                QWidget* widget = findChild<QWidget*>(list.at(i));
                
                if (widget && widget->hasFocus())
                {
                    prev = (i == 0) ? list.length() - 1 : i - 1;
                    break;
                }
            }
            
            if (list.length())
            {
                QWidget* widgetprev = findChild<QWidget*>(list.at(prev));
                
                if (widgetprev)
                {
                    widgetprev->setFocus();
                }
            }
        }
        else
        {
            for (int i = 0; i < nameList.length(); i++)
            {
                QWidget* widget = findChild<QWidget*>(nameList.at(i));
                
                // 按钮图片切换 focus 离开 按钮图片变暗
                if (widget && widget->hasFocus())
                {
                    if (nameList.at(i) == "homeTBnt")
                    {
                        QToolButton* button = static_cast<QToolButton*>(widget);
                        button->setIcon(QIcon(":/images/home_normal"));
                    }
                    else if (nameList.at(i) == "settingTBtn")
                    {
                        QToolButton* button = static_cast<QToolButton*>(widget);
                        button->setIcon(QIcon(":/images/System_SetBtn_SelNo"));
                    }
                    else if (nameList.at(i) == "testTBtn")
                    {
                        QToolButton* button = static_cast<QToolButton*>(widget);
                        button->setIcon(QIcon(":/images/System_TestBtn_SelNo"));
                    }
                    else if (nameList.at(i) == "aboutTBtn")
                    {
                        QToolButton* button = static_cast<QToolButton*>(widget);
                        button->setIcon(QIcon(":/images/System_AboutBtn_SelNo"));
                    }
                    prev = (i == 0) ? nameList.length() - 1 : i - 1;
                    break;
                }
                //focus 离开 编辑框字体变更
                else if (m_NumEdit >= 1 && m_NumEdit <= 3)
                {
                    prev = (m_NumEdit <= 1) ? nameList.length() - 1 : m_NumEdit - 2;
                    
                    switch (m_NumEdit - 1)
                    {
                    case 0:
                    {
                        ui->listWidget->setCurrentRow(-1);
                        QFont font("Ubuntu", 15, QFont::Bold);
                        ui->listWidget->item(0)->setFont(font);
                        break;
                    }
                    
                    case 1:
                    {
                        ui->listWidget_2->setCurrentRow(-1);
                        QFont font("Ubuntu", 15, QFont::Bold);
                        ui->listWidget_2->item(0)->setFont(font);
                        break;
                    }
                    
                    case 2:
                    {
                        ui->listWidget_3->setCurrentRow(-1);
                        QFont font("Ubuntu", 15, QFont::Bold);
                        ui->listWidget_3->item(0)->setFont(font);
                        break;
                    }
                    break;
                    }
                    
                    break;
                }
            }
            
            if (m_NumEdit > 3 || m_NumEdit == 0)
            {
                m_NumEdit = 0;
            }
            else
            {
                QString styleStr =
                    "QLineEdit{border:none;outline: none;background: transparent;color: rgb(105, 115, 119);background-color :transparent;}"
                    "QLineEdit:focus{color:rgb(0, 0, 0);background-color:white;}"
                    "QLineEdit:selected{color:rgb(0, 0, 0);background-color:white;}";
                    
                if (m_NumEdit == 1)//4 or 5-digit Call Code 的子编辑框颜色切换
                {
                    ui->lineEdit_4->setStyleSheet(styleStr);
                    ui->lineEdit_5->setStyleSheet(styleStr);
                    ui->lineEdit_6->setStyleSheet(styleStr);
                    ui->lineEdit_7->setStyleSheet(styleStr);
                    ui->lineEdit_8->setStyleSheet(styleStr);
                    ui->lineEdit_9->hide();
                    ui->lineEdit_10->hide();
                }
                else if (m_NumEdit == 2)//9-digit MMSI Code 的子编辑框颜色切换
                {
                    ui->lineEdit_12->setStyleSheet(styleStr);
                    ui->lineEdit_13->setStyleSheet(styleStr);
                    ui->lineEdit_14->setStyleSheet(styleStr);
                    ui->lineEdit_15->setStyleSheet(styleStr);
                    ui->lineEdit_16->setStyleSheet(styleStr);
                    ui->lineEdit_17->setStyleSheet(styleStr);
                    ui->lineEdit_18->setStyleSheet(styleStr);
                    ui->lineEdit_19->setStyleSheet(styleStr);
                    ui->lineEdit_20->setStyleSheet(styleStr);
                    ui->lineEdit_11->hide();
                    ui->lineEdit_21->hide();
                }
                else if (m_NumEdit == 3)
                {
                    ui->lineEdit->setStyleSheet(styleStr);
                }
                
                m_NumEdit--;
            }
            
            QWidget* widgetprev = findChild<QWidget*>(nameList.at(prev));
            widgetprev->setFocus();
            
            if (widgetprev)
            {
                //// 按钮图片切换 focus 获得 按钮图片亮
                widgetprev->setFocus();
                
                if (nameList.at(prev) == "numFocus3")
                {
                    m_NumEdit = 3;
                }
                else if (m_NumEdit >= 1 && m_NumEdit <= 2)
                {
                    prev = m_NumEdit - 1;
                }
                
                if (nameList.at(prev) == "homeTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widgetprev);
                    button->setIcon(QIcon(":/images/home_hover"));
                }
                else if (nameList.at(prev) == "settingTBtn")
                {
                    QToolButton* button = static_cast<QToolButton*>(widgetprev);
                    button->setIcon(QIcon(":/images/System_SetBtn_SelYes"));
                }
                else if (nameList.at(prev) == "testTBtn")
                {
                    QToolButton* button = static_cast<QToolButton*>(widgetprev);
                    button->setIcon(QIcon(":/images/System_TestBtn_SelYes"));
                }
                else if (nameList.at(prev) == "aboutTBtn")
                {
                    QToolButton* button = static_cast<QToolButton*>(widgetprev);
                    button->setIcon(QIcon(":/images/System_AboutBtn_SelYes"));
                }
                
                if (prev >= 0 && prev <= 2)
                {
                    switch (prev)//focus 获得 编辑框字体变更
                    {
                    case 0:
                    {
                        ui->listWidget->setCurrentRow(0);
                        QFont font("Ubuntu", 18, QFont::Bold);
                        ui->listWidget->item(0)->setFont(font);
                        break;
                    }
                    
                    case 1:
                    {
                        ui->listWidget_2->setCurrentRow(0);
                        QFont font("Ubuntu", 18, QFont::Bold);
                        //   QString str = tr("9-digit MMSI Code");
                        //    ui->listWidget_2->currentItem()->setText(str);
                        ui->listWidget_2->item(0)->setFont(font);
                        break;
                    }
                    
                    case 2:
                    {
                        ui->listWidget_3->setCurrentRow(0);
                        QFont font("Ubuntu", 18, QFont::Bold);
                        // QString str = tr("Answer Back Code");
                        //  ui->listWidget->currentItem()->setText(str);
                        ui->listWidget_3->item(0)->setFont(font);
                        break;
                    }
                    break;
                    }
                }
                
                if (m_NumEdit >= 1 && m_NumEdit <= 3)
                {
                    QStringList list;
                    QString styleStr =
                        "QLineEdit{border:none;outline: none;background: transparent;color: white;background-color :qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255))}"
                        "QLineEdit:focus{color:rgb(0, 0, 0);background-color:white;}"
                        "QLineEdit:selected{color:rgb(0, 0, 0);background-color:white;}";
                        
                    if (m_NumEdit == 1)//4 or 5-digit Call Code 编辑框背景颜色切换
                    {
                        ui->lineEdit_4->setStyleSheet(styleStr);
                        ui->lineEdit_4->setFocus();
                        ui->lineEdit_5->setStyleSheet(styleStr);
                        ui->lineEdit_6->setStyleSheet(styleStr);
                        ui->lineEdit_7->setStyleSheet(styleStr);
                        ui->lineEdit_8->setStyleSheet(styleStr);
                        ui->lineEdit_9->setStyleSheet(styleStr);
                        ui->lineEdit_9->show();
                        ui->lineEdit_10->setStyleSheet(styleStr);
                        ui->lineEdit_10->show();
                    }
                    else if (m_NumEdit == 2)//9-digit MMSI Code 编辑框背景颜色切换
                    {
                        ui->lineEdit_12->setStyleSheet(styleStr);
                        ui->lineEdit_12->setFocus();
                        ui->lineEdit_13->setStyleSheet(styleStr);
                        ui->lineEdit_14->setStyleSheet(styleStr);
                        ui->lineEdit_15->setStyleSheet(styleStr);
                        ui->lineEdit_16->setStyleSheet(styleStr);
                        ui->lineEdit_17->setStyleSheet(styleStr);
                        ui->lineEdit_18->setStyleSheet(styleStr);
                        ui->lineEdit_19->setStyleSheet(styleStr);
                        ui->lineEdit_20->setStyleSheet(styleStr);
                        ui->lineEdit_11->setStyleSheet(styleStr);
                        ui->lineEdit_11->show();
                        ui->lineEdit_21->setStyleSheet(styleStr);
                        ui->lineEdit_21->show();
                    }
                    else if (m_NumEdit == 3)//Answer Back Code 编辑框背景颜色切换
                    {
                        ui->lineEdit->setStyleSheet(styleStr);
                        ui->lineEdit->setFocus();
                    }
                }
            }
        }
        
        break;
    }
    
    case Qt::Key_Return:
    case Qt::Key_Enter:
    {
        if (QEvent::KeyPress == event->type())// 按下时键屏蔽
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type())// 弹起时键屏蔽
        {
            return true;
        }
        // 默认键值51 响应一次
        // 按钮响应Enter 事件
        for (int i = 0; i < nameList.length(); i++)
        {
            QWidget* widget = findChild<QWidget*>(nameList.at(i));
            
            if (widget && widget->hasFocus())
            {
                if (nameList.at(i) == "homeTBnt")
                {
                    QWidget* widget = findChild<QWidget*>("homeTBnt");
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                }
                else if (nameList.at(i) == "settingTBtn")
                {
                    QWidget* widget = findChild<QWidget*>("settingTBtn");
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                }
                else if (nameList.at(i) == "testTBtn")
                {
                    QWidget* widget = findChild<QWidget*>("testTBtn");
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                }
                else if (nameList.at(i) == "aboutTBtn")
                {
                    QWidget* widget = findChild<QWidget*>("aboutTBtn");
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                }
                else if (nameList.at(i) == "numFocus2")
                {
                    m_NumEdit = true;
                }
                
                break;
            }
        }
        
        break;
    }
    // 响应 ESC事件
    case Qt::Key_Escape:
    {
        if (QEvent::KeyPress == event->type())
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type())
        {
            return true;
        }
        
        QWidget* widget = findChild<QWidget*>("cancelBtn");
        
        if (widget)
        {
            Button* button = static_cast<Button*>(widget);
            button->click();
        }
        
        break;
    }
    }
    
    if (a == Qt::Key_Escape)
        return true;
        
    return QWidget::eventFilter(watched, event);
}
/****************************************************************************
**
** 函数名称：IdentificationSetting::okButtonClickedSlot
** 功能概述: 确认保存
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void IdentificationSetting::okButtonClickedSlot()
{
    Logging::get()->info("IdentificationSetting::okButtonClickedSlot");
    QMap <QString, QString>paraMap;
    QString str;
    int count = 5;
    
    if (ui->lineEdit_4->text() == "" || ui->lineEdit_4->text() == " ")
    {
        count--;
    }
    
    if (ui->lineEdit_5->text() == "" || ui->lineEdit_5->text() == " ")
    {
        count--;
    }
    
    if (ui->lineEdit_6->text() == "" || ui->lineEdit_6->text() == " ")
    {
        count--;
    }
    
    if (ui->lineEdit_7->text() == "" || ui->lineEdit_7->text() == " ")
    {
        count--;
    }
    
    if (ui->lineEdit_8->text() == "" || ui->lineEdit_8->text() == " ")
    {
        count--;
    }
    
    if (count < 4)
    {
        MessageBox  msg;
        msg.move((SCREEN_SIZE_WIDTH - msg.width()) / 2, (SCREEN_SIZE_HEIGHT - msg.height()) / 2);
        msg.SetMessage(tr("Error"), tr("4 or 5-digit Call Code must be 4 or 5 number !"), 0);
        msg.exec() ;
        return;
    }
    
    str += ui->lineEdit_4->text();
    str += ui->lineEdit_5->text();
    str += ui->lineEdit_6->text();
    str += ui->lineEdit_7->text();
    str += ui->lineEdit_8->text();
    paraMap.insert(SYSTEM_SETTING_DIGITCALLCODE, str);
    
    if ((ui->lineEdit_12->text() == "" || ui->lineEdit_12->text() == " ")
        || (ui->lineEdit_13->text() == "" || ui->lineEdit_13->text() == " ")
        || (ui->lineEdit_14->text() == "" || ui->lineEdit_14->text() == " ")
        || (ui->lineEdit_15->text() == "" || ui->lineEdit_15->text() == " ")
        || (ui->lineEdit_16->text() == "" || ui->lineEdit_16->text() == " ")
        || (ui->lineEdit_17->text() == "" || ui->lineEdit_17->text() == " ")
        || (ui->lineEdit_18->text() == "" || ui->lineEdit_18->text() == " ")
        || (ui->lineEdit_19->text() == "" || ui->lineEdit_19->text() == " ")
        || (ui->lineEdit_20->text() == "" || ui->lineEdit_20->text() == " "))
    {
        MessageBox  msg;
        msg.move((SCREEN_SIZE_WIDTH - msg.width()) / 2, (SCREEN_SIZE_HEIGHT - msg.height()) / 2);
        msg.SetMessage(tr("Error"), tr("9-digit MMSI Code must be 9 number !"), 0);
        msg.exec() ;
        return;
    }
    
    QString str2;
    str2 += ui->lineEdit_12->text();
    str2 += ui->lineEdit_13->text();
    str2 += ui->lineEdit_14->text();
    str2 += ui->lineEdit_15->text();
    str2 += ui->lineEdit_16->text();
    str2 += ui->lineEdit_17->text();
    str2 += ui->lineEdit_18->text();
    str2 += ui->lineEdit_19->text();
    str2 += ui->lineEdit_20->text();
    paraMap.insert(SYSTEM_SETTING_DIGITMMSICODELABEL, str2);
    QString str3;
    str3 += ui->lineEdit->text();
    QSqlRecord record = m_model->record(0);
    record.setValue(SYSTEM_SETTING_DIGITCALLCODE, str);
    record.setValue(SYSTEM_SETTING_MMSICODE, str2);
    record.setValue(SYSTEM_SETTING_ANSWERBACKCODE, str3);

    Transit::get()->EmitSignalReflashDeviceInfo(str,str2,str3);
    m_model->setRecord(0, record);
    m_model->submitAll();
    paraMap.insert(SYSTEM_SETTING_MODLE_NAME, SYSTEM_SETTING_MODLE_OK);
    emit setMMSI(str2);
    emit afterPageSignal(Constants::SYSTEM_IDENTIFICATION_SETTING_TITLE, Constants::SYSTEM_SETTING_VIEW, paraMap);
}
/****************************************************************************
**
** 函数名称：IdentificationSetting::cancelButtonClickedSlot
** 功能概述: 取消保存返回
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void IdentificationSetting::cancelButtonClickedSlot()
{
    Logging::get()->info("IdentificationSetting::cancelButtonClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(Constants::SYSTEM_IDENTIFICATION_SETTING_TITLE, Constants::SYSTEM_SETTING_VIEW, paraMap);
}
/****************************************************************************
**
** 函数名称：IdentificationSetting::homeClickedSlot
** 功能概述: 返回到主菜单
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void IdentificationSetting::homeClickedSlot()
{
    Logging::get()->info("IdentificationSetting::homeClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(Constants::SYSTEM_IDENTIFICATION_SETTING_TITLE, "homeWidget", paraMap);
}
/****************************************************************************
**
** 函数名称：IdentificationSetting::settingClickedSlot
** 功能概述: 进入系统设置页面
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void IdentificationSetting::settingClickedSlot()
{
    Logging::get()->info("IdentificationSetting::settingClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(Constants::SYSTEM_IDENTIFICATION_SETTING_TITLE, Constants::SYSTEM_IDENTIFICATION_SETTING_VIEW,
                         paraMap);
}
/****************************************************************************
**
** 函数名称：IdentificationSetting::testClickedSlot
** 功能概述: 进入系统测试页面
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void IdentificationSetting::testClickedSlot()
{
    Logging::get()->info("IdentificationSetting::testClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(Constants::SYSTEM_IDENTIFICATION_SETTING_TITLE, Constants::SYSTEM_TEST_VIEW, paraMap);
}
/****************************************************************************
**
** 函数名称：IdentificationSetting::aboutClickedSlot
** 功能概述: 进入系统about页面
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void IdentificationSetting::aboutClickedSlot()
{
    Logging::get()->info("IdentificationSetting::aboutClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(Constants::SYSTEM_IDENTIFICATION_SETTING_TITLE, Constants::SYSTEM_ABOUT_VIEW, paraMap);
}
/****************************************************************************
**
** 函数名称：IdentificationSetting::frontPageSlot
** 功能概述: 打开页面时更新页面数据
** 参数说明： thisID：起始页面， fowordID：目标页面， paraMap：传递参数
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void IdentificationSetting::frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap)
{
    if (fowordID != Constants::SYSTEM_IDENTIFICATION_SETTING_VIEW) {return;}
    
    Logging::get()->info("IdentificationSetting::frontPageSlot");
    m_model->select();
    QSqlRecord  sqlRecord = m_model->record(0);
    QString digitcallcode = sqlRecord.value(SYSTEM_SETTING_DIGITCALLCODE).toString();
    QString mmsicode = sqlRecord.value(SYSTEM_SETTING_MMSICODE).toString();
    QString answerbackcode = sqlRecord.value(SYSTEM_SETTING_ANSWERBACKCODE).toString();
    QString d(1, digitcallcode[0]);
    ui->lineEdit_4->setText(d);
    QString d2(1, digitcallcode[1]);
    ui->lineEdit_5->setText(d2);
    QString d3(1, digitcallcode[2]);
    ui->lineEdit_6->setText(d3);
    QString d4(1, digitcallcode[3]);
    ui->lineEdit_7->setText(d4);
    QString d5(1, digitcallcode[4]);
    ui->lineEdit_8->setText(d5);
    QString m(1, mmsicode[0]);
    ui->lineEdit_12->setText(m);
    QString m2(1, mmsicode[1]);
    ui->lineEdit_13->setText(m2);
    QString m3(1, mmsicode[2]);
    ui->lineEdit_14->setText(m3);
    QString m4(1, mmsicode[3]);
    ui->lineEdit_15->setText(m4);
    QString m5(1, mmsicode[4]);
    ui->lineEdit_16->setText(m5);
    QString m6(1, mmsicode[5]);
    ui->lineEdit_17->setText(m6);
    QString m7(1, mmsicode[6]);
    ui->lineEdit_18->setText(m7);
    QString m8(1, mmsicode[7]);
    ui->lineEdit_19->setText(m8);
    QString m9(1, mmsicode[8]);
    ui->lineEdit_20->setText(m9);
    ui->lineEdit->setText(answerbackcode);
}
/****************************************************************************
**
** 函数名称：IdentificationSetting::~IdentificationSetting
** 功能概述: 析构函数
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
IdentificationSetting::~IdentificationSetting()
{
    Logging::get()->info("IdentificationSetting::~IdentificationSetting");
    delete ui;
}

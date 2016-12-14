#include "systemtest.h"
#include "ui_systemtest.h"
#include "views/common/constants.h"
#include "views/contacts/contactsstyle.h"
#include "widgets/messagedialog.h"
#include <QEvent>
#include <QKeyEvent>
#include "widgets/button.h"
#include "transit.h"
#include <QDebug>
#include "logging.h"
#include "core/utils/sqlitehelper.h"
#include <QDateTime>
/****************************************************************************
**
** 函数名称：SystemTest::SystemTest
** 功能概述: 初始化
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
SystemTest::SystemTest(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::SystemTest)
{
    Logging::get()->info("SystemTest::SystemTest");
    ui->setupUi(this);
    ui->tiltewidget->setText(Constants::SYSTEM_TEST_TITLE);
    this->installEventFilter(this);
    QIcon selfTest;
    selfTest.addPixmap(QPixmap(":/images/System_Test_Check_SelNo"), QIcon::Normal);
    selfTest.addPixmap(QPixmap(":/images/System_Test_Check_SelYes"), QIcon::Selected);
    ui->listWidget->addItem(new QListWidgetItem(selfTest, tr("1.Self Test")));
    QIcon markTransmission;
    markTransmission.addPixmap(QPixmap(":/images/System_Test_Check_SelNo"), QIcon::Normal);
    markTransmission.addPixmap(QPixmap(":/images/System_Test_Check_SelYes"), QIcon::Selected);
    ui->listWidget->addItem(new QListWidgetItem(markTransmission, tr("2.Mark Transmission")));
    QIcon spaceTransmission;
    spaceTransmission.addPixmap(QPixmap(":/images/System_Test_Check_SelNo"), QIcon::Normal);
    spaceTransmission.addPixmap(QPixmap(":/images/System_Test_Check_SelYes"), QIcon::Selected);
    ui->listWidget->addItem(new QListWidgetItem(spaceTransmission, tr("3.Space Transmission")));
    QIcon dotTransmission;
    dotTransmission.addPixmap(QPixmap(":/images/System_Test_Check_SelNo"), QIcon::Normal);
    dotTransmission.addPixmap(QPixmap(":/images/System_Test_Check_SelYes"), QIcon::Selected);
    ui->listWidget->addItem(new QListWidgetItem(dotTransmission, tr("4.Dot Transmission")));
    QIcon printTest;
    printTest.addPixmap(QPixmap(":/images/System_Test_Check_SelNo"), QIcon::Normal);
    printTest.addPixmap(QPixmap(":/images/System_Test_Check_SelYes"), QIcon::Selected);
    ui->listWidget->addItem(new QListWidgetItem(printTest, tr("5.Print Test")));
    ui->listWidget->setCurrentRow(0);
    connect(ui->homeTBnt, SIGNAL(clicked()), this, SLOT(homeClickedSlot()));
    connect(ui->settingTBtn, SIGNAL(clicked()), this, SLOT(settingClickedSlot()));
    connect(ui->testTBtn, SIGNAL(clicked()), this, SLOT(testClickedSlot()));
    connect(ui->aboutTBtn, SIGNAL(clicked()), this, SLOT(aboutClickedSlot()));
    connect(ui->okBtn, SIGNAL(clicked()), this, SLOT(okButtonClickedSlot()));
    connect(ui->cancelBtn, SIGNAL(clicked()), this, SLOT(cancelButtonClickedSlot()));
}
/****************************************************************************
**
** 函数名称：SystemTest::frontPageSlot
** 功能概述: 打开页面时更新页面数据
** 参数说明： thisID：起始页面， fowordID：目标页面， paraMap：传递参数
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SystemTest::frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap)
{
    if (fowordID != Constants::SYSTEM_TEST_VIEW) {return;}
    
    ui->homeTBnt->setIcon(QIcon(":/images/home_normal"));
    ui->aboutTBtn->setIcon(QIcon(":/images/System_AboutBtn_SelNo"));
    ui->settingTBtn->setIcon(QIcon(":/images/System_SetBtn_SelNo"));
    ui->listWidget->setCurrentRow(0);
    ui->listWidget->setFocus();
}
/****************************************************************************
**
** 函数名称：SystemTest::eventFilter
** 功能概述: 事件监听函数，响应用户键盘操作
** 参数说明： watched：发送方， event：事件数据
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool SystemTest::eventFilter(QObject* watched, QEvent* event)
{
    Logging::get()->info("SystemTest::eventFilter");
    //画面控件光标切换
    QStringList nameList;
    nameList << "listWidget" << "okBtn" << "cancelBtn" << "homeTBnt" << "settingTBtn"  << "aboutTBtn";
    QKeyEvent* key_event = static_cast<QKeyEvent*>(event);
    int a =   key_event->key();
    
    switch (a)
    {
    case Qt::Key_Right:
    case Qt::Key_Down:
    case Qt::Key_Tab:
    {
        // 按下时键屏蔽  弹起时键屏蔽 默认键值51 响应一次
        if (QEvent::KeyPress == event->type())
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type())
        {
            return true;
        }
        
        int next = 0;
        bool inListWidget = false;
        // 按钮图片切换 focus 离开 按钮图片变暗
        for (int i = 0; i < nameList.length(); i++)
        {
            QWidget* widget = findChild<QWidget*>(nameList.at(i));
            
            if (widget && widget->hasFocus())
            {
                if (nameList.at(i) == "listWidget" && a == Qt::Key_Down)
                {
                    inListWidget = true;
                    break;
                }
                
                if (nameList.at(i) == "homeTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/home_normal"));
                }
                
                if (nameList.at(i) == "settingTBtn")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/System_SetBtn_SelNo"));
                }
                
                if (nameList.at(i) == "testTBtn")
                {
                    //    QToolButton* button = static_cast<QToolButton*>(widget);
                    //   button->setIcon(QIcon(":/images/System_TestBtn_SelNo"));
                }
                
                if (nameList.at(i) == "aboutTBtn")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/System_AboutBtn_SelNo"));
                }
                
                next = (i == nameList.length() - 1) ? 0 : i + 1;
                break;
            }
        }
        
        if (inListWidget)
            break;
            
        QWidget* widgetnext = findChild<QWidget*>(nameList.at(next));
        // 按钮图片切换 focus 获得 按钮图片亮
        if (widgetnext)
        {
            widgetnext->setFocus();
            
            if (nameList.at(next) == "homeTBnt")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetnext);
                button->setIcon(QIcon(":/images/home_hover"));
            }
            
            if (nameList.at(next) == "settingTBtn")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetnext);
                button->setIcon(QIcon(":/images/System_SetBtn_SelYes"));
            }
            
            if (nameList.at(next) == "testTBtn")
            {
                //    QToolButton* button = static_cast<QToolButton*>(widgetnext);
                //    button->setIcon(QIcon(":/images/System_TestBtn_SelYes"));
            }
            
            if (nameList.at(next) == "aboutTBtn")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetnext);
                button->setIcon(QIcon(":/images/System_AboutBtn_SelYes"));
            }
        }
        
        break;
    }
    
    case Qt::Key_Up:
    case Qt::Key_Backtab:
    case Qt::Key_Left:
    {
        // 按下时键屏蔽  弹起时键屏蔽 默认键值51 响应一次
        if (QEvent::KeyPress == event->type())
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type())
        {
            return true;
        }
        
        int prev = 0;
        bool inListWidget = false;
        
        for (int i = 0; i < nameList.length(); i++)
        {
            QWidget* widget = findChild<QWidget*>(nameList.at(i));
            // 按钮图片切换 focus 离开 按钮图片变暗
            if (widget && widget->hasFocus())
            {
                if (nameList.at(i) == "listWidget" && a == Qt::Key_Up)
                {
                    inListWidget = true;
                    break;
                }
                
                if (nameList.at(i) == "homeTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/home_normal"));
                }
                
                if (nameList.at(i) == "settingTBtn")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/System_SetBtn_SelNo"));
                }
                
                if (nameList.at(i) == "testTBtn")
                {
                    // QToolButton* button = static_cast<QToolButton*>(widget);
                    //  button->setIcon(QIcon(":/images/System_TestBtn_SelNo"));
                }
                
                if (nameList.at(i) == "aboutTBtn")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/System_AboutBtn_SelNo"));
                }
                
                prev = (i == 0) ? nameList.length() - 1 : i - 1;
                break;
            }
        }
        
        if (inListWidget)
            break;
            
        QWidget* widgetprev = findChild<QWidget*>(nameList.at(prev));
        widgetprev->setFocus();
        
        if (widgetprev)
        {
            // 按钮图片切换 focus 获得 按钮图片亮
            widgetprev->setFocus();
            
            if (nameList.at(prev) == "homeTBnt")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetprev);
                button->setIcon(QIcon(":/images/home_hover"));
            }
            
            if (nameList.at(prev) == "settingTBtn")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetprev);
                button->setIcon(QIcon(":/images/System_SetBtn_SelYes"));
            }
            
            if (nameList.at(prev) == "testTBtn")
            {
                //  QToolButton* button = static_cast<QToolButton*>(widgetprev);
                //   button->setIcon(QIcon(":/images/System_TestBtn_SelYes"));
            }
            
            if (nameList.at(prev) == "aboutTBtn")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetprev);
                button->setIcon(QIcon(":/images/System_AboutBtn_SelYes"));
            }
        }
        
        break;
    }
    
    case Qt::Key_Return:
    case Qt::Key_Enter:
    {
        // 按下时键屏蔽  弹起时键屏蔽 默认键值51 响应一次
        if (QEvent::KeyPress == event->type())
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type())
        {
            return true;
        }
        

        for (int i = 0; i < nameList.length(); i++)
        {
            QWidget* widget = findChild<QWidget*>(nameList.at(i));
            
            // 按钮响应Enter 事件
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
                    break;
                }
                else if (nameList.at(i) == "aboutTBtn")
                {
                    QWidget* widget = findChild<QWidget*>("aboutTBtn");
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                }
                else if (nameList.at(i) == "listWidget")
                {
                    QWidget* widget = findChild<QWidget*>("okBtn");
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                }
                
                break;
            }
        }
        
        break;
    }
    
    case Qt::Key_Escape:
    {
        // 按下时键屏蔽  弹起时键屏蔽 默认键值51 响应一次
        if (QEvent::KeyPress == event->type())
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type())
        {
            return true;
        }
        
        // 响应 ESC事件
        QWidget* widget = findChild<QWidget*>("homeTBnt");
        
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
** 函数名称：SystemTest::okButtonClickedSlot
** 功能概述: 开始测试
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SystemTest::okButtonClickedSlot()
{
    Logging::get()->info("SystemTest::okButtonClickedSlot");
    QListWidgetItem* item = ui->listWidget->currentItem();
    ui->okBtn->hide();
    ui->cancelBtn->hide();
    ui->line_2->hide();
    
    if (item)
    {
        QString text = item->text();
        MessageDialog  msg;
        connect(this, SIGNAL(selfTestSignal(QList<bool>)), &msg, SLOT(selfTestSlot(QList<bool>)));
        msg.move((SCREEN_SIZE_WIDTH - msg.width()) / 2, (SCREEN_SIZE_HEIGHT - msg.height()) / 2);
        
        if (text == "1.Self Test")
        {
            Transit::get()->EmitSignalCheck();
            msg.SetMessage(tr("Self Test"), tr("Terminal Unit Test \nReceivr Unit Test\nTransmission Unit Test"), 1);
            msg.exec() ;
        }
        else  if (text == "2.Mark Transmission")
        {
            Transit::get()->EmitSignalMarkTrans();
            msg.SetMessage(tr("Mark Transmission"), tr("15S"), 3);
            msg.exec() ;
        }
        else  if (text == "3.Space Transmission")
        {
            Transit::get()->EmitSignalSpaceTrans();
            msg.SetMessage(tr("Space Transmission"), tr("15S"), 3);
            msg.exec() ;
        }
        else  if (text == "4.Dot Transmission")
        {
            Transit::get()->EmitSignalDotTrans();
            msg.SetMessage(tr("Dot Transmission"), tr("15S"), 3);
            msg.exec() ;
        }
        else  if (text == "5.Print Test")
        {
            QDateTime now = QDateTime::currentDateTime();
            QDate now_date = now.date();
            QTime now_time = now.time();
            QString date(QString::number(now_date.year(), 10));
            date += "/";
            
            if (now_date.month() < 10)
                date += "0";
                
            date += QString::number(now_date.month(), 10);
            date += "/";
            
            if (now_date.day() < 10)
                date += "0";
                
            date += QString::number(now_date.day(), 10);
            date += "        ";
            
            if (now_time.hour() < 10)
                date += "0";
                
            date += QString::number(now_time.hour(), 10);
            date += ":";
            
            if (now_time.minute() < 10)
                date += "0";
                
            date += QString::number(now_time.minute(), 10);
            date += ":";
            
            if (now_time.second() < 10)
                date += "0";
                
            date += QString::number(now_time.second(), 10);
            SQLiteHelper::printStr(date);
        }
        
        ui->okBtn->show();
        ui->cancelBtn->show();
        ui->line_2->show();
    }
    
    return;
}
/****************************************************************************
**
** 函数名称：SystemTest::selfTest
** 功能概述: selfTest测试下发
** 参数说明：返回的测试结果
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SystemTest::selfTest(QList<bool> test)
{
    Logging::get()->info("SystemTest::selfTest");
    emit selfTestSignal(test);
}
/****************************************************************************
**
** 函数名称：SystemTest::cancelButtonClickedSlot
** 功能概述: 返回到上一层界面
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SystemTest::cancelButtonClickedSlot()
{
    Logging::get()->info("SystemTest::cancelButtonClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(Constants::SYSTEM_TEST_VIEW, "homeWidget", paraMap);
}
/****************************************************************************
**
** 函数名称：SystemTest::homeClickedSlot
** 功能概述: 返回到主菜单
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SystemTest::homeClickedSlot()
{
    Logging::get()->info("SystemTest::homeClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(Constants::SYSTEM_TEST_VIEW, "homeWidget", paraMap);
}
/****************************************************************************
**
** 函数名称：SystemTest::settingClickedSlot
** 功能概述: 返回到系统设置界面
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SystemTest::settingClickedSlot()
{
    Logging::get()->info("SystemTest::settingClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(Constants::SYSTEM_TEST_VIEW, Constants::SYSTEM_SETTING_VIEW, paraMap);
}
/****************************************************************************
**
** 函数名称：SystemTest::testClickedSlot
** 功能概述: 跳转到系统测试界面
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SystemTest::testClickedSlot()
{
    Logging::get()->info("SystemTest::testClickedSlot");
}
/****************************************************************************
**
** 函数名称：SystemTest::aboutClickedSlot
** 功能概述: 跳转到系统about界面
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SystemTest::aboutClickedSlot()
{
    Logging::get()->info("SystemTest::aboutClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(Constants::SYSTEM_TEST_VIEW, Constants::SYSTEM_ABOUT_VIEW, paraMap);
}
/****************************************************************************
**
** 函数名称：SystemTest::~SystemTest
** 功能概述: 析构函数
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
SystemTest::~SystemTest()
{
    Logging::get()->info("SystemTest::~SystemTest");
    delete ui;
}

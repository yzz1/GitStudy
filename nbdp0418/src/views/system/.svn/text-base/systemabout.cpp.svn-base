#include "systemabout.h"
#include "ui_systemabout.h"
#include "views/common/constants.h"
#include "views/contacts/contactsstyle.h"
#include <QEvent>
#include <QKeyEvent>
#include "widgets/button.h"
#include "logging.h"
/****************************************************************************
**
** 函数名称：SystemAbout::SystemAbout
** 功能概述: 初始化
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
SystemAbout::SystemAbout(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::SystemAbout)
{
    Logging::get()->info("SystemAbout::SystemAbout");
    ui->setupUi(this);
    ui->tiltewidget->setText(Constants::SYSTEM_ABOUT_TITLE);
    QStringList string;
    string << tr("Version Number   1.0") << tr("Support Technique 0574-55712385") << tr("ALL property     CETC");
    ui->label->setText(string.at(0));
    ui->label_2->setText(string.at(1));
    ui->label_3->setText(string.at(2));
    this->installEventFilter(this);
    connect(ui->homeTBnt, SIGNAL(clicked()), this, SLOT(homeClickedSlot()));
    connect(ui->settingTBtn, SIGNAL(clicked()), this, SLOT(settingClickedSlot()));
    connect(ui->testTBtn, SIGNAL(clicked()), this, SLOT(testClickedSlot()));
    connect(ui->aboutTBtn, SIGNAL(clicked()), this, SLOT(aboutClickedSlot()));
}
/****************************************************************************
**
** 函数名称：SystemAbout::eventFilter
** 功能概述: 事件监听函数，响应用户键盘操作
** 参数说明 watched：发送方， event：事件数据
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool SystemAbout::eventFilter(QObject* watched, QEvent* event)
{
    Logging::get()->info("SystemAbout::eventFilter");
    QStringList nameList;
    nameList << "homeTBnt" << "settingTBtn" << "testTBtn" ;
    QKeyEvent* key_event = static_cast<QKeyEvent*>(event);
    int a =   key_event->key();
    
    switch (a)
    {
    case Qt::Key_Right:
    case Qt::Key_Down:
    case Qt::Key_Tab:
    {
        if (QEvent::KeyPress == event->type())// 按下时键屏蔽
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type())// 弹起时键屏蔽
        {
            return true;
        }
        
        int next = 0;
        // 默认键值51 响应一次
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
                
                if (nameList.at(i) == "settingTBtn")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/System_SetBtn_SelNo"));
                }
                
                if (nameList.at(i) == "testTBtn")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/System_TestBtn_SelNo"));
                }
                
                if (nameList.at(i) == "aboutTBtn")
                {
                    //  QToolButton* button = static_cast<QToolButton*>(widget);
                    //   button->setIcon(QIcon(":/images/System_AboutBtn_SelNo"));
                }
                
                next = (i == nameList.length() - 1) ? 0 : i + 1;
                break;
            }
        }
        
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
                QToolButton* button = static_cast<QToolButton*>(widgetnext);
                button->setIcon(QIcon(":/images/System_TestBtn_SelYes"));
            }
            
            if (nameList.at(next) == "aboutTBtn")
            {
                //QToolButton* button = static_cast<QToolButton*>(widgetnext);
                //button->setIcon(QIcon(":/images/System_AboutBtn_SelYes"));
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
        else if (QEvent::KeyRelease == event->type())// 弹起时键屏蔽
        {
            return true;
        }
        
        int prev = 0;
        
        // 默认键值51 响应一次
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
                
                if (nameList.at(i) == "settingTBtn")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/System_SetBtn_SelNo"));
                }
                
                if (nameList.at(i) == "testTBtn")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/System_TestBtn_SelNo"));
                }
                
                if (nameList.at(i) == "aboutTBtn")
                {
                    //    QToolButton* button = static_cast<QToolButton*>(widget);
                    //   button->setIcon(QIcon(":/images/System_AboutBtn_SelNo"));
                }
                
                prev = (i == 0) ? nameList.length() - 1 : i - 1;
                break;
            }
        }
        
        QWidget* widgetprev = findChild<QWidget*>(nameList.at(prev));
        widgetprev->setFocus();
        // 按钮图片切换 focus 获得 按钮图片亮
        if (widgetprev)
        {
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
                QToolButton* button = static_cast<QToolButton*>(widgetprev);
                button->setIcon(QIcon(":/images/System_TestBtn_SelYes"));
            }
            
            if (nameList.at(prev) == "aboutTBtn")
            {
                //   QToolButton* button = static_cast<QToolButton*>(widgetprev);
                //    button->setIcon(QIcon(":/images/System_AboutBtn_SelYes"));
            }
        }
        
        break;
    }
    
    case Qt::Key_Return:
    case Qt::Key_Enter:// 按钮响应Enter 事件
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
                    break;
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
** 函数名称：SystemAbout::homeClickedSlot
** 功能概述: 返回到主菜单
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SystemAbout::homeClickedSlot()
{
    Logging::get()->info("SystemAbout::homeClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(Constants::SYSTEM_ABOUT_VIEW, "homeWidget", paraMap);
}
/****************************************************************************
**
** 函数名称：SystemAbout::settingClickedSlot
** 功能概述: 跳转到系统设置界面
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SystemAbout::settingClickedSlot()
{
    Logging::get()->info("SystemAbout::settingClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(Constants::SYSTEM_ABOUT_VIEW, Constants::SYSTEM_SETTING_VIEW, paraMap);
}
/****************************************************************************
**
** 函数名称：SystemAbout::testClickedSlot
** 功能概述: 跳转到系统测试界面
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SystemAbout::testClickedSlot()
{
    Logging::get()->info("SystemAbout::testClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(Constants::SYSTEM_ABOUT_VIEW, Constants::SYSTEM_TEST_VIEW, paraMap);
}
/****************************************************************************
**
** 函数名称：SystemAbout::aboutClickedSlot
** 功能概述: 跳转到系统about界面
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SystemAbout::aboutClickedSlot()
{
    Logging::get()->info("SystemAbout::aboutClickedSlot");
}
/****************************************************************************
**
** 函数名称：SystemAbout::frontPageSlot
** 功能概述: 打开页面时更新页面数据
** 参数说明： thisID：起始页面， fowordID：目标页面， paraMap：传递参数
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SystemAbout::frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap)
{
    if (fowordID != Constants::SYSTEM_ABOUT_VIEW) {return;}
    
    ui->homeTBnt->setIcon(QIcon(":/images/home_hover"));
    ui->settingTBtn->setIcon(QIcon(":/images/System_SetBtn_SelNo"));
    ui->testTBtn->setIcon(QIcon(":/images/System_TestBtn_SelNo"));
    ui->homeTBnt->setFocus();
}
/****************************************************************************
**
** 函数名称：SystemAbout::～SystemAbout
** 功能概述: 析构函数
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
SystemAbout::~SystemAbout()
{
    Logging::get()->info("SystemAbout::~SystemAbout");
    delete ui;
}

#include "homeview.h"
#include <QLabel>
#include <QEvent>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QUuid>
#include "widgets/button.h"
#include "views/common/constants.h"
#include "widgets/button.h"
#include <QSqlQuery>
#include "core/database/database.h"
#include "logging.h"

bool click(Database*);

bool on_button_click(Database*);
/****************************************************************************
**
** 函数名称：HomeWidget::HomeWidget
** 功能概述: 初始化
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
HomeWidget::HomeWidget(QWidget* parent): QWidget(parent)
{
    Logging::get()->info("HomeWidget::HomeWidget");
    m_enterflag = false;
    m_layout = new QGridLayout(this);
    this->installEventFilter(this);
    QStringList iconNameList;
    iconNameList << Constants::CALLBTN_ICON_NAME << Constants::CONTACTSBTN_ICON_NAME << Constants::MESSAGESBTN_ICON_NAME
                 << Constants::SCANBTN_ICON_NAME << Constants::MANAGEBTN_ICON_NAME << Constants::SYSTEMBTN_ICON_NAME;
    qDebug() << iconNameList;
    QStringList textList;
    textList << Constants::CALLBTN_DISPLAY_NAME << Constants::CONTACTSBTN_DISPLAY_NAME <<
             Constants::MESSAGESBTN_DISPLAY_NAME
             << Constants::SCANBTN_DISPLAY_NAME << Constants::MANAGEBTN_DISPLAY_NAME << Constants::SYSTEMBTN_DISPLAY_NAME;
    QStringList nameList;
    nameList << Constants::CALLBTN_NAME << Constants::CONTACTSBTN_NAME << Constants::MESSAGESBTN_NAME
             << Constants::SCANBTN_NAME << Constants::MANAGEBTN_NAME << Constants::SYSTEMBTN_NAME;
    qDebug() << nameList;
    QSignalMapper* signalMapper = new QSignalMapper(this);
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Button* button = new Button(iconNameList.at(3 * i + j), textList.at(3 * i + j));
            button->setObjectName(nameList.at(3 * i + j));
            button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
            button->onClick  = on_button_click;
            signalMapper->setMapping(button, 3 * i + j);
            connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
            m_layout->addWidget(button, i, j);
        }
    }
    
    connect(signalMapper, SIGNAL(mapped(int)), this, SIGNAL(buttonClicked(int)));
    setFixedHeight(600);
    const QObjectList list = children();
    foreach(QObject * obj, list)
    {
        QString clsName = obj->metaObject()->className();
        qDebug() << clsName;
    }
}
/****************************************************************************
**
** 函数名称：on_button_click
** 功能概述: 按钮响应接口
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool on_button_click(Database* db)
{
    Logging::get()->info("HomeWidget  on_button_click");
    //emit buttonClicked(index);
}
/****************************************************************************
**
** 函数名称：click
** 功能概述: 点击事件
** 参数说明  数据库文件
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool click(Database* db)
{
    Logging::get()->info("HomeWidget click");
    QUuid id = QUuid::createUuid();
    QString strId = id.toString();
    bool result1 = true;
    bool result2 = true;
    bool result3 = true;
    QString sql1 =
        "insert into station(uuid, name, callsign, country, callcode) values(?, 'Shanghai1', 'SUH', 'China','123456789')";
    QVariantMap map1;
    map1.insert(":id", strId);
    result1 = db->executeSql(sql1, map1);
    id = QUuid::createUuid();
    strId = id.toString();
    QVariantMap map2;
    map2.insert(":id", strId);
    result2 = db->executeSql(sql1, map2);
    id = QUuid::createUuid();
    strId = id.toString();
    QVariantMap map3;
    map3.insert(":id", strId);
    result3 = db->executeSql(sql1, map3);
    return result1 && result2 && result3;
}

/****************************************************************************
**
** 函数名称：HomeWidget::eventFilter
** 功能概述: 事件监听函数，响应用户键盘操作
** 参数说明 watched：发送方， event：事件数据
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool HomeWidget::eventFilter(QObject* watched, QEvent* event)
{
    Logging::get()->info("HomeWidget::eventFilter");
    QStringList nameList;
    nameList << "callBtn" << "contactsBtn" << "messagesBtn" << "scanBtn"
             << "manageBtn" << "systemBtn";
    QKeyEvent* key_event = static_cast<QKeyEvent*>(event);
    int a = key_event->key();
    
    switch (a)
    {
    case Qt::Key_Enter:
    case Qt::Key_Return:
    {
        if (QEvent::KeyPress == event->type()) // 按下时键屏蔽
        {
            m_enterflag = true;
            return true;
        }
        else if (QEvent::KeyRelease == event->type() && m_enterflag) // 键弹起时
        {
            m_enterflag = false;
            
            // 模拟焦点所在按钮的点击事件
            for (int i = 0; i < nameList.length(); i++)
            {
                QWidget* widget = findChild<QWidget*>(nameList.at(i));
                
                if (widget && widget->hasFocus())
                {
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                    break;
                }
            }
        }
        
        break;
    }
    
    case Qt::Key_Down:
    case Qt::Key_Tab:
    case Qt::Key_Right:
    {
        if (QEvent::KeyRelease == event->type()) // 按下时键屏蔽
            break;
            
        if (QEvent::KeyPress == event->type()) // 弹起时键屏蔽
            break;
            
        // 将当前控件的焦点清除掉
        int next = 0;
        for (int i = 0; i < nameList.length(); i++)
        {
            QWidget* widget = findChild<QWidget*>(nameList.at(i));
            
            if (widget && widget->hasFocus())
            {
                clearFocus();
                next = (i == nameList.length() - 1) ? 0 : i + 1;
                break;
            }
        }
        
        // 如果是向下键，则计算得出下一行同一位置的控件的下标
        if (a == Qt::Key_Down)
            next = (next + 2) % nameList.length();
        
        // 将焦点转移到下一个控件
        QWidget* widgetnext = findChild<QWidget*>(nameList.at(next));
        if (widgetnext)
        {
            widgetnext->setFocus();
        }
        
        break;
    }
    
    case Qt::Key_Up:
    case Qt::Key_Backtab:
    case Qt::Key_Left:
    {
        if (QEvent::KeyRelease == event->type()) // 弹起时键屏蔽
            break;
            
        int prev = 0;
        // 将当前控件的焦点清除掉
        for (int i = 0; i < nameList.length(); i++)
        {
            QWidget* widget = findChild<QWidget*>(nameList.at(i));
            
            if (widget && widget->hasFocus())
            {
                clearFocus();
                prev = (i == 0) ? nameList.length() - 1 : i - 1;
                break;
            }
        }
        
        // 如果是向上键，则计算得出上一行同一位置的控件的下标
        if (a == Qt::Key_Up)
            prev = (nameList.length() + (prev - 2)) % nameList.length();
        
        // 将焦点转移到上一个控件
        QWidget* widgetprev = findChild<QWidget*>(nameList.at(prev));
        if (widgetprev)
        {
            widgetprev->setFocus();
        }
        
        break;
    }
    
    case Qt::Key_Home:
        break;
    }
    
    if (a == Qt::Key_Escape)
        return true;
        
    return QWidget::eventFilter(watched, event);
}
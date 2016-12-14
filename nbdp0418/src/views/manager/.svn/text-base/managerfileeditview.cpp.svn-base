#include "managerfileeditview.h"
#include "ui_managerfileeditview.h"
#include "views/common/constants.h"
#include "core/database/database.h"
#include "QUuid"
#include "QDateTime"
#include "QString"
#include "QInputDialog"
#include "QLabel"
#include "widgets/messagebox.h"
#include "widgets/inputdialog.h"
#include <QEvent>
#include <QKeyEvent>
#include "widgets/button.h"
#include "logging.h"
#include "core/utils/intputcheck.h"
/****************************************************************************
**
** 函数名称：ManagerFileEditView::ManagerFileEditView
** 功能概述: 初始化
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ManagerFileEditView::ManagerFileEditView(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::ManagerFileEditView)
{
    Logging::get()->info("ManagerFileEditView::ManagerFileEditView");
    ui->setupUi(this);
    connect(ui->homeTBnt, SIGNAL(clicked()), this, SLOT(homeClickedSlot()));
    connect(ui->cancelBnt, SIGNAL(clicked()), this, SLOT(cancelClickedSlot()));
    connect(ui->saveBnt, SIGNAL(clicked()), this, SLOT(saveData()));
    connect(ui->copyBnt, SIGNAL(clicked()), this, SLOT(copyClicedSlot()));
    connect(ui->pasteBnt, SIGNAL(clicked()), this, SLOT(pasteClicedSlot()));
    connect(ui->cutBnt, SIGNAL(clicked()), this, SLOT(cutClicedSlot()));
    connect(ui->undoBnt, SIGNAL(clicked()), this, SLOT(undoClicedSlot()));
    connect(ui->macroTBnt, SIGNAL(clicked()), this, SLOT(macroClickedSlot()));
    connect(ui->phrasebookTBnt, SIGNAL(clicked()), this, SLOT(phrasebookClickedSlot()));
    connect(ui->fileTBnt_2, SIGNAL(clicked()), this, SLOT(fileClickedSlot()));
    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(inputCheckSlot()));
    this->installEventFilter(this);
    ui->textEdit->setFocus();
}
/****************************************************************************
**
** 函数名称：ManagerFileEditView::inputCheckSlot
** 功能概述: 输入校验
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerFileEditView::inputCheckSlot()
{
    IntputCheck check;
    QString str = ui->textEdit->toPlainText();
    
    if (!check.checkStr(str))//校验失败
    {
        QTextCursor cursor = ui->textEdit->textCursor();
        int len = ui->textEdit->toPlainText().length();
        len = len - cursor.position();
        ui->textEdit->setText(m_editStr);
        len = m_editStr.length() - len;
        cursor.setPosition(len);
        ui->textEdit->setTextCursor(cursor);
    }
    else
        m_editStr = ui->textEdit->toPlainText();
}
/****************************************************************************
**
** 函数名称：ManagerFileEditView::macroClickedSlot
** 功能概述: 进入macro界面
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerFileEditView::macroClickedSlot()
{
    Logging::get()->info("ManagerFileEditView::macroClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(Constants::MANAGER_FILE_EDIT_VIEW, Constants::MANAGER_MACRO, paraMap);
}
/****************************************************************************
**
** 函数名称：ManagerFileEditView::fileClickedSlot
** 功能概述: 进入文件列表界面
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerFileEditView::fileClickedSlot()
{
    Logging::get()->info("ManagerFileEditView::fileClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(Constants::MANAGER_FILE_EDIT_VIEW, Constants::MANAGER_FILE, paraMap);
}
/****************************************************************************
**
** 函数名称：ManagerFileEditView::phrasebookClickedSlot
** 功能概述: 进入phrasebook界面
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerFileEditView::phrasebookClickedSlot()
{
    Logging::get()->info("ManagerFileEditView::phrasebookClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(Constants::MANAGER_FILE_EDIT_VIEW, Constants::MANAGER_PHRASEBOOK, paraMap);
}
/****************************************************************************
**
** 函数名称：ManagerFileEditView::eventFilter
** 功能概述: 事件监听函数，响应用户键盘操作
** 参数说明 watched：发送方， event：事件数据
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool ManagerFileEditView::eventFilter(QObject* watched, QEvent* event)
{
    Logging::get()->info("ManagerFileEditView::eventFilter");
    QStringList nameList;
    nameList << "textEdit" << "undoBnt" << "copyBnt" << "cutBnt" << "pasteBnt" <<
             "saveBnt" << "cancelBnt" << "homeTBnt" << "macroTBnt" << "phrasebookTBnt";
    QKeyEvent* key_event = static_cast<QKeyEvent*>(event);
    int a =   key_event->key();
    // 按下时键屏蔽
    // 弹起时键屏蔽
     // 默认键值51 响应一次
    switch (a)
    {
    case Qt::Key_Right:
    case Qt::Key_Down:
    case Qt::Key_Tab:
    {
        int next = 0;
        
        if (QEvent::KeyPress == event->type())
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type())
        {
            return true;
        }

        QWidget* widget;
        int i = 0;
        // 按钮图片切换 focus 离开 按钮图片变暗
        for (i = 0; i < nameList.length(); i++)
        {
            widget = findChild<QWidget*>(nameList.at(i));
            
            if (widget && widget->hasFocus())
            {
                if (nameList.at(i) == "textEdit")
                {
                    break;
                }
                
                if (nameList.at(i) == "homeTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/home_normal"));
                }
                if (nameList.at(i) == "macroTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/manager_Macro_Btn_SelNo"));
                }
                
                if (nameList.at(i) == "phrasebookTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/manager_PhraseBook_Btn_SelNo"));
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
            
            if (nameList.at(next) == "fileTBnt_2")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetnext);
                button->setIcon(QIcon(":/images/manager_File_Btn_SelYes"));
            }
            
            if (nameList.at(next) == "macroTBnt")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetnext);
                button->setIcon(QIcon(":/images/manager_Macro_Btn_SelYes"));
            }
            
            if (nameList.at(next) == "phrasebookTBnt")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetnext);
                button->setIcon(QIcon(":/images/manager_PhraseBook_Btn_SelYes"));
            }
        }
        
        break;
    }
    
    case Qt::Key_Up:
    case Qt::Key_Backtab:
    case Qt::Key_Left:
    {
        if (QEvent::KeyPress == event->type())
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type())
        {
            return true;
        }
        
        int prev = 0;
        
        for (int i = 0; i < nameList.length(); i++)// 按钮图片切换 focus 离开 按钮图片变暗
        {
            QWidget* widget = findChild<QWidget*>(nameList.at(i));
            
            if (widget && widget->hasFocus())
            {
                if (nameList.at(i) == "textEdit")
                {
                    break;
                }
                
                if (nameList.at(i) == "homeTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/home_normal"));
                }
                
                if (nameList.at(i) == "fileTBnt_2")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/manager_File_Btn_SelNo"));
                }
                
                if (nameList.at(i) == "macroTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/manager_Macro_Btn_SelNo"));
                }
                
                if (nameList.at(i) == "phrasebookTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/manager_PhraseBook_Btn_SelNo"));
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
            
            if (nameList.at(prev) == "fileTBnt_2")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetprev);
                button->setIcon(QIcon(":/images/manager_File_Btn_SelYes"));
            }
            
            if (nameList.at(prev) == "macroTBnt")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetprev);
                button->setIcon(QIcon(":/images/manager_Macro_Btn_SelYes"));
            }
            
            if (nameList.at(prev) == "phrasebookTBnt")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetprev);
                button->setIcon(QIcon(":/images/manager_PhraseBook_Btn_SelYes"));
            }
        }
        
        break;
    }
    
    case Qt::Key_Return:
    case Qt::Key_Enter:
    {
        if (QEvent::KeyPress == event->type())
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type())
        {
            return true;
        }
        
        for (int i = 0; i < nameList.length(); i++)//触发按键事件
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
                else if (nameList.at(i) == "macroTBnt")
                {
                    QWidget* widget = findChild<QWidget*>("macroTBnt");
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                }
                else if (nameList.at(i) == "phrasebookTBnt")
                {
                    QWidget* widget = findChild<QWidget*>("phrasebookTBnt");
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
        QWidget* widgetTextEdit = findChild<QWidget*>("textEdit");
        
        if (QEvent::KeyPress == event->type())
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type())
        {
            return true;
        }
        else if (widgetTextEdit && widgetTextEdit->hasFocus())
        {
            QWidget* widgetnext = findChild<QWidget*>("undoBnt");
            
            if (widgetnext)
            {
                widgetnext->setFocus();
            }
            
            return true;
        }
        
        QWidget* widget = findChild<QWidget*>("cancelBnt");
        
        if (widget)
        {
            Button* button = static_cast<Button*>(widget);
            button->click();
        }
        
        return true;
    }
    }
    
    if (a == Qt::Key_Escape)
        return true;
        
    return QWidget::eventFilter(watched, event);
}

/****************************************************************************
**
** 函数名称：ManagerFileEditView::~ManagerFileEditView
** 功能概述: 析构函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ManagerFileEditView::~ManagerFileEditView()
{
    Logging::get()->info("ManagerFileEditView::~ManagerFileEditView");
    delete ui;
}
/****************************************************************************
**
** 函数名称：ManagerFileEditView::homeClickedSlot
** 功能概述: 返回到主菜单
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerFileEditView:: homeClickedSlot()
{
    Logging::get()->info("ManagerFileEditView::homeClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(Constants::MANAGER_FILE_EDIT_VIEW, HOME_VIEW_NAME, paraMap);
}

/****************************************************************************
**
** 函数名称：ManagerFileEditView::cancelClickedSlot
** 功能概述: 取消编辑并返回
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerFileEditView::cancelClickedSlot()
{
    Logging::get()->info("ManagerFileEditView::cancelClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(Constants::MANAGER_FILE_EDIT_VIEW, Constants::MANAGER_FILE, paraMap);
}

/****************************************************************************
**
** 函数名称：ManagerFileEditView::saveData
** 功能概述: 确认保存
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerFileEditView:: saveData()
{
    Logging::get()->info("ManagerFileEditView::saveData");
    
    if (m_strModle == Constants::MANAGER_FILE_NEW)
    {
        int ret = 0;
        InputDialog  inputDialog;
        inputDialog.move((SCREEN_SIZE_WIDTH - inputDialog.width()) / 2, (SCREEN_SIZE_HEIGHT - inputDialog.height()) / 2);
        inputDialog.SetTitle(tr("Input file name"));
        ret =  inputDialog.exec() ;
        
        if (ret)//确认输入
        {
            QString fileName = inputDialog.getTextContent();
            QMap <QString, QString>paraMap;
            paraMap.insert(COMMON_MODLE_NAME, COMMON_MODLE_OK);
            Database* database = new Database();
            database->openConnection();
            bool hasTransaction = database->transaction();
            QUuid idFile = QUuid::createUuid();
            QString strFileId = idFile.toString();
            paraMap.insert(Constants::MANAGER_FILE_UUID, strFileId);
            QDateTime dateTime = QDateTime::currentDateTime();
            int y = dateTime.date().year();
            int m = dateTime.date().month();
            QString mStr = "0";
            
            if (m < 10)
                mStr += QString::number(m);
            else
                mStr = QString::number(m);
                
            int d = dateTime.date().day();
            QString dStr = "0";
            
            if (d < 10)
                dStr += QString::number(d);
            else
                dStr = QString::number(d);
                
            QString strTime = dateTime.time().toString();
            QString strDateTime = (QString::number(y) + "-" + mStr + "-" + dStr + " " + strTime);
            QString sqlInsert =
                "insert into File(UUID, Name,Content,CreateDateTime,UpdateDateTime) values(:UUID,:Name,:Content,:CreateDateTime,:UpdateDateTime)";
            QVariantMap mapInsert;
            bool bInsertResult = false;
            mapInsert.insert(Constants::MANAGER_FILE_UUID, strFileId);
            mapInsert.insert(Constants::FILe_LIST_COL_NAME, fileName);
            mapInsert.insert(Constants::FILe_LIST_COL_CONTENT, ui->textEdit->toPlainText());
            mapInsert.insert(Constants::FILe_LIST__COL_CDATETIME, strDateTime);
            mapInsert.insert(Constants::FILe_LIST__COL_UDATETIME, strDateTime);
            bInsertResult = database->executeSql(sqlInsert, mapInsert);
            
            if (hasTransaction && bInsertResult)
            {
                database->commit();
            }
            else
            {
                database->rollback();
            }
            
            emit afterPageSignal(Constants::MANAGER_FILE_EDIT_VIEW, Constants::MANAGER_FILE, paraMap);
        }
    }
    else//edit模式
    {
        QMap <QString, QString>paraMap;
        paraMap.insert(COMMON_MODLE_NAME, COMMON_MODLE_OK);
        Database* database = new Database();
        database->openConnection();
        bool hasTransaction = database->transaction();
        QString  strUUID = m_paraMap[Constants::MANAGER_FILE_UUID];
        paraMap.insert(Constants::MANAGER_FILE_UUID, strUUID);
        QDateTime dateTime = QDateTime::currentDateTime();
        int y = dateTime.date().year();
        int m = dateTime.date().month();
        QString mStr = "0";
        
        if (m < 10)
            mStr += QString::number(m);
        else
            mStr = QString::number(m);
            
        int d = dateTime.date().day();
        QString dStr = "0";
        
        if (d < 10)
            dStr += QString::number(d);
        else
            dStr = QString::number(d);
            
        QString strTime = dateTime.time().toString();
        QString strDateTime = (QString::number(y) + "-" + mStr + "-" + dStr + " " + strTime);
        QString sql1Update =
            "update File set Content=:Content,UpdateDateTime=:UpdateDateTime where UUID=:UUID";
        QVariantMap mapUpdate;
        bool resultUpdate = false;
        mapUpdate.insert(Constants::FILe_LIST_COL_CONTENT, ui->textEdit->toPlainText());
        mapUpdate.insert(Constants::FILe_LIST__COL_UDATETIME, strDateTime);
        mapUpdate.insert(Constants::MANAGER_FILE_UUID, strUUID);
        resultUpdate = database->executeSql(sql1Update, mapUpdate);
        
        if (hasTransaction && resultUpdate)
        {
            database->commit();
        }
        else
        {
            database->rollback();
        }
        
        emit afterPageSignal(Constants::MANAGER_FILE_EDIT_VIEW, Constants::MANAGER_FILE, paraMap);
    }
}
/****************************************************************************
**
** 函数名称：ManagerFileEditView::frontPageSlot
** 功能概述: 打开页面时更新页面数据
** 参数说明： thisID：起始页面， fowordID：目标页面， paraMap：传递参数
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void  ManagerFileEditView::frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap)
{
    if (fowordID != Constants::MANAGER_FILE_EDIT_VIEW) {return;}
    
    Logging::get()->info("ManagerFileEditView::frontPageSlot");
    QFont  tempFont(ui->textEdit->font());
    tempFont.setPixelSize(Constants::MANAGER_FILE_EDIT_SIZE);
    ui->textEdit->setFont(tempFont);
    m_paraMap = paraMap;
    
    if (m_paraMap.isEmpty()) {return;}
    
    m_strModle  =  m_paraMap[Constants::MANAGER_MODLE_NAME];
    
    if (m_strModle == Constants::MANAGER_FILE_EDIT)
    {
        QString strUUID = m_paraMap[Constants::MANAGER_FILE_UUID];
        QString strName = m_paraMap[Constants::FILe_LIST_COL_NAME];
        QString strContent = m_paraMap[Constants::FILe_LIST_COL_CONTENT];
        ui->contactsTiltewidget->setText(strName);
        ui->textEdit->setText(strContent);
    }
    else
    {
        ui->contactsTiltewidget->setText(Constants::MANAGER_FILE_EDIT_VIEW_TITLE);
        ui->textEdit->clear();
    }
    
    m_editStr = ui->textEdit->toPlainText();
    ui->textEdit->setFocus();
}
/****************************************************************************
**
** 函数名称：ManagerFileEditView::copyClicedSlot
** 功能概述: copy功能
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerFileEditView:: copyClicedSlot()
{
    Logging::get()->info("ManagerFileEditView::copyClicedSlot");
    ui->textEdit->copy();
    ui->textEdit->setFocus();
}
/****************************************************************************
**
** 函数名称：ManagerFileEditView::pasteClicedSlot
** 功能概述: 粘贴功能
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerFileEditView:: pasteClicedSlot()
{
    Logging::get()->info("ManagerFileEditView::pasteClicedSlot");
    ui->textEdit->paste();
    ui->textEdit->setFocus();
}
/****************************************************************************
**
** 函数名称：ManagerFileEditView::cutClicedSlot
** 功能概述: 剪切功能
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerFileEditView:: cutClicedSlot()
{
    Logging::get()->info("ManagerFileEditView::cutClicedSlot");
    ui->textEdit->cut();
    ui->textEdit->setFocus();
}
/****************************************************************************
**
** 函数名称：ManagerFileEditView::undoClicedSlot
** 功能概述: 回撤功能
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ManagerFileEditView:: undoClicedSlot()
{
    Logging::get()->info("ManagerFileEditView::undoClicedSlot");
    ui->textEdit->undo();
    ui->textEdit->setFocus();
}

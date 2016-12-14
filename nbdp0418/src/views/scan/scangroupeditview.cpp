#include "scangroupeditview.h"
#include "ui_scangroupeditview.h"
#include "views/common/constants.h"
#include <QSqlQuery>
#include <QSqlRecord>
//#include "models/contactsitemdelegate.h"
//#include <QVariant>
//#include "core/database/connectionpool.h"
#include "core/database/database.h"
#include "core/utils/sqlitehelper.h"
#include "widgets/messagebox.h"
#include <QEvent>
#include <QKeyEvent>
#include "widgets/button.h"
#include <QDateTime>
#include <QUuid>
#include "logging.h"
#include <QDebug>
/****************************************************************************
**
** 函数名称：FrequencyScanData::clear
** 功能概述: 清理数据
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void FrequencyScanData::clear()
{
    Logging::get()->info("FrequencyScanData::clear");
    strTx.clear();
    strRx.clear();
    scanFlag.clear();
}
/****************************************************************************
**
** 函数名称：ScanGroupEditView::ScanGroupEditView
** 功能概述: 初始化
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ScanGroupEditView::ScanGroupEditView(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::ScanGroupEditView)
{
    Logging::get()->info("ScanGroupEditView::ScanGroupEditView");
    ui->setupUi(this);
    ui->titleWidget->setText(Constants::SCAN_GROUP__NEW_TITLE);
    this->installEventFilter(this);
    FrequencyScanData temp;
    
    for (int n = 0; n < SCAN_GROUP_MAX_DISPLAY_DATA; n++)
    {
        m_list.append(temp);
    }
    
    m_editmode = false;
    QRegExp rx("[3-4][.][0-9]||[5]");
    ui->dwellTimeEdit->setValidator(new QRegExpValidator(rx, this));
    QStringList modeQStringList;
    modeQStringList << "ARQ" << "FEC" << "Auto";
    ui->comboBox->addItems(modeQStringList);
    QStringList scanPass;
    scanPass << "Scan" << "Pass";
    ui->comboBox_2->addItems(scanPass);
    ui->comboBox_3->addItems(scanPass);
    ui->comboBox_4->addItems(scanPass);
    ui->comboBox_5->addItems(scanPass);
    ui->comboBox_6->addItems(scanPass);
    ui->comboBox_7->addItems(scanPass);
    QFont font("Ubuntu", 18, QFont::Bold);
    ui->group_name->addItem(tr("Group Name"));
    ui->dwell_time->addItem(tr("Dwell Time"));
    ui->scan_mode->addItem(tr("Scan Mode"));
    ui->group_name->item(0)->setFont(font);
    ui->group_name->setCurrentRow(0);
    ui->dwell_time->item(0)->setFont(font);
    ui->scan_mode->item(0)->setFont(font);
    connect(ui->okBtn, SIGNAL(clicked()), this, SLOT(okButtonClickedSlot()));
    connect(ui->cancelBtn, SIGNAL(clicked()), this, SLOT(cancelButtonClickedSlot()));
    connect(ui->homeBtn, SIGNAL(clicked()), this, SLOT(homeClickedSlot()));
    connect(ui->arrowUpButton, SIGNAL(clicked()), this, SLOT(arrowUpButtonClicked()));
    connect(ui->arrowDownButton, SIGNAL(clicked()), this, SLOT(arrowDownButtonClicked()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(pushButtonClickedSlot()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(pushButtonClickedSlot()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(pushButtonClickedSlot()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(pushButtonClickedSlot()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(pushButtonClickedSlot()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(pushButtonClickedSlot()));
    connect(ui->comboBox_2, SIGNAL(activated(const QString&)), this, SLOT(activatedSlot(const QString&)));
    connect(ui->comboBox_3, SIGNAL(activated(const QString&)), this, SLOT(activatedSlot(const QString&)));
    connect(ui->comboBox_4, SIGNAL(activated(const QString&)), this, SLOT(activatedSlot(const QString&)));
    connect(ui->comboBox_5, SIGNAL(activated(const QString&)), this, SLOT(activatedSlot(const QString&)));
    connect(ui->comboBox_6, SIGNAL(activated(const QString&)), this, SLOT(activatedSlot(const QString&)));
    connect(ui->comboBox_7, SIGNAL(activated(const QString&)), this, SLOT(activatedSlot(const QString&)));
}

/****************************************************************************
**
** 函数名称：ScanGroupEditView::activatedSlot
** 功能概述: scan/pass标记切换处理
** 参数说明 显示选择的模式
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ScanGroupEditView::activatedSlot(const QString& str)
{
    if (ui->pushButton->hasFocus())
        ui->pushButton->setText(str);
    else if (ui->pushButton_2->hasFocus())
        ui->pushButton_2->setText(str);
    else if (ui->pushButton_3->hasFocus())
        ui->pushButton_3->setText(str);
    else if (ui->pushButton_4->hasFocus())
        ui->pushButton_4->setText(str);
    else if (ui->pushButton_5->hasFocus())
        ui->pushButton_5->setText(str);
    else if (ui->pushButton_6->hasFocus())
        ui->pushButton_6->setText(str);
}
/****************************************************************************
**
** 函数名称：ScanGroupEditView::activatedSlot
** 功能概述: scan/pass标记切换处理
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ScanGroupEditView::pushButtonClickedSlot()
{
    if (ui->pushButton->hasFocus())
    {
        ui->comboBox_2->showPopup();
    }
    else if (ui->pushButton_2->hasFocus())
    {
        ui->comboBox_3->showPopup();
    }
    else if (ui->pushButton_3->hasFocus())
    {
        ui->comboBox_4->showPopup();
    }
    else if (ui->pushButton_4->hasFocus())
    {
        ui->comboBox_5->showPopup();
    }
    else if (ui->pushButton_5->hasFocus())
    {
        ui->comboBox_6->showPopup();
    }
    else if (ui->pushButton_6->hasFocus())
    {
        ui->comboBox_7->showPopup();
    }
}
/****************************************************************************
**
** 函数名称：ScanGroupEditView::arrowDownButtonClicked
** 功能概述: 频率下翻处理
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void  ScanGroupEditView::arrowDownButtonClicked()
{
    Logging::get()->info("ScanGroupEditView::arrowDownButtonClicked");
    
    if (ui->widget_11->getData() == "" && ui->widget_12->getData() == "")//最后一行数据为空时不往下翻
    {
        if (m_list[SCAN_GROUP_MAX_DISPLAY_DATA - 1].display)
        {
            MessageBox  msg;
            msg.move((SCREEN_SIZE_WIDTH - msg.width()) / 2, (SCREEN_SIZE_HEIGHT - msg.height()) / 2);
            msg.SetMessage(tr("Warning"), tr("No data to display"), 0);
            msg.exec() ;
            return;
        }
        else
        {
            int n = 0;
            bool bDisplay = false;
            
            while (n < SCAN_GROUP_MAX_DISPLAY_DATA)
            {
                if (m_list[n].display)
                {
                    bDisplay = true;
                }
                else if (bDisplay)
                {
                    if (m_list[n].strTx  != "" || m_list[n].strRx  != "")
                        break;
                }
                
                if (n == SCAN_GROUP_MAX_DISPLAY_DATA - 1)
                {
                    MessageBox  msg;
                    msg.move((SCREEN_SIZE_WIDTH - msg.width()) / 2, (SCREEN_SIZE_HEIGHT - msg.height()) / 2);
                    msg.SetMessage(tr("Warning"), tr("No data to display"), 0);
                    msg.exec() ;
                    return;
                }
                
                n++;
            }
        }
    }
    
    for (int n = 0 ; n < SCAN_GROUP_MAX_DISPLAY_DATA - 6; n++)
    {
        if (m_list[n].display)
        {
            m_list[n].display = false;
            m_list[n].strTx = ui->widget->getData();
            m_list[n].strRx = ui->widget_2->getData();
            m_list[n].scanFlag = ui->pushButton->text();
            ui->widget->setData((ui->widget_3->getData()));
            ui->widget_2->setData(ui->widget_4->getData());
            ui->pushButton->setText(ui->pushButton_2->text());
            ui->widget_3->setData(ui->widget_5->getData());
            ui->widget_4->setData(ui->widget_6->getData());
            ui->pushButton_2->setText(ui->pushButton_3->text());
            ui->widget_5->setData(ui->widget_7->getData());
            ui->widget_6->setData(ui->widget_8->getData());
            ui->pushButton_3->setText(ui->pushButton_4->text());
            ui->widget_7->setData(ui->widget_9->getData());
            ui->widget_8->setData(ui->widget_10->getData());
            ui->pushButton_4->setText(ui->pushButton_5->text());
            ui->widget_9->setData(ui->widget_11->getData());
            ui->widget_10->setData(ui->widget_12->getData());
            ui->pushButton_5->setText(ui->pushButton_6->text());
            ui->widget_11->setData(m_list[n + 6].strTx);
            ui->widget_12->setData(m_list[n + 6].strRx);
            ui->pushButton_6->setText(m_list[n + 6].scanFlag);
            m_list[n + 6].display = true;
            break;
        }
    }
}
/****************************************************************************
**
** 函数名称：ScanGroupEditView::arrowUpButtonClicked
** 功能概述: 频率上翻处理
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void  ScanGroupEditView::arrowUpButtonClicked()
{
    Logging::get()->info("ScanGroupEditView::arrowUpButtonClicked");
    
    if (m_list[0].display)//第一行数据已经显示在最上面时不往上翻。
    {
        return;
    }
    
    for (int n = 1; n < SCAN_GROUP_MAX_DISPLAY_DATA - 5; n++)
    {
        if (m_list[n].display)
        {
            m_list[n + 5].display = false;
            m_list[n + 5].strTx = ui->widget_11->getData();
            m_list[n + 5].strRx = ui->widget_12->getData();
            m_list[n + 5].scanFlag = ui->pushButton_6->text() ;
            ui->widget_11->setData(ui->widget_9->getData());
            ui->widget_12->setData(ui->widget_10->getData());
            ui->pushButton_6->setText(ui->pushButton_5->text());
            ui->widget_9->setData(ui->widget_7->getData());
            ui->widget_10->setData(ui->widget_8->getData());
            ui->pushButton_5->setText(ui->pushButton_4->text());
            ui->widget_7->setData(ui->widget_5->getData());
            ui->widget_8->setData(ui->widget_6->getData());
            ui->pushButton_4->setText(ui->pushButton_3->text());
            ui->widget_5->setData(ui->widget_3->getData());
            ui->widget_6->setData(ui->widget_4->getData());
            ui->pushButton_3->setText(ui->pushButton_2->text());
            ui->widget_3->setData(ui->widget->getData());
            ui->widget_4->setData(ui->widget_2->getData());
            ui->pushButton_2->setText(ui->pushButton->text());
            ui->widget->setData(m_list[n - 1].strTx);
            ui->widget_2->setData(m_list[n - 1].strRx);
            ui->pushButton->setText(m_list[n - 1].scanFlag);
            m_list[n - 1].display = true;
            break;
        }
    }
}
/****************************************************************************
**
** 函数名称：ScanGroupEditView::homeClickedSlot
** 功能概述: 返回到主菜单
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ScanGroupEditView:: homeClickedSlot()
{
    Logging::get()->info("ScanGroupEditView::homeClickedSlot");
    QMap <QString, QString> paraMap;
    emit afterPageSignal(SCAN_GROUP_EDIT_VIEW, HOME_VIEW_NAME, paraMap);
}
/****************************************************************************
**
** 函数名称：ScanGroupEditView::okButtonClickedSlot
** 功能概述: 确认保存
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ScanGroupEditView:: okButtonClickedSlot()
{
    Logging::get()->info("ScanGroupEditView::okButtonClickedSlot");
    QMap <QString, QString>paraMap;
    QString strModle  =  QString(SCAN_GROUP_MODLE_OK);
    paraMap.insert("Modle", strModle);
    
    if (m_strModle == "Edit")
    {
        Database* database = new Database();
        database->openConnection();
        bool hasTransaction = database->transaction();
        QString strUUID = m_stationMap[Constants::SCAN_GROUP_UUID];
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
        QString sTime = (QString::number(y) + "-" + mStr + "-" + dStr + "  " + strTime);
        QString sql1 =
            "update scangroup set groupname=:GroupName,DwellTime=:DwellTime,ScanMode=:ScanMode,UpdateDateTime=:UpdateDateTime  where uuid=:UUID";
        QVariantMap map1;
        bool result1 = true;
        QString groupName = ui->groupNameEdit->text();
        QString dwellTime = ui->dwellTimeEdit->text();
        QString scanMode = ui->comboBox->currentText();
        map1.insert(Constants::SCAN_GROUP_UUID, strUUID);
        map1.insert(Constants::SCAN_GROUP_GROUPNAME, groupName);
        map1.insert(Constants::SCAN_GROUP_UDATETIME, sTime);
        map1.insert(Constants::SCAN_GROUP_SCANMODE, scanMode);
        map1.insert(Constants::SCAN_GROUP_DWELLTIME, dwellTime);
        result1 = database->executeSql(sql1, map1);
        
        if (hasTransaction && result1)
        {
            database->commit();
        }
        else
        {
            database->rollback();
        }
        
        QSqlQuery idqueryFrequency = database->getQuery();
        QString idFrequency = "select UUID from Frequency where FKey=";
        idFrequency.append("'");
        idFrequency.append(strUUID);
        idFrequency.append("';");
        idqueryFrequency.prepare(idFrequency);
        idqueryFrequency.exec();
        QSqlQuery idqueryFrequencyAll = database->getQuery();
        int intCount = 0;
        QString sqlFrequency = "update Frequency set Tx=:Tx,Rx=:Rx,scanFlag=:scanFlag  where UUID=:UUID";
        QString sqlFrequencyDel = "delete from Frequency where UUID=:UUID";
        QVariantMap mapFrequency;
        QVariantMap mapFrequencyDel;
        QString uuidFrequency ;
        int ret = 1;
        QString sqlFrequencyAdd =
            "insert into Frequency (UUID,FKey,Ower,Tx,Rx,scanFlag)values(:UUID,:FKey,:Ower,:Tx,:Rx,:scanFlag)";
            
        for (int n = 0; n < SCAN_GROUP_MAX_DISPLAY_DATA; n++)
        {
            bool hasData = idqueryFrequency.next();
            
            if (hasData)
            {
                uuidFrequency = idqueryFrequency.value(0).toString();
                mapFrequency.insert("UUID", uuidFrequency);
            }
            else
            {
                QUuid idFrequency = QUuid::createUuid();
                QString strFrequency = idFrequency.toString();
                mapFrequency.insert("UUID", strFrequency);
                mapFrequency.insert("FKey", strUUID);
                mapFrequency.insert("Ower", COMMON_OWER_SCANGROUP);
            }
            
            if (!m_list[n].display)
            {
                mapFrequency.insert("Tx", m_list[n].strTx.trimmed());
                mapFrequency.insert("Rx", m_list[n].strRx.trimmed());
                
                if (m_list[n].scanFlag == "Scan")
                    mapFrequency.insert("scanFlag", "S");
                else
                    mapFrequency.insert("scanFlag", "P");
            }
            else
            {
                switch (intCount)
                {
                case 0:
                    mapFrequency.insert("Tx", ui->widget->getData());
                    mapFrequency.insert("Rx", ui->widget_2->getData());
                    
                    if (ui->pushButton->text() == "Scan")
                        mapFrequency.insert("scanFlag", "S");
                    else
                        mapFrequency.insert("scanFlag", "P");
                        
                    break;
                    
                case 1:
                    mapFrequency.insert("Tx", ui->widget_3->getData());
                    mapFrequency.insert("Rx", ui->widget_4->getData());
                    
                    if (ui->pushButton_2->text() == "Scan")
                        mapFrequency.insert("scanFlag", "S");
                    else
                        mapFrequency.insert("scanFlag", "P");
                        
                    break;
                    
                case 2:
                    mapFrequency.insert("Tx", ui->widget_5->getData());
                    mapFrequency.insert("Rx", ui->widget_6->getData());
                    
                    if (ui->pushButton_3->text() == "Scan")
                        mapFrequency.insert("scanFlag", "S");
                    else
                        mapFrequency.insert("scanFlag", "P");
                        
                    break;
                    
                case 3:
                    mapFrequency.insert("Tx", ui->widget_7->getData());
                    mapFrequency.insert("Rx", ui->widget_8->getData());
                    
                    if (ui->pushButton_4->text() == "Scan")
                        mapFrequency.insert("scanFlag", "S");
                    else
                        mapFrequency.insert("scanFlag", "P");
                        
                    break;
                    
                case 4:
                    mapFrequency.insert("Tx", ui->widget_9->getData());
                    mapFrequency.insert("Rx", ui->widget_10->getData());
                    
                    if (ui->pushButton_5->text() == "Scan")
                        mapFrequency.insert("scanFlag", "S");
                    else
                        mapFrequency.insert("scanFlag", "P");
                        
                    break;
                    
                case 5:
                    mapFrequency.insert("Tx", ui->widget_11->getData());
                    mapFrequency.insert("Rx", ui->widget_12->getData());
                    
                    if (ui->pushButton_6->text() == "Scan")
                        mapFrequency.insert("scanFlag", "S");
                    else
                        mapFrequency.insert("scanFlag", "P");
                        
                    break;
                    
                default :
                    break;
                }
                
                intCount++;
            }
            
            if ((mapFrequency["Tx"] == "") && (mapFrequency["Rx"] == ""))
            {
                if (hasData)
                {
                    mapFrequencyDel.insert("UUID", uuidFrequency);
                    ret = database->executeSql(sqlFrequencyDel, mapFrequencyDel);
                }
                else
                    continue;
            }
            else
            {
                if (hasData)
                    ret = database->executeSql(sqlFrequency, mapFrequency);
                else
                    ret = database->executeSql(sqlFrequencyAdd, mapFrequency);
            }
            
            if (hasTransaction && ret)
            {
                database->commit();
            }
            else
            {
                database->rollback();
            }
        }
    }
    else
    {
        Database* database = new Database();
        database->openConnection();
        bool hasTransaction = database->transaction();
        QSqlQuery idqueryFrequencyAll = database->getQuery();
        int intCount = 0;
        QUuid idStation = QUuid::createUuid();
        QString strStationId = idStation.toString();
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
        QString sTime = (QString::number(y) + "-" + mStr + "-" + dStr + "  " + strTime);
        QString sql1 =
            "insert into scangroup(UUID, GroupName,DwellTime,ScanMode,CreateDateTime) values(:UUID,:GroupName,:DwellTime,:ScanMode,:CreateDateTime)";
        QVariantMap map1;
        bool result1 = true;
        map1.insert(Constants::SCAN_GROUP_UUID, strStationId);
        map1.insert(Constants::SCAN_GROUP_CDATETIME, sTime);
        map1.insert(Constants::SCAN_GROUP_GROUPNAME, ui->groupNameEdit->text());
        map1.insert(Constants::SCAN_GROUP_DWELLTIME, ui->dwellTimeEdit->text());
        QString scanMode;
        
        if (ui->comboBox->currentIndex() == 0)
        {
            scanMode += "ARQ";
        }
        else if (ui->comboBox->currentIndex() == 1)
        {
            scanMode += "FEC";
        }
        else if (ui->comboBox->currentIndex() == 2)
        {
            scanMode += "Auto";
        }
        
        map1.insert(Constants::SCAN_GROUP_SCANMODE, scanMode);
        result1 = database->executeSql(sql1, map1);
        QVariantMap map2;
        map2.insert("Ower", COMMON_OWER_SCANGROUP);
        intCount = 0;
        bool result2 = true;
        
        for (int n = 0; n < SCAN_GROUP_MAX_DISPLAY_DATA; n++)
        {
            if (!m_list[n].display)
            {
                if (m_list[n].strTx == "" && m_list[n].strRx == "")
                    continue;
                    
                map2.insert("Tx", m_list[n].strTx.trimmed());
                map2.insert("Rx", m_list[n].strRx.trimmed());
                
                if (m_list[n].scanFlag == "Scan")
                    map2.insert("scanFlag", "S");
                else
                    map2.insert("scanFlag", "P");
            }
            else if (intCount <= 5)
            {
                switch (intCount)
                {
                case 0:
                    map2.insert("Tx", ui->widget->getData());
                    map2.insert("Rx", ui->widget_2->getData());
                    
                    if (ui->pushButton->text() == "Scan")
                        map2.insert("scanFlag", "S");
                    else
                        map2.insert("scanFlag", "P");
                        
                    break;
                    
                case 1:
                    map2.insert("Tx", ui->widget_3->getData());
                    map2.insert("Rx", ui->widget_4->getData());
                    
                    if (ui->pushButton_2->text() == "Scan")
                        map2.insert("scanFlag", "S");
                    else
                        map2.insert("scanFlag", "P");
                        
                    break;
                    
                case 2:
                    map2.insert("Tx", ui->widget_5->getData());
                    map2.insert("Rx", ui->widget_6->getData());
                    
                    if (ui->pushButton_3->text() == "Scan")
                        map2.insert("scanFlag", "S");
                    else
                        map2.insert("scanFlag", "P");
                        
                    break;
                    
                case 3:
                    map2.insert("Tx", ui->widget_7->getData());
                    map2.insert("Rx", ui->widget_8->getData());
                    
                    if (ui->pushButton_4->text() == "Scan")
                        map2.insert("scanFlag", "S");
                    else
                        map2.insert("scanFlag", "P");
                        
                    break;
                    
                case 4:
                    map2.insert("Tx", ui->widget_9->getData());
                    map2.insert("Rx", ui->widget_10->getData());
                    
                    if (ui->pushButton_5->text() == "Scan")
                        map2.insert("scanFlag", "S");
                    else
                        map2.insert("scanFlag", "P");
                        
                    break;
                    
                case 5:
                    map2.insert("Tx", ui->widget_11->getData());
                    map2.insert("Rx", ui->widget_12->getData());
                    
                    if (ui->pushButton_6->text() == "Scan")
                        map2.insert("scanFlag", "S");
                    else
                        map2.insert("scanFlag", "P");
                        
                    break;
                    
                default :
                    break;
                }
                
                intCount++;
            }
            
            if ((map2["Tx"] == "")  && (map2["Rx"] == ""))
            {
                continue;
            }
            else
            {
                QUuid idFrequency = QUuid::createUuid();
                QString strFrequency = idFrequency.toString();
                QString sql2 = "insert into Frequency (UUID,FKey,Ower,Tx,Rx,scanFlag)values(:UUID,:FKey,:Ower,:Tx,:Rx,:scanFlag)";
                map2.insert("UUID", strFrequency);
                map2.insert("FKey", strStationId);
                result2 = database->executeSql(sql2, map2);
            }
        }
        
        if (hasTransaction && result1 && result2)
        {
            database->commit();
        }
        else
        {
            database->rollback();
        }
    }
    
    emit afterPageSignal(SCAN_GROUP_EDIT_VIEW, SCAN_GROUP_VIEW, paraMap);
    return;
}
/****************************************************************************
**
** 函数名称：ScanGroupEditView::cancelButtonClickedSlot
** 功能概述: 取消保存返回上层
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void ScanGroupEditView:: cancelButtonClickedSlot()
{
    Logging::get()->info("ScanGroupEditView::cancelButtonClickedSlot");
    QMap <QString, QString> paraMap;
    emit afterPageSignal(SCAN_GROUP_EDIT_VIEW, SCAN_GROUP_VIEW, paraMap);
}
/****************************************************************************
**
** 函数名称：ScanGroupEditView::eventFilter
** 功能概述: 事件监听函数，响应用户键盘操作
** 参数说明 watched：发送方， event：事件数据
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool ScanGroupEditView::eventFilter(QObject* watched, QEvent* event)
{
    Logging::get()->info("ScanGroupEditView::eventFilter");
    QStringList nameList;
    nameList << "groupNameEdit" << "dwellTimeEdit" << "scanModeFocus" <<
             "pushButton" << "widget" << "widget_2" << "pushButton_2" << "widget_3" << "widget_4" << "pushButton_3" <<
             "widget_5" << "widget_6" << "pushButton_4" << "widget_7" << "widget_8" << "pushButton_5" <<
             "widget_9" << "widget_10" << "pushButton_6" << "widget_11" << "widget_12" <<
             "arrowUpButton" << "arrowDownButton" <<
             "okBtn" << "cancelBtn" << "homeBtn";
    QStringList widgetList;
    widgetList << "widget" << "widget_2" << "widget_3" << "widget_4"
               << "widget_5" << "widget_6" << "widget_7" << "widget_8"
               << "widget_9" << "widget_10" << "widget_11" << "widget_12";
    QKeyEvent* key_event = static_cast<QKeyEvent*>(event);
    int a =   key_event->key();
    // 按下时键屏蔽
    // 弹起时键屏蔽
    // 默认键值51 响应一次
    if (m_editmode)//频率编辑模式状态
    {
        if (QEvent::KeyPress == event->type())
        {
            return true;
        }
        else if (QEvent::KeyRelease  == event->type())
        {
            return true;
        }
        
        if (a == Qt::Key_Enter || a == Qt::Key_Return)//频率编辑模式完成退出响应
        {
            m_editmode = false;
            
            for (int i = 0; i < widgetList.length(); i++)
            {
                QWidget* widget = findChild<QWidget*>(widgetList.at(i));
                
                if (widget && widget->hasFocus())
                {
                    FrequencyInput* inputwidget = static_cast<FrequencyInput*>(widget);
                    inputwidget->offEditmode();
                }
            }
        }
        else if (a == Qt::Key_Escape)//频率编辑模式完成退出响应
        {
            m_editmode = false;
            
            for (int i = 0; i < widgetList.length(); i++)
            {
                QWidget* widget = findChild<QWidget*>(widgetList.at(i));
                
                if (widget && widget->hasFocus())
                {
                    FrequencyInput* inputwidget = static_cast<FrequencyInput*>(widget);
                    inputwidget->offEditmode(false);
                }
            }
        }
        
        return true;
    }
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
                if (nameList.at(i) == "homeBtn")
                {
                    Button* button = static_cast<Button*>(widget);
                    button->setIcon(QIcon(":/images/home_normal"));
                }
                else if (nameList.at(i) == "groupNameEdit")
                {
                    ui->group_name->setCurrentRow(-1);
                }
                else if (nameList.at(i) == "dwellTimeEdit")
                {
                    ui->dwell_time->setCurrentRow(-1);
                }
                else if (nameList.at(i) == "scanModeFocus")
                {
                    ui->scan_mode->setCurrentRow(-1);
                }
                else if (widgetList.count(nameList.at(i)))
                {
                    FrequencyInput* inputwidget = static_cast<FrequencyInput*>(widget);
                    inputwidget->widgetCleanFocus();
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
            
            if (nameList.at(next) == "homeBtn")
            {
                Button* button = static_cast<Button*>(widgetnext);
                button->setIcon(QIcon(":/images/home_hover"));
            }
            else if (nameList.at(next) == "groupNameEdit")
            {
                ui->group_name->setCurrentRow(0);
            }
            else if (nameList.at(next) == "dwellTimeEdit")
            {
                ui->dwell_time->setCurrentRow(0);
            }
            else if (nameList.at(next) == "scanModeFocus")
            {
                ui->scan_mode->setCurrentRow(0);
            }
            else if (widgetList.count(nameList.at(next)))
            {
                FrequencyInput* inputwidget = static_cast<FrequencyInput*>(widgetnext);
                inputwidget->widgetSetFocus();
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
         // 按钮图片切换 focus 离开 按钮图片变暗
        for (int i = 0; i < nameList.length(); i++)
        {
            QWidget* widget = findChild<QWidget*>(nameList.at(i));
            
            if (widget && widget->hasFocus())
            {
                
                if (nameList.at(i) == "homeBtn")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/home_normal"));
                }
                else if (nameList.at(i) == "groupNameEdit")
                {
                    ui->group_name->setCurrentRow(-1);
                }
                else if (nameList.at(i) == "dwellTimeEdit")
                {
                    ui->dwell_time->setCurrentRow(-1);
                }
                else if (nameList.at(i) == "scanModeFocus")
                {
                    ui->scan_mode->setCurrentRow(-1);
                }
                else if (widgetList.count(nameList.at(i)))
                {
                    FrequencyInput* inputwidget = static_cast<FrequencyInput*>(widget);
                    inputwidget->widgetCleanFocus();
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
            
            if (nameList.at(prev) == "homeBtn")
            {
                QToolButton* button = static_cast<QToolButton*>(widgetprev);
                button->setIcon(QIcon(":/images/home_hover"));
            }
            else if (nameList.at(prev) == "groupNameEdit")
            {
                ui->group_name->setCurrentRow(0);
            }
            else if (nameList.at(prev) == "dwellTimeEdit")
            {
                ui->dwell_time->setCurrentRow(0);
            }
            else if (nameList.at(prev) == "scanModeFocus")
            {
                ui->scan_mode->setCurrentRow(0);
            }
            else if (widgetList.count(nameList.at(prev)))
            {
                FrequencyInput* inputwidget = static_cast<FrequencyInput*>(widgetprev);
                inputwidget->widgetSetFocus();
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
                if (nameList.at(i) == "homeBtn")
                {
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                }
                else if (nameList.at(i) == "scanModeFocus")
                {
                    ui->comboBox->showPopup();
                }
                else if (widgetList.count(nameList.at(i)))
                {
                    FrequencyInput* inputwidget = static_cast<FrequencyInput*>(widget);
                    bool txOrRx;
                    int n = 0;
                    
                    for (; n < widgetList.length(); n++)
                    {
                        if (widgetList.at(n) == nameList.at(i))
                            break;
                            
                        if (n + 1 == widgetList.length())
                            n = -1;
                    }
                    
                    if (n % 2 == 1)
                        txOrRx = false;
                    else
                        txOrRx = true;
                        
                    inputwidget->openEditmode(txOrRx);//开启频率编辑模式
                    inputwidget->widgetCleanFocus();
                    m_editmode = true;
                }
                
                break;
            }
        }
        
        break;
    }
    
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
        //触发按键事件
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
** 函数名称：ScanGroupEditView::frontPageSlot
** 功能概述: 打开页面时更新页面数据
** 参数说明： thisID：起始页面， fowordID：目标页面， paraMap：传递参数
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void  ScanGroupEditView::frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap)
{
    if (fowordID != SCAN_GROUP_EDIT_VIEW) {return;}
    
    Logging::get()->info("ScanGroupEditView::frontPageSlot");
    m_editmode = false;
    ui->groupNameEdit->setFocus();
    ui->homeBtn->setIcon(QIcon(":/images/home_normal"));
    m_stationMap = paraMap;
    
    if (m_stationMap.isEmpty()) {return;}
    
    m_strModle  =  m_stationMap[SCAN_GROUP_MODLE_NAME];
    
    for (int n = 0; n < SCAN_GROUP_MAX_DISPLAY_DATA; n++)
    {
        m_list[n].display = false;
        m_list[n].clear();
        m_list[n].scanFlag = "Scan";
    }
    
    ui->groupNameEdit->clear();
    ui->dwellTimeEdit->clear();
    ui->widget->editDataClean();
    ui->widget_2->editDataClean();
    ui->widget_3->editDataClean();
    ui->widget_4->editDataClean();
    ui->widget_5->editDataClean();
    ui->widget_6->editDataClean();
    ui->widget_7->editDataClean();
    ui->widget_8->editDataClean();
    ui->widget_9->editDataClean();
    ui->widget_10->editDataClean();
    ui->widget_11->editDataClean();
    ui->widget_12->editDataClean();
    ui->pushButton->setText(QString("Scan"));
    ui->pushButton_2->setText(QString("Scan"));
    ui->pushButton_3->setText(QString("Scan"));
    ui->pushButton_4->setText(QString("Scan"));
    ui->pushButton_5->setText(QString("Scan"));
    ui->pushButton_6->setText(QString("Scan"));
    m_list[0].display = m_list[1].display = m_list[2].display = m_list[3].display = m_list[4].display = m_list[5].display =
            true;
            
    if (m_strModle == "Edit")
    {
        ui->titleWidget->setText(Constants::SCAN_GROUP__EDIT_TITLE);
        QString strUUID = m_stationMap[Constants::SCAN_GROUP_UUID];
        QString strGroupName = m_stationMap[Constants::SCAN_GROUP_GROUPNAME];
        QString strDwellTime = m_stationMap[Constants::SCAN_GROUP_DWELLTIME];
        QString strScanMode = m_stationMap[Constants::SCAN_GROUP_SCANMODE];
        ui->groupNameEdit->setText(strGroupName);
        ui->dwellTimeEdit->setText(strDwellTime);
        
        if (strScanMode == "ARQ")
        {
            ui->comboBox->setCurrentIndex(0);
        }
        else if (strScanMode == "FEC")
        {
            ui->comboBox->setCurrentIndex(1);
        }
        else if (strScanMode == "Auto")
        {
            ui->comboBox->setCurrentIndex(2);
        }
        else
            ui->comboBox->setCurrentIndex(0);
            
        Database* database = new Database();
        database->openConnection();
        QSqlQuery queryFrequency = database->getQuery();
        QString Frequency = "select Tx,Rx,scanFlag  from Frequency  where FKey= ";
        Frequency.append("'");
        Frequency.append(strUUID);
        Frequency.append("';");
        queryFrequency.prepare(Frequency);
        queryFrequency.exec();
        int intCount = 0;
        
        while (queryFrequency.next())
        {
            m_list[intCount].strTx = queryFrequency.value(0).toString();
            m_list[intCount].strRx = queryFrequency.value(1).toString();
            QString scanFlag = queryFrequency.value(2).toString();
            
            if (scanFlag == "S")
                m_list[intCount].scanFlag = QString("Scan");
            else
                m_list[intCount].scanFlag = QString("Pass");
                
            intCount++;
            
            if (intCount == 20)
                break;
        }
        
        ui->pushButton->setText(QString("Scan"));
        ui->pushButton_2->setText(QString("Scan"));
        ui->pushButton_3->setText(QString("Scan"));
        ui->pushButton_4->setText(QString("Scan"));
        ui->pushButton_5->setText(QString("Scan"));
        ui->pushButton_6->setText(QString("Scan"));
        
        if (intCount >= 1)
        {
            ui->widget->setData(m_list[0].strTx);
            ui->widget_2->setData(m_list[0].strRx);
            ui->pushButton->setText(m_list[0].scanFlag);
        }
        
        if (intCount >= 2)
        {
            ui->widget_3->setData(m_list[1].strTx);
            ui->widget_4->setData(m_list[1].strRx);
            ui->pushButton_2->setText(m_list[1].scanFlag);
        }
        
        if (intCount >= 3)
        {
            ui->widget_5->setData(m_list[2].strTx);
            ui->widget_6->setData(m_list[2].strRx);
            ui->pushButton_3->setText(m_list[2].scanFlag);
        }
        
        if (intCount >= 4)
        {
            ui->widget_7->setData(m_list[3].strTx);
            ui->widget_8->setData(m_list[3].strRx);
            ui->pushButton_4->setText(m_list[3].scanFlag);
        }
        
        if (intCount >= 5)
        {
            ui->widget_9->setData(m_list[4].strTx);
            ui->widget_10->setData(m_list[4].strRx);
            ui->pushButton_5->setText(m_list[4].scanFlag);
        }
        
        if (intCount >= 6)
        {
            ui->widget_11->setData(m_list[5].strTx);
            ui->widget_12->setData(m_list[5].strRx);
            ui->pushButton_6->setText(m_list[5].scanFlag);
        }
    }
    else
    {
        ui->comboBox->setCurrentIndex(0);
        ui->titleWidget->setText(Constants::SCAN_GROUP__NEW_TITLE);
    }
}
/****************************************************************************
**
** 函数名称：ScanGroupEditView::～ScanGroupEditView
** 功能概述: 析构函数
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
ScanGroupEditView::~ScanGroupEditView()
{
    Logging::get()->info("ScanGroupEditView::~ScanGroupEditView");
    delete ui;
}

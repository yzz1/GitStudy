#include "stationeditview.h"
#include "ui_stationeditview.h"
#include "core/database/database.h"
#include "widgets/titlewidget.h"
#include "widgets/messagebox.h"
#include <QString>
#include <QDateTime>
#include <QUuid>
#include <QMap>
#include "views/common/constants.h"
#include <QEvent>
#include <QKeyEvent>
#include "widgets/button.h"
#include "logging.h"
#include <QDebug>
#include "widgets/iocmessage.h"
/****************************************************************************
**
** 函数名称：FrequencyStationData::clear
** 功能概述: 清理频率缓存数据
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void FrequencyStationData::clear()
{
    Logging::get()->info("FrequencyStationData::clear");
    strNO.clear();
    strChannel.clear();
    strTx.clear();
    strRx.clear();
}
/****************************************************************************
**
** 函数名称：StationEditView::StationEditView
** 功能概述: 初始化
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
StationEditView::StationEditView(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::StationEditView)
{
    Logging::get()->info("StationEditView::StationEditView");
    ui->setupUi(this);
    ui->tiltewidget->setText("NEW STATION");
    this->installEventFilter(this);
    m_editmode = false;
    QRegExp rx("([0-9][0-9]+9)");
    ui-> callcode->setValidator(new QRegExpValidator(rx, this));
    ui->callcode->setMaxLength(CONTACTS_CALLCODE_MAXLEN);
    ui->name->setMaxLength(CONTACTS_NAME_MAXLEN);
    ui->callsign->setMaxLength(CONTACTS_CALLSIGN_MAXLEN);
    ui->country->setMaxLength(CONTACTS_COUNTRY_MAXLEN);
    ui->no->setValidator(new QRegExpValidator(rx, this));
    ui->no2->setValidator(new QRegExpValidator(rx, this));
    ui->no3->setValidator(new QRegExpValidator(rx, this));
    ui->channel1->setValidator(new QRegExpValidator(rx, this));
    ui->channel2->setValidator(new QRegExpValidator(rx, this));
    ui->channel3->setValidator(new QRegExpValidator(rx, this));
    FrequencyStationData temp;
    
    for (int n = 0; n < CONTACTS_STATION_MAX_DISPLAY_DATA; n++)
    {
        m_list.append(temp);
    }
    
    connect(ui->okBtn, SIGNAL(clicked()), this, SLOT(saveData()));
    connect(ui->cancelBtn, SIGNAL(clicked(bool)), this, SLOT(cancelButtonClicked()));
    connect(ui->homeTBnt, SIGNAL(clicked()), this, SLOT(homeClickedSlot()));
    connect(ui->individualTBnt, SIGNAL(clicked(bool)), this, SLOT(individualClickedSlot()));
    connect(ui->stationTBnt, SIGNAL(clicked()), this, SLOT(stationClickedSlot()));
    connect(ui->arrowUpButton, SIGNAL(clicked()), this, SLOT(arrowUpButtonClicked()));
    connect(ui->arrowDownButton, SIGNAL(clicked()), this, SLOT(arrowDownButtonClicked()));
    ui->name->setFocus();
}
/****************************************************************************
**
** 函数名称：StationEditView::～StationEditView
** 功能概述: 析构函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
StationEditView::~StationEditView()
{
    Logging::get()->info("StationEditView::~StationEditView");
    delete ui;
}
/****************************************************************************
**
** 函数名称：StationEditView::saveData
** 功能概述: 保存数据
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool  StationEditView::saveData()
{
    Logging::get()->info("StationEditView::saveData");
    QRegExp re("\\d{4}|\\d{5}|\\d{9}");
    QString callCode = ui->callcode->text();
    
    if (!callCode.isEmpty() && !re.exactMatch(callCode))
    {
        IocMessage infomsg;
        infomsg.move((SCREEN_SIZE_WIDTH - infomsg.width()) / 2, (SCREEN_SIZE_HEIGHT - infomsg.height()) / 2);
        infomsg.SetIoc(":/images/images/Call_exclamatory_mark.png", 120, false);
        infomsg.SetMessage(tr("Warning"), tr("Callcode Error! "), tr("Callcode must be 4 or 5 or 9 digits!"));
        QFont font("Ubuntu", 18, QFont::Bold);
        infomsg.SetFont(font);
        infomsg.exec();
        return false;
    }
    
    QMap <QString, QString>paraMap;
    
    if (m_strModle == CONTACTS_STATION_MODLE_EDIT)
    {
        QString strModle  =  QString(CONTACTS_STATION_MODLE_EDIT);
        paraMap.insert(CONTACTS_STATION_MODLE_NAME, strModle);
        Database* database = new Database();
        database->openConnection();
        QString strUUID = m_stationMap["UUID"];
        paraMap.insert("UUID", strUUID);
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
            "update Station set name=:name,CallSign=:CallSign,Country=:Country,CallCode=:CallCode,UpdateDateTime=:UpdateDateTime  where uuid=:uuid";
        QVariantMap map1;
        map1.insert("uuid", strUUID);
        map1.insert("UpdateDateTime", sTime);
        
        for (int i = 1; i < 2; i++)//保存主表数据
        {
            for (int j = 0; j < 4; j++)
            {
                QLineEdit* text = static_cast<QLineEdit*>(ui->gridLayout->itemAtPosition(i, j)->widget());
                QLineEdit* callcode = static_cast<QLineEdit*>(ui->gridLayout->itemAtPosition(1, 3)->widget());
                QString callcode1 = callcode->text();
                
                if (j == 0)
                {
                    if (text->text().length() == 0)
                    {
                        map1.insert("name", callcode1);
                    }
                    else
                    {
                        map1.insert("name", text->text());
                    }
                }
                else if (j == 1)
                {
                    map1.insert("CallSign",  text->text());
                }
                else if (j == 2)
                {
                    if (text->text().length() == 0)
                    {
                        map1.insert("Country", "null");
                    }
                    else
                    {
                        map1.insert("Country", text->text());
                    }
                }
                else if (j == 3)
                {
                    map1.insert("CallCode",  text->text());
                }
            }
        }
        
        database->executeSql(sql1, map1);
        QSqlQuery idqueryFrequency = database->getQuery();
        QString idFrequency = "select UUID from Frequency where FKey=";
        idFrequency.append("'");
        idFrequency.append(strUUID);
        idFrequency.append("';");
        idqueryFrequency.prepare(idFrequency);
        idqueryFrequency.exec();
        QStringList channelNameList;
        int count = 0;
        
        for (int n = 0; n < CONTACTS_STATION_MAX_DISPLAY_DATA; n++)//提取所有通道号
        {
            if (!m_list[n].display)
                channelNameList << m_list[n].strChannel;
            else if (count <= 2)
            {
                switch (count)
                {
                case 0:
                    channelNameList  <<  ui->channel1->text();
                    break;
                    
                case 1:
                    channelNameList  <<  ui->channel2->text();
                    break;
                    
                case 2:
                    channelNameList  <<  ui->channel3->text();
                    break;
                }
                
                count++;
            }
        }
        
        for (int n = 0; n < channelNameList.length(); n++)//比较通道号是否重复
            for (int m = 0; m < channelNameList.length(); m++)
            {
                if (m == n || channelNameList[n] == "")
                    continue;
                    
                if (channelNameList[n] == channelNameList[m])
                {
                    MessageBox mgb;
                    mgb.SetMessage(tr("Message"), tr("Channel must be unique."), 0);
                    mgb.exec() ;
                    return false;
                }
            }
            
        QSqlQuery idqueryFrequencyAll = database->getQuery();
        int intCount = 0;
        bool hasOldRecord = false;
        
        for (int n = 0; n < CONTACTS_STATION_MAX_DISPLAY_DATA; n++)//查询通道对应的UUID号
        {
            QString uuid;
            QString channel;
            bool hasData = idqueryFrequency.next();
            
            if (hasData)
            {
                uuid = idqueryFrequency.value(0).toString();
            }
            
            if (!m_list[n].display)
            {
                if (m_list[n].strNO == "" && m_list[n].strChannel == ""
                    && m_list[n].strTx == "" && m_list[n].strRx == "")
                    continue;
                    
                channel = m_list[n].strChannel;
            }
            else if (intCount <= 2)
            {
                switch (intCount)
                {
                case 0:
                    channel = ui->channel1->text();
                    break;
                    
                case 1:
                    channel = ui->channel2->text();
                    break;
                    
                case 2:
                    channel = ui->channel3->text();
                    break;
                }
                
                intCount++;
            }
            
            if (channel == "")
            {
                continue;
            }
            else
            {
                QString idFrequencyAll = "select UUID from Frequency where channel = ";
                idFrequencyAll.append("'") ;
                idFrequencyAll.append(channel) ;
                idFrequencyAll.append("';  ") ;
                idqueryFrequencyAll.prepare(idFrequencyAll);
                idqueryFrequencyAll.exec();
                
                if (!hasData)
                {
                    if (idqueryFrequencyAll.next())
                    {
                        hasOldRecord = true;
                        break;
                    }
                }
                else if (idqueryFrequencyAll.next() && idqueryFrequencyAll.value(0).toString() !=  uuid)
                {//比较当前通道好的UUID是否和数据库相同通道号的UUID是否相同，不相同说明重复了
                    hasOldRecord = true;
                    break;
                }
            }
        }
        
        if (hasOldRecord)
        {
            MessageBox mgb;
            mgb.SetMessage(tr("Message"), tr("Channel already exists!"), 0);
            mgb.exec() ;
            return false;
        }
        
        bool hasTransaction = database->transaction();
        intCount = 0;
        idqueryFrequency.seek(0);
        QString sqlFrequency = "update Frequency set No=:No,Channel=:Channel,Tx=:Tx,Rx=:Rx  where UUID=:UUID";
        QString sqlFrequencyDel = "delete from Frequency where UUID=:UUID";
        QVariantMap mapFrequency;
        QVariantMap mapFrequencyDel;
        QString uuidFrequency ;
        int ret = 1;
        QLineEdit* name = static_cast<QLineEdit*>(ui->gridLayout->itemAtPosition(1, 0)->widget());
        QString name1 = name->text();
        QString sqlFrequencyAdd =
            "insert into Frequency (UUID,FKey,Ower,No,Channel,Tx,Rx)values(:UUID,:FKey,:Ower,:No,:Channel,:Tx,:Rx)";
            
        for (int n = 0; n < CONTACTS_STATION_MAX_DISPLAY_DATA; n++)//保存所有子表数据
        {
            bool hasData = idqueryFrequency.isValid();
            
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
                mapFrequency.insert("Ower", "S");
            }
            
            if (!m_list[n].display)
            {
                mapFrequency.insert("No", m_list[n].strNO);
                mapFrequency.insert("Channel", m_list[n].strChannel);
                mapFrequency.insert("Tx", m_list[n].strTx);
                mapFrequency.insert("Rx", m_list[n].strRx);
            }
            else
            {
                switch (intCount)
                {
                case 0:
                    mapFrequency.insert("No", ui->no->text());
                    mapFrequency.insert("Channel", ui->channel1->text());
                    mapFrequency.insert("Tx", ui->widget->getData());
                    mapFrequency.insert("Rx", ui->widget_2->getData());
                    break;
                    
                case 1:
                    mapFrequency.insert("No", ui->no2->text());
                    mapFrequency.insert("Channel", ui->channel2->text());
                    mapFrequency.insert("Tx", ui->widget_3->getData());
                    mapFrequency.insert("Rx", ui->widget_4->getData());
                    break;
                    
                case 2:
                    mapFrequency.insert("No", ui->no3->text());
                    mapFrequency.insert("Channel", ui->channel3->text());
                    mapFrequency.insert("Tx", ui->widget_5->getData());
                    mapFrequency.insert("Rx", ui->widget_6->getData());
                    break;
                    
                default :
                    break;
                }
                
                intCount++;
            }
            
            if ((mapFrequency["No"] == "")  && (mapFrequency["Channel"] == "") && (mapFrequency["Tx"] == "")
                && (mapFrequency["Rx"] == ""))
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
            
            idqueryFrequency.next();
        }
    }
    else
    {
        QStringList channelNameList;
        int count = 0;
        
        for (int n = 0; n < CONTACTS_STATION_MAX_DISPLAY_DATA; n++)//获取所有通道号
        {
            if (!m_list[n].display)
                channelNameList << m_list[n].strChannel;
            else if (count <= 2)
            {
                switch (count)
                {
                case 0:
                    channelNameList  <<  ui->channel1->text();
                    break;
                    
                case 1:
                    channelNameList  <<  ui->channel2->text();
                    break;
                    
                case 2:
                    channelNameList  <<  ui->channel3->text();
                    break;
                }
                
                count++;
            }
        }
        
        for (int n = 0; n < channelNameList.length(); n++)//比较通道号是否重复
            for (int m = 0; m < channelNameList.length(); m++)
            {
                if (m == n || channelNameList[n] == "")
                    continue;
                    
                if (channelNameList[n] == channelNameList[m])
                {
                    MessageBox mgb;
                    mgb.SetMessage(tr("Message"), tr("Channel must be unique."), 0);
                    mgb.exec() ;
                    return false;
                }
            }
            
        Database* database = new Database();
        database->openConnection();
        QSqlQuery idqueryFrequencyAll = database->getQuery();
        bool hasOldRecord = false;
        int intCount = 0;
        
        for (int n = 0; n < CONTACTS_STATION_MAX_DISPLAY_DATA; n++)//比较通道号与数据库内是否重复
        {
            QString channel;
            
            if (!m_list[n].display)
            {
                if (m_list[n].strNO == "" && m_list[n].strChannel == ""
                    && m_list[n].strTx == "" && m_list[n].strRx == "")
                    continue;
                    
                channel = m_list[n].strChannel;
            }
            else if (intCount <= 2)
            {
                switch (intCount)
                {
                case 0:
                    channel = ui->channel1->text();
                    break;
                    
                case 1:
                    channel = ui->channel2->text();
                    break;
                    
                case 2:
                    channel = ui->channel3->text();
                    break;
                }
                
                intCount++;
            }
            
            if (channel == "")
            {
                continue;
            }
            else
            {
                QString idFrequencyAll = "select count(*) from Frequency where channel = ";
                idFrequencyAll.append("'") ;
                idFrequencyAll.append(channel) ;
                idFrequencyAll.append("';  ") ;
                idqueryFrequencyAll.prepare(idFrequencyAll);
                idqueryFrequencyAll.exec();
                idqueryFrequencyAll.next();
                
                if (idqueryFrequencyAll.value(0).toBool())
                {
                    hasOldRecord = true;
                    break;
                }
            }
        }
        
        if (hasOldRecord)
        {
            MessageBox mgb;
            mgb.SetMessage(tr("Message"), tr("Channel already exists!"), 0);
            mgb.exec() ;
            return false;
        }
        
        bool hasTransaction = database->transaction();
        QUuid idStation = QUuid::createUuid();
        QString strStationId = idStation.toString();
        paraMap.insert("UUID", strStationId);
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
            "insert into Station(uuid, name,CallSign,Country,callcode,CreateDateTime,UpdateDateTime) values(:uuid,:name,:CallSign,:Country,:callcode,:CreateDateTime,:UpdateDateTime)";
        QVariantMap map1;
        map1.insert("uuid", strStationId);
        map1.insert("CreateDateTime", sTime);
        map1.insert("UpdateDateTime", sTime);
        
        for (int i = 1; i < 2; i++)//保存主表信息到数据库
        {
            for (int j = 0; j < 4; j++)
            {
                QLineEdit* text = static_cast<QLineEdit*>(ui->gridLayout->itemAtPosition(i, j)->widget());
                QLineEdit* callcode = static_cast<QLineEdit*>(ui->gridLayout->itemAtPosition(1, 3)->widget());
                QString callcode1 = callcode->text();
                
                if (j == 0)
                {
                    if (text->text().length() == 0)
                    {
                        map1.insert("name", callcode1);
                    }
                    else
                    {
                        map1.insert("name", text->text());
                    }
                }
                else if (j == 1)
                {
                    map1.insert("CallSign", text->text());
                }
                else if (j == 2)
                {
                    map1.insert("Country", text->text());
                }
                else if (j == 3)
                {
                    map1.insert("callcode", text->text());
                }
            }
        }
        
        database->executeSql(sql1, map1);
        QVariantMap map2;
        map2.insert("Ower", COMMON_OWER_STATION);
        intCount = 0;
        
        for (int n = 0; n < CONTACTS_STATION_MAX_DISPLAY_DATA; n++)//保存子表信息到数据库
        {
            if (!m_list[n].display)
            {
                if (m_list[n].strNO == "" && m_list[n].strChannel == ""
                    && m_list[n].strTx == "" && m_list[n].strRx == "")
                    continue;
                    
                map2.insert("No", m_list[n].strNO);
                map2.insert("Channel", m_list[n].strChannel);
                map2.insert("Tx", m_list[n].strTx);
                map2.insert("Rx", m_list[n].strRx);
            }
            else if (intCount <= 2)
            {
                switch (intCount)
                {
                case 0:
                    map2.insert("No", ui->no->text());
                    map2.insert("Channel", ui->channel1->text());
                    map2.insert("Tx", ui->widget->getData());
                    map2.insert("Rx", ui->widget_2->getData());
                    break;
                    
                case 1:
                    map2.insert("No", ui->no2->text());
                    map2.insert("Channel", ui->channel2->text());
                    map2.insert("Tx", ui->widget_3->getData());
                    map2.insert("Rx", ui->widget_4->getData());
                    break;
                    
                case 2:
                    map2.insert("No", ui->no3->text());
                    map2.insert("Channel", ui->channel3->text());
                    map2.insert("Tx", ui->widget_5->getData());
                    map2.insert("Rx", ui->widget_6->getData());
                    break;
                    
                default :
                    break;
                }
                
                intCount++;
            }
            
            if ((map2["No"] == "")  && (map2["Channel"] == "") && (map2["Tx"] == "")  && (map2["Rx"] == ""))
            {
                continue;
            }
            else
            {
                QUuid idFrequency = QUuid::createUuid();
                QString strFrequency = idFrequency.toString();
                QString sql2 = "insert into Frequency (UUID,FKey,Ower,No,Channel,Tx,Rx)values(:UUID,:FKey,:Ower,:No,:Channel,:Tx,:Rx)";
                map2.insert("UUID", strFrequency);
                map2.insert("FKey", strStationId);
                database->executeSql(sql2, map2);
            }
        }
        
        if (hasTransaction)
        {
            database->commit();
        }
        else
        {
            database->rollback();
        }
    }
    
    emit afterPageSignal("contacts_station_edit_view", "contactsStaViewWidget", paraMap);
    return true;
}
/****************************************************************************
**
** 函数名称：StationEditView::frontPageSlot
** 功能概述: 打开页面时更新页面数据
** 参数说明： thisID：起始页面， fowordID：目标页面， paraMap：传递参数
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void  StationEditView::frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap)
{
    if (fowordID != "contacts_station_edit_view") {return;}
    
    Logging::get()->info("StationEditView::frontPageSlot");
    ui->individualTBnt->setIcon(QIcon(":/images/images/individual_gray.png"));
    ui->homeTBnt->setIcon(QIcon(":/images/home_normal"));
    m_stationMap = paraMap;
    m_editmode = false;
    ui->widget->editDataClean();
    ui->widget_2->editDataClean();
    ui->widget_3->editDataClean();
    ui->widget_4->editDataClean();
    ui->widget_5->editDataClean();
    ui->widget_6->editDataClean();
    
    if (m_stationMap.isEmpty()) {return;}
    
    m_strModle  =  m_stationMap[CONTACTS_STATION_MODLE_NAME];
    
    for (int n = 3; n < CONTACTS_STATION_MAX_DISPLAY_DATA; n++)
    {
        m_list[n].display = false;
        m_list[n].clear();
    }
    
    m_list[0].clear();
    m_list[1].clear();
    m_list[2].clear();
    ui->name->clear();
    ui->callsign->clear();
    ui->callcode->clear();
    ui->country->clear();
    ui->no->clear();
    ui->no2->clear();
    ui->no3->clear();
    ui->channel1->clear();
    ui->channel2->clear();
    ui->channel3->clear();;
    m_list[0].display = m_list[1].display = m_list[2].display = true;
    
    if (m_strModle == CONTACTS_STATION_MODLE_EDIT)
    {
        ui->tiltewidget->setText("EDIT STATION");
        QString strUUID = m_stationMap["UUID"];
        Database* database = new Database();
        database->openConnection();
        QSqlQuery queryStation = database->getQuery();
        bool hasTransaction = database->transaction();
        QString station = "select  name,CallSign,Country,CallCode  from station  where uuid=";
        station.append("'") ;
        station.append(strUUID);
        station.append("';  ") ;
        queryStation.prepare(station);
        queryStation.exec();
        
        while (queryStation.next())
        {
            QString name1 = queryStation.value(0).toString();
            QString CallSign1 = queryStation.value(1).toString();
            QString Country1 = queryStation.value(2).toString();
            QString CallCode1 = queryStation.value(3).toString();
            ui->name->setText(name1);
            ui->callsign->setText(CallSign1);
            ui->country->setText(Country1);
            ui->callcode->setText(CallCode1);
        }
        
        QSqlQuery queryFrequency = database->getQuery();
        QString Frequency = "select UUID,FKey,Ower,No,Channel,Tx,Rx  from Frequency  where FKey= ";
        Frequency.append("'");
        Frequency.append(strUUID);
        Frequency.append("';");
        queryFrequency.prepare(Frequency);
        queryFrequency.exec();
        int intCount = 0;
        
        while (queryFrequency.next())
        {
            m_list[intCount].strNO = queryFrequency.value(3).toString();
            m_list[intCount].strChannel = queryFrequency.value(4).toString();
            m_list[intCount].strTx = queryFrequency.value(5).toString();
            m_list[intCount].strRx = queryFrequency.value(6).toString();
            intCount++;
        }
        
        if (intCount >= 1)
        {
            ui->no->setText(m_list[0].strNO);
            ui->channel1->setText(m_list[0].strChannel);
            ui->widget->setData(m_list[0].strTx);
            ui->widget_2->setData(m_list[0].strRx);
        }
        
        if (intCount >= 2)
        {
            ui->no2->setText(m_list[1].strNO);
            ui->channel2->setText(m_list[1].strChannel);
            ui->widget_3->setData(m_list[1].strTx);
            ui->widget_4->setData(m_list[1].strRx);
        }
        
        if (intCount >= 3)
        {
            ui->no3->setText(m_list[2].strNO);
            ui->channel3->setText(m_list[2].strChannel);
            ui->widget_5->setData(m_list[2].strTx);
            ui->widget_6->setData(m_list[2].strRx);
        }
        
        if (hasTransaction)
        {
            database->commit();
        }
        else
        {
            database->rollback();
        }
    }
    else
    {
        ui->tiltewidget->setText("NEW STATION");
        
        for (int n = 3; n < CONTACTS_STATION_MAX_DISPLAY_DATA; n++)
        {
            m_list[n].clear();
        }
    }
    
    ui->name->setFocus();
}
/****************************************************************************
**
** 函数名称：StationEditView::cancelButtonClicked
** 功能概述: 返回到站台联系人界面
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void  StationEditView::cancelButtonClicked()
{
    Logging::get()->info("StationEditView::cancelButtonClicked");
    QMap <QString, QString>paraMap;
    QString strModle  =  QString("Cancel");
    paraMap.insert(CONTACTS_STATION_MODLE_NAME, strModle);
    emit afterPageSignal("contacts_station_edit_view", "contactsStaViewWidget", paraMap);
    ui->name->clear();
    ui->callsign->clear();
    ui->callcode->clear();
    ui->country->clear();
    ui->no->clear();
    ui->no2->clear();
    ui->no3->clear();
    ui->channel1->clear();
    ui->channel2->clear();
    ui->channel3->clear();;
}
/****************************************************************************
**
** 函数名称：StationEditView::arrowDownButtonClicked
** 功能概述: 下拉频率数据
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void  StationEditView::arrowDownButtonClicked()
{
    Logging::get()->info("StationEditView::arrowDownButtonClicked");
    
    if (ui->no3->text() == NULL && ui->channel3->text() == NULL && ui->widget_5->getData() == NULL
        && ui->widget_6->getData() == NULL)
    {
        if (m_list[CONTACTS_STATION_MAX_DISPLAY_DATA - 1].display || m_strModle != CONTACTS_STATION_MODLE_EDIT)
        {
            MessageBox  msg;
            msg.SetMessage(tr("Warning"), tr("No data to display"), 0);
            msg.exec() ;
            return;
        }
        else
        {
            int n = 0;
            bool bDisplay = false;
            
            while (n < CONTACTS_STATION_MAX_DISPLAY_DATA)
            {
                if (m_list[n].display)
                {
                    bDisplay = true;
                }
                else if (bDisplay)
                {
                    if (m_list[n].strChannel != "" || m_list[n].strNO != "" || m_list[n].strRx != "" || m_list[n].strTx != "")
                        break;
                }
                
                if (n == CONTACTS_STATION_MAX_DISPLAY_DATA - 1)
                {
                    MessageBox  msg;
                    msg.SetMessage(tr("Warning"), tr("No data to display"), 0);
                    msg.exec() ;
                    return;
                }
                
                n++;
            }
        }
    }
    
    for (int n = 0 ; n < CONTACTS_STATION_MAX_DISPLAY_DATA - 3; n++)
    {
        if (m_list[n].display)
        {
            m_list[n].display = false;
            m_list[n].strNO =  ui->no->text();
            m_list[n].strChannel = ui->channel1->text();
            m_list[n].strTx = ui->widget->getData();
            m_list[n].strRx = ui->widget_2->getData();
            ui->no->setText(ui->no2->text());
            ui->channel1->setText(ui->channel2->text());
            ui->widget->setData(ui->widget_3->getData());
            ui->widget_2->setData(ui->widget_4->getData());
            ui->no2->setText(ui->no3->text());
            ui->channel2->setText(ui->channel3->text());
            ui->widget_3->setData(ui->widget_5->getData());
            ui->widget_4->setData(ui->widget_6->getData());
            ui->no3->setText(m_list[n + 3].strNO);
            ui->channel3->setText(m_list[n + 3].strChannel);
            ui->widget_5->setData(m_list[n + 3].strTx);
            ui->widget_6->setData(m_list[n + 3].strRx);
            m_list[n + 3].display = true;
            break;
        }
    }
}
/****************************************************************************
**
** 函数名称：StationEditView::arrowUpButtonClicked
** 功能概述: 上拉频率数据
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void  StationEditView::arrowUpButtonClicked()
{
    Logging::get()->info("StationEditView::arrowUpButtonClicked");
    
    if (m_list[0].display)
    {
        return;
    }
    
    for (int n = 1; n < CONTACTS_STATION_MAX_DISPLAY_DATA - 2; n++)
    {
        if (m_list[n].display)
        {
            m_list[n + 2].strNO =  ui->no3->text();
            m_list[n + 2].strChannel = ui->channel3->text();
            m_list[n + 2].strTx = ui->widget_5->getData();
            m_list[n + 2].strRx = ui->widget_6->getData();
            m_list[n + 2].display = false;
            ui->no3->setText(ui->no2->text());
            ui->channel3->setText(ui->channel2->text());
            ui->widget_5->setData(ui->widget_3->getData());
            ui->widget_6->setData(ui->widget_4->getData());
            ui->no2->setText(ui->no->text());
            ui->channel2->setText(ui->channel1->text());
            ui->widget_3->setData(ui->widget->getData());
            ui->widget_4->setData(ui->widget_2->getData());
            m_list[n - 1].display = true;
            ui->no->setText(m_list[n - 1].strNO);
            ui->channel1->setText(m_list[n - 1].strChannel);
            ui->widget->setData(m_list[n - 1].strTx);
            ui->widget_2->setData(m_list[n - 1].strRx);
            break;
        }
    }
}
/****************************************************************************
**
** 函数名称：StationEditView::homeClickedSlot
** 功能概述: 返回主菜单
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void StationEditView:: homeClickedSlot()
{
    Logging::get()->info("StationEditView::homeClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(CONTACTS_STATION_EDIT_NAME, HOME_VIEW_NAME, paraMap);
}
/****************************************************************************
**
** 函数名称：StationEditView::individualClickedSlot
** 功能概述: 打开个人联系表界面
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void StationEditView:: individualClickedSlot()
{
    Logging::get()->info("StationEditView::individualClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(CONTACTS_STATION_EDIT_NAME, CONTACTS_INDIVIDUAL_VIEW, paraMap);
}
/****************************************************************************
**
** 函数名称：StationEditView::stationClickedSlot
** 功能概述: 打开站台联系表界面
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void StationEditView:: stationClickedSlot()
{
    Logging::get()->info("StationEditView::stationClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(CONTACTS_STATION_EDIT_NAME, CONTACTS_STATION_VIEW_NAME, paraMap);
}
/****************************************************************************
**
** 函数名称：StationEditView::eventFilter
** 功能概述: 事件监听函数，响应用户键盘操作。
** 参数说明：watched：发送方， event：事件数据
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool StationEditView::eventFilter(QObject* watched, QEvent* event)
{
    Logging::get()->info("StationEditView::eventFilter");

    QStringList group1 ;
    group1 << "name" << "callsign" << "country" << "callcode";
    QStringList group2 ;
    group2 <<"no" << "channel1" << "widget" << "widget_2" <<
           "no2" << "channel2" << "widget_3" << "widget_4" <<
           "no3" << "channel3" << "widget_5" << "widget_6" ;
    QStringList group3 ;
    group3 << "arrowUpButton" << "arrowDownButton";
    QStringList group4 ;
    group4 << "okBtn" << "cancelBtn";
    QStringList group5;
    group5 << "homeTBnt" << "individualTBnt";
    QList<QStringList> names;
    names  << group1 << group2 << group3 << group4<< group5;
    QStringList widgetList;
    widgetList << "widget" << "widget_2" << "widget_3" << "widget_4"
               << "widget_5" << "widget_6";
    QKeyEvent* key_event = static_cast<QKeyEvent*>(event);
    int a =   key_event->key();
    
    if (m_editmode)// 编辑框可编辑
    {
        if (QEvent::KeyPress == event->type())// 按下时键屏蔽
        {
            return true;
        }
        else if (QEvent::KeyRelease  == event->type())// 弹起时键屏蔽
        {
            return true;
        }
        // 默认键值51 响应一次
        //  按钮响应Enter 事件  编辑框不可编辑
        if (a == Qt::Key_Enter || a == Qt::Key_Return)
        {
            m_editmode = false;
            
            for (int i = 0; i < widgetList.length(); i++)
            {
                QWidget* widget = findChild<QWidget*>(widgetList.at(i));
                
                if (widget && widget->hasFocus())
                {
                    ContactsInput* inputwidget = static_cast<ContactsInput*>(widget);
                    inputwidget->offEditmode();
                }
            }
        }
        // 响应 ESC事件  编辑框不可编辑
        else if (a == Qt::Key_Escape)
        {
            m_editmode = false;
            
            for (int i = 0; i < widgetList.length(); i++)
            {
                QWidget* widget = findChild<QWidget*>(widgetList.at(i));
                
                if (widget && widget->hasFocus())
                {
                    ContactsInput* inputwidget = static_cast<ContactsInput*>(widget);
                    inputwidget->offEditmode(false);
                }
            }
        }
        
        return true;
    }
    
    switch (a)
    {
    case Qt::Key_Tab:
    {
        int next = 0;

        if (QEvent::KeyPress == event->type())// 按下时键屏蔽
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type())// 弹起时键屏蔽
        {
            return true;
        }

        QWidget* widget;
        int i = 0;
        // 默认键值51 响应一次
        // 按钮图片切换 focus 离开 按钮图片变暗
        for (i = 0; i < names.length(); i++)
        {
            for (int j = 0; j < names.at(i).length(); j++)
            {
                widget = findChild<QWidget*>(names.at(i).at(j));
                if (widget && widget->hasFocus())
                {
                    if (widgetList.count(names.at(i).at(j)))
                    {
                        ContactsInput* inputwidget = static_cast<ContactsInput*>(widget);
                        inputwidget->widgetCleanFocus();
                    }
                    i =(i == names.length() - 1) ? 0 : i + 1;
                    QWidget* widget2 = findChild<QWidget*>(names.at(i).at(0));
                    if (widget2)
                    {
                        widget2->setFocus();
                        return true;
                    }
                }
            }
        }
        break;
    }
    case Qt::Key_Down:
    case Qt::Key_Right:
    {
        int next = 0;
        
        if (QEvent::KeyPress == event->type())// 按下时键屏蔽
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type())// 弹起时键屏蔽
        {
            return true;
        }
        
        QWidget* widget;
        int i = 0;
        // 默认键值51 响应一次
        // 按钮图片切换 focus 离开 按钮图片变暗
        for (i = 0; i < names.length(); i++)
        {
            for (int j = 0; j < names.at(i).length(); j++)
            {
                widget = findChild<QWidget*>(names.at(i).at(j));
                if (widget && widget->hasFocus())
                {
                    if (names.at(i).at(j) == "homeTBnt")
                    {
                        QToolButton* button = static_cast<QToolButton*>(widget);
                        button->setIcon(QIcon(":/images/home_normal"));
                    }
                    else if (names.at(i).at(j) == "individualTBnt")
                    {
                        QToolButton* button = static_cast<QToolButton*>(widget);
                        button->setIcon(QIcon(":/images/images/individual_gray.png"));
                    }
                    else if (names.at(i).at(j) == "stationTBnt")
                    {
                        QToolButton* button = static_cast<QToolButton*>(widget);
                        button->setIcon(QIcon(":/images/images/station_gray.png"));
                    }
                    else if (names.at(i).at(j) == "widget_6")
                    {
                        arrowDownButtonClicked();
                        ui->no3->setFocus();
                        ui->widget_6->widgetCleanFocus();
                        return true;
                    }
                    else if (widgetList.count(names.at(i).at(j)))
                    {
                        ContactsInput* inputwidget = static_cast<ContactsInput*>(widget);
                        inputwidget->widgetCleanFocus();
                    }

                    next = (j == names.at(i).length() - 1) ? 0 : j + 1;

                    QWidget* widgetnext = findChild<QWidget*>(names.at(i).at(next));
                    // 按钮图片切换 focus 获得 按钮图片亮
                    if (widgetnext)
                    {
                        widgetnext->setFocus();

                        if (names.at(i).at(next) == "homeTBnt")
                        {
                            QToolButton* button = static_cast<QToolButton*>(widgetnext);
                            button->setIcon(QIcon(":/images/home_hover"));
                        }
                        else if (names.at(i).at(next) == "individualTBnt")
                        {
                            QToolButton* button = static_cast<QToolButton*>(widgetnext);
                            button->setIcon(QIcon(":/images/images/individual_white.png"));
                        }
                        else if (names.at(i).at(next) == "stationTBnt")
                        {
                            QToolButton* button = static_cast<QToolButton*>(widgetnext);
                            button->setIcon(QIcon(":/images/images/station_white.png"));
                        }
                        else if (widgetList.count(names.at(i).at(next)))
                        {
                            ContactsInput* inputwidget = static_cast<ContactsInput*>(widgetnext);
                            inputwidget->widgetSetFocus();
                        }
                    }

                    return true;
                }

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
        // 默认键值51 响应一次
        int prev = 0;
        bool inTableView = false;
        // 按钮图片切换 focus 离开 按钮图片变暗
        int i=0;
        for (i = 0; i < names.length(); i++)
        {
            for (int j = 0; j < names.at(i).length(); j++)
            {
                QWidget* widget = findChild<QWidget*>(names.at(i).at(j));

                if (widget && widget->hasFocus())
                {
                    if (names.at(i).at(j) == "homeTBnt")
                    {
                        QToolButton* button = static_cast<QToolButton*>(widget);
                        button->setIcon(QIcon(":/images/home_normal"));
                    }
                    else if (names.at(i).at(j) == "individualTBnt")
                    {
                        QToolButton* button = static_cast<QToolButton*>(widget);
                        button->setIcon(QIcon(":/images/images/individual_gray.png"));
                    }
                    else if (names.at(i).at(j) == "stationTBnt")
                    {
                        QToolButton* button = static_cast<QToolButton*>(widget);
                        button->setIcon(QIcon(":/images/images/station_gray.png"));
                    }
                    else if (widgetList.count(names.at(i).at(j)))
                    {
                        ContactsInput* inputwidget = static_cast<ContactsInput*>(widget);
                        inputwidget->widgetCleanFocus();
                    }
                    else if (names.at(i).at(j) == "no")
                    {
                        arrowUpButtonClicked();
                        return true;
                    }
                    prev = (j == 0) ? names.at(i).length() - 1 : j - 1;
                    QWidget* widgetprev = findChild<QWidget*>(names.at(i).at(prev));
                    widgetprev->setFocus();
                    // 按钮图片切换 focus 获得 按钮图片亮
                    if (widgetprev)
                    {
                        widgetprev->setFocus();

                        if (names.at(i).at(prev) == "homeTBnt")
                        {
                            QToolButton* button = static_cast<QToolButton*>(widgetprev);
                            button->setIcon(QIcon(":/images/home_hover"));
                        }
                        else if (names.at(i).at(prev) == "individualTBnt")
                        {
                            QToolButton* button = static_cast<QToolButton*>(widgetprev);
                            button->setIcon(QIcon(":/images/images/individual_white.png"));
                        }
                        else if (names.at(i).at(prev) == "stationTBnt")
                        {
                            QToolButton* button = static_cast<QToolButton*>(widgetprev);
                            button->setIcon(QIcon(":/images/images/station_white.png"));
                        }
                        else if (widgetList.count(names.at(i).at(prev)))
                        {
                            ContactsInput* inputwidget = static_cast<ContactsInput*>(widgetprev);
                            inputwidget->widgetSetFocus();
                        }
                    }

                    return true;
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
        for (int i = 0; i < names.length(); i++)
        {
            for (int j = 0; j < names.at(i).length(); j++)
            {
                QWidget* widget = findChild<QWidget*>(names.at(i).at(j));
                if (widget && widget->hasFocus())
                {
                    if (names.at(i).at(j) == "homeTBnt")
                    {
                        QWidget* widget = findChild<QWidget*>("cancelBtn");
                        Button* button = static_cast<Button*>(widget);
                        button->click();
                    }
                    else if (names.at(i).at(j) == "individualTBnt")
                    {
                        QWidget* widget = findChild<QWidget*>("individualTBnt");
                        Button* button = static_cast<Button*>(widget);
                        button->click();
                    }
                    else if (names.at(i).at(j) == "stationTBnt")
                    {
                        break;
                    }
                    else if (widgetList.count(names.at(i).at(j)))
                    {
                        ContactsInput* inputwidget = static_cast<ContactsInput*>(widget);
                        bool txOrRx;
                        int n = 0;

                        for (; n < widgetList.length(); n++)
                        {
                            if (widgetList.at(n) == names.at(i).at(j))
                                break;

                            if (n + 1 == widgetList.length())
                                n = -1;
                        }

                        if (n % 2 == 1)
                            txOrRx = false;
                        else
                            txOrRx = true;

                        inputwidget->openEditmode(txOrRx);
                        inputwidget->widgetCleanFocus();
                        m_editmode = true;
                        return true;
                    }

                    break;
                }
            }
       }
        
        break;
    }
    
    case Qt::Key_Escape:
    {
        if (QEvent::KeyPress == event->type())// 按下时键屏蔽
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type())// 弹起时键屏蔽
        {
            return true;
        }
        
        QWidget* widget = findChild<QWidget*>("cancelBtn");
        // 响应 ESC事件
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

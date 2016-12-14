#include "individualeditview.h"
#include "ui_individualeditview.h"
#include "core/database/database.h"
#include "widgets/titlewidget.h"
#include <QString>
#include <QDateTime>
#include <QUuid>
#include <QMap>
#include "widgets/messagebox.h"
#include "views/common/constants.h"
#include <QEvent>
#include <QKeyEvent>
#include "widgets/button.h"
#include "logging.h"
#include "widgets/iocmessage.h"
/****************************************************************************
**
** 函数名称：FrequencyIndividualData::clear
** 功能概述: 频率缓存清理
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void FrequencyIndividualData::clear()
{
    Logging::get()->info("FrequencyIndividualData::clear");
    strNO.clear();
    strChannel.clear();
    strTx.clear();
    strRx.clear();
}
/****************************************************************************
**
** 函数名称：IndividualEditView::IndividualEditView
** 功能概述: 初始化
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
IndividualEditView::IndividualEditView(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::IndividualEditView)
{
    Logging::get()->info("IndividualEditView::IndividualEditView");
    ui->setupUi(this);
    ui->tiltewidget->setText("NEW INDIVIDUAL");
    this->installEventFilter(this);
    m_editmode = false;
    QRegExp rx("([0-9][0-9]+9)");
    ui-> callcode->setValidator(new QRegExpValidator(rx, this));
    ui->callcode->setMaxLength(CONTACTS_CALLCODE_MAXLEN);
    ui->name->setMaxLength(CONTACTS_NAME_MAXLEN);
    ui->no->setValidator(new QRegExpValidator(rx, this));
    ui->no2->setValidator(new QRegExpValidator(rx, this));
    ui->no3->setValidator(new QRegExpValidator(rx, this));
    ui->channel1->setValidator(new QRegExpValidator(rx, this));
    ui->channel2->setValidator(new QRegExpValidator(rx, this));
    ui->channel3->setValidator(new QRegExpValidator(rx, this));
    connect(ui->okBtn, SIGNAL(clicked()), this, SLOT(saveData()));
    connect(ui->cancelBtn, SIGNAL(clicked(bool)), this, SLOT(cancelButtonClicked()));
    connect(ui->homeTBnt, SIGNAL(clicked()), this, SLOT(homeClickedSlot()));
    connect(ui->individualTBnt, SIGNAL(clicked(bool)), this, SLOT(individualClickedSlot()));
    connect(ui->stationTBnt, SIGNAL(clicked()), this, SLOT(stationClickedSlot()));
    connect(ui->arrowUpButton, SIGNAL(clicked()), this, SLOT(arrowUpButtonClicked()));
    connect(ui->arrowDownButton, SIGNAL(clicked()), this, SLOT(arrowDownButtonClicked()));
    ui->callcode->setFocus();
    FrequencyIndividualData temp;
    
    for (int n = 0; n < CONTACTS_STATION_MAX_DISPLAY_DATA; n++)
    {
        m_list.append(temp);
    }
}
/****************************************************************************
**
** 函数名称：IndividualEditView::~IndividualEditView
** 功能概述: 析构函数
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
IndividualEditView::~IndividualEditView()
{
    Logging::get()->info("IndividualEditView::~IndividualEditView");
    delete ui;
}
/****************************************************************************
**
** 函数名称：IndividualEditView::saveData
** 功能概述: 保存数据
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool  IndividualEditView::saveData()
{
    Logging::get()->info("IndividualEditView::saveData");
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
    
    if (m_strModle == CONTACTS_INDIVIDUAL_MODLE_EDIT)
    {
        QString strModle  =  QString(CONTACTS_INDIVIDUAL_MODLE_EDIT);
        paraMap.insert(CONTACTS_INDIVIDUAL_MODLE_NAME, strModle);
        Database* database = new Database();
        database->openConnection();
        QString strUUID = m_stationMap["UUID"];
        paraMap.insert(CONTACTS_STATION_UUID, strUUID);
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
        QString sql1 = "update individual set name=:name,CallCode=:CallCode,UpdateDateTime=:UpdateDateTime  where uuid=:uuid";
        QVariantMap map1;
        map1.insert("uuid", strUUID);
        map1.insert("UpdateDateTime", sTime);
        QString name1 = ui-> name->text();
        QString callcode1 = ui->callcode->text();
        
        if (name1.length() == 0)
        {
            map1.insert("name", callcode1);
        }
        else
        {
            map1.insert("name", name1);
        }
        
        map1.insert("CallCode", callcode1);
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
        
        for (int n = 0; n < CONTACTS_STATION_MAX_DISPLAY_DATA; n++)//保存缓存的数据和显示的数据
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
        
        for (int n = 0; n < channelNameList.length(); n++)//比较通道号是否有重复
            for (int m = 0; m < channelNameList.length(); m++)
            {
                if (m == n || channelNameList[n] == "")
                    continue;
                    
                if (channelNameList[n] == channelNameList[m])
                {
                    MessageBox mgb;
                    mgb.move((SCREEN_SIZE_WIDTH - mgb.width()) / 2, (SCREEN_SIZE_HEIGHT - mgb.height()) / 2);
                    mgb.SetMessage(tr("Message"), tr("Channel must be unique."), 0);
                    mgb.exec() ;
                    return false;
                }
            }
            
        QSqlQuery idqueryFrequencyAll = database->getQuery();
        int intCount = 0;
        bool hasOldRecord = false;
        
        for (int n = 0; n < CONTACTS_STATION_MAX_DISPLAY_DATA; n++)//判断通道号是否与数据库内的重复
        {
            QString uuid;
            QString channel;
            bool hasData = idqueryFrequency.next();
            
            if (hasData)//存在主表数据
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
                QString idFrequencyAll = "select UUID,Fkey from Frequency where channel = ";
                idFrequencyAll.append("'") ;
                idFrequencyAll.append(channel) ;
                idFrequencyAll.append("';  ") ;
                idqueryFrequencyAll.prepare(idFrequencyAll);
                idqueryFrequencyAll.exec();
                
                if (!hasData)//没有主表数据时
                {
                    if (idqueryFrequencyAll.next())
                    {
                        hasOldRecord = true;
                        break;
                    }
                }
                else if (idqueryFrequencyAll.next() && idqueryFrequencyAll.value(0).toString() !=  uuid)//保存的主表的UUID和当前数据库已经存在的UUID不同，说明重复
                {
                    hasOldRecord = true;
                    break;
                }
            }
        }
        
        if (hasOldRecord)//通道号重复
        {
            MessageBox mgb;
            mgb.move((SCREEN_SIZE_WIDTH - mgb.width()) / 2, (SCREEN_SIZE_HEIGHT - mgb.height()) / 2);
            mgb.SetMessage(tr("Message"), tr("Channel already exists!"), 0);
            mgb.exec() ;
            return false;
        }
        
        bool hasTransaction = database->transaction();
        idqueryFrequency.seek(0);
        intCount = 0;
        QString sqlFrequency = "update Frequency set No=:No,Channel=:Channel,Tx=:Tx,Rx=:Rx  where UUID=:UUID";
        QString sqlFrequencyDel = "delete from Frequency where UUID=:UUID";
        QVariantMap mapFrequency;
        QVariantMap mapFrequencyDel;
        QString sqlFrequencyAdd =
            "insert into Frequency (UUID,FKey,Ower,No,Channel,Tx,Rx)values(:UUID,:FKey,:Ower,:No,:Channel,:Tx,:Rx)";
        bool resultFrequency = true;
        QString uuidFrequency;
        
        for (int n = 0; n < CONTACTS_STATION_MAX_DISPLAY_DATA; n++)
        {
            bool hasData = idqueryFrequency.isValid();
            
            if (hasData)//子表有记录
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
                mapFrequency.insert("Ower", "I");
            }
            
            if (!m_list[n].display)//不在显示中的数据
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
                if (hasData)//有数据，但被清空，所以删除记录
                {
                    mapFrequencyDel.insert("UUID", uuidFrequency);
                    resultFrequency = database->executeSql(sqlFrequencyDel, mapFrequencyDel);
                }
                else
                    continue;
            }
            else
            {
                if (hasData)
                    resultFrequency = database->executeSql(sqlFrequency, mapFrequency);
                else//没数据，所以新建一条
                    resultFrequency = database->executeSql(sqlFrequencyAdd, mapFrequency);
            }
            
            if (hasTransaction && resultFrequency)
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
        
        for (int n = 0; n < CONTACTS_STATION_MAX_DISPLAY_DATA; n++)
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
        
        for (int n = 0; n < channelNameList.length(); n++)//比较是否有重复
            for (int m = 0; m < channelNameList.length(); m++)
            {
                if (m == n || channelNameList[n] == "")
                    continue;
                    
                if (channelNameList[n] == channelNameList[m])
                {
                    MessageBox mgb;
                    mgb.move((SCREEN_SIZE_WIDTH - mgb.width()) / 2, (SCREEN_SIZE_HEIGHT - mgb.height()) / 2);
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
        
        for (int n = 0; n < CONTACTS_STATION_MAX_DISPLAY_DATA; n++)//保存数据
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
        
        if (hasOldRecord)//存在重复通道
        {
            MessageBox mgb;
            mgb.move((SCREEN_SIZE_WIDTH - mgb.width()) / 2, (SCREEN_SIZE_HEIGHT - mgb.height()) / 2);
            mgb.SetMessage(tr("Message"), tr("Channel already exists!"), 0);
            mgb.exec() ;
            return false;
        }
        
        bool hasTransaction = database->transaction();
        QUuid idStation = QUuid::createUuid();
        QString strStationId = idStation.toString();
        paraMap.insert(CONTACTS_STATION_UUID, strStationId);
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
            "insert into individual(uuid,name,callcode,CreateDateTime,UpdateDateTime) values(:uuid,:name,:callcode,:CreateDateTime,:UpdateDateTime)";
        QVariantMap map1;
        map1.insert("uuid", strStationId);
        map1.insert("CreateDateTime", sTime);
        map1.insert("UpdateDateTime", sTime);
        QString nametext = ui->name->text();
        QString callcode1 = ui->callcode->text();
        
        if (nametext.length() == 0)
        {
            map1.insert("name", callcode1);
        }
        else
        {
            map1.insert("name", nametext);
        }
        
        map1.insert("callcode", callcode1);
        database->executeSql(sql1, map1);
        QVariantMap map2;
        map2.insert("Ower", COMMON_OWER_INDIVIDUAL);
        intCount = 0;
        
        for (int n = 0; n < CONTACTS_STATION_MAX_DISPLAY_DATA; n++)//保存子表数据
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
                map2.insert("Ower", COMMON_OWER_INDIVIDUAL);
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
    
    emit afterPageSignal(CONTACTS_INDIVIDUAL_EDIT_NAME, CONTACTS_INDIVIDUAL_VIEW, paraMap);
    return true;
}

/****************************************************************************
**
** 函数名称：IndividualEditView::frontPageSlot
** 功能概述: 打开页面时更新页面数据
** 参数说明： thisID：起始页面， fowordID：目标页面， paraMap：传递参数
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void  IndividualEditView::frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap)
{
    if (fowordID != CONTACTS_INDIVIDUAL_EDIT_NAME) {return;}
    
    Logging::get()->info("IndividualEditView::frontPageSlot");
    ui->stationTBnt->setIcon(QIcon(":/images/images/station_gray.png"));
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
    
    m_strModle  =  m_stationMap[CONTACTS_INDIVIDUAL_MODLE_NAME];
    
    for (int n = 3; n < CONTACTS_STATION_MAX_DISPLAY_DATA; n++)
    {
        m_list[n].display = false;
        m_list[n].clear();
    }
    
    m_list[0].clear();
    m_list[1].clear();
    m_list[2].clear();
    ui->name->clear();
    ui->callcode->clear();
    ui->no->clear();
    ui->no2->clear();
    ui->no3->clear();
    ui->channel1->clear();
    ui->channel2->clear();
    ui->channel3->clear();;
    m_list[0].display = m_list[1].display = m_list[2].display = true;
    
    if (m_strModle == CONTACTS_INDIVIDUAL_MODLE_EDIT)
    {
        ui->tiltewidget->setText("EDIT INDIVIDUAL");
        QString strUUID = m_stationMap["UUID"];
        Database* database = new Database();
        database->openConnection();
        QSqlQuery queryStation = database->getQuery();
        bool hasTransaction = database->transaction();
        QString station = "select  name,CallCode  from INDIVIDUAL  where uuid=";
        station.append("'") ;
        station.append(strUUID);
        station.append("';  ") ;
        queryStation.prepare(station);
        queryStation.exec();
        
        while (queryStation.next())
        {
            QString name1 = queryStation.value(0).toString();
            QString CallCode1 = queryStation.value(1).toString();
            ui->name->setText(name1);
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
            //QString UUID = queryFrequency.value(0).toString();
            m_list[intCount].strNO = queryFrequency.value(3).toString();
            m_list[intCount].strChannel = queryFrequency.value(4).toString();
            m_list[intCount].strTx = queryFrequency.value(5).toString();
            m_list[intCount].strRx = queryFrequency.value(6).toString();
            intCount = intCount + 1;
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
        ui->tiltewidget->setText("NEW INDIVIDUAL");
        
        for (int n = 3; n < CONTACTS_STATION_MAX_DISPLAY_DATA; n++)
        {
            m_list[n].clear();
        }
    }
    
    ui->name->setFocus();
}
/****************************************************************************
**
** 函数名称：IndividualEditView::cancelButtonClicked
** 功能概述: 返回到个人联系表界面
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void  IndividualEditView::cancelButtonClicked()
{
    Logging::get()->info("IndividualEditView::cancelButtonClicked");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(CONTACTS_INDIVIDUAL_EDIT_NAME, CONTACTS_INDIVIDUAL_VIEW, paraMap);
    ui->name->clear();
    ui->callcode->clear();
    ui->no->clear();
    ui->no2->clear();
    ui->no3->clear();
    ui->channel1->clear();
    ui->channel2->clear();
    ui->channel3->clear();;
}
/****************************************************************************
**
** 函数名称：IndividualEditView::arrowDownButtonClicked
** 功能概述: 下拉个人联系表记录
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void  IndividualEditView::arrowDownButtonClicked()
{
    Logging::get()->info("IndividualEditView::arrowDownButtonClicked");
    
    if (ui->no3->text() == NULL && ui->channel3->text() == NULL && ui->widget_5->getData() == NULL
        && ui->widget_6->getData() == NULL)
    {
        if (m_list[CONTACTS_STATION_MAX_DISPLAY_DATA - 1].display || m_strModle != CONTACTS_INDIVIDUAL_MODLE_EDIT)
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
                    msg.move((SCREEN_SIZE_WIDTH - msg.width()) / 2, (SCREEN_SIZE_HEIGHT - msg.height()) / 2);
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
** 函数名称：IndividualEditView::arrowUpButtonClicked
** 功能概述: 上拉个人联系表记录
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void  IndividualEditView::arrowUpButtonClicked()
{
    Logging::get()->info("IndividualEditView::arrowUpButtonClicked");
    
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
** 函数名称：IndividualEditView::homeClickedSlot
** 功能概述: 返回主菜单
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void IndividualEditView:: homeClickedSlot()
{
    Logging::get()->info("IndividualEditView::homeClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(CONTACTS_INDIVIDUAL_EDIT_NAME, HOME_VIEW_NAME, paraMap);
}
/****************************************************************************
**
** 函数名称：IndividualEditView::stationClickedSlot
** 功能概述: 打开站台联系表界面
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void IndividualEditView:: stationClickedSlot()
{
    Logging::get()->info("IndividualEditView::stationClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(CONTACTS_INDIVIDUAL_EDIT_NAME, CONTACTS_STATION_VIEW_NAME, paraMap);
}
/****************************************************************************
**
** 函数名称：IndividualEditView::individualClickedSlot
** 功能概述: 打开个人联系表界面
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void IndividualEditView:: individualClickedSlot()
{
    Logging::get()->info("IndividualEditView::individualClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(CONTACTS_INDIVIDUAL_EDIT_NAME, CONTACTS_INDIVIDUAL_VIEW, paraMap);
}
/****************************************************************************
**
** 函数名称：IndividualEditView::eventFilter
** 功能概述: 事件监听函数，响应用户键盘操作
** 参数说明：watched：发送方， event：事件数据
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool IndividualEditView::eventFilter(QObject* watched, QEvent* event)
{
    Logging::get()->info("IndividualEditView::eventFilter");
    QStringList group1 ;
    group1 << "name" << "callcode";
    QStringList group2 ;
    group2 <<"no" << "channel1" << "widget" << "widget_2" <<
             "no2" << "channel2" << "widget_3" << "widget_4" <<
             "no3" << "channel3" << "widget_5" << "widget_6" ;
    QStringList group3 ;
    group3 << "arrowUpButton" << "arrowDownButton";
    QStringList group4 ;
    group4 << "okBtn" << "cancelBtn";
    QStringList group5;
    group5 << "homeTBnt" << "stationTBnt";
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
    

    if (QEvent::KeyPress == event->type())
    {
        if (a == Qt::Key_Escape)
            return true;
        else
            return QWidget::eventFilter(watched, event);
    }
    else if (QEvent::KeyRelease == event->type())
    {
        if (a == Qt::Key_Escape)
            return true;
        else
            return QWidget::eventFilter(watched, event);
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
        QWidget* widget;
        int i = 0;
        
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
        int prev = 0;
        bool inTableView = false;
        int i=0;
        // 按钮图片切换 focus 离开 按钮图片变暗
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
                    else if (names.at(i).at(j) == "no")
                    {
                        arrowUpButtonClicked();
                        return true;
                    }
                    else if (widgetList.count(names.at(i).at(j)))
                    {
                        ContactsInput* inputwidget = static_cast<ContactsInput*>(widget);
                        inputwidget->widgetCleanFocus();
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

        for (int i = 0; i < names.length(); i++)
        {
            for (int j = 0; j < names.at(i).length(); j++)
            {
                QWidget* widget = findChild<QWidget*>(names.at(i).at(j));

                if (widget && widget->hasFocus())
                {
                    if (names.at(i).at(j)== "homeTBnt")
                    {
                        QWidget* widget = findChild<QWidget*>("cancelBtn");
                        Button* button = static_cast<Button*>(widget);
                        button->click();
                    }
                    else if (names.at(i).at(j) == "individualTBnt")
                    {
                    }
                    else if (names.at(i).at(j) == "stationTBnt")
                    {
                        QWidget* widget = findChild<QWidget*>("stationTBnt");
                        Button* button = static_cast<Button*>(widget);
                        button->click();
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
    
    case Qt::Key_Escape:// 响应 ESC事件
    {
        QWidget* widget = findChild<QWidget*>("cancelBtn");
        
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

#include "systemsetting.h"
#include "ui_systemsetting.h"
#include "views/common/constants.h"
#include <QListWidget>
#include <QDateTime>
#include <QEvent>
#include <QKeyEvent>
#include "widgets/button.h"
#include "core/utils/sqlitehelper.h"
#include <QSqlRecord>
#include <time.h>
#include <QDebug>
#include "logging.h"
#include "transit.h"
/****************************************************************************
**
** 函数名称：SystemSetting::SystemSetting
** 功能概述: 初始化
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
SystemSetting::SystemSetting(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::SystemSetting)
{
    Logging::get()->info("SystemSetting::SystemSetting");
    ui->setupUi(this);
    ui->tiltewidget->setText(Constants::SYSTEM_SETTING_TITLE);
    ui->horizontalScrollBar->setValue(80);
    QString sys = "echo ";
    sys += QString::number(50);
    sys += " > /sys/class/backlight/LCD_backlight/brightness ";
    ui->horizontalScrollBar_2->setValue(50);
    QString sys2 = "amixer cset numid=1 ";
    sys2 += QString::number(50);
    system(sys2.toStdString().c_str());
    m_bInTimeEdit = false;
    m_model = new ContactsModel(this, SQLiteHelper::openConnection());
    m_model->setTable(Constants::SYSTEM_SETTING_TABLE_NAME);
    m_model->select();
    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->lineEdit_6->hide();
    ui->lineEdit_7->hide();
    ui->lineEdit_8->hide();
    ui->lineEdit_9->hide();
    ui->lineEdit_10->hide();
    ui->lineEdit_11->hide();
    ui->lineEdit_12->hide();
    ui->lineEdit_13->hide();
    ui->lineEdit_14->hide();
    ui->lineEdit_15->hide();
    ui->lineEdit_16->hide();
    ui->lineEdit_17->hide();
    ui->lineEdit_18->hide();
    ui->lineEdit_19->hide();
    ui->lineEdit_20->hide();
    ui->lineEdit->setMaxLength(1);
    ui->lineEdit_2->setMaxLength(1);
    ui->lineEdit_3->setMaxLength(1);
    ui->lineEdit_4->setMaxLength(1);
    ui->lineEdit_6->setMaxLength(1);
    ui->lineEdit_7->setMaxLength(1);
    ui->lineEdit_8->setMaxLength(1);
    ui->lineEdit_9->setMaxLength(1);
    ui->lineEdit_10->setMaxLength(1);
    ui->lineEdit_11->setMaxLength(1);
    ui->lineEdit_12->setMaxLength(1);
    ui->lineEdit_13->setMaxLength(1);
    ui->lineEdit_14->setMaxLength(1);
    ui->lineEdit_15->setMaxLength(1);
    ui->lineEdit_16->setMaxLength(1);
    ui->lineEdit_17->setMaxLength(1);
    ui->lineEdit_18->setMaxLength(1);
    ui->lineEdit_19->setMaxLength(1);
    QRegExp rx1("[0-2]");
    QRegExp rx2("[0-9]+3");
    QRegExp rx3("[0-3]");
    QRegExp rx4("[0-5]");
    QRegExp rx5("[0-4][0-9]||[5][0]");
    ui->lineEdit_5->setMaxLength(2);
    ui->lineEdit_5->setValidator(new QRegExpValidator(rx5, this));
    ui->lineEdit->setValidator(new QRegExpValidator(rx1, this));
    ui->lineEdit_2->setValidator(new QRegExpValidator(rx2, this));
    ui->lineEdit_3->setValidator(new QRegExpValidator(rx2, this));
    ui->lineEdit_4->setValidator(new QRegExpValidator(rx2, this));
    ui->lineEdit_7->setValidator(new QRegExpValidator(rx1, this));
    ui->lineEdit_8->setValidator(new QRegExpValidator(rx2, this));
    ui->lineEdit_10->setValidator(new QRegExpValidator(rx3, this));
    ui->lineEdit_11->setValidator(new QRegExpValidator(rx2, this));
    ui->lineEdit_12->setValidator(new QRegExpValidator(rx1, this));
    ui->lineEdit_13->setValidator(new QRegExpValidator(rx2, this));
    ui->lineEdit_15->setValidator(new QRegExpValidator(rx4, this));
    ui->lineEdit_16->setValidator(new QRegExpValidator(rx2, this));
    ui->lineEdit_18->setValidator(new QRegExpValidator(rx4, this));
    ui->lineEdit_19->setValidator(new QRegExpValidator(rx2, this));
    QStringList langQStringList;
    langQStringList << "English" << "Chinese" ;
    ui->comboBox->addItems(langQStringList);
    QStringList printQStringList;
    printQStringList << "Real Time Printing" << "Print" ;
    ui->comboBox_2->addItems(printQStringList);
    this->installEventFilter(this);
    QFont font("Ubuntu", 18, QFont::Bold);
    QIcon dateTime;
    dateTime.addPixmap(QPixmap(":/images/System_dateTime_SelNo"), QIcon::Normal);
    dateTime.addPixmap(QPixmap(":/images/System_dateTime_SelYes"), QIcon::Selected);
    ui->listWidget->addItem(new QListWidgetItem(dateTime, tr("  Date&Time")));
    ui->listWidget->item(0)->setFont(font);
    ui->listWidget->setCurrentRow(0);
    QIcon language;
    language.addPixmap(QPixmap(":/images/System_Lang_SelNo"), QIcon::Normal);
    language.addPixmap(QPixmap(":/images/System_Lang_SelYes"), QIcon::Selected);
    ui->listWidget_2->addItem(new QListWidgetItem(language, tr("  Language")));
    ui->listWidget_2->item(0)->setFont(font);
    QIcon brightness;
    brightness.addPixmap(QPixmap(":/images/System_Brightness_SelNo"), QIcon::Normal);
    brightness.addPixmap(QPixmap(":/images/System_Brightness_SelYes"), QIcon::Selected);
    ui->listWidget_3->addItem(new QListWidgetItem(brightness, tr("  Brightness")));
    ui->listWidget_3->item(0)->setFont(font);
    QIcon volume;
    volume.addPixmap(QPixmap(":/images/System_Volume_SelNo"), QIcon::Normal);
    volume.addPixmap(QPixmap(":/images/System_Volume_SelYes"), QIcon::Selected);
    ui->listWidget_4->addItem(new QListWidgetItem(volume, tr("  Volume")));
    ui->listWidget_4->item(0)->setFont(font);
    QIcon slaveDelay;
    slaveDelay.addPixmap(QPixmap(":/images/System_Delay_SelNo"), QIcon::Normal);
    slaveDelay.addPixmap(QPixmap(":/images/System_Delay_SelYes"), QIcon::Selected);
    ui->listWidget_5->addItem(new QListWidgetItem(slaveDelay, tr("  Slave Delay")));
    ui->listWidget_5->item(0)->setFont(font);
    QIcon Identification;
    Identification.addPixmap(QPixmap(":/images/System_Identification_SelNo"), QIcon::Normal);
    Identification.addPixmap(QPixmap(":/images/System_Identification_SelYes"), QIcon::Selected);
    ui->listWidget_6->addItem(new QListWidgetItem(Identification, tr("  Identification")));
    ui->listWidget_6->item(0)->setFont(font);
    QIcon print;
    print.addPixmap(QPixmap(":/images/System_Print_SelNo"), QIcon::Normal);
    print.addPixmap(QPixmap(":/images/System_Print_SelYes"), QIcon::Selected);
    ui->listWidget_7->addItem(new QListWidgetItem(print, tr("  Print")));
    ui->listWidget_7->item(0)->setFont(font);
    QStringList IdentificationInfo;
    IdentificationInfo << SYSTEM_SETTING_DIGITCALLCODELABEL
                       << SYSTEM_SETTING_DIGITMMSICODELABEL
                       << SYSTEM_SETTING_ANSWERBACKCODELABEL;
    ui->label->setText(IdentificationInfo.at(0));
    ui->label_2->setText(IdentificationInfo.at(1));
    ui->label_3->setText(IdentificationInfo.at(2));
    connect(ui->homeTBnt, SIGNAL(clicked()), this, SLOT(homeClickedSlot()));
    connect(ui->settingTBtn, SIGNAL(clicked()), this, SLOT(settingClickedSlot()));
    connect(ui->testTBtn, SIGNAL(clicked()), this, SLOT(testClickedSlot()));
    connect(ui->aboutTBtn, SIGNAL(clicked()), this, SLOT(aboutClickedSlot()));
    QSqlRecord  sqlRecord = m_model->record(0);
    QString digitcallcode = sqlRecord.value(SYSTEM_SETTING_DIGITCALLCODE).toString();
    QString mmsicode = sqlRecord.value(SYSTEM_SETTING_MMSICODE).toString();
    QString answerbackcode = sqlRecord.value(SYSTEM_SETTING_ANSWERBACKCODE).toString();
    QString slavedelay = sqlRecord.value(SYSTEM_SETTING_SLAVEDELAY).toString();
    int languageNum = sqlRecord.value(SYSTEM_SETTING_LANGUAGE).toInt();
    QString printNum = sqlRecord.value(SYSTEM_SETTING_REALTIMEPRINT).toString();
    
    if (printNum != SYSTEM_SETTING_PRINTMODE_REAL && printNum != SYSTEM_SETTING_PRINTMODE_PRINT)
        printNum = SYSTEM_SETTING_PRINTMODE_REAL;
        
    if (slavedelay == "")
        slavedelay = "10";
        
    ui->lineEdit_5->setText(slavedelay);
    ui->label_4->setText(digitcallcode);
    ui->label_5->setText(mmsicode);
    ui->label_6->setText(answerbackcode);
    ui->dateTimeButton->setFocus();
    ui->comboBox->setCurrentIndex(languageNum);
    ui->comboBox_2->setCurrentIndex(printNum.toInt());
    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(listwidgetClickedSlot(QListWidgetItem*)));
    connect(ui->listWidget_2, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(listwidget2ClickedSlot(QListWidgetItem*)));
    connect(ui->listWidget_3, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(listwidget3ClickedSlot(QListWidgetItem*)));
    connect(ui->listWidget_4, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(listwidget4ClickedSlot(QListWidgetItem*)));
    connect(ui->listWidget_5, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(listwidget5ClickedSlot(QListWidgetItem*)));
    connect(ui->listWidget_6, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(listwidget6ClickedSlot(QListWidgetItem*)));
    connect(ui->listWidget_7, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(listwidget7ClickedSlot(QListWidgetItem*)));
    connect(ui->dateTimeButton, SIGNAL(clicked()), this, SLOT(dateTimeButtonClick()));
}
/****************************************************************************
**
** 函数名称：SystemSetting::dateTimeButtonClick
** 功能概述: 点击事件光标切换
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SystemSetting::dateTimeButtonClick()
{
    ui->homeTBnt->setIcon(QIcon(":/images/home_normal"));
    ui->testTBtn->setIcon(QIcon(":/images/System_TestBtn_SelNo"));
    ui->aboutTBtn->setIcon(QIcon(":/images/System_AboutBtn_SelNo"));
    ui->listWidget->setCurrentRow(0);
    
    if (ui->listWidget_2->currentRow() != -1)//关闭其他高亮的名称
    {
        ui->listWidget_2->setCurrentRow(-1);
    }
    
    if (ui->listWidget_3->currentRow() != -1)//关闭其他高亮的名称
    {
        ui->listWidget_3->setCurrentRow(-1);
    }
    
    if (ui->listWidget_4->currentRow() != -1)//关闭其他高亮的名称
    {
        ui->listWidget_4->setCurrentRow(-1);
    }
    
    if (ui->listWidget_5->currentRow() != -1)//关闭其他高亮的名称 未保存时还原数据
    {
        ui->listWidget_5->setCurrentRow(-1);
        QSqlRecord  sqlRecord = m_model->record(0);
        QString slavedelay = sqlRecord.value(SYSTEM_SETTING_SLAVEDELAY).toString();
        ui->lineEdit_5->setText(slavedelay);
        ui->lineEdit_5->setReadOnly(true);
    }
    
    if (ui->listWidget_6->currentRow() != -1)//关闭其他高亮的名称
    {
        ui->listWidget_6->setCurrentRow(-1);
        QString styleStr = "QLabel { font: 15pt 'Ubuntu';color: rgb(105, 115, 119); }";
        ui->label_4->setStyleSheet(styleStr);
        ui->label_5->setStyleSheet(styleStr);
        ui->label_6->setStyleSheet(styleStr);
        QStringList IdentificationInfo1;
        IdentificationInfo1 << SYSTEM_SETTING_DIGITCALLCODELABEL
                            <<SYSTEM_SETTING_DIGITMMSICODELABEL
                            <<SYSTEM_SETTING_ANSWERBACKCODELABEL;
        ui->label->setText(IdentificationInfo1.at(0));
        ui->label_2->setText(IdentificationInfo1.at(1));
        ui->label_3->setText(IdentificationInfo1.at(2));
    }
    
    if (ui->listWidget_7->currentRow() != -1)//关闭其他高亮的名称
    {
        ui->listWidget_7->setCurrentRow(-1);
    }
}
/****************************************************************************
**
** 函数名称：SystemSetting::listwidgetClickedSlot
** 功能概述: 点击事件光标切换
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SystemSetting::listwidgetClickedSlot(QListWidgetItem* item)
{
    ui->homeTBnt->setIcon(QIcon(":/images/home_normal"));
    ui->testTBtn->setIcon(QIcon(":/images/System_TestBtn_SelNo"));
    ui->aboutTBtn->setIcon(QIcon(":/images/System_AboutBtn_SelNo"));
    
    if (ui->listWidget_2->currentRow() != -1)//关闭其他高亮的名称
    {
        ui->listWidget_2->setCurrentRow(-1);
    }
    
    if (ui->listWidget_3->currentRow() != -1)//关闭其他高亮的名称
    {
        ui->listWidget_3->setCurrentRow(-1);
    }
    
    if (ui->listWidget_4->currentRow() != -1)//关闭其他高亮的名称
    {
        ui->listWidget_4->setCurrentRow(-1);
    }
    
    if (ui->listWidget_5->currentRow() != -1)//关闭其他高亮的名称 未保存时还原数据
    {
        ui->listWidget_5->setCurrentRow(-1);
        QSqlRecord  sqlRecord = m_model->record(0);
        QString slavedelay = sqlRecord.value(SYSTEM_SETTING_SLAVEDELAY).toString();
        ui->lineEdit_5->setText(slavedelay);
        ui->lineEdit_5->setReadOnly(true);
    }
    
    if (ui->listWidget_6->currentRow() != -1)//关闭其他高亮的名称 
    {
        ui->listWidget_6->setCurrentRow(-1);
        QString styleStr = "QLabel { font: 15pt 'Ubuntu';color: rgb(105, 115, 119); }";
        ui->label_4->setStyleSheet(styleStr);
        ui->label_5->setStyleSheet(styleStr);
        ui->label_6->setStyleSheet(styleStr);
        QStringList IdentificationInfo1;
        IdentificationInfo1 <<SYSTEM_SETTING_DIGITCALLCODELABEL
                            << SYSTEM_SETTING_DIGITMMSICODELABEL
                            << SYSTEM_SETTING_ANSWERBACKCODELABEL;
        ui->label->setText(IdentificationInfo1.at(0));
        ui->label_2->setText(IdentificationInfo1.at(1));
        ui->label_3->setText(IdentificationInfo1.at(2));
    }
    
    if (ui->listWidget_7->currentRow() != -1)//关闭其他高亮的名称 
    {
        ui->listWidget_7->setCurrentRow(-1);
    }
    
    ui->dateTimeButton->setFocus();
}
/****************************************************************************
**
** 函数名称：SystemSetting::listwidget2ClickedSlot
** 功能概述: 点击事件光标切换
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SystemSetting::listwidget2ClickedSlot(QListWidgetItem* item)
{
    if (m_bInTimeEdit)	//如果在时间编辑模式，还原数据	
    {
        ui->dateTimeButton->setText(m_timeStr);
    }
    
    ui->homeTBnt->setIcon(QIcon(":/images/home_normal"));
    ui->testTBtn->setIcon(QIcon(":/images/System_TestBtn_SelNo"));
    ui->aboutTBtn->setIcon(QIcon(":/images/System_AboutBtn_SelNo"));
    
    if (ui->listWidget->currentRow() != -1)//关闭其他高亮的名称 
    {
        ui->listWidget->setCurrentRow(-1);
        
        if (m_bInTimeEdit)//如果在时间编辑模式，关闭模式样式
        {
            m_bInTimeEdit = false;
            ui->lineEdit->hide();
            ui->lineEdit_2->hide();
            ui->lineEdit_3->hide();
            ui->lineEdit_4->hide();
            ui->lineEdit_6->hide();
            ui->lineEdit_7->hide();
            ui->lineEdit_8->hide();
            ui->lineEdit_9->hide();
            ui->lineEdit_10->hide();
            ui->lineEdit_11->hide();
            ui->lineEdit_12->hide();
            ui->lineEdit_13->hide();
            ui->lineEdit_14->hide();
            ui->lineEdit_15->hide();
            ui->lineEdit_16->hide();
            ui->lineEdit_17->hide();
            ui->lineEdit_18->hide();
            ui->lineEdit_19->hide();
            ui->lineEdit_20->hide();
        }
    }
    
    if (ui->listWidget_3->currentRow() != -1)//关闭其他高亮的名称 
    {
        ui->listWidget_3->setCurrentRow(-1);
    }
    
    if (ui->listWidget_4->currentRow() != -1)//关闭其他高亮的名称 
    {
        ui->listWidget_4->setCurrentRow(-1);
    }
    
    if (ui->listWidget_5->currentRow() != -1)//关闭其他高亮的名称 未保存时还原数据
    {
        ui->listWidget_5->setCurrentRow(-1);
        QSqlRecord  sqlRecord = m_model->record(0);
        QString slavedelay = sqlRecord.value(SYSTEM_SETTING_SLAVEDELAY).toString();
        ui->lineEdit_5->setText(slavedelay);
        ui->lineEdit_5->setReadOnly(true);
    }
    
    if (ui->listWidget_6->currentRow() != -1)//关闭其他高亮的名称 
    {
        ui->listWidget_6->setCurrentRow(-1);
        QString styleStr = "QLabel { font: 15pt 'Ubuntu';color: rgb(105, 115, 119); }";
        ui->label_4->setStyleSheet(styleStr);
        ui->label_5->setStyleSheet(styleStr);
        ui->label_6->setStyleSheet(styleStr);
        QStringList IdentificationInfo1;
        IdentificationInfo1 << SYSTEM_SETTING_DIGITCALLCODELABEL
                            << SYSTEM_SETTING_DIGITMMSICODELABEL
                            << SYSTEM_SETTING_ANSWERBACKCODELABEL;
        ui->label->setText(IdentificationInfo1.at(0));
        ui->label_2->setText(IdentificationInfo1.at(1));
        ui->label_3->setText(IdentificationInfo1.at(2));
    }
    
    if (ui->listWidget_7->currentRow() != -1)//关闭其他高亮的名称 
    {
        ui->listWidget_7->setCurrentRow(-1);
    }
    
    ui->languageFocus->setFocus();
}
/****************************************************************************
**
** 函数名称：SystemSetting::listwidget3ClickedSlot
** 功能概述: 点击事件光标切换
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SystemSetting::listwidget3ClickedSlot(QListWidgetItem* item)
{
    if (m_bInTimeEdit)//如果在时间编辑模式，还原数据	
    {
        ui->dateTimeButton->setText(m_timeStr);
    }
    
    ui->homeTBnt->setIcon(QIcon(":/images/home_normal"));
    ui->testTBtn->setIcon(QIcon(":/images/System_TestBtn_SelNo"));
    ui->aboutTBtn->setIcon(QIcon(":/images/System_AboutBtn_SelNo"));
    
    if (ui->listWidget->currentRow() != -1)//关闭其他高亮的名称 
    {
        ui->listWidget->setCurrentRow(-1);
        
        if (m_bInTimeEdit)//如果在时间编辑模式，关闭模式样式
        {
            m_bInTimeEdit = false;
            ui->lineEdit->hide();
            ui->lineEdit_2->hide();
            ui->lineEdit_3->hide();
            ui->lineEdit_4->hide();
            ui->lineEdit_6->hide();
            ui->lineEdit_7->hide();
            ui->lineEdit_8->hide();
            ui->lineEdit_9->hide();
            ui->lineEdit_10->hide();
            ui->lineEdit_11->hide();
            ui->lineEdit_12->hide();
            ui->lineEdit_13->hide();
            ui->lineEdit_14->hide();
            ui->lineEdit_15->hide();
            ui->lineEdit_16->hide();
            ui->lineEdit_17->hide();
            ui->lineEdit_18->hide();
            ui->lineEdit_19->hide();
            ui->lineEdit_20->hide();
        }
    }
    
    if (ui->listWidget_2->currentRow() != -1)//关闭其他高亮的名称 
    {
        ui->listWidget_2->setCurrentRow(-1);
    }
    
    if (ui->listWidget_4->currentRow() != -1)//关闭其他高亮的名称 
    {
        ui->listWidget_4->setCurrentRow(-1);
    }
    
    if (ui->listWidget_5->currentRow() != -1)//关闭其他高亮的名称 未保存时还原数据
    {
        ui->listWidget_5->setCurrentRow(-1);
        QSqlRecord  sqlRecord = m_model->record(0);
        QString slavedelay = sqlRecord.value(SYSTEM_SETTING_SLAVEDELAY).toString();
        ui->lineEdit_5->setText(slavedelay);
        ui->lineEdit_5->setReadOnly(true);
    }
    
    if (ui->listWidget_6->currentRow() != -1)//关闭其他高亮的名称 
    {
        ui->listWidget_6->setCurrentRow(-1);
        QString styleStr = "QLabel { font: 15pt 'Ubuntu';color: rgb(105, 115, 119); }";
        ui->label_4->setStyleSheet(styleStr);
        ui->label_5->setStyleSheet(styleStr);
        ui->label_6->setStyleSheet(styleStr);
        QStringList IdentificationInfo1;
        IdentificationInfo1 << SYSTEM_SETTING_DIGITCALLCODELABEL
                            << SYSTEM_SETTING_DIGITMMSICODELABEL
                            << SYSTEM_SETTING_ANSWERBACKCODELABEL;
        ui->label->setText(IdentificationInfo1.at(0));
        ui->label_2->setText(IdentificationInfo1.at(1));
        ui->label_3->setText(IdentificationInfo1.at(2));
    }
    
    if (ui->listWidget_7->currentRow() != -1)//关闭其他高亮的名称 
    {
        ui->listWidget_7->setCurrentRow(-1);
    }
    
    ui->horizontalScrollBarFocus->setFocus();
}
/****************************************************************************
**
** 函数名称：SystemSetting::listwidget4ClickedSlot
** 功能概述: 点击事件光标切换
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SystemSetting::listwidget4ClickedSlot(QListWidgetItem* item)
{
    if (m_bInTimeEdit)//如果在时间编辑模式，还原数据	
    {
        ui->dateTimeButton->setText(m_timeStr);
    }
    
    ui->homeTBnt->setIcon(QIcon(":/images/home_normal"));
    ui->testTBtn->setIcon(QIcon(":/images/System_TestBtn_SelNo"));
    ui->aboutTBtn->setIcon(QIcon(":/images/System_AboutBtn_SelNo"));
    
    if (ui->listWidget->currentRow() != -1)//关闭其他高亮的名称 
    {
        ui->listWidget->setCurrentRow(-1);
        
        if (m_bInTimeEdit)//如果在时间编辑模式，关闭模式样式
        {
            m_bInTimeEdit = false;
            ui->lineEdit->hide();
            ui->lineEdit_2->hide();
            ui->lineEdit_3->hide();
            ui->lineEdit_4->hide();
            ui->lineEdit_6->hide();
            ui->lineEdit_7->hide();
            ui->lineEdit_8->hide();
            ui->lineEdit_9->hide();
            ui->lineEdit_10->hide();
            ui->lineEdit_11->hide();
            ui->lineEdit_12->hide();
            ui->lineEdit_13->hide();
            ui->lineEdit_14->hide();
            ui->lineEdit_15->hide();
            ui->lineEdit_16->hide();
            ui->lineEdit_17->hide();
            ui->lineEdit_18->hide();
            ui->lineEdit_19->hide();
            ui->lineEdit_20->hide();
        }
    }
    
    if (ui->listWidget_2->currentRow() != -1)//关闭其他高亮的名称 
    {
        ui->listWidget_2->setCurrentRow(-1);
    }
    
    if (ui->listWidget_3->currentRow() != -1)//关闭其他高亮的名称
    {
        ui->listWidget_3->setCurrentRow(-1);
    }
    
    if (ui->listWidget_5->currentRow() != -1)//关闭其他高亮的名称 未保存时还原数据
    {
        ui->listWidget_5->setCurrentRow(-1);
        QSqlRecord  sqlRecord = m_model->record(0);
        QString slavedelay = sqlRecord.value(SYSTEM_SETTING_SLAVEDELAY).toString();
        ui->lineEdit_5->setText(slavedelay);
        ui->lineEdit_5->setReadOnly(true);
    }
    
    if (ui->listWidget_6->currentRow() != -1)//关闭其他高亮的名称 
    {
        ui->listWidget_6->setCurrentRow(-1);
        QString styleStr = "QLabel { font: 15pt 'Ubuntu';color: rgb(105, 115, 119); }";
        ui->label_4->setStyleSheet(styleStr);
        ui->label_5->setStyleSheet(styleStr);
        ui->label_6->setStyleSheet(styleStr);
        QStringList IdentificationInfo1;
        IdentificationInfo1 << SYSTEM_SETTING_DIGITCALLCODELABEL
                            << SYSTEM_SETTING_DIGITMMSICODELABEL
                            << SYSTEM_SETTING_ANSWERBACKCODELABEL;
        ui->label->setText(IdentificationInfo1.at(0));
        ui->label_2->setText(IdentificationInfo1.at(1));
        ui->label_3->setText(IdentificationInfo1.at(2));
    }
    
    if (ui->listWidget_7->currentRow() != -1)//关闭其他高亮的名称 
    {
        ui->listWidget_7->setCurrentRow(-1);
    }
    
    ui->horizontalScrollBarFocus2->setFocus();
}
/****************************************************************************
**
** 函数名称：SystemSetting::listwidget5ClickedSlot
** 功能概述: 点击事件光标切换
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SystemSetting::listwidget5ClickedSlot(QListWidgetItem* item)
{
    if (m_bInTimeEdit)//如果在时间编辑模式，还原数据	
    {
        ui->dateTimeButton->setText(m_timeStr);
    }
    
    ui->homeTBnt->setIcon(QIcon(":/images/home_normal"));
    ui->testTBtn->setIcon(QIcon(":/images/System_TestBtn_SelNo"));
    ui->aboutTBtn->setIcon(QIcon(":/images/System_AboutBtn_SelNo"));
    
    if (ui->listWidget->currentRow() != -1)//关闭其他高亮的名称 
    {
        ui->listWidget->setCurrentRow(-1);
        
        if (m_bInTimeEdit)//如果在时间编辑模式，关闭模式样式
        {
            m_bInTimeEdit = false;
            ui->lineEdit->hide();
            ui->lineEdit_2->hide();
            ui->lineEdit_3->hide();
            ui->lineEdit_4->hide();
            ui->lineEdit_6->hide();
            ui->lineEdit_7->hide();
            ui->lineEdit_8->hide();
            ui->lineEdit_9->hide();
            ui->lineEdit_10->hide();
            ui->lineEdit_11->hide();
            ui->lineEdit_12->hide();
            ui->lineEdit_13->hide();
            ui->lineEdit_14->hide();
            ui->lineEdit_15->hide();
            ui->lineEdit_16->hide();
            ui->lineEdit_17->hide();
            ui->lineEdit_18->hide();
            ui->lineEdit_19->hide();
            ui->lineEdit_20->hide();
        }
    }
    
    if (ui->listWidget_3->currentRow() != -1)//关闭其他高亮的名称 
    {
        ui->listWidget_3->setCurrentRow(-1);
    }
    
    if (ui->listWidget_4->currentRow() != -1)//关闭其他高亮的名称 
    {
        ui->listWidget_4->setCurrentRow(-1);
    }
    
    if (ui->listWidget_2->currentRow() != -1)//关闭其他高亮的名称 
    {
        ui->listWidget_2->setCurrentRow(-1);
    }
    
    if (ui->listWidget_6->currentRow() != -1)//关闭其他高亮的名称 
    {
        ui->listWidget_6->setCurrentRow(-1);
        QString styleStr = "QLabel { font: 15pt 'Ubuntu';color: rgb(105, 115, 119); }";
        ui->label_4->setStyleSheet(styleStr);
        ui->label_5->setStyleSheet(styleStr);
        ui->label_6->setStyleSheet(styleStr);
        QStringList IdentificationInfo1;
        IdentificationInfo1 << SYSTEM_SETTING_DIGITCALLCODELABEL
                            << SYSTEM_SETTING_DIGITMMSICODELABEL
                            << SYSTEM_SETTING_ANSWERBACKCODELABEL;
        ui->label->setText(IdentificationInfo1.at(0));
        ui->label_2->setText(IdentificationInfo1.at(1));
        ui->label_3->setText(IdentificationInfo1.at(2));
    }
    
    if (ui->listWidget_7->currentRow() != -1)//关闭其他高亮的名称 
    {
        ui->listWidget_7->setCurrentRow(-1);
    }
    
    ui->lineEdit_5->setFocus();
}
/****************************************************************************
**
** 函数名称：SystemSetting::listwidget6ClickedSlot
** 功能概述: 点击事件光标切换
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SystemSetting::listwidget6ClickedSlot(QListWidgetItem* item)
{
    if (m_bInTimeEdit)//如果在时间编辑模式，还原数据	
    {
        ui->dateTimeButton->setText(m_timeStr);
    }
    
    ui->homeTBnt->setIcon(QIcon(":/images/home_normal"));
    ui->testTBtn->setIcon(QIcon(":/images/System_TestBtn_SelNo"));
    ui->aboutTBtn->setIcon(QIcon(":/images/System_AboutBtn_SelNo"));
    
    if (ui->listWidget->currentRow() != -1)//关闭其他高亮的名称 
    {
        ui->listWidget->setCurrentRow(-1);
        
        if (m_bInTimeEdit)//如果在时间编辑模式，关闭模式样式
        {
            m_bInTimeEdit = false;
            ui->lineEdit->hide();
            ui->lineEdit_2->hide();
            ui->lineEdit_3->hide();
            ui->lineEdit_4->hide();
            ui->lineEdit_6->hide();
            ui->lineEdit_7->hide();
            ui->lineEdit_8->hide();
            ui->lineEdit_9->hide();
            ui->lineEdit_10->hide();
            ui->lineEdit_11->hide();
            ui->lineEdit_12->hide();
            ui->lineEdit_13->hide();
            ui->lineEdit_14->hide();
            ui->lineEdit_15->hide();
            ui->lineEdit_16->hide();
            ui->lineEdit_17->hide();
            ui->lineEdit_18->hide();
            ui->lineEdit_19->hide();
            ui->lineEdit_20->hide();
        }
    }
    
    if (ui->listWidget_3->currentRow() != -1)//关闭其他高亮的名称 
    {
        ui->listWidget_3->setCurrentRow(-1);
    }
    
    if (ui->listWidget_4->currentRow() != -1)//关闭其他高亮的名称 
    {
        ui->listWidget_4->setCurrentRow(-1);
    }
    
    if (ui->listWidget_5->currentRow() != -1)//关闭其他高亮的名称 未保存时还原数据
    {
        ui->listWidget_5->setCurrentRow(-1);
        QSqlRecord  sqlRecord = m_model->record(0);
        QString slavedelay = sqlRecord.value(SYSTEM_SETTING_SLAVEDELAY).toString();
        ui->lineEdit_5->setText(slavedelay);
        ui->lineEdit_5->setReadOnly(true);
    }
    
    if (ui->listWidget_2->currentRow() != -1)//关闭其他高亮的名称 
    {
        ui->listWidget_2->setCurrentRow(-1);
    }
    
    if (ui->listWidget_7->currentRow() != -1)//关闭其他高亮的名称 
    {
        ui->listWidget_7->setCurrentRow(-1);
    }
    
    QStringList IdentificationInfo2;
    IdentificationInfo2 << "<font color=white>4 or 5-digit Call Code:</font>"
                        << "<font color=white>9-digit MMSI Code:</font>"
                        << "<font color=white>Answer Back Code:</font>";
    ui->label->setText(IdentificationInfo2.at(0));
    ui->label_2->setText(IdentificationInfo2.at(1));
    ui->label_3->setText(IdentificationInfo2.at(2));
    QString styleStr = "QLabel { font: 15pt 'Ubuntu';color:white; }";
    ui->label_4->setStyleSheet(styleStr);
    ui->label_5->setStyleSheet(styleStr);
    ui->label_6->setStyleSheet(styleStr);
    ui->identificationSetting->setFocus();
}
/****************************************************************************
**
** 函数名称：SystemSetting::listwidget7ClickedSlot
** 功能概述: 点击事件光标切换
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SystemSetting::listwidget7ClickedSlot(QListWidgetItem* item)
{
    if (m_bInTimeEdit)//如果在时间编辑模式，还原数据	
    {
        ui->dateTimeButton->setText(m_timeStr);
    }
    
    ui->homeTBnt->setIcon(QIcon(":/images/home_normal"));
    ui->testTBtn->setIcon(QIcon(":/images/System_TestBtn_SelNo"));
    ui->aboutTBtn->setIcon(QIcon(":/images/System_AboutBtn_SelNo"));
    
    if (ui->listWidget->currentRow() != -1)//关闭其他高亮的名称 
    {
        ui->listWidget->setCurrentRow(-1);
        
        if (m_bInTimeEdit)//如果在时间编辑模式，关闭模式样式
        {
            m_bInTimeEdit = false;
            ui->lineEdit->hide();
            ui->lineEdit_2->hide();
            ui->lineEdit_3->hide();
            ui->lineEdit_4->hide();
            ui->lineEdit_6->hide();
            ui->lineEdit_7->hide();
            ui->lineEdit_8->hide();
            ui->lineEdit_9->hide();
            ui->lineEdit_10->hide();
            ui->lineEdit_11->hide();
            ui->lineEdit_12->hide();
            ui->lineEdit_13->hide();
            ui->lineEdit_14->hide();
            ui->lineEdit_15->hide();
            ui->lineEdit_16->hide();
            ui->lineEdit_17->hide();
            ui->lineEdit_18->hide();
            ui->lineEdit_19->hide();
            ui->lineEdit_20->hide();
        }
    }
    
    if (ui->listWidget_3->currentRow() != -1)//关闭其他高亮的名称
    {
        ui->listWidget_3->setCurrentRow(-1);
    }
    
    if (ui->listWidget_4->currentRow() != -1)//关闭其他高亮的名称
    {
        ui->listWidget_4->setCurrentRow(-1);
    }
    
    if (ui->listWidget_5->currentRow() != -1)//关闭其他高亮的名称 未保存时还原数据
    {
        ui->listWidget_5->setCurrentRow(-1);
        QSqlRecord  sqlRecord = m_model->record(0);
        QString slavedelay = sqlRecord.value(SYSTEM_SETTING_SLAVEDELAY).toString();
        ui->lineEdit_5->setText(slavedelay);
        ui->lineEdit_5->setReadOnly(true);
    }
    
    if (ui->listWidget_6->currentRow() != -1)//关闭其他高亮的名称
    {
        ui->listWidget_6->setCurrentRow(-1);
        QString styleStr = "QLabel { font: 15pt 'Ubuntu';color: rgb(105, 115, 119); }";
        ui->label_4->setStyleSheet(styleStr);
        ui->label_5->setStyleSheet(styleStr);
        ui->label_6->setStyleSheet(styleStr);
        QStringList IdentificationInfo1;
        IdentificationInfo1 << SYSTEM_SETTING_DIGITCALLCODELABEL
                            << SYSTEM_SETTING_DIGITMMSICODELABEL
                            << SYSTEM_SETTING_ANSWERBACKCODELABEL;
        ui->label->setText(IdentificationInfo1.at(0));
        ui->label_2->setText(IdentificationInfo1.at(1));
        ui->label_3->setText(IdentificationInfo1.at(2));
    }
    
    if (ui->listWidget_2->currentRow() != -1)//关闭其他高亮的名称
    {
        ui->listWidget_2->setCurrentRow(-1);
    }
    
    ui->printFocus->setFocus();
}
/****************************************************************************
**
** 函数名称：SystemSetting::eventFilter
** 功能概述: 事件监听函数，响应用户键盘操作
** 参数说明 watched：发送方， event：事件数据
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool SystemSetting::eventFilter(QObject* watched, QEvent* event)
{
    Logging::get()->info("SystemSetting::eventFilter");
    QStringList nameList;
    //所有焦点
    nameList << "dateTimeButton" << "languageFocus" << "horizontalScrollBarFocus"
             << "horizontalScrollBarFocus2" << "lineEdit_5" << "identificationSetting" << "printFocus"
             << "homeTBnt" << "testTBtn" << "aboutTBtn";
    QStringList IdentificationInfo1;//不高亮时的label
    IdentificationInfo1 << SYSTEM_SETTING_DIGITCALLCODELABEL
                        << SYSTEM_SETTING_DIGITMMSICODELABEL
                        << SYSTEM_SETTING_ANSWERBACKCODELABEL;
    QStringList IdentificationInfo2;//高亮时的label
    IdentificationInfo2 << "<font color=white>4 or 5-digit Call Code:</font>"
                        << "<font color=white>9-digit MMSI Code:</font>"
                        << "<font color=white>Answer Back Code:</font>";
    QStringList lineList;//时间控件编辑一栏
    lineList << "lineEdit" << "lineEdit_2" << "lineEdit_3" << "lineEdit_4" << "lineEdit_7" << "lineEdit_8"
             << "lineEdit_10" << "lineEdit_11" << "lineEdit_12" << "lineEdit_13" << "lineEdit_15" << "lineEdit_16" << "lineEdit_18"
             << "lineEdit_19";
    QStringList labelList;//左侧名称一列
    labelList << "listWidget" << "listWidget_2" << "listWidget_3" << "listWidget_4"
              << "listWidget_5" << "listWidget_6" << "listWidget_7";
    QKeyEvent* key_event = static_cast<QKeyEvent*>(event);
    int a =   key_event->key();
    //按键触发三种类型键值：51，按下，弹起。
            // 默认键弹起响应一次

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
        if (QEvent::KeyPress == event->type())//按下类型不处理
        {
            return true;
        }
        else if (51 == event->type())//51类型不处理，弹起时处理
        {
            return true;
        }
        
        for (int i = 0; i < lineList.length(); i++)//填入控件输入的数字
        {
            QWidget* widget = findChild<QWidget*>(lineList.at(i));
            
            if (widget && widget->hasFocus())
            {
                QLineEdit* edit = static_cast<QLineEdit*>(widget);
                edit->clear();
                edit->setText(QString::number(a - 0x30));
                
                if ((i + 1) < lineList.length())
                {
                    QWidget* widget2 = findChild<QWidget*>(lineList.at(i + 1));
                    
                    if (widget2)
                        widget2->setFocus();
                }
                
                break;
            }
        }
        
        break;
    }
    
    case Qt::Key_Right:
    case Qt::Key_Down:
    case Qt::Key_Tab:
    {
        if (QEvent::KeyPress == event->type())
        {
            return true;
        }
        else if (QEvent::KeyRelease == event->type())
        {
            int next=0;
            if (m_bInTimeEdit && a == Qt::Key_Right)//移动时间编辑框光标
            {
                for (int i = 0; i < lineList.length(); i++)
                {
                    QWidget* widget = findChild<QWidget*>(lineList.at(i));

                    if (widget && widget->hasFocus())
                    {
                        next = (i == lineList.length() - 1) ? 0 : i + 1;
                        break;
                    }
                }

                if (lineList.length())
                {
                    QWidget* widgetnext = findChild<QWidget*>(lineList.at(next));

                    if (widgetnext)
                    {
                        widgetnext->setFocus();
                    }
                }
            }
            return true;
        }
        int next = 0;
        bool inListWidget = false;
        if (m_bInTimeEdit)//当处于时间编辑状态，关闭编辑样式
        {
            m_bInTimeEdit = false;
            ui->lineEdit->hide();
            ui->lineEdit_2->hide();
            ui->lineEdit_3->hide();
            ui->lineEdit_4->hide();
            ui->lineEdit_6->hide();
            ui->lineEdit_7->hide();
            ui->lineEdit_8->hide();
            ui->lineEdit_9->hide();
            ui->lineEdit_10->hide();
            ui->lineEdit_11->hide();
            ui->lineEdit_12->hide();
            ui->lineEdit_13->hide();
            ui->lineEdit_14->hide();
            ui->lineEdit_15->hide();
            ui->lineEdit_16->hide();
            ui->lineEdit_17->hide();
            ui->lineEdit_18->hide();
            ui->lineEdit_19->hide();
            ui->lineEdit_20->hide();
            ui->dateTimeButton->setText(m_timeStr);
            ui->dateTimeButton->setFocus();
        }

        for (int i = 0; i < nameList.length(); i++)
        {
            QWidget* widget = findChild<QWidget*>(nameList.at(i));

            if (widget && widget->hasFocus())
            {
                if (nameList.at(i) == "horizontalScrollBarFocus" && a == Qt::Key_Right)//调节亮度
                {
                    int value = ui->horizontalScrollBar->value();

                    if (value < 100)
                    {
                        ui->horizontalScrollBar->setValue(value + 1);
                        QString sys = "echo ";
                        sys += QString::number(value + 1);
                        sys += " > /sys/class/backlight/LCD_backlight/brightness ";
                        system(sys.toStdString().c_str());
                    }

                    inListWidget = true;
                    break;
                }
                else if (nameList.at(i) == "horizontalScrollBarFocus2" && a == Qt::Key_Right)//调节声音
                {
                    int value = ui->horizontalScrollBar_2->value();

                    if (value < 127)
                    {
                        ui->horizontalScrollBar_2->setValue(value + 1);
                        QString sys = "amixer cset numid=1 ";
                        sys += QString::number(value + 1);
                        system(sys.toStdString().c_str());
                    }

                    inListWidget = true;
                    break;
                }
                else if (nameList.at(i) == "homeTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/home_normal"));
                }
                else if (nameList.at(i) == "settingTBtn")
                {

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
                else if (nameList.at(i) == "identificationSetting")//不高亮label
                {
                    ui->label->setText(IdentificationInfo1.at(0));
                    ui->label_2->setText(IdentificationInfo1.at(1));
                    ui->label_3->setText(IdentificationInfo1.at(2));
                    QString styleStr = "QLabel { font: 15pt 'Ubuntu';color: rgb(105, 115, 119); }";
                    ui->label_4->setStyleSheet(styleStr);
                    ui->label_5->setStyleSheet(styleStr);
                    ui->label_6->setStyleSheet(styleStr);
                    ui->listWidget_6->setCurrentRow(-1);
                }
                else if (nameList.at(i) == "lineEdit_5"  && a == Qt::Key_Right && !ui->lineEdit_5->isReadOnly())//编辑slaveDelay时，不移动光标
                {
                    inListWidget = true;
                    break;
                }
                else if (i >= 0 && i <= 6)//关闭左侧对应高亮名称
                {
                    switch (i)
                    {
                    case 0:
                    {
                        ui->listWidget->setCurrentRow(-1);
                        break;
                    }

                    case 1:
                    {
                        ui->listWidget_2->setCurrentRow(-1);
                        break;
                    }

                    case 2:
                    {
                        ui->listWidget_3->setCurrentRow(-1);
                        break;
                    }

                    case 3:
                    {
                        ui->listWidget_4->setCurrentRow(-1);
                        break;
                    }

                    case 4:
                    {
                        ui->listWidget_5->setCurrentRow(-1);

                        if (!ui->lineEdit_5->isReadOnly())
                        {
                            QSqlRecord  sqlRecord = m_model->record(0);
                            QString slavedelay = sqlRecord.value(SYSTEM_SETTING_SLAVEDELAY).toString();
                            ui->lineEdit_5->setText(slavedelay);
                            ui->lineEdit_5->setReadOnly(true);
                        }

                        break;
                    }

                    case 5:
                    {
                        ui->listWidget_6->setCurrentRow(-1);
                        break;
                    }

                    case 6:
                    {
                        ui->listWidget_7->setCurrentRow(-1);
                        break;
                    }
                    break;
                    }
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
            else if (nameList.at(next) == "settingTBtn")
            {

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
            else if (nameList.at(next) == "identificationSetting")//高亮文字
            {
                ui->label->setText(IdentificationInfo2.at(0));
                ui->label_2->setText(IdentificationInfo2.at(1));
                ui->label_3->setText(IdentificationInfo2.at(2));
                ui->listWidget_6->setCurrentRow(0);
                QString styleStr = "QLabel { font: 15pt 'Ubuntu';color:white; }";
                ui->label_4->setStyleSheet(styleStr);
                ui->label_5->setStyleSheet(styleStr);
                ui->label_6->setStyleSheet(styleStr);
            }
            else if (next >= 0 && next <= 6)//高亮对应左侧名称
            {
                switch (next)
                {
                case 0:
                {
                    ui->listWidget->setCurrentRow(0);
                    break;
                }

                case 1:
                {
                    ui->listWidget_2->setCurrentRow(0);
                    break;
                }

                case 2:
                {
                    ui->listWidget_3->setCurrentRow(0);
                    break;
                }

                case 3:
                {
                    ui->listWidget_4->setCurrentRow(0);
                    break;
                }

                case 4:
                {
                    ui->listWidget_5->setCurrentRow(0);
                    break;
                }

                case 5:
                {
                    ui->listWidget_6->setCurrentRow(0);
                    break;
                }

                case 6:
                {
                    ui->listWidget_7->setCurrentRow(0);
                    break;
                }
                break;
                }
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
            int prev=0;
            if (m_bInTimeEdit && a == Qt::Key_Left)
            {
                for (int i = 0; i < lineList.length(); i++)
                {
                    QWidget* widget = findChild<QWidget*>(lineList.at(i));

                    if (widget && widget->hasFocus())
                    {
                        prev = (i == 0) ? lineList.length() - 1 : i - 1;
                        break;
                    }
                }

                if (lineList.length())
                {
                    QWidget* widgetprev = findChild<QWidget*>(lineList.at(prev));

                    if (widgetprev)
                    {
                        widgetprev->setFocus();
                    }
                }
            }

            return true;
        }
        
        int prev = 0;
        bool inListWidget = false;
        if (m_bInTimeEdit)//关闭时间编辑样式
        {
            ui->dateTimeButton->setText(m_timeStr);
            m_bInTimeEdit = false;
            ui->lineEdit->hide();
            ui->lineEdit_2->hide();
            ui->lineEdit_3->hide();
            ui->lineEdit_4->hide();
            ui->lineEdit_6->hide();
            ui->lineEdit_7->hide();
            ui->lineEdit_8->hide();
            ui->lineEdit_9->hide();
            ui->lineEdit_10->hide();
            ui->lineEdit_11->hide();
            ui->lineEdit_12->hide();
            ui->lineEdit_13->hide();
            ui->lineEdit_14->hide();
            ui->lineEdit_15->hide();
            ui->lineEdit_16->hide();
            ui->lineEdit_17->hide();
            ui->lineEdit_18->hide();
            ui->lineEdit_19->hide();
            ui->lineEdit_20->hide();
            ui->dateTimeButton->setFocus();
        }
        // 按钮图片切换 focus 离开 按钮图片变暗
        for (int i = 0; i < nameList.length(); i++)
        {
            QWidget* widget = findChild<QWidget*>(nameList.at(i));

            if (widget && widget->hasFocus())
            {
                if (nameList.at(i) == "horizontalScrollBarFocus" && a == Qt::Key_Left)//调节亮度
                {
                    int value = ui->horizontalScrollBar->value();

                    if (value >= 1)
                    {
                        ui->horizontalScrollBar->setValue(value - 1);
                        QString sys = "echo ";
                        sys += QString::number(value - 1);
                        sys += " > /sys/class/backlight/LCD_backlight/brightness ";
                        system(sys.toStdString().c_str());
                    }

                    inListWidget = true;
                    break;
                }
                else if (nameList.at(i) == "horizontalScrollBarFocus2" && a == Qt::Key_Left)//调节声音
                {
                    int value = ui->horizontalScrollBar_2->value();

                    if (value >= 1)
                    {
                        ui->horizontalScrollBar_2->setValue(value - 1);
                        QString sys = "amixer cset numid=1 ";
                        sys += QString::number(value - 1);
                        system(sys.toStdString().c_str());
                    }

                    inListWidget = true;
                    break;
                }
                else if (nameList.at(i) == "homeTBnt")
                {
                    QToolButton* button = static_cast<QToolButton*>(widget);
                    button->setIcon(QIcon(":/images/home_normal"));
                }
                else if (nameList.at(i) == "settingTBtn")
                {

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
                else if (nameList.at(i) == "identificationSetting")
                {
                    ui->label->setText(IdentificationInfo1.at(0));
                    ui->label_2->setText(IdentificationInfo1.at(1));
                    ui->label_3->setText(IdentificationInfo1.at(2));
                    QString styleStr = "QLabel { font: 15pt 'Ubuntu';color: rgb(105, 115, 119); }";
                    ui->label_4->setStyleSheet(styleStr);
                    ui->label_5->setStyleSheet(styleStr);
                    ui->label_6->setStyleSheet(styleStr);
                    ui->listWidget_6->setCurrentRow(-1);
                }
                else if (nameList.at(i) == "lineEdit_5" && a == Qt::Key_Left && !ui->lineEdit_5->isReadOnly())//编辑slaveDelay时，不移动光标
                {
                    inListWidget = true;
                    break;
                }
                else if (i >= 0 && i <= 6)//关闭左侧对应高亮名称
                {
                    switch (i)
                    {
                    case 0:
                    {
                        ui->listWidget->setCurrentRow(-1);
                        break;
                    }

                    case 1:
                    {
                        ui->listWidget_2->setCurrentRow(-1);
                        break;
                    }

                    case 2:
                    {
                        ui->listWidget_3->setCurrentRow(-1);
                        break;
                    }

                    case 3:
                    {
                        ui->listWidget_4->setCurrentRow(-1);
                        break;
                    }

                    case 4:
                    {
                        ui->listWidget_5->setCurrentRow(-1);

                        if (!ui->lineEdit_5->isReadOnly())
                        {
                            QSqlRecord  sqlRecord = m_model->record(0);
                            QString slavedelay = sqlRecord.value(SYSTEM_SETTING_SLAVEDELAY).toString();
                            ui->lineEdit_5->setText(slavedelay);
                            ui->lineEdit_5->setReadOnly(true);
                        }

                        break;
                    }

                    case 5:
                    {
                        ui->listWidget_6->setCurrentRow(-1);
                        break;
                    }

                    case 6:
                    {
                        ui->listWidget_7->setCurrentRow(-1);
                        break;
                    }
                    break;
                    }
                }

                prev = (i == 0) ? nameList.length() - 1 : i - 1;
                break;
            }
        }

        if (inListWidget)
            break;

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
            else if (nameList.at(prev) == "settingTBtn")
            {

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
            else if (nameList.at(prev) == "identificationSetting")//高亮文字
            {
                ui->label->setText(IdentificationInfo2.at(0));
                ui->label_2->setText(IdentificationInfo2.at(1));
                ui->label_3->setText(IdentificationInfo2.at(2));
                QString styleStr = "QLabel { font: 15pt 'Ubuntu';color: white; }";
                ui->label_4->setStyleSheet(styleStr);
                ui->label_5->setStyleSheet(styleStr);
                ui->label_6->setStyleSheet(styleStr);
                ui->listWidget_6->setCurrentRow(0);
            }
            else if (prev >= 0 && prev <= 6)//高亮对应左侧名称
            {
                switch (prev)
                {
                case 0:
                {
                    ui->listWidget->setCurrentRow(0);
                    break;
                }

                case 1:
                {
                    ui->listWidget_2->setCurrentRow(0);
                    break;
                }

                case 2:
                {
                    ui->listWidget_3->setCurrentRow(0);
                    break;
                }

                case 3:
                {
                    ui->listWidget_4->setCurrentRow(0);
                    break;
                }

                case 4:
                {
                    ui->listWidget_5->setCurrentRow(0);
                    break;
                }

                case 5:
                {
                    ui->listWidget_6->setCurrentRow(0);
                    break;
                }

                case 6:
                {
                    ui->listWidget_7->setCurrentRow(0);
                    break;
                }
                break;
                }
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
            if (ui->listWidget_7->currentRow() == 0)//保存并修改打印模式状态
            {
                QSqlRecord record = m_model->record(0);
                int num = ui->comboBox_2->currentIndex();
                QString numStr = QString::number(num, 10);
                record.setValue(SYSTEM_SETTING_REALTIMEPRINT, numStr);
                emit realTimePrinting(numStr);
                m_model->setRecord(0, record);
                m_model->submitAll();
            }
            else if (ui->listWidget_2->currentRow() == 0)//保存修改的语言模式
            {
                QSqlRecord record = m_model->record(0);
                int num = ui->comboBox->currentIndex();
                QString numStr = QString::number(num, 10);
                record.setValue(SYSTEM_SETTING_LANGUAGE, numStr);
                m_model->setRecord(0, record);
                m_model->submitAll();
            }
            
            return true;
        }
        
        for (int i = 0; i < nameList.length(); i++)//触发按键事件
        {
            QWidget* widget = findChild<QWidget*>(nameList.at(i));
            
            if (widget && widget->hasFocus())
            {
                if (nameList.at(i) == "homeTBnt")
                {
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                }
                else if (nameList.at(i) == "settingTBtn")
                {
                    break;
                }
                else if (nameList.at(i) == "testTBtn")
                {
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                }
                else if (nameList.at(i) == "aboutTBtn")
                {
                    Button* button = static_cast<Button*>(widget);
                    button->click();
                }
                else if (nameList.at(i) == "languageFocus")
                {
                    ui->comboBox->showPopup();
                }
                else if (nameList.at(i) == "printFocus")
                {
                    ui->comboBox_2->showPopup();
                }
                else if (nameList.at(i) == "identificationSetting")
                {
                    identificationSettingClickedSlot();
                }
                else if (nameList.at(i) == "dateTimeButton")//打开时间编辑模式样式
                {
                    QDateTime now = QDateTime::currentDateTime();
                    QDate now_date = now.date();
                    QTime now_time = now.time();
                    QString y = QString::number(now_date.year() / 1000, 10);
                    ui->lineEdit->setText(y);
                    ui->lineEdit->show();
                    QString y2 = QString::number((now_date.year() / 100) % 10, 10);
                    ui->lineEdit_2->setText(y2);
                    ui->lineEdit_2->show();
                    QString y3 = QString::number((now_date.year() / 10) % 10, 10);
                    ui->lineEdit_3->setText(y3);
                    ui->lineEdit_3->show();
                    QString y4 = QString::number(now_date.year() % 10, 10);
                    ui->lineEdit_4->setText(y4);
                    ui->lineEdit_4->show();
                    ui->lineEdit_6->show();
                    QString y7 = QString::number(now_date.month() / 10, 10);
                    ui->lineEdit_7->setText(y7);
                    ui->lineEdit_7->show();
                    QString y8 = QString::number(now_date.month() % 10, 10);
                    ui->lineEdit_8->setText(y8);
                    ui->lineEdit_8->show();
                    ui->lineEdit_9->show();
                    QString y10 = QString::number(now_date.day() / 10, 10);
                    ui->lineEdit_10->setText(y10);
                    ui->lineEdit_10->show();
                    QString y11 = QString::number(now_date.day() % 10, 10);
                    ui->lineEdit_11->setText(y11);
                    ui->lineEdit_11->show();
                    QString y12 = QString::number(now_time.hour() / 10, 10);
                    ui->lineEdit_12->setText(y12);
                    ui->lineEdit_12->show();
                    QString y13 = QString::number(now_time.hour() % 10, 10);
                    ui->lineEdit_13->setText(y13);
                    ui->lineEdit_13->show();
                    ui->lineEdit_14->show();
                    QString y15 = QString::number(now_time.minute() / 10, 10);
                    ui->lineEdit_15->setText(y15);
                    ui->lineEdit_15->show();
                    QString y16 = QString::number(now_time.minute() % 10, 10);
                    ui->lineEdit_16->setText(y16);
                    ui->lineEdit_16->show();
                    ui->lineEdit_17->show();
                    QString y18 = QString::number(now_time.second() / 10, 10);
                    ui->lineEdit_18->setText(y18);
                    ui->lineEdit_18->show();
                    QString y19 = QString::number(now_time.second() % 10, 10);
                    ui->lineEdit_19->setText(y19);
                    ui->lineEdit_19->show();
                    ui->lineEdit_20->show();
                    ui->lineEdit->setFocus();
                    ui->dateTimeButton->setText(QString(""));
                    m_bInTimeEdit = true;
                }
                else if (nameList.at(i) == "lineEdit_5")//打开SLAVE DELAY编辑模式
                {
                    if (ui->lineEdit_5->isReadOnly())
                    {
                        ui->lineEdit_5->setReadOnly(false);
                    }
                    else
                    {
                        QSqlRecord record = m_model->record(0);
                        int num = ui->lineEdit_5->text().toInt();
                        ui->lineEdit_5->setText(QString::number(num, 10));
                        record.setValue(SYSTEM_SETTING_SLAVEDELAY, ui->lineEdit_5->text());
                        m_model->setRecord(0, record);
                        m_model->submitAll();
                        ui->lineEdit_5->setReadOnly(true);
                        Transit::get()->EmitSignalSlaveDelay(num);
                    }
                }
                
                break;
            }
            else if (m_bInTimeEdit)//处于时间编辑状态时，保存设置时间，退出编辑模式样式
            {
                ui->dateTimeButton->setFocus();
                m_bInTimeEdit = false;
                ui->lineEdit->hide();
                ui->lineEdit_2->hide();
                ui->lineEdit_3->hide();
                ui->lineEdit_4->hide();
                ui->lineEdit_6->hide();
                ui->lineEdit_7->hide();
                ui->lineEdit_8->hide();
                ui->lineEdit_9->hide();
                ui->lineEdit_10->hide();
                ui->lineEdit_11->hide();
                ui->lineEdit_12->hide();
                ui->lineEdit_13->hide();
                ui->lineEdit_14->hide();
                ui->lineEdit_15->hide();
                ui->lineEdit_16->hide();
                ui->lineEdit_17->hide();
                ui->lineEdit_18->hide();
                ui->lineEdit_19->hide();
                ui->lineEdit_20->hide();
                
                if (ui->lineEdit->text() == "" || ui->lineEdit_2->text() == "" || ui->lineEdit_3->text() == ""
                    || ui->lineEdit_4->text() == ""
                    || ui->lineEdit_7->text() == "" || ui->lineEdit_8->text() == "" || ui->lineEdit_11->text() == ""
                    || ui->lineEdit_10->text() == ""
                    || ui->lineEdit_12->text() == "" || ui->lineEdit_13->text() == "" || ui->lineEdit_15->text() == ""
                    || ui->lineEdit_16->text() == "" || ui->lineEdit_18->text() == "" || ui->lineEdit_19->text() == "")
                {
                    break;
                }
                else//时间输入值有效时，进行保存处理
                {
                    QDateTime now = QDateTime::currentDateTime();
                    QDate date = now.date();
                    QTime timeNow = now.time();
                    QString timestr;
                    int y, m, d;
                    int h, min, s;
                    __time_t t = 0;
                    struct tm t2;
//   struct tm {      int tm_sec;			/* Seconds.	[0-60] (1 leap second) */
//                           int tm_min;			/* Minutes.	[0-59] */
//                           int tm_hour;			/* Hours.	[0-23] */
//                           int tm_mday;			/* Day.		[1-31] */
//                           int tm_mon;			/* Month.	[0-11] */
//                           int tm_year;			/* Year	- 1900.  */
//                           int tm_wday;			/* Day of week.	[0-6] */
//                           int tm_yday;			/* Days in year.[0-365]	*/
//                           int tm_isdst;			/* DST.		[-1/0/1]*/
                    y = ui->lineEdit->text().toInt() * 1000 + ui->lineEdit_2->text().toInt() * 100 + ui->lineEdit_3->text().toInt() * 10
                        + ui->lineEdit_4->text().toInt();
                        
                    if (y < 1970 || y > 2050)
                        y = date.year();
                        
                    t2.tm_year = y - 1900;
                    m = ui->lineEdit_7->text().toInt() * 10 + ui->lineEdit_8->text().toInt();
                    
                    if (m < 1 || m > 12)
                        m = date.month();
                        
                    t2.tm_mon = m - 1;
                    d = ui->lineEdit_10->text().toInt() * 10 + ui->lineEdit_11->text().toInt();
                    
                    if (d > 31 || d < 1)
                        d = date.day();
                        
                    t2.tm_mday = d;
                    bool ret = date.isValid(y, m, d);
                    h = ui->lineEdit_12->text().toInt() * 10 + ui->lineEdit_13->text().toInt();
                    min = ui->lineEdit_15->text().toInt() * 10 + ui->lineEdit_16->text().toInt();
                    s = ui->lineEdit_18->text().toInt() * 10 + ui->lineEdit_19->text().toInt();
                    
                    if (h < 0 || h > 23)
                        h = timeNow.hour();
                        
                    t2.tm_hour = h;
                    
                    if (min < 0 || min > 59)
                        min = timeNow.minute();
                        
                    t2.tm_min = min;
                    
                    if (s < 0 || s > 59)
                        s = timeNow.second();
                        
                    t2.tm_sec = s;
                    bool ret2 = timeNow.isValid(h, min, s);
                    
                    if (ret)
                    {
                        date.setDate(y, m, d);
                        timestr += QString::number(y, 10);
                        timestr += "/";
                        
                        if (m < 10)
                            timestr += "0";
                            
                        timestr += QString::number(m, 10);
                        timestr += "/";
                        
                        if (d < 10)
                            timestr += "0";
                            
                        timestr += QString::number(d, 10);
                    }
                    else
                    {
                        timestr += QString::number(date.year(), 10);
                        timestr += "/";
                        
                        if (date.month() < 10)
                            timestr += "0";
                            
                        timestr += QString::number(date.month(), 10);
                        timestr += "/";
                        
                        if (date.day() < 10)
                            timestr += "0";
                            
                        timestr += QString::number(date.day(), 10);
                    }
                    
                    timestr += "        ";
                    
                    if (ret2)
                    {
                        if (h < 10)
                            timestr += "0";
                            
                        timestr += QString::number(h, 10);
                        timestr += ":";
                        
                        if (min < 10)
                            timestr += "0";
                            
                        timestr += QString::number(min, 10);
                        timestr += ":";
                        
                        if (s < 10)
                            timestr += "0";
                            
                        timestr += QString::number(s, 10);
                    }
                    else
                    {
                        if (timeNow.hour() < 10)
                            timestr += "0";
                            
                        timestr += QString::number(timeNow.hour(), 10);
                        timestr += ":";
                        
                        if (timeNow.minute() < 10)
                            timestr += "0";
                            
                        timestr += QString::number(timeNow.minute(), 10);
                        timestr += ":";
                        
                        if (timeNow.second() < 10)
                            timestr += "0";
                            
                        timestr += QString::number(timeNow.second(), 10);
                    }
                    
                    if (ret && ret2)
                    {
                        t = mktime(&t2);
                        stime(&t);
                        system("hwclock -w");//写入时间芯片
                    }
                    
                    ui->dateTimeButton->setText(timestr);
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
        
        if (m_bInTimeEdit)//退出时间编辑模式
        {
            ui->dateTimeButton->setFocus();
            ui->dateTimeButton->setText(m_timeStr);
            m_bInTimeEdit = false;
            ui->lineEdit->hide();
            ui->lineEdit_2->hide();
            ui->lineEdit_3->hide();
            ui->lineEdit_4->hide();
            ui->lineEdit_6->hide();
            ui->lineEdit_7->hide();
            ui->lineEdit_8->hide();
            ui->lineEdit_9->hide();
            ui->lineEdit_10->hide();
            ui->lineEdit_11->hide();
            ui->lineEdit_12->hide();
            ui->lineEdit_13->hide();
            ui->lineEdit_14->hide();
            ui->lineEdit_15->hide();
            ui->lineEdit_16->hide();
            ui->lineEdit_17->hide();
            ui->lineEdit_18->hide();
            ui->lineEdit_19->hide();
            ui->lineEdit_20->hide();
        }
        else//返回到主菜单
        {
            if (!ui->lineEdit_5->isReadOnly())//保存SLAVE DELAY数据，退出编辑模式
            {
                QSqlRecord  sqlRecord = m_model->record(0);
                QString slavedelay = sqlRecord.value(SYSTEM_SETTING_SLAVEDELAY).toString();
                ui->lineEdit_5->setText(slavedelay);
                ui->lineEdit_5->setReadOnly(true);
            }
            
            QWidget* widget = findChild<QWidget*>("homeTBnt");
            
            if (widget)
            {
                Button* button = static_cast<Button*>(widget);
                button->click();
            }
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
** 函数名称：SystemSetting::homeClickedSlot
** 功能概述: 返回到主菜单
** 参数说明
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SystemSetting::homeClickedSlot()
{
    Logging::get()->info("SystemSetting::homeClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(Constants::SYSTEM_SETTING_VIEW, "homeWidget", paraMap);
}
/****************************************************************************
**
** 函数名称：SystemSetting::frontPageSlot
** 功能概述: 打开页面时更新页面数据
** 参数说明： thisID：起始页面， fowordID：目标页面， paraMap：传递参数
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SystemSetting::frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap)
{
    if (fowordID != Constants::SYSTEM_SETTING_VIEW) {return;}
    
    Logging::get()->info("SystemSetting::frontPageSlot");
    ui->homeTBnt->setIcon(QIcon(":/images/home_normal"));
    ui->testTBtn->setIcon(QIcon(":/images/System_TestBtn_SelNo"));
    ui->aboutTBtn->setIcon(QIcon(":/images/System_AboutBtn_SelNo"));
    ui->listWidget->setCurrentRow(0);
    ui->listWidget_2->setCurrentRow(-1);
    ui->listWidget_3->setCurrentRow(-1);
    ui->listWidget_4->setCurrentRow(-1);
    ui->listWidget_5->setCurrentRow(-1);
    ui->listWidget_6->setCurrentRow(-1);
    ui->listWidget_7->setCurrentRow(-1);
    QString styleStr = "QLabel { font: 15pt 'Ubuntu';color: rgb(105, 115, 119); }";
    ui->label_4->setStyleSheet(styleStr);
    ui->label_5->setStyleSheet(styleStr);
    ui->label_6->setStyleSheet(styleStr);
    QStringList IdentificationInfo1;
    IdentificationInfo1 << SYSTEM_SETTING_DIGITCALLCODELABEL
                        << SYSTEM_SETTING_DIGITMMSICODELABEL
                        << SYSTEM_SETTING_ANSWERBACKCODELABEL;
    ui->label->setText(IdentificationInfo1.at(0));
    ui->label_2->setText(IdentificationInfo1.at(1));
    ui->label_3->setText(IdentificationInfo1.at(2));
    ui->dateTimeButton->setFocus();
    
    if (m_bInTimeEdit)//如果上次退出时编辑状态，清楚模式残留样式，初始化
    {
        m_bInTimeEdit = false;
        ui->lineEdit->hide();
        ui->lineEdit_2->hide();
        ui->lineEdit_3->hide();
        ui->lineEdit_4->hide();
        ui->lineEdit_6->hide();
        ui->lineEdit_7->hide();
        ui->lineEdit_8->hide();
        ui->lineEdit_9->hide();
        ui->lineEdit_10->hide();
        ui->lineEdit_11->hide();
        ui->lineEdit_12->hide();
        ui->lineEdit_13->hide();
        ui->lineEdit_14->hide();
        ui->lineEdit_15->hide();
        ui->lineEdit_16->hide();
        ui->lineEdit_17->hide();
        ui->lineEdit_18->hide();
        ui->lineEdit_19->hide();
        ui->lineEdit_20->hide();
    }
    
    if (paraMap[SYSTEM_SETTING_MODLE_NAME] == SYSTEM_SETTING_MODLE_OK)
    {
        m_model->select();
        QSqlRecord  sqlRecord = m_model->record(0);
        QString digitcallcode = sqlRecord.value(SYSTEM_SETTING_DIGITCALLCODE).toString();
        QString mmsicode = sqlRecord.value(SYSTEM_SETTING_MMSICODE).toString();
        QString answerbackcode = sqlRecord.value(SYSTEM_SETTING_ANSWERBACKCODE).toString();
        ui->label_4->setText(digitcallcode);
        ui->label_5->setText(mmsicode);
        ui->label_6->setText(answerbackcode);
    }
    
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
    m_timeStr = date;
    ui->dateTimeButton->setText(now.toString(date));
}
/****************************************************************************
**
** 函数名称：SystemSetting::settingClickedSlot
** 功能概述: 跳转到系统设置界面
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SystemSetting::settingClickedSlot()
{
    Logging::get()->info("SystemSetting::settingClickedSlot");
}
/****************************************************************************
**
** 函数名称：SystemSetting::testClickedSlot
** 功能概述: 跳转到系统测试界面
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SystemSetting::testClickedSlot()
{
    Logging::get()->info("SystemSetting::testClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(Constants::SYSTEM_SETTING_VIEW, Constants::SYSTEM_TEST_VIEW, paraMap);
}
/****************************************************************************
**
** 函数名称：SystemSetting::aboutClickedSlot
** 功能概述: 跳转到系统about界面
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SystemSetting::aboutClickedSlot()
{
    Logging::get()->info("SystemSetting::aboutClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(Constants::SYSTEM_TEST_VIEW, Constants::SYSTEM_ABOUT_VIEW, paraMap);
}
/****************************************************************************
**
** 函数名称：SystemSetting::identificationSettingClickedSlot
** 功能概述: 进入到系统设置子界面
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void SystemSetting::identificationSettingClickedSlot()
{
    Logging::get()->info("SystemSetting::identificationSettingClickedSlot");
    QMap <QString, QString>paraMap;
    emit afterPageSignal(Constants::SYSTEM_TEST_VIEW, Constants::SYSTEM_IDENTIFICATION_SETTING_VIEW, paraMap);
}
SystemSetting::~SystemSetting()
{
    Logging::get()->info("SystemSetting::~SystemSetting");
    delete ui;
}

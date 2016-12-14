/****************************************************************************
**
** 文件名称： nbdpview.h
** 功能概述:  nbdp主菜单类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef NbdpView_H
#define NbdpView_H

#include <QSplitter>
#include <QTextEdit>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QTreeWidgetItemIterator>
#include <QSettings>
#include <QDateTime>
#include <QLabel>
#include <QCloseEvent>
#include <QStackedWidget>
#include <QSplitterHandle>
#include <QPainter>
#include <QVBoxLayout>
#include <QStackedWidget>

#include "common/baseview.h"
#include "common/statuswidget.h"
#include "home/homeview.h"
#include "call/callview.h"
#include "contacts/contactsview.h"
//#include "common/controlwidget.h"
#include "core/manager/viewmanager.h"
#include "contacts/individualeditview.h"
#include "contacts/stationeditview.h"
#include "views/contacts/contactsindview.h"
#include "views/messages/messageslistview.h"
#include "views/messages/messagesshowview.h"
#include "views/manager/managerfile.h"
#include "views/manager/managerfileeditview.h"
#include "views/manager/managermacro.h"
#include "views/manager/managerphrasebook.h"
#include "views/call/individualselectview.h"
#include "views/call/stationselectview.h"

#include "views/system/systemsetting.h"
#include "views/system/systemtest.h"
#include "views/system/identificationsetting.h"
#include "views/system/systemabout.h"
#include "call/manualfrequencyview.h"
#include "call/frequencyview.h"
#include "call/callcommunication.h"
#include "views/scan/scangroupview.h"
#include "views/scan/scangroupeditview.h"
#include "views/scan/scanfrequencyview.h"
#include "widgets/iocmessage.h"

#include "transit.h"
#include "control.h"

#ifndef __DOFAR_LED_AND_GPIO_H
#define __DOFAR_LED_AND_GPIO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <linux/errno.h>

#define 	LED_DEV			"/dev/emec_leds_gpio"
#define 	HIGH_LEVEL	1
#define		LOW_LEVEL	0
#define MOTOR_MAGIC 'M'
#define DF_D36 		_IOW(MOTOR_MAGIC, 11,int)
//#define DF_D37		_IOW(MOTOR_MAGIC, 12,int)
//#define DF_D35D38	_IOW(MOTOR_MAGIC, 13,int)

#define DF_GPO1		_IOW(MOTOR_MAGIC, 14,int)
#define DF_GPO2		_IOW(MOTOR_MAGIC, 15,int)
#define DF_GPO3		_IOW(MOTOR_MAGIC, 16,int)

#define DF_GPI1 	_IOW(MOTOR_MAGIC, 17,int)
#define DF_GPI2		_IOW(MOTOR_MAGIC, 18,int)
#define LCD_EN		_IOW(MOTOR_MAGIC, 19,int)
#define ARM_CTR		_IOW(MOTOR_MAGIC, 20,int)
#define DF_GPO22	_IOW(MOTOR_MAGIC, 21,int)
#define DF_GPO25	_IOW(MOTOR_MAGIC, 22,int)



int dofar_LED_initialization();
int dofar_LED_AND_GPIO_control(int fd, int LED_num, int LED_level);
void dofar_LED_release(int fd);
#endif

class NbdpView : public BaseView
{
        Q_OBJECT
        Q_PROPERTY(QString backPix READ backPix WRITE setBackPix DESIGNABLE true SCRIPTABLE true)
        
    public:
        explicit NbdpView(QWidget* parent = 0);
        ~NbdpView();
        QString get_strSelfMMSI();
        
        const QString& backPix()
        {
            return m_backgroundPix;
        }
        // int dofar_LED_initialization();
        //  int dofar_LED_AND_GPIO_control(int fd,int LED_num,int LED_level);
        //  int dofar_LED_release(int fd);
        Q_INVOKABLE void setBackPix(const QString& backPix);
        
    signals:
        void  afterPageSignal(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        void signal1();
        void realTimePrinting(QString realTimePrinting);
        void setMMSI(QString mmsi);
        
    protected:
        void paintEvent(QPaintEvent* event);
        bool focusNextPrevChild(bool next);
        #ifdef SIMULATE_MODE
        void keyPressEvent(QKeyEvent* event);
        #endif
    private:
        QVBoxLayout* m_mainLayout;
        StatusWidget* m_statusWidget;		//状态栏
        HomeWidget* m_homeWidget;		//主菜单处理
        QString m_backgroundPix;		//主背景
        QStackedWidget*  m_stackWidget;		//各界面处理
        //  bool eventFilter(QObject* watched, QEvent* event);
        CallView* m_callWidget;
        ContactsView* m_contactsWidget;
        
        MessagesListView* m_messagesListView;
        MessagesShowView* m_messagesShowView;
        ManagerFileEditView* m_managerFileEditView;
        ManagerFile* m_managerFile;
        ManagerMacro* m_managerMacro;
        ManagerPhrasebook* m_managerPhrasebook;
        IndividualEditView* m_individualEditView;
        StationEditView* m_stationEditView;
        ContactsIndView* m_contactsindview;
        IndividualSelectView* m_individualSelectView;
        StationSelectView* m_stationSelectView;
        SystemSetting* m_systemSetting;
        ScanGroupView* m_scangroupview;
        ScanGroupEditView* m_scangroupeditview;
        ScanFrequencyView* m_scanfrequencyview;
        SystemTest* m_systemtest;
        SystemAbout* m_systemabout;
        IdentificationSetting* m_identification;
        ManualFrequencyView* m_manualFrequencyView;
        FrequencyView* m_frequencyView;
        CallCommunication* m_callCommunication;
        
        ViewManager m_viewManager ;	//各主界面列表
        
    private slots:
        void forward(int index = 0);
        void afterPageslot(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        void SlotTimeout();
        void SlotRadioConnectAnswer(bool ret);
        void SlotCheckData(CheckDataClass* cdc);
        void SlotShutDown();
        void SlotDSCfollowComm(CallInfoClass* cic);
};

#endif // NbdpView_H

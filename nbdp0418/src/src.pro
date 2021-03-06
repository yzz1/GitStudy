#-------------------------------------------------
#
# Project created by QtCreator 2015-08-10T15:18:12
#
#-------------------------------------------------

QT       += core gui xml sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = nbdp
TEMPLATE = app

# 是否使用键盘快捷键模拟信号发送 如果不用键盘模拟，只要把下面语句注释掉重新编译即可。
DEFINES += SIMULATE_MODE

include(../libs/3rdparty/log4qt/log4qt.pri)

INCLUDEPATH += ../transit \
../control \
../logging \
../myCom

LIBS += -L../dist/nbdp/lib -ltransit \
-L../dist/nbdp/lib -lcontrol \
-L../dist/nbdp/lib -llogging \
-L../dist/nbdp/lib -lmyCom

DESTDIR = ../dist/nbdp

target.path = ../dist/nbdp
INSTALLS += target

MOC_DIR = tmp
OBJECTS_DIR = tmp
RCC_DIR = tmp
UI_DIR = tmp

SOURCES += \
    core/database/connectionpool.cpp \
    core/database/database.cpp \
    core/database/sqls.cpp \
    core/utils/configutils.cpp \
    core/utils/pathresolve.cpp \
    views/call/callview.cpp \
    views/common/baseview.cpp \
    views/common/configreader.cpp \
    views/common/statuswidget.cpp \
    views/home/homeview.cpp \
    views/nbdpview.cpp \
    widgets/button.cpp \
    main.cpp \
    core/manager/viewmanager.cpp \
    widgets/messagebox.cpp \
    views/contacts/contactsview.cpp \
    models/contactsmodel.cpp \
    models/contactsitemdelegate.cpp \
    views/contacts/contactsstyle.cpp \
    core/utils/sqlitehelper.cpp \
    widgets/titlewidget.cpp \
    views/contacts/individualeditview.cpp \
    views/contacts/stationeditview.cpp \
    models/frequencymodel.cpp \
    models/frequencyitemdelegate.cpp \
    views/contacts/contactsindview.cpp \
    views/messages/messageslistview.cpp \
    views/contacts/contactsindstyle.cpp \
    views/messages/messagesstyle.cpp \
    views/messages/messagesshowview.cpp \
    models/messagesitemdelegate.cpp \
    views/manager/managerfile.cpp \
    views/manager/managerfileeditview.cpp \
    models/messagesmodel.cpp \
    models/messagedetaildelegate.cpp \
    views/manager/managerfilestyle.cpp \
    models/filemodels.cpp \
    models/fileitemdelegate.cpp \
    widgets/inputdialog.cpp \
    views/manager/managermacro.cpp \
    views/manager/managerphrasebook.cpp \
    views/call/individualselectview.cpp \
    views/call/stationselectview.cpp \
    views/manager/managerstyle.cpp \
    models/managermodel.cpp \
    models/managerdelegate.cpp \
    views/system/systemsetting.cpp \
    views/system/systemtest.cpp \
    widgets/messagedialog.cpp \
    views/call/manualfrequencyview.cpp \
    views/call/frequencyview.cpp \
    widgets/iocmessage.cpp \
    views/system/identificationsetting.cpp \
    views/system/systemabout.cpp \
    views/call/callcommunication.cpp \
    views/scan/scangroupview.cpp \
    views/scan/scangroupstyle.cpp \
    views/scan/scangroupeditview.cpp \
    views/scan/scanfrequencyview.cpp \
    views/call/commumessagesstyle.cpp \
    views/call/callcommunicationwidget.cpp \
    views/call/callcommunicationstyle.cpp \
    views/call/callphrasebookstyle.cpp \
    views/call/callfilestyle.cpp \
    models/managerloadfilemodel.cpp \
    core/serialport/serialportcommunication.cpp \
    core/serialport/serialbase.cpp \
    widgets/frequencyinput.cpp \
    widgets/contactsinput.cpp \
    core/utils/intputcheck.cpp \
    core/utils/commonutils.cpp


HEADERS  += \
    core/database/connectionpool.h \
    core/database/database.h \
    core/database/sqls.h \
    core/utils/configutils.h \
    core/utils/constants.h \
    core/utils/pathresolve.h \
    core/utils/singleton.h \
    views/call/callview.h \
    views/common/baseview.h \
    views/common/configreader.h \
    views/common/constants.h \
    views/common/statuswidget.h \
    views/home/homeview.h \
    views/nbdpview.h \
    widgets/button.h \
    core/manager/viewmanager.h \
    widgets/messagebox.h \
    views/contacts/contactsview.h \
    core/manager/viewmanager_p.h \
    models/contactsmodel.h \
    models/contactsitemdelegate.h \
    views/contacts/contactsstyle.h \
    core/utils/sqlitehelper.h \
    widgets/titlewidget.h \
    views/contacts/individualeditview.h \
    views/contacts/stationeditview.h \
    models/frequencymodel.h \
    models/frequencyitemdelegate.h \
    views/contacts/contactsindview.h \
    views/messages/messageslistview.h \
    views/contacts/contactsindstyle.h \
    views/messages/messagesstyle.h \
    views/messages/messagesshowview.h \
    models/messagesitemdelegate.h  \
    views/manager/managerfile.h \
    views/manager/managerfileeditview.h \
    models/messagesmodel.h \
    models/messagedetaildelegate.h \
    models/managerfileitemdelegate.h \
    views/manager/managerfilestyle.h \
    models/filemodels.h \
    models/fileitemdelegate.h \
    widgets/inputdialog.h \
    views/manager/managermacro.h \
    views/manager/managerphrasebook.h \
    views/call/individualselectview.h \
    views/call/stationselectview.h \
    views/manager/managerstyle.h \
    models/managermodel.h \
    models/managerdelegate.h \
    views/system/systemsetting.h \
    views/system/systemtest.h \
    widgets/messagedialog.h \
    views/call/manualfrequencyview.h \
    views/call/frequencyview.h \
    widgets/iocmessage.h \
    views/system/identificationsetting.h \
    views/system/systemabout.h \
    views/call/callcommunication.h \
    views/scan/scangroupview.h \
    views/scan/scangroupstyle.h \
    views/scan/scangroupeditview.h \
    views/scan/scanfrequencyview.h \
    views/call/commumessagesstyle.h \
    views/call/callcommunicationwidget.h \
    views/call/callcommunicationstyle.h \
    views/call/callphrasebookstyle.h \
    views/call/callfilestyle.h \
    models/managerloadfilemodel.h \
    core/serialport/serialportcommunication.h \
    core/serialport/serialbase.h \
    widgets/frequencyinput.h \
    widgets/contactsinput.h \
    core/utils/intputcheck.h \
    core/utils/commonutils.h

FORMS    += mainwindow.ui \
    widgets/messagebox.ui \
    views/contacts/contactsview.ui \
    widgets/titlewidget.ui \
    views/contacts/individualeditview.ui \
    views/contacts/stationeditview.ui \
    views/contacts/contactsindview.ui \
    views/messages/messageslistview.ui \
    views/messages/messagesshowview.ui \
    views/manager/managerfile.ui \
    views/manager/managerfileeditview.ui \
    widgets/inputdialog.ui \
    views/call/callview.ui \
    views/manager/managermacro.ui \
    views/manager/managerphrasebook.ui \
    views/call/individualselectview.ui \
    views/call/stationselectview.ui \
    views/system/systemsetting.ui \
    views/system/systemtest.ui \
    widgets/messagedialog.ui \
    views/call/manualfrequencyview.ui \
    views/call/frequencyview.ui \
    widgets/iocmessage.ui \
    views/system/identificationsetting.ui \
    views/system/systemabout.ui \
    views/call/callcommunication.ui \
    views/scan/scangroupview.ui \
    views/scan/scangroupeditview.ui \
    views/scan/scanfrequencyview.ui \
    views/call/callcommunicationwidget.ui \
    widgets/frequencyinput.ui \
    widgets/contactsinput.ui

RESOURCES += \
    resources/nbdp.qrc

copydb.commands =$(COPY_DIR) $$PWD/resources/db $$DESTDIR
copyconfig.commands =$(COPY_DIR) $$PWD/resources/config $$DESTDIR

first.depends = $(first) copyconfig copydb
export(first.depends)
export(copydb.commands)
export(copyconfig.commands)
QMAKE_EXTRA_TARGETS += first copyconfig copydb

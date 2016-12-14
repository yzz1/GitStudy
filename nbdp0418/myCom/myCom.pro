#-------------------------------------------------
#
# Project created by QtCreator 2015-05-16T09:44:09
#   PC duan :发送有发送计时器，接受有接受空字符来判断
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DEFINES+= _TTY_POSIX_

TARGET = myCom
TEMPLATE = lib

INCLUDEPATH += ../transit
LIBS += -L../dist/nbdp/lib -ltransit



SOURCES += main.cpp\
        mainwindow.cpp \
    qextserialport.cpp \
    qextserialbase.cpp \
    posix_qextserialport.cpp \
    globalarray.cpp \
    dockwidget.cpp \
    UISerial.cpp \
    UISerialFilter.cpp \
    nbdpWorkFlow.cpp \
    maintimer.cpp \
    recetimer.cpp

HEADERS  += mainwindow.h \
    qextserialport.h \
    qextserialbase.h \
    posix_qextserialport.h \
    globalarray.h \
    dockwidget.h \
    UIDefineInsStruct.h \
    UISerial.h \
    UISerialFilter.h \
    nbdpWorkFlow.h \
    mainwindow_global.h \
    maintimer.h \
    recetimer.h

FORMS    += mainwindow.ui \
    dockwidget.ui

OTHER_FILES += \
    qss/stylesheet.qss \
    translateFile.txt

RESOURCES += \
    yzzResource.qrc

DESTDIR = ../dist/nbdp/lib

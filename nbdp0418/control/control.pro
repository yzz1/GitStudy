#-------------------------------------------------
#
# Project created by QtCreator 2015-10-11T16:57:01
#
#-------------------------------------------------

QT       -= gui

TARGET = control
TEMPLATE = lib

include(../libs/3rdparty/log4qt/log4qt.pri)

DEFINES += CONTROL_LIBRARY

INCLUDEPATH += ../transit \
../logging
LIBS += -L../dist/nbdp/lib -ltransit \
-L../dist/nbdp/lib -llogging

SOURCES += \
    control.cpp

HEADERS +=\
        control_global.h \
    control.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

MOC_DIR = tmp
OBJECTS_DIR = tmp
RCC_DIR = tmp
UI_DIR = tmp

DESTDIR = ../dist/nbdp/lib

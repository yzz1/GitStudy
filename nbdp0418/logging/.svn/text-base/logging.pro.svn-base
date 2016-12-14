#-------------------------------------------------
#
# Project created by QtCreator 2009-02-17T12:57:11
#
#-------------------------------------------------

QT       -= gui

TARGET = logging
TEMPLATE = lib

DEFINES += LOGGING_LIBRARY

include(../libs/3rdparty/log4qt/log4qt.pri)

SOURCES += logging.cpp

HEADERS += logging.h\
        logging_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

MOC_DIR = tmp
OBJECTS_DIR = tmp
RCC_DIR = tmp
UI_DIR = tmp

DESTDIR = ../dist/nbdp/lib

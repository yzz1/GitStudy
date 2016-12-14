#-------------------------------------------------
#
# Project created by QtCreator 2015-10-12T11:40:46
#
#-------------------------------------------------

QT       -= gui

TARGET = transit
TEMPLATE = lib

DEFINES += TRANSIT_LIBRARY

SOURCES += transit.cpp \
    messageclass.cpp \
    callclass.cpp \
    scanclass.cpp \
    checkdataclass.cpp \
    callinfoclass.cpp \
    channelinfoclass.cpp

HEADERS += transit.h\
        transit_global.h \
    messageclass.h \
    callclass.h \
    scanclass.h \
    checkdataclass.h \
    callinfoclass.h \
    channelinfoclass.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

MOC_DIR = tmp
OBJECTS_DIR = tmp
RCC_DIR = tmp
UI_DIR = tmp

DESTDIR = ../dist/nbdp/lib

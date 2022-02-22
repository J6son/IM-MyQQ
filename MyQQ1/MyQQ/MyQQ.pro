#-------------------------------------------------
#
# Project created by QtCreator 2021-05-03T13:56:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyQQ
TEMPLATE = app

include(./netapi/netapi.pri)
include(./RecordVideo/RecordVideo.pri)
include(./RecordAudio/RecordAudio.pri)
include(./uiapi/uiapi.pri)

INCLUDEPATH += ./netapi/
INCLUDEPATH += ./RecordVideo/
INCLUDEPATH += ./RecordAudio/
INCLUDEPATH += ./uiapi/

SOURCES += main.cpp\
        myqqdialog.cpp \
    logindialog.cpp \
    useritem.cpp \
    IMToolBox.cpp \
    chatdialog.cpp \
    notify.cpp \
    roomdialog.cpp \
    videoitem.cpp

HEADERS  += myqqdialog.h \
    logindialog.h \
    useritem.h \
    IMToolBox.h \
    chatdialog.h \
    notify.h \
    roomdialog.h \
    videoitem.h

FORMS    += myqqdialog.ui \
    logindialog.ui \
    useritem.ui \
    chatdialog.ui \
    notify.ui \
    roomdialog.ui \
    videoitem.ui

RESOURCES += \
    resource.qrc

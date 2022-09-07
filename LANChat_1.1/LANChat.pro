#-------------------------------------------------
#
# Project created by QtCreator 2022-07-05T21:41:34
#
#-------------------------------------------------

QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TRANSLATIONS=LANChat_cn.ts
TARGET = LANChat
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    ChatWidget.cpp \
    qdialoglogin.cpp \
    tcpsendfiledialog.cpp \
    receivefiledialog.cpp \
    mytcpserver.cpp \
    filesender.cpp \
    sendfiledialog.cpp

HEADERS += \
    ChatWidget.h \
    qdialoglogin.h \
    tcpsendfiledialog.h \
    receivefiledialog.h \
    mytcpserver.h \
    filesender.h \
    sendfiledialog.h


FORMS += \
    ChatWidget.ui \
    qdialoglogin.ui \
    tcpsendfiledialog.ui \
    receivefiledialog.ui \
    sendfiledialog.ui

RESOURCES += \
    res.qrc

#-------------------------------------------------
#
# Project created by QtCreator 2015-03-20T13:36:30
#
#-------------------------------------------------

QT       += core gui webkitwidgets network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DesktopBuild
TEMPLATE = app

LIBS += -lqrencode

SOURCES += main.cpp\
        mainwindow.cpp \
    login_dialog.cpp \
    create_order.cpp \
    admin.cpp \
    paymentwithstatus.cpp \
    sendtext.cpp \
    keypad.cpp

HEADERS  += mainwindow.h \
    login_dialog.h \
    create_order.h \
    admin.h \
    paymentwithstatus.h \
    sendtext.h \
    keypad.h

FORMS    += mainwindow.ui \
    login_dialog.ui \
    create_order.ui \
    admin.ui \
    paymentwithstatus.ui \
    sendtext.ui \
    keypad.ui

OTHER_FILES += \
    PayTerm/LICENSE \
    PayTerm/README.md \
    LICENSE \
    README.md

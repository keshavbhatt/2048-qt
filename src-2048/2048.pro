#-------------------------------------------------
#
# Project created by QtCreator 2015-12-28T23:19:05
#
#-------------------------------------------------

QT       += core gui webkitwidgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt-2048-snap
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cookiejar.cpp \
    aboutdialog.cpp

HEADERS  += mainwindow.h \
    cookiejar.h \
    aboutdialog.h

FORMS    += mainwindow.ui \
    aboutdialog.ui

RESOURCES += \
    res.qrc

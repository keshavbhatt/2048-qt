#-------------------------------------------------
#
# Project created by QtCreator 2015-12-28T23:19:05
#
#-------------------------------------------------

QT       += core webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2048-qt
TEMPLATE = app


RC_ICONS = icon.ico


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
    res.qrc \
    html.qrc

DISTFILES += \
    icon.ico
#-------------------------------------------------
#
# Project created by QtCreator 2015-12-28T23:19:05
#
#-------------------------------------------------

QT       += core gui webkit webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2048-qt
TEMPLATE = app

CONFIG += c++11

# Set program version
VERSION = 3.0
DEFINES += VERSIONSTR=\\\"$${VERSION}\\\"
DEFINES += APPNAMESTR=\\\"$${TARGET}\\\"

RC_ICONS = icon.ico


SOURCES += main.cpp\
        mainwindow.cpp \
    aboutdialog.cpp

HEADERS  += mainwindow.h \
    aboutdialog.h

FORMS    += mainwindow.ui \
    aboutdialog.ui

RESOURCES += \
    res.qrc \
    html.qrc

DISTFILES += \
    icon.ico
    
# Default rules for deployment.
isEmpty(PREFIX){
 PREFIX = /usr
}

BINDIR  = $$PREFIX/bin
DATADIR = $$PREFIX/share

target.path = $$BINDIR

icon.files = icon.png
icon.path = $$DATADIR/icons/hicolor/512x512/apps/

desktop.files = 2048.desktop
desktop.path = $$DATADIR/applications/

INSTALLS += target icon desktop

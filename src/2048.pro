#-------------------------------------------------
#
# Project created by QtCreator 2015-12-28T23:19:05
#
#-------------------------------------------------

QT       += core gui webengine webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2048-qt
TEMPLATE = app

CONFIG += c++11


CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG_OUTPUT

QTQUICK_COMPILER_SKIPPED_RESOURCES += html.qrc

# Set program version
VERSION = 4.0
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

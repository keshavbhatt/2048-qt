#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWindow w;

    QApplication::setApplicationName("2048-Qt");
    QApplication::setApplicationVersion("1.0");
    QApplication::setOrganizationName("org.keshavnrj.ubuntu.2048Qt");

    w.setMaximumHeight(590);
    w.setMinimumHeight(590);
    w.setMaximumWidth(340);
    w.setMinimumWidth(340);
    w.show();

    return a.exec();
}

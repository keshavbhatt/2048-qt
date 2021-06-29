#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWindow w;

    QApplication::setApplicationName("2048-qt");
    QApplication::setApplicationVersion("3.0");
    QApplication::setOrganizationName("org.keshavnrj.ubuntu");

    w.setFixedSize(QSize(340,590));
    w.show();

    return a.exec();
}

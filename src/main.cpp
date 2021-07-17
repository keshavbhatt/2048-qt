#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString appname = APPNAMESTR;
    QApplication::setApplicationName(appname);
    QApplication::setOrganizationName("org.keshavnrj.ubuntu");
    QApplication::setApplicationVersion(VERSIONSTR);

    mainWindow w;

    w.setFixedSize(QSize(340,590));
    w.show();

    return a.exec();
}

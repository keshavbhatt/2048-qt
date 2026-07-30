#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // A single small local page doesn't need Chromium's full footprint;
    // must be set before QApplication so WebEngine picks it up.
    // --single-process and --disable-gpu drop the helper processes and GPU
    // contexts (~27% less RAM); safe here because the only content is the
    // bundled game and the request interceptor blocks everything else.
    if (!qEnvironmentVariableIsSet("QTWEBENGINE_CHROMIUM_FLAGS")) {
        qputenv("QTWEBENGINE_CHROMIUM_FLAGS",
                "--single-process"
                " --disable-gpu"
                " --disable-gpu-compositing"
                " --enable-low-end-device-mode"
                " --num-raster-threads=1"
                " --js-flags=--jitless"
                " --disable-background-networking"
                " --disable-breakpad");
    }

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

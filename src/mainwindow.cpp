#include "aboutdialog.h"
#include "cookiejar.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QNetworkDiskCache>
#include <QStandardPaths>
#include <QWebFrame>
#include <QWebInspector>
#include <QWebSettings>
#include <QDir>


mainWindow::mainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);

    setWindowIcon(QIcon(":/icon.png"));
    setWindowTitle(QApplication::applicationName());

    QString setting_path  =  QStandardPaths::writableLocation(QStandardPaths::DataLocation);

    if(!QDir(setting_path).exists()){
        QDir d(setting_path);
        d.mkpath(setting_path);
    }
    QString cookieJarPath  =  setting_path + "cookiejar.dat";

    ui->webView->settings()->setAttribute(QWebSettings::LocalStorageEnabled, true);
    ui->webView->settings()->enablePersistentStorage(setting_path);

    ui->actionDebug->setVisible(false);
#ifdef QT_DEBUG
    ui->actionDebug->setVisible(true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
#endif
    QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::JavascriptEnabled, true);

    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    QNetworkDiskCache* diskCache = new QNetworkDiskCache(manager);

    diskCache->setCacheDirectory(setting_path);
    manager->setCache(diskCache);
    manager->setCookieJar(new CookieJar(cookieJarPath, manager));

    ui->webView->page()->mainFrame()->setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);
    ui->webView->page()->setNetworkAccessManager(manager);
    ui->webView->page()->settings()->setMaximumPagesInCache(10);

    ui->webView->load(QUrl("qrc:/html/index.html"));
}

mainWindow::~mainWindow()
{
    delete ui;
}

void mainWindow::on_actionAbout_triggered()
{
    AboutDialog *a =  new AboutDialog(this);
    a->setWindowTitle(QApplication::applicationName()+" | About");
    a->setWindowFlags(Qt::Dialog);
    a->setAttribute(Qt::WA_DeleteOnClose, true);
    a->show();
}


void mainWindow::on_actionQuit_triggered()
{
    qApp->quit();
}

void mainWindow::on_actionDebug_triggered()
{
#ifdef QT_DEBUG
    page  = ui->webView->page();
    QWebInspector *ins  = new QWebInspector(this);
    ins->setWindowFlags(Qt::Window);
    ins->setAttribute(Qt::WA_DeleteOnClose, true);
    ins->setPage(page);
    ins->showNormal();
#endif
}

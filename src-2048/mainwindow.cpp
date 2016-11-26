#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutdialog.h"
#include "cookiejar.h"

#include <QStandardPaths>
#include <QNetworkDiskCache>
#include <QWebSettings>
#include <QNetworkCookieJar>
#include <QWebInspector>

mainWindow::mainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);



    //browser settings
       QString setting_path =  QStandardPaths::writableLocation(QStandardPaths::DataLocation);
       QString cookieJarPath  = QApplication::applicationDirPath().left(1) + setting_path + "cookiejar.dat";

       ui->webView->settings()->setAttribute(QWebSettings::LocalStorageEnabled, true);
       ui->webView->settings()->enablePersistentStorage(setting_path);
       QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
       QWebSettings::globalSettings()->setAttribute(QWebSettings::JavascriptEnabled, true);
       QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);
  //     QWebSettings *settings = QWebSettings::globalSettings();
//       const QString path = "qrc:/scroll.css";
//       settings->setUserStyleSheetUrl(QUrl(path));

       QNetworkAccessManager* manager = new QNetworkAccessManager(this);
       QNetworkDiskCache* diskCache = new QNetworkDiskCache(this);

     //  QString location = QStandardPaths::writableLocation(QStandardPaths::CacheLocation);
       diskCache->setCacheDirectory(setting_path);
       manager->setCache(diskCache);
       manager->setCookieJar(new CookieJar(cookieJarPath, manager));




       ui->webView->page()->setNetworkAccessManager(manager);
       ui->webView->page()->settings()->setMaximumPagesInCache(10);

           QNetworkRequest request = QNetworkRequest();
           request.setAttribute(QNetworkRequest::CacheLoadControlAttribute, QNetworkRequest::PreferCache);
           request.setUrl(ui->webView->url());

           // connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
           manager->get(request);
             ui->webView->load(QUrl("qrc:///index.html"));
}

mainWindow::~mainWindow()
{
    delete ui;
}

void mainWindow::on_actionAbout_triggered()
{
    AboutDialog a ;
    a.exec();
}


void mainWindow::on_actionQuit_triggered()
{
    qApp->quit();
}

void mainWindow::on_actionDebug_triggered()
{
    page=ui->webView->page();
    QWebInspector *ins  = new QWebInspector;
    ins->setPage(page);
    ins->showNormal();
}

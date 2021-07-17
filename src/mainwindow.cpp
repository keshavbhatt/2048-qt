#include "aboutdialog.h"
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

    QWebSettings *settings = ui->webView->settings();
    settings->setAttribute(QWebSettings::LocalStorageEnabled, true);
    settings->setLocalStoragePath(setting_path);
    settings->enablePersistentStorage(setting_path);
    QWebSettings::globalSettings()->enablePersistentStorage(setting_path);
    qDebug()<<setting_path;

    QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
    //ui->actionDebug->setVisible(false);
#ifdef QT_DEBUG
    //ui->actionDebug->setVisible(true);
#endif

    //QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::JavascriptEnabled, true);
    ui->webView->page()->mainFrame()->setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);    
    ui->webView->page()->mainFrame()->addToJavaScriptWindowObject("mainwindow",this);
//    connect(ui->webView,&QWebView::loadFinished,[=](bool loaded){
//        if(loaded){
//            QString bestScore = this->settings.value("oiks_765729283y27","0").toString();
//            ui->webView->page()->mainFrame()->evaluateJavaScript("this.localStorage.setItem('bestScore','"+bestScore+"')");
//        }
//    });

    ui->webView->load(QUrl("qrc:/html/index.html"));
}

mainWindow::~mainWindow()
{
    delete ui;
}

void mainWindow::update_high_score(QVariant var)
{
    if(var.isNull() == false && var.typeName() == QString("QString"))
    {
        settings.setValue("oiks_765729283y27", var.toString());
        qDebug()<<var;
    }
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

#include "aboutdialog.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "urlrequestinterceptor.h"

#include <QWebEngineProfile>

mainWindow::mainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/icon.png"));
    setWindowTitle(QApplication::applicationName());

    ui->actionDebug->setVisible(false);
#ifdef QT_DEBUG
    ui->actionDebug->setVisible(true);
#endif

    // Qt 6's default profile is off-the-record; a named profile keeps the
    // game's localStorage (best score, saved game) across runs.
    auto *profile = new QWebEngineProfile(QApplication::applicationName(), this);
    profile->setHttpCacheType(QWebEngineProfile::NoCache); // all content lives in qrc
    profile->setUrlRequestInterceptor(new UrlRequestInterceptor(profile));
    webView = new QWebEngineView(this);
    webView->setPage(new QWebEnginePage(profile, webView));

    auto *settings = webView->settings();
    settings->setAttribute(QWebEngineSettings::ShowScrollBars,false);
    // The game uses neither WebGL, canvas, favicons nor the PDF viewer.
    settings->setAttribute(QWebEngineSettings::WebGLEnabled,false);
    settings->setAttribute(QWebEngineSettings::Accelerated2dCanvasEnabled,false);
    settings->setAttribute(QWebEngineSettings::AutoLoadIconsForPage,false);
    settings->setAttribute(QWebEngineSettings::PdfViewerEnabled,false);
    webView->setMaximumSize(340,590);
    webView->load(QUrl("qrc:/html/index.html"));
    ui->centralWidget->layout()->addWidget(webView);
    webView->setFocus();
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
    auto page  = webView->page();

    QWebEngineView *ins  = new QWebEngineView(this);
    page->setDevToolsPage(ins->page());
    ins->setWindowFlags(Qt::Window);
    ins->setAttribute(Qt::WA_DeleteOnClose, true);
    ins->showNormal();
}

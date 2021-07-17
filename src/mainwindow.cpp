#include "aboutdialog.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"


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

    webView = new QWebEngineView(this);
    webView->settings()->setAttribute(QWebEngineSettings::ShowScrollBars,false);
    webView->setMaximumSize(340,590);
    webView->load(QUrl("qrc:/html/index.html"));
    ui->centralWidget->layout()->addWidget(webView);
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

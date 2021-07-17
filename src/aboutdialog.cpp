
#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#include <QDebug>
#include <QDesktopServices>
#include <QSettings>
#include <QUrl>

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap(":/about.png"));
    ui->textBrowser->setHtml(ui->textBrowser->toHtml().arg(APPNAMESTR,VERSIONSTR,QString("Qt ")+QT_VERSION_STR,"<a href='https://github.com/keshavbhatt'>Keshav Bhatt</a>"));
}


AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::on_moreapplication_clicked()
{
    QDesktopServices::openUrl(QUrl("https://snapcraft.io/search?q=keshavnrj"));
}

void AboutDialog::on_donate_clicked()
{
    QDesktopServices::openUrl(QUrl("https://paypal.me/keshavnrj"));
}

void AboutDialog::on_close_clicked()
{
    this->close();
}

void AboutDialog::on_source_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/keshavbhatt/2048-qt"));
}

void AboutDialog::on_textBrowser_anchorClicked(const QUrl &arg1)
{
    QDesktopServices::openUrl(QUrl(arg1));
}

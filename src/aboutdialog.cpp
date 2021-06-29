
#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#include <QDebug>
#include <QWebSettings>
#include <QDesktopServices>
#include <QSettings>
#include <QUrl>

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);

   // this->setStyleSheet(QString("background-color:#302F2F;"));

    QPixmap pixmap(":/about.png");
    pixmap=pixmap.scaledToWidth(200);
    ui->label->setPixmap(pixmap);
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

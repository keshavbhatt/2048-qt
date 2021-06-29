
#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>

namespace Ui {
class AboutDialog;
}

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent = 0);
    ~AboutDialog();

private:
    Ui::AboutDialog *ui;

private slots:
    void on_moreapplication_clicked();
    void on_donate_clicked();
    void on_close_clicked();
    void on_source_clicked();
};

#endif // ABOUTDIALOG_H
